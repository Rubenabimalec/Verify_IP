#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
/**
La problematica de este ejercio se basa en validar una IP.
la funcion principal se pide al usuario la direccion ip que desea
validar mediante la funcion fgets que lee una cadena de caracteres
ingresadas y las deposita en un arreglo de tipo char nombrado como INPUT.
Por segundo eliminamos el caracter final de salto de linea, si existiera,
con un if que recorre el arreglo input menos 1 encuentra un salto de
linea lo elimina y le asigna un un fin de linea que es representado por '\0'

El tercer paso ya teniendo la ip dentro del buffer, es mandar a validar el
IP a la funcion externa a la principal, que denomine como "validar_ip" de tipo booleana, esta
funcion retorna una señal true o false indicando si es o no valida la IP
-La Funcion de validar ip se conforma de un ciclo while que esta ejecutando mientras
no encuentro un fin de linea.En cada iteracion del while la logica está en dividir por bloques el ip,
tenemos 3 puntos que dividen los numeros, una vez que empieza a recorrer el arreglo que apunta a
la cadena de caracteres que ingresamos por teclado se valida cada caracter al que se
ingresa, de esta forma se construye un numero de 3 digitos por el metodo de conversion
de tipo, formado este numero se valida que no sea de mas de 3 digitos, que
no sea menor a cero(no sea numero negativo) y que no sea mayor a 255. Otra validacion
que se hace es que no se puede empezar con un caracter que no sea un digito
por lo cual si no es un digito en la primera iteracion del while, entonces retornara
falso y sino entonces tendremos que se empieza el segundo bloque de la ip, por
decirlo de otra manera el punto se va contando cuantos numeros vamos validando,
sirve como punto de reinicio de las variables que nos ayudan a armar el numero que se quiere validar.
Una vez que ya encuentre.
Al final de la validacion del while hace una validacion para saber si
hay mas puntos de los que deberia en el contador o si no hay ningun digito
en el contador y como el utimo numero  ya no se inicializa porque ya no hay punto,
entonces solo se verifica que el numero no sea mayor a 255 o menor a cero otra vez
 */

//---------------validarIP-------------------------------------
bool validar_ip(char *ip)
{
    int count_points = 0;
    int count_digits = 0;
    int numero = 0;
    int i = 0;
    while (ip[i] != '\0')
    {
        if (isdigit(ip[i])) // verificar que cada caracter sea un digito
        {
            numero = numero * 10 + (ip[i] - '0'); // construir el numero por conversión de caracteres a números en codigo ASCII
            count_digits++;
            if (count_digits > 3 || numero < 0 || numero > 255)
            {
                return false;
            }
        }
        else if (ip[i] == '.')
        {
            if (count_digits == 0)
            {
                return false;
            }
            numero = 0;
            count_digits = 0;
            count_points++;
        }
        else
        {
            return false;
        }
        i++;
    }
    if (count_points != 3 || count_digits == 0 || numero < 0 || numero > 255)
    {
        return false;
    }
    return true;
}
//-----------------------Impresion---en binario--------------
void connversion_binario(char *ip)
{
    int num[4]; // Array para almacenar cada parte numérica de la dirección IP
    int n = sscanf(ip, "%d.%d.%d.%d", &num[0], &num[1], &num[2], &num[3]);

    // Imprimir la dirección IP en formato binario
    printf("Direccion IP en formato binario: ");
    for (int i = 0; i < 4; i++)
    {
        char binario[9]; // Un arreglo de caracteres para representar cada parte numérica en binario
        int resto;
        int cociente = num[i];

        // Convertir cada parte numérica en binario
        for (int j = 0; j < 8; j++)
        {
            resto = cociente % 2;
            cociente = cociente / 2;
            binario[7 - j] = resto + '0'; // Convertir el dígito binario en un carácter ('0' o '1')
        }
        binario[8] = '\0'; // Agregar el terminador nulo al final de la cadena

        // Imprimir la parte numérica en binario
        printf("%s", binario);
        if (i < 3)
        {
            printf(".");
        }
    }
    printf("\n");
}
//------------------------Funcion principal------------------------
int main()
{
    char input[20];
    printf("Ingrese una direccion IP: ");
    fgets(input, sizeof(input), stdin);
    // Eliminar el carácter de salto de línea final (si existe)
    if (input[strlen(input) - 1] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }
    if (validar_ip(input))
    {
        printf("La direccion IP es valida.\n");
        connversion_binario(input);
    }
    else
    {
        printf("La direccion IP NO es valida.\n");
    }

    return 0;
}
/** referencias:
-KERNIGHAN, B., [BRIAN W.KERNIGHAN], &RITCHIE, D., [DENNIS M.RITCHIE].(1991)
.EL LENGUAJE DE PROGRAMACION C(2.a ed.).PRENTICE - HALL HISPANOAMERICANA, S.A.
-makigas aprende a programar.(2020, 5 noviembre).Tutorial de C – 24. Archivos(4)
Leer con FGets[Vídeo].YouTube.https: // www.youtube.com/watch?v=b-fAFEbZuvI
-UnPuntoycoma. (2017, 30 noviembre). [Lenguaje C #3] Leer cadenas de texto con FGets. [Vídeo].
YouTube. https://www.youtube.com/watch?v=JWiDnEbpE8E
*/