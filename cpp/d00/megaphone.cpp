/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:58:19 by mmayibo           #+#    #+#             */
/*   Updated: 2018/06/04 16:41:22 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string		toupperCase(std::string tempString)
{
	std::string upperCaseString; 
	int length;

	length = tempString.length();

	for(int i = 0; i < length ; i++)
		upperCaseString += toupper(tempString[i]);
	
	return upperCaseString;
}

int				main(int ac, char **av)
{
	std::string BLANK_MESSAGE = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac < 2)
		std::cout<< BLANK_MESSAGE;
	else
	{
		for(int i = 1; i < ac ; i++)
			std::cout<< toupperCase(av[i]);
		std::cout<<'\n';
	}
	return 0;
}

