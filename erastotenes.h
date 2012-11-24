
#ifndef ERASTOTENES_H
#define ERASTOTENES_H

#include <stdexcept>
#include <vector.h>
#include <list.h>

class Erastotenes{
private:
	vector<int> internalList;


public:
	Erastotenes(int max);

	int getFirstElementOfList();
	int getLastElementOfList();
	vector<int> getInternalList();
	list<int> findPrimes();



};

#endif