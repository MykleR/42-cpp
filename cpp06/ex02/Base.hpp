/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:20:13 by mykle             #+#    #+#             */
/*   Updated: 2025/05/26 11:29:06 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>

class Base
{
public:
	virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);
