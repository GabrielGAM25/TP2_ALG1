#ifndef DisjointSets_H
#define DisjointSets_H

#include<vector>

using namespace std;

class DisjointSets{
private:
  vector<int> parents;
  vector<int> ranks;
  int n;

public:
  DisjointSets(int n);
  int findSet(int u);
  void mergeSets(int x, int y);
};

#endif
