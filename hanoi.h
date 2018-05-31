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

    /* | Helper function that moves top n tiles from 
     * first tower to the second */
    void move(unsigned int, Tower&, Tower&);

    /* Finds the "best" tower currently not in use.
     * The term "best" here refers to the tower which
     * 1) Is not equal to any of the two arguments passed
     * 2) Has the largest tile on the top */
    Tower *spareTower(Tower&, Tower&);

  public:
    Hanoi(Tile); // default 3 towers
    Hanoi(Tile, unsigned int); // variable number of towers

    /* Solves the towers of hanoi, printing each intermediatery step
     * TODO Created derived classes that solves hanoi under different constraints */
    virtual void solve();
    void prettyPrint();
};

#endif // HANOI_H_
