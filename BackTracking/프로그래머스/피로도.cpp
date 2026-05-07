#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isUsed[8]; 
int ans = -1;

void dfs(int depth, int ck, vector<vector<int>> dungeons)
{
    ans = max(ans, depth);

    for (int i = 0; i < dungeons.size(); i++)
    {
        // 가지 치기 (이미 방문 or 최소 피로도 미만)
        if (isUsed[i] || ck < dungeons[i][0]) continue;

        // 상태 기록
        isUsed[i] = true;

        // depth + 1
        dfs(depth + 1, ck - dungeons[i][1], dungeons);

        // 상태 복구
        isUsed[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) 
{
    dfs(0, k, dungeons);

    return ans;
}

int main()
{
    vector<vector<int>> vec({{ 80, 20 }, { 50, 40 }, { 30, 10 }});
    cout << solution(80, vec);
}