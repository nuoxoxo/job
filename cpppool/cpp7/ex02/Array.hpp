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
/*                                   Array                                    */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#ifndef ARRAY_HPP
#define	ARRAY_HPP

#include "iostream"
#include "cstdlib"
#include "Array.tpp" // obsolete
#include "iomanip" // boolalpha

template<typename T>
class	Array
{
private:
	unsigned int	m_size;
	T		* m_array;

public:
	// canon
	Array();
	~Array();
	Array(const Array &);
	Array & operator = (const Array &);

	// param constr
	Array(const unsigned int &); 
	
	// []
	T & operator [] (unsigned int);	
	T const & operator [] (unsigned int) const ;

	// utils
	unsigned int 	size() const;
	unsigned int 	length() const; // we need 1+ mem fn, not `m_length`
	void		printer() const;
};


/* ************ TPP implementation ************ */

// constr
template<typename T>
Array<T>::Array() : m_size(), m_array(new T[0]) {}


// param constr
template<typename T>
Array<T>::Array(const unsigned int & s) : m_size(s), m_array(new T[s])
{
	unsigned int	i = -1;

	while (++i < s)
	{
		m_array[i] = 0;
	}
}

// destr
template<typename T>
Array<T>::~Array(void)
{
	if (m_array)
		delete [] m_array;
}

// copy constr
template<typename T>
Array<T>::Array(const Array & dummy)
{
	unsigned int	temp = dummy.size(), i = -1;

	m_array = new T[temp];
	m_size = temp;
	while (++i < temp)
		m_array[i] = dummy.m_array[i];
}

// copy assignment
template<typename T>

Array<T> & Array<T>::operator = (const Array & dummy)
{
	unsigned int	size, i;

	if (this == & dummy)
		return (*this);
	if (m_array)
		delete [] m_array;
	size = dummy.size();
	m_array = new T[size];
	m_size = size;
	i = -1;
	while (++i < size)
		m_array[i] = dummy.m_array[i];
	return (*this);
}

// []
template<typename T>
T & Array<T>::operator [] (unsigned int i)
{
	// if (m_size == 0 || i > m_size - 1)
	if (i > m_size - 1)
		throw (std::exception());
	
	if ((int)m_size == 0)
		//std::cout << std::boolalpha << (m_size == 0) << std::noboolalpha << " (&) \n";
		throw (std::exception());
	
	
	// I tried something like this
	/*
	try {return m_array[i];}
	catch (std::exception & e)
	{ std::cout << e.what() << std::endl; }
	return m_array[i];
	*/
	
	return (m_array[i]);
}

template<typename T>
const T & Array<T>::operator [] (unsigned int i) const
{
	if (i > m_size - 1)
		throw (std::exception());
	
	if ((int)m_size == 0)
		//std::cout << std::boolalpha << (m_size == 0) << std::noboolalpha << " (const &) \n";
		throw (std::exception());
	

	return (m_array[i]);
}

// size
template<typename T>
unsigned int Array<T>::size() const
{
	return (m_size);
}

template<typename T>
unsigned int Array<T>::length() const
{
	return (m_size);
}

// printer
template<typename T>
void	Array<T>::printer() const
{
	unsigned int	i;

	if (!m_size)
	{
		std::cout << "[]" << std::endl;
		return ;
	}
	i = -1;
	std::cout << '[';
	while (++i < m_size)
	{
		std::cout << m_array[i] << (i == m_size - 1 ? "] \n" : ", ");
		
		// idem but no ternary
		/*std::cout << m_array[i];
		if (i != m_size - 1)
			std::cout << ", ";
		*/
	}
	// std::cout << ']' << std::endl;
}

template<typename T>
std::ostream & operator << (std::ostream & ostream, const Array<T> & arr)
{
	unsigned int	len = arr.size();
	unsigned int	i = -1;

	if (!len)
	{
		ostream << "[]\n";
		return ostream;
	}
	ostream << '[';
	i = -1;
	while (++i < len)
		ostream << arr[i] << (i == len - 1 ? "] \n" : ", ");
	return ostream;
}

template<typename T>
std::ostream & operator << (std::ostream & ostream, Array<T> & arr)
{
	unsigned int	len = arr.size();
	unsigned int	i = -1;

	if (!len)
	{
		ostream << "[]\n";
		return ostream;
	}
	ostream << '[';
	i = -1;
	while (++i < len)
		ostream << arr[i] << (i == len - 1 ? "] \n" : ", ");
	return ostream;
}


#endif
