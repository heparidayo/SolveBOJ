// 일반 님 게임과 다르게, 바로 합치면 안되고 상태를 직접 구해야 함 (MEX)

#include <iostream>
#include <vector>
using namespace std;

int DP[1005];
bool visit[1005];

int main() 
{
    int n; cin >> n;
    for (int i = 2; i <= n; i++) 
    {
        vector<bool> visit(n + 1, false);
        for (int j = 0; j <= i - 2; j++) 
        {
            int l = j;
            int r = i - 2 - j;

            int nxt = DP[l] ^ DP[r];
            if (nxt <= i) visit[nxt] = true;
        }

        int mex = 0;
        while (visit[mex]) mex++;
        
        DP[i] = mex;
    }

    DP[n] > 0 ? cout << 1 : cout << 2;

    return 0;
}