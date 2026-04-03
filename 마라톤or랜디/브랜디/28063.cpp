#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int x, y;
    cin >> x >> y;
    
    int ans = 4;
    if (x == 1 || x == n) ans--;
    if (y == 1 || y == n) ans--;
    if (n == 1) ans = 0;
    cout << ans;
}