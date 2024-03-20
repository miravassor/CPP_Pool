/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:37:31 by avassor           #+#    #+#             */
/*   Updated: 2023/11/21 17:34:18 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
	public:
		virtual ~Base(){};
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
