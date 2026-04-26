#include <iostream>
using namespace std;

int main() 
{
    int t; cin >> t;
    while (t--) 
    {
        long long s, k;
        cin >> s >> k;
        // k가 홀수일 때
        if (k % 2 == 1) 
        {
            if (s % 2 == 0) cout << 0 << '\n';
            else cout << 1 << '\n';
        } 
        // k가 짝수일 때
        else 
        {
            long long m = s % (k + 1);
            if (m % 2 == 0 && m != k) cout << 0 << '\n'; // m이 k가 아닌 짝수일 때 (필패)
            else if (m % 2 == 1) cout << 1 << '\n'; // m이 홀수일 때 (최소 승리 수는 1)
            else cout << k << '\n'; // m이 k일 때 (최소 승리 수는 k)
                
        }
    }
    
    return 0;
}