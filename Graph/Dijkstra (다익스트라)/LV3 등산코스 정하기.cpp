#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    // 산봉우리 검사용
    vector<bool> visit(n + 1, false);
    for (int s : summits) visit[s] = true;

    // 양방향 그래프
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto p : paths)
    {
        int u, v, w;
        u = p[0];
        v = p[1];
        w = p[2];
        adj[u].push_back({ w, v });
        adj[v].push_back({ w, u });
    }

    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 다중 탐색 (BFS 토마토 같은 유형)
    for (int g : gates)
    {
        dist[g] = 0;
        pq.push ({ 0, g });
    }

    // dijkstra
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if (dist[cur.second] < cur.first) continue;
        if (visit[cur.second]) continue;

        for (auto nxt : adj[cur.second])
        {
            // 기존 간선 완화랑 다르게 최댓값으로 갱신
            int nmax = max(cur.first, nxt.first);
            if (dist[nxt.second] > nmax)
            {
                dist[nxt.second] = nmax;
                pq.push({ nmax, nxt.second });
            }
        }
    }

    int ans = 0;
    int intensity = INF;
    sort(summits.begin(), summits.end()); // intensity 동률 - 오름차순

    for (int s : summits)
    {
        if (dist[s] < intensity)
        {
            intensity = dist[s];
            ans = s;
        }
    }

    return { ans, intensity };
}