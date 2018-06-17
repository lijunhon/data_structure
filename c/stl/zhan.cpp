/*************************************************************************
	> File Name: zhan.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月19日 星期六 15时42分58秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(19);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
