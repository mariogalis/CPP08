/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:55:35 by magonzal          #+#    #+#             */
/*   Updated: 2023/11/30 17:55:37 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{

    std::list<int> lst;
    std::vector<int> vec;
    int numOK = 3;
    int numKO = 7; 

    for (int i = 5; i <= 9; i ++)
        vec.push_back(i);

    for (int i = 1; i <= 5; ++i)
        lst.push_back(i);

    /* ------ Prueba Vector ----- */
    try
    {
        std::vector<int>::const_iterator it_vec = easyfind(vec, numOK);
        std::cout << GREEN << "Success: Number " << numOK << " found in the vector: " << *it_vec << std::endl << RESET;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Vector Failure: " << e.what() << std::endl << RESET;
    }

    try
    {
        std::vector<int>::const_iterator it_vec = easyfind(vec, numKO);
        std::cout << GREEN << "Success: Number " << numKO << " found in the vector: " << *it_vec << std::endl << RESET;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Vector Failure: " << e.what() << std::endl << RESET;
    }

    /* ------ Prueba Array ----- */

    try
    {
        std::list<int>::const_iterator it_lst = easyfind(lst, numOK);
        std::cout << GREEN << "Success: Number " << numOK << " found in the list: " << *it_lst << std::endl << RESET;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "List Success: " << e.what() << std::endl << RESET;
    }

    try
    {
        std::list<int>::const_iterator it_lst = easyfind(lst, numKO);
        std::cout << GREEN << "Failure: Number " << numKO << " found in the list: " << *it_lst << std::endl << RESET;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "List Failure: " << e.what() << std::endl << RESET;
    }

    return 0;
}
