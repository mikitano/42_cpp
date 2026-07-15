/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 03:10:01 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/15 03:20:25 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& rhs);
		~Serializer();
	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};