/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:43:48 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/06 02:03:04 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include "Weapon.hpp"


class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);

		void attack(void);

	private:
		std::string _name;
		Weapon &_weapon;
};

#endif
