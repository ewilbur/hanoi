#include "hanoi.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Hanoi::Hanoi(Tile cap) : numTowers(3), numMoves(0), numTiles(cap) {
  Tower t1(cap), t2(cap), t3(cap);
  t1.fill();
  towers.push_back(t1);
  towers.push_back(t2);
  towers.push_back(t3);
}

Hanoi::Hanoi(Tile cap, unsigned int nt) : numTowers(nt), numMoves(0), numTiles(cap) {
  Tower t1(cap);
  t1.fill();
  towers.push_back(t1);

  for (int i = 0; i < nt; ++i) {
    Tower t(cap);
    towers.push_back(t);
  }
}

void Hanoi::solve() {
  move(numTiles,towers[0], towers[2]);
}

void Hanoi::prettyPrint() {
  string row;
  for (int i = numTiles; i >= 0; --i) {
    for (int j = 0; j < towers.size(); j++) {
      row += towers[j].get_towerVectorString()[i];
    }
    cout << row << endl;
    row = "";
  }
}

void Hanoi::move(unsigned int numTiles, Tower &source, Tower &dest) {
  if (numTiles == 1) {
    if (source.moveTo(dest) == ILLEGAL) {
      cout << "You fucked up" << endl;
      exit(0);
    }
    prettyPrint();
    return;
  }
}

/* void Hanoi::move(unsigned int numTiles, unsigned int sourceTower, unsigned int destTower) { */
/*   if (numTiles == 1) { */
/*     if kk */
/* } */

/* unsigned int Hanoi::openTower(Tile tile) { */
/*   for (int i = 0; i < towers.size(); ++i) */
/*     if (towers[i].top() > tile) */
/*       return i; */
/* } */
