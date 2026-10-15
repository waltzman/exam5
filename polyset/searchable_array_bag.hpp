/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:00:29 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 15:15:11 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : virtual public array_bag, virtual public searchable_bag
{
	public:
		searchable_array_bag() {}
		searchable_array_bag(const searchable_array_bag& o) : array_bag(o) {}
		searchable_array_bag& operator= (const searchable_array_bag& o)
		{ 
			if (this != &o)
				array_bag::operator=(o);
			return *this;
		}
		~searchable_array_bag() {}

		virtual	bool has(int v) const
		{
			for (int i = 0; i < size; ++i)
				if (v == data[i])
					return true;
			return false;
		}
};

#endif

