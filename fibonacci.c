#include <stdio.h>

int main() {

    unsigned long int liczba_kolejna;
    unsigned long int licznik;
    unsigned long int wynik = 0;
    unsigned long int poprzednia1=0;	// zmienne do przechowywania poprzednich liczb w kolejnosci:
    unsigned long int poprzednia2=1;	// poprzednia1, poprzednia2, liczba_kolejna

    printf("Podaj wartosc calkowita dla ktorej mam obliczyc liczbe Fibonacciego, n = ");
    scanf(" %ld", &liczba_kolejna);

    if (liczba_kolejna <= 92)
    {
		if(liczba_kolejna<2)
			wynik=liczba_kolejna;
		else
		{
			for (licznik = 2; licznik <= liczba_kolejna; licznik++)
			{
				wynik = poprzednia1+poprzednia2;
				poprzednia1=poprzednia2;			// poprzednia1=liczba_kolejna(-2) bedzie tym czym byla liczba_kolejna(-1)
				poprzednia2=wynik;					// poprzednia2=liczba_kolejna(-1) bedzie tym czym byla liczba_kolejna(0)
			}
        }

        printf("\nLiczba Fibonacciego (%ld): %ld\n", liczba_kolejna, wynik);

    }
    else
    {
        printf("Za duza wartosc n, n <= 92\n");
    }

    return 0;
}
