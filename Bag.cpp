#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	daCapacity = 8;
	bagSize = 0;
	elems = new TElem[daCapacity];
	freq = new TElem[daCapacity];
}


void Bag::add(TElem elem) {
	//resize if needed
	if (bagSize == daCapacity)
	{
		daCapacity *= 2;
		TElem* tempArray = new TElem[daCapacity];
		TElem* tempFreq = new TElem[daCapacity];
		int index = 0;
		while (index < bagSize)
		{
			tempArray[index] = elems[index];
			tempFreq[index] = freq[index];
			index++;
		}
		delete[] elems;
		delete[] freq;
		elems = tempArray;
		freq = tempFreq;

	}

	bool found = false;
	int i;
	for (i = 0; i < bagSize; i++)
	{
		if (elems[i] == elem)
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		//elem already exists, don't add just increment freq
		freq[i]++;
	}
	else
	{
		//add new elem & !increment freq counter
		elems[bagSize-1] = elem;
		freq[bagSize-1] = 1;
		//increment size of the array
		bagSize++;
	}

}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
	return false; 
}


bool Bag::search(TElem elem) const {
	//TODO - Implementation
	return false; 
}


int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	return 0; 
}


int Bag::size() const {
	//TODO - Implementation
	return 0;
}


bool Bag::isEmpty() const {
	//TODO - Implementation
	return 0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
}

