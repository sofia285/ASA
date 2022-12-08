#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main () {

    int n, j, i, m, aux;

    cin >> n;
    cin >> m;
    vector<vector<int>> tiles = vector<vector<int>>(n, vector<int>(m, 0));

    // colocação dos 1 na matriz
    for(i = 0; i < n; i++) {
        cin >> aux;
        if (aux > 0) {
            for(j = aux - 1; j >= 0; j--) {
                tiles.at(i).at(j) = 1;
            }
        }
        if (aux == 0)
            tiles.at(i).at(aux) = 0;
    }

    // Descobre quantos quadrados de n x n cabe em cada ponto da matriz
    for (i = 1; i < n; i++) {
        for (j = m - 2; j >= 0; j--) {
            if (tiles.at(i).at(j) != 0) {
                tiles.at(i).at(j) = tiles.at(i - 1).at(j + 1) + 1;
            }
        }
    }

    
    


    // print da matriz com 0 e 1
    for(i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << tiles.at(i).at(j) << " ";
        }
        cout << endl;
    }

  return 0;
}