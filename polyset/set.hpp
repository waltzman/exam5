/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:36:03 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 15:17:09 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "searchable_array_bag.hpp"

class set
{
	private:
		searchable_bag &bag;
	public:
		set(searchable_bag& b) : bag(b) {};
		set(const set& o) : bag(o.bag) {};
		set& operator=(const set& o)
		{
			if (this != &o)
				bag = o.bag;
			return *this;
		}

		bool has(int value) const {return bag.has(value);}
		void insert(int value) {if !(bag.has(value)) bag.insert(value);}
		void insert(int* arr, int size {for(int i = 0; i < size; ++i) bag.insert(arr[i]);}
		void print()  const { bag.print();}
		void clear() {bag.clear();}

		searchable_bag& get_bag() {return bag} 


};

#endif
