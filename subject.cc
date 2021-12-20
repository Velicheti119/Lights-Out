#include "subject.h"
#include <vector>
#include "observer.h"
#include <iostream>
using std::string;


void Subject::attach(Observer *o) {
	observers.push_back(o);
}

string Subject::getObserverNames() const {
	int len = observers.size();
	//std::sort(observers.begin(), observers.end());
	std::vector<string> tempArray;
	for(int i = 0; i < len; i++) {
		tempArray.push_back(observers[i]->getName());
	}

	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(tempArray[j] > tempArray[i]) {
				std::swap(tempArray[j],tempArray[i]);
			}
		}
	}

	string retval = "";
	for(int i = 0; i < len; i++) {
		if(i != len -1) {
		        retval += tempArray[i] + ",";
		} else {
			retval += tempArray[i];
		}
	}
	return retval;
}


