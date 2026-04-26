#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        vector<int> a(m);
        for (int j = 0; j < m; j++) 
            cin >> a[j];

        // 우 - 좌 역순 그라운디 탐색
        int g = 0;
        for (int j = m - 1; j >= 0; j--) 
        {
            if (a[j] == 0) continue;
            
            if (a[j] <= g) g = a[j] - 1;
            else g = a[j];
        }
        
        ans ^= g;
    }

    ans > 0 ? cout << "koosaga" : cout << "cubelover";
    
    return 0;
}