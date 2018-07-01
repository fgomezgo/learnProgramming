//http://acm.timus.ru/problem.aspx?space=1&num=2001
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3],b[3];
    cin>>a[0]>>b[0];
    cin>>a[1]>>b[1];
    cin>>a[2]>>b[2];
    cout<<a[0]-a[2]<<" "<<b[0]-b[1]<<endl;
    return 0;
}