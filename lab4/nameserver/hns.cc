#include "hns.h"
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

void HNS::insert(const HostName& hostname, const IPAddress& ip) {
	uint32_t bucket = SuperFastHash(hostname.c_str(), hostname.length());
	//cout << "Bucket is: " << bucket << endl;

	nameserver[bucket].push_back(make_pair(hostname, ip));
}

bool HNS::remove(const HostName& hostname) {
	uint32_t bucket = SuperFastHash(hostname.c_str(), hostname.length());
	auto ret = find_if((nameserver[bucket]).begin(), nameserver[bucket].end(),
			[hostname](std::pair<HostName, IPAddress> x) {return x.first == hostname;});

	if(ret != nameserver[bucket].end()) {
		nameserver[bucket].erase(ret);
		return true;
	}
	else return false;
	//return true;
}

IPAddress HNS::lookup(const HostName& hostname) const {
	uint32_t bucket = SuperFastHash(hostname.c_str(), hostname.length());
	auto ret = find_if(nameserver[bucket].begin(), nameserver[bucket].end(),
			[hostname](std::pair<HostName, IPAddress> x) {return x.first == hostname;});

	return ret != nameserver[bucket].end() ? (*ret).second : NON_EXISTING_ADDRESS;
	//return NON_EXISTING_ADDRESS;
}
