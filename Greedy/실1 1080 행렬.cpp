#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    vector<string> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;

    // 3x3 탐색
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = 0; j <= m - 3; j++)
        {
            if (a[i][j] != b[i][j])
            {
                // 3x3 뒤집기
                for (int x = i; x < i + 3; x++)
                    for (int y = j; y < j + 3; y++)
                        a[x][y] = (a[x][y] == '0') ? '1' : '0';

                ans++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "-1";
            return 0;
        }
    }

    cout << ans;

    return 0;
}