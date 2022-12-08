#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int combinations = 0;

bool isComplete(vector<vector<int>> aux, int n, int m) {
    int i, j;
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < m; j++) {
            if (aux.at(i).at(j) > 1) {
                return false;
            }
        }
    }
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


void getCombinations(vector<vector<int>> tiles, vector<vector<int>> aux, int n, int m, int id) {

    int k, i, j ;

    cout << "\n" << "aux" << endl;
    for(i = 0; i < n; i++) {    
        for (j = 0; j < m; j++) {
            cout << aux.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    if (isComplete(aux, n, m)) {
        combinations++;
    }

    else {
        for (i = n - 1; i >= 0; i--) {
            for (j = 0; j < m; j++) {
                if(aux.at(i).at(j) > 1) {
                    for (k = aux.at(i).at(j); k > 0; k--) {
                        vector<vector<int>> aux2 = negatives(aux, i, j, k, id);
                        getCombinations(tiles, aux2, n, m, id - 1);
                    }
                }
            }
        }
    }

}

int main () {

    int n, j, i, m, aux, count_0 = 0, diff = 0;

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
        if (aux == 0){
            tiles.at(i).at(aux) = 0;
        }
    }

    // Descobre quantos quadrados de n x n cabe em cada ponto da matriz
    for (i = 1; i < n; i++) {
        for (j = m - 2; j >= 0; j--) {
            if (tiles.at(i).at(j) != 0) {
                tiles.at(i).at(j) = tiles.at(i - 1).at(j + 1) + 1;
            }
        }
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < m; j++) {
            if (tiles.at(i).at(j) > 1) {
                diff++;
                getCombinations(tiles, tiles, n, m, -1);
            }

            else if (tiles.at(i).at(j) == 0) {
                count_0++;
            }
        }
    }

    if (count_0 == n * m) {
        combinations = 0;
    }

    else if (diff == 0) {
        combinations++;
    }

    // print da matriz
    cout << "tiles" << endl; 
    for(i = 0; i < n; i++) {    
        for (j = 0; j < m; j++) {
            cout << tiles.at(i).at(j) << " ";
        }
        cout << endl;
    }

    cout << "\n" << "combinations: " << combinations << endl;

  return 0;
}