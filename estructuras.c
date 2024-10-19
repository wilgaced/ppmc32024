/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Sabados                                     */
/*  Practica:  struturas                                   */
/*  Fecha:     7/9/2024                                    */
/*  Link al video: https://onedrivldkasdofiof.com          */
/***********************************************************/

// Inclucion de encabezados
#include <stdio.h>
#include <stdlib.h>

// Declaracion de definiciones y macros

// Declaracion de constantes

//Declaracion de variables 
struct fecha
    {
        int dia;
        int mes;
        int anio;
    };
typedef struct Datos
{
    char nombre[20];
    char apellido[20];
    char ID[20];
    int edad;
    int nota;
    float promedio;
    struct fecha nacimiento;
  
    
}datos;

datos alumnos[20]; //array



int main(int argc, char const *argv[])
{
    printf("Favor introducir datos alumno\r\n");
    printf("Introdusca el nombre\r\n");
    scanf("%s", &alumnos[0].nombre);
    printf("Introdusca el apellido\r\n");
    scanf("%s", &alumnos[0].apellido);
    printf("el apellido es %s\r\n",alumnos[0].apellido);
    printf("dia de nacimiento\r\n");
    scanf("%d", &alumnos[0].nacimiento.dia);
    return 0;

}
