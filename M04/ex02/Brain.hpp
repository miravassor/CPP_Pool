/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:44:36 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 10:35:28 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Brain {
	protected:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(Brain const &copy);
		~Brain(void);
		Brain& operator=(Brain const &copy);
		std::string	getIdeas(int i) const;
		void	setIdeas(std::string str, int i);
};
