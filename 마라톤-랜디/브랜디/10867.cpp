// set으로 대츙
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    while (n--)
    {
        int x; cin >> x;
        s.insert(x);
    }
    
    for (auto i : s)
        cout << i << ' ';
}