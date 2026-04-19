#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) 
{
    return a + b > b + a;
}

int main() 
{
    int k, n;
    cin >> k >> n;

    vector<string> v;
    int ansi = -1;
    string anss = "";

    // 가장 큰 수 찾기
    for (int i = 0; i < k; i++) 
    {
        string s; cin >> s;
        v.push_back(s);
        
        int val = stoi(s); 
        if (val > ansi) 
        {
            ansi = val;
            anss = s;
        }
    }

    // 가장 큰 수로 도배
    for (int i = 0; i < n - k; i++) 
        v.push_back(anss);

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) 
        cout << v[i];

    return 0;
}