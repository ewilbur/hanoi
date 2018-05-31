#ifndef TOWER_H_
#define TOWER_H_

#include <vector>
#include <string>

typedef unsigned int Tile;

enum TileMove {
  LEGAL,
  ILLEGAL,
};

class Tower {
  private:
    std::vector<Tile> tower; 
    Tile capacity;
    std::vector<std::string> towerVectorString;

    Tile pop();
    TileMove place(Tile);

    std::string prettyStringRow(std::string&, Tile);
    void makePrettyString();

  public:
    Tower(Tile);

    void fill();
    void clear();
    Tile top() const;
    TileMove moveTo(Tower&);
    const std::vector<std::string> get_towerVectorString();
    void prettyPrint(); // TODO remove

    bool partiallyComplete();

    bool operator==(const Tower&) const;
    bool operator!=(const Tower&) const;
    bool operator>=(const Tower&) const;
    bool operator<=(const Tower&) const;
    bool operator<(const Tower&) const;
    bool operator>(const Tower&) const;
    Tile operator[](int) const;
};

#endif // TOWER_H_
