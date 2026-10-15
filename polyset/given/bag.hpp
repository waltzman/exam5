/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:37:24 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/15 13:28:59 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_HPP
# define BAG_HPP
	
class bag
{
	public:
		virtual void insert(int) = 0;
		virtual void insert(int*, int) =  0;
		virtual void print() const = 0;
		virtual void clear() = 0;
};
	
#endif
