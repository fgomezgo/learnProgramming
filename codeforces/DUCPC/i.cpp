#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int piles[n];
        int oddpiles=0;
        for(int i=0;i<n;i++){
            cin>>piles[i];
            if(piles[i]%2==0){
                oddpiles++;
            }
        }
        if(oddpiles%2==1){
            cout<<"Yalalov"<<endl;
        }
        else{
            cout<<"Shin"<<endl;
        }
    }
}