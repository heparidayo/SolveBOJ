#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

tuple<int, int, int> edge[1000005];

vector<int> p(100005, -1);

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool union_(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (p[u] > p[v]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = { w, u, v };
    }

    sort(edge + 1, edge + 1 + m);

    int cnt = 0;
    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        // 정점이 2개면 2개의 마을로 분리
        if (cnt == n - 2) break; 

        int w, u, v;
        tie(w, u, v) = edge[i];
        if (union_(u, v))
        {
            cnt++;
            ans += w;
        }
    }

    cout << ans << '\n';
    return 0;
}