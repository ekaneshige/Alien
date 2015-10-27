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

void Map::CreateMaze(int x, int y) {
  //Maze generation
  /*     _       _             _      _
     0: |_|  1:  _| 2: |_| 3: |_  4: | |
                 _      _                    
    12:  _| 13:  _ 14:   |                   
    
    23: |_  24: | |
         _
    34: |
                 _  
    123: _  134:    124:  | 234: |
    
    1234:
   */
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      FirstFloor[x][y] = make_pair("unknown", 0);
      SecondFloor[x][y] = make_pair("unknown", 0);
    }
  }
  //Break Walls
  
}
