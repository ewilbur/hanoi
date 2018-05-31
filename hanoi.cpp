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

/* This is not the most efficient algorithm as it is not memoized
 * and therefore replicates many of the same operations. However,
 * it is by far the coolest way of doing this. It will find the
 * optimal solution if the number of towers you have is 3, but
 * the solution when numTowers > 3 is not optimal (however it still
 * gives a pretty good solution */
void Hanoi::move(unsigned int numTiles, Tower &source, Tower &dest) {
  if (numTiles == 1) {
    // Only moving one tile
    if (source.moveTo(dest) == ILLEGAL) {
      // Try moving it
      cout << "error" << endl;
      exit(1);
    }
    prettyPrint();
    cout << endl;
    numMoves++;
    return;
  } else {

    // Otherwise find an open tile to use
    Tower *spare = spareTower(source, dest);
    // Move the top n - 1 tiles to it
    move(numTiles - 1, source, *spare);
    // Then move the bottom tile to the destination
    move(1, source, dest);
    // Move the tiles on the spare to the destination
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
