// g(0) = 0
// g(sum) = mex(0, 1, 2, ... , sum-1) = sum

// 그라운디가 2 -> 내가 원하면 다음 턴 상대를 g=0 or g=1 로 강제 가능

#include <iostream>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    long long xor_sum = 0;
    
    for (int i = 0; i < n; i++) 
    {
        long long sum = 0;
        
        // 각 행의 합
        for (int j = 0; j < m; j++) 
        {
            long long x;
            cin >> x;
            sum += x;
        }
        
        // 행의 합이 요 게임(행) 그라운디 수 ==> XOR 연산
        xor_sum ^= sum;
    }

    if (xor_sum > 0) cout << "august14";
    else cout << "ainta";

    return 0;
}