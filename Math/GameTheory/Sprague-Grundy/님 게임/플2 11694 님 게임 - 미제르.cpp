// sprague-grundy (스프라그 그런디) 연습 문제
// 상태를 숫자로 치환하고, XOR의 합으로 구한다.

// 님 게임 2 랑 다르게 예외 상황 처리가 필요함 (111) (1111)

#include <iostream>
using namespace std;

int main() 
{
    int n; cin >> n;

    // 모든 돌더미가 1이라면? (111) (1111)
    bool flag = true; 
    int xor_sum = 0;

    for (int i = 0; i < n; i++) 
    {
        int p; cin >> p;

        // 각 돌더미의 개수를 누적해서 XOR
        xor_sum ^= p; 

        // 2개 이상 돌더미가 나온다면 false
        if (p > 1) flag = false; 
    }

    // 모든 돌더미가 1
    if (flag) 
    {
        if (xor_sum == 0) cout << "koosaga\n"; 
        else cout << "cubelover\n";
    }
    // 2개 이상 돌더미 있음
    else 
    {
        if (xor_sum == 0) cout << "cubelover\n";
        else cout << "koosaga\n";
    }

    return 0;
}