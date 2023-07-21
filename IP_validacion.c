#include <stdio.h>
#include <stdbool.h>

bool Verify_IP(char *ip)
{
    int num;
    int puntos = 0;
    int i = 0;
    while (*ip)
    {
        if (*ip == '.')
        {
            if (num < 0 || num > 255)
            {
                return false;
            }
            num = 0;
            puntos++;
        }
        else if (*ip >= '0' && *ip <= '9')
        {
            num = num * 10 + (*ip - '0');
        }
        else
        {
            return false;
        }
        ip++;
        i++;
    }
    if (puntos != 3 || num < 0 || num > 255)
    {
        return false;
    }
    return true;
}
int main()
{
    char ip[16]; // caracteres de la ip
    printf("Ingrese una direccion IP:   ");
    scanf("%15s", ip);
    if (Verify_IP(ip))
    {
        // bloque de código a ejecutar si la condición es verdadera
        printf("La direccion IP ingresada es Valida.\n");
    }

    else
    {
        // bloque de código a ejecutar si la condición es falso
        printf("La direccion IP ingresada es invalida.\n");
    }
}