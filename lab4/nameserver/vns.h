#ifndef VNS_H

#define VNS_H 1

#include "nameserverinterface.h"
#include <vector>

class VNS : public NameServerInterface {
public:

	~VNS() {;}

	virtual void insert(const HostName&, const IPAddress&) override;

	bool remove(const HostName&) override;

	IPAddress lookup(const HostName&) const override;
private:
	std::vector<std::pair<HostName, IPAddress>> nameserver;

};

#endif
