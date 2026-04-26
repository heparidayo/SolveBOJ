#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    long long n; cin >> n;

    vector<long long> fib;
    fib.push_back(1);
    fib.push_back(2);
    
    while (fib.back() < n) 
    {
        long long nxt = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(nxt);
    }

    // 제켄도르프 분해
    long long ans = 0;
    int nn = n;
    for (int i = fib.size() - 1; i >= 0; i--) 
    {
        if (n >= fib[i]) 
        {
            ans = fib[i]; // 마지막으로 뺀 가장 작은 피보나치 수
            n -= fib[i];
            
            if (n == 0) break;
        }
    }

    (ans == nn) ? cout << -1 : cout << ans;

    return 0;
}