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
class Union {
 public:
  vector<int> parent;

  Union(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

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
      parent[root_x] = root_y;
    }
  }
};

int main() {
  int V, E, u, v, w;
  cin >> V >> E;  

  vector<Edge> edges;  // Vector to store the edges of the graph

  // Read the edges from the input
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    Edge e;
    e.start = u;
    e.end = v;
    e.weight = w;
    edges.push_back(e);
  }

  // Sort the edges by weight
  sort(edges.begin(), edges.end(),
       [](const Edge &a, const Edge &b) { return a.weight > b.weight; });


  Union uf(V);

  int sol = 0;

  for (const Edge &e : edges) {
    // If adding the edge would create a cycle in the minimum spanning tree, discard the edge
    if (uf.find(e.start) != uf.find(e.end)) {
      
      sol += e.weight;
      // Merge the connected components of the start and end vertices
      uf.unite(e.start, e.end);

      if (uf.parent.size() == 1) {
        break;
      }
    }  
  }

  cout << sol << endl;

  return 0;
}
