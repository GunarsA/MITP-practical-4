#include "./Product.h"
#include <fstream>
#include <string>
#include <iostream>


Product::Product(const char *name, unsigned int price, unsigned int unitsAvailable, unsigned int unitsSold) :
    price(price), unitsAvailable(unitsAvailable), unitsSold(unitsSold){

    strncpy(this->name, name, NAME_SIZE-1);
    this->name[NAME_SIZE-1]='\0';
}
Product::~Product(){
    
}

void Product::print(){
    std::cout<<
        "Vārds: "<<name<<"\n"<<
        "Cena: "<<price<<"\n"<<
        "Pieejamās vienības: "<<unitsAvailable<<"\n"<<
        "Pārdotās vienības: "<<unitsSold<<"\n";
}


void Product::writeProducts(const std::map<std::string,Product>& products){
    std::ofstream ostream("products.bin", std::ios::binary | std::ios::out);
    if(ostream.is_open()){
        size_t len=products.size();
        ostream.write((char*)(&len), sizeof(size_t));
        for(auto& pair : products){
            const Product &product=pair.second;
            ostream.write(product.name,NAME_SIZE);
            ostream.write((char *)(&(product)), sizeof(Product));
        }

    }else{
        std::cout<<"\n\nNevarēja atvērt failu.\n\n";
    }
    
    ostream.close();
}

void Product::fetchProducts(std::map<std::string,Product>& productRef){
    std::ifstream istream("products.bin", std::ios::binary | std::ios::in);
    if(istream.is_open()){
        productRef.clear();
        size_t productCount;
        istream.read((char*)(&productCount),sizeof(size_t));
        for(size_t i=0;i<productCount;i++){
            char name[NAME_SIZE];
            istream.read(name, NAME_SIZE);
            std::map<std::string,Product>::iterator pr=productRef.emplace(std::pair<std::string, Product>(std::string(name),Product(name))).first;
            istream.read(reinterpret_cast<char *>(&((*pr).second)), sizeof(Product));  
        }

    }else{
        std::cout<<"\n\nNevarēja atvērt failu.\n\n";
    }
    istream.close();
    
}
