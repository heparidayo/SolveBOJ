#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
vector<int> tmp;
int main()
{
    int n;
    cin >> n;

    int a, b, c;
    for (b = 0; b <= n; b++)
    {
        a = n;
        tmp.push_back(a);
        tmp.push_back(b);
        int t1 = a;
        int t2 = b;
        while (true)
        {
            c = t1 - t2;
            if (c < 0) break;
            tmp.push_back(c);
            t1 = t2;
            t2 = c;
        }

        if (ans.size() < tmp.size())
            ans = tmp;
        tmp.clear();
    }


    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

}