    //https://www.codechef.com/problems/LOSTMAX/
    #include<stdio.h>
    #include<string.h>
    #include<algorithm>
    char str[1000];
    int array[55];
    int sz = 0;
     
    int main(){
        int test;
        scanf("%d",&test); 
        fgets(str,1000,stdin);          //Lee los caracteres basura seguidos de la variable test 
        while(test--){ 
            fgets(str,1000,stdin);      //Lee una linea del input sin formato
            int length = strlen(str);   //Length del string
            int num = 0;                //numero temporal que construye los enteros que se van a ir extrayendo de la cadena str
     
            bool isANumberReady = false;    //Bandera que indica si un numero esta siendo construido o ya esta listo para incluirse en el array
     
            for(int i = 0; i < length; ++i){ //Iterar por cada caracter
                //Preguntarse si el caracter str[i] es numerico
                if( str[i] >= '0' && str[i] <= '9' ){
                    isANumberReady = true;              //La bandera en true indica que hay un numero en proceso de construccion (digito a digito)
                    num = num*10 + int(str[i]-'0');     //Cada digito de str se va agregando a la variable temporal num
                } else {
                    if( isANumberReady ){   //El numero ya esta listo para incluirse en el arreglo array
                        array[sz++] = num;  //Inserta el numero num en el arreglo
                        num = 0;            //Se deja lista la variable temporal para construir otro numero
                        isANumberReady = false; //Se indica que ya no hay un numero en proceso de construccion (digito a digito)
                    }
                }
            }
            //En caso de que no haya entrado al else en el ultimo caracter por ser numerico, entoces forzalo a que agregue el ultimo numero en construccion en caso
            // de existir
            if( isANumberReady )
                array[sz++] = num; //Inserta el numero num en el arreglo
            
            //Ya sabemos que el n del problema es equivalente al sz-1
            bool isNSkipped = false; //Bandera que se activa cuando N ya fue ignorada en el calculo del numero mayor
            int maxi = 0;            //Variable que guarda el maximo valor encontrado en el arreglo
            for(int i = 0; i < sz; ++i){
                if(isNSkipped){
                    //Si N ya fue ignorado, el numero se considera como candidato a ser el mayor
                    maxi = std::max(maxi,array[i]);
                } else {
                    if(array[i] == sz-1){ //si array[i] es N y no ha sido ignorado, entonces ignoralo
                        isNSkipped = true;  //Activa la bandera de que N ya fue ignorado
                    } else {
                        maxi = std::max(maxi,array[i]); //Si N ya fue ignorado, el numero se considera como candidato a ser el mayor
                    }
                }
            }
            sz = 0; //Regresamos el iterador al principio para "vaciar" array para el siguiente caso
            printf("%d\n",maxi); //Se imprime el mayor
        }
        return 0;
    } 