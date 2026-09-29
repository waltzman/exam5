/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:11:09 by rlobun            #+#    #+#             */
/*   Updated: 2026/09/15 13:19:29 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class vect2 
{
	private:
		int x;
		int y;
	public:
		vect2(): x(0), y(0) {}
		vect2(const int x, const int y): x(x), y(y) {};
		vect2(const vect2& o): x(o.x), y(o.y) {};
		vect2& operator=(const vect2& o) {x = o.x; y = o.y; return *this;}
		~vect2() {};

		int operator[](const int i) const {return ( i == 0? x: y);}
		int& operator[](const int i) {return (i == 0? x: y);}

		vect2& operator+=(const vect2& o)  {x += o.x; y += o.y; return *this;}
		vect2& operator-=(const vect2& o)  {x -= o.x; y -= o.y; return *this;}
		vect2& operator*=(const int n)  {x *= n; y *= n; return *this;}

		vect2 operator+(const vect2& o) const { return vect2(x + o.x, y + o.y);}
		vect2 operator-(const vect2& o) const { return vect2(x - o.x, y - o.y);}
		vect2 operator*(const int n) const { return vect2(n * x, n * y);}
		
		vect2& operator++() {++x; ++y; return *this;};
		vect2 operator++(int) { vect2 t(*this); ++x, ++y; return(t);};
		vect2& operator--() {--x; --y; return *this;};
		vect2 operator--(int) { vect2 t(*this); --x, --y; return(t);};

		vect2& operator-() {x = -x; y = -y; return *this;}

		bool operator==(const vect2& o) {return ( x == o.x && y == o.y);}
		bool operator!=(const vect2& o) {return !( *this == o);}

		friend vect2 operator*(const int n, const vect2& v) {return vect2(n * v.x, n * v.y);}
		friend std::ostream& operator<<(std::ostream& o, const vect2& v)
		{ return ( o << "{" << v.x << ", " << v.y << "}");}

};

#endif
