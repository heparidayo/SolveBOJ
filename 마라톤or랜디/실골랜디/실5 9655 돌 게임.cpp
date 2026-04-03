#include <iostream>
using namespace std;
// 마지막 돌 승리, 상근 -> 찬영
// 1 3 5
int main()
{
   int n; cin >> n;
   n%2 == 0 ? cout << "CY" : cout << "SK";
}