#include <iostream>
#include <algorithm>

#include "../include/Graph.h"
#include "../include/DisjointSets.h"

Graph::Graph(vector< Point > touristicPoints) {
  this->pointsCount = touristicPoints.size();
  this->touristicPoints = touristicPoints;
  touristicPointsPaths = vector<int>(pointsCount);
  mstCost = 0;
  mstAttractiveness = 0;
}

void Graph::addBicyclePath(Point firstPoint, Point secondPoint, int cost) {
  BicyclePath newBicyclePath = BicyclePath(firstPoint, secondPoint, cost);
  bicyclePaths.push_back(newBicyclePath);
}

struct {
  bool operator()(BicyclePath firstBicyclePath, BicyclePath secondBicyclePath) const {
    int firstPathCost = firstBicyclePath.getCost();
    int secondPathCost = secondBicyclePath.getCost();
    bool isFirstCostMinor = firstPathCost < secondPathCost;
    bool areCostsEqual = firstPathCost == secondPathCost;

    int secondPathAttractiveness = secondBicyclePath.getAttractiviteness();
    int firstPathAttractiveness = firstBicyclePath.getAttractiviteness();
    bool isFirstAttractivenessGreater = firstPathAttractiveness > secondPathAttractiveness;

    return isFirstCostMinor || (areCostsEqual && isFirstAttractivenessGreater);
  }
} pathsSorter;

void Graph::calculateMinSpanningTree() {
  sort(bicyclePaths.begin(), bicyclePaths.end(), pathsSorter);

  DisjointSets disjointSets = DisjointSets(pointsCount);

  vector< BicyclePath >::iterator currentPath;
  for (currentPath = bicyclePaths.begin(); currentPath != bicyclePaths.end(); currentPath++)
  {
    Point firstPoint = currentPath->getFirstPoint();
    Point secondPoint = currentPath->getSecondPoint();

    int firstPointSet = disjointSets.find(firstPoint.getId());
    int secondPointSet = disjointSets.find(secondPoint.getId());

    if (firstPointSet != secondPointSet)
    {
      minSpanningTree.push_back(*currentPath);
      
      mstCost += currentPath->getCost();
      mstAttractiveness += currentPath->getAttractiviteness();
      
      touristicPointsPaths.at(firstPoint.getId())++;
      touristicPointsPaths.at(secondPoint.getId())++;

      disjointSets.merge(firstPointSet, secondPointSet);
    }
  }
}

vector< BicyclePath > Graph::getMinSpanningTree() {
  return minSpanningTree;
}

vector< int > Graph::getTouristicPointsPaths() {
  return touristicPointsPaths;
}

int Graph::getMstCost() {
  return mstCost;
}

int Graph::getMstAttractiveness() {
  return mstAttractiveness;
}
