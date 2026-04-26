#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[3000005];
int visit[3000005];

int main() 
{
    int n; cin >> n;
    vector<int> p(n);
    int max_p = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> p[i];
        if (p[i] > max_p) 
            max_p = p[i];
    }

    vector<int> fib;
    int a = 1;
    int b = 2;
    fib.push_back(1);
    if (max_p >= 2) fib.push_back(2);
    
    while (true) 
    {
        int c = a + b;
        if (c > max_p) break;
        fib.push_back(c);
        a = b;
        b = c;
    }

    dp[0] = 0;
    for (int i = 1; i <= max_p; i++) 
    {
        for (int f : fib) 
        {
            if (f > i) break; // 배열은 오름차순
            visit[dp[i - f]] = i; 
        }

        int mex = 0;
        while (visit[mex] == i) mex++;
        dp[i] = mex;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) 
        ans ^= dp[p[i]];

    ans > 0 ? cout << "koosaga" : cout << "cubelover";

    return 0;
}