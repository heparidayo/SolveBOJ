#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() 
{
    int n; cin >> n;

    vector<set<int>> s(n + 1);
    int xor_sum = 0; 
    int c = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++) 
    {
        int f; cin >> f;
        s[i].insert(f);
        
        xor_sum ^= 1;
        c++;
    }

    vector<int> vvec(n + 1);
    vector<bool> bvec(n + 1);
    vector<int> cvec(n + 1);

    // 1일차
    vvec[1] = xor_sum;
    bvec[1] = (cnt > 0);
    cvec[1] = c;

    for (int k = 1; k <= n - 1; k++) 
    {
        int u, v; 
        cin >> u >> v;

        int usz = s[u].size();
        int vsz = s[v].size();

        // u, v의 크기를 게임 상태에서 제거
        xor_sum ^= usz;
        xor_sum ^= vsz;
        if (usz == 1) c--;
        if (usz > 1) cnt--;
        if (vsz == 1) c--;
        if (vsz > 1) cnt--;

        // small to large
        if (s[u].size() > s[v].size()) 
            swap(s[u], s[v]);
        for (int x : s[u]) 
            s[v].insert(x);
        s[u].clear();

        // 합쳐진 새로운 v의 크기 추가
        int nsz = s[v].size();
        xor_sum ^= nsz;
        if (nsz == 1) c++;
        if (nsz > 1) cnt++;

        // day k+1 기록
        vvec[k + 1] = xor_sum;
        bvec[k + 1] = (cnt > 0);
        cvec[k + 1] = c;
    }

    // n일차에서 1일차로 역방향 전파
    bool flag = true;
    bool ans = true;
    for (int k = n; k >= 1; k--) 
    {
        if (bvec[k]) ans = (vvec[k] > 0);
        else ans = ((cvec[k] % 2 == 1) == flag);
        
        flag = ans;
    }

    (ans) ? cout << "Sejong\n" : cout << "Areum\n";

    return 0;
}