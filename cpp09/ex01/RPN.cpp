/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:48:24 by mykle             #+#    #+#             */
/*   Updated: 2025/05/28 19:02:30 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <stdexcept>

static int rpn_mult(int nb1, int nb2) { return nb1 * nb2; }
static int rpn_sub(int nb1, int nb2) { return nb1 - nb2; }
static int rpn_add(int nb1, int nb2) { return nb1 + nb2; }

static int rpn_div(int nb1, int nb2)
{
    if (nb2 == 0)
        throw std::runtime_error("you can't do a division by 0");
    return nb1 / nb2;
}

static void rpn_sign(const char *str, std::stack<int> &stack, int sign(int, int))
{
    if (stack.size() < 2)
        throw std::runtime_error("you can't do a action on less than 2 number");
    int b = stack.top(); stack.pop();
    int a = stack.top(); stack.pop();
    stack.push(sign(a, b));
    if (*(++str) != ' ' && *str != 0)
        throw std::runtime_error("invalid formating");
}

static void _action(const char *index, std::stack<int> &stack)
{
    if (isdigit(*index)) {
		stack.push(*index - '0');
		return;
	}
	switch (*index)
	{
		case '*': rpn_sign(index, stack, rpn_mult); break;
		case '/': rpn_sign(index, stack, rpn_div); break;
		case '+': rpn_sign(index, stack, rpn_add); break;
		case '-': rpn_sign(index, stack, rpn_sub); break;
		case ' ': break;
		default:
			throw std::runtime_error("invalid formating");
	}
}

void rpn(const char *str)
{
    const char     *index = str;
    std::stack<int> stack;

    while (*index) {
        _action(index, stack);
        index++;
    }
    if (stack.size() != 1)
        throw std::runtime_error("invalid formating");
    std::cout << stack.top() << std::endl;
}
