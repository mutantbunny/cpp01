/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:12:36 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/15 03:12:38 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) { }

int Harl::get_hash(std::string level)
{
	int hash(0);

	for (size_t i = 0; i < 4; ++i)
		hash += level[i] * (4 - i);
	return (hash - 696) / 25;
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my"
					" 7XL-double-cheese-triple-pickle-special ketchup burger.\n"
					"I really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\n"
					"You didn't put enough bacon in my burger!\nIf you did,"
					" I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon"
					" for free.\nI've been coming for years whereas you"
					" started working here since last month.\n" << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to"
					" speak to the manager now.\n" << std::endl;
}

void Harl::filter(std::string level)
{
	switch(get_hash(level))
	{
		case Harl::DEBUG:
			debug();
			info();
			warning();
			error();
			break;

		case Harl::INFO:
			info();
			warning();
			error();
			break;

		case Harl::WARNING:
			warning();
			error();
			break;

		case Harl::ERROR:
			error();
	}
}
