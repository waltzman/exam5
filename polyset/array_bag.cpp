/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:58:27 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 15:09:06 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_bag.hpp"
#include <iostream>

array_bag::array_bag(): data(0), size(0) {}

array_bag::array_bag(const array_bag& o) 
{
	size = o.size;
	data = new int[size];
	for(int i = 0; i < size; ++i)
		data[i] = o.data[i];
}

array_bag& array_bag::operator=(const array_bag& o)
{
	if (this == &o)
		return *this;
	this->clear();
	size = o.size;
	for (int i = 0; i < size; ++i)
		data[i] = o.data[i];
	return *this;
}

array_bag::~array_bag() 
{
	delete data;
}


void array_bag::insert(int value)
{
	int* tmp = new int[size + 1];
	for(int i = 0; i < size; ++i)
		tmp[i] = data[i];
	tmp[size] = value;
	delete data;
	data = tmp;
	size++;
}

void array_bag::insert(int *array, int ar_size)
{
	for (int i = 0; i < ar_size; ++i)
		insert(array[i]);
}

void array_bag::print() const
{
	for (int i = 0; i < size; ++i)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

void array_bag::clear()
{
	delete data;
	data = 0;
	size = 0;
}
