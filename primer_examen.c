/**Alumno: Ruben Abimalec Caballero Sanchez --Matr: 19760767 ---examen 1/3
El codigo para resolver el problema lo reparti en 2 partes
La Primera parte mete los digitos del numero ingresado a un arreglo
por medio de dos funciones externa a la funcion principal, dentro de la funcion principal
se lee el numero por teclado y se guarda en una variable, despues se pasa como
argumento ese mismo numero a la funcion contador que principalmente
cuenta las iteraciones que hace un while al deconstruir un numero de manera que
de cada iteracion divide el numero y toma la parte entera hasta que
la parte entera de la division sea cero, esto indica se terminaron los digitos a iterar.
Una vez que se tiene el numero de digitos se guarda dentro de otra variable y se declara
el arreglo con una longitud de elementos con el numero de digitos que se ingreso por teclado.
La segunda funcion genera el arreglo de caracteres que tendra el arreglo de digitos, tiene 3 argumentos
de entrada, el arreglo de numeros, la longitud del arreglo y el numero que se ingreso por teclado.
mediante un ciclo for se llena el arreglo a la inversa con la conversion de tipo ASCII teniendo como
resultado en cada iteracion un digito.
Al funal solo se hace la imagen del arreglo al imprimir desde la funcion principal
funciona de la siguiente manera:
posicionde:2
suma:5
ingrese el numero: 1235
arroja: elemento: 4
arroja: el arreglo es: [1, 2, 3, 5]
arroja: Arreglo con la suma realizada: [1, 2, 8, 5]


*/

#include <stdio.h>
#include <stdlib.h>
void convierte_arr(int num, char *numeros, int longit)
{
    numeros[longit] = '\0';
    // longitud menos 1 reptesenta empezar a llenar desde el
    // penultimo, osea uno antes del valor nulo o el final de la linea
    for (int i = longit - 1; i >= 0; i--)
    {
        // convertimos el numero original por metodo de conversion de tipo ASCII
        // tomamos la parte residuo y le sumamos el codigo asi de cero que
        //  es 48 entonces da el numero residuo pero en ASCII
        numeros[i] = (num % 10) + '0';
        // dejamos la parte entera para volver
        // a hacer el proceso anterior en la siguiente iteracion
        num = num / 10;
    }
}
int contador(int num)
{
    int count_digit = 0;
    // cuando el numero es igual a cero dejamos de iterar
    while (num != 0)
    {
        count_digit++;
        // deconstuyendo el numero original en cada iteracion, dividimos y tomamos solo la parte entera
        num = num / 10; // la inversa de convertir un caracter a numero
    }
    return count_digit;
}
void sumale(int posicion, int suma, char arreglo[], int elementos)
{
    // Asegurarnos de que la posición sea válida
    if (posicion < 0 || posicion >= elementos)
    {
        printf("La posision no es validA\n");
        return;
    }
    // Sumar el valor a la posición indicada
    arreglo[posicion] = arreglo[posicion] + suma;
    // if (arreglo[posicion] > 9)
}

int main()
{
    int posicion = 2;
    int suma = 5;
    int num = 0;
    printf("ingrese el numero: ");
    scanf("%d", &num);
    // numero de digitos en el numero dado
    char elementos = contador(num);
    if (elementos <= 0)
    {
        printf("No ingreso ningun numero");
        return 0;
    }

    printf("elemento: %d \n", elementos);
    // mas uno representa el valor nulo al final del arreglo de elementos, el final de la linea
    char numeros[elementos + 1];

    convierte_arr(num, numeros, elementos);
    // printf("El arreglo con los digitos separados es: %s \n", numeros);
    //  Imprimir cada digito como un elemento separado en el arreglo
    printf("el arreglo es: [");
    for (int i = 0; i < elementos - 1; i++)
    {
        printf("%c", numeros[i]);
        if (i < elementos - 1)
        {
            printf(", ");
        }
    }
    printf("%c]\n", numeros[elementos - 1]);

    // mandamos a hacer la suma en el arreglo
    sumale(posicion, suma, numeros, elementos);

    // imprime el arreglo ya sumado
    printf("Arreglo con la suma realizada: [");
    for (int i = 0; i < elementos - 1; i++)
    {
        printf("%c", numeros[i]);
        if (i < elementos - 1)
        {
            printf(", ");
        }
    }
    printf("%c]\n", numeros[elementos - 1]);
    return 0;
}

/**referencias
 -Binary Man. (2021, 1 octubre). Programación en C: STRINGS | Como almacenar cadenas de caracteres [Vídeo]. YouTube. https://www.youtube.com/watch?v=pJHNYeAKogA
 -Hayde, H. (s. f.). Ciencias computacionales Propedéutico: Programación. Recuperado 1 de agosto de 2023, de https://posgrados.inaoep.mx/archivos/PosCsComputacionales/Curso_Propedeutico/Programacion_Estructuras_Datos/Capitulo_3_Apuntadores.pdf#page7
 -KERNIGHAN, B., [BRIAN W. KERNIGHAN], & RITCHIE, D., [DENNIS M. RITCHIE]. (1991). EL LENGUAJE DE PROGRAMACION C (2.a ed.). PRENTICE-HALL HISPANOAMERICANA, S.A.
 -makigas: aprende a programar. (2023, 4 abril). Cómo convertir char a número en C [Vídeo]. YouTube. https://www.youtube.com/watch?v=HxnaGER_lXI
 -Peter. (s. f.). Codigo ASCII 0 , Número cero, tabla con los codigos ASCII completos, caracteres simbolos letras numero, cero, 0,ascii,48, ascii codigo, tabla ascii, codigos ascii, caracteres ascii, codigos, tabla, caracteres, simbolos, control, imprimibles, extendido, letras, vocales, signos, simbolos, mayusculas, minusculas, alt, teclas, acentos, agudo, grave, eñe, enie, arroba, dieresis, circunflejo, tilde, cedilla, anillo, libra, esterlina, centavo, teclado, tipear, escribir, español, ingles, notebook, laptop, asccii, asqui, askii, aski,20230801. Codigo ASCII 0 , Número cero. https://elcodigoascii.com.ar/codigos-ascii/numero-cero-0-codigo-ascii-48.html

*/