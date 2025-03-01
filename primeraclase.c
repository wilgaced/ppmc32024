/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Sabados                                     */
/*  Practica:  hola mundo                                  */
/*  Fecha:     25/1/2025                                   */
/*  Link al video: https://onedrivldkasdofiof.com          */
/***********************************************************/

// Inclucion de encabezados
#include <stdio.h>

// Declaracion de definiciones y macros

// Declaracion de constantes

// Declaracion de variables globales

// Declaracion de prototipos de funciones
int multiplicacion(int a, int b);


// Programa
/*****************************************************************************//*!
   * @brief funcion principal. 
   * @param[in] recive un primer argumento entero y un segundo argumento una cadana de caracters.
   * @return devuelve un entero que puede ser utilizado como indicador de error
   * @ Pass/ Fail criteria:  none.
*****************************************************************************/
int main(void)
{
   int op1 = 0;
    printf("Tabla de multiplicar de un numero\r\n");
    scanf("%d", &op1);
      for (int i = 0; i < 11; i++)
      {
         printf("%d x %d = %d\r\n", op1, i, multiplicacion(op1, i));
      }

}

int multiplicacion(int a, int b)
{
    return a * b;
}