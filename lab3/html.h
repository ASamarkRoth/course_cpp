#ifndef HTML_H
#define HTML_H 1

#include <fstream>
#include <istream>
#include <ostream>

class TagRemover {
	public:
		TagRemover(std::istream&);
		~TagRemover();
		void print(std::ostream&);
	private:
		void find_and_replace(std::string&, const std::string&, const std::string& replace);
		std::string all;


};
#endif
