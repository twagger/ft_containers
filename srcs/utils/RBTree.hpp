/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:31 by twagner           #+#    #+#             */
/*   Updated: 2022/05/14 11:04:49 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

namespace   ft
{
    template< class T >
    struct RBNode
    {
        T       _value;
        char    _color;
        RBNode  *_left;
        RBNode  *_right;
        RBNode  *_parent;
    }

    template< class T, class Compare >
    class RBTree
    {
        public:
            // Constructor & destructir
            RBTree(void) {}
            RBTree(const RBTree &src);
            ~RBTree(void) {}

            // Operator overload
            RBTree  &operator=(const RBTree &rhs);

            // Member functions
            // insert
            // delete
            // search
            // rot left
            // rot right

        private:
            RBNode<T>   *_root;            
    }
}

#endif
