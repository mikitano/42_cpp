/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:14:35 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/17 03:23:27 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T* array, const size_t length, F func) {
	if (!array)
		return ;
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename T>
void print(const T& p) {
	std::cout << p << std::endl;
}