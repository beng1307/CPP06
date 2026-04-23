/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:25:28 by bgretic           #+#    #+#             */
/*   Updated: 2026/04/23 14:25:29 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{		
	public:

		virtual ~Base();

		static Base	*generate(void);
		static void	identify(Base *p);
		static void	identify(Base &p);
};

#endif