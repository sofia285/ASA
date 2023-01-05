#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int start;
  int end;
  int weight;
};

// Guarda as ligações entre vértices
class UnionFind {
 public:
  vector<int> parent;
  vector<int> rank;

  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n);
    // Inicializa o vetor de pais com os próprios vértices
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0; 
    }
  }

  // Encontra a raiz do vértice x
  int find(int x) {
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
      if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
      } else if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
      } else {  // rank[root_x] == rank[root_y]
        parent[root_y] = root_x;
        rank[root_x]++;
      }
    }
  }
};

int main() {
  int V, E, u, v, w;
  // cin >> V >> E; 
  scanf("%d %d", &V, &E); 

  vector<Edge> edges;  // Vector to store the edges of the graph

  // Read the edges from the input
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    Edge e;
    e.start = u;
    e.end = v;
    e.weight = w;
    edges.push_back(e);
  }

  // Sort the edges in decreasing order of weight
  sort(edges.begin(), edges.end(),
      [](const Edge &a, const Edge &b) { return a.weight > b.weight; });


  UnionFind uf(V);

  int sol = 0;
  for (const Edge &e : edges) {
    // If adding the edge would create a cycle in the minimum spanning tree, discard the edge
    if (uf.find(e.start) != uf.find(e.end)) {
      
      sol += e.weight;
      // Merge the connected components of the start and end vertices
      uf.unite(e.start, e.end);

    }  
  }

  printf("%d\n", sol);

  return 0;
}
