/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Sabados                                     */
/*  Practica:  hola mundo                                  */
/*  Fecha:     7/9/2024                                    */
/***********************************************************/

//Inclucion de encabezados
#include <stdio.h>
#include <stdlib.h>

//Declaracion de definiciones y macros


//Declaracion de constantes
const float PI = 3.1416;

//Declaracion de variables globales
char operacion = 0;
int op1 = 0;
int op2 = 0;

//Declaracion de prototipos de funciones
int suma(int a, int b);
int resta(int a, int b);

//Programa
int main(int argc, char const *argv[])
{
    do
    {
       printf("Calculadora Basica\r\n");
    printf("Digite la operacion que desea realizar\r\n");
    scanf("%c", &operacion);
    if(operacion == '+'){
        printf("Digite el primer oprando\r\n");
        scanf("%d", &op1);
        scanf("%d", &op2);
        printf("el resultado de sumar %d + %d = %d\r\n",op1, op2, suma(op1, op2));
    }
    else if (operacion == '-')
    {
        printf("Digite el primer oprando\r\n");
        scanf("%d", &op1);
        scanf("%d", &op2);
        printf("el resultado de resta %d + %d = %d\r\n",op1, op2, resta(op1, op2));
    }
    else
    {
        printf("operacion no valida intentelo de nuevo o presio x para salir\r\n");
        puts("Press any key to continue ... ");
        fflush;
        getchar();
        getchar();
        system("clear");
        
    }
    

    
    } while (operacion != 'x');
    
    
}

/*Funcion suma*/
/*Argumentos de entra int a, int b      
Argumento de salida la suma de a + b                 
criterios de falla ninguno*/

int suma(int a, int b)
{
    return a + b;
}

/*Funcion resta*/
/*Argumentos de entra int a, int b      
Argumento de salida la resta de a - b                 
criterios de falla ninguno*/

int resta(int a, int b)
{
    return a - b;
}
