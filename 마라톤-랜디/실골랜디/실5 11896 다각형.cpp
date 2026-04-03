// #include <iostream>
// using namespace std;
// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     if (a == 1 || a == 2) a = 3;
//     int ans = 0;
//     for (int i = a; i <= b; i++)
//     {
//         if (i%2==0) ans += i;
//     }
//     cout << ans;
// }

#include <iostream>
using namespace std;

long long se(long long n)
{
    long long k = n/2;
    return k*(k+1);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    if (a == 1 || a == 2) a = 3;
    long long ans = se(b) - se(a - 1);
    
    if (ans < 0) ans = 0;
    cout << ans;
}