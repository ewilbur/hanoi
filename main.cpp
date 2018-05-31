#include "hanoi.h"
#include "tower.h"

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void zip(vector<string>&, vector<string>*, vector<string>*);

int main() {
  Hanoi h(3);
  h.prettyPrint();
  h.solve();






















  /* Tower t1(8); */
  /* Tower t2(8); */

  /* t1.fill(); */
  /* t1.prettyPrint(); */
  /* t2.prettyPrint(); */

  /* cout << endl << endl; */

  /* t1.moveTo(t2); */
  /* t1.prettyPrint(); */
  /* t2.prettyPrint(); */
  /* cout << endl << endl; */
  /* t2.moveTo(t1); */
  /* t1.prettyPrint(); */
  /* t2.prettyPrint(); */
  /* cout << endl << endl; */
  /* vector<string> zipped; */
  /* t.makePrettyString(); */
  /* zip(zipped,t.towerString,t.towerString); */

  /* for (int i = 0; i < zipped.size(); ++i) */
  /*   cout << zipped[i] << endl; */

}

void zip(vector<string> &zipped, vector<string> *x, vector<string> *y) {
  zipped.clear();
  for (int i = 0; i < x->size() && i < y->size(); ++i) {
    zipped.push_back(x->at(i) + y->at(i));
  }
}
