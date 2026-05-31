#include <iostream>
#include <vector>
#include <algorithm>

class TreeNode {
public:
    int val;            // Значение узла
    TreeNode* left;     // Указатель на левый дочерний узел
    TreeNode* right;    // Указатель на правый дочерний узел

    // Конструктор класса
    // Принимает значение узла и указатели на левый и правый узлы (по умолчанию nullptr, что аналог None)
    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : val(val), left(left), right(right) {
    } // Инициализация членов класса
};

void insert(TreeNode* node, int& value) {
    // Если значение меньше текущего, вставляем в левое поддерево
    if (value < node->val) {
        if (node->left) {
            insert(node->left, value);  // Рекурсивно ищем место в левом поддереве
        }
        else {
            node->left = new TreeNode(value);  // Вставляем новый узел
        }
    }
    // Если значение больше текущего, вставляем в правое поддерево
    else if (value > node->val) {
        if (node->right) {
            insert(node->right, value);  // Рекурсивно ищем место в правом поддереве
        }
        else {
            node->right = new TreeNode(value);  // Вставляем новый узел
        }
    }
}

bool same_tree(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    }
    
    if (tree1 == nullptr || tree2 == nullptr) {
        return false;
    }

    if (tree1->val != tree2->val) {
        return false;
    }

    return same_tree(tree1->left, tree2->left) and same_tree(tree1->right, tree2->right);
}

void free_tree(TreeNode* node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    delete node;
}

int base(int n) {
    std::vector<int> ns;
    for (int i = 1; i <= n; i++) {
        ns.push_back(i);
    }

    std::vector<TreeNode*> unique_trees;
    bool has_permutations = true;

    while (has_permutations) {
        TreeNode* tree = new TreeNode(ns[0]);

        for (size_t i = 1; i < ns.size(); i++) {
            insert(tree, ns[i]);
        }

        bool is_duplicate = false;
        for (TreeNode* utree : unique_trees) {
            if (same_tree(tree, utree)) {
                is_duplicate = true;
                break;
            }
        }

        if (!is_duplicate) {
            unique_trees.push_back(tree);
        }
        else {
            free_tree(tree);
        }

        has_permutations = std::next_permutation(ns.begin(), ns.end());
    }

    return unique_trees.size();
}

int main() {
    int n = 0;
    std::cin >> n;
    if (n <= 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int unique_trees = base(n);

    std::cout << unique_trees << std::endl;

    return 0;
}