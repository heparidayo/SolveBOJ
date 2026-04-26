// 님 게임 3 루프

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n; cin >> n;
    while(n > 0)
    {
        vector<int> p(n);
        int xor_sum = 0;
        
        // 전체 더미 xor 계산
        for (int i = 0; i < n; i++) 
        {
            cin >> p[i];
            xor_sum ^= p[i];
        }

        int ans = 0;

        // 선공이 이기는 경우만 계산 (xor_sum > 0)
        if (xor_sum > 0) 
            for (int i = 0; i < n; i++) 
                if ((p[i] ^ xor_sum) < p[i]) // 실제로 돌이 줄어드는가?
                    ans++;

        cout << ans << '\n';
        cin >> n;
    }
    

    return 0;
}