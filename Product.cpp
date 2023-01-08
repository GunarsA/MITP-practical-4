#include "./Product.h"
#include <fstream>
#include <string>


Product::Product(const char *name, unsigned int price, unsigned int unitsAvailable, unsigned int unitsSold) :
    price(price), unitsAvailable(unitsAvailable), unitsSold(unitsSold){

    strncpy(this->name, name, NAME_SIZE-1);
    this->name[NAME_SIZE-1]='\0';
}
Product::~Product(){
    
}

void Product::writeProducts(const std::map<std::string,Product>& products){
    std::ofstream ostream("products.bin", std::ios::binary | std::ios::out);
    std::string len=std::to_string(products.size());
    ostream.write((char*)(&len), sizeof(size_t));
    for(auto& product : products){
        ostream.write(product.first.c_str(),product.first.size());
        ostream.write((char *)(&(product.second)), sizeof(Product));
    }

}

void Product::fetchProducts(std::map<std::string,Product>& productRef){
    std::ifstream istream("products.bin", std::ios::binary | std::ios::in);
    
    //istream.read(reinterpret_cast<char *>(name), sizeof(Product));
}
