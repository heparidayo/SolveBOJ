#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    stack<char> stack;
    string str;
    string answer = "";
    
    while (getline(cin, str))
    {
        if (str == ".")
            break;
        
        while (!stack.empty())
            stack.pop();
        
        answer = "yes";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                stack.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (stack.empty() || stack.top() != '(')
                {
                    answer = "no";
                    break;
                }
                stack.pop();
            }
            else if (str[i] == ']')
            {
                if (stack.empty() || stack.top() != '[')
                {
                    answer = "no";
                    break;
                }
                stack.pop();
            }
        }
        
        if (!stack.empty())
            answer = "no";
        
        cout << answer << endl;
    }
    
    return 0;
}
