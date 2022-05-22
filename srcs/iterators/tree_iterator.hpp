/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:15 by twagner           #+#    #+#             */
/*   Updated: 2022/05/22 09:29:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "RBTree.hpp"

namespace   ft
{
    template < class T, class Compare >
    class t_iterator 
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            typedef typename ft::RBNode<T>          *pointer;
            typedef typename ft::RBNode<T>          &reference;
            typedef std::bidirectional_iterator_tag iterator_category;
            
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
            { this = this->_successor(); return (*this); }
            t_iterator  operator++(int)
            { t_iterator tmp(*this); this = this->_successor; return (tmp); }
            // t_iterator    &operator--(void) {--this->_p;return *this;}
            // t_iterator    operator--(int)
            // { t_iterator tmp(*this); --this->_p; return tmp; }

            bool        operator==(const t_iterator& rhs) const
            { return this->_p == rhs._p; }
            // bool            operator!=(const iterator& rhs) const
            // { return this->_p != rhs._p; }

            // reference       operator*(void) {return *(this->_p);}
            // const reference operator*(void) const {return *(this->_p);}
            T   *operator->(void) const {return (&this->_p->key);}

        private:
            // member attributes
            pointer _p; // pointer to RBNode<T>

            // Predecessor
            t_iterator  &_predecessor(void)
            {
                pointer found;

                if (this->_p->child[RIGHT])
                {
                    found = this->_p->child[RIGHT];
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    if (Compare(found->key, this->_p->key))
                        return (t_iterator(found));
                }
                if (this->child[LEFT])
                {
                    found = this->_p->child[LEFT];
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    if (Compare(found->key, this->_p->key))
                        return (t_iterator(found));
                }
                if (this->parent)
                {
                    found = this->_p;
                    while (found = found->parent)
                    {
                        if (Compare(found->key, this->_p->key))
                            return (t_iterator(found));
                    }
                }
                return (t_iterator(NULL));
            }

            // Successor
            t_iterator  &_successor(void)
            {
                pointer found;

                if (this->_p->child[RIGHT])
                {
                    found = this->_p->child[RIGHT];
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    if (Compare(this->_p->key, found->key))
                        return (t_iterator(found));
                }
                if (this->_p->child[LEFT])
                {
                    found = this->_p->child[LEFT];
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    if (Compare(this->_p->key, found->key))
                        return (t_iterator(found));
                }
                if (this->_p->parent)
                {
                    found = this->_p;
                    while (found = found->parent)
                    {
                        if (Compare(this->_p->key, found->key))
                            return (t_iterator(found));
                    }
                }
                return (t_iterator(NULL));
            }
    };

}

#endif
