#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

static class nullptr_t
{
    public:
     
        template<class T>
        operator T*() const { return (0); }

       
        template<class C, class T>
        operator T C::*() const { return (0); }

    private:
     
        void operator&() const;

} u_nullptr = {};

namespace ft
{

    template <typename T>
        std::string to_string(T n)
        {
            /* Stream used to convert */
            std::ostringstream ss;
            ss << n;
            return (ss.str());
        }
    

    template <class Arg1, class Arg2, class Result>
        struct binary_function
        {
            /* The first argument type */
            typedef Arg1 first_argument_type;

            /* The second arguement type */
            typedef Arg2 second_argument_type;

            /* The result type */
            typedef Result result_type;
        };
    
  
    template <class T>
        struct less : binary_function<T, T, bool>
        {
            bool operator() (const T& x, const T& y) const { return (x < y); }
        };

   
    template <class T1, class T2>
        struct pair
        {
            public :

                // Member types :

                /* The first template argument type */
                typedef T1 first_type;

                /* The second template argument type */
                typedef T2 second_type;

                // Member variables :

                /* The first value in the pair */
                first_type first;

                /* The second value in the pair */
                second_type second;

            
                pair()
                :
                    first(),
                    second()
                {}

                template<class U, class V>
                    pair (const pair<U, V>& pr)
                    :
                        first(pr.first),
                        second(pr.second)
                    {}

          
                pair (const first_type& a, const second_type& b)
                :
                    first(a),
                    second(b)
                {}

                
                pair& operator= (const pair& pr)
                {
                    if (*this == pr)
                        return (*this);
                    this->first = pr.first;
                    this->second = pr.second;
                    return (*this);
                }
        };
    

    template <class T1, class T2>
        bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
        {
            return (lhs.first == rhs.first && lhs.second == rhs.second);
        }

  
    template <class T1, class T2>
        bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
        {
            return !(lhs == rhs);
        }
    

    template <class T1, class T2>
        bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
        {
            return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
        }

 
    template <class T1, class T2>
        bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
        {
            return !(rhs < lhs);
        }


    template <class T1, class T2>
        bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
        {
            return (rhs < lhs);
        }


    template <class T1, class T2>
        bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
        {
            return !(lhs < rhs);
        }
    

