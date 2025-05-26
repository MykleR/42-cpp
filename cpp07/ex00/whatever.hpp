/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:44:54 by mykle             #+#    #+#             */
/*   Updated: 2025/05/26 11:45:56 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<class T> void	swap(T &a, T& b)
{
	T c = a;
	a = b;
	b =  c;
}

template<class T> T max(T a, T b)
{
	return ((a > b) ? a:b);
}

template<class T> T min(T a, T b)
{
	return ((a < b) ? a:b);
}
