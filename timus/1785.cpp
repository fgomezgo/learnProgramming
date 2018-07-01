//http://acm.timus.ru/problem.aspx?space=1&num=1785
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n >= 1 && n <= 4)
        cout<<"few"<<endl;
    if(n >= 5 && n <= 9)
        cout<<"several"<<endl;
    if(n >= 10 && n <= 19)
        cout<<"pack"<<endl;
    if(n >= 20 && n <= 49)
        cout<<"lots"<<endl;
    if(n >= 50 && n <= 99)
        cout<<"horde"<<endl;
    if(n >= 100 && n <= 249)
        cout<<"throng"<<endl;
    if(n >= 250 && n <= 499)
        cout<<"swarm"<<endl;
    if(n >= 500 && n <= 999)
        cout<<"zounds"<<endl;
    if(n >= 1000)
        cout<<"legion"<<endl;
    return 0;
}