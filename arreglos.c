
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
__uint8_t arrayuni[3] = {1,5,9};
char array[8][8]={{"wfafaabc"},
                  {"diddfsff"},
                  {"ghljrrgi"},
                  {"gimknrgi"},
                  {"ghmairgi"},
                  {"ghljrngi"},
                  {"gamjrrsi"},
                  {"ghmjrrgi"} };   //arreglo de tipo entero de 8 posiciones 
int opcion = 0;

int main(int argc, char const *argv[])
{
    
    do
    {
        printf("favor de elegir la opcion\r\n");
        printf("1: para lala\r\n");
        printf("2: para lele\r\n");
        printf("3: para tutu\r\n");
        printf("4: para salir\r\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("usted seleciono el 1\r\n");
            break;
        case 2:
            printf("usted seleciono el 2\r\n");
            break;
        case 3:
            printf("usted seleciono el 3\r\n");
            break;   
        
        default:
            printf("Opcion no valida intentelo de nuevo\r\n");
            break;
        }
    } while (opcion != 4);

    arrayuni[1] = 4;
    printf("Elemento es: %d del arreglo array posicion %d\r\n", arrayuni[1], 1);
    
    array[2][2] = 'w';
    printf("Elemento No. %c del arreglo array fila %d columna %d\r\n", array[2][2], 2,2);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Elemento No. %c del arreglo array fila %d columna %d\r\n", array[i][j], i,j);
        }
        
        
    }
    
    return 0;
}