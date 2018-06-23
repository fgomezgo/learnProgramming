#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int n,p;
string str;
int main(){ IO
    cin>>n>>p>>str;
    if(p == n){
        puts("No");
        return 0;
    }
    bool fl = true;
    for(int i = 0; i < p; ++i){
        int zero = 0, one = 0;
        for(int j = i; j < n; j += p){
            if(str[j] == '0') zero = 1;
            if(str[j] == '1') one = 1;
        }
        for(int j = i; j < n; j += p){
            if(str[j] == '.'){
                if(zero){
                    str[j] = '1';
                    one = 1;
                } else if(one){
                    str[j] = '0';
                    zero = 1;
                } else{
                    str[j] = '0';
                    zero = 1;
                }
            }
        }
        if(zero && one)
            fl = false;
    }
    if(!fl)
        cout<<str<<endl;
    else
        puts("No");
    return 0;
}