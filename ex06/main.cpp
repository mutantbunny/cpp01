#include "Harl.hpp"

static int print_usage_and_fail(char *prog_name)
{
	std::cout << "Usage: " << prog_name << " <level>, where <level>"
					" must be DEBUG, INFO, WARNING or ERROR."
					<< std::endl;
	return 1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	 return print_usage_and_fail(argv[0]);

	std::string level(argv[1]);

	if (level != "DEBUG" && level != "INFO"
		&& level != "WARNING" && level != "ERROR")
		return print_usage_and_fail(argv[0]);

	Harl harl;

	harl.filter(level);
	return 0;
}