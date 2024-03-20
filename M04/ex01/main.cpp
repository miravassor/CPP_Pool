/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:10:29 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 11:50:11 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void) {
	Animal *array[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
		array[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete array[i];

	Dog dog1;
	dog1.setIdeas("let's go for a walk!", 0);
	Dog dog2 = Dog(dog1);
	dog1.getIdeas(0);
	dog2.getIdeas(0);
	dog1.setIdeas("hungry and sleepy", 0);
	dog1.getIdeas(0);
	dog2.getIdeas(0);
	dog2.getIdeas(1);
	dog2.getIdeas(100);
	return (0);
}


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
