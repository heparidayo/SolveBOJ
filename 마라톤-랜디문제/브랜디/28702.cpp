#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s[3];
    int num = 0;

    for (int i = 0; i < 3; i++) 
    {
        cin >> s[i];
        if (s[i] != "Fizz" && s[i] != "Buzz" && s[i] != "FizzBuzz") 
            num = stoi(s[i]) + (3 - i);
    }

    if (num % 15 == 0) cout << "FizzBuzz";
    else if (num % 3 == 0) cout << "Fizz";
    else if (num % 5 == 0) cout << "Buzz";
    else cout << num;

    return 0;
}