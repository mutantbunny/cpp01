/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:12:50 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/15 03:12:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void filter(std::string level);

		Harl(void);

	private:
		typedef void (Harl::*t_complain_fn)(void);
		typedef enum e_level
		{
			DEBUG,
			INFO,
			ERROR,
			WARNING
		} t_level;

		int get_hash(std::string level);
};

#endif
