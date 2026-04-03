#include <iostream>
#include <vector>
using namespace std;

int vec[100005];
bool vis[100005];
bool ans[100005];
int cnt;

void dfs(int cur) 
{
    // true 남기면서 최대한 깊게
    vis[cur] = true;
    int nxt = vec[cur];
    if (!vis[nxt]) dfs(nxt); 

    // 사이클 찾음, 카운팅
    else if (!ans[nxt]) 
    {
        for (int i = nxt; i != cur; i = vec[i]) cnt++;
        cnt++; // 본인 + 1
    }
    
    ans[cur] = true; // 해당 번호는 탐색 끝남
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
    
        for (int i = 1; i <= n; i++) 
        {
            cin >> vec[i];
            vis[i] = false;
            ans[i] = false;
        }

        cnt = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (!vis[i]) dfs(i); // 사이클 탐색
        }

        cout << n - cnt << '\n';
    }
    
    return 0;
}