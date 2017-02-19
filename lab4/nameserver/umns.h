#ifndef UMNS_H
#define UMNS_H 1

#include "nameserverinterface.h"
#include <unordered_map>

class UMNS : public NameServerInterface {
public:

	~UMNS() {;}

	void insert(const HostName&, const IPAddress&) override;

	bool remove(const HostName&) override;

	IPAddress lookup(const HostName&) const override;
private:
	std::unordered_map<HostName, IPAddress> nameserver;

};

#endif
