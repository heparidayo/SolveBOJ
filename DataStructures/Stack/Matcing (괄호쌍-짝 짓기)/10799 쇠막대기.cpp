#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s; cin >> s;
    
    int ans = 0;
    stack<char> stk;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') stk.push('('); // 막대 + 1
        else 
        {
            stk.pop();
            
            if (s[i - 1] == '(') ans += stk.size(); // 레이저
            else ans += 1; // 막대 -1
        }
    }
    
    cout << ans;
}