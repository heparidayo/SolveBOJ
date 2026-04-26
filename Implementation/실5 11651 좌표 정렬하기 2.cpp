#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n; cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        pq.push({ y, x });
    }
    while (!pq.empty())
    {
        auto cur = pq.top();
        cout << cur.second << ' ' << cur.first << '\n';
        pq.pop();
    }

    return 0;
}