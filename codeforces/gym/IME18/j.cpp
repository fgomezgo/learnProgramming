#include<bits/stdc++.h>
using namespace std;

const int N = 2*5e5+5;

int n,m;
char cipher[30][30];
char keys[30][30];
char str[30];
char tmp[N];
int trie[N][26];
int nn = 1;

char test[N];

void dfs(int nodo, int cont, int idx){
    bool fl = true;
    for(int i = 0; i < 26; ++i){
        if(trie[nodo][i] != 0){
            fl = false;
            test[idx] = keys[cont][i];
            dfs(trie[nodo][i],cont,idx+1);
            test[idx] = 0;
        }
    }
    if(fl){
        cout<<test<<endl;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    //assert(m >= 1);
    scanf("%s",str);
    for(int i = 0; i < n; ++i)
        cipher[0][i] = keys[0][i] = i+'A';
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n; ++j){
            keys[i][j] = str[(int)keys[i-1][j]-'A'];
            cipher[i][(int)keys[i][j]-'A'] = j+'A';
        }
    }
    
    cout<<"encrypt:"<<endl;
    for(int i = 0; i < n; ++i)
        cout<<keys[i]<<endl;
    cout<<endl;
    for(int i = 0; i < n; ++i)
        cout<<cipher[i]<<endl;
    
    int cont = 0,t;
    while(m--){
        cout<<"Before Operation: "<<endl;
        dfs(0,cont,0);
        scanf("%d",&t);
        if(t == 2){
            cont = (cont+1)%n;
        }
        if(t == 1){
            scanf("%s",tmp);
            int len = strlen(tmp);
            int idx = 0;
            for(int i = 0; i < len; ++i){
                assert(((int)tmp[i]-'A') < n);
                char c = cipher[cont][(int)tmp[i]-'A'];
                if(trie[idx][(int)c-'A'] == 0){
                    trie[idx][(int)c-'A'] = nn++;
                }
                idx = trie[idx][(int)c-'A'];
            }
        }
        if(t == 3){
            scanf("%s",tmp);
            int len = strlen(tmp);
            int idx = 0;
            bool fl = true;
            for(int i = 0; i < len; ++i){
                assert(((int)tmp[i]-'A') < n);
                char c = cipher[cont][(int)tmp[i]-'A'];
                if(trie[idx][(int)c-'A'] == 0){
                    fl = false;
                    break;
                }
                idx = trie[idx][(int)c-'A'];
            }
            if(fl)  puts("YES");
            else    puts("NO");
        }
        cout<<"After Operation: "<<endl;
        dfs(0,cont,0);
        cout<<endl;
    }

    return 0;
}
