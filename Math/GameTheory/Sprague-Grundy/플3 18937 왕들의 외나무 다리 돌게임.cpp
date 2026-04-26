#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int n; cin >> n;
    long long xor_sum = 0;
    
    // 다리의 값 = 칸 - 2
    for (int i = 0; i < n; i++) 
    {
        long long a; cin >> a;
        xor_sum ^= (a - 2);
    }

    string s;
    cin >> s;

    if (xor_sum > 0) cout << s;
    else if (s == "Whiteking") cout << "Blackking";
    else cout << "Whiteking";

    return 0;
}