#include "./Product.h"


Product::Product(const char *name, unsigned int price, unsigned int unitsAvailable, unsigned int unitsSold) :
    price(price), unitsAvailable(unitsAvailable), unitsSold(unitsSold){

    strncpy(this->name, name, NAME_SIZE-1);
    this->name[NAME_SIZE-1]='\0';
}
Product::~Product(){
    
}