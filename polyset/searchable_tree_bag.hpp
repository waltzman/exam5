/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:19:32 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 15:09:41 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

# include "tree_bag.hpp"
# include "searchable_bag.hpp"

class searchable_tree_bag: public tree_bag, public searchable_bag
{
	public:
		searchable_tree_bag() {}
		searchable_tree_bag(const searchable_tree_bag& o) : tree_bag(o) {}
		searchable_tree_bag& operator=(const searchable_tree_bag& o)
		{
			if (this != &o)
				tree_bag::operator=(o);
			return (*this);
		}
		~searchable_tree_bag() {}

		virtual bool has(int val) const
		{
			node* n = tree;
			while(n)
			{
				if (n->value == val)
					return (true);
				if  (val < n->value)
					n = n->l;
				else
					n = n->r;

			}
		}
}

#endif
