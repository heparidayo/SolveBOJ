#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int w[26];

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        
        int p = 1; 
        
        for (int j = s.length() - 1; j >= 0; j--)
        {
            w[s[j] - 'A'] += p;
            p *= 10;
        }
    }

    // 가중치 내림차순 정렬
    sort(w, w + 26, greater<int>());

    int ans = 0;
    int num = 9;

    for (int i = 0; i < 26; i++)
    {
        if (w[i] == 0) break; 
        
        ans += w[i] * num;
        num--;
    }

    cout << ans << '\n';

    return 0;
}