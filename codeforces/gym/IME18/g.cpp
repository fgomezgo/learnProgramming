#include<bits/stdc++.h>
using namespace std;
long long int factorial[300005];
long long int inverse[300005];
long long int inversefactorial[300005];
long long int MOD=1000000007;

long long int binexp(int a){
    int exp=MOD-2;
    long long int mult=a;
    long long int ans=1;
    while(exp>0){
        if(exp%2==1){
            ans*=mult;
            ans%=MOD;
        }
        mult=mult*mult;
        mult%=MOD;
        exp/=2;
    }
    return ans;
}

long long int expsix(int exp){
    long long int mult=6;
    long long int ans=1;
    while(exp>0){
        if(exp%2==1){
            ans*=mult;
            ans%=MOD;
        }
        mult=mult*mult;
        mult%=MOD;
        exp/=2;
    }
    return ans;
}

int main(){
    int n,c;
    cin>>c>>n;
    //Inversos
    for(int i=1;i<n;i++){
        inverse[i]=binexp(i);
    }
    //inversosfactoriales
    inversefactorial[0]=1;
    for(int i=1;i<n;i++){
        inversefactorial[i]=inversefactorial[i-1]*inverse[i];
        inversefactorial[i]%=MOD;
    }
    //factoriales
    factorial[0]=1;
    for(int i=1;i<n;i++){
        factorial[i]=factorial[i-1]*i;
        factorial[i]%=MOD;
    }
    long long int ans=1;
    ans*=factorial[n-2*c];
    ans%=MOD;
    ans*=inversefactorial[n-3*c];
    ans%=MOD;
    ans*=inversefactorial[c];
    ans%=MOD;
    ans*=factorial[c];
    ans%=MOD;
    ans*=expsix(c);
    ans%=MOD;
    cout<<ans;
}