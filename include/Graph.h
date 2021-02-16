#ifndef Graph_H
#define Graph_H

#include<vector>

using namespace std;

// TODO: add a class for this pair
typedef  pair<int, int> iPair;

class Graph {
private:
  int pointsCount;
  vector< pair<int, iPair> > edges;

public:
  Graph(int pointsCount);
  void addEdge(int u, int v, int w);
  int kruskalMST();
};

#endif
