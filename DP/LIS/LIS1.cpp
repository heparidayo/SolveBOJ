#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int input[1001];
int main(void)
{
    dp[0] = 0;                          // dp[n] << n을 마지막으로 하는 수열의 길이(LIS의 길이)

    int n; cin >> n;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];

        int here = 0;                    // n번까지의 숫자 중 가장 긴 수열을 저장하기 위한 임시 데이터
        for (int j = 1; j < i; j++)
        {
            if (input[i] > input[j])     // 새로 들어온 숫자 > 지금까지 있던 숫자들 {1, 2, ... , n}
                here = max(here, dp[j]); // j를 마지막으로 하는 수열 [1, 3, 5, j]의 길이 vs here
        }
        dp[i] = here + 1;
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;
    return 0;
}
