// 님 게임 변형 - 홀짝
// 짝수개 제거 - 전체 제거 x
// - 남은 돌의 개수는 무조건 원래 개수와 홀짝이 같음 (짝수: 짝수/짝수, 홀수: 짝수/홀수)

// 홀수개 제거 - 무조건 전체 제거 O
// - 돌더미가 홀수일 때만 0개로 한 번에 만들 수 있음

// 돌이 0/2개 남으면 종료 
// g(0) = 0
// G(2) = 0

// 정리
// - 돌이 홀수 g(x) = (x + 1) / 2
// - 돌이 짝수 g(x) = (x / 2) - 1

// 각 돌 더미의 g값을 구해서 xor
// - 누적 XOR 값이 > 0 : 선공 승리 (이기는 수가 존재함)
// - 누적 XOR 값이 == 0 : 후공 승리 (어떻게 둬도 상대방이 이김)

#include <iostream>
using namespace std;

int main() 
{
    int n; cin >> n;

    long long xor_sum = 0;
    for (int i = 0; i < n; i++) 
    {
        long long p;
        cin >> p;
        
        long long g;
        if (p % 2 == 1) g = (p + 1) / 2;
        else g = (p / 2) - 1;
        
        xor_sum ^= g;
    }

    if (xor_sum > 0) cout << "koosaga";
    else cout << "cubelover";

    return 0;
}