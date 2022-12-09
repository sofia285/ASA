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

void getCombinations(vector<vector<int>>* aux_super, int n_0, int n, int m, int id) {

    int k, i, j, aux_i, aux_j, s, l;
    
    for (i = n - 1; i >= n_0; i--) {
        for (j = 0; j < m; j++) {
            if((*aux_super).at(i).at(j) > 1) {
                for (k = (*aux_super).at(i).at(j); k > 0; k--) {
                    vector<vector<int>> aux2 = (*aux_super);
                    for (aux_i = i; aux_i > i - k; aux_i--) {
                        for (aux_j = j; aux_j < j + k; aux_j++) {
                            aux2.at(aux_i).at(aux_j) = id;
                            if(aux_j > 0 && aux2.at(aux_i).at(aux_j - 1) > 1) {
                                s = 1;
                                for (l = aux_j - 1; l >= 0; l--) {
                                    if (aux2.at(aux_i).at(l) > s) {
                                        aux2.at(aux_i).at(l) = s;
                                    }
                                    s++;
                                }
                            }
                        }
                    }
                    getCombinations(&aux2,n_0, n, m, id - 1);
                }
                return;
            }
        }
    }
    combinations++;
}

int main () {

    int n, j, i, m, aux, newN, count_0 = 0, n_max = 0, m_max = 0;

    cin >> n;
    cin >> m;
    vector<vector<int>> tiles = vector<vector<int>>(n, vector<int>(m, 0));

    // colocação dos 1 na matriz e descobre quantos quadrados cabem
    for(i = 0; i < n; i++) {
        cin >> aux;

        if (aux > m_max) {
            m_max = aux;
        }

        if (aux > 1) {
            n_max++;
        }
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
            count_0++;
        }
    }

    if (count_0 == n) {
        cout << 0 <<endl;
        return 0;
    }

    if (tiles.at(n - 1).at(0) > 1) {
        newN = n - n_max;
        getCombinations(&tiles, newN, n, m_max, -1);
        cout << combinations << endl;
        return 0;
    }

    cout << 1 << endl;

  return 0;
}