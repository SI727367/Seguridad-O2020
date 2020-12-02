#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned long long Numeros1[4] = {95,25,42,10};
    unsigned long long Numeros2[4] = {38,45,63,00};
    unsigned long long Numeros3[4] = {45,45,45,45};
    unsigned long long NResultados[4];
    unsigned long long NCache = 0;

    //Intento para capturar datos
    /*for (size_t i = 0; i < 4; i++)
    {
        printf("Ingrese el %d numero",i+1);
        scanf("%d",Numeros1[i]);
    }*/
    
    /*for (size_t i = 0; i < 4; i++)
    {
        printf("Ingrese el %d numero",i+1);
        scanf("%d",Numeros2[i]);
    }*/

    for (size_t i = 0; i < 4; i++)
    {
        unsigned long long NIntCache = Numeros1[i] + NCache;
        if (NIntCache < NCache)
        {
            NResultados[i] = Numeros2[i] % Numeros3[i];
        }
        else
        {
            NIntCache += Numeros2[i];
            NCache = Numeros2[i] > NIntCache ? 1:0;
            NResultados[i] = NIntCache % Numeros3[i];

        }

    }
    for (size_t i = 0; i < 4; i++)
    {
        printf("%llu",NResultados[i]);
    }
    return 0;
}