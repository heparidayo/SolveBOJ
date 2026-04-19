#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end()); // 오름차순

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (ans < a[i]) break;
        ans += a[i];
    }

    cout << ans << '\n';

    return 0;
}