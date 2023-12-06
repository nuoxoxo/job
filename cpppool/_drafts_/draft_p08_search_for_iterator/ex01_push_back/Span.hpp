/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                             ~  ~  ~  ~  ~    ~                             */
/*                              ~    _ ~ _   o>                               */
/*                             ~  \ / \ / \ /  ~                              */
/*                              ~  ~      ~    ~                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                 Template                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#ifndef SPAN_HPP
# define SPAN_HPP

#include "iostream"
#include "vector"
#include "algorithm"
#include "cstdlib" // srand . RAND_MAX


class	Span
{
private:
	std::vector<int>	m_core;
	unsigned int		m_maxsize;
public:
	// canon + param constr
	Span();
	Span(const Span &);
	Span(unsigned int N);
	Span & operator = (const Span & );
	~Span();

	// methods
	int	shortestSpan(void) const;
	int	longestSpan(void) const;
	void	addNumber(int);

	// int	gen(void) const;
	void	addRandomNumbers(unsigned int);

	// getter
	const std::vector<int>	& getCore() const;
	unsigned int		getMaxsize() const;
};

#endif
