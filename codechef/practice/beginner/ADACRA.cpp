//https://www.codechef.com/problems/ADACRA
#include<stdio.h>
#include<string.h>
#include<algorithm>
char str[55];

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%s",str);
        int su = 0, sd = 0;    //Contadores de segmentos consecutivos de D's y U's
        int len = strlen(str); //Longitud de la cadena
        //Banderas de deteccion de segmento
        bool inU = false; //El iterador esta en un segmento de u?
        bool inD = false; //El iterador esta en un segmento de d?
        for(int i = 0; i < len; ++i){
            if(str[i] == 'U'){      //Estoy en un segmento de U
                if(!inU){           //Si no estaba en un segmento U
                    inU = true;     //Ahora estoy en un segmento de U
                    ++su;           //Sumo a mi contador de segmentos de U
                }
                inD = false;        //Sali de un segmento de D
            } else {                //Estoy en un segmento de D
                if(!inD){           //Si no estaba en un segmento D
                    inD = true;     //Ahora estoy en un segmento de D
                    ++sd;           //Sumo a mi contador de segmentos de D
                }
                inU = false;        //Sali de un segmento de U
            }
        }
        printf("%d\n",std::min(su,sd));
    }

    return 0;
}