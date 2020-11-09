#include <stdio.h>
int main()
{
    int n1, n2;
    printf("Ingresa dos numeros [N N]\n~> ");
    scanf("%d %d",&n1,&n2);

    n1 = ( n1 > 0) ? n1 : -n1;
    n2 = ( n2 > 0) ? n2 : -n2;

    while(n1!=n2)
    {
        if(n1 > n2){
             n2 -= n1;
        }   
        else{
            n1 -= n2;
        }
        
    }
    printf("GCD = %d",n1);
    return 0;
}