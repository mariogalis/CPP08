#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    // Inicialización de la lista con bucle for
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i)
    {
        lst.push_back(i);
    }

    // Inicialización del vector con bucle for
    std::vector<int> vec;
    for (int i = 10; i <= 50; i += 10)
    {
        vec.push_back(i);
    }

    int number_to_find_success = 3; // Número que se encuentra en los contenedores
    int number_to_find_failure = 7; // Número que no se encuentra en los contenedores

    // Prueba exitosa para el vector
    try
    {
        std::vector<int>::const_iterator it_vec = easyfind(vec, number_to_find_success);
        std::cout << "Success: Number " << number_to_find_success << " found in the vector: " << *it_vec << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Vector Success: " << e.what() << std::endl;
    }

    // Prueba fallida para el vector
    try
    {
        std::vector<int>::const_iterator it_vec = easyfind(vec, number_to_find_failure);
        std::cout << "Failure: Number " << number_to_find_failure << " found in the vector: " << *it_vec << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Vector Failure: " << e.what() << std::endl;
    }

    // Prueba exitosa para la lista (array)
    try
    {
        std::list<int>::const_iterator it_lst = easyfind(lst, number_to_find_success);
        std::cout << "Success: Number " << number_to_find_success << " found in the list: " << *it_lst << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "List Success: " << e.what() << std::endl;
    }

    // Prueba fallida para la lista (array)
    try
    {
        std::list<int>::const_iterator it_lst = easyfind(lst, number_to_find_failure);
        std::cout << "Failure: Number " << number_to_find_failure << " found in the list: " << *it_lst << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "List Failure: " << e.what() << std::endl;
    }

    return 0;
}
