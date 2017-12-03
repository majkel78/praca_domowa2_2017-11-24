#include <stdio.h>

int main() {

    unsigned long int liczba_kolejna;
    unsigned long int licznik;
    unsigned long int wynik = 0;
    unsigned long int poprzednia1=0;
    unsigned long int poprzednia2=1;

    printf("Podaj wartosc calkowita dla ktorej mam obliczyc liczbe Fibonacciego, n = ");
    scanf(" %ld", &liczba_kolejna);

    if (liczba_kolejna <= 92) {

        for (licznik = 1; licznik < liczba_kolejna; licznik++) {
            wynik = poprzednia1+poprzednia2;
            poprzednia1=poprzednia2;
            poprzednia2=wynik;
        }

        printf("\nLiczba Fibonacciego (%ld): %ld\n", liczba_kolejna, wynik);

    } else {
        printf("Za duza wartosc n, n <= 92\n");
    }

    return 0;
}
