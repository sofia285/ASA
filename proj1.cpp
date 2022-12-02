#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {

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