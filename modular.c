
/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Miercoles                                   */
/*  Practica:  Array                                       */
/*  Fecha:     9/10/2024                                   */
/***********************************************************/

#include <stdio.h>

//Varibles globales
int a = 0;
int b = 0;
float result = 0.0;

//Declaracion de funcinciones
float suma(int c, int d);
float factorial(int a);

int main(void)
{
    printf("Primer valor\r\n");
    scanf("%d", &a);
    result = factorial(a);
    printf("!%d = %f\r\n",a,result);
    printf("Segundo valor\r\n");
    scanf("%d", &b);
    result = suma(a,b);
    printf("%d + %d = %f\r\n",a,b,result);
    return 0;
}

/*Funcion suma
InParam two int
OutParam sum of two int and return floa
Fail: none */
float suma(int c, int d)
{
    return c + d;
    
}

/*Funcion factorial
InParam one int
OutParam factorial of a number int return float
Fail: none */
float factorial(int n)
{
    float f=0.0;
    if (n==0) f=1;
        else f=n*factorial(n-1);
    return f;
}
