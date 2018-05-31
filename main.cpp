#include "hanoi.h"
#include "tower.h"

#include <stdio.h>
#include <iostream>
#include <vector>
/* #include <string> */
#include <cstring>
#include <cstdlib>

using namespace std;

void zip(vector<string>&, vector<string>*, vector<string>*);

int main(int argc, char **argv) {
  if ( argc != 2) exit(0);
  Hanoi h(atoi(argv[1]));
  h.prettyPrint();
  h.solve();
}
