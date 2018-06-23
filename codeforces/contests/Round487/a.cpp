#include<bits/stdc++.h>
using namespace std;
string str;
int s[3];

int main(){
    cin>>str;
    int len = str.size();
    bool fl = true;
    for(int i = 1; i < len-1; ++i){
        int num = str[i]-'A';
        if(num >= 0 && num < 3){
            s[num] = 1;
        }
        num = str[i-1]-'A';
        if(num >= 0 && num < 3){
            s[num] = 1;
        }
        num = str[i+1]-'A';
        if(num >= 0 && num < 3){
            s[num] = 1;
        }
        if(s[0] && s[1] && s[2]){
            puts("Yes");
            fl = false;
            break;
        }
        memset(s,0,sizeof s);
    }
    if(fl) puts("No");
    return 0;
}