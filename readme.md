# 1. Liczbowe typy danych (binarny, ósemkowy, szesnastkowy)

Najpopularniejszym używanym systemem liczbowym jest system dziesiętny. Jest to system pozycyjny o podstawie 10. Konstrukcje liczące (komputery) zapisują informacje w pamięci w postaci bitów. Interpretacja tych informacji notowana jest za pomocą cyfr 0 oraz 1 i jest nazywana zapisem (systemem) binarnym lub dwójkowym. W systemie pozycyjnym używa się też innych systemów, z czego oprócz napopularniejszego dziesiętnego także szesnastkowego i ósemkowego.

### Typ binarny (dwójkowy)
Pozycyjny system liczbowy o podstawie 2. Podstawę jego stanowi liczba 2, wszystkie więc liczby można zapisać dwiema tylko cyframi: 0 i 1. Liczby naturalne w systemie dwójkowym zapisujemy tak samo jak w systemie dziesiętnym - zamiast kolejnych potęg liczby dziesięć, stosujemy kolejne potęgi liczby dwa.

Przykład zapisania liczby dziesiętej 9 w systemie dwójkowym:<br>
1001<sub>(2)</sub> = 1 * 2<sup>3</sup> + 0 * 2<sup>2</sup> + 0 * 2<sup>1</sup> + 1 * 2<sup>0</sup> = 8 + 1 = 9<sub>(10)</sub>

Na potrzeby systemów informatycznych opracowano w systemie dwójkowym sposób reprezentacji liczb ujemnych:
- kod znak-moduł
- kod uzupełnienie do jedności (U1)
- kod uzupelnienie do dwóch (U2) - najczęściej używany

### Typ ósemkowy (oktalny)
Pozycyjny system liczbowy o podstawie 8. Podstawa wynosi 8 więc wszystkie liczby zapisuje się cyframi od 0 do 7. Nazywany jest też systemem "oktalnym" (od słowa octal).

Przykład zapisania liczby dziesiętnej 99 w systemie ósemkowym:<br>
143<sub>(8)</sub> = 1 * 8<sup>2</sup> + 4 * 8<sup>1</sup> + 3 * 8<sup>0</sup> = 64 + 32 + 3 = 99<sub>(10)</sub>

W językach programowania do zapisu liczby w formacie oktalnym (jeżeli język przewiduje wprowadzanie liczb w takim formacie) stosuje się przerostek 0 np. 0143 to zapis ósemkowy liczby dziesiętnej 99. Przykładem wykorzystującym zapis ósemkowy jest polecenie `chmod` (w systemach linux) którym zmienia się uprawnienia do plików (aby ustawić uprawnienia na `rwx r-x r--` stosuje się polecenie `chmod 754 plik`).

### Typ szesnastkowy (heksadecymalny)
Pozycyjny system liczbowy o podstawie 16. Cyfry w tym systemie zapisuje się za pomocą znaków: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F. Cyfry od 0 do 9 mają te same wartości co w systemie dziesiętnym natomiast A, B, C, D, E, F odpowiadają kolejno wartościom 10, 11, 12, 13, 14, 15.

Przykład zapisania liczby dziesiętnej 999 w systemie szesnastkowym:<br>
3E7<sub>(16)</sub> = 3 * 16<sup>2</sup> + 14 * 16<sup>1</sup> + 7 = 768 + 224 + 7 = 999<sub>(10)</sub>

W językach programowania bardzo często używa się zapisu szesnastkowego. Najczęstsze sposoby zapisu to:
- w językach C,C++,C#, Java, Python: prefiks 0x (np. `0x3E7`)
- w języku Pascal prefix $ (np. `$3E7`)
- w asemblerze spotyka się formę za pomocą sufiksa h (np. `3E7h`)
- w HTML/CSS używa się prefiksa # (przykład to wartość koloru - `#FF99A0`)

