/*************************************************************************
	> File Name: map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月19日 星期六 15时13分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>

using namespace std;
int main()
{
    map<int,string> mapStudent;
    map<int,string>::iterator iter,beg,end;
    mapStudent[0] = "student_one";
    mapStudent[1] = "student_two";
    mapStudent[2] = "student_three";
    mapStudent.insert(pair<int,string>(5,"Fear Kubrick"));
    mapStudent.insert(pair<int,string>(2,"Akemi Homura"));
    mapStudent.insert(pair<int,string>(-1,"Eren Jaeger"));
    mapStudent.insert(pair<int,string>(99,"Lin"));
    cout<<mapStudent.size()<<endl;
    cout<<endl;

    for(iter = mapStudent.begin();iter != mapStudent.end();iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
    cout<<endl;

    return 0;
}
