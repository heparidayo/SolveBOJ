#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

priority_queue<tuple<int, int, int, int>> pq;

int main()
{
    int n, k;
    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pq.push({ a, b, c, d });
    }
}