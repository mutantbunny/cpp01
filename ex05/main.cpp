/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:12:21 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/15 03:12:23 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "\nDEBUG level message:\n";
	harl.complain("DEBUG");

	std::cout << "INFO level message:\n";
	harl.complain("INFO");

	std::cout << "WARNING level message:\n";
	harl.complain("WARNING");

	std::cout << "ERROR level message:\n";
	harl.complain("ERROR");

	std::cout << "Unknown levels should be ignored (test with"
					" unknown BLAH level, no message"
					" expected after this line):\n";
	harl.complain("BLAH");

	std::cout << std::endl;
}