#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    long long n; cin >> n;

    vector<long long> fib;
    fib.push_back(1); 
    fib.push_back(2); 
    
    while (true) 
    {
        long long nxt = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(nxt);
        if (nxt > 1000000000000000LL) break;
    }

    // 제켄도르프 분해 - 큰 피보나치부터 탐욕적으로 감산
    long long ans = 0;
    for (int i = fib.size() - 1; i >= 0; i--) 
    {
        if (n >= fib[i]) 
        {
            ans = fib[i]; // 분해된 피보나치 수 
            n -= fib[i];
            
            if (n == 0) break;
        }
    }

    cout << ans << '\n';

    return 0;
}