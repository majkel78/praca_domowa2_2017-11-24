# 1. Liczbowe typy danych (binarny, ósemkowy, szesnastkowy)

Najpopularniejszym używanym systemem liczbowym jest system dziesiętny. Jest to system pozycyjny o podstawie 10. Konstrukcje liczące (komputery) zapisują informacje w pamięci w postaci bitów. Interpretacja tych informacji notowana jest za pomocą cyfr 0 oraz 1 i jest nazywana zapisem (systemem) binarnym lub dwójkowym. W systemie pozycyjnym używa się też innych systemów, z czego oprócz napopularniejszego dziesiętnego także szesnastkowego i ósemkowego.

### Typ binarny (dwójkowy)
Pozycyjny system liczbowy o podstawie 2. Podstawę jego stanowi liczba 2, wszystkie więc liczby można zapisać dwiema tylko cyframi: 0 i 1. Liczby naturalne w systemie dwójkowym zapisujemy tak samo jak w systemie dziesiętnym - zamiast kolejnych potęg liczby dziesięć, stosujemy kolejne potęgi liczby dwa.

Przykład zapisania liczby dziesiętej 9 w systemie dwójkowym:
$$1001_{2}=1*2^3+0*2^2+0*2^1+1*2^0=8+1=9_{10}$$

Na potrzeby systemów informatycznych opracowano w systemie dwójkowym sposób reprezentacji liczb ujemnych:
- kod znak-moduł
- kod uzupełnienie do jedności (U1)
- kod uzupelnienie do dwóch (U2) - najczęściej używany

### Typ ósemkowy (oktalny)
Pozycyjny system liczbowy o podstawie 8. Podstawa wynosi 8 więc wszystkie liczby zapisuje się cyframi od 0 do 7. Nazywany jest też systemem "oktalnym" (od słowa octal).

Przykład zapisania liczby dziesiętnej 99 w systemie ósemkowym:
$$143_{8}=1*8^2+4*8^1+3*8^0=64+32+3=99_{10}$$

W językach programowania do zapisu liczby w formacie oktalnym (jeżeli język przewiduje wprowadzanie liczb w takim formacie) stosuje się przerostek 0 np. 0143 to zapis ósemkowy liczby dziesiętnej 99. Przykładem wykorzystującym zapis ósemkowy jest polecenie `chmod` (w systemach linux) którym zmienia się uprawnienia do plików (aby ustawić uprawnienia na `rwx r-x r--` stosuje się polecenie `chmod 754 plik`).

### Typ szesnastkowy (heksadecymalny)
Pozycyjny system liczbowy o podstawie 16. Cyfry w tym systemie zapisuje się za pomocą znaków: 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F. Cyfry od 0 do 9 mają te same wartości co w systemie dziesiętnym natomiast A,B,C,D,E,F odpowiadają kolejno wartościom 10,11,12,13,14,15.

Przykład zapisania liczby dziesiętnej 999 w systemie szesnastkowym:
$$3E7_{16}=3*16^2+14*16^1+7=768+224+7=999_{10}$$

W językach programowania bardzo często używa się zapisu szesnastkowego. Najczęstsze sposoby zapisu to:
- w językach C,C++,C#, Java, Python: prefiks 0x (np. `0x3E7`)
- w języku Pascal prefix $ (np. `$3E7`)
- w asemblerze spotyka się formę za pomocą sufiksa h (np. `3E7h`)
- w HTML/CSS używa się prefiksa # (przykład to wartość koloru - `#FF99A0`)

W systemach informatycznych system szesnastkowy stosuje się między innymi do zapisu koloru (`0xFF0000` oznacza czerwony), adresu sprzętowego MAC (`00:0B:E3:2F:FA:D1`) czy też adresu IPv6 (`2001:db8:85a3:8d3:1319:8a2e:370:7348`).

# 2. Konwersja między systemami 10-2 oraz 16-2.
### Konwersja z systemu dziesiętnego na dwójkowy
Do manualnej konwersji liczby dziesiętnej na dwójkową stosujemy niniejszy sposób:
- liczbę dziesiętną dzielimy na 2
- zapisujemy wynik poniżej a obok resztę z dzielenia
- dzielenie (za każdym razem przez 2) wykonujemy aż osiągniemy w wyniku dzielenia 0

Przykład:
| 122 | 2 | 0 |
|:---:|:-:|:-:|
| 61  | 2 | 1 |

| 122 | 2 | 0 |
| 61  | 2 | 1 |

| 122 | 2 | 0 |
|-----|---|---|
| 61  | 2 | 1 |

|-----|---|---|
| 122 | 2 | 0 |
| 61  | 2 | 1 |

|     |   |   |
|-----|---|---|
| 122 | 2 | 0 |
| 61  | 2 | 1 |

|     |   |   |
|-----|---|---|
| 122 | 2 | 0 |
| 61  | 2 | 1 |
|     |   |   |
