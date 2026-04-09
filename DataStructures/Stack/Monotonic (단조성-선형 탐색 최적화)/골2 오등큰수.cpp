// 이전에 푼거 깔끔하게 정리

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    vector<int> a(n);
    vector<int> af(1000001, 0);   // 실제 숫자들의 등장 빈도 1 ≤ Ai ≤ 1,000,000
    vector<int> ans(n, -1); // 없으면 -1
    stack<int> stk;         // idx 저장

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        af[a[i]]++; // 등장 빈도 기록
    }

    // a수열의 i인덱스를 처리한다
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && af[a[stk.top()]] < af[a[i]])
        {
            ans[stk.top()] = a[i];
            stk.pop(); // 오큰수 제거
        }

        stk.push(i);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}