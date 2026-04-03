#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> v(n + 1, -1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        int ans = n;
        for (int i = 1; i <= n; i++)
        {
            int st = i;
            int cur = i;
            vector<bool> vis(n + 1, false);

            while (true)
            {
                if (vis[cur]) break;
                vis[cur] = true;
                cur = v[cur];

                if (cur == st)
                {
                    ans--;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}