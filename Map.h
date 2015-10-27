#ifndef MAP_H
#define MAP_H

using namespace std; 

class Map {
 public:
  Map();
  Map(int, int);
  void BuildRegMap();
  void BuildRandMap(int, int);
  void CreateMaze(int, int);
 private:
  pair<string, int> **ShipMap;
  pair<string, int> **FirstFloor;
  pair<string, int> **SecondFloor;
};


#endif
