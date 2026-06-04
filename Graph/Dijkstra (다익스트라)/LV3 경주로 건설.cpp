#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dist[25][25][4];

#define TIIII tuple<int, int, int, int>

int solution(vector<vector<int>> board) 
{
    int n = board.size();
    memset(dist, 0x3f3f3f3f, sizeof(dist));

    for (int i = 0; i < 4; i++) dist[0][0][i] = 0;
    
    priority_queue<TIIII, vector<TIIII>, greater<TIIII>> pq;
    pq.push({ 0, 0, 0, -1 }); // w, x, y, dir; (시작 방향 : -1)
    
    while (!pq.empty())
    {
        auto [cw, cx, cy, cdir] = pq.top(); pq.pop(); // tie보다 편함

        // 가지치기
        if (cdir != -1 && dist[cx][cy][cdir] < cw) continue;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] == 1) continue;

            // 일단 직진. 방향이 전과 다르면 코너 필요
            int nw = cw + 100; 
            if (cdir != -1 && cdir != dir) nw += 500; 

            // edge relaxation
            if (dist[nx][ny][dir] > nw)
            {
                dist[nx][ny][dir] = nw;
                pq.push({ nw, nx, ny, dir });
            }
        }
    }

    // 도착점 (n-1, n-1) 검사
    int ans = INF;
    for (int dir = 0; dir < 4; dir++)
        ans = min(ans, dist[n - 1][n - 1][dir]);

    return ans;
}