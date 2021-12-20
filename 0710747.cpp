#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

struct vertex
{
	int x, y;
};

int flag;
int mst_wt = 0;
vector<iPair> ans;
  
struct Graph
{
    	int V, E;
    	vector< pair<int, iPair> > edges;
	vector< pair<int, iPair> > edges_2;
  
    	Graph(int V, int E) {
        	this->V = V;
        	this->E = E;
    	}
  
    	void addEdge(int u, int v, int w) {
		if (flag == 0) {
        		edges.push_back({w, {u, v}});
		} else {
        		edges_2.push_back({w, {u, v}});	
		}
    	}
  
    	void kruskalMST();
};
  
struct DisjointSets
{
    	int *parent, *rnk;
    	int n;
  
    	DisjointSets(int n) {
        	this->n = n;
        	parent = new int[n+1];
        	rnk = new int[n+1];
  
        	for (int i = 0; i <= n; i++) {
            		rnk[i] = 0;
  
            		parent[i] = i;
        	}
    	}
  
    	int find(int u) {
        	if (u != parent[u]) {
            		parent[u] = find(parent[u]);
		}
        	return parent[u];
    	}
  
    	void merge(int x, int y) {
        	x = find(x), y = find(y);
  
        	if (rnk[x] > rnk[y]) {
            		parent[y] = x;
        	} else {
            		parent[x] = y;
		}
  
        	if (rnk[x] == rnk[y]) {
            		rnk[y]++;
		}
    	}
};
  
void Graph::kruskalMST()
{
    	sort(edges_2.begin(), edges_2.end());
  	edges.insert(edges.end(), edges_2.begin(), edges_2.end());
    	
	DisjointSets ds(V);
  
    	vector< pair<int, iPair> >::iterator it;
    	for (it=edges.begin(); it!=edges.end(); it++) {
        	int u = it->second.first;
        	int v = it->second.second;
  
        	int set_u = ds.find(u);
        	int set_v = ds.find(v);
  
        	if (set_u != set_v) {
  			ans.push_back({u, v});
            		mst_wt += it->first;
            		ds.merge(set_u, set_v);
        	}
	}
}

int main(int argc, char *argv[])
{
	vector<string> res;
	string result;
        string text;
	
	int n, V, E, count = 0;
	vector<vertex> Vertex;
	vector<iPair> Edge;
	vertex temp;

        ifstream MyReadFile(argv[1]);
        ofstream MyFile(argv[2]);

        while (getline(MyReadFile, text)) {
                res.clear();
                stringstream input(text);
                while (input >> result) {
                        res.push_back(result);
                }
		
		if (res.size() == 1) {
			n = stoi(res[0]);
			V = n;
			continue;
		}
		if (n > 0) {
			temp.x = stoi(res[0]);
			temp.y = stoi(res[1]);
			Vertex.push_back(temp);
		}
		n--;
		if (n < 0) {
			count++;
			Edge.push_back({stoi(res[0]), stoi(res[1])});
		}	
	}

	E = V * (V - 1) / 2;
	Graph g(V, E);
	iPair temp2;
	int weight, a, b, error = 0;
	
	flag = 0;
	for (int i = 0; i < count; i++) {
		a = Edge[i].first;
		b = Edge[i].second;
		weight = abs(Vertex[a].x - Vertex[b].x) + abs(Vertex[a].y - Vertex[b].y);
		error += weight;
		g.addEdge(a, b, weight);			
	}
	
	flag = 1;
	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			temp2.first = i;
			temp2.second = j;
			if (find(Edge.begin(), Edge.end(), temp2) == Edge.end()) {
				weight = abs(Vertex[i].x - Vertex[j].x) + abs(Vertex[i].y - Vertex[j].y);
				g.addEdge(i, j, weight);
			}
		}
	}
	
	g.kruskalMST();
	
	MyFile << mst_wt - error << endl;
	
	ans.erase(ans.begin(), ans.begin() + count);
	for (int i = 0; i < ans.size(); i++) {
		MyFile << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
