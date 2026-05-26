#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;
using namespace sf;

const int GRID_SIZE = 10; // Размер поля NxN
const int CELL_SIZE = 80;  // Размер одной ячейки в пикселях
const int WINDOW_SIZE = GRID_SIZE * CELL_SIZE; // размер окна

// Типы ячеек
enum CellType {
    EMPTY, // пустота
    OBSTACLE, // ограждение
    START,// начало
    END,// конец
    PATH,// путь
    VISITED// посещённые
};

// Структура для представления ячейки
struct Cell {
    int x, y; // координаты
    CellType type; // тип ячейки
    int f, g, h; // Для алгоритма A*
    Cell* parent; // сслыка на родителей
    int weight; // вес

    Cell(int x, int y) : x(x), y(y), type(EMPTY), f(0), g(0), h(0), parent(nullptr), weight(1) {}

    // Перезагрузка оператора == для сравнения ячеек
    bool operator==(const Cell& other) const {
        return x == other.x && y == other.y;
    }
};



// Функция для вычисления эвристики (манхэттенское расстояние)
int heuristic(const Cell& a, const Cell& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Функция для проверки, находится ли ячейка в пределах сетки
bool isValid(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE);
}


//функция для создания сетки
std::vector<std::vector<Cell>> make_grid(int GRID_SIZE) {
    vector<vector<Cell>> grid;
    for (int x = 0; x < GRID_SIZE; x++) {
        std::vector<Cell> row;
        for (int y = 0; y < GRID_SIZE; y++) {
            Cell cell(x, y);
            row.push_back(cell);
        }
        grid.push_back(row);
    }
    return grid;
}

//функция для отрисовки сетки
void draw_grid(sf::RenderWindow& win, std::vector<std::vector<Cell>>& grid) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            RectangleShape cell(Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
            cell.setPosition(i * CELL_SIZE, j * CELL_SIZE);

            switch (grid[i][j].type) {
            case EMPTY: cell.setFillColor(Color::White); break;
            case OBSTACLE: cell.setFillColor(Color::Black); break;
            case START: cell.setFillColor(Color::Green); break;
            case END: cell.setFillColor(Color::Red); break;
            case PATH: cell.setFillColor(Color::Blue); break;
            case VISITED: cell.setFillColor(Color::Cyan); break;
            }

            win.draw(cell);
        }
    }
}

// компоратор для очереди с приоритетом (priority_queue)
// сортирует ячейки так, чтобы первым всегда была ячейка с наименьшим значением f
struct CompareCells {
    bool operator()(Cell const* c1, Cell const* c2) {
        return c1->f > c2->f;
    }
};

// функция восстановления пути
void reconstruct_path(Cell* current) {
    if (current && current->type == END) {
        current = current->parent;
    }
    while (current != nullptr && current->type != START) {
        current->type = PATH;
        current = current->parent;
    }
}

// функция сброса результатов работы алгоритма перед новым запуском
void reload(std::vector<std::vector<Cell>>& grid) {
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            grid[x][y].parent = nullptr;
            grid[x][y].g = 999999;
            if (grid[x][y].type == PATH || grid[x][y].type == VISITED) {
                grid[x][y].type = EMPTY;
            }
        }
    }

}

//функция алгоритма A*
void a_star_algorithm(std::vector<std::vector<Cell>>& grid, Cell* start, Cell* end) {
    reload(grid); // сбрасывается старый путь

    // очередь с приоритетом для хранения доступных ячеек
    std::priority_queue<Cell*, std::vector<Cell*>, CompareCells> open_list;

    // двумерный массив для отслеживания закрытых уже посещенных и обработанных ячеек
    std::vector<std::vector<Cell*>> closed_list(GRID_SIZE, std::vector<Cell*>(GRID_SIZE, nullptr));

    // параметры начальной точки
    start->g = 0;
    start->f = heuristic(*start, *end);
    open_list.push(start);

    // основной цикл алгоритма
    while (!open_list.empty()) {
        // берётся ячейка с минимальным f
        Cell* n = open_list.top();
        open_list.pop();

        // если дошли до конца строится путь и завершается работа алгоритма
        if (*n == *end) {
            reconstruct_path(&grid[end->x][end->y]);
            return;
        }

        // если ячейка уже находится в закрытом списке — пропускаем её
        if (closed_list[n->x][n->y] != nullptr) continue;

        // добавляем текущую ячейку в закрытый список
        closed_list[n->x][n->y] = n;

        // помечаем пустую ячейку как посещенную
        if (n->type == EMPTY) {
            n->type = VISITED;
        }

        // смещения для проверки 4-х соседних ячеек 
        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };

        for (int i = 0; i < 4; i++) {
            int nx = n->x + dx[i];
            int ny = n->y + dy[i];

            // проверяем подходят ли координаты (препятствия и не обработан ли уже сосед)
            if (!isValid(nx, ny) || grid[nx][ny].type == OBSTACLE || closed_list[nx][ny] != nullptr) {
                continue;
            }

            // рассчитываем предполагаемую стоимость пути g до этого соседа
            Cell* m = &grid[nx][ny];
            int tentative_g = n->g + m->weight;

            // если найден более короткий путь
            if (tentative_g < m->g) {
                m->parent = n;
                m->g = tentative_g;
                m->h = heuristic(*m, *end);
                m->f = m->g + m->h; // обновляем полную стоимость

                // добавляем соседа в открытй список
                open_list.push(m);
            }
        }
    }
}

