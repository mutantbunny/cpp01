/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:43:57 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/06 01:19:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"


class HumanB
{
	public:
		HumanB(std::string name);

		void attack(void);
		void setWeapon(Weapon &weapon);

	private:
		std::string _name;
		Weapon *_weapon;
};

#endif
