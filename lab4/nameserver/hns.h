#ifndef HNS_H
#define HNS_H 1

#include "nameserverinterface.h"
#include "hash_func.h"
#include <vector>

class HNS : public NameServerInterface {
public:
	HNS(const size_t size) : table_size(size) {;}

	~HNS() {;}

	void insert(const HostName&, const IPAddress&) override;

	bool remove(const HostName&) override;

	IPAddress lookup(const HostName&) const override;

private:
	const size_t table_size;
	std::vector<std::vector<std::pair<HostName, IPAddress>>> nameserver;

};

#endif
