#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	currentPosition = 0;
}

void BagIterator::first() {
	currentPosition = 0;
}


void BagIterator::next() {
	if (currentPosition  >= bag.currentArraySize)
	{
		throw exception();
	}
	currentPosition++;
}


bool BagIterator::valid() const {
	return currentPosition < bag.currentArraySize;
}


TElem BagIterator::getCurrent() const
{
	if (currentPosition >= bag.currentArraySize)
	{
		throw exception();
	}
	return bag.valuesArray[currentPosition];
}
