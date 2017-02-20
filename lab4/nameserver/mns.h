#ifndef MNS_H
#define MNS_H 1

#include "nameserverinterface.h"
//#include "vns.h"
#include <map>

//class MNS : public VNS {
class MNS : public NameServerInterface {
public:
	~MNS() {;}

	void insert(const HostName&, const IPAddress&) override;

	bool remove(const HostName&);

	IPAddress lookup(const HostName&) const;

private:
	std::map<HostName, IPAddress> nameserver;

};

#endif
