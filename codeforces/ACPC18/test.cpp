#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    srand(time(NULL));
    test = (rand()%10)+1;
    cout<<test<<endl;
    while(test--){
        int m = (rand()%100)+1;
        int k = (rand()%1000)+1;
        cout<<m<<" "<<k<<endl;
        int idx = 0;
        for(int i = 0; i < m; ++i){
            int l = idx+(rand()%100)+1;
            int r = l+(rand()%100)+1;
            int v = (rand()%1000)+1;
            idx = r;
            cout<<l<<" "<<r<<" "<<v<<endl;
        }
        cout<<endl<<endl;
    }



    return 0;
}