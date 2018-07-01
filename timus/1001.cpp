//http://acm.timus.ru/problem.aspx?space=1&num=1001
#include<bits/stdc++.h>
using namespace std;

vector<long long> res;

int main(){
    long long num;
    while(cin>>num){
        res.push_back(num);
    }
    int len = res.size();
    for(int i = len-1; i >= 0; --i)
        cout<<fixed<<setprecision(4)<<sqrt(res[i])<<endl;
    return 0;
}
