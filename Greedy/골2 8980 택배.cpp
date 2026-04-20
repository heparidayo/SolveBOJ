#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box 
{
    int st, ed, x;
};

bool cmp(Box a, Box b) 
{
    if (a.ed == b.ed) return a.st < b.st;
    return a.ed < b.ed;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c, m;
    cin >> n >> c; 
    cin >> m;      

    vector<Box> bvec(m);
    for (int i = 0; i < m; i++) 
        cin >> bvec[i].st >> bvec[i].ed >> bvec[i].x;

    sort(bvec.begin(), bvec.end(), cmp);

    vector<int> vec(n + 1, 0);
    int ans = 0;

    for (int i = 0; i < m; i++) 
    {
        int tmp = 0;
        for (int j = bvec[i].st; j < bvec[i].ed; j++) 
            tmp = max(tmp, vec[j]);

        ans += min(bvec[i].x, c - tmp);
        for (int j = bvec[i].st; j < bvec[i].ed; j++) 
            vec[j] += min(bvec[i].x, c - tmp);;
    }

    cout << ans;

    return 0;
}