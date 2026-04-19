// 기하 문제 (ccw, convex hull 등의 문제를 풀기 위한 템플릿 코드)
// monotone chain (O(n log n))
// 추가로 벡터 외적 함수와 ccw 함수 포함

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    long long x, y;
    // 좌표 정렬용 연산자 오버로딩 추가
    bool operator < (const Point& p) const 
    {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    Point operator - (const Point& p) const 
    {
        return { x - p.x, y - p.y };
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

// monotone chain
vector<Point> getConvexHull(vector<Point> points) 
{
    int n = points.size();
    if (n <= 2) return points;

    sort(points.begin(), points.end());

    vector<Point> hull;
    
    // lower hull
    for (int i = 0; i < n; i++) 
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i]) <= 0) 
            hull.pop_back();
        hull.push_back(points[i]);
    }

    // upper hull - 역순
    int lower = hull.size();
    for (int i = n - 2; i >= 0; i--) 
    {
        while (hull.size() > lower && ccw(hull[hull.size() - 2], hull.back(), points[i]) <= 0) 
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back(); 

    return hull;
}

// 다각형 내부에 점 p가 완전히 포함되어 있는지
bool isInside(vector<Point> hull, Point p) 
{
    if (hull.size() < 3) return false;
    
    for (int i = 0; i < hull.size(); i++) 
    {
        int vec = (i + 1) % hull.size();
        // 볼록 다각형의 선분에 대해 하나라도 우회전이거나 일직선상에 있다면 외부/경계
        if (ccw(hull[i], hull[vec], p) <= 0) 
            return false;
    }
    return true;
}

int main() 
{
    int n; 
    Point prison;
    cin >> n >> prison.x >> prison.y;

    vector<Point> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i].x >> v[i].y;

    int ans = 0;

    // 점이 3개 이상 남아있는 동안 껍질 벗기기
    while (v.size() >= 3) 
    {
        vector<Point> hull = getConvexHull(v);

        // 감옥이 껍질 내부에 없다면 더 이상 둘러쌀 수 없으므로 종료
        if (!isInside(hull, prison)) break;

        ans++;

        // 사용된 껍질의 점들을 전체 집합에서 제거
        vector<Point> vec;
        for (auto p : v) 
        {
            bool inHull = false;
            for (auto hp : hull) 
            {
                if (p == hp) 
                {
                    inHull = true;
                    break;
                }
            }
            if (!inHull) vec.push_back(p);
        }
        v = vec; // 점 집합 갱신
    }

    cout << ans << '\n';
    return 0;
}