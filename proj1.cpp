#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int combinations = 0;

bool isComplete(vector<vector<int>> aux, int n, int m) {
    int i, j;
    cout << "isComplete: ";
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < m; j++) {
            if (aux.at(i).at(j) > 1) {
                cout << "false" << endl;
                return false;
            }
        }
    }
    cout << "true" << endl;
    return true;

}

vector<vector<int>> negatives(vector<vector<int>> aux , int aux_i, int aux_j, int k, int id) {
    int i, j;
    for (i = aux_i; i > aux_i - k; i--) {
        for (j = aux_j; j < aux_j + k; j++) {
            aux.at(i).at(j) = id;
        }
    }

    return aux;
}


void getCombinations(vector<vector<int>> tiles, int n, int m, int id) {

    int k, i, j;

    for(i = 0; i < n; i++) {    
        for (j = 0; j < m; j++) {
            cout << tiles.at(i).at(j) << " ";
        }
        cout << endl;
    }

    if (isComplete(tiles, n, m)) {
        combinations++;
        cout << "increase combinations: " << combinations << endl;
    }

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < m; j++) {
            if(tiles.at(i).at(j) > 1) {
                for (k = tiles.at(i).at(j); k > 0; k--) {
                    cout << "k: " << k << endl;
                    vector<vector<int>> aux = negatives(tiles, i, j, k, id);
                    getCombinations(aux, n, m, id - 1);
                }
            }
        }
    }
}

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

    getCombinations(tiles, n, m, -1);

    // print da matriz
    for(i = 0; i < n; i++) {    
        for (j = 0; j < m; j++) {
            cout << tiles.at(i).at(j) << " ";
        }
        cout << endl;
    }

    cout << combinations << endl;

  return 0;
}