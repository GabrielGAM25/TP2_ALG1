#include "../include/DisjointSets.h"

DisjointSets::DisjointSets(int pointsCount) {
  for (int i = 0; i <= pointsCount; i++)
  {
    ranks.push_back(0);
    parents.push_back(i);
  }
}

int DisjointSets::find(int point) {
  if (point != parents.at(point))
    parents.at(point) = find(parents.at(point));
  return parents.at(point);
}

void DisjointSets::merge(int firstPoint, int secondPoint) {
  int firstPointParent = find(firstPoint);
  int secondPointParent = find(secondPoint);

  if (ranks[firstPointParent] > ranks[secondPointParent]) {
    parents[secondPointParent] = firstPointParent;
  } else {
    parents[firstPointParent] = secondPointParent;
  }

  if (ranks[firstPointParent] == ranks[secondPointParent]) {
    ranks[secondPointParent]++;
  }
}