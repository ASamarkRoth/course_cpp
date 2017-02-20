/*
 * A BitsetIterator is an iterator for Bitsets.
 * Postfix ++, ==, and -> are not implemented.
 */

#ifndef BITSET_ITERATOR_H
#define BITSET_ITERATOR_H

#include "bitreference.h"
#include <iterator>
#include <iostream>

class BitsetIterator : public std::iterator<std::forward_iterator_tag, bool> {
public:
	BitsetIterator(Bitset::BitStorage* pb, std::size_t p) : ref(pb, p) {}

	bool operator==(const BitsetIterator& bsi) const {
		//What if BitsetIterator = end(), then dereference -> seg. fault.
		//Is it ok to only compare pointers?
		return ref.pos == bsi.ref.pos && ref.p_bits == bsi.ref.p_bits;
	}

	bool operator!=(const BitsetIterator& bsi) const {
		//std::cout << "Not equals ... " << std::endl;
		return !(*this == bsi);
	}

	//this is prefix (indicated with that a reference is returned)
	BitsetIterator& operator++() {
		if(ref.pos >= Bitset::BPW - 1) {
			ref.pos = Bitset::BPW;
		}
		else ++ref.pos;
		++counter;
		//std::cout << "count = " << counter << std::endl;
		return *this;
	}

	//postfix (apparently an int needs to be passed as arg.)
	BitsetIterator operator++(int) {
		BitsetIterator result(ref.p_bits, ref.pos);
		++(*this);
		return result;
	}

	BitReference operator*() {
		return ref;
	}

	BitReference* operator->() {
		return &ref;
	}

	BitsetIterator& operator=(const BitsetIterator& rhs) {
		ref.p_bits = rhs.ref.p_bits;
		ref.pos = rhs.ref.pos;
		return *this;
	}
private:
	BitReference ref;
	int counter = 0;
};

#endif

