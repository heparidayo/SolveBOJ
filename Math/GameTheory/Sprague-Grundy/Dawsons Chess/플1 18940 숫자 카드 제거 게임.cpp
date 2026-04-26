#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[205];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 1; i <= 150; i++) 
    {
        vector<bool> visit(205, false);
        
        // 카드 x를 고르는 모든 경우
        for (int x = 1; x <= i; x++) 
        {
            int l = max(0, x - 2);
            int r = max(0, i - x - 1);
            
            int nxt = dp[l] ^ dp[r];
            visit[nxt] = true;
        }
        
        int mex = 0;
        while (visit[mex]) mex++;
        dp[i] = mex;
    }

    int t; cin >> t;
    while (t--) 
    {
        int n; cin >> n;
        
        int ans;
        // 주기성 (34)
        if (n <= 100) ans = dp[n];
        else ans = dp[100 + (n - 100) % 34];
        
        ans > 0 ? cout << "Yuto\n" : cout << "Platina\n";
    }

    return 0;
}