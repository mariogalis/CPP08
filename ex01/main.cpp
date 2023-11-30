/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:54:58 by magonzal          #+#    #+#             */
/*   Updated: 2023/11/30 17:55:07 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
    try 
    {
        Span span(8);

        span.addNumber(10);
        span.addNumber(3);
        span.addNumber(8);
        span.addNumber(12);
        span.addNumber(5);

        std::vector<int> nums;
        nums.push_back(15);
        nums.push_back(2);
        nums.push_back(9);
        //nums.push_back(9);
   
        span.addNumber(nums.begin(), nums.end());

        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << span.longestSpan() << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

/*
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
*/
