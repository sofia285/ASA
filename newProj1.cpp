#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int combinations = 0;

void printMatrix(vector<vector<int>> tiles, int n, int m) {
    int i, j;
    cout << "tiles" << endl;
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cout << tiles.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> negatives(vector<vector<int>> aux , int aux_i, int aux_j, int k, int id) {
    int i, j, l, n;
    for (i = aux_i; i > aux_i - k; i--) {
        for (j = aux_j; j < aux_j + k; j++) {
            aux.at(i).at(j) = id;
            if(j > 0 && aux.at(i).at(j - 1) > 1) {
                n = 1;
                for (l = j - 1; l >= 0; l--) {
                    if (aux.at(i).at(l) > n) {
                        aux.at(i).at(l) = n;
                    }
                    n++;
                }
            }
        }
    }

    return aux;
}


void getCombinations(vector<vector<int>> aux, int n, int m, int id) {

    int k, i, j;
    
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < m; j++) {
            if(aux.at(i).at(j) > 1) {
                for (k = aux.at(i).at(j); k > 0; k--) {
                    vector<vector<int>> aux2 = negatives(aux, i, j, k, id);
                    getCombinations(aux2, n, m, id - 1);
                }
                return;
            }
        }
    }
    combinations++;
}

int main () {

    int n, j, i, m, aux, count_0 = 0;

    cin >> n;
    cin >> m;
    vector<vector<int>> tiles = vector<vector<int>>(n, vector<int>(m, 0));

    // colocação dos 1 na matriz e descobre quantos quadrados cabem
    for(i = 0; i < n; i++) {
        cin >> aux;
        if (aux > 0) {
            for(j = aux - 1; j >= 0; j--) {
                if (i > 0 && j < m - 1) {
                    tiles.at(i).at(j) = tiles.at(i - 1).at(j + 1) + 1;
                }
                else {
                    tiles.at(i).at(j) = 1;
                }
            }
        }
        if (aux == 0){
            tiles.at(i).at(aux) = 0;
            count_0++;
        }
    }
    if (count_0 == n) {
        cout << 0 <<endl;
        return 0;
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < m; j++) {
            if (tiles.at(i).at(j) > 1) {
                getCombinations(tiles, n, m, -1);
                cout << combinations << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;

  return 0;
}