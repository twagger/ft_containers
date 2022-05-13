/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:36:12 by twagner           #+#    #+#             */
/*   Updated: 2022/05/13 18:01:01 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "../iterators/iterator.hpp"
# include "Vector.hpp"

namespace   ft
{
    // Stack
    template < class T, class Container = ft::vector<T> > 
    class stack
    {
        public:
            /* ************************************************************** */
            /* 	MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            typedef Container                               container_type;
            typedef typename Container::value_type          value_type;
            typedef typename Container::size_type           size_type;
            typedef typename Container::reference           reference;
            typedef typename Container::const_reference     const_reference;
            
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            // Constructor
            explicit stack(const container_type &cont = container_type())
            : c(cont) {}
            // Destructor
            ~stack(void) {}
            
            /* ************************************************************** */
            /*  OPERATOR OVERLOADS                                            */
            /* ************************************************************** */
            stack   &operator=(const stack &x) {this->c = x.c;return (*this);};
            
            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Element access
            reference       top(void) {return this->c.back();};
            const_reference top(void) const {return this->c.back();};
            // Capacity
            bool            empty(void) const {return this->c.empty();};
            size_type       size(void) const {return this->c.size();};
            // Modifiers
            void            push(const value_type &val)
            {return this->c.push_back(val);};
            void            pop(void) {return this->c.pop_back();};

        protected:
            // Member object
            container_type  c;
        
        private:
            // Non member function overloads
            friend bool operator==(const ft::stack<T, Container> &lhs, \
                                const ft::stack<T, Container> &rhs)
            { return (lhs.c == rhs.c); }

            friend bool operator!=(const ft::stack<T, Container> &lhs, \
                                const ft::stack<T, Container> &rhs)
            { return (lhs.c != rhs.c); }

            friend bool operator<(const ft::stack<T, Container> &lhs, \
                                const ft::stack<T, Container> &rhs)
            { return (lhs.c < rhs.c); }

            friend bool operator<=(const ft::stack<T, Container> &lhs, \
                                const ft::stack<T, Container> &rhs)
            { return (lhs.c <= rhs.c); }

            friend bool operator>(const ft::stack<T, Container> &lhs, \
                                const ft::stack<T, Container> &rhs)
            { return (lhs.c > rhs.c); }

            friend bool operator>=(const ft::stack<T, Container> &lhs, \
                                const ft::stack<T, Container> &rhs)
            { return (lhs.c >= rhs.c); }
    };
}

#endif
