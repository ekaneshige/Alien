#include <iostream>
#include "Map.cpp"

using namespace std;

Map *world;

void Start() {
  world = new Map();
}

int main() {
  Start();
  return 0;
}
