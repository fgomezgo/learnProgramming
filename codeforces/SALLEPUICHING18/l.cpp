#include<bits/stdc++.h>
using namespace std;

int w,a,b;
char str[5][105];

void printstr(){
    puts("Possible");
    for(int i = 1; i <= 3; ++i, puts(""))
        for(int j = 1; j <= w; ++j)
            printf("%c",str[i][j]);
}

int main(){
    scanf("%d%d%d",&w,&a,&b);
    for(int i = 1; i <= 3; ++i)
        for(int j = 1; j <= w; ++j)
            str[i][j] = '.';
    str[1][a] = 'A';
    str[3][b] = 'B';
    str[2][1] = 'X';
    if(a == b){
        printstr();
        return 0;
    }
    if(a%2 != b%2){
        puts("Impossible");
        return 0;
    }
    if(a == 1 || b == 1){
        puts("Impossible");
        return 0;
    }
    if(a < b){
        int idx = a;
        str[1][a-1] = '*';
        bool fl = true;
        if(str[2][a-1] != 'X'){
            str[2][a-1] = '*';
            a += 2;
            fl = false;
        }
        while(a < b && idx < w){
            if(fl){
                a += 2;
                fl = false;
            }
            str[2][idx++] = '*';
            a += 2;
        }
    } else{
        int idx = b;
        str[3][b-1] = '*';
        bool fl = true;
        if(str[2][b-1] != 'X'){
            str[2][b-1] = '*';
            b += 2;
            fl = false;
        }
        while(b < a && idx < w){
            if(fl){
                b += 2;
                fl = false;
            }
            str[2][idx++] = '*';
            b += 2;
        }
    }
    if(a == b)
        printstr();
    else
        puts("Impossible");
 
    return 0;
}