/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <nuxu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:37:56 by nuxu              #+#    #+#             */
/*   Updated: 2023/01/25 10:27:54 by nuxu             ###   ########.fr       */
/* ************************************************************************** */

#include "Span.hpp"

// default
Span::Span() : m_maxsize() {}
Span::Span(unsigned int N) : m_maxsize(N) {}
Span::Span(const Span &cp) : m_core(cp.getCore()), m_maxsize(cp.getMaxsize()){}
Span::~Span() {}

// getter
const std::vector<int>	& Span::getCore() const { return m_core; }
unsigned int		Span::getMaxsize() const { return m_maxsize; }

Span & Span::operator = (Span const & dummy)
{
	if (this == & dummy)
		return (*this);
	m_maxsize = dummy.getMaxsize();
	m_core = dummy.getCore();
	return (*this);
}

int	Span::longestSpan() const
{
	if (m_maxsize == 0 || m_core.size() < 2)	
	{
		throw std::exception();
	}
	std::vector<int>	v = m_core;

	std::sort(v.begin(), v.end());
	return (v[v.size() - 1] - v[0]); // TODO to checkk
}

int	Span::shortestSpan() const
{
	if (m_maxsize == 0 || m_core.size() < 2)	
	{
		throw std::exception();
	}

	int			diff = 2147483647, i = 0;
	std::vector<int>	v = m_core;

	std::sort(v.begin(), v.end());
	while (++i < (int) v.size())
	{
		diff = std::min(diff, v[i] - v[i - 1]);
	}
	return (diff);
}

void	Span::addNumber(int num)
{
	if (!m_maxsize || m_maxsize == m_core.size())
		throw std::exception();
	m_core.push_back(num);
}

void	Span::addRandomNumbers(unsigned int n)
{
	if (!m_maxsize || m_maxsize < n)
	{
		throw std::exception();
	}

	srand(time(0));

	while (n)
	{
		m_core.push_back(std::rand() % RAND_MAX);
		n--;
	}
}

/*class	Span
{
private:
	std::vector<int>	m_core;
	int			m_maxsize;
public:
	// canon + param constr
	Span();
	Span(const Span &);
	Span(unsigned int N);
	Span & operator = (const Span & );
	~Span();

	int	shortestSpan(void) const;
	int	longestSpan(void) const;
	void	addNumber(int);

	const unsigned int	getMaxsize() const;
	const std::vector<int>	& getCore() const;
};*/
