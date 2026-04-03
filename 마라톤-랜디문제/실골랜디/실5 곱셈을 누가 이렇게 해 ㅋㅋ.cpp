#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> v;
int main()
{
    #define int long long
    int t; cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = a * b;

        v.clear();
        while (a > 0 || b > 0)
        {
            if (a == 0) a = 1;
            else if (b == 0) b = 1;

            v.push_back((a % 10) * (b % 10));

            a /= 10;
            b /= 10;
        }

        int res = 0;
        int pos = 1;
        for (auto cur : v)
        {
            res += cur*pos;
            if (cur >= 10) pos *= 100;
            else pos *= 10;
        }

        if (res == ans) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}