#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    while (true)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        string s; getline(cin, s);
        if (s == ".") break;
        
        bool ans = true;
        stack<char> stk;

        for (char c : s)
        {
            if (c == '(' || c == '[') stk.push(c);

            else if (c == ')')
            {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else
                {
                    ans = false;
                    break;
                }
            }
            else if (c == ']')
            {
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else
                {
                    ans = false;
                    break;
                }
            }
        }

        if (!stk.empty()) ans = false;
        cout << (ans ? "yes\n" : "no\n");
    }
}