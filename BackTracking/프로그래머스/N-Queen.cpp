#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isUsed1[20];
bool isUsed2[20];
bool isUsed3[20];
int ans = 0;

void dfs(int cy, int n)
{
    // base case
    if (cy == n)
    {
        ans++;
        return;
    }
    
    for (int cx = 0; cx < n; cx++)
    {
        // 가지 치기
        if (isUsed1[cx] || isUsed2[cx + cy] || isUsed3[cx - cy + n - 1]) continue;
        
        // 상태 기록
        isUsed1[cx] = true;
        isUsed2[cx + cy] = true;
        isUsed3[cx - cy + n - 1] = true;
        
        // depth + 1
        dfs(cy + 1, n);
        
        // 상태 복구
        isUsed1[cx] = false;
        isUsed2[cx + cy] = false;
        isUsed3[cx - cy + n - 1] = false;
    }
}


int solution(int n) 
{
    dfs(0, n);
    
    return ans;
}

int main()
{
    int n; cin >> n;
    cout << solution(n);

    return 0;
}