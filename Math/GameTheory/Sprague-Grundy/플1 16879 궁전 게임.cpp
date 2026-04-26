#include <iostream>
using namespace std;

//      y\x | 0 1 2 | 3 4 5

//      0   | 0 1 2 | 3 4 5
//      1   | 1 2 0 | 4 5 3
//      2   | 2 0 1 | 5 3 4

//      3   | 3 4 5 | 0 1 2
//      4   | 4 5 3 | 1 2 0
//      5   | 5 3 4 | 2 0 1


// 3x3 (0,1,2 / 1,2,0 / 2,0,1) 반복
// x y를 3으로 나눈 나머지를 더한 뒤, 다시 3으로 나눈 값
// ((x % 3) + (y % 3)) % 3

// 3x3 가장 왼쪽 아래 값(0,0 / 3,0 / 0,3 / 3,3) - 0, 3, 3, 0
// 블록의 좌표(x/3, y/3)를 XOR 연산한 뒤 3을 곱한 값
// ((x / 3) ^ (y / 3)) * 3

// g(x, y) = B(기준) + A(변동)

int main() 
{
    int n; cin >> n;
    int xor_sum = 0;
    
    for (int i = 0; i < n; i++) 
    {
        int x, y;
        cin >> x >> y;
        
        // 그라운디
        int g = ((x / 3) ^ (y / 3)) * 3 + ((x % 3) + (y % 3)) % 3;
        xor_sum ^= g;
    }

    if (xor_sum > 0) cout << "koosaga";
    else cout << "cubelover";

    return 0;
}