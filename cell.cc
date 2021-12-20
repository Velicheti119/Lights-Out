#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"

Cell::Cell() {
  isOn = false;
}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
  isOn = true;
  notifyObservers(SubscriptionType::All);
}

void Cell::toggle() {
  isOn = (isOn) ? false : true;
  notifyObservers(SubscriptionType::All);
  notifyObservers(SubscriptionType::SwitchOnly);
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Cell & whoNotified) {
  isOn = (isOn) ? false : true;
  notifyObservers(SubscriptionType::All);
}

void Cell::notifyObservers(SubscriptionType t) {
  int len = observers.size();
  for(int i = 0; i < len; i++) {
    if(observers[i]->subType() == t) {
        observers[i]->notify(*this);
    }
  }
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}

std::string Cell::getName() const {
  std::string retval = "(" + std::to_string(getRow()) + "," + std::to_string(getCol()) + ")";
  return retval;
}


