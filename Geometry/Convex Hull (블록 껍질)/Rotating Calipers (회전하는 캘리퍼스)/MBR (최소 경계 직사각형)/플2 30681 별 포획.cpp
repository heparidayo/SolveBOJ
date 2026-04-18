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

// 벡터 외적
long long crossProduct(Point a, Point b) 
{
    return a.x * b.y - a.y * b.x;
}

// 벡터 내적 (정사영 길이 계산용)
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

// 다각형 넓이용 신발끈 공식
double getArea(vector<Point> points)
{
    double area = 0;
    int n = points.size();
    if (n < 3) return 0; // 교점이 3개 미만이면 넓이는 0

    for (int i = 0; i < n; i++) 
    {
        Point curr = points[i];
        Point next = points[(i + 1) % n];
        area += (curr.x * next.y - curr.y * next.x);
    }
    return abs(area) / 2.0;
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

// 거리 (제곱근)
double dist(Point a, Point b) 
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    
    vector<Point> v(n);
    for (int i = 0; i < n; i++) 
    {
        v[i].id = i;
        cin >> v[i].x >> v[i].y;
    }

    vector<Point> hull = getConvexHull(v);
    int m = hull.size();
    
    // 점이 2개 이하
    if (m <= 2) 
    {
        double d = (m == 2) ? dist(hull[0], hull[1]) : 0;
        
        cout << fixed;
        cout.precision(10);
        cout << d;
        return 0;
    }
    
    // 다각형의 둘레 길이 누적합
    vector<double> vec(m + 1, 0.0);
    double P = 0;
    for (int i = 0; i < m; i++) 
    {
        double d = dist(hull[i], hull[(i + 1) % m]);
        vec[i + 1] = vec[i] + d;
        P += d;
    }

    double ans = 1e18;
    int r = 1;

    // 회전하는 캘리퍼스
    for (int l = 0; l < m; l++) 
    {
        int nxtl = (l + 1) % m;
        while (true) 
        {
            int nxtr = (r + 1) % m;
            Point vecl = hull[nxtl] - hull[l];
            Point vecr = hull[nxtr] - hull[r];
            
            if (crossProduct(vecl, vecr) > 0) r = nxtr;
            else break;
        }

        auto lmdist = [&](int a, int b) 
        {
            if (a <= b) return vec[b] - vec[a];
            return P - (vec[a] - vec[b]);
        };
        
        // l -> nxtl (nxtl과 r에서 떨어짐)
        // 밧줄은 당기는 방향의 뒤쪽, CCW 기준으로 r에서 nxtl로 감긴다
        double len1 = lmdist(r, nxtl);
        if (len1 < ans) ans = len1;
        
        // nxtl -> l (l과 r에서 떨어짐)
        // 밧줄은 CCW 기준으로 l에서 r로 감긴다
        double len2 = lmdist(l, r);
        if (len2 < ans) ans = len2;
    }
    
    cout << fixed;
    cout.precision(10);
    cout << ans;

    return 0;
}