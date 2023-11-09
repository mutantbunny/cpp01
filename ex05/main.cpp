#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "\nDEBUG level message:\n";
	harl.complain("DEBUG");

	std::cout << "\nINFO level message:\n";
	harl.complain("INFO");

	std::cout << "\nWARNING level message:\n";
	harl.complain("WARNING");

	std::cout << "\nERROR level message:\n";
	harl.complain("ERROR");

	std::cout << "\nUnknown levels should be ignored (test with"
					" unknown 'BLAH' level, no message"
					" expected after this line):\n";
	harl.complain("BLAH");

	std::cout << std::endl;
}