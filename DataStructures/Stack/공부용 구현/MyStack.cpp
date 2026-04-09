// c++ 로도 재구현

#include <iostream>
#include <string>
using namespace std;

struct stack
{
    int arr[10000];
    int last;
    
    void init(){        // initialize를 의미한다. last 지역 변수 초기화.
        last = -1;
    }
    void push(int data){
        arr[++last] = data;
    }
    bool empty(){
        return (last < 0);
    }
    int pop(){
        if (empty()){   // empty()의 return이 true라면 -1 return
            return -1;
        }
        return arr[last--];
    }
    int size(){
        return last + 1;
    }
    int top(){
        if (empty()){
            return -1;  // 위와 동일
        }
        return arr[last];
    }
};

int main(void)
{
    int n; cin >> n;
    stack s;
    s.init();
    for (; n--;){
        string str;
        int num;
        cin >> str;
        if (str == "push"){
            cin >> num;
            s.push(num);
        }
        if (str == "pop"){
            cout << s.pop() << endl;
        }
        if (str == "size"){
            cout << s.size() << endl;
        }
        if (str == "top"){
            cout << s.top() << endl;
        }
        if (str == "empty"){
            cout << s.empty() << endl;
        }
    }    
}
