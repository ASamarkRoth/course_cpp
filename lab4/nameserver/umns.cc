#include "umns.h"
#include <algorithm>

void UMNS::insert(const HostName& hostname, const IPAddress& ip) {
	nameserver.push_back(make_pair(hostname, ip));
}

bool UMNS::remove(const HostName& hostname) {
	auto ret = find_if(nameserver.begin(), nameserver.end(),
			[hostname](std::pair<HostName, IPAddress> x) {return x.first == hostname;});

	if(ret != nameserver.end()) {
		nameserver.erase(ret);
		return true;
	}
	else return false;
}

IPAddress UMNS::lookup(const HostName& hostname) const {
	auto ret = find_if(nameserver.begin(), nameserver.end(),
			[hostname](std::pair<HostName, IPAddress> x) {return x.first == hostname;});

	return ret != nameserver.end() ? (*ret).second : NON_EXISTING_ADDRESS;
}
