#include<bits/stdc++.h>
using namespace std;

char mat[55][55];
int a,b,c,d;

int main(){
    cin>>a>>b>>c>>d;
    --a; --b; --c; --d;
    for(int i = 0; i < 25; ++i)
        for(int j = 0; j < 25; ++j)
            mat[i][j] = 'A';
    for(int i = 25; i < 50; ++i)
        for(int j = 0; j < 25; ++j)
            mat[i][j] = 'B';
    for(int i = 0; i < 25; ++i)
        for(int j = 25; j < 50; ++j)
            mat[i][j] = 'C';
    for(int i = 25; i < 50; ++i)
        for(int j = 25; j < 50; ++j)
            mat[i][j] = 'D';
    
    //For A
    for(int i = 0; i < 24; i+=2){
        for(int j = 0; j < 24; j+=2){
            if(b){
                mat[i][j] = 'B';
                b--;
                continue;
            }
            if(c){
                mat[i][j] = 'C';
                c--;
                continue;
            }
            if(d){
                mat[i][j] = 'D';
                d--;
                continue;
            }
        }
    }
    //For B
    for(int i = 26; i < 50; i+=2){
        for(int j = 0; j < 24; j+=2){
            if(a){
                mat[i][j] = 'A';
                a--;
                continue;
            }
            if(c){
                mat[i][j] = 'C';
                c--;
                continue;
            }
            if(d){
                mat[i][j] = 'D';
                d--;
                continue;
            }
        }
    }
    //For C
    for(int i = 0; i < 25; i+=2){
        for(int j = 26; j < 50; j+=2){
            if(a){
                mat[i][j] = 'A';
                a--;
                continue;
            }
            if(b){
                mat[i][j] = 'B';
                b--;
                continue;
            }
            if(d){
                mat[i][j] = 'D';
                d--;
                continue;
            }
        }
    }
    //For D
    for(int i = 26; i < 50; i+=2){
        for(int j = 26; j < 50; j+=2){
            if(a){
                mat[i][j] = 'A';
                a--;
                continue;
            }
            if(b){
                mat[i][j] = 'B';
                b--;
                continue;
            }
            if(c){
                mat[i][j] = 'C';
                c--;
                continue;
            }
        }
    }
    cout<<"50 50"<<endl;
    for(int i = 0; i < 50; ++i)
        cout<<mat[i]<<endl;

    return 0;
}