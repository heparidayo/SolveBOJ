#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p(105, -1);

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]); // path compression
}

void union_(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return; 
    
    // union by size (union by rank 변형)
    if (p[v] < p[u]) swap(u, v); 
    p[u] += p[v];

    p[v] = u; 
    return;
}

int main() 
{
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int u, v;
        cin >> u >> v;
        union_(u, v);
    }

    cout << p[find(1)] * -1 - 1;
    
    return 0;
}