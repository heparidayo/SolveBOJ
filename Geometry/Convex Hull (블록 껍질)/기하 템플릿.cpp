// 기하 문제 (ccw, convex hull 등의 문제를 풀기 위한 템플릿 코드)
// 사용 알고리즘은 monotone chain (O(n log n))
// 벡터 외적/내적적 함수와 ccw, 다각형 내부에 점 포함 여부 함수
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

// 벡터 내적
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

// 3차원 문제용
// 3차원 벡터 내적 - 방향 판별 (Dot Product)
// double dotProduct(Point a, Point b)
// {
//     return a.x * b.x + a.y * b.y + a.z * b.z;
// }
// 
// // 3차원 벡터 크기 반환 - 피타고라스 (Magnitude)
// double getMagnitude(Point a)
// {
//     return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
// }

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

// 선분 교차 판정 - (17387 선분 교차 2 함수화)
bool isCross(Point a, Point b, Point c, Point d)
{
    long long abc = ccw(a, b, c);
    long long abd = ccw(a, b, d);
    long long cda = ccw(c, d, a);
    long long cdb = ccw(c, d, b);

    // 모든 점이 직선 위에 있다면 
    if (abc == 0 && abd == 0 && cda == 0 && cdb == 0)
    {
        // 계산이 용이하게 점 a와 점 c가 좌하귀로 가도록 정렬
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);

        // 겹침 (항상 그림 그려보기, 일직선으로 점이 a b c d 있을때 b d 에 있는 점을 찾는다 생각하기)
        if (!(min(b, d) < max(a, c))) return true;
        else return false;
    }

    // 일반적인 경우
    if (abc * abd <= 0 && cda * cdb <= 0) return true;
    else return false;
}

// 회전하는 캘리퍼스 1 (볼록 다각형의 최소 너비 반환)
double getMinWidth(vector<Point> hull) // 인자 hull은 getConvexHull의 볼록 다각형
{
    int n = hull.size();
    if (n <= 2) return 0; // 점이 2개 이하면 너비는 0

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
            if (crossProduct(vecl, vecr) > 0) r = nxtr;
            else break;
        }
        // 너비 계산
        // 높이(너비) = 넓이(외적) / 밑변

        // 1. 밑변 계산 (l -> nxtl)
        // 지름과 다르게 밑변은 캘리퍼스가 닿은 변의 길이
        double dx = hull[l].x - hull[nxtl].x;
        double dy = hull[l].y - hull[nxtl].y;

        // 이때, 밑변 길이가 필요하므로 루트 씌어줌 (피타고라스)
        double base = sqrt(dx * dx + dy * dy);

        // 2. 외적으로 평행사변형 넓이 계산 (절댓값 처리) (l -> nxtl변, l -> r변)
        double area = abs(crossProduct(hull[nxtl] - hull[l], hull[r] - hull[l]));

        // 3. 높이(너비) 갱신
        double height = area / base;
        if (height < minWidth)  minWidth = height;
    }

    return minWidth;
}

// 회전하는 캘리퍼스 2 (볼록 다각형의 최대 너비 ~ 가장 먼 두 점 사이의 거리) 
double getMaxDiameter(vector<Point> hull) 
{
    int n = hull.size();
    if (n < 2) return 0;
    if (n == 2) return dist(hull[0], hull[1]); // 점이 2개면 무조건 최대 거리

    double maxDist = 0;
    int r = 1;

    for (int l = 0; l < n; l++) 
    {
        int nxtl = (l + 1) % n;
        
        while (true) 
        {
            int nxtr = (r + 1) % n;
            
            Point vecl = hull[nxtl] - hull[l];
            Point vecr = hull[nxtr] - hull[r];
            
            if (crossProduct(vecl, vecr) > 0) 
                r = nxtr;
            else 
                break;
        }
        
        // 현재 캘리퍼스에 닿은 점들 사이의 거리로 최댓값 갱신
        double currentDist = dist(hull[l], hull[r]);
        if (currentDist > maxDist) maxDist = currentDist;
    }
    
    return maxDist;
}

int main() 
{
    int n;  cin >> n;
    vector<Point> v(n);

    for (int i = 0; i < n; i++) 
        cin >> v[i].x >> v[i].y;

    vector<Point> hull = getConvexHull(v);

    cout << hull.size() << '\n';
    return 0;
}