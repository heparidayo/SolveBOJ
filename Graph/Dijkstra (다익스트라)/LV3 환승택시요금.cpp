#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

// 최단 거리 배열 반환
vector<int> dijkstra(int st, int n, vector<vector<pair<int, int>>> adj)
{
    vector<int> dist(n + 1, INF);
    dist[st] = 0;
    
    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, st }); // { 비용, 도착지 }
    
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] < cur.first) continue;
        
        for (auto nxt : adj[cur.second])
        {
            // edge relaxation
            if (dist[nxt.second] > dist[cur.second] + nxt.first)
            {
                dist[nxt.second] = dist[cur.second] + nxt.first;
                pq.push({ dist[nxt.second], nxt.second });
            }
        }
    }
    
    return dist;
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    // 양방향 그래프
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto f : fares) 
    {
        int u = f[0], v = f[1], w = f[2];
        adj[u].push_back({ w, v });
        adj[v].push_back({ w, u }); 
    }
    
    // (환승) -> (목적지a), (목적지a) -> (환승)
    // 두 거리는 어차피 같으므로 미리 최단거리 구해두기
    vector<int> ds = dijkstra(s, n, adj); 
    vector<int> da = dijkstra(a, n, adj); 
    vector<int> db = dijkstra(b, n, adj);
    
    int ans = INF;
    for (int i = 1; i <= n; i++) 
    {
        // INF 끼리 합치면 오버플로우라 예외처리
        if (ds[i] == INF || da[i] == INF || db[i] == INF) continue;
        
        int sum = ds[i] + da[i] + db[i];
        ans = min(ans, sum);
    }

    return ans;
}