/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:14:48 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/05 02:20:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string brain("HI THIS IS BRAIN");
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "The memory address of the string variable \"brain\" is "
				<< &brain << ".\n";
	std::cout << "The memory address held by stringPTR is "
				<< stringPTR << ".\n";
	std::cout << "The memory address held by stringREF is "
				<< &stringREF << ".\n";
	std::cout << "The value of the string variable \"brain\" is \""
				<< brain << "\".\n";
	std::cout << "The value pointed to by stringPTR is \""
				<< *stringPTR << "\".\n";
	std::cout << "The value pointed to by stringREF is \""
				<< stringREF << "\"." << std::endl;
}
