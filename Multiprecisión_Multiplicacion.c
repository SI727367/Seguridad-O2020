#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
    unsigned long long Numeros1[4] = {10,25,32,40};
    unsigned long long Numeros2[4] = {44,34,20,10};
    unsigned long long NResultados = 0;
    unsigned long long NTabla [4][7];

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            NTabla [i][j] = 0;
        }
        
    }
    

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
    
    //Row 1
    for (size_t i = 3; i < 7; i++)
    {
        NTabla [0][i] = Numeros2[3] * Numeros1[i-3];
    }

    //Row 2
    for (size_t i = 2; i <6; i++)
    {
        NTabla [1][i] = Numeros2[2] * Numeros1[i-2];
    }

    //Row 3
    for (size_t i = 1; i < 5; i++)
    {
        NTabla [2][i] = Numeros2[1] * Numeros1[i-1];
    }

    //Row 4
    for (size_t i = 0; i < 4; i++)
    {
        NTabla [3][i] = Numeros2[0] * Numeros1[i];
    }


    /*for (size_t i = 0; i < 4; i++)                        //Checar la tabla
    {
        for (size_t j = 0; j < 7; j++)
        {
            printf("        %llu        ",NTabla [i][j]);
        }

        printf("\n");
    }*/

    unsigned long long Z[7];
    Z[0] =  NTabla[0][6];
    Z[1] =  NTabla[0][5] + NTabla[1][5];
    Z[2] =  NTabla[0][4] + NTabla[1][4] + NTabla[2][4];
    Z[3] =  NTabla[0][3] + NTabla[1][3] + NTabla[2][3] + NTabla[3][3];
    Z[4] =  NTabla[1][2] + NTabla[2][2] + NTabla[3][2];
    Z[5] =  NTabla[2][1] + NTabla[3][1];
    Z[6] =  NTabla[3][0];
    
    /*for (size_t i = 0; i < 7; i++)  //Imprimir valores Z
    {
        printf("%d %llu\n",i,Z[i]);
    }*/
    
    unsigned long long Residuo = 0;
    for (size_t i = 0; i < 7; i++)
    {
        int digits = 0;
        unsigned long long dcache = Z[i];
        if (dcache < 0) digits = 1; 
        while (dcache) {
            dcache /= 10;
            digits++;
        }

        //printf("%d\n",digits); Imprimir cantidad Digitos

        if (digits == 1)
        {
            NResultados += Z[i] * (pow(10,i));
        }
        else
        {
            unsigned long long dcache2;
            int power = pow(10,i);
            dcache2 = ((Z[i] % (10 * power))*power) + (Residuo*power);
            Residuo = dcache2 % 10;
            NResultados = dcache2;
        }
    }
    
    NResultados += Residuo*pow(10,7);
    printf("%llu",NResultados);
    return 0;
}