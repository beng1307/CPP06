/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:25:13 by bgretic           #+#    #+#             */
/*   Updated: 2026/04/23 14:25:14 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

enum Type
{
	CLASS_A,
	CLASS_B,
	CLASS_C
};

Base::~Base()
{
	return ;
};

Base	*Base::generate(void)
{
	static bool seeded = false;
	int			random_number;
	
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}

	random_number = std::rand() % 3;

	if (random_number == CLASS_A)
		return (new A());
	else if (random_number == CLASS_B)
		return (new B());
	else if (random_number == CLASS_C)
		return (new C());
	else
	{
		std::cout << "Wrong random number generated!" << std::endl;
		return (NULL);
	}
}

void	Base::identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Is not a child!" << std::endl;
}

void	Base::identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...) {}

	std::cout << "Is not a child!" << std::endl;
}
