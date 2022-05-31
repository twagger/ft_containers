/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:15 by twagner           #+#    #+#             */
/*   Updated: 2022/05/31 13:09:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "RBTree.hpp"

namespace   ft
{
    template < class T >
    class t_iterator 
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            typedef typename ft::iterator_traits<T*>::difference_type          \
                             difference_type;
            typedef typename ft::iterator_traits<T*>::value_type               \
                             value_type;
            typedef typename ft::iterator_traits<T*>::pointer                  \
                             node_ptr;
            typedef typename T::value_type          &reference;
            typedef typename T::value_type          *pointer;
            typedef bidirectional_iterator_tag      iterator_category;
            
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            t_iterator(void) : _p(NULL) {}
            t_iterator(node_ptr x) : _p(x) {}
            t_iterator(const t_iterator &it) : _p(it._p) {}
            ~t_iterator(void) {}
            
            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            t_iterator  &operator=(t_iterator const &rhs)
            { this->_p = rhs._p; return (*this);}

            t_iterator  &operator++(void) 
            { this->_p = this->_p->successor(); return (*this); }
            t_iterator  operator++(int)
            { t_iterator tmp(*this); ++this; return (tmp); }
            t_iterator  &operator--(void)
            { this->_p = this->_p->predecessor(); return (*this);}
            t_iterator  operator--(int)
            { t_iterator tmp(*this); --this; return tmp; }

            bool        operator==(const t_iterator& rhs) const
            { return this->_p == rhs._p; }
            bool        operator!=(const t_iterator& rhs) const
            { return this->_p != rhs._p; }

            reference       operator*(void) { return (this->_p->value); }
            const reference operator*(void) const { return (this->_p->value); }
            pointer         operator->(void) const { return (&this->_p->value);}

        private:
            // member attributes
            node_ptr _p; // pointer to RBNode
    };

    template < class T >
    class t_const_iterator 
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            typedef typename ft::iterator_traits<T*>::difference_type          \
                             difference_type;
            typedef typename ft::iterator_traits<T*>::value_type               \
                             value_type;
            typedef typename ft::iterator_traits<T*>::pointer                  \
                             node_ptr;
            typedef typename T::value_type          &reference;
            typedef typename T::value_type          *pointer;
            typedef bidirectional_iterator_tag      iterator_category;
            
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            t_const_iterator(void) : _p(NULL) {}
            t_const_iterator(node_ptr x) : _p(x) {}
            t_const_iterator(const t_const_iterator &it) : _p(it._p) {}
            ~t_const_iterator(void) {}
            
            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            t_const_iterator  &operator=(t_const_iterator const &rhs)
            { this->_p = rhs._p; return (*this);}

            t_const_iterator  &operator++(void) 
            { this->_p = this->_p->successor(); return (*this); }
            t_const_iterator  operator++(int)
            { t_const_iterator tmp(*this); ++this; return (tmp); }
            t_const_iterator  &operator--(void)
            { this->_p = this->_p->predecessor(); return (*this);}
            t_const_iterator  operator--(int)
            { t_const_iterator tmp(*this); --this; return tmp; }

            bool            operator==(const t_const_iterator& rhs) const
            { return this->_p == rhs._p; }
            bool            operator!=(const t_const_iterator& rhs) const
            { return this->_p != rhs._p; }

            const reference operator*(void) const { return (this->_p->value); }
            pointer         operator->(void) const { return (&this->_p->value);}

        private:
            // member attributes
            node_ptr _p; // pointer to RBNode
    };

}

#endif
