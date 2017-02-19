#include "hns.h"
#include <algorithm>

void HNS::insert(const HostName& hostname, const IPAddress& ip) {
}

bool HNS::remove(const HostName& hostname) {

	return true;
}

IPAddress HNS::lookup(const HostName& hostname) const {

	return NON_EXISTING_ADDRESS;
}