W systemach informatycznych system szesnastkowy stosuje się między innymi do zapisu koloru (`0xFF0000` oznacza czerwony), adresu sprzętowego MAC (`00:0B:E3:2F:FA:D1`) czy też adresu IPv6 (`2001:db8:85a3:8d3:1319:8a2e:370:7348`).

# 2. Konwersja między systemami 10-2 oraz 16-2
### Konwersja z systemu dziesiętnego na dwójkowy
Do manualnej konwersji liczby dziesiętnej na dwójkową stosujemy niniejszy sposób:
- liczbę dziesiętną dzielimy na 2
- zapisujemy wynik poniżej a obok resztę z dzielenia
- dzielenie (za każdym razem przez 2) wykonujemy aż osiągniemy w wyniku dzielenia 0

Przykład:

| Liczba dziesiętna | Dzielimy przez 2 | Reszta (modulo) |
|-------------------|------------------|-----------------|
|122                |:2                |0                |
|61                 |:2                |1                |
|30                 |:2                |0                |
|15                 |:2                |1                |
|7                  |:2                |1                |
|3                  |:2                |1                |
|1                  |:2                |1                |
|0                  |-                 |-                |

Wynik odczytujemy od dołu i w tym przypadku będzie to 122<sub>(10)</sub> = 1111010<sub>(2)</sub>

### Konwersja z systemu dwójkowego na dziesiętny
Przeliczanie z systemu dwójkowego na dziesiętny odbywa się poprzez mnożenie cyfry na danej pozycji z wartością jaką odpowiada przypisana do niej waga. Wagi odpowiadają kolejnym potęgom liczby będącej podstawą systemu (czyli w przypadku systemu binarnego jest to 2) począwszy od potęgi 0 oraz zaczynając od ostatniej liczby.

Przykład:<br>
1111010<sub>(2)</sub> = 1 * 2<sup>6</sup> + 1 * 2<sup>5</sup> + 1 * 2<sup>4</sup> + 1 * 2<sup>3</sup> + 0 * 2<sup>2</sup> + 1 * 2<sup>1</sup> + 0 * 2<sup>0</sup><br>
1111010<sub>(2)</sub> = 64 + 32 + 16 + 8 + 0 + 2 + 0<br>
1111010<sub>(2)</sub> = 122<sub>(10)</sub>


### Konwersja z systemu szesnastkowego na dwójkowy
Konwersja pomiędzy systemami szesnastkowym i dwójkowym jest prosta w realizacji, ponieważ jednej cyfrze szesnastkowej odpowiada 4-cyftrowy zapis w systemie dwójkowym. Kolejnym cyfrom zapisu szesnastkowego odpowiadają kolejne wartości w zapisie dwójkowym:

|Zapis szesnastkowy|Zapis dwójkowy|
|-|-|
|0|0000|
|1|0001|
|2|0010|
|3|0011|
|4|0100|
|5|0101|
|6|0110|
|7|0111|
|8|1000|
|9|1001|
|A|1010|
|B|1011|
|C|1100|
|D|1101|
|E|1110|
|F|1111|

Konwertując liczbę zapisaną w systemie szesnastkowym na liczbę w systemie dwójkowym każdą wartość cyfry szesnastkowej zapisujemy w postaci czterech cyfr zapisu binarnego, np:<br>
1FA0<sub>(16)</sub> = 0001 1111 1010 0000<sub>(2)</sub>

### Konwersja z systemu dwójkowego na szesnastkowy
Niniejsza konwersja przebiega dokładnie na tej samej zasadzie co konwersja opisana powyżej, przy czym każde 4 bity (cyfry) liczby w zapisie dwójkowym odpowiadają jednej cyfrze zapisu szesnastkowego.
Przykład:<br>
1010 0000 0001 1111<sub>(2)</sub> = A01F<sub>(16)</sub><br>
ponieważ:<br>
1010<sub>(2)</sub> = A<sub>(16)</sub><br>
0000<sub>(2)</sub> = 0<sub>(16)</sub><br>
0001<sub>(2)</sub> = 1<sub>(16)</sub><br>
1111<sub>(2)</sub> = F<sub>(16)</sub><br>

