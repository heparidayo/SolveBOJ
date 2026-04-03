#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

// 0 1 2 3 - 상 좌 하 우 (반시계)
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

char map[55][55];
int visit[55][55][7][4]; // x, y, speed, dir
/*
FORWARD: The rover starts rolling forward at a speed of 1cm/s.
BACKWARD: The rover starts rolling backward at a speed of 1cm/s.
FASTER: If the rover is already rolling forward, its speed increases by 1cm/s, but never to more than 5cm/s.
SLOWER: If the rover is rolling forward, its speed decreases by 1cm/s.
STOP: The rover stops moving.
RIGHT: The rover turns 90 degrees to the right.
LEFT: The rover turns 90 degrees to the left.

0 전진
1 후진 
2 가속
3 감속
4 정지
5 우회전
6 좌회전
*/

int main()
{
    int k; cin >> k;
    for (int cnt = 1; cnt <= k; cnt++)
    {
        memset(visit, 0, sizeof(visit));

        int h, w;
        cin >> h >> w;

        // R -> P
        // 90도 회전 1초
        // 이동 1초
        
        // 맵 초기화
        queue<tuple<int, int, int, int>> q;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'R')
                {
                    q.push({ i, j, 0 , 0 });
                    visit[i][j][1][0] = 1;
                }
            }
        }

        // BFS 시작
        int ans = -1;
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            int cx = get<0>(cur);
            int cy = get<1>(cur);
            int cz = get<2>(cur);

            // 1. 전진
            int nx = cx + dx[cz];
            int ny = cy + dy[cz];
            if (nx <= h && nx > 0 && ny <= w && ny > 0
                && visit[nx][ny][cz] == 0 
                && map[nx][ny] != 'P')
            {
                visit[nx][ny][cz] = visit[cx][cy][cz] + 1;
                if (map[nx][ny] == 'D')
                {
                    ans = visit[nx][ny][cz] - 1;
                    break;
                }
                    
                q.push({ nx, ny, cz });
            }

            // 2. 반시계 회전
            int nz = (cz + 1) % 4;
            if (visit[cx][cy][nz] == 0)
            {
                visit[cx][cy][nz] = visit[cx][cy][cz] + 1;
                q.push({ cx, cy, nz });
            }
            
            // 3. 시계 회전
            nz = cz - 1;
            if (cz - 1 < 0) nz = 3;
            if (visit[cx][cy][nz] == 0)
            {
                visit[cx][cy][nz] = visit[cx][cy][cz] + 1;
                q.push({ cx, cy, nz });
            }
        }

        cout << "Data Set " << cnt << ":" << '\n';
        if (ans > -1) cout << ans << '\n';
        else cout << "Impossible" << '\n';
    }

    return 0;
}