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

  for (int i = 1; i < nt; ++i) {
    Tower t(cap);
    towers.push_back(t);
  }
}

void Hanoi::solve() {
  move(numTiles,towers[0], towers[towers.size() - 1]);
  cout << "Solved in " << numMoves << " moves." << endl;
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
      cout << "error" << endl;
      exit(0);
    }
    prettyPrint();
    cout << endl;
    numMoves++;
    return;
  } else {

    Tower *spare = spareTower(source, dest);
    move(numTiles - 1, source, *spare);
    move(1, source, dest);
    move(numTiles - 1, *spare, dest);
  }
}

Tower *Hanoi::spareTower(Tower &source, Tower &dest) {
  int i;
  Tower *maybeSpare;
  if (towers[0] != source && towers[0] != dest)
    i = 0;
  else if (towers[1] != source && towers[1] != dest)
    i = 1;
  else
    i = 2;
  maybeSpare = &towers[i];
  for (; i < towers.size(); ++i)
    if (towers[i] > *maybeSpare && towers[i] != source && towers[i] != dest) {
      maybeSpare = &towers[i];
    }

  return maybeSpare;
}
