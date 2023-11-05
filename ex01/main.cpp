/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:14:48 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/05 01:55:56 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *horde;
	const int num_zombies = 5;
	const std::string name("Zeh");

	horde = zombieHorde(5, name);

	if (!horde)
		return 1;

	for (int i = 0; i < num_zombies; ++i)
	{
		std::cout << "Zombie #" << i << " in the horde: ";
		horde[i].announce();
	}

	delete[] horde;
}
