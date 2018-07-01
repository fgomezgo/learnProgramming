#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,r,p;
    cin>>l>>r>>p;
    double c = ((double)min(l,r)/(double)max(l,r))*100.0;
    if(r == l || c >= (double)p){
        puts("Ambidextrous");
        return 0;
    }
    if(r > l)
        puts("Right-handed");
    else
        puts("Left-handed");

    return 0;
}