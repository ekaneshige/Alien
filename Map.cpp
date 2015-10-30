#include <iostream>
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> 
#include <stack> 
#include <vector>     
#include "Map.h"

Map::Map() {
  xbound = 10;
  ybound = 10;
  BuildRegMap();
}
Map::Map(int x, int y) {
  xbound = x;
  ybound = y;
  BuildRandMap();
}

void Map::BuildRegMap() {
  int const x = xbound;
  int const y = ybound;
  FirstFloor = new pair<string, int>*[y];
  for (int i = 0; i < y; i++) {
    FirstFloor[i] = new pair<string, int>[x];
  }
  SecondFloor = new pair<string, int>*[y];
  for (int i = 0; i < y; i++) {
    SecondFloor[i] = new pair<string, int>[x];
  }
  ShipMap = FirstFloor;
  CreateMaze();
  printmaze();
  printcode();
}

void Map::BuildRandMap() { //unofficial
  int x = xbound;
  int y = ybound;
  FirstFloor = new pair<string, int>*[y];
  for (int i = 0; i < y; i++) {
    FirstFloor[y] = new pair<string, int>[x];
  }
  SecondFloor = new pair<string, int>*[y];
  for (int i = 0; i < y; i++) {
    SecondFloor[y] = new pair<string, int>[x];
  }
  ShipMap = FirstFloor;
  //CreateMaze();
}

void Map::CreateMaze() { //also do 2nd floor.
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
  
  srand (time(NULL));
  for (int i = 0; i < xbound; i++) {
    for (int j = 0; j < ybound; j++) {
      //FirstFloor[i][j].first = "unknown";
      //FirstFloor[i][j].second = 0;
      FirstFloor[i][j] = make_pair("unknown", 0);
      SecondFloor[i][j] = make_pair("unknown", 0);
    }
  } 
  
  int random_x_num; 
  int random_y_num; 
  int counter = xbound * ybound;

  while (counter > 0) {
    counter--;//HACK
    //printcode(); //testestes
    //int t; //testestest
    //cin >> t; //testetstset
    random_x_num = rand() % xbound;
    random_y_num = rand() % ybound;
    cout << "x: " << random_x_num <<endl;
    cout << "y: " << random_y_num << endl;
    cout << FirstFloor[random_x_num][random_y_num].second << endl;
    if (FirstFloor[random_x_num][random_y_num].second == 0) {
      cout << "in while loop" << endl; ////////////////////////////
      bool broken = false;
      while (!broken) {
	int temp1 = 0; //holds the original floor type before it changes
	int temp2 = 0; //holds the original floor value of adjacent tile
	int newtype = (rand() % 4 + 1);
	cout << "new type: " << newtype << endl;
	switch (newtype) { 
	case 1: 
	  {
	    if ((random_x_num - 1) >= 0) { 
	      broken = true;
	      temp1 = FirstFloor[random_x_num][random_y_num].second;
	      FirstFloor[random_x_num][random_y_num].second = 
		newFloor(temp1, newtype);
	      temp2 = FirstFloor[random_x_num - 1][random_y_num].second;
	      FirstFloor[random_x_num - 1][random_y_num].second =
		newFloor(temp2, oppositeFloorType(newtype));
	    } break;
	  }
	case 2:
	  {
	    if ((random_y_num - 1) >= 0)  { 
	      //broken = true;
	      //FirstFloor[random_x_num][random_y_num].second = newtype;
	      broken = true;
	      temp1 = FirstFloor[random_x_num][random_y_num].second;
	      FirstFloor[random_x_num][random_y_num].second = 
		newFloor(temp1, newtype); 
	      temp2 = FirstFloor[random_x_num][random_y_num - 1].second;
	      FirstFloor[random_x_num][random_y_num - 1].second =
		newFloor(temp2, oppositeFloorType(newtype));

	    } break;	  
	  }
	case 3:
	  {
	    if ((random_x_num + 1) < xbound)  { 
	      //broken = true;
	      //FirstFloor[random_x_num][random_y_num].second = newtype;
	      broken = true;
	      temp1 = FirstFloor[random_x_num][random_y_num].second;
	      FirstFloor[random_x_num][random_y_num].second = 
		newFloor(temp1, newtype); 
	      temp2 = FirstFloor[random_x_num + 1][random_y_num].second;
	      FirstFloor[random_x_num + 1][random_y_num].second =
		newFloor(temp2, oppositeFloorType(newtype));
	    } break;
	  }
	case 4: 
	  {
	    if ((random_y_num + 1) < ybound)  { 
	      //broken = true;
	      //FirstFloor[random_x_num][random_y_num].second = newtype;
	      broken = true;
	      temp1 = FirstFloor[random_x_num][random_y_num].second;
	      FirstFloor[random_x_num][random_y_num].second = 
		newFloor(temp1, newtype); 
	      temp2 = FirstFloor[random_x_num][random_y_num + 1].second;
	      FirstFloor[random_x_num][random_y_num + 1].second =
		newFloor(temp2, oppositeFloorType(newtype));
	    } break;
	  }
	}
      }
      counter--;
    }
  }
  //Break Walls
  
  
}
 
