#include <iostream>
#include <numeric>
using namespace std;

// numeric 왜 안대지
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct Point 
{
    long long x, y;
};

long long ccw(Point p1, Point p2, Point p3) 
{
    return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y)
         - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

// 경계점(Boundary point) 구하기
long long getBoundaryPoints(Point p1, Point p2, Point p3) 
{
    long long b1 = gcd(abs(p1.x - p2.x), abs(p1.y - p2.y));
    long long b2 = gcd(abs(p2.x - p3.x), abs(p2.y - p3.y));
    long long b3 = gcd(abs(p3.x - p1.x), abs(p3.y - p1.y));
    return b1 + b2 + b3;
}

int main() 
{
    Point p1, p2, p3;
    
    while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y) 
    {
        if (p1.x == 0 && p1.y == 0 && p2.x == 0 && p2.y == 0 && p3.x == 0 && p3.y == 0) break;

        // 픽의 정리
        // I = (2A - B + 2) / 2
        long long doubleArea = abs(ccw(p1, p2, p3)); // CCW에 절댓값 == 2A (넓이의 2배)
        long long ans = (doubleArea - getBoundaryPoints(p1, p2, p3) + 2) / 2;

        cout << ans << '\n';
    }

    return 0;
}