#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;

int solution(int N, vector<vector<int>> road, int K) 
{
    // 양방향 그래프
    vector<vector<pair<int, int>>> adj(N + 1);
    for (auto r : road) 
    {
        int u = r[0], v = r[1], w = r[2];
        adj[u].push_back({ w, v });
        adj[v].push_back({ w, u }); 
    }
    vector<int> dist(N + 1, INF);
    dist[1] = 0; // 1 -> 1 은 비용 0
    
    
    // min heap (graeter; 오름차순)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });
    
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop(); // { 비용, 도착지 }
        if (dist[cur.second] < cur.first) continue; // != 처리도 가능
        
        for (auto nxt : adj[cur.second])
        {
            // edge relaxation (간선 완화)
            if (dist[nxt.second] > dist[cur.second] + nxt.first)
            {
                dist[nxt.second] = dist[cur.second] + nxt.first;
                pq.push({ dist[nxt.second], nxt.second });
            }
        }
    }
    
    
    // ans 카운팅
    int ans = 0;
    for (int i = 1; i <= N; i++) if (dist[i] <= K) ans++;
    return ans;
}