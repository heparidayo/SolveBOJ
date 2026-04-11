#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long ans = 0;
    stack<pair<int, int>> stk; // 높이, 같은 키

    for (int i = 0; i < n; i++)
    {
        int cur = v[i];
        int cnt = 1;

        // 왼쪽 검사 - cur보다 작거나 같은 사람 처리 (cur이 시야 가림)
        while (!stk.empty() && stk.top().first <= cur)
        {
            ans += stk.top().second;
            
            if (stk.top().first == cur) // 같은 키 압축
                cnt += stk.top().second;

            stk.pop();
        }

        // 단조 감소 깨짐 - cur보다 큰 사람에 왼쪽 시야 막힘
        if (!stk.empty())
            ans += 1;

        stk.push({ cur, cnt });
    }
    
    cout << ans;
}