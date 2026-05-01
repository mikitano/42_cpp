/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 10:29:09 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/30 12:07:02 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	private:
		int _rawBits;
		static const int _fracBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};
