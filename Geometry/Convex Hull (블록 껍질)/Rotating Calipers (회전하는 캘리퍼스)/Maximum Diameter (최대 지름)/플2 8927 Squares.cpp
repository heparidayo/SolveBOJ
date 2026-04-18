// 기하 문제 (ccw, convex hull 등의 문제를 풀기 위한 템플릿 코드)
// 사용 알고리즘은 monotone chain (O(n log n))
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

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        // 정수 n개만큼 정사각형 받기
        // x,y는 왼쪽 아래 꼭짓점 좌표, w는 한 변의 길이
        // 정사각형 무시하고 캘리퍼스 돌리기
        vector<Point> v; // -- 아 C# List랑 다르게 v(n) 하면 0으로 초기화해둠 잊지마셈,,

        for (int i = 0; i < n; i++)
        {
            long long x, y, w;
            cin >> x >> y >> w;

            // cin >> v[i].x >> v[i].y;
            v.push_back({ x, y });
            v.push_back({ x + w, y });
            v.push_back({ x, y + w });
            v.push_back({ x + w, y + w });
        }

        // 1. convex hull
        vector<Point> hull = getConvexHull(v);

        // l = 캘리퍼스 한쪽 끝점 - 0부터 시작
        // r = 캘리퍼스 반대쪽 끝점 - 1부터 시작
        // 2. rotating calipers - 가장 먼 두 점 찾기
        int r = 1; 
        long long maxDist = 0;
        Point p1, p2;
        for (int l = 0; l < hull.size(); l++)
        {
            int nxtl = (l + 1) % hull.size(); // 원형 자료구조처럼 인덱스 회전을 위해

            while (true)
            {
                int nxtr = (r + 1) % hull.size(); // nxtl과 마찬가지

                // hull 은 position같은 상태 이므로 벡터(기울기)로 변환
                // 유니티에서 Vector3 direction = target.position - transform.position; 랑 같은원리임
                // 여기서 정규화하면 단위벡터인 dir이 되는거고
                Point vecl = hull[nxtl] - hull[l];
                Point vecr = hull[nxtr] - hull[r];

                // r쪽 변이 더 반시계 방향(왼쪽)을 가리키면 r을 더 전진
                if (crossProduct(vecl, vecr) > 0) 
                    r = nxtr;
                else 
                    break;
            }

            // l <-> r 최대 거리 계산 
            // 피타고라스(루트 안씌운 제곱상태) 사용
            long long dx = hull[l].x - hull[r].x;
            long long dy = hull[l].y - hull[r].y;
            long long d = dx * dx + dy * dy;
            
            if (d > maxDist) 
            {
                maxDist = d;
                p1 = hull[l];
                p2 = hull[r];
            }
        }
        
        cout << maxDist << '\n';
    }
}