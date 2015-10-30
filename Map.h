#ifndef MAP_H
#define MAP_H

using namespace std; 

class Map {
 public:
  Map();
  Map(int, int);
  void BuildRegMap();
  void BuildRandMap();
  void CreateMaze();
  void printmaze();
  int newFloor(int, int);
  int oppositeFloorType(int);
  bool DFS_check();
  bool DFS_to_target(int,int,int,int);
  void add_new_opportunities(int, int, string[]);
  bool check_history(int x, int y);
 
 private:
  
  void printfloor(int);
  void printwalls(int);
  void printceiling();
  void printcode();
  pair<string, int> **ShipMap;
  pair<string, int> **FirstFloor;
  pair<string, int> **SecondFloor;
  int xbound;
  int ybound;
  stack<pair<int, int> > backtrack; //stack of how to get back FOR ALIEN
  vector <pair<int, int> > history; //stack of all places I've been FOR ALIEN
  stack<pair<int, int> > new_opportunities; //FOR ALIEN
  //string *chosen_seq; //for the DFS
};


#endif
