/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:10:29 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 11:50:50 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void) {
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	// const Animal k;
	delete j;
	delete i;
	return (0);
}

// int	main(void) {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;
// 	delete i;

// 	Animal *array[4];
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (i < 2)
// 			array[i] = new Dog();
// 		else
// 			array[i] = new Cat();
// 	}
// 	for (int i = 0; i < 4; i++)
// 		array[i]->makeSound();
// 	for (int i = 0; i < 4; i++)
// 		delete array[i];
// 	return (0);
// }


// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }

// int	main(void) {
// 	Animal	a("Animal");
// 	a.makeSound();
// 	Dog		d("Dog");
// 	d.makeSound();
// 	Cat		c("Cat");
// 	c.makeSound();
// }
