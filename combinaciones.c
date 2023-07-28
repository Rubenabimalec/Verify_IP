#include <stdio.h>

void combinaciones(int bits_prestados)
{
    if (bits_prestados < 1)
        return;
    if (bits_prestados > 23)
        return;

    int max_combinaciones = 1 << bits_prestados; // Calcula el numero de combinaciones (2^bits_prestados)

    for (int i = 0; i < max_combinaciones; ++i)
    {
        printf("%d: ", i);

        // Imprimir los bits (combinacion actual)
        for (int j = bits_prestados - 1; j >= 0; --j)
        {
            int bit = (i >> j) & 1; // hace la operacion and con cada bit de izquierda a derecha
            printf("%d", bit);
        }

        printf("\n");
    }
}

int main()
{
    int bits_prestados = 5;
    combinaciones(bits_prestados);

    return 0;
}
