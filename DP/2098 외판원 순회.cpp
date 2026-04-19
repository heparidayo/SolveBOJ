#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9

int n;
int w[16][16];
int dp[16][1 << 16];

int dfs(int cur, int visit)
{
    if (visit == (1 << n) - 1)
    {
        // 시작점(0번)으로 돌아가는 길이 있다면 그 비용 반환, 없으면 INF
        if (w[cur][0] != 0) return w[cur][0];
        return INF;
    }

    // 2. 이미 계산된 경로인 경우 (메모이제이션)
    if (dp[cur][visit] != 0) 
        return dp[cur][visit];

    dp[cur][visit] = INF;

    // 3. 아직 방문하지 않은 다음 도시들을 탐색합니다
    for (int i = 0; i < n; i++)
    {
        // 가는 길이 없거나, 이미 방문한 도시인 경우 패스
        if (w[cur][i] == 0 || (visit & (1 << i))) continue;

        // 다음 도시로 가는 비용과 현재 최솟값 비교
        dp[cur][visit] = min(dp[cur][visit], dfs(i, visit | (1 << i)) + w[cur][i]);
    }

    return dp[cur][visit];
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    // 0번 도시에서 출발, 방문 상태 비트는 1 (000...001)
    cout << dfs(0, 1);

    return 0;
}