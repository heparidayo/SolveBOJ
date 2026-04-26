#include <iostream>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        int a; cin >> a;
        int g = 0;

        // 짝수
        if (k % 2 == 0) 
        {
            if (a == 1) g = 1;
            else if (a == 2) g = 2;
            else if (a % 2 != 0) g = 0;
            else g = 1;
        } 
        // 홀수
        else 
        {
            int tmp = a;
            int cnt = 0;
            while (tmp >= 6 && tmp % 2 == 0) 
            {
                tmp /= 2;
                cnt++;
            }
            
            if (tmp == 1) g = 1;
            else if (tmp == 2) g = 0;
            else if (tmp == 3) g = 1;
            else if (tmp == 4) g = 2;
            else if (tmp % 2 != 0) g = 0;
            
            while (cnt--) 
                g = (g == 1) ? 2 : 1;
        }
        
        ans ^= g;
    }

    ans > 0 ? cout << "Kevin" : cout << "Nicky";

    return 0;
}