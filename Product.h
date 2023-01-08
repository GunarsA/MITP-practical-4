#pragma once
#include <string>
#include <cstring>
#include <map>
#define NAME_SIZE 128
class Product
{
public:
    char name[NAME_SIZE];

    // price in cents
    unsigned int price;

    unsigned int unitsAvailable;

    unsigned int unitsSold;

    Product(const char *name="THIS SHOULDN'T BE VISIBLE", unsigned int price=0, unsigned int unitsAvailable=0, unsigned int unitsSold=0);
    ~Product();

    static void writeProducts(const std::map<std::string,Product>& products);
    static void fetchProducts(std::map<std::string,Product>& productRef);
};

