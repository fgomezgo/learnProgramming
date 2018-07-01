#include<bits/stdc++.h>
using namespace std;
double const PI=3.14159265358979323846;

int main(){
    int m,n;
    double r;
    cin>>m>>n>>r;
    int ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    if(ay<by){
        swap(ax,bx);
        swap(ay,by);
    }
    double ans=(ay-by)*(r/n);
    double mincurv=(PI/m)*by*(r/n)*abs(ax-bx);
    for(int i=by-1;i>=0;i--){
        mincurv=min(mincurv,2*(by-i)*(r/n)+i*(r/n)*(PI/m)*abs(ax-bx));
    }
    ans+=mincurv;
    cout<<fixed<<setprecision(20)<<ans;
}