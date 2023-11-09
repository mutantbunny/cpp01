#include "Harl.hpp"

Harl::Harl(void)
{
	complaints[Harl::DEBUG] = &Harl::debug;
	complaints[Harl::INFO] = &Harl::info;
	complaints[Harl::ERROR] = &Harl::error;
	complaints[Harl::WARNING] = &Harl::warning;
}

int Harl::get_hash(std::string level)
{
	int hash(0);

	for (size_t i = 0; i < 4; ++i)
		hash += level[i] * (4 - i);
	return (hash - 696) / 25;
}

void Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my"
					" 7XL-double-cheese-triple-pickle-special ketchup burger."
					" I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money."
					" You didn't put enough bacon in my burger! If you did,"
					" I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon"
					" for free. I've been coming for years whereas you"
					" started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to"
					" speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	if (level != "DEBUG" && level != "INFO"
		&& level != "WARNING" && level != "ERROR")
		return;

	((this)->*(complaints[get_hash(level)]))();
}
