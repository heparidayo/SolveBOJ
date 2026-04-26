#include <iostream>
using namespace std;

// N값이 엄청 커서 DP/MEX로는 안댐
// 모듈러 규칙 찾아야 함
// 1 4 16 64
// 4^0 = 1, 1 % 5 = 1
// 4^1 = 4, 4 % 5 = 4
// 4^2 = 16, 16 % 5 = 1
// 4^3 = 64, 64 % 5 = 4
// 항상 5로 나누면 1/5 반복됨
// 몇개를 가져가든 항상 돌은 1 or 4개 가져가는거랑 같다.

int main()
{
    long long n;
    cin >> n;

    // 나머지 0/2 면 CY 승리
    if (n % 5 == 0 || n % 5 == 2) cout << "CY";
    else cout << "SK";

    return 0;
}