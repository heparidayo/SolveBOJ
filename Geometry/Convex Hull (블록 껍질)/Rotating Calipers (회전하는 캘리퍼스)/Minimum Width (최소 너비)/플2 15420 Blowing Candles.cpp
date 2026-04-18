// 기하 문제 (ccw, convex hull 등의 문제를 풀기 위한 템플릿 코드)
// 사용 알고리즘은 monotone chain (O(n log n))
// 추가로 벡터 외적 함수와 ccw 함수 포함

#include <cmath>
#include <iomanip>
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
    int cnt = 1;
    int n, r; cin >> n >> r;
    while (true)
    {
        vector<Point> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].x >> v[i].y;

        // 1. convex hull
        vector<Point> hull = getConvexHull(v);

        // 최소 너비 계산이므로, minWidth로 초기화
        double minWidth = 0x3f3f3f3f;
        
        // l = 캘리퍼스 한쪽 끝점 - 0부터 시작
        // r = 캘리퍼스 반대쪽 끝점 - 1부터 시작
        int r = 1; 
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

            // 너비 계산
            // 높이(너비) = 넓이(외적) / 밑변

            // 1. 밑변 계산 (l -> nxtl)
            // 지름과 다르게 밑변은 캘리퍼스가 닿은 변의 길이
            double dx = hull[l].x - hull[nxtl].x;
            double dy = hull[l].y - hull[nxtl].y;

            // 이때, 밑변 길이가 필요하므로 루트 씌어줌 (피타고라스)
            double base = sqrt(dx * dx + dy * dy);

            // 2. 넓이(외적) 계산 (l -> nxtl변, l -> r변)
            double area = crossProduct(hull[nxtl] - hull[l], hull[r] - hull[l]);

            // 3. 높이 (너비) 계산
            double height = area / base;

            if (height < minWidth)
                minWidth = height;
        }

        cout << minWidth;
        if (cnt == 1) break;
    }

    return 0;
}