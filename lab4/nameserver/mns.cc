#include "mns.h"
#include <algorithm>
#include <utility>

void MNS::insert(const HostName& hostname, const IPAddress& ip) {
	nameserver.insert(std::make_pair(hostname, ip));
}

bool MNS::remove(const HostName& hostname) {
	auto ret = nameserver.find(hostname);

	if(ret != nameserver.end()) {
		nameserver.erase(ret);
		return true;
	}
	else return false;
	return true;
}

IPAddress MNS::lookup(const HostName& hostname) const {
	auto ret = nameserver.find(hostname);

	return ret != nameserver.end() ? (*ret).second : NON_EXISTING_ADDRESS;
}
