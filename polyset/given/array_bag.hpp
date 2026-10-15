/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:44:38 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 11:57:57 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_BAG_HPP
# define ARRAY_BAG_HPP

# include "bag.hpp"

class array_bag : virtual public bag
{
	protected:
		int* data;
		int  size;

	public:
		array_bag();
		array_bag(const array_bag& o);
		array_bag& operator=(const array_bag& o);
		~array_bag();

		void insert(int);
		void insert(int*, int);
		void print() const;
		void clear();
	
};

#endif
