#include <iostream>
using namespace std;

// 라스커의 님 게임 그라운디 패턴
// g(0) = 0
// g(1) = 1
// g(2) = 2
// g(3) = mex(0, 1, 2, g(1)^g(2)) = mex(0, 1, 2, 3) = 4
// g(4) = mex(0, 1, 2, 4, g(1)^g(3), g(2)^g(2)) = mex(0, 1, 2, 4, 5, 0) = 3
// x % 4 == 1 or 2  => g(x) = x
// x % 4 == 3       => g(x) = x + 1
// x % 4 == 0       => g(x) = x - 1
 
long long g(long long x) 
{
    if (x % 4 == 0) return x - 1;
    if (x % 4 == 1) return x;
    if (x % 4 == 2) return x;
    if (x % 4 == 3) return x + 1;
    return 0;
}

int main() 
{
    int n; cin >> n;
    long long xor_sum = 0;
    
    for (int i = 0; i < n; i++) 
    {
        long long p;
        cin >> p;
        
        xor_sum ^= g(p);
    }

    // 최종 판별
    if (xor_sum > 0) cout << "koosaga";
    else cout << "cubelover";

    return 0;
}