
/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Miercoles                                   */
/*  Practica:  Array                                       */
/*  Fecha:     9/10/2024                                   */
/***********************************************************/

// Inclucion de encabezados
#include <stdio.h>

// Declaracion de definiciones y macros

// Declaracion de constantes

// Declaracion de variables globales

// Declaracion de prototipos de funciones
void clean_stdin(void);

int main(int argc, char const *argv[])
{
    int opcion = 0;
    while (opcion != 0)
    {
        printf("1. Imprimir arreglo de enteros\r\n");
        printf("2. Imprimir arreglo de caracteres\r\n");
        printf("3. Salir\r\n");
        printf("4. Imprimir arreglo de enteros de 2 dimensiones\r\n");
        printf("5. Imprimir arreglo de caracteres de 2 dimensiones\r\n");
        scanf("%d", &opcion);
        clean_stdin();

        switch (opcion)
        {
        case 1:
        {
            printf("usted selecciono la opcion 1\r\n");
            break;
        }
        case 2:
        {
            printf("usted selecciono la opcion 2\r\n");
            break;
        }
        case 3:
        {
            printf("usted selecciono la opcion 3\r\n");
            break;
        }
        case 4:
        {
            printf("usted selecciono la opcion 4\r\n");
            break;
        }
        case 5:
        {
            printf("usted selecciono la opcion 5\r\n");
            break;
        }
        default:
        {
            printf("Opcion no valida\r\n");
            break;
        }
        }
    } 

    return 0;
}

/*@brief funcion para limpiar el buffer de entrada*/
/*@param[in] void                                 */
/*@return void                                    */
/*@ Pass/ Fail criteria:  none.                   */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}