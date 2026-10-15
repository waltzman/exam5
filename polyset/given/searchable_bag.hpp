/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_bag.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:35:53 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 12:38:07 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_BAG
# define SEARCHABLE_BAG

#include "bag.hpp"

class searchable_bag: virtual public bag
{
	public:
		virtual bool has(int val) const = 0; 
};

#endif
