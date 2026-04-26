#include <iostream>
using namespace std;

int main() 
{
    int n; cin >> n;

    long long ans = 0;
    for (int i = 0; i < n; i++) 
    {
        long long x, m;
        cin >> x >> m;

        long long l = x - 1;
        long long r = x + m - 1;

        // 1 -> r xor 합 주기 4
        long long xor_l = (l % 4 == 0) ? l : 
                          (l % 4 == 1) ? 1 : 
                          (l % 4 == 2) ? l + 1 : 0;

        // 1 -> r xor 합 주기 4
        long long xor_r = (r % 4 == 0) ? r : 
                          (r % 4 == 1) ? 1 : 
                          (r % 4 == 2) ? r + 1 : 0;
        
        // 전체 xor 합 구간 누적
        ans ^= (xor_l ^ xor_r);
    }

    ans > 0 ? cout << "koosaga" : cout << "cubelover";

    return 0;
}