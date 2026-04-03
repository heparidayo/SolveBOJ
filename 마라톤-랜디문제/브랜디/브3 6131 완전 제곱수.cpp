#include <iostream>
using namespace std; 

int main()
{
    int n; cin >> n;
    // a^2 == b^2 + n, a < b

    int cnt = 0;
    for (int b = 1; b <= 500; b++)
        for (int a = b; a <= 500; a++)
            if (a*a == b*b + n) cnt++;

    cout << cnt;
}