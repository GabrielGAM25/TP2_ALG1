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

  //  making above shown graph 
  // 0 1 4
  // 0 7 8
  // 1 2 8
  // 1 7 11
  // 2 3 7
  // 2 8 2
  // 2 5 4
  // 3 4 9
  // 3 5 14
  // 4 5 10
  // 5 6 2
  // 6 7 1
  // 6 8 6
  // 7 8 7

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
    
    cout << firstPoint.getId() << " - " << secondPoint.getId() << " " << currentPath.getCost() << endl;
  }

  return 0;
}