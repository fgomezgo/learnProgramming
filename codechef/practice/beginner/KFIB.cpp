//https://www.codechef.com/problems/KFIB
#include<stdio.h>
#include<string.h>
#define mod 1000000007 //Defini el modulo como "mod" para usarlo mas adelante en el codigo solo como "mod"
int memo[200005];

//Funcion T
//Recursion con Memorizacion
//METODO RECURSIVO QUE EXCEDE LLAMADAS AL STACK DEL PROGRAMA
/*
int T(int n, int k){
    printf("%d\n",n);
    fflush(stdout);
    int &ans = memo[n]; //Variable de referencia que failita mi referencia a memo[n]
    if(ans != -1){
        printf("ans %d\n",ans);
        fflush(stdout);
        return ans; //Con esto ya no entro al resto de la llamada de T(n,k)
    }

    //Caso base
    if(n <= k)
        return ans = 1;
    //Relacion de recurrencia o Hipotesis de Induccion
    //Sumatoria
    int sum = 0;
    for(int i = 1; i <= k; ++i) //Calculo de la sumatoria de valores anteriores
        sum = (sum+T(n-i,k))%1000000007;
    
    return ans = sum;

}
*/

int main(){
    int n,k;
    //memset(memo,-1,sizeof memo); //Funcion que inicializa un bloque de memoria en -1 (memo)
    scanf("%d%d",&n,&k);
    //METODO ITERATIVO QUE NO REQUIERE DEL STACK

    //COMPLEJIDAD O(NK)
    //Empezamos por el caso base
    /*
    for(int i = 1; i <= k; ++i)
        memo[i] = memo[i-1];
    
    for(int i = k+1; i <= n; ++i){   //El i-esimo representa el argumento n (itera sobre todos los casos que ya no son base)
        for(int j = 1; j <= k; ++j){ //El j-esimo itera sobre todos los valores de los cuales depende n
            memo[i] = (memo[i]+memo[i-j])%1000000007;
        }
    }*/

    //printf("%d\n",T(n,k));

    //COMPLEJIDAD O(N)
    //Empezamos por el caso base
    
    for(int i = 1; i <= k; ++i)
        memo[i] = memo[i-1]+1;
    
    for(int i = k+1; i <= n; ++i){   //El i-esimo representa el argumento n (itera sobre todos los casos que ya no son base)
        //memo[i] = memo[i-1]+memo[i-1]-memo[i-k-1]; //En memo[i] se guarda el valor de la suma anterior (memo[i-1]) mas el valor que corresponderia
                                                     //al termino n-esimo de la funcion (memo[i-1]-memo[i-k-1])
        //Lo que seria equivalente a 2 veces el anterior (memo[i-1]) menos el valor del primer elemento que ya no es considerado en el rango de subsumas (memo[i-k-1])
        memo[i] = (((memo[i-1]*2)%mod-memo[i-k-1])+mod)%mod; 
    }
    //Como la localidad memo[n] guarda la suma de todos los estados hasta el n-esimo, para extraer el n-esimo es simplemente la resta de memo[n]-memo[n-1]
    printf("%d\n",((memo[n]-memo[n-1])+mod)%mod); //Se imprime el n-esimo
    
    return 0;  
}