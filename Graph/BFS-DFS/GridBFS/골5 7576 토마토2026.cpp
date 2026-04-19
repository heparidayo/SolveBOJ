#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int map[1005][1005];

int main()
{
    int n, m;
    cin >> n >> m;
    
    // 토마토 초기화
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1) q.push({ i, j });
        }
    }
    
    // BFS
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (map[nx][ny] != 0) continue;
            
            map[nx][ny] = map[cur.first][cur.second] + 1;
            q.push({ nx, ny });
        }
    }
    
    // 검사
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            
            ans = max(ans, map[i][j]);
        }
    }
    
    cout << ans - 1;
    return 0;
}