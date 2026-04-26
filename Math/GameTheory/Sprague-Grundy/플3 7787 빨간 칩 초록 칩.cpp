#include <iostream>
using namespace std;

int main() 
{
    int r, g;
    cin >> r >> g;

    // 해당 수를 나누어 떨어지게 하는 가장 큰 2의 거듭제곱 수
    (r & -r) != (g & -g) ? cout << "A player wins" : cout << "B player wins";
}