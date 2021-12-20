#include <iostream>
#include "grid.h"
#include "textdisplay.h"

using namespace std;

Grid::Grid() {
  td = nullptr;
}

Grid::~Grid() { 
  theGrid.clear();
  delete td;
}

void Grid::clearGrid() { 
  theGrid.clear();
  gridSize = 0;
}

bool Grid::isWon() const { return won; }

void Grid::init(int n) {
  clearGrid();
  delete td;
  td = new TextDisplay(n);
  gridSize = n;
  won = false;
  for(int i = 0; i < n; i++) {
    theGrid.push_back(vector<Cell>());
    for(int j = 0; j < n; j++) {
      theGrid[i].push_back(Cell());
      theGrid[i][j].setCoords(i, j);
    }
  }
  // neighbours
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      // top row
      if(i != 0) {
        theGrid[i][j].attach(&theGrid[i-1][j]);
      }
      if(i != n-1) {
        theGrid[i][j].attach(&theGrid[i+1][j]);
      }
      if(j != 0) {
        theGrid[i][j].attach(&theGrid[i][j-1]);
      }
      if(j != n-1) {
        theGrid[i][j].attach(&theGrid[i][j+1]);
      }
      theGrid[i][j].attach(td);
    }
  }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  bool anyCellOn = false;
  for(int i = 0; i < gridSize; i++) {
    for(int j = 0; j < gridSize; j++) {
      if(theGrid[i][j].getState() == true){
        anyCellOn = true;
        break;
      }
    }
  }
  if (!anyCellOn) {
    won = true;
  }
}

ostream &operator<<(ostream &out, const Grid &g) {
  out << *g.td;
  return out;
}

void Grid::printCells() const {
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      std::cout << theGrid[i][j].getName() << ": ";
      std::cout << theGrid[i][j].getObserverNames() << endl;
    } 
  } 
}

