#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> dp) 
{
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            // 좌우 끝 예외처리
            if (j == 0) dp[i][j] += dp[i - 1][j];
            else if (j == dp[i].size() - 1) dp[i][j] += dp[i - 1][j - 1];
            
            // 중앙
            else dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < dp[dp.size() - 1].size(); i++)
        ans = max(ans, dp[dp.size() - 1][i]);
    return ans;
}