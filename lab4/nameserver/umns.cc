#include "umns.h"
#include <algorithm>

void UMNS::insert(const HostName& hostname, const IPAddress& ip) {
	nameserver.insert(std::make_pair(hostname, ip));
}

bool UMNS::remove(const HostName& hostname) {
	auto ret = nameserver.find(hostname);

	if(ret != nameserver.end()) {
		nameserver.erase(ret);
		return true;
	}
	else return false;
}

IPAddress UMNS::lookup(const HostName& hostname) const {
	auto ret = nameserver.find(hostname);

	return ret != nameserver.end() ? (*ret).second : NON_EXISTING_ADDRESS;
}
