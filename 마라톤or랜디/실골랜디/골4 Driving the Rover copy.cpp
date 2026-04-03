#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <math.h>
using namespace std;

// 상 좌 하 우
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int main() 
{
    int k; cin >> k;
    for (int cnt = 1; cnt <= k; cnt++) 
    {
        int n; cin >> n;

        int x = 0;
        int y = 0;
        int dir = 0; 
        int v = 0; 

        string s;
        for (int i = 0; i < n; i++) 
        {
            cin >> s;

            if (s == "FORWARD" && v == 0) 
            {
                v = 1;
            } 
            else if (s == "BACKWARD" && v == 0) 
            {
                v = -1;
            } 
            else if (s == "FASTER" && v > 0) 
            {
                v = min(5, v + 1);
            } 
            else if (s == "SLOWER" && v > 0) 
            {
                v = v - 1;
            } 
            else if (s == "STOP") 
            {
                v = 0;
            } 
            else if (s == "LEFT" && v == 0) 
            {
                dir = (dir + 1) % 4;
            } 
            else if (s == "RIGHT" && v == 0) 
            {
                if (dir > 0) dir = dir - 1;
                else dir = 3;
            } 
            else 
            {
                
            }

            x += dx[dir] * v;
            y += dy[dir] * v;
        }

        cout << "Data Set " << cnt << ":" << '\n';
        cout << x << ' ' << y << "\n\n";
    }

    return 0;
}
