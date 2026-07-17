/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:31:38 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/16 20:10:37 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T& min(const T& a, const T& b) {
	if (a < b)
		return a;
	return b;
}

template <typename T>
const T& max(const T& a, const T& b) {
	if (a > b)
		return a;
	return b;
}