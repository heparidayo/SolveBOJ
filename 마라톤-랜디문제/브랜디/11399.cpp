#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
        
    sort(v.begin(), v.end());
    
    int ans = 0;
    int sum = 0;
    for (auto i : v)
    {
        sum += i;
        ans += sum;
    }
    
    cout << ans;
}