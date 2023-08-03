/*Alumno: Ruben Abimalec Caballero Sanchez --Matr: 19760767 ---examen 1/3
El ejercicio se basa en tratar de hacer todo de forma manual aunque aun no
se agrega la entrada por consola. La idea es de que el usuario ingrese el arreglo
de  numeros y que en un punto para que el usuario marque el fin de ingreso ponga el "-1",
 nos ayuda tambien deja marcado el final del arreglo de numeros como un
valor de busqueda para poder recorrer el arreglo en un siguiente bucle while y asi
no necesariamente buscar la longitud del arreglo en otro ciclo extra o mas tiempo
de ejecucion.
De esta forma la funcion finder solo recibe el arreglo y el resultado el numero N a comparar.


*/
#include <stdio.h>

void SumaFinder(int N, int vector[])
{
    int i = 0;
    while (vector[i] != -1)
    {
        int j = i + 1;
        while (vector[j] != -1)
        {
            if (vector[i] + vector[j] == N)
            {
                printf("  [%d] y [%d]\n", i, j);
            }
            j++;
        }
        i++;
    }
}

int main()
{
    int vector[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 33, 54, 7, -1};
    int N = 8;
    int i = 0;
    printf("Arreglo original: [");
    while (vector[i] != -1)
    {
        printf("%d, ", vector[i]);
        i++;
    }
    printf("\b\b]\n"); // Eliminamos la última coma y espacio antes del corchete final

    printf("Combinaciones que suman %d:\n", N);
    SumaFinder(N, vector);

    return 0;
}