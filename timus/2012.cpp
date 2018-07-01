//http://acm.timus.ru/problem.aspx?space=1&num=2012
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int rest = 4*60;
    if((12-n)*45 <= rest)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}