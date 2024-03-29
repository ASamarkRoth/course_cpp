#include "simplebitset.h"
#include <iostream>

SimpleBitset::SimpleBitset() : bits(0) {}

size_t SimpleBitset::size() const {
	return BPW;
}

bool SimpleBitset::get(size_t pos) const {
	/*
	 * Shift a '1' to position pos, 'and' with the bits,
	 * check if result is != 0.
	 */
	//std::cout << "1L << pos: " << (1L << pos) << std::endl;
	return (bits & (1L << pos)) != 0;
}

void SimpleBitset::set(size_t pos, bool b) {
	/*
	 * If b is true, shift a '1' to position pos, 'or' with
	 * the bits, save the bits.
	 * If b is false, shift a '1' to position pos, complement
	 * so it becomes '0' and all other bits '1', 'and' with
	 * the bits, save the bits.
	 */
	if (b) {
		bits |= 1L << pos;
	} else {
		bits &= ~ (1L << pos);
	}
}
