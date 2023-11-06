/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:43:52 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/06 01:56:22 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):
	_name(name), _weapon(NULL) { }

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (!_weapon)
		std::cout << _name << " attacks with their bare hands (no weapon set)"
			<< std::endl;
	else
		std::cout << _name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
}
