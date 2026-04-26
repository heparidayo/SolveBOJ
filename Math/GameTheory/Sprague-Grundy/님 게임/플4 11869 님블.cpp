// 좌표(거리) 자체가 돌 더미 크기가 되는 느낌
// 님 게임 공간 변곃 

#include <iostream>
using namespace std;

int main() 
{
    int m; cin >> m;

    long long xor_sum = 0;
    for (int i = 0; i < m; i++) 
    {
        // 동전의 위치 값 자체가 돌더미 갯수
        long long p; cin >> p;
        xor_sum ^= p;
    }

    if (xor_sum > 0) cout << "koosaga";
    else cout << "cubelover";

    return 0;
}