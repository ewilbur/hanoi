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
    std::vector<Tile> tower; // Vector to hold the tiles that the Tower contains
    /* | The capacity is the size of the base on the tower. Even though
     * the base is not a tile, treating it as such simplifies the code a little
     * bit. The program does not rely too heavily on the fact that the base is 
     * a tile and so this can therefore be changed to refer to the size of the
     * maximum tile instead with minimal refactoring */
    Tile capacity;
    /* | Container to hold the pretty printed string for a tower. It's easier to
     * keep it as a vector of strings so that hanoi.h can easily concat the towers
     * in its pretty printer. */
    std::vector<std::string> towerVectorString;

    /* | Standard stack pop instruction. Removes the top tile and returns it. */
    Tile pop();
    /* | Place a tile on a tower. If move is LEGAL, tower is changed, otherwise on
     * ILLEGAL this will not change the tower at all */
    TileMove place(Tile);

    /* | Helper funtion for getting the string for a given row of the tower */
    std::string prettyStringRow(std::string&, Tile);
    /* | Creates the towerVectorString */
    void makePrettyString();

  public:
    Tower(Tile);

    /* | Fill tower to capacity */
    void fill();
    /* Remove all tiles from the tower */
    void clear();
    /* | Essentially a stack peek instruction. Returns the top of the tower
     * without removing it */
    Tile top() const;
    /* Moves the tile on the top of *this to top of argument. If move is
     * ILLEGAL, it does not change either tower, otherwise, both towers are adjusted */
    TileMove moveTo(Tower&);
    const std::vector<std::string> get_towerVectorString();

    /* | Checks to see if the given tower is partially completed, meaning that
     * the tiles it contains are all in their corret position. Currently not
     * used anywhere in the code, but will be ised later to implement the
     * optimal solution when there are more than 3 towers. */
    bool partiallyComplete();

    /* | IMPORTANT NOTE ABOUT THESE OVERLOADED OPERATORS BECAUSE THEY MIGHT NOT WORK
     * AS YOU WOULD ORIGINALLY EXPECT
     *
     * As you probably know, if x <= y && y <= x --> x == y. 
     * THAT IS NOT THE CASE HERE. 
     * The equality operators (== and !=) check if the ADDRESSES of the towers
     * are equal (ie, they are the same object) while the comparison operators
     * compare the TOP TILES of the towers.
     *
     * Thus, you may have a case where two towers are identically stacked with
     * tiles HOWEVER they will not be equal if they are two seperate objects.
     * EVEN THOUGH the ordinal operators would normally imply that they are.
     *
     * For example:
     * ```cpp
     * Tower t1(9); 
     * Tower t2(9);
     * t1.fill();
     * t2.fill();
     * // t1 and t2 are now identically stacked towers.
     *
     * cout << "t1 " << (t1 >= t2) ? ">= " : "<= " << "t2" << endl;
     * cout << "t1 " << (t1 <= t2) ? "<= " : ">= " << "t2" << endl;
     * cout << "t1 " << (t1 == t2) ? "== " : "!= " << "t2" << endl;
     * ```
     * Will produce the output
     * ```
     * t1 >= t2
     * t1 <= t2
     * t1 != t2
     * ```
     *
     * This goes against every mathematical bone in my body, however it makes
     * the code cleaner.
     * */

    bool operator==(const Tower&) const;
    bool operator!=(const Tower&) const;


    bool operator>=(const Tower&) const;
    bool operator<=(const Tower&) const;
    bool operator<(const Tower&) const;
    bool operator>(const Tower&) const;

    /* | Returns the nth element starting from the top of the stack */
    Tile operator[](int) const;
};

#endif // TOWER_H_
