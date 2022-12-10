#ifndef TEST_HPP
#define TEST_HPP

#include "../Vector.hpp"
//#include "../List.hpp"
#include "../Stack.hpp"
//#include "../Queue.hpp"
#include "../Map.hpp"
//#include "../Set.hpp"
//#include "../MultiMap.hpp"
//#include "../MultiSet.hpp"
//#include "../Deque.hpp"
#include <iostream>
#include <assert.h>

class ConstrCounter
{
public:
    static int g_constr;
    static int g_destr;

    int val;

    ConstrCounter();
    ConstrCounter(int val);
    ConstrCounter(const ConstrCounter &o);
    ~ConstrCounter();

    static void reset_counters();
};

bool operator==(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator!=(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator<(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator<=(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator>(const ConstrCounter &lhs, const ConstrCounter &rhs);
bool operator>=(const ConstrCounter &lhs, const ConstrCounter &rhs);

void test_one(std::string name, void (&fn)());

void test_vector();
//void test_list();
void test_stack();
//void test_queue();
void test_map();
//void test_set();
//void test_multimap();
//void test_multiset();
//void test_deque();

#endif
