/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 23:21:31 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/18 02:59:14 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#define MAX_VAL 750

int main(int, char**)
{
	std::cout << "===== TESTE DO PDF (alteradinho) =====" << std::endl;
    srand(time(NULL));
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	std::cout << "Criando Array<int> com " << MAX_VAL << " elementos..." << std::endl;
	std::cout << "Criando array espelho..." << std::endl;

	std::cout << "Preenchendo os dois arrays com valores aleatórios..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	std::cout << "OK!" << std::endl;

    //SCOPE
	std::cout << "\n===== TESTE COPY CONSTRUCTOR =====" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << "Copy constructor chamado duas vezes com sucesso." << std::endl;
    }

	std::cout << "\n===== TESTE COMPARAÇÃO =====" << std::endl;
	std::cout << "Comparando Array e mirror..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << "Todos os valores são iguais!" << std::endl;

	std::cout << "\n===== TESTE EXCEÇÕES =====" << std::endl;
    try
    {
		std::cout << "Acessando índice -2..." << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
		std::cout << "Exceção capturada: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
    }
    try
    {
		std::cout << "Acessando índice " << MAX_VAL << "..." << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
		std::cout << "Exceção capturada: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
    }

	std::cout << "\nAlterando todos os elementos do Array..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << "OK!" << std::endl;
	
    delete [] mirror;

	{
		std::cout << "\n===== EXTRA TEST: SIZE =====\n";
		Array<int> a(5);
		std::cout << a.size() << std::endl;
	}
	{
		std::cout << "\n===== EXTRA TEST: EMPTY =====" << std::endl;
		Array<int> empty;
		std::cout << empty.size() << std::endl;
	}
	{
		std::cout << "\n===== EXTRA TEST: OPERATOR =====" << std::endl;
		Array<int> a(3);
		a[0] = 10;
		a[1] = 20;
		a[2] = 30;
		
		Array<int> b;
		b = a;

		std::cout << b[0] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << b[2] << std::endl;
	}
	{
		std::cout << "\n===== EXTRA TEST: DEEP COPY =====" << std::endl;
		Array<int> a(3);
		a[0] = 10;
		Array<int> b(a);

		std::cout << "Original:" << std::endl;
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;

		b[0] = 42;

		std::cout << "\nAfter Copy:" << std::endl;
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;
	}
	{
		std::cout << "\n===== EXTRA TEST: STRING =====" << std::endl;
		Array<std::string> circus(3);
		circus[0] = "Caine";
		circus[1] = "Jax";
		circus[2] = "Pomni";

		for (unsigned int i = 0; i < circus.size(); i++)
			std::cout << circus[i] << std::endl;
	}
	{
		std::cout << "\n===== EXTRA TEST: EMPTY EXCEPTION =====" << std::endl;
		Array<int> empty;
		try {
			empty[0];
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
    return 0;
}