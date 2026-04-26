#include <iostream>
#include <algorithm>
using namespace std;

// 모든 말의 g 합하기

//  룩 (x-k, y) (x, y-k)
//  g(x, y) = x ^ y

//  비숍 (x-k, y-k)
//  g(x, y) = min(x, y)

//  킹 (x-1, y), (x, y-1), (x-1, y-1)
//  x == y
//  - 짝수 0, 홀수 2
//  - x != y (mn = min(x,y), mx = max(x,y))
//  - mn짝수 - mx 짝수면 0, 홀수면 1
//  - mn홀수 - mx 짝수면 3, 홀수면 2

//  나이트 (x-1, y-2), (x-2, y-1)
//  주기 3
//  - 0 (mx == mn) - mn % 3 이 2일 때만 1, 나머지는 0
//  - 1 (mx == mn+1) - mn % 3 이 0일 때만 0, 나머지는 1
//  - 2 이상 - mn % 3 

//  궁전
//  룩 + 킹 대각선 ~~ 3x3 단위
//  - (x/3) ^ (y/3) * 3
//  - 3x3 내부 - (x%3 + y%3) % 3 
//  - g(x, y) = ((x / 3) ^ (y / 3)) * 3 + ((x % 3 + y % 3) % 3)

int main() 
{
    int n; cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        int x, y;
        char c;
        cin >> x >> y >> c;

        int g = 0;

        if (c == 'R') g = x ^ y;
        else if (c == 'B') g = min(x, y);
        else if (c == 'K') 
        {
            if (x == y) g = (x % 2 == 0) ? 0 : 2;
            else 
            {
                int mn = min(x, y);
                int mx = max(x, y);
                
                if (mn % 2 == 0) g = (mx % 2 == 0) ? 0 : 1;
                else g = (mx % 2 == 0) ? 3 : 2;
            }
        } 
        else if (c == 'N') 
        {
            int mn = min(x, y);
            int mx = max(x, y);
            
            if (mx == mn) g = (mn % 3 == 2) ? 1 : 0;
            else if (mx == mn + 1) g = (mn % 3 == 0) ? 0 : 1;
            else g = mn % 3;
        } 
        else if (c == 'P') 
            g = ((x / 3) ^ (y / 3)) * 3 + ((x % 3 + y % 3) % 3);

        ans ^= g;
    }

    ans > 0 ? cout << "koosaga" : cout << "cubelover";

    return 0;
}