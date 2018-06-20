#include<bits/stdc++.h>
using namespace std;

int arr[1000005];

int main(){
    int n = 1000000;
    int k = 1000000;
    cout<<n<<" ";
    srand(time(NULL));
    int m = 0;
    for(int i = 100001; i < n; ++i){
        int r = rand()%10;
        arr[i] = 1;
        ++m;
        /*
        if(r != 9){
            arr[i] = 1;
            ++m;
        }*/
    }
    cout<<m<<" "<<k<<endl;
    for(int i = 0; i < n; ++i){
        if(arr[i] == 1)
            cout<<i<<" ";
    } cout<<endl;
    for(int i = 0; i < k; ++i){
        int r = (rand()%1000)+1;
        cout<<r<<" ";
    } cout<<endl;

    return 0;
}