#include<bits/stdc++.h>
using namespace std;
int n;
char str[5];
int mat[10][7] = {  {1,1,1,1,1,0,1},
                    {0,0,1,1,0,0,0},
                    {0,1,1,0,1,1,1},
                    {0,0,1,1,1,1,1},
                    {1,0,1,1,0,1,0},
                    {1,0,0,1,1,1,1},
                    {1,1,0,1,1,1,1},
                    {0,0,1,1,1,0,0},
                    {1,1,1,1,1,1,1},
                    {1,0,1,1,1,1,1}};
int cont[10] = {6,2,5,5,4,5,6,3,7,6}; 

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s",str);
        int sum = 0;
        if(str[0] == '1')
            sum = cont[str[0]-'0']+cont[str[1]-'0'];
        else{
            if(mat[str[0]-'0'][2] == mat[str[1]-'0'][0] && mat[str[0]-'0'][3] == mat[str[1]-'0'][1]){
                sum = cont[str[0]-'0']+cont[str[1]-'0']-mat[str[0]-'0'][2]-mat[str[0]-'0'][3];
            } else{
                sum = cont[str[0]-'0']+cont[str[1]-'0'];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}