bool breakable(int x, int y) {
  //if (x == 0 || y == 0 ||
}



void Map::printwalls(int num) {
  
  /*
     _       _             _      _
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
  switch(num) {
  case 0: cout << "[_]"; break;
  case 1: cout << " _]"; break;
  case 2: cout << "[_]"; break;//skip only 3
  case 3: cout << "[_ "; break;
  case 4: cout << "[ ]"; break;
  case 12: cout << " _]"; break;
  case 13: cout << " _ "; break;
  case 14: cout << "  ]"; break;
  case 23: cout << "[_ "; break;
  case 24: cout << "[ ]"; break;
  case 34: cout << "[  "; break;
  case 123: cout << " _ "; break;
  case 124: cout << "  ]"; break;
  case 134: cout << "   "; break;
  case 234: cout << "  ]"; break;
  case 1234: cout << "   "; break;
  }
}

void Map::printceiling() {
  int x = xbound;
  for (int top = 0; top < x; top++) {
    cout << " _ ";
  }
  cout<< endl;
}

void Map::printfloor(int num) {
  switch (num) {
  case 0: cout << " _ "; break;
  case 1: cout << " _ "; break;
  case 2: cout << " _ "; break;
  case 3: cout << " _ "; break;
  case 12: cout << " _ "; break;
  case 13: cout << " _ "; break;
  case 23: cout << " _ "; break;
  case 123: cout << " _ "; break;
  }
}

void Map::printmaze() {
  printceiling();
  for (int j = 0; j < ybound; j++) {
    //cout << "|";
    for (int i = 0; i < xbound; i++) {
      printwalls(ShipMap[i][j].second);
    }
    /*
    cout << endl;
    
    for (int k = 0; k < xbound; k++) {
      printfloor(ShipMap[k][j].second);
      } 
    */
    cout << endl;
  }
}

void Map::printcode() {
  for (int j = 0; j < ybound; j++) {
    //cout << "|";
    for (int i = 0; i < xbound; i++) {
      cout << ShipMap[i][j].second;
    }
    cout << endl;
 }
}

int Map::oppositeFloorType (int num) {
  int result = 0;
  switch(num) {
  case 1: {result = 3; break;}
  case 2: {result = 4; break;}
  case 3: {result = 1; break;}
  case 4: {result = 2; break;}
  }
  return result;
}

int Map::newFloor (int current, int destroyedwall) {
  bool left = false;
  bool up = false;
  bool right = false;
  bool down = false;
  //true means that wall is gone for this particular tile
  switch (current) {
  case 1: {left = true; break;}
  case 2: {up = true; break;}
  case 3: {right = true; break;}
  case 4: {down = true; break;}
  case 12: {left = true; up = true; break;}
  case 13: {left = true; right = true; break;}
  case 14: {left = true; down = true; break;}
  case 23: {up = true;  right = true; break;}
  case 24: {up = true; down = true; break;}
  case 34: {right = true; down = true; break;}
  case 123: {left = true; up = true; right = true; break;}
  case 124: {left = true; up = true; down = true; break;}
  case 134: {left = true; right = true; down = true; break;}
  case 234: {up = true; right = true; down = true; break;}
  case 1234: {left = true; up = true; right = true; down = true; break;}
  }
  switch (destroyedwall) {
  case 1: {left = true; break;}
  case 2: {up = true; break;}
  case 3: {right = true; break;}
  case 4: {down = true; break;}
  }
  if (left && !up && !right && !down) return 1; 
  if (!left && up && !right && !down) return 2; 
  if (!left && !up && right && !down) return 3; 
  if (!left && !up && !right && down) return 4; 
  if (left && up && !right && !down) return 12; 
  if (left && !up && right && !down) return 13; 
  if (left && !up && !right && down) return 14; 
  if (!left && up && right && !down) return 23; 
  if (!left && up && !right && down) return 24; 
  if (!left && !up && right && down) return 34; 
  if (left && up && right && !down) return 123; 
  if (left && up && !right && down) return 124; 
  if (left && !up && right && down) return 134; 
  if (!left && up && right && down) return 234; 
  if (left && up && right && down) return 1234; 
  //if (!left && !up && !right && !down) return 1; 
  return 0;
}

