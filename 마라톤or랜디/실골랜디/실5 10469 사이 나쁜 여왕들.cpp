#include <iostream>
using namespace std;
char map[8][8];
int main()
{int cnt  = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> map[i][j];if(map[i][j] == '*')cnt++;}}if(cnt < 8) { cout << "invalid";
                return 0; }
            for (int i = 0; i < 8; i++)
            {
            for (int j = 0; j < 8; j++)    
            {
                if (map[i][j] == '*')
                {
                    for (int ix = 0; ix < 8; ix++)
                    {
                        if (ix == i) continue;
                        if (map[ix][j] == '*')
                        {
                            cout << "invalid";
                            return 0;
                        }
                    }
                    for (int jy = 0; jy < 8; jy++)
                    {
                        if (jy == j) continue;
                        if (map[i][jy] == '*')
                        {
                            cout << "invalid";
                            return 0;
                        }
                    }
                    for (int dir = 0; dir < 4; ++dir)
{
    int dx[4] = { 1, -1, 1, -1 };
    int dy[4] = { -1, 1, 1, -1 };
    int nx = i + dx[dir];
    int ny = j + dy[dir];
    while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
    {
        if (map[nx][ny] == '*')
        {
            cout << "invalid";
            return 0;
        }
        nx += dx[dir];
        ny += dy[dir];
    }
}
                }
            }  
            }cout << "valid";
}