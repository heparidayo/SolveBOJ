#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        // 스택이 비어있지 않고, 마지막 숫자가 들어올 숫자보다 작고, 아직 지울 수 있음
        while (!ans.empty() && ans.back() < s[i] && k > 0)
        {
            ans.pop_back(); 
            k--;            
        }

        ans.push_back(s[i]); 
    }

    if (k > 0) ans.erase(ans.length() - k);

    cout << ans << '\n';

    return 0;
}