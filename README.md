# Prosty obiektowo‑zorientowany symulator świata (simpleObjectOrientedGame)

## Opis projektu
Konsolowa symulacja świata z organizmami (zwierzęta i rośliny), napisana w C++ w stylu obiektowym. Gracz steruje człowiekiem, stara się przeżyć i rozwijać swoje statystyki (jeżeli to możliwe). Gra posiada opcję zapisu aktualnego stanu do pliku `logi.txt` oraz na koniec tury pojawiają się infomacje o akcjach wykonanych przez organizmy. Projekt stworzony na rzecz przedmiotu Programowanie Obiektowe. Projekt posiadał z góry ustalone zasady działania symulacji i wymagań. 

## Sterowanie
- **Ruch gracza (Człowiek):** `w` = góra, `s` = dół, `a` = lewo, `d` = prawo.
- **Umiejętność specjalna (Człowiek):** `spacja` — pali wszystkie sąsiednie organizmy; czas odnowienia: 5 tur.
- **Zapis gry:** `z` - zapisanie aktualnego stanu planszy, `x` wczytanie stanu planszy z pliku `logi.txt` 

## Mechanika ogólna
- **Organizmy:** Dzielą się na `Zwierze` i `Roslina` (klasa nadrzędna: `Organizm`).
- **Tury:** Każdy organizm wykonuje `akcja()`; zwierzęta poruszają się i mogą wchodzić w kolizje; rośliny mają szansę rozprzestrzenienia.
- **Kolizje:** Kiedy dwa organizmy spotkają się na tym samym polu, wywoływana jest metoda `kolizja(Organizm* atakujacy)` i rozstrzygane są skutki (zabicie, zatrucie, ucieczka, rozmnażanie).
- **Rozmnażanie zwierząt:** Dwa osobniki tego samego gatunku rozmnażają się, jeśli osiągnęły odpowiedni wiek.
- **Rozmnażanie roślin:** Rośliny mają stałą szansę reprodukcji (szansa 5% w jednej turze); niektóre rośliny mają specjalne reguły reprodukcji np. `Mlecz`.

## Lista organizmów i ich funkcjonalności
- **Człowiek (`C`)**: organizm gracza; umiejętność specjalna - pali wszystkie sąsiednie organizmy (czas odnowienia 5 tur).
- **Wilk (`W`)**: silny drapieżnik (wysoka siła i inicjatywa), podstawowe zachowania: poruszanie się, walka i rozmnażanie.
- **Lis (`L`)**: podczas wyboru ruchu unika pól zajętych przez silniejsze organizmy; jeśli nie ma zagrożenia, zachowuje standardowe ruchy.
- **Owca (`O`)**: standardowe zwierzę o zrównoważonej sile i inicjatywie; porusza się, walczy i rozmnaża.
- **Antylopa (`A`)**: posiada zwiększony zares ruchu o jedno dodatkowe pole; podczas kolizji ma szansę uniknąć wali i uciec.
- **Żółw (`Z`)**: wykonuje ruch tylko z prawdopodobieństwem 1/4; odbija atakujące organizmy o sile mniejszej niż 5, inaczej normalna walka.
- **Mlecz (`m`)**: roślina szybko się rozprzestrzeniająca - w jednej turze próbuje rozprzestrzenić się wielokrotnie, przy czym ma mechanizm obniżania wieku, by zbalansować ekspansję.
- **Trawa (`t`)**: podstawowa roślina, standardowe zachowanie rośliny.
- **Guarana (`g`)**: przy kolizji wzmacnia atakującego - zwiększa siłę atakującego o 3, a następnie jest zjadana.
- **Wilcze jagody (`j`)**: przy kolizji zarówno atakujący, jak i roślina giną.
- **Barszcz Sosnowskiego (`b`)**: podczas swojej akcji zabija wszystkie sąsiednie zwierzęta; przy kolizji zabija również atakującego i siebie.

## Uwagi implementacyjne
- Symbolika: wielkie litery (`A`..`Z`) reprezentują zwierzęta, małe (`a`..`z`) rośliny.
- Szanse na poszczególne akcje i stałe są zdefiniowane w plikach źródłowych poszczególnych klas.
- Ilość generowanych organizmów jest możliwa do edycji w pliku `Swiat.cpp`