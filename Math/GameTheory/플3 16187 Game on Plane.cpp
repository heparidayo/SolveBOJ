#include <iostream>
using namespace std;

// dp[K] = MEX { dp[j] ^ dp[K-2-j] | 0 <= j <= K-2 }

// 첫턴에만 직선이 아니라 n각형
// k, n-2-k (직선에 정점 -2소모)

// 선공이 k = (n-2)/2 대각선 그으면
// 양쪽에 같은 정점 남음
// - dp[k] == dp[k] 선공 승

int dp[5005];
int visit[5005];

int main() 
{
    for (int i = 2; i <= 5000; i++) 
    {
        for (int j = 0; j <= i - 2; j++) 
        {
            int nxt = dp[j] ^ dp[i - 2 - j];
            if (nxt < 5005) visit[nxt] = i; 
        }

        int mex = 0;
        while (visit[mex] == i) mex++;
        dp[i] = mex;
    }

    int t; cin >> t;
    while (t--) 
    {
        int n; cin >> n;
        if (n % 2 == 0) cout << "First\n";
        else 
        {
            bool ans = false;
            int rem = n - 2;
            
            for (int k = 0; k <= rem; k++) 
            {
                if (dp[k] == dp[rem - k]) 
                {
                    ans = true;
                    break;
                }
            }

            (ans) ? cout << "First\n" : cout << "Second\n";
        }
    }

    return 0;
}