Uwaga: zapis dwójkowy o długości innej niż wielokrotność 4 podczas konwersji uzupełniamy z przodu zerami, np:<br>
101111<sub>(2)</sub> = 10 1111<sub>(2)</sub> = 0010 1111<sub>(2)</sub> = 2F<sub>(16)</sub>

# 3. Formatowanie printf()/scanf()
Funkcje języka C printf() oraz scanf() używają specjalnych kodów (tagów) do wyświetlania zawartości przekazanych zmiennych lub interpretacji ciągu znaków w celu wpisania ich do zmiennej. Ogólna budowa wygląda następująco:
```%[flagi][szerokość][.precyzja][rozmiar]specyfikator_typu```

Przykłady:
```c
printf("Zmienna a = %d",a); // wypisanie wartości zmiennej "a" w postaci dziesiętnej
scanf("%d",&a);             // pobranie od użytkownika wartości w formacie dziesiętnym i wpisaniem jej do zmiennej "a"
```

Specyfikator jest wymagany. Pozostałe parametry (flagi, szerokość, precyzja, rozmiar) są opcjonalne.

Tabela kodów (specyfikatorów):

|Specyfikator|Typ argumentu|Przykład|
|-|-|-|
|%d|liczba całkowita ze znakiem (format dziesiętny)|1234|
|%i|j.w.|1234|
|%u|liczba całkolwita bez znaku (format dziesiętny)|4096|
|%o|liczba w systemie ósemkowym (oktalnym)|774|
|%x|liczba w systemie szesnastkowym (małe litery)|1ffa|
|%X|liczba w systemie szesnastkowym (duże litery)|1FFA|
|%f|liczba rzeczywista (typ: float lub double), wynik dziesiętny|12.54300|
|%e|liczba w notacji naukowej (ze znakiem e)|2.123e+2|
|%E|liczba w notacji naukowej (ze znakiem E)|2.123E+2|
|%g|liczba rzeczywista w notacji %e bądź %f. Notacja naukowa jest używana tylko wtedy gdy wykładnik jest mniejszy od -4 lub gdy wykładnik jest większy albo równy od parametru precyzja|3.12|
|%c|znak|w|
|%s|ciąg znaków zakończony znakiem \0|World|
|%p|adres w pamięci|A600:2000|

Flagi:

|flaga|opis|
|-|-|
|-|	Wyrównaj wypisywane dane do lewej. Pozycja jest ustalana na podstawie parametru szerokość oraz na podstawie długości tekstu wyjściowego. Domyślnie tekst jest wyrównywany do prawej.|
|+|	Poprzedza wynik znakiem + lub - jeżeli wartość wyjściowa jest liczbą całkowitą ze znakiem. Domyślnie tylko liczby ujemne są poprzedzone znakiem -.|
|0|	Jeżeli parametr szerokość jest poprzedzony 0, znaki 0 są wstawiane dopóki minimalna długość tekstu wyjściowego nie zostanie osiągnięta.|
|(spacja)|	Poprzedza wartość wyjściową jedną spacją jeżeli jest to liczba nieujemna. Flaga ta jest ignorowana gdy w tagu wystąpiła flaga +.|
|#|	Jeżeli flaga zostanie użyta razem ze specyfikatorami o, x, lub X to wynik, który jest niezerowy zostanie poprzedzony 0, 0x lub 0X odpowiednio do typów.<br><br>Jeżeli flaga zostanie użyta razem ze specyfikatorami e, E lub f to na wyjściu zostanie wymuszone pojawienie się separatora oddzielającego część całkowitą od ułamkowej. Domyślnie, po wartości całkowitej nie jest wypisywany separator oddzielający (domyślnie jest nim kropka).<br><br>Jeżeli flaga zostanie użyta ze specyfikatorami g lub G to na wyjściu zostanie wymuszone pojawienie się separatora oddzielającego część całkowitą od ułamkowej oraz zapobiegnie ucięciu zer końcowych.<br><br>Flaga jest ignorowana gdy zostanie użyta z następującymi specyfikatorami typów: c, d, i , u lub s. |

