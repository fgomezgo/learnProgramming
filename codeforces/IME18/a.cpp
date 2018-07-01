#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long int amount=0;
    long long int minvalley=0;
    int test;
    for(int i=0;i<n;i++){
        cin>>test;
        amount+=test;
        if(amount<minvalley){
            minvalley=amount;
        }
    }
    cout<<-minvalley;
}