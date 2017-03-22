#include <stdio.h>
#include <stdlib.h>
int main(){
    int num,i,n=4,cont=2,j=0;
    int cad[1000];
    // printf("ingrese un numero\n");
    // scanf("%d",&num);
    num = 10000;
    if(num>2){
        printf("2 3");
        while(cont<num){
            i=2;
            while(i<=n){
                if(i==n){
                    cad[j]=n;
                    printf(" %d ",cad[j]);
                    j++;
                    cont=cont+1;
                }else{
                if(n%i==0){
                    i=n;
                }
                }
                i=i+1;
            }
            n=n+1;
        }
    }else{
    if(num>0){
        if(num==1){
            printf("es primo 2");
        }else{
            printf("es primo 2, 3");
        }
    }else{
        printf("ingrese numeros positivos");
    }
    }
   return 0;
}
