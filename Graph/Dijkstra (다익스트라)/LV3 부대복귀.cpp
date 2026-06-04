#include <string>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    // 양방향 그래프
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto r : roads) 
    {
        int u, v;
        u = r[0];
        v = r[1];
        adj[u].push_back({ 1, v });
        adj[v].push_back({ 1, u });
    }

    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 목적지에서 역방향 탐색
    dist[destination] = 0;
    pq.push({ 0, destination }); 

    while (!pq.empty()) 
    {
        auto cur = pq.top(); pq.pop();

        // 가지치기
        if (dist[cur.second] < cur.first) continue;

        for (auto nxt : adj[cur.second]) 
        {
            // edge relaxation
            int nw = cur.first + nxt.first; 
            if (dist[nxt.second] > nw) 
            {
                dist[nxt.second] = nw;
                pq.push({nw, nxt.second});
            }
        }
    }

    vector<int> ans;
    for (int s : sources) 
    {
        if (dist[s] == INF) ans.push_back(-1); // 복귀 X
        else ans.push_back(dist[s]);
    }

    return ans;
}