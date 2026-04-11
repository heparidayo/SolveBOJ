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

void solve()
{
    int n; cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y;

    // (재활용) 컨벡스 헐 추출
    vector<Point> hull = getConvexHull(v);

    // getConvecxHull은 X좌표순 정렬이라 새로 시작점 찾아야 함 (y가 가장큼 or 만약 y가 같으면 x가 가장 작은 점)
    int st = 0;
    for (int i = 1; i < hull.size(); i++)
    {
        if (hull[i].y > hull[st].y || hull[i].y == hull[st].y && hull[i].x < hull[st].x)
            st = i;
    }

    cout << hull.size() << '\n';

    // ccw -> cw로 방향 뒤집고 (-i)
    // 음수 보정으로 한바퀴 돌리기 (+ hull.size(), % hull.size())
    for (int i = 0; i < hull.size(); i++)
        cout << hull[(st - i + hull.size()) % hull.size()].x << ' ' << hull[(st - i + hull.size()) % hull.size()].y << '\n';
    
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) solve();
}