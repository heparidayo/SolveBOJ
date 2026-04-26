#include <iostream>
using namespace std;

int dp[65];

int main() 
{
    // k(k+1)/2 <= i 를 만족하는 최대 k
    for (int i = 1; i <= 60; i++) 
    {
        int k = 0;
        while ((k + 1) * (k + 2) / 2 <= i) 
            k++;

        dp[i] = k;
    }

    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        int a; cin >> a;
        ans ^= dp[a];
    }

    ans > 0 ? cout << "koosaga" : cout << "cubelover";

    return 0;
}