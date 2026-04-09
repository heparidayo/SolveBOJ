#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (0)
    {
        int n; cin >> n;
        if (n == 0) break;

        vector<int> height(n, 0);
        for (int i = 0; i < n; i++)
            cin >> height[i];

        // i번째를 기준으로 left, right
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> lstk;
        stack<int> rstk;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!lstk.empty() && h[lstk.top()] >= left[i])
            {
                ans[i] += h[lstk.top()];
                lstk.pop();
            }
        }


    }
}