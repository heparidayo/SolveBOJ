// 기하 문제 (ccw, convex hull 등의 문제를 풀기 위한 템플릿 코드)
// 추가로 벡터 외적 함수와 ccw 함수 포함

#include <iostream>
#include <vector>
#include <algorithm>
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

// 거리 제곱 (일직선상에 점 정렬)
long long distSq(Point a, Point b) 
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

int main() 
{
    int t; 
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<Point> v(n);

        for (int i = 0; i < n; i++) 
        {
            cin >> v[i].x >> v[i].y;
            v[i].id = i; // 초기 인덱스 저장
        }

        // pivot 설정
        sort(v.begin(), v.end());
        Point pivot = v[0];

        // 반시계 방향 각도순 정렬
        sort(v.begin() + 1, v.end(), [&](const Point& a, const Point& b) 
        {
            long long c = ccw(pivot, a, b);
            if (c > 0) return true;  // 반시계
            if (c < 0) return false; // 시계

            // 각도가 같으면(일직선), 기준점에서 가까운 순서로
            return distSq(pivot, a) < distSq(pivot, b);
        });

        // 점 역순 배치
        int last = n - 1;
        while (last > 1 && ccw(pivot, v[last - 1], v[last]) == 0) 
            last--;
        reverse(v.begin() + last, v.end());

        // 결과
        for (int i = 0; i < n; i++) 
            cout << v[i].id << " ";
            
        cout << '\n';
    }

    return 0;
}