#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>
using namespace std;

int dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int dy[8] = { 1, 0, -1, 0 -1, 1, -1, 1 };

int map[1005][1005];

int main()
{
    int r, c;
    cin >> r >> c;

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> map[i][j];

    queue<pair<int, int>> q;
    int ans = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (map[i][j] > 0)
            {
                q.push({ i, j });
                map[i][j] = 0;
                ans += 1;
                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 8; dir++)
                    {
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                    
                        if (map[ny][nx] == 0) continue;
                        if (nx < 1 || ny < 1 || ny > r || nx > c) continue;
                        
                        map[ny][nx] = 0;
                        q.push({ ny, nx });
                    }
                }
            }
        }
    }

    cout << ans;
}