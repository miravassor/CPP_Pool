/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:43:54 by avassor           #+#    #+#             */
/*   Updated: 2023/11/24 12:01:26 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Array.hpp"
#include "Array.cpp"

int main() {
    Array<int>  narr(100);
    Array<int>  narr2(0);
    Array<int>  narr3;

    srand(time(NULL));

    std::cout << "trying to fill narr2:" << std::endl;
    try {
        for (int i = 0; i < 100; i++)
        narr2[i] = (unsigned int)rand();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "trying to fill narr3:" << std::endl;
    try {
        for (int i = 0; i < 100; i++)
        narr2[i] = (unsigned int)rand();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // giving value to narr[0]
    narr[0] = 42;
    std::cout << "printing narr[0] after modif:" << std::endl;
    std::cout << narr[0] << std::endl;

    std::cout << "trying to access out of range index:" << std::endl;
    try {
        std::cout << narr[-2325] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "trying to access out of range index round 2:" << std::endl;
    try {
        std::cout << narr[100] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // veryfying copy operator
    Array<int>  narrCopy = narr;
    // modifying index 0 of original object
    narrCopy[0] = -42;

    std::cout << "printing index 0 of copied object:" << std::endl;
    try {
        std::cout << narrCopy[0] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "printing index 0 of original object:" << std::endl;
    try {
        std::cout << narr[0] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
