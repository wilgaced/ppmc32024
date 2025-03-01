
/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Miercoles                                   */
/*  Practica:  Array                                       */
/*  Fecha:     9/10/2024                                   */
/***********************************************************/

#include <stdio.h>
#include <stdbool.h>

//Varibles globales
__uint8_t arrayuni[8] = {1,5,7,6,3,2,4,8};   //arreglo de tipo entero de 8 posiciones
char array[8][8]={{"wfafaabc"},
                  {"diddfsff"},
                  {"ghljrrgi"},
                  {"gimknrgi"},
                  {"ghmairgi"},
                  {"ghljrngi"},
                  {"gamjrrsi"},
                  {"ghmjrrgi"} };   //arreglo de tipo entero de 8 posiciones 
char datain = '0';
int opcion = 0;
bool noanumber = false;

// prototipo de funcion
void clean_stdin(void);

int main(void)
{
    
    do
    {
        printf("1. Imprimir arreglo de enteros\r\n");
        printf("2. Imprimir arreglo de caracteres\r\n");
        printf("3. Salir\r\n");
        
        do
        {
           datain = getchar();
           clean_stdin();
           opcion = datain - '0';
           if((opcion < 0) || opcion > 9){
                noanumber = true;
                printf("no es un numero intentelo de nuevo");
           }
           else
           {
            noanumber = false;
           }
           
                
        } while (noanumber);
        
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < 8; i++)
            {
                printf("%d \n", arrayuni[i]);
            }
            printf("\r\n");
            break;
        case 2:
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    printf("%c ", array[i][j]);
                }
                printf("\r\n");
            }
            break;
        case 3:
            break;
        default:
            printf("Opcion no valida\r\n");
            break;
        }

    array[4][3] = 'Z';
    if (array[4][3] == 'a')
    {
        printf("Se cambio el valor de la posicion 4,3 a 'a'\r\n");
    }
    } while (opcion != 3);


    for(;;);
    while(1);
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