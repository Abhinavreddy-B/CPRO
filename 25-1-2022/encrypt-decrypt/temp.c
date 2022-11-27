#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    long long int key[800127] = {0}, int_key[100000] = {0}, dec[100000] = {0};
    unsigned char temp;
    FILE *fp[3];

    fp[0] = fopen(argv[1], "r");
    fp[1] = fopen(argv[2], "r");
    fp[2] = fopen(argv[3], "w");

    for (long long int i = 0; i < 127; i++)
    {
        fscanf(fp[0], "%c", &temp);
        key[i] = temp - '0'; // Converts chars 0 and 1 from enc.txt to ints 0 and 1
    }

    for (long long int i = 127; i < 800127; i++)
    {
        key[i] = key[i - 1] ^ key[i - 127]; //generating all bits of key
    }

    for (long long int i = 127, j = 0; i < 800127, j < 100000; i += 8, j++)
    {
        long long int pow = 128, k = 0;

        while (k <= 7) // convert key bits from bit 128 to end bit in groups of 8 into int
        {
            int_key[j] += key[i + k] * pow;
            pow /= 2;
            k++;
        }
    }

    for (long long int i = 0; i < 100000&&(fscanf(fp[1], "%c", &temp) != EOF) ; i++)
    {
        long long int k = 0, pow = 128, break_trigger = 1;
        unsigned char ans;

        while ((k <= 7))
        {
            dec[i] += (temp - '0') * pow;
            pow /= 2;
            k++;
            break_trigger = 0;
        }

        if (break_trigger)
        {
            break;
        }

        else
        {
            ans = int_key[i] ^ dec[i];

            fprintf(fp[2], "%c", ans);
        }
    }

    for (long long int i = 0; i < argc - 1; i++)
    {
        fclose(fp[i]);
    }

    return 0;
}