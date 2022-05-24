/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:15 by twagner           #+#    #+#             */
/*   Updated: 2022/05/24 10:44:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "RBTree.hpp"

namespace   ft
{
    template < class T > // T = RBNode<key, value>
    class t_iterator 
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            typedef typename T::comb_type               comb_type;
            typedef T                                   *pointer;
            typedef T                                   &reference;
            typedef std::bidirectional_iterator_tag     iterator_category;
            
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            t_iterator(void) : _p(NULL) {}
            t_iterator(pointer x) : _p(x) {}
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

            reference       operator*(void) { return *(this->_p); }
            const reference operator*(void) const { return *(this->_p); }
            comb_type       *operator->(void) const { return (&this->_p->comb); }

        private:
            // member attributes
            pointer _p; // pointer to RBNode
    };

}

#endif
