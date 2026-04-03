#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int map[105][105];
int dist[105][105][2];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    
    queue<tuple<int, int, int>> q;
    q.push({ 1, 1, 0 });
    while (!q.empty())
    {
        int cx, cy, cz;
        tie(cx, cy, cz) = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if ((cz == 0) && map[nx][ny] == 1) continue;
            if (dist[nx][ny][cz] > 0) continue;
            
            dist[nx][ny][cz] = dist[cx][cy][cz] + 1;
            if (map[nx][ny] == 2) 
            {
                q.push({ nx, ny, 1 });
                dist[nx][ny][1] = dist[nx][ny][cz];
            }
            
            q.push({ nx, ny, cz });
        }
    }
    
    int ans = 105*105;
    if (dist[n][m][0] > 0) ans = min(ans, dist[n][m][0]);
    if (dist[n][m][1] > 0) ans = min(ans, dist[n][m][1]);

    (ans <= t && ans != 105*105) ? cout << ans : cout << "Fail";
}