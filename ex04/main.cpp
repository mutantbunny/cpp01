/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 03:44:38 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/08 02:10:32 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

static std::string ft_replace(std::string haystack, std::string needle,
						std::string subst)
{
	std::string replaced("");
	size_t last_pos = 0;
	size_t found = haystack.find(needle, 0);
	const size_t hs_len = haystack.length();
	const size_t n_len = needle.length();

	while (last_pos < hs_len && found != std::string::npos)
	{
		replaced += haystack.substr(last_pos, found - last_pos);
		replaced += subst;
		last_pos = (found + n_len);
		found = haystack.find(needle, last_pos);
	}

	if (last_pos < hs_len)
		replaced += haystack.substr(last_pos, hs_len - last_pos);

	return replaced;
}

static void print_usage(char *prog_name)
{
	std::cerr << "Usage: " << prog_name << " filename s1 s2\n";
	std::cerr << "Replace every occurrence of s1 with s2 in file filename and"
					" save result to file filename.replace" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		print_usage(argv[0]);
		return (1);
	}

	std::ifstream infile(argv[1]);

	if (!infile)
	{
		std::cerr << "Error: could not open file " << argv[1]
						<< " for reading." << std::endl;
		return (1);
	}

	std::string outfile_name(argv[1]);
	outfile_name += ".replace";
	std::ofstream outfile(outfile_name.c_str());

	if (!outfile)
	{
		std::cerr << "Error: could not open file " << outfile_name
						<< " for writing." << std::endl;
		return (1);
	}

	const std::string needle(argv[2]);
	const std::string subst(argv[3]);
	std::string str_input;

	std::getline(infile, str_input);

	while (infile.good())
	{
		outfile << ft_replace(str_input, needle, subst) << '\n';

		if (outfile.bad())
		{
			std::cerr << "Error: could not write to file " << outfile_name << std::endl;
			return (1);
		}

		std::getline(infile, str_input);
	}

	if (infile.eof() && !infile.fail())
	{
		outfile << ft_replace(str_input, needle, subst);

		if (outfile.bad())
		{
			std::cerr << "Error: could not write to file " << outfile_name << std::endl;
			return (1);
		}
	}

	if (infile.bad())
	{
		std::cerr << "Error: could not read from file " << argv[1] << std::endl;
		return (1);
	}

	infile.close();
	outfile.close();
}
