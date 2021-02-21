#include "../include/DisjointSets.h"

DisjointSets::DisjointSets(int pointsCount) {
  for (int i = 0; i <= pointsCount; i++)
  {
    ranks.push_back(0);
    parents.push_back(i);
  }
}

int DisjointSets::findSet(int point) {
  if (point != parents.at(point))
    parents.at(point) = findSet(parents.at(point));
  return parents.at(point);
}

void DisjointSets::mergeSets(int firstPoint, int secondPoint) {
  int firstPointParent = findSet(firstPoint);
  int secondPointParent = findSet(secondPoint);

  if (ranks[firstPointParent] > ranks[secondPointParent]) {
    parents[secondPointParent] = firstPointParent;
  } else {
    parents[firstPointParent] = secondPointParent;
  }

  if (ranks[firstPointParent] == ranks[secondPointParent]) {
    ranks[secondPointParent]++;
  }
}