Szerokość:

|Szerokość|	Opis|
|-|-|
|(liczba)|	Minimalna liczba znaków do wyświetlenia. Jeżeli liczba wyświetlanych znaków jest mniejsza niż podana wartość to wynik będzie uzupełniony spacjami. Wartość nie zostanie obcięta jeżeli wynik jest dłuższy niż wartość podana.|
|*|	Szerokość nie jest określona przez tekst sformatowany. Długość tekstu określa się natomiast poprzez argument będący liczbą, który musi wystąpić bezpośrednio przed wypisywaną wartością.|

Przykład użycia *:
```c
printf( "%*g", 20, 123.0 );
//Powyższy zapis równoważny jest poniższemu:
printf( "%20g", 123.0 );
```

Precyzja:

|.precyzja|	opis|
|-|-|
|.liczba|	Dla specyfikatorów typów całkowitych tj. d, i, o, u, x oraz X precyzja określa minimalną liczbę cyfr jaka ma zostać wyświetlona. Jeżeli liczba cyfr jest mniejsza od podanej wartości to liczba zostanie uzupełniona zerami wiodącymi. Liczba nie zostanie ucięta jeżeli liczba będzie dłuższa niż podana wartość. Jeżeli długość precyzji będzie wynosiła 0 oraz wartość, która ma zostać wypisana będzie wynosiła 0 to nic nie zostanie wypisane na ekran. Jeżeli nie określono precyzji, domyślną wartością dla wymienionych powyżej typów jest 1.<br><br>Dla specyfikatorów typów e, E oraz f precyzja jest maksymalną liczbą cyfr po przecinku jaka ma zostać wypisana.<br><br>Dla specyfikatorów typów g i G precyzja oznacza maksymalną liczbę cyfr do wyświetlenia.<br><br>Dla specyfikatora s precyzja oznacza maksymalną liczbę znaków jaka może zostać wypisana z łańcucha znaków. Domyślnie wszystkie znaki z łańcucha znaków są wypisywane aż do napotkania znaku terminalnego '\0'.<br><br>Dla specyfikatora typu c precyzja nie ma żadnego efektu.|
|.*|	Precyzja nie jest określona przez tekst sformatowany. Precyzję określa się natomiast poprzez argument będący liczbą, który musi wystąpić bezpośrednio przed wypisywaną wartością.|

Rozmiar:

|Rozmiar|	opis|
|-|-|
|h|	Argument jest interpretowany jako short int lub unsigned short int (dotyczy tylko specyfikatorów liczbowych, tj. i, d, u, o, x oraz X).|
|l|	Argument jest interpretowany jako long int lub unsigned long int dla specyfikatorów określających argumenty liczbowe tj. i, d, o, u, x oraz X.<br><br>Parametr ten stosuje się również do wypisywania znaku unikodowego jak i unikodowego łańcucha znaków stosowanych odpowiednio dla specyfikatorów c i s.|
|L|	Argument jest interpretowany jako long double (dotyczy tylko specyfikatorów określających zmiennoprzecinkowe argumenty: f, e, E, g oraz G).|


# 4. Program obliczający liczbę z ciągu Fibonacciego

*Ciąg Fibonacciego* jest to ciąg liczb naturalnych, gdzie każda kolejna liczba jest sumą dwóch poprzednich.<br>
Poniżej zaprezentowany jest program który oblicza i wyświetla liczbę Fibonacciego na konkretnej pozycji (podanej przez użytkownika).
Algorytm polega wykonywaniu pętli w której wyznacza się sumę dwóch poprzednio wyznaczonych liczb (sum).
Pętla wykonuje się taką ilość razy, aby dojść do zadanej przez użytkownika pozycji w ciągu.
Ze względu na ograniczenie liczbowe zmiennej ```unsigned long``` program umożliwia obliczenie maksylanie do 92 liczby Fibonacciego.

```c
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
```

