/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:38:40 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 13:25:09 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_BAG_HPP
# define TREE_BAG_HPP

#include "bag.hpp"
#include <iostream>

class tree_bag : virtual public bag
{
	protected:
		struct node
		{
			node* l;
			node* r;
			int value;
			node(node* l, node* r, int value) : l(l), r(r), value(value) {}
		};
		node* tree;
	public:
		tree_bag() : tree(0) {}
		tree_bag(const tree_bag& o) 
		{
			tree = copy_node(o.tree);
		}

		tree_bag& operator=(const tree_bag& o)
		{
			if ( this == &o)
				return *this;
			clear();
			tree = copy_node(o.tree);
			return *this;
		}
		~tree_bag() 
		{
			destroy_tree(tree);
		}

		node* extract_tree()
		{
			node* tmp = tree;
			destroy_tree(tree);
			return tmp;
		}

		void set_tree(node* tr)
		{
			destroy_tree(tree);
			tree = tr;
		}

		void clear()
		{
			destroy_tree(tree);
			tree = 0;
		}

		node* copy_node(node *n)
		{
			if (!n)
				return 0;
			return new node(copy_node(n->l), copy_node(n->r), n->value);
		}

		void print_node(node* n) const
		{
			if (!n)
				return ;
			print_node(n->l);
			std::cout << n->value << " ";
			print_node(n->r);
		}

		void print() const
		{
			print_node(tree);
			std::cout << std::endl;
		}

		void destroy_tree(node* n)
		{
			if (!n)
				return ;
			destroy_tree(n->l);
			destroy_tree(n->r);
			delete(n);
		}

		void insert(int value)
		{
			node** n = &(tree);

			while(*n)
			{
				if (value < (*n)->value)
					n = &(*n)->l;
				else
					n = &(*n)->r;
			}
			*n = new node(0,0,value);
		}
		void insert(int* arr, int size)
		{
			for (int i = 0;  i < size; ++i)
				insert(arr[i]);
		}
		




};

#endif


