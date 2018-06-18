#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    long long int n,m;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        long long int area1,area2;
        area1=n*n;
        area2=2*m*m;
        if(area1>area2){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
}