/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:43:31 by rlobun            #+#    #+#             */
/*   Updated: 2026/09/29 16:49:35 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <algorithm>

class bigint 
{
	private:
		std::string s;
	public:
		bigint(): s("0") {}
		explicit bigint(unsigned long long num)
		{
			if (num == 0)
				s = "0";
			else
				while(num)
				{
					s.push_back(static_cast<char>(num % 10 + '0'));
					num /= 10;
				}
		}
		explicit bigint(std::string str) 
		{
			s = (str.find_first_not_of('0') == std::string::npos? "0" : str.substr(str.find_first_not_of('0')));
			std::reverse(s.begin(), s.end());
		}

		bigint(const bigint& o): s(o.s) {}
		bigint& operator=(const bigint& o) {s = o.s; return *this;}
		bigint& operator+=(const bigint& o)
		{
			const size_t osz = o.s.size();
			size_t ssz = this->s.size();
			std::string str = this->s;

			size_t max = (osz > ssz)? osz : ssz;

			size_t carry = 0;

			for (size_t i = 0; i < max || carry; ++i)
			{
				size_t d = carry;

				if (i < ssz)
					d += s[i] - '0';
				if (i < osz)
					d += o.s[i] - '0';
				carry = d / 10;
				char digit = static_cast<char>(d % 10 + '0');
				if (i < ssz)
					str[i] = digit;
				else
					str.push_back(digit);
			}
			this->s = str;
			return *this;
		}
		
		bigint& operator+=(int i) {return (*this += bigint(i));}
		bigint operator+(const bigint& o) const {bigint t(*this); return (t += o);}
		bigint operator+(int i) {bigint t(*this); return (t += i);}

		bigint& operator++() {return *this += 1;}
		bigint operator++(int) {bigint t(*this); ++(*this); return t;}

		bigint& operator<<=(const bigint& o)
		{
			size_t amount = atol(o.s.c_str());
			s.insert(0, amount, '0');
			return *this;
		}

		bigint& operator<<=(const unsigned long i){ s.insert(0, i, '0'); return *this;}
		bigint& operator>>=(const bigint& o)
		{
			size_t amount = atol(o.s.c_str());
			if (amount > s.size())
				s = "0";
			else
				s.erase(0, amount);
			return *this;
		}
		bigint& operator>>=(const unsigned long i) { s.erase(0, i); return *this;}


		bigint operator>>(const bigint& o) {bigint t(*this); t >>= o; return t;}
		bigint operator>>(const int i) {bigint t(*this); t >>= i; return t;}
		bigint operator<<(const bigint& o) {bigint t(*this); t <<= o; return t;}
		bigint operator<<(const int i) {bigint t(*this); return (t <<= i);}

		/* ------------ compare ------------------- */

		bool operator==(const bigint& o) const { return s == o.s;}
		bool operator!=(const bigint& o) const { return s != o.s;}

		bool operator<(const bigint& o) const
		{
			if (s.size() != o.s.size())
				return (s.size() < o.s.size());

			std::string::const_reverse_iterator it_s = s.rbegin();
			std::string::const_reverse_iterator it_os = o.s.rbegin();
			while ( it_s != s.rend())
			{
				if (it_s != it_os)
					return it_s < it_os;
				++it_s;
				++it_os;
			}

			return false;
		}
		bool operator>(const bigint& o) const {return ( o < *this);}
		bool operator<=(const bigint& o) const {return !( *this > o);}
		bool operator>=(const bigint& o) const {return !( *this < o);}
		
		friend std::ostream& operator<<(std::ostream& o, const bigint& b)
		{
			if (b.s.empty())
				o << "0";
			else
			{
				std::string::const_reverse_iterator it = b.s.rbegin();
				std::string::const_reverse_iterator end = b.s.rend();
				while (it != end)
				{
					o << *it;
					it ++;
				}
			}
			return o;
		}
};
