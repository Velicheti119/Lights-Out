#include <iostream>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"

using namespace std;

TextDisplay::TextDisplay(int n) : gridSize{n} {
  for(int i = 0; i < n; i++) {
    theDisplay.push_back(vector<char>());
    for(int j = 0; j < n; j++) {
      theDisplay[i].push_back('.');
    }
  }
}

void TextDisplay::notify(Cell &whoNotified) {
  int r = whoNotified.getRow();
  int c = whoNotified.getCol();
  theDisplay[r][c] = (theDisplay[r][c] == '.') ? theDisplay[r][c] = 'X' : theDisplay[r][c] = '.';
}

TextDisplay::~TextDisplay() {
  theDisplay.clear();
}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

std::string TextDisplay::getName() const {
  return "TD";
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for(int i = 0; i < td.gridSize; i++) {
    for(int j = 0; j < td.gridSize; j++) {
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  return out;
}

