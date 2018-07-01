#include<bits/stdc++.h>
using namespace std;
int n;
long long int differ[100005];

int binsearch(long long int x){
    int mins=0,maxs=n;
    int mids=(mins+maxs)/2;
    while(maxs>mins){
        if(maxs==mins+1){
            if(differ[maxs]<x){
                return maxs;
            }
            else{
                return mins;
            }
        }
        if(differ[mids]<x){
            mins=mids;
        }
        else{
            maxs=mids-1;
        }
        mids=(mins+maxs)/2;
    }
    return mids;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>differ[i+1];
    }
    differ[0]=-1;
    int q;
    cin>>q;
    long long int x,y;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        int indmid=binsearch(y-x);
        int indend=binsearch(y);
        if(indend==0){
            cout<<0<<endl;
        }
        else if(indmid==0){
            if(y-x>x-y+differ[indmid+1]){
                cout<<indmid+1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            if(indmid==indend){
                cout<<indmid<<endl;
            }
            else{
                if(y-differ[indmid]-x>x-y+differ[indmid+1]){
                    cout<<indmid+1<<endl;
                }
                else{
                    cout<<indmid<<endl;
                }
            }
        }
    }
}
