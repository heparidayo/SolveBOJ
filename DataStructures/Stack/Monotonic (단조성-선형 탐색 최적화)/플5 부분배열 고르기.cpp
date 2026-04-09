// monotonic stack + preifx sum 풀이 - O(N)
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    #define int long long
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n+1, 0);
    vector<int> sum(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = (a[i] + sum[i - 1]);
    }

    // 최솟값의 경계 left/right를 따로 구하기

    vector<int> left(n+1, 0);
    stack<int> stk_left;
    for (int i = 1; i <= n; i++)
    {
        // 최소값이 안됨 - 탈락
        while (!stk_left.empty() && a[stk_left.top()] >= a[i])
            stk_left.pop();

        if (stk_left.empty())
            left[i] = 0;
        else
            left[i] = stk_left.top();

        stk_left.push(i); // 추후 오른쪽 원소들의 left 경계 후보 idx
    }

    vector<int> right(n+1, 0);
    stack<int> stk_right;
    for (int i = n; i >= 1; i--)
    {
        while (!stk_right.empty() && a[stk_right.top()] >= a[i])
            stk_right.pop();
        
        if (stk_right.empty())
            right[i] = n + 1;
        else
            right[i] = stk_right.top();

        stk_right.push(i); // 왼쪽 원소들의 right 경계 후보
    }
    
    // sum(i ~ j) * min(i ~ j) 이고, 항상 a[i]가 최소값이라고 가정
    // 인덱싱 실수.. right[i]은 경계 자체의 idx이므로 실제 데이터는 그 전인 -1까지만
    // left[i]는 누적합이니까 그대로 쓰기
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max((sum[right[i] - 1] - sum[left[i]]) * a[i], ans);
    
    cout << ans;
    return 0;
}