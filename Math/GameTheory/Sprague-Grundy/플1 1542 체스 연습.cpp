#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int g[105][105];

int main() 
{
    // 그라운디 100까지
    for (int i = 1; i <= 100; i++) 
    {
        for (int j = 1; j <= 100; j++) 
        {
            // 가로/세로/대각선
            if (i == j) continue; 
            vector<bool> visit(1005, false);

            // 가로
            for (int k = 1; k <= i; k++) 
            {
                int nx = i - k;
                int ny = j;
                if (nx != 0 && ny != 0 && nx != ny) visit[g[nx][ny]] = true;
            }
            
            // 세로
            for (int k = 1; k <= j; k++) 
            {
                int nx = i;
                int ny = j - k;
                if (nx != 0 && ny != 0 && nx != ny) visit[g[nx][ny]] = true;
            }
            
            // 대각선
            for (int k = 1; k <= min(i, j); k++) 
            {
                int nx = i - k;
                int ny = j - k;
                if (nx != 0 && ny != 0 && nx != ny) visit[g[nx][ny]] = true;
            }

            // mex
            int mex = 0;
            while (visit[mex]) mex++;
            g[i][j] = mex;
        }
    }

    int n;
    while (cin >> n) 
    {
        int ans = 0;
        bool isWin = false;
        for (int i = 0; i < n; i++) 
        {
            int x, y;
            cin >> x >> y;
            
            // 시작 부터 위험 지역
            if (x == 0 || y == 0 || x == y) isWin = true;
            else ans ^= g[x][y];
        }

        isWin || ans > 0 ? cout << "S\n" : cout << "D\n";
    }

    return 0;
}