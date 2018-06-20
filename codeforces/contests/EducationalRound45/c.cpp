#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
string str[N];
char tmp[N];
int opn[N];
int cls[N];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s",tmp);
        str[i] = string(tmp);
    }
    int reg = 0;
    for(int i = 0; i < n; ++i){
        int len = str[i].size();
        int c = 0, o = 0;
        stack <char> Q;
        for(int j = 0; j < len; ++j){
            if(str[i][j] == '(')
                Q.push('(');
            else{
                if(!Q.empty())
                    Q.pop();
                else
                    c++;
            }
        }
        while(!Q.empty()){
            Q.pop();
            o++;
        }
        if(c == 0 && o == 0){
            ++reg;
            continue;
        }
        if(c == 0)
            ++opn[o];
        if(o == 0)
            ++cls[c];
    }
    long long ans = (long long)reg*reg;
    for(int i = 1; i <= N; ++i){
        ans += (long long)opn[i]*cls[i];
    }
    printf("%lld\n",ans);
    

    return 0;
}