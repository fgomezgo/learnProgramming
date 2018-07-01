#include<bits/stdc++.h>
using namespace std;

bool ispower2(long long int a){
    while(a%2==0){
        a/=2;
    }
    if(a==1){
        return true;
    }
    return false;
}

int main(){
    int q;
    cin>>q;
    long long int x;
    for(int i=0;i<q;i++){
        cin>>x;
        if(ispower2(x)){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
}