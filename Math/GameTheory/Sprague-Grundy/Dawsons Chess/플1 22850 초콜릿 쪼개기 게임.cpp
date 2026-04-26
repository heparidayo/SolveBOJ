#include <iostream>
#include <vector>
using namespace std;

int dp[205];
vector<bool> visit(205, false);

int main() 
{
    // 도슨의 체스 150까지 계산
    dp[0] = dp[1] = dp[2] = 0;
    for (int i = 3; i <= 150; i++) 
    {
        
        // i 크기 쪼개서 탐색 -> j / i-1-j
        for (int j = 1; j <= i - 2; j++) 
        {
            int nxt = dp[j] ^ dp[i - 1 - j];
            visit[nxt] = true;
        }
        
        int mex = 0;
        while (visit[mex]) mex++;
        dp[i] = mex;
    }

    int n, m;
    if (cin >> n >> m) 
    {
        // 주기 34로 그라운디
        int gn = (n <= 100) ? dp[n] : dp[100 + (n - 100) % 34];
        int gm = (m <= 100) ? dp[m] : dp[100 + (m - 100) % 34];

        gn == 0 && gm == 0 ? cout << "hs" : cout << "sh";
    }

    return 0;
}