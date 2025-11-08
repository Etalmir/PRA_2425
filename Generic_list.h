#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

template <typename T>
class GenericList {
    public:
        virtual void insert(int pos, const T& e) = 0;
        virtual void append(const T& e) = 0;
        virtual void prepend(const T& e) = 0;
        virtual T remove(int pos) = 0;
        virtual T get(int pos) const = 0;
        virtual int search(const T& e) const = 0;
        virtual bool empty() const = 0;
        virtual int size() const = 0;
};

#endif