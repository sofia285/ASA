#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {

    int n, j, i, m, aux;
    vector<vector<int>> tiles = {};

    cin >> n;
    cin >> m;

    for(i = 0; i < n; ++i) {
        vector<int> vec = {};
        for(j = 0; j < m; j++) {
            vec.push_back(0);
        }
        tiles.push_back(vec);
    }

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

    for(i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << tiles[i][j] << " ";
        }
        cout << endl;
    }
    /*
    int n, m, i, j, aux, zeros = 0;

    cin >> n;
    cin >> m;

    int tiles[n][m] = {{0}};

    for (i = 1; i <= n; i++){
        for(j = 1; j <= m; j++) {
            tiles[i][j] = 0;
        }
    }


    // mete a um os pontos recebidos
    for (i = 1; i <= n; i++) {
        cin >> aux;
        if (aux > 0) {
            tiles[i][aux] = 1;
        }
        if (aux == 0) {
            zeros++;
        }
        
    }

    // preenche a area toda a ser ladrilhada
    for (i = zeros + 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (tiles[i][j] == 1) {
                break;
            }

            else {
                tiles[i][j] = 1;
            }
        }
    }

  return 0;
}