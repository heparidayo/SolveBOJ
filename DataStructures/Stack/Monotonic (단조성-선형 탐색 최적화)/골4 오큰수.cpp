#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    stack<int> stk; // idx
    vector<int> ans(n, -1); // 오큰수 없는곳 미리 -1로 초기화
    
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty())
        {
            // 단조성이 깨짐
            if (v[stk.top()] < v[i])
            {
                ans[stk.top()] = v[i];
                stk.pop();
            }
            // 단조 감소 유지됨
            else break;
        }
        
        stk.push(i);
    }
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    
    return 0;
}