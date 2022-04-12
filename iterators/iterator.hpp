/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:15 by twagner           #+#    #+#             */
/*   Updated: 2022/04/12 11:24:29 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace	ft
{
	template < class T >
	class iterator : public std::iterator<std::random_access_iterator_tag, T> 
	{
		public:
			// constructors and destructor
			iterator(void) : _p(NULL) {}
			iterator(T *x) : _p(x) {}
			iterator(const iterator &it) : _p(it._p) {}

			// operators overload  
			iterator	&operator++(void) {++this->_p;return *this;}
			iterator 	operator++(int) {iterator tmp(*this); operator++(); return tmp;}
			iterator	&operator--(void) {--this->_p;return *this;}
			iterator 	operator--(int) {iterator tmp(*this); operator--(); return tmp;}

			bool 		operator==(const iterator& rhs) const {return this->_p == rhs.getIt();}
			bool 		operator!=(const iterator& rhs) const {return this->_p != rhs.getIt();}
			bool 		operator<(const iterator& rhs) const {return this->_p < rhs.getIt();}
			bool 		operator<=(const iterator& rhs) const {return this->_p <= rhs.getIt();}
			bool 		operator>(const iterator& rhs) const {return this->_p > rhs.getIt();}
			bool 		operator>=(const iterator& rhs) const {return this->_p >= rhs.getIt();}

			T			&operator*(void) {return *(this->_p);}
			const T		&operator*(void) const {return *(this->_p);}

			ptrdiff_t	operator-(const iterator& rhs) const {return (this->_p - rhs.getIt());}

			// accessors
			const T		*getIt(void) const {return (this->_p);};

		private:
			T	*_p;
	};

	template < class T >
	class const_iterator : public std::iterator<std::random_access_iterator_tag, T> 
	{
		public:
			// constructors and destructor
			const_iterator(void) : _p(NULL) {}
			const_iterator(T *x) : _p(x) {}
			const_iterator(const const_iterator &it) : _p(it._p) {}

			// operators overload  
			const_iterator	&operator++(void) {++this->_p;return *this;}
			const_iterator 	operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
			const_iterator	&operator--(void) {--this->_p;return *this;}
			const_iterator 	operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}

			bool 		operator==(const const_iterator& rhs) const {return this->_p == rhs.getIt();}
			bool 		operator!=(const const_iterator& rhs) const {return this->_p != rhs.getIt();}
			bool 		operator<(const const_iterator& rhs) const {return this->_p < rhs.getIt();}
			bool 		operator<=(const const_iterator& rhs) const {return this->_p <= rhs.getIt();}
			bool 		operator>(const const_iterator& rhs) const {return this->_p > rhs.getIt();}
			bool 		operator>=(const const_iterator& rhs) const {return this->_p >= rhs.getIt();}

			const T		&operator*(void) const {return *(this->_p);}

			ptrdiff_t	operator-(const const_iterator& rhs) const {return (this->_p - rhs.getIt());}

			// accessors
			const T		*getIt(void) const {return (this->_p);};

		private:
			T	*_p;
	};
}

#endif
