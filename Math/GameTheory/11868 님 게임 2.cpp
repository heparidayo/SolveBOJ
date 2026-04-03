// sprague-grundy (스프라그 그런디) 연습 문제

#include <iostream>
using namespace std;

int main() 
{
    int n; cin >> n;

    int xor_sum = 0;
    for (int i = 0; i < n; i++) 
    {
        int p; cin >> p;
        xor_sum ^= p; // 각 돌더미의 개수를 누적해서 XOR
    }

    // xor_sum 합이 0이면 후공 승리
    if (xor_sum == 0) cout << "cubelover\n"; 
    else cout << "koosaga\n";

    return 0;
}