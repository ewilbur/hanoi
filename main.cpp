#include "hanoi.h"
#include "tower.h"

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void zip(vector<string>&, vector<string>*, vector<string>*);

int main() {
  Hanoi h(9);
  h.prettyPrint();
  h.solve();
}
