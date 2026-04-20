// 다각형 내부에 점 p가 완전히 포함되어 있는지 -- 참조 + 이분 탐색으로 최적화. log N
bool isInside(const vector<Point>& hull, Point p) 
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