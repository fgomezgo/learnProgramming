#include<bits/stdc++.h>
using namespace std;

int n;
long long arr[15];
int tmp[15];

int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>arr[i];
        tmp[i] = i;
    }
    bool fl = true;
    do{
        long long sum = 0;
        bool cl = true;
        for(int i = 0; i < n; ++i){
            sum += arr[tmp[i]];
            if(sum < 0 || sum > 99999999)
                cl = false;
        }
        if(cl){
            for(int i = 0; i < n; ++i)
                cout<<arr[tmp[i]]<<endl;
            fl = false;
            break;
        }
    }while(next_permutation(tmp,tmp+n));
    if(fl) puts("Error");
    return 0;
}