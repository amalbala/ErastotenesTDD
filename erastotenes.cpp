
#include "erastotenes.h"


Erastotenes::Erastotenes(int max){
	if(max <= 2){
		throw(std::range_error("Max value is lower than two"));
	}
	for(int i=2; i<=max; i++){
		internalList.push_back(i);
	}
}

int Erastotenes::getFirstElementOfList(){
	return internalList.front();
}

int Erastotenes::getLastElementOfList(){
	return internalList.back();
}

vector<int> Erastotenes::getInternalList(){
	return internalList;
}

list<int> Erastotenes::findPrimes(){
	vector<int>::iterator currentItemUnderStudy;
	currentItemUnderStudy = internalList.begin();
	list<int> primes;
	while(currentItemUnderStudy != internalList.end()){

		if(*currentItemUnderStudy!=0){
			primes.push_back(*currentItemUnderStudy);

			for(int i=2; (*currentItemUnderStudy)*i<internalList.size()+2;i++){

				internalList[((*currentItemUnderStudy)*i)-2] = 0;
			}


		}
		currentItemUnderStudy++;
	}

	return primes;

}



