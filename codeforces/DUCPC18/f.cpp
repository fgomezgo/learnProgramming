#include<bits/stdc++.h>
using namespace std;
map <int,int> occur;
int factorial[1005];


int main(){
    int t;
    cin>>t;
    factorial[0]=1;
    for(int i=1;i<1003;i++){
        factorial[i]=(factorial[i-1]*i)%7901;
    }
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        long long int ans=1;
        int tosort[n];
        for(int j=0;j<n;j++){
            cin>>tosort[j];
            if(occur.find(tosort[j])!=occur.end()){
                occur[tosort[j]]++;
            }
            else{
                occur.insert(make_pair(tosort[j],1));
            }
        }
        for(map <int,int>::iterator iter=occur.begin();iter!=occur.end();iter++){
            ans*=factorial[(*iter).second];
            ans%=7901;
        }
        cout<<ans<<endl;
        occur.clear();
    }
}