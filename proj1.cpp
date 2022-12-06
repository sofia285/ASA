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
    /*
    for(i = 0; i < n; ++i) {
        vector<int> vec = {};
        for(j = 0; j < m; j++) {
            vec.push_back(0);
        }
        tiles.push_back(vec);
    }*/

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

  return 0;
}