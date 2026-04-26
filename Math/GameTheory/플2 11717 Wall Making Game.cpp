#include <iostream>
#include <string>
using namespace std;

int dp[25][25][25][25];

int visit[1005];
string map[25];

int main() 
{
    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++) 
        cin >> map[i];

    int tmp = 0;
    for (int cx = 1; cx <= h; cx++) 
    {
        for (int cy = 1; cy <= w; cy++) 
        {
            for (int x1 = 0; x1 <= h - cx; x1++) 
            {
                for (int y1 = 0; y1 <= w - cy; y1++) 
                {
                    int x2 = x1 + cx - 1;
                    int y2 = y1 + cy - 1;

                    tmp++;
                    for (int nx = x1; nx <= x2; nx++) 
                    {
                        for (int ny = y1; ny <= y2; ny++) 
                        {
                            if (map[nx][ny] == '.') 
                            {
                                // 4방탐색
                                int g1 = (nx > x1 && ny > y1) ? dp[x1][nx - 1][y1][ny - 1] : 0; // 좌상단
                                int g2 = (nx > x1 && ny < y2) ? dp[x1][nx - 1][ny + 1][y2] : 0; // 우상단
                                int g3 = (nx < x2 && ny > y1) ? dp[nx + 1][x2][y1][ny - 1] : 0; // 좌하단
                                int g4 = (nx < x2 && ny < y2) ? dp[nx + 1][x2][ny + 1][y2] : 0; // 우하단

                                // 다음 상태의 님합
                                int nxt = g1 ^ g2 ^ g3 ^ g4;
                                if (nxt < 1000) visit[nxt] = tmp;
                            }
                        }
                    }

                    // mex 
                    int mex = 0;
                    while (visit[mex] == tmp) mex++;
                    dp[x1][x2][y1][y2] = mex;
                }
            }
        }
    }

    dp[0][h - 1][0][w - 1] > 0 ? cout << "First" : cout << "Second";

    return 0;
}