//https://www.codechef.com/problems/FLOW007
#include<stdio.h>
#include<string.h>
char str[10];

int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        scanf("%s",str);
        int len = strlen(str); //Longitud de la cadena
        bool isLeading = true;
        for(int i = len-1; i >= 0; --i){ //Recorremos la cadena al reves
            if(str[i] == '0'){  //Si el caracter es zero
                if(!isLeading)  //No es un leading zero?
                    printf("%c",str[i]); //Imprimelo
            } else{
                isLeading = false;       //Se acabaron los leading zeros
                printf("%c",str[i]);     //Imprime caracter diferente de 0
            }
        }
        printf("\n");
    }

    return 0;
}