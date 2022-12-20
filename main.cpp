#include <iostream>
#include <stdlib.h>
#include <time.h>


// funkcja tworzaca macierze
int **tworzyM(int wiersz, int kolumna) {
    int **Macierz = (int **) malloc(wiersz * sizeof(int));
    for (int i = 0; i < kolumna; ++i) {
        Macierz[i] = (int *) malloc(kolumna * sizeof(int));

    }
    return Macierz;
}
// generator liczb wpisanych do macierzy
void wpiszLiczby(int wiersz, int kolumna, int **Macierz) {
    srand(time(NULL));
    for (int i = 0; i < wiersz; i++) {
        for (int j = 0; j < kolumna; j++) {
            Macierz[i][j] = rand() % 20;
        }
    }
}


// funkcja do mnozenia elmentow odwolujaca sie do fun tworzenia.

int **mnozenie(int wierszA, int kolumnaA, int kolumnaB, int **macierzA, int **macierzB) {
    int **C = tworzyM(wierszA, kolumnaB); // macierz wynikow

    for (int i = 0; i < wierszA; ++i) {
        for (int j = 0; j < kolumnaB; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < kolumnaA; ++k) {
                C[i][j] += macierzA[i][k] * macierzB[k][j];
            }
        }
    }
    return C;
}

void wyswietl_macierz(int wiersz, int kolumna, int **Macierz) {
    int i, j;
    for (i = 0; i < wiersz; i++) {
        for (j = 0; j < kolumna; j++)
            printf("%d ", Macierz[i][j]);
        printf("\n");
    }
}

void Wolnapamiec(int wiersz, int **Macierz) {
    for (int i = 0; i < wiersz; i++) {
        free(Macierz[i]);
    }
    free(Macierz);
}


int main() {

    //Krok 1z8 Podanie wymiarow macierzy przez uzyt
    int wA, wB, kA, kB;
    printf("podaj wymiar macierzy A (wiersz kolumna)");
    scanf_s("%d %d", &wA, &kA);
    printf("podaj wymiar macierzy B (wiersz kolumna)");
    scanf_s("%d %d", &wB, &kB);
    //Krok 2z8 Sprawdznie czy mozna wykonac mnozenie
    if (kA != wB) {
        printf("Nie mozna wykonac mnozenia macierzy.\n");
        return 0;
    }
    // Krok 3z8 Wywolanie funkcji ktora tworzy macierze
    int **A = tworzyM(wA, kA);
    int **B = tworzyM(wB, kB);

    // Krok 4z8 Wywolanie funkcji ktora wpisze do macierzy wylosowanie liczby

    wpiszLiczby(wA, kA, A);
    wpiszLiczby(wB, kB, B);


    // Krok 5z8 Wywolanie funkcji ktora wypisze macirze A i B
    printf("Pierwsza macierz A:\n");
    wyswietl_macierz(wA, kA, A);

    printf("Druga macierz B:\n");
    wyswietl_macierz(wB, kB, B);

    // Krok 6z8 Wywolanie funkcji ktora pomnozy elementy macierzy(przy okazji tworzac macierz C)

    int **C = mnozenie(wA, kA, kB, A, B);


    //Krok 7z8 Wypisanie macierzy C
    printf("Wynik AxB: \n");
    wyswietl_macierz(wA, kB, C);



    // krok 8z8 wywolanie funkcji od zwolnienia pamieci
    Wolnapamiec(wA, A);
    Wolnapamiec(wB, B);
    Wolnapamiec(wA, C);
}