// генерация карты по заданию
void generate_normal_grid(vector<vector<Cell>>& grid) {
    grid[0][3].type = START; //начало
    grid[GRID_SIZE - 1][GRID_SIZE - 1].type = END; // конец
    // массив с координатами непроходимых клеток
    vector<Vector2i> obstacles = {
        {0,0}, {1,0}, {2,0}, {3,0}, {4, 0}, {6, 0},
        {0,1}, {1,1}, {5,1},
        {1,2},
        {2,3}, {4,3}, {5,3}, {7,3}, {8, 3},
        {1,4}, {3,4}, {5,4}, {6,4}, {7,4},
        {6,5}, {7,5}, {8,5}, {9,5},
        {0,6}, {4,6}, {5,6},
        {0, 7}, {5, 7}, {6, 7}, {7, 7}, {9, 7},
        {8, 8},
        {2,9}
    };

    // расстановка препятствий
    for (const auto& p : obstacles) {
        if (p.x < GRID_SIZE && p.y < GRID_SIZE) {
            grid[p.x][p.y].type = OBSTACLE;
        }
    }

}

// генерация случайной карты со случайным весом
void generate_random_grid(vector<vector<Cell>>& grid) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    uniform_real_distribution<> s(0, GRID_SIZE-1);
    uniform_real_distribution<> random_weight(50, 100);

    // случайные клетки стартка и конца
    grid[s(gen)][s(gen)].type = START;
    grid[s(gen)][s(gen)].type = END;

    //проверяем, чтобы они не совпали
    if (START == END) {
        grid[s(gen)][s(gen)].type = START;
        grid[s(gen)][s(gen)].type = END;
    }

    // заполняем случайно клетки препятсвиями и весами
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            if (grid[x][y].type != START && grid[x][y].type != END) {
                if (dis(gen) < 0.3) { // шанс появление препятсвия
                    grid[x][y].type = OBSTACLE;
                }
                else {
                    grid[x][y].type = EMPTY;
                    grid[x][y].weight = random_weight(gen); // случайный вес
                }
            }
        }
    }
}

int main() {
    // создаём окно и сетку по заданию
    RenderWindow window(VideoMode(WINDOW_SIZE, WINDOW_SIZE), "A*");
    vector<vector<Cell>> grid = make_grid(GRID_SIZE);
    generate_normal_grid(grid);

    // задание клеток начала и конца
    Cell* start = nullptr;
    Cell* end = nullptr;

    for (auto& row : grid) {
        for (auto& cell : row) {
            if (cell.type == START) {
                start = &grid[cell.x][cell.y];
            }
            if (cell.type == END) {
                end = &grid[cell.x][cell.y];
            }
        }
    }

    // цикл открытого окна
    while (window.isOpen()) {
        // обработка событий
        Event event;
        while (window.pollEvent(event)) {
            // закрытие окна
            if (event.type == Event::Closed) {
                window.close();
            }
            // нажатие клавиш
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    // по нажатию на пробел запускается поиск пути алгоритмом A*
                    a_star_algorithm(grid, start, end);
                }
                if (event.key.code == Keyboard::R) {
                    // сбрасываются значения
                    start->type = EMPTY;
                    end->type = EMPTY;
                    // генерируется случайная карта
                    generate_random_grid(grid);
                    // задание новых клеток начала и конца
                    for (auto& row : grid) {
                        for (auto& cell : row) {
                            if (cell.type == START) {
                                start = &grid[cell.x][cell.y];
                            }
                            if (cell.type == END) {
                                end = &grid[cell.x][cell.y];
                            }
                        }
                    }
                }
            }
        }

        window.clear(); // очистка экрана
        draw_grid(window, grid); // отрисовка всех ячеек
        window.display(); // отображение
    }
    return 0;
}