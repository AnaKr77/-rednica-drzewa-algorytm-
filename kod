#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 100;


vector<int> graf[MAX_N];

int odleglosci[MAX_N];
bool odwiedzony[MAX_N];

int maksymalna_odleglosc = 0;
int najdalszy_wierzcholek = 0;

// Funkcja do obliczania najdalszego wierzchołka i jego odległości
int oblicz_srednice(int start) {
    // Zerowanie odwiedzin i odległości
    memset(odwiedzony, 0, sizeof(odwiedzony));
    memset(odleglosci, 0, sizeof(odleglosci));
    
    // Przeszukiwanie w głąb
    queue<int> kolejka;
    kolejka.push(start);
    odwiedzony[start] = true;

    while (!kolejka.empty()) {
        int wierzcholek = kolejka.front();
        kolejka.pop();

        for (int sasiad : graf[wierzcholek]) {
            if (!odwiedzony[sasiad]) {
                odwiedzony[sasiad] = true;
                odleglosci[sasiad] = odleglosci[wierzcholek] + 1;
                kolejka.push(sasiad);

                // Aktualizowanie maksymalnej odległości
                if (odleglosci[sasiad] > maksymalna_odleglosc) {
                    maksymalna_odleglosc = odleglosci[sasiad];
                    najdalszy_wierzcholek = sasiad;
                }
            }
        }
    }

    return maksymalna_odleglosc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; // liczba wierzchołków
    cout << "Podaj liczbę wierzchołków: ";
    cin >> n;

    cout << "Podaj " << n - 1 << " par krawędzi (u v):" << endl;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u);
    }

    // Znalezienie kandydata na średnicę (pierwszy najdalszy wierzchołek)
    oblicz_srednice(1);
    int kandydat = najdalszy_wierzcholek;

    // Ponowne uruchomienie BFS, by obliczyć średnicę drzewa
    maksymalna_odleglosc = 0; // Zerujemy maksymalną odległość
    int srednica_drzewa = oblicz_srednice(kandydat);

    cout << "Średnica drzewa wynosi: " << srednica_drzewa+1 << endl;

    return 0;
}
