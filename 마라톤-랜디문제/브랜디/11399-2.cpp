#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--)
    {
        int x; cin >> x;
        pq.push(x);
    }
    
    int ans = 0;
    int sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        ans += sum;
        pq.pop();
    }
    
    cout << ans;
}