#include <iostream>
#include <cmath>
using namespace std;

// DP에 이전 DP값을 계속 누적합으로 탐색해서 O(1)로 떨궈야함

int dp[1000005];
int pref[6][1000005];

int main() 
{
    // 바텀업 DP + prefix sum
    for (long long i = 1; i <= 1000000; i++) 
    {
        // 4제곱근
        long long L = round(pow(i, 0.25));
        while (L * L * L * L < i) L++;
        while ((L - 1) * (L - 1) * (L - 1) * (L - 1) >= i) L--;

        // 제곱근
        long long R = round(sqrt(i));
        while ((R + 1) * (R + 1) <= i) R++;
        while (R * R > i) R--;
        
        // y < x
        if (R >= i) R = i - 1; 

        int mex = 0;
        if (L <= R) 
            while (mex < 6 && pref[mex][R] - pref[mex][L - 1] > 0) 
                mex++;

        dp[i] = mex;
        for (int k = 0; k < 6; k++) 
            pref[k][i] = pref[k][i - 1] + (dp[i] == k ? 1 : 0);
        
    }

    int n; cin >> n;

    // 여기서 님
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        long long a;
        cin >> a;
        
        long long L = round(pow(a, 0.25));
        while (L * L * L * L < a) L++;
        while ((L - 1) * (L - 1) * (L - 1) * (L - 1) >= a) L--;

        long long R = round(sqrt(a));
        while ((R + 1) * (R + 1) <= a) R++;
        while (R * R > a) R--;

        if (R >= a) R = a - 1;

        int mex = 0;
        if (L <= R) 
            while (mex < 6 && pref[mex][R] - pref[mex][L - 1] > 0) 
                mex++;
        
        ans ^= mex;
    }

    ans > 0 ? cout << "koosaga" : cout << "cubelover";

    return 0;
}