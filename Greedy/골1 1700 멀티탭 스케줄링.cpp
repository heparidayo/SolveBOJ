#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(k);
    for (int i = 0; i < k; i++)
        cin >> v[i];

    vector<int> plug;
    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        // 이미 꽂힘
        if (find(plug.begin(), plug.end(), v[i]) != plug.end()) continue;

        // 멀티탭에 빈자리
        if (plug.size() < n)
        {
            plug.push_back(v[i]);
            continue;
        }

        int idx = -1;
        int mx = -1;

        for (int j = 0; j < plug.size(); j++)
        {
            int nxt = 0x3f3f3f3f; 

            for (int m = i + 1; m < k; m++)
            {
                if (plug[j] == v[m])
                {
                    nxt = m;
                    break;
                }
            }

            if (nxt > mx)
            {
                mx = nxt;
                idx = j;
            }
        }

        // 플러그 교체
        plug[idx] = v[i];
        ans++;
    }

    cout << ans;

    return 0;
}