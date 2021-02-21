#include <iostream>
#include "./Graph.h"

using namespace std;

int main() {
  int pointsCount;
  int routesCount;

  cin >> pointsCount >> routesCount;

  vector <Point> touristicPoints;

  for(int i = 0; i < pointsCount; i++) {
    int touristicValue;
    
    cin >> touristicValue;

    touristicPoints.push_back(Point(i, touristicValue));
  }

  Graph graph = Graph(touristicPoints);

  for (int i = 0; i < routesCount; i++) {
    int firstPoint;
    int secondPoint;
    int cost;

    cin >> firstPoint >> secondPoint >> cost;

    graph.addBicyclePath(touristicPoints[firstPoint], touristicPoints[secondPoint], cost);
  }

  graph.calculateMinSpanningTree();

  int mstCost = graph.getMstCost();
  int mstAttractiveness = graph.getMstAttractiveness();

  cout << mstCost << " " << mstAttractiveness << endl;

  vector<int> touristicPointsPaths = graph.getTouristicPointsPaths();

  cout << touristicPointsPaths.at(0);
  for(int i = 1; i < pointsCount; i++) {
    cout << " " << touristicPointsPaths.at(i);
  }

  cout << endl;
  
  vector<BicyclePath> minSpanningTree = graph.getMinSpanningTree();

  for(auto& currentPath : minSpanningTree) {
    Point firstPoint = currentPath.getFirstPoint();
    Point secondPoint = currentPath.getSecondPoint();
    
    cout << firstPoint.getId() << " " << secondPoint.getId() << " " << currentPath.getCost() << endl;
  }

  return 0;
}