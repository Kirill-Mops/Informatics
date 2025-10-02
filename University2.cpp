#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;

int main()
{
    float x, y, R, S, C;
    cin >> x >> y;
    R = x * tan(PI / 2);
    S = sqrt(pow(x, 2)+pow(y, 2))/(pow(2, log2(x)));
    cout << R << " " << S << endl;
    C = max(R, S);
    cout << C << endl;

    system("pause");

    return 0;
}
