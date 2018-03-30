//https://www.codechef.com/problems/FLOW017
#include<stdio.h>

int main(){
    int test;  //Multiples casos
    int a,b,c; 
    
    scanf("%d",&test);
        
    while(test--){ 
        scanf("%d%d%d",&a,&b,&c);
        //Conjunto de condiciones para saber el segundo numero mayor de los valores de a,b,c
        if(a < b){
            if(b < c){
                printf("%d\n",b);
            } else {
                if(a < c)
                    printf("%d\n",c);
                else
                    printf("%d\n",a);
            }
        } else {
            if(a < c){
                printf("%d\n",a);
            } else {
                if(b < c)
                    printf("%d\n",c);
                else
                    printf("%d\n",b);                    
            }
        }
    }
    return 0;
} 