bool Map::DFS_check() {
  int x;
  int y;
  int target_x = rand() % xbound;
  int target_y = rand() % ybound;
  for (y = 0; y < ybound; y++) {
    for (x = 0; x < xbound; x++) {
      if (!DFS_to_target(x, y, target_x, target_y)) return false;
    }
  }
}

bool Map::DFS_to_target (int startx, int starty, int endx, int endy) {
  pair<int, int> curr = make_pair(startx, starty);
  pair<int, int> end = make_pair(endx, endy);
  //stack<pair<int, int> > backtrack; //stack of how to get back
  int tile = FirstFloor[curr.first][curr.second].second;
  //stack<pair<int, int> > history; //stack of all places I've been
  //stack<pair<int, int> > new_opportunities;
  bool left = false;
  bool up = false;
  bool right = false;
  bool down = false;

  //setting DFS priorities
  srand (time(NULL));
  int priority_seq;
  string basic_seq[] = {"left", "down", "right", "up"}; 
  string chosen_seq[] = {"", "", "", ""};
  int chosen_seq_size = 0;
  //sets and approves DFS sequence
  while (chosen_seq_size < 4) {
    priority_seq = rand() % 4;
    bool acceptable = true;
    for (int i = 0; i < chosen_seq_size; i++) {
      if (basic_seq[priority_seq] == chosen_seq[i]) {
	acceptable = false;
      }
    } 
    if (acceptable) chosen_seq_size++;
  }

  while (curr != end) {
    //true means that wall is gone for this particular tile
    switch (tile) {
    case 1: {left = true; break;}
    case 2: {up = true; break;}
    case 3: {right = true; break;}
    case 4: {down = true; break;}
    case 12: {left = true; up = true; break;}
    case 13: {left = true; right = true; break;}
    case 14: {left = true; down = true; break;}
    case 23: {up = true;  right = true; break;}
    case 24: {up = true; down = true; break;}
    case 34: {right = true; down = true; break;}
    case 123: {left = true; up = true; right = true; break;}
    case 124: {left = true; up = true; down = true; break;}
    case 134: {left = true; right = true; down = true; break;}
    case 234: {up = true; right = true; down = true; break;}
    case 1234: {left = true; up = true; right = true; down = true; break;}
    }
    bool approved_move = false;
    for (int j = 0; !approved_move && (j < chosen_seq_size); j++) {
      if (chosen_seq[j] == "left") {
	if (left) {//add to history. move. add new possibilities.
	  backtrack.push(make_pair(curr.first, curr.second)); //add curr space
	  history.push(make_pair(curr.first, curr.second));
	  curr.first--;
	  //add new possibilities function of this tile space.
	  
	}
      }
      else if (chosen_seq[j] == "up") {

      }
      else if (chosen_seq[j] == "down") {

      }
      else if (chosen_seq[j] == "right") {

      }
    }
    
  


    /*
    if (tile == 1 || tile == 12 || tile == 13 || tile == 14
	|| tile == 123 || tile == 124 || tile == 134) {
      //search through history
      for (int i = 0; i < vector.size(); i++) {
	//if (curr == history[i]) 
	//don't go back unless have to.
	//stages: advance. and then going backwards until finding a new path
      }
      //
      } */
  }
    return true;
}

void Map::add_new_opportunities(int x, int y) {
  bool left = false;
  bool down = false;
  bool up = false;
  bool right = false;
  switch (FirstFloor[x][y].second) {
  case 1: {left = true; break;}
  case 2: {up = true; break;}
  case 3: {right = true; break;}
  case 4: {down = true; break;}
  case 12: {left = true; up = true; break;}
  case 13: {left = true; right = true; break;}
  case 14: {left = true; down = true; break;}
  case 23: {up = true;  right = true; break;}
  case 24: {up = true; down = true; break;}
  case 34: {right = true; down = true; break;}
  case 123: {left = true; up = true; right = true; break;}
  case 124: {left = true; up = true; down = true; break;}
  case 134: {left = true; right = true; down = true; break;}
  case 234: {up = true; right = true; down = true; break;}
  case 1234: {left = true; up = true; right = true; down = true; break;}
  }
  if (left) new_opportunities.push(make_pair(x--, y));
  if (down) new_opportunities.push(make_pair(x, y++));
  if (up) new_opportunities.push(make_pair(x, y--));
  if (right) new_opportunities.push(make_pair(x++, y));
  //dont add to new_opportunities from places you have been and was just from
  //when using this function, add the priority direction to this. don't 
  //just have every new opportunity be from left->down->up->right
}
