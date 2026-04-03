#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    sort(vec.begin(), vec.end(), 
            [](const string s1, const string s2)
            {
                // 1. 길이가 짧은거
                if (s1.size() != s2.size())
                    return s1.size() < s2.size();
                
                // 2. 자리수의 합합
                int sum1 = 0;
                for (auto c : s1)
                {
                    if ('0' <= c && c <= '9')
                        sum1 += (c - '0');
                }
                int sum2 = 0;
                for (auto c : s2)
                {
                    if ('0' <= c && c <= '9')
                        sum2 += (c - '0');
                }
                if (sum1 != sum2)
                {
                    if (sum1 < sum2) return true;
                    else return false;
                }

                // 3. 사전순
                if (s1 < s2) return true;
                return false;
            });


    for (auto s : vec)
            cout << s << '\n';
}