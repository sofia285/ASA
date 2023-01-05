#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int start;
  int end;
  int weight;
};

struct DisjointSets{
	int *parent, *rank;
	int n;

	DisjointSets(int n)	{
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];

		for (int i = 0; i <= n; i++){
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int find(int x){
		if (x != parent[x]){
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unite(int x, int y){
		int root_x = find(x);
		int root_y = find(y);
		if (root_x != root_y){
			if (rank[root_x] > rank[root_y]){
				parent[root_y] = root_x;
			} else{
				parent[root_x] = root_y;
				if (rank[root_x] == rank[root_y]){
					rank[root_y]++;
				}
			}
		}
	}
};

struct Graph{
	int V, E;
	vector<Edge> edges;

	Graph(int V, int E)	{
		this->V = V;
		this->E = E;
	}

	void addEdge(int u, int v, int w){	
		Edge e;
    	e.start = u;
    	e.end = v;
    	e.weight = w;
    	edges.push_back(e);
	}

	int kruskal(){
		int sol = 0;
	
		sort(edges.begin(), edges.end(),
      		[](const Edge &a, const Edge &b) { return a.weight > b.weight; });
	
		DisjointSets ds(V);

		for (Edge &e : edges){
			int u = e.start;
			int v = e.end;
		
			int set_u = ds.find(u);
			int set_v = ds.find(v);

			if (set_u != set_v){
				sol += e.weight;
				ds.unite(set_u, set_v);
			}
		}
		return sol;
	}
};

int main(){
	int V, E, u, v, w;

	scanf("%d", &V);
	scanf("%d", &E);
	Graph g(V, E);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		g.addEdge(u, v, w);
	}

	int s = g.kruskal(); 

  	printf("%d\n", s);

	return 0;
}