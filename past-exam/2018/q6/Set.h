#ifndef SET_H
#define SET_H

#include <vector>
#include <initializer_list>
using namespace std;

template <class T>
class Set {
    private:
        vector<T> items;

    public:
        Set();
        Set(initializer_list<T> list);

        bool add(const T& value);
        bool remove(const T& value);
        bool contains(const T& value) const;

        int size() const;
};

#include "Set.cc"

#endif