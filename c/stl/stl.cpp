/*************************************************************************
	> File Name: stl.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月19日 星期六 14时58分51秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vec;
    int i;
    cout<<"vector size = "<<vec.size()<<endl;
    for(i = 0;i < 5;i++)
    {
        vec.push_back(i);
    }
    cout<<"extended vector size = "<<vec.size()<<endl;
    for(i = 0;i<5;i++)
    {
        cout<<"value of vec["<<i<<"]"<<vec[i]<<endl;
    }
    vector<int>::iterator v = vec.begin();
    while(v!=vec.end())
    {
        cout<<"value of v = "<<*v<<endl;
        v++;
    }
    return 0;
}

