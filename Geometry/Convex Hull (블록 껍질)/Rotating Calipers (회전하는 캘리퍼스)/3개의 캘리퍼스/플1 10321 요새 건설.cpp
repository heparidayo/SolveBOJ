// 3개 캘리퍼스 유형 !!

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

long long dotProduct(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}

// 신발끈 공식 (개선)
// 세 점 P1, P2, P3로 이루어진 삼각형의 넓이
long long ccw(Point p1, Point p2, Point p3)
{
    return crossProduct(p2 - p1, p3 - p2);
}

// 거리 (제곱근)
double dist(Point a, Point b) 
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
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



int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) 
    {
        vector<Point> v(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> v[i].x >> v[i].y;
            v[i].id = i;
        }

        vector<Point> hull = getConvexHull(v);
        int h = hull.size();

        if (h <= 2) 
        {
            if (h == 2) cout << 2.0 * dist(hull[0], hull[1]) << '\n';
            else cout << 0.0 << '\n';
            continue;
        }

        double ans = 1e18;
        int t, r, l;
        t = 1;
        r = 1;
        l = 1;

        // 3개의 캘리퍼스 - (top, right, left)
        for (int i = 0; i < h; i++)
        {
            int nxt = (i + 1) % h;
            Point E = hull[nxt] - hull[i]; // 기준 밑변 벡터
            
            // t 캘리퍼스
            while (crossProduct(E, hull[(t + 1) % h] - hull[t % h]) >= 0) 
                t++;
            
            // r 너비 캘리퍼스
            while (dotProduct(E, hull[(r + 1) % h] - hull[r % h]) >= 0) 
                r++;
            
            // l 너비 캘리퍼스 
            if (i == 0) l = r; // (첫 기준선에서는 r부터 탐색 시작)
            while (dotProduct(E, hull[(l + 1) % h] - hull[l % h]) <= 0) 
                l++;
            
            double base = dist(hull[i], hull[nxt]);
            if (base == 0) continue;
            
            // 외적으로 직사각형의 높이
            double height = (double)crossProduct(E, hull[t % h] - hull[i]) / base;
            
            // 내적으로 직사각형 너비 (우측 투영 길이 - 좌측 투영 길이)
            double width = (double)(dotProduct(E, hull[r % h] - hull[i]) - dotProduct(E, hull[l % h] - hull[i])) / base;
            
            // 둘레
            double perim = 2.0 * (height + width);
            if (perim < ans) ans = perim;
        }

        cout << ans << '\n';
    }

    return 0;
}