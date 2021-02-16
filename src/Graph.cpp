#include <iostream>
#include <algorithm>

#include "../include/Graph.h"
#include "../include/DisjointSets.h"

Graph::Graph(int pointsCount) {
  this->pointsCount = pointsCount;
}

void Graph::addEdge(int firstPoint, int secondPoint, int cost){
  edges.push_back({ cost, {firstPoint, secondPoint} });
}

int Graph::kruskalMST(){
  int mst_wt = 0;

  sort(edges.begin(), edges.end());

  DisjointSets ds = DisjointSets(pointsCount);

  vector< pair<int, iPair> >::iterator it;
  for (it = edges.begin(); it != edges.end(); it++)
  {
    int firstPoint = it->second.first;
    int secondPoint = it->second.second;

    int firstPointSet = ds.find(firstPoint);
    int secondPointSet = ds.find(secondPoint);

    if (firstPointSet != secondPointSet)
    {
      cout << firstPoint << " - " << secondPoint << endl;
      mst_wt += it->first;
      ds.merge(firstPointSet, secondPointSet);
    }
  }

  return mst_wt;
}
