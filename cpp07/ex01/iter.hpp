/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:48:57 by mykle             #+#    #+#             */
/*   Updated: 2025/05/26 11:57:41 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T, typename F> void iter(T *array, size_t length, void func(F))
{
	if (!array) return;

	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}
