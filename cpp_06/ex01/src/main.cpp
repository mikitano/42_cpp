/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:42:51 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/15 18:51:49 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void) {
	Data data;

	data.id = 42;
	data.name = "Pomni";

	Data* ptr = &data;

	uintptr_t	raw = Serializer::serialize(ptr);
	Data*		recovered = Serializer::deserialize(raw);

	std::cout << "=============== Original ===============" << std::endl;
	std::cout << "Pointer: " << ptr << std::endl;
	std::cout << "ID: " << recovered->id << std::endl;
	std::cout << "Name: " << recovered->name << std::endl;

	std::cout << "\n=============== After serialize ===============" << std::endl;
	std::cout << "uintptr_t: " << raw << std::endl;

	std::cout << "\n=============== After deserialize ===============" << std::endl;
	std::cout << "Pointer: " << recovered << std::endl;
	std::cout << "ID: " << recovered->id << std::endl;
	std::cout << "Name: " << recovered->name << std::endl;
	return (0);
}