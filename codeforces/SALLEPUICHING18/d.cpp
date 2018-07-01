#include<bits/stdc++.h>
using namespace std;

char str[100005];
int coef[105];

int main(){
    scanf("%s",str);
    if(str[0] == '0'){
        puts("0");
        return 0;
    }
    int idx = 0;
    char sign = '+';
    if(str[0] == '-'){
        sign = '-';
        ++idx;
    }
    while(str[idx] != 0){
        //coeff
        int num = 0;
        while(str[idx] != 0 && str[idx] != 'x'){
            num *= 10;
            num += str[idx]-'0';
            ++idx;
        }
        if(num == 0) ++num;
        if(sign == '-') num *= -1;
        if(str[idx] == 0){
            coef[0] = num;
            break;
        }
        ++idx;
        int pot = 0;
        while(str[idx] != 0 && str[idx] >= '0' && str[idx] <= '9'){
            pot *= 10;
            pot += str[idx]-'0';
            ++idx;
        }
        if(pot == 0) ++pot;
        coef[pot] = num;
        if(str[idx] != 0){
            sign = str[idx];
            ++idx;
        }
    }
    bool fl = true;
    for(int i = 100; i > 0; --i){
        coef[i] *= i;
        //cout<<i<<" "<<coef[i]<<endl;
        if(coef[i] != 0){
            if(coef[i] > 0){
                if(fl)
                    fl = false;
                else if(!fl)
                    printf("+");
            } else
                fl = false;
            if(abs(coef[i]) != 1)
                printf("%d",coef[i]);
            if(i-1 != 0){
                printf("x");
                if(i-1 != 1)
                    printf("%d",i-1);
            } else{
                if(abs(coef[i]) == 1)
                    printf("%d",coef[i]);
            }
        }
    }
    if(coef[0] != 0 && fl)
        printf("0");
    puts("");

    return 0;
}