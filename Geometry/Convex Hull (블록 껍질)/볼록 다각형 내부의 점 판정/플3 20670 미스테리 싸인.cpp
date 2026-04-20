// 기하 문제 (ccw, convex hull 등의 문제를 풀기 위한 템플릿 코드)
// 사용 알고리즘은 monotone chain (O(n log n))
// 추가로 벡터 외적 함수와 ccw, 다각형 내부에 점 포함 여부 함수
// dist(sqrt) 추가
// == 연산자와 id 추가
// 3차원용 주석 처리
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int id;
    long long x, y;

    bool operator < (const Point& p) const 
    {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    Point operator - (const Point& p) const 
    {
        return { 0, x - p.x, y - p.y };
    }
    bool operator == (const Point& p) const
    {
        return x == p.x && y == p.y;
    }
};

long long crossProduct(Point a, Point b) 
{
    return a.x * b.y - a.y * b.x;
}

// 신발끈 공식 (개선)
// 세 점 P1, P2, P3로 이루어진 삼각형의 넓이
long long ccw(Point p1, Point p2, Point p3)
{
    return crossProduct(p2 - p1, p3 - p2);
}

// 다각형 내부에 점 p가 완전히 포함되어 있는지 -- 이분 탐색으로 최적화. log N
bool isInside(vector<Point> hull, Point p) 
{
    int n = hull.size();
    if (n < 3) 
    {
        if (n == 0) return false;
        if (n == 1) return p == hull[0];
        if (n == 2) 
        {
            return ccw(
                hull[0], hull[1], p) == 0 &&
                p.x >= min(hull[0].x, hull[1].x) && p.x <= max(hull[0].x, hull[1].x) &&
                p.y >= min(hull[0].y, hull[1].y) && p.y <= max(hull[0].y, hull[1].y);
        }
    }
    
    // 점이 기준점과 이루는 양 극단의 범위를 벗어나는 경우
    if (ccw(hull[0], hull[1], p) < 0) return false;
    if (ccw(hull[0], hull[n - 1], p) > 0) return false;

    // 이분 탐색으로 점이 위치할 수 있는 삼각형 영역(wedge) 탐색 // 직관편하게 low-high로 변수 잡았음
    int low = 1, high = n - 1;
    while (low + 1 < high) 
    {
        int mid = (low + high) / 2;
        if (ccw(hull[0], hull[mid], p) >= 0) 
            low = mid;
        else 
            high = mid;
    }
    
    // 찾은 구간의 바깥 변에 대해 CCW를 수행하여 내부 여부 최종 판별
    return ccw(hull[low], hull[high], p) >= 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<Point> A(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i].x >> A[i].y;
        A[i].id = i;
    }

    vector<Point> B(m);
    for (int i = 0; i < m; i++) 
    {
        cin >> B[i].x >> B[i].y;
        B[i].id = i;
    }

    int ans = 0;
    for (int i = 0; i < k; i++) 
    {
        Point p;
        p.id = i;
        cin >> p.x >> p.y;

        bool inA = isInside(A, p);
        bool inB = isInside(B, p);

        // 점이 A 외부 or B 내부에 있으면 X
        if (!inA || inB) ans++;
    }

    ans == 0 ? cout << "YES" : cout << ans;

    return 0;
}