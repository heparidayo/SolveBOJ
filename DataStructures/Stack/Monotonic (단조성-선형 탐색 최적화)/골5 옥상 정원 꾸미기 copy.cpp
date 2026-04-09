#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    stack<int> stk;

    // 오아시스 유형 문제 - 단조 스택 (내림차순)으로 풀이
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int h; cin >> h;

        // 시야 막힌 빌딩은 모두 제거
        while (!stk.empty() && stk.top() <= h)
            stk.pop();
            
        // 내림차순 상태 - 내려다 보는게 가능함
        ans += stk.size();
        stk.push(h);
    }

    cout << ans;

    return 0;
}