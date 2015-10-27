#include <iostream>
#include "Map.h"

Map::Map() {
  BuildRegMap();
}
Map::Map(int x, int y) {
  BuildRandMap(x, y);
}

void Map::BuildRegMap() {
  int const x = 10;
  int const y = 10;
  FirstFloor = new pair<string, int>*[y];
  for (int i = 0; i < y; i++) {
    FirstFloor[y] = new pair<string, int>[x];
  }
  SecondFloor = new pair<string, int>*[y];
  for (int i = 0; i < y; i++) {
    SecondFloor[y] = new pair<string, int>[x];
  }
  ShipMap = FirstFloor;
}

void Map::BuildRandMap(int tx, int ty) {
  int x = tx;
  int y = ty;
  FirstFloor = new pair<string, int>*[y];
  for (int i = 0; i < y; i++) {
    FirstFloor[y] = new pair<string, int>[x];
  }
  SecondFloor = new pair<string, int>*[y];
  for (int i = 0; i < y; i++) {
    SecondFloor[y] = new pair<string, int>[x];
  }
  ShipMap = FirstFloor;
}
