#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	daTotalCapacity = 8;
	currentArraySize = 0;
	valuesArray = new TElem[daTotalCapacity];
	frequencyArray = new TElem[daTotalCapacity];
}


void Bag::add(TElem elem) {
	//resize if needed
	if (currentArraySize == daTotalCapacity)
	{
		daTotalCapacity *= 2;
		TElem* tempArray = new TElem[daTotalCapacity];
		TElem* tempFreq = new TElem[daTotalCapacity];
		int index = 0;
		while (index < currentArraySize)
		{
			tempArray[index] = valuesArray[index];
			tempFreq[index] = frequencyArray[index];
			index++;
		}
		delete[] valuesArray;
		delete[] frequencyArray;
		valuesArray = tempArray;
		frequencyArray = tempFreq;

	}
	//search for elem
	bool found = false;
	int i;
	for (i = 0; i < currentArraySize; i++)
	{
		if (valuesArray[i] == elem)
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		//elem already exists, don't add just increment frequencyArray
		frequencyArray[i]++;
	}
	else
	{
		//add new elem & !increment frequencyArray counter
		valuesArray[currentArraySize] = elem; // VStudio needs "-1" for buffer overrun, on xCode don't need it
		frequencyArray[currentArraySize] = 1;
		//increment size of the array
		currentArraySize++;
	}

}


bool Bag::remove(TElem elem) {
	//search for elem
	bool found = false;
	int i;
	for (i = 0; i < currentArraySize; i++)
	{
		if (valuesArray[i] == elem)
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		if (frequencyArray[i] > 1)
		{
			frequencyArray[i]--;
		}
		else
		{
			valuesArray[i] = valuesArray[currentArraySize - 1];
			frequencyArray[i] = frequencyArray[currentArraySize - 1];
			currentArraySize--;
		}
		return true;
	}
	return false;
}


bool Bag::search(TElem elem) const {
	for (int i = 0; i < currentArraySize; i++)
	{
		if (valuesArray[i] == elem)
		{
			return true;
		}
	}
	return false;
}


int Bag::nrOccurrences(TElem elem) const {
	int nrOccured = 0;
	for (int i = 0; i < currentArraySize; i++)
	{
		if (valuesArray[i] == elem)
		{
			return frequencyArray[i];
		}
	}
	return 0; 
}


int Bag::size() const {
	int totalSize = 0;
	for (int i = 0; i < currentArraySize; i++)
	{
		totalSize += frequencyArray[i];
	}
	return totalSize;
}


bool Bag::isEmpty() const {
	return currentArraySize == 0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[] frequencyArray;
	delete[] valuesArray;
}

