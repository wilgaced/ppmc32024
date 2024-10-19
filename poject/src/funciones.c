
/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Miercoles                                   */
/*  Practica:  Funciones                                   */
/*  Fecha:     9/10/2024                                   */
/***********************************************************/

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
