#pragma once
#include <string>
#include <cstring>

class Product
{
private:
    const static size_t NAME_SIZE=128;
    char name[NAME_SIZE];

    // price in cents
    unsigned int price;

    unsigned int unitsAvailable;

    unsigned int unitsSold;
public:
    Product(const char *name, unsigned int price=0, unsigned int unitsAvailable=0, unsigned int unitsSold=0);
    ~Product();
};

