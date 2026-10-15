/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:17:24 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 13:30:31 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_bag.hpp"

int main()
{
	tree_bag* tr = new tree_bag();
	int a[] = {2, 4, 6, 20, 1, 15, 2234};
	tr->insert(a, 7);
	tr->print();
	tr->insert(7);
	tr->print();
	tr->insert(-1);
	tr->print();
	tr->insert(5);
	tr->print();
	tr->insert(546635);
	tr->print();
	tr->insert(1);
	tr->print();
	return (0);
}