    template <class T1, class T2>
        ft::pair<T1,T2> make_pair(T1 x, T2 y)
        {
            return (ft::pair<T1, T2>(x, y));
        }
    
 
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };

    template <bool is_integral, typename T>
        struct is_integral_res {
            typedef T type;
            static const bool value = is_integral;
            };

 
    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};

    /* @brief is_integral_type for bool. "value is true".*/
    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    /* @brief is_integral_type for char. "value is true".*/
    template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};

    /* @brief is_integral_type for signed char. "value is true".*/
    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    /* @brief is_integral_type for short int. "value is true".*/
    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    /* @brief is_integral_type for int. "value is true".*/
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};

    /* @brief is_integral_type for long int. "value is true".*/
    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    /* @brief is_integral_type for long long int. "value is true".*/
    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    /* @brief is_integral_type for unsigned char. "value is true".*/
    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    /* @brief is_integral_type for unsigned short int. "value is true".*/
    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    /* @brief is_integral_type for unsigned int. "value is true".*/
    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    /* @brief is_integral_type for unsigned long int. "value is true".*/
    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    /* @brief is_integral_type for unsigned long long int. "value is true".*/
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    template <typename T>
        struct is_integral : public is_integral_type<T> { };

    /*  End of is_integral. */


    class random_access_iterator_tag { };

   
    class bidirectional_iterator_tag { };

    class forward_iterator_tag { };


    class input_iterator_tag { };

    class output_iterator_tag { };


    template <bool is_valid, typename T>
        struct valid_iterator_tag_res { typedef T type; const static bool value = is_valid; };
    
  
    template <typename T>
        struct is_input_iterator_tagged : public valid_iterator_tag_res<false, T> { };

    /* Check is_input_iterator_tagged from ft::random_access_iterator_tag */
    template <>
        struct is_input_iterator_tagged<ft::random_access_iterator_tag>
            : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

    /* Check is_input_iterator_tagged from ft::bidirectional_iterator_tag */
    template <>
        struct is_input_iterator_tagged<ft::bidirectional_iterator_tag>
            : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

    /* Check is_input_iterator_tagged from ft::forward_iterator_tag */
    template <>
        struct is_input_iterator_tagged<ft::forward_iterator_tag>
            : public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

    /* Check is_input_iterator_tagged from ft::input_iterator_tag */
    template <>
        struct is_input_iterator_tagged<ft::input_iterator_tag>
            : public valid_iterator_tag_res<true, ft::input_iterator_tag> { };



    template <typename T>
        struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T> { };
    
    /* Check is_ft_iterator_tagged from ft::random_access_iterator_tag */
    template <>
        struct is_ft_iterator_tagged<ft::random_access_iterator_tag>
            : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

    /* Check is_ft_iterator_tagged from ft::bidirectional_iterator_tag */
    template <>
        struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag>
            : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

    /* Check is_ft_iterator_tagged from ft::forward_iterator_tag */
    template <>
        struct is_ft_iterator_tagged<ft::forward_iterator_tag>
            : public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

    /* Check is_ft_iterator_tagged from ft::input_iterator_tag */
    template <>
        struct is_ft_iterator_tagged<ft::input_iterator_tag>
            : public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

    /* Check is_ft_iterator_tagged from ft::output_iterator_tag */
    template <>
        struct is_ft_iterator_tagged<ft::output_iterator_tag>
            : public valid_iterator_tag_res<true, ft::output_iterator_tag> { };

    template <typename T>
    class InvalidIteratorException : public std::exception
    {
        private:
            std::string _msg;
        
        public :
            InvalidIteratorException () throw() { _msg = "Is invalid iterator tag : " + std::string(typeid(T).name()); }
            InvalidIteratorException (const InvalidIteratorException&) throw() {}
            InvalidIteratorException& operator= (const InvalidIteratorException&) throw() {}
            virtual ~InvalidIteratorException() throw() {}
            virtual const char* what() const throw() { return (_msg.c_str()); }
    };

    template <class Iterator> struct iterator_traits
    {
        /* Result of subtracting one iterator from another, from Iterator. */
        typedef typename Iterator::difference_type       difference_type;

        /* Type of the element where iterator point, from Iterator. */
        typedef typename Iterator::value_type            value_type;

        /* Type of a pointer to an element where the iterator point, from Iterator. */
        typedef typename Iterator::pointer               pointer;

        /* Type of a reference where iterator point, from Iterator. */
        typedef typename Iterator::reference             reference;

        /* The iterator category from Iterator. */
        typedef typename Iterator::iterator_category     iterator_category;
    };

    template <class T> struct iterator_traits<T*>
    {
        /* Result of subtracting one iterator from another. */
        typedef ptrdiff_t                       difference_type;

        /* Type of the element where iterator point. */
        typedef T                               value_type;

        /* Type of a pointer to an element where the iterator point. */
        typedef T*                              pointer;

        /* Type of a reference where iterator point. */
        typedef T&                              reference;

        /* The iterator category from Iterator. */
        typedef ft::random_access_iterator_tag  iterator_category;
    };

    template <class T> class iterator_traits<const T*>
    {
        /* Result of subtracting one iterator from another. */
        typedef ptrdiff_t                       difference_type;

        /* Type of the element where iterator point. */
        typedef T                               value_type;

        /* Type of a pointer to an element where the iterator point. */
        typedef const T*                        pointer;

        /* Type of a reference where iterator point. */
        typedef const T&                        reference;

        /* The iterator category from Iterator. */
        typedef ft::random_access_iterator_tag  iterator_category;
    };

 
    template<class InputIterator>
        typename ft::iterator_traits<InputIterator>::difference_type
            distance (InputIterator first, InputIterator last)
        {
            typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
            while (first != last)
            {
                first++;
                rtn++;
            }
            return (rtn);
        }

   
    template <class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&>
        class iterator
        {
            public:
                /* Type of elements pointed. */
                typedef T           value_type;

                /* Type to represent the difference between two iterators. */
                typedef Distance    difference_type;

                /* Type to represent a pointer to an element pointed */
                typedef Pointer     pointer;

                /* Type to represent a reference to an element pointed */
                typedef Reference   reference;

                /* Category of the iterator. */
                typedef Category    iterator_category;
        };

    template <class T>
        class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
        {  
            /* Category of the iterator. */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
            
            /* Type of elements pointed. */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
            
            /* Type to represent the difference between two iterators. */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
            
            /* Type to represent a pointer to an element pointed */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
            
            /* Type to represent a reference to an element pointed */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;
            
            private:
                /* Element pointed by the iterator. */
                pointer _elem;
        };

    template <class Iterator>
    class reverse_iterator
    {
        public:

            /* Iterator's type. */
            typedef Iterator    iterator_type;

            /* Preserves Iterator's category. */
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            
            /* Preserves Iterator's value type. */
            typedef typename ft::iterator_traits<Iterator>::value_type      value_type;
            
            /* Preserves Iterator's difference type. */
            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
            
            /* Preserves Iterator's pointer. */
            typedef typename ft::iterator_traits<Iterator>::pointer     pointer;
            
            /* Preserves Iterator's reference. */
            typedef typename ft::iterator_traits<Iterator>::reference   reference;
      
            reverse_iterator()
            :
                _elem()
            {}

         
            explicit reverse_iterator (iterator_type it)
            :
                _elem(it)
            {}

       
            template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it)
                :
                    _elem(rev_it.base())
                {}

            /* Added to follow subject obligation */
            virtual ~reverse_iterator() {}

            iterator_type base() const
            { return (_elem); }

            reference operator*() const
            {
                iterator_type tmp = _elem;
                return (*(--tmp));
            }

       
            reverse_iterator operator+ (difference_type n) const { return (reverse_iterator(_elem - n)); }

            reverse_iterator& operator++()
            {
                --_elem;
                return (*this);
            }

   
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }

     
            reverse_iterator& operator+= (difference_type n)
            {
                _elem -= n;
                return (*this);
            }

     
            reverse_iterator operator- (difference_type n) const { return (reverse_iterator(_elem + n)); }

            reverse_iterator& operator--()
            {
                ++_elem;
                return (*this);
            }

        
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }

            reverse_iterator& operator-= (difference_type n)
            {
                _elem += n;
                return (*this);
            }

            pointer operator->() const { return &(operator*()); }

        
            reference operator[] (difference_type n) const { return (this->base()[-n - 1]); }

        private:
            iterator_type     _elem;
    };


    template <class Iterator>
        bool operator== (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }

    /* For reverser_iterator == const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator== (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() == rhs.base()); }


    template <class Iterator>
        bool operator!= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }

    /* For reverser_iterator != const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator!= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() != rhs.base()); }


    template <class Iterator>
        bool operator<  (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }

    /* For reverser_iterator < const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator< (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() > rhs.base()); }


    template <class Iterator>
        bool operator<= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }

    /* For reverser_iterator <= const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator<= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() >= rhs.base()); }


    template <class Iterator>
        bool operator> (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.bash()); }

    /* For reverser_iterator > const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator> (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() < rhs.base()); }
 
    template <class Iterator>
        bool operator>= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

    /* For reverser_iterator >= const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator>= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() <= rhs.base()); }


    template <class Iterator>
        reverse_iterator<Iterator> operator+ (
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }

 
    template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator- (
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs) { return (lhs.base() - rhs.base()); }

    /* For reverser_iterator - const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator- (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() - rhs.base()); }

    /* Lexicographical comparison */

    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1) return false;
                else if (*first1 < *first2) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }

    template <class InputIterator1, class InputIterator2, class Compare>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2,
                                        Compare comp)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || comp(*first2, *first1)) return false;
                else if (comp(*first1, *first2)) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }
    
    template <typename T>
    struct BST_Node
    {
        public :

            /* First template argument, the type of stocked value */
            typedef T   value_type;

            value_type value;
            BST_Node* parent;
            BST_Node* left;
            BST_Node* right;

          
            BST_Node ()
            :
                value(),
                parent(u_nullptr),
                left(u_nullptr),
                right(u_nullptr)
            {}

      
            BST_Node (BST_Node* parent = u_nullptr,
                    BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
            :
                value(),
                parent(parent),
                left(left),
                right(right)
            {}
            
        
            BST_Node (const value_type& val, BST_Node* parent = u_nullptr,
                    BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
            :
                value(val),
                parent(parent),
                left(left),
                right(right)
            {}

            BST_Node (const BST_Node& nd)
            :
                value(nd.value),
                parent(nd.parent),
                left(nd.left),
                right(nd.right)
            {}

            virtual ~BST_Node() {}

 
            BST_Node &operator=(const BST_Node& nd)
            {
                if (nd == *this)
                    return (*this);
                
                this->value = nd.value;
                this->parent = nd.parent;
                this->left = nd.left;
                this->right = nd.right;
                
                return (*this);
            }

  
            bool operator==(const BST_Node& nd)
            {
                if (value == nd.value)
                    return (true);
                return (false);
            }
    };

    /* List Node : */
    template <class Data_T>
    struct Doubly_Linked_Node 
    {
        public :

            Doubly_Linked_Node  *prev;
            Doubly_Linked_Node  *next;
            Data_T              data;

            Doubly_Linked_Node()
            :
                prev(u_nullptr),
                next(u_nullptr)
            {}

     
            Doubly_Linked_Node(const Data_T& val)
            :
                prev(u_nullptr),
                next(u_nullptr),
                data(val)
            {}

            Doubly_Linked_Node(const Data_T& val,
                Doubly_Linked_Node *prev, Doubly_Linked_Node *next)
            :
                prev(prev),
                next(next),
                data(val)
            {}
    };


} /* End of namespace */

# endif