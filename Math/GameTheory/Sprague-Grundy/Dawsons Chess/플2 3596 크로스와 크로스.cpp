#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2005];

int main() 
{
    int n; cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        vector<bool> visit(2005, false);

        // i 크기 보드에서 k번에 x두는 모든 경우
        for (int k = 1; k <= i; k++) 
        {
            int l = max(0, k - 3);
            int r = max(0, i - k - 2);

            // 2개 분할 게임은 xor로 합침
            visit[dp[l] ^ dp[r]] = true;
        }

        int mex = 0;
        while (visit[mex]) mex++;

        dp[i] = mex;
    }

    dp[n] > 0 ? cout << 1 : cout << 2;

    return 0;
}