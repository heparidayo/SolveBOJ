#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p(100002, -1);

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]); // path compression
}

int main()
{
    int G; cin >> G;
    int P; cin >> P;

    int ans = 0;
    for (int i = 0; i < P; i++)
    {
        int g; cin >> g;
        int root = find(g);

        if (root == 0) break; 

        ans++;
        
        p[root] = find(root - 1); // root로만 붙이면 됨
    }

    cout << ans << '\n';
    return 0;
}