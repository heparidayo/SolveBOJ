#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n; cin >> n;
    priority_queue<int> pq;
    int x; cin >> x;
    n -= 1;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    while (n--)
    {
        int xx; cin >> xx;
        pq.push(xx);
    }

    int cnt = 0;
    while (x <= pq.top())
    {
        int xx = pq.top(); pq.pop();
        x += 1;
        cnt += 1;
        xx -= 1;
        pq.push(xx);
    }

    cout << cnt;
}