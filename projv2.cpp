#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {

    int n, m, aux;

    cin >> n;
    cin >> m;

    int tiles[n][m];

    // inicializa vetor
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            tiles[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> aux;
        if (aux > 0){
            for(int j = aux - 1; j >= 0; j--)
                tiles[i][j] = 1;
        if (aux == 0)
            tiles[i][aux] = 0;
        }
    }


    for(int  i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cout << tiles[i][j] << " ";
        }
        cout << endl;
    }
}
