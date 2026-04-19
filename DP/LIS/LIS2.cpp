/*
C# 으로 재구현 할 문제
*/



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a, ans;

//이진 검색 알고리즘 구현
//binary search


// 이분검색이랑 매우 비슷함
// 어차피 LIS는 선형 {1 2 3} 의 구조니까
// 이분 하고 왼쪽에서 검색.
// 못찾으면 오른쪽에서 검색.
// 반복하면서 현재 최소값이 상한을 넘기 전에 멈추는 원리
int idx_bsearch(int k)
{
    int lo = 0;                 // 최소 (좌측)
    int mid;                    // 커서 (중앙)
    int hi = ans.size() - 1;    // 최대 (우측)

    while (lo < hi)                 // 현재 로우가 하이보다 작다면?
    {
        mid = lo + (hi - lo) / 2;   // 로우 + (로우와 하이의 거리 / 2) == 중앙

        if (ans[mid] >= k)          // 커서가 가르키는 값이 k보다 크다면
            hi = mid;               // 최대값에 커서값을 저장
        else
            lo = mid + 1;           // 이분해서 검색하지 못한 오른쪽 공간을 검색하기 위해서 lo에 mid+1(오른쪽) 넣어줌
    }

    return hi;                  
}






int main(void)
{
    // 10 20 30 15 20 25 50 45 55 60
    // 10
    // 10 20
    // 10 20 30 
    // 10 20 30 . 15와 만남
    // 10 20 30 . 15 보다 크면서 가장 차이가 적은 원소를 LIS에서 찾음, 그후 대체
    // 10 15 30
    // 이런식으로 하면
    // 1. 현재 길이가 보전된다.(최대 길이가 줄지 않는다.)
    // 2. 추후의 새로운 LIS가 생기는 상황을 대처할 수 있다.

    int n, t, idx;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t; a.push_back(t);
    }
    ans.push_back(a.front()); // 정답 벡터 1 초기화


    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans.back())  // LIS수열 뒷부분 보다 큰 수와 만나면?
            ans.push_back(a[i]);// LIS수열 뒤에 그 수를 추가한다.

        else
        {
            // LIS 수열 뒷부분 보다 작은 수와 만나면
            // LIS 수열에서 해당 수와 가장 차이가 적으면서
            // 해당 수 보다는 큰 숫자를 찾아서 자리르 바꾼다.
            // 이진 검색 시작
            idx = idx_bsearch(a[i]);
            ans[idx] = a[i];
        }
    }

    cout << ans.size();
    return 0;
}
