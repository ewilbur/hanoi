#include "tower.h"

#include <iostream>

using namespace std;

Tower::Tower(Tile tile) : capacity(tile + 1) {
  towerVectorString.resize(capacity);
  tower.push_back(capacity);
}

void Tower::fill() {
  tower.clear();
  for (Tile i = capacity; i > 0; --i) {
    tower.push_back(i);
  }
}

void Tower::clear() {
  tower.clear();
  tower.push_back(capacity);
}

TileMove Tower::moveTo(Tower &dest) {
  if (top() >= dest.top()) return ILLEGAL;
  dest.place(pop());
  return LEGAL;
}

const vector<string> Tower::get_towerVectorString() {
  makePrettyString();
  return towerVectorString;
}



Tile Tower::top() {
  return tower.back();
}

Tile Tower::pop() {
  Tile topTile = top();
  if (topTile == capacity) return topTile;
  tower.pop_back();
  return topTile;
}

TileMove Tower::place(Tile tile){
  if (tile >= top() || tower.size() == capacity) return ILLEGAL;
  tower.push_back(tile);
  return LEGAL;
}

string Tower::prettyStringRow(string &dest, Tile tile) {
  string padding = "..";
  string tileString = "";
  if (tile == capacity) {
    dest = "##";
    for (int i = 0; i < capacity; ++i)
      dest += "##";
    dest = "_" + dest + "_";
  } else {
    for (int i = 0; i < tile; ++i)
      tileString += "@@";
    for (int i = tile; i < capacity; ++i)
      padding += ".";

    dest = padding + tileString + padding;
  }
  return dest;
}

void Tower::makePrettyString() {
  int i = 0;
  for (; i < tower.size(); ++i) 
    prettyStringRow(towerVectorString.at(i), tower[i]);
  for (; i < capacity; ++i) 
    prettyStringRow(towerVectorString.at(i), 0);
}

void Tower::prettyPrint() {
  makePrettyString();
  for (int i = towerVectorString.size() - 1; i >= 0; --i)
    cout << towerVectorString.at(i) << endl;
}


