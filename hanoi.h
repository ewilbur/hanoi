#ifndef HANOI_H_
#define HANOI_H_

#include "tower.h"
#include <vector>

class Hanoi {
  private:
    unsigned int numTowers;
    std::vector<Tower> towers;
    unsigned int numMoves;
    Tile numTiles;

    void move(unsigned int, Tower&, Tower&);
    unsigned int openTower(Tile);

  public:
    Hanoi(Tile); // default 3 towers
    Hanoi(Tile, unsigned int); // variable number of towers

    virtual void solve();
    void prettyPrint();
};

#endif // HANOI_H_
