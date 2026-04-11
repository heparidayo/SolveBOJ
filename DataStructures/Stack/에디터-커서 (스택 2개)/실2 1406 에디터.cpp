#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    stack<char> lstk;
    stack<char> rstk;

    // 전부 왼쪽 스택에 넣음
    for (char c : s) 
        lstk.push(c);

    int m; cin >> m;
    while (m--) 
    {
        char x;
        cin >> x;

        if (x == 'L') 
        {
            // 커서 <- | 좌 -> 우
            if (!lstk.empty()) 
            {
                rstk.push(lstk.top());
                lstk.pop();
            }
        } 
        else if (x == 'D') 
        {
            // 커서 -> | 좌 <- 우
            if (!rstk.empty()) 
            {
                lstk.push(rstk.top());
                rstk.pop();
            }
        } 
        else if (x == 'B') 
        {
            // 커서 왼쪽 삭제
            if (!lstk.empty()) 
                lstk.pop();
        } 
        else if (x == 'P') 
        {
            // 커서 왼쪽 추가
            char c; cin >> c;
            lstk.push(c);
        }
    }

    while (!lstk.empty()) 
    {
        rstk.push(lstk.top());
        lstk.pop();
    }

    while (!rstk.empty()) 
    {
        cout << rstk.top();
        rstk.pop();
    }
    cout << '\n';

    return 0;
}