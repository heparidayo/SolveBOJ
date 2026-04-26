#include <iostream>
using namespace std;

int dp[100005];
int pref[100005];
int visit[200005]; 

int main() 
{
    int n; cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        for (int k = 2; k * (k - 1) / 2 < i; k++) 
        {
            int rem = i - k * (k - 1) / 2;
            if (rem % k == 0) 
            {
                int a = rem / k;
                int nxt = pref[a + k - 1] ^ pref[a - 1];
                if (nxt < 200005) visit[nxt] = i; 
            }
        }

        int mex = 0;
        while (visit[mex] == i) mex++;
        
        dp[i] = mex;
        pref[i] = pref[i - 1] ^ mex;
    }

    if (dp[n] == 0) cout << -1;
    else 
    {
        for (int k = 2; k * (k - 1) / 2 < n; k++) 
        {
            int rem = n - k * (k - 1) / 2;
            if (rem % k == 0) 
            {
                int a = rem / k;
                int nxt = pref[a + k - 1] ^ pref[a - 1];
                
                if (nxt == 0) 
                {
                    cout << k;
                    return 0; 
                }
            }
        }
    }

    return 0;
}