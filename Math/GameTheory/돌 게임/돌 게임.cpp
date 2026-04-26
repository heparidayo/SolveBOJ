#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    string s;
    cin >> s;

    vector<int> vec;
    for (int i = 0; i < s.length(); i++) 
        if (s[i] != '.') vec.push_back(i);

    // 빈칸 갯수, xor 누적
    int ans = 0;
    for (int i = 0; i < vec.size(); i += 2) 
    {
        int gap = vec[i + 1] - vec[i] - 1;
        ans ^= gap;
    }

    ans > 0 ? cout << "Win" : cout << "Lose";

    return 0;
}