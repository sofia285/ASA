#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void printList(int E, vector<vector<int>> list) {

    for (int i = 1; i <= E; i++) {
        for (int j = 1; j <= E; j++) {
            cout << list.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E, i, W, u, v;

    cin >> V;
    cin >> E;
    vector<vector<int>> tiles = vector<vector<int>>(E + 1, vector<int>(E + 1, 0));
    for (i = 0; i < E; i++) {
        cin >> u;
        cin >> v;
        cin >> W;
        tiles.at(u).at(v) = W;
    }

    printList(E, tiles);

    return 0;
}