#pragma once
#include <string>

class Product
{
private:
    
    char name[128];

    // price in cents
    unsigned int price;

    unsigned int unitsAvailable;

    unsigned int unitsSold;
public:
    Product(char *name, unsigned int price=0, unsigned int unitsAvailable=0, unsigned int unitsSold=0);
    ~Product();
};

