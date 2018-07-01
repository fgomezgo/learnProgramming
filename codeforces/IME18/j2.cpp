#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 5e5+5;

int n,m;
char str[30];
vector <string> arr;
char tmp[N];

int main(){
    scanf("%d%d%s",&n,&m,str);
    int t;
    for(int i = 0; i < m; ++i){
        scanf("%d", &t);
        if(t == 1){
            scanf("%s",tmp);
            arr.pb(string(tmp));
        }
        if(t == 2){
            int sz = arr.size();
            for(int i = 0; i < sz; ++i){
                int len = arr[i].size();
                for(int j = 0; j < len; ++j){
                    arr[i][j] = str[(int)arr[i][j]-'A'];
                }
            }
        }
        if(t == 3){
            scanf("%s",tmp);
            int tmplen = strlen(tmp);
            int sz = arr.size();
            bool cl = true;
            for(int i = 0; i < sz; ++i){
                int len = arr[i].size();
                bool fl = true;
                for(int j = 0; j < min(len,tmplen); ++j){
                    if(arr[i][j] != tmp[j]){
                        fl = false;
                        break;
                    }
                }
                if(fl){
                    puts("YES");
                    cl = false;
                    break;
                }
            }
            if(cl) puts("NO");
        }
    }
    return 0;
}