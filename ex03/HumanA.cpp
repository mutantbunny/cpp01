/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:43:38 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/06 01:55:59 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):
	_name(name), _weapon(weapon) { }

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}
