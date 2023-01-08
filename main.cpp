#include "utils.hpp"
#include "Product.h"
#include <map>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

enum class eAction
{
    AddProduct = 1,
    OutputProducts = 2,
    SellProduct = 3,
    ProductInfo = 4,
    Top3MostSold = 5,
    Top3LeastSold = 6,
    Top3MostProfit = 7,
    Top3LeastProfit = 8,
    Top3MostExpensive = 9,
    Top3LeastExpensive = 10,
    Exit = 11
};

eAction promptAction()
{
    std::pair<eAction, std::string> actions[] = {
        {eAction::AddProduct, "Papildināt produktu ar skaitu"},
        {eAction::OutputProducts, "Izvadīt visus produktus uz ekrāna"},
        {eAction::SellProduct, "Pārdot produktu"},
        {eAction::ProductInfo, "Izvadīt datus par produktu"},
        {eAction::Top3MostSold, "Izdrukāt uz ekrāna Top3 visvairāk iztirgotos produktus"},
        {eAction::Top3LeastSold, "Izdrukāt uz ekrāna Top3 vismazāk iztirgotos produktus"},
        {eAction::Top3MostProfit, "Izdrukāt uz ekrāna Top3 tos produktus par kuriem ir visvairāk nopelnīts"},
        {eAction::Top3LeastProfit, "Izdrukāt uz ekrāna Top3 tos produktus par kuriem ir vismazāk nopelnīts"},
        {eAction::Top3MostExpensive, "Izdrukāt uz ekrāna Top3 visdārgākos produktus"},
        {eAction::Top3LeastExpensive, "Izdrukāt uz ekrāna Top3 vislētākos produktus"},
        {eAction::Exit, "Beigt programmu"}};

    cout << "Izvēlieties darbību:\n";
    for (auto action : actions)
    {
        cout << "\t" << (int)action.first << ". " << action.second << endl;
    }

    eAction result;
    input("Izvēlieties darbību [1-11]: ", (int &)result, [](int x) -> bool
          { return x >= 1 && x <= 11; });
    return result;
}

int main()
{
    cout << "3. PRAKTISKAIS" << endl;

    std::map<std::string, Product> products;
    while (true)
    {
        Product::fetchProducts(products);
        clearConsole();
        eAction action = promptAction();
        switch (action)
        {
        case eAction::AddProduct:
        {
            std::string productName;
            unsigned int amount;
            unsigned int price;
            inputLine("Ievadiet produkta nosaukumu: ", productName);
            input("Ievadiet skaitu: ",amount);
            input("Ievadiet cenu (centos): ", price);
            int unitsAdding;
            products[productName] = Product(productName.c_str(),price,amount);
            pauseConsole();
            break;
        }
        case eAction::OutputProducts:
        {
            for(auto& pair : products){
                Product& prod=pair.second;
                prod.print();
                std::cout<<"\n";
            }
            pauseConsole();
            break;
        }
        case eAction::SellProduct:
        {
            std::string productName;
            inputLine("Ievadiet produkta nosaukumu: ", productName);
            if (products.find(productName) == products.end())
            {
                cout << "Produkts \"" << productName << "\" netika atrasts!\n";
                break;
            }
            if (products[productName].unitsAvailable==0)
            {
                cout << "Produkta \"" << productName << "\" pieejamais skaits ir 0!\n";
                break;
            }
            products[productName].unitsAvailable--;
            products[productName].unitsSold++;
            pauseConsole();
            break;
        }
        case eAction::ProductInfo:
        {
            std::string productName;
            inputLine("Ievadiet produkta nosaukumu: ", productName);
            if (products.find(productName) == products.end())
            {
                cout << "Produkts \"" << productName << "\" netika atrasts!\n";
                break;
            }
            products[productName].print();
            pauseConsole();
            break;
        }
        case eAction::Top3MostSold:
        {
            const int TOP_COUNT=3;
            std::vector<Product*> top3vec(TOP_COUNT);
            for(int i=0;i<TOP_COUNT;i++){
                top3vec[i]=nullptr;
            }
            for(auto& pair : products){
                Product* prod=&pair.second;
                for(int i=0;i<TOP_COUNT;i++){
                    if(top3vec[i]==nullptr || top3vec[i]->unitsSold<prod->unitsSold){
                        for(int i2=i+1;i2<TOP_COUNT;i2++){
                            top3vec[i2]=top3vec[i2-1];
                        }
                        top3vec[i]=prod;
                        break;
                    }
                }
            }
            if(top3vec[0]!=nullptr){
                std::cout<<"Pārdotākais:\n";
                top3vec[0]->print();
            }
            if(top3vec[1]!=nullptr){
                std::cout<<"\n\nOtrais pārdotākais:\n";
                top3vec[1]->print();
            }
            if(top3vec[2]!=nullptr){
                std::cout<<"\n\nTrešais pārdotākais:\n";
                top3vec[2]->print();
            }
            pauseConsole();
            break;
        }
        case eAction::Top3LeastSold:
        {
            std::vector<Product> productVec;
            for (auto p : products)
                productVec.push_back(p.second);

            // sort by units sold in ascending order
            std::sort(productVec.begin(), productVec.end(),
                      [](const Product &a, const Product &b) -> bool
                      {
                          return a.unitsSold < b.unitsSold;
                      });

            cout<<"3 vismazāk iztirgotie produkti\n";
            for (int i = 1; i <= 3; i++)
            {
                cout << "Top " << i << ": ";
                if (i <= productVec.size())
                    cout << productVec[i - 1].name;
                cout<<"\n";
            }
            pauseConsole();
            break;
        }
        case eAction::Top3MostProfit:
        {
            std::vector<Product> productVec;
            for (auto p : products)
                productVec.push_back(p.second);

            // sort by (units sold * price) in descending order
            std::sort(productVec.begin(), productVec.end(),
                      [](const Product &a, const Product &b) -> bool
                      {
                          return (a.unitsSold*a.price) > (b.unitsSold*b.price);
                      });

            cout<<"3 produkti, ar kuriem visvairāk nopelnīts\n";
            for (int i = 1; i <= 3; i++)
            {
                cout << "Top " << i << ": ";
                if (i <= productVec.size())
                    cout << productVec[i - 1].name;
                cout<<"\n";
            }
            pauseConsole();
            break;
        }
        case eAction::Top3LeastProfit:
        {
            const int TOP_COUNT=3;
            std::vector<Product*> top3vec(TOP_COUNT);
            for(int i=0;i<TOP_COUNT;i++){
                top3vec[i]=nullptr;
            }
            for(auto& pair : products){
                Product* prod=&pair.second;
                for(int i=0;i<TOP_COUNT;i++){
                    if(top3vec[i]==nullptr||(top3vec[i]->unitsSold*top3vec[i]->price)>(prod->unitsSold*prod->price)){
                        for(int i2=i+1;i2<TOP_COUNT;i2++){
                            top3vec[i2]=top3vec[i2-1];
                        }
                        top3vec[i]=prod;
                        break;
                    }
                }
            }
            if(top3vec[0]!=nullptr){
                std::cout<<"Vismazāk pelnošais:\n";
                top3vec[0]->print();
            }
            if(top3vec[1]!=nullptr){
                std::cout<<"\n\nOtrais vismazāk pelnošais:\n";
                top3vec[1]->print();
            }
            if(top3vec[2]!=nullptr){
                std::cout<<"\n\nTrešais vismazāk pelnošais:\n";
                top3vec[2]->print();
            }
            pauseConsole();
            
            break;
        }
        case eAction::Top3MostExpensive:
        {
            const int TOP_COUNT=3;
            std::vector<Product*> top3vec(TOP_COUNT);
            for(int i=0;i<TOP_COUNT;i++){
                top3vec[i]=nullptr;
            }
            for(auto& pair : products){
                Product* prod=&pair.second;
                for(int i=0;i<TOP_COUNT;i++){
                    if(top3vec[i]==nullptr||(top3vec[i]->price)<(prod->price)){
                        for(int i2=i+1;i2<TOP_COUNT;i2++){
                            top3vec[i2]=top3vec[i2-1];
                        }
                        top3vec[i]=prod;
                        break;
                    }
                }
            }
            if(top3vec[0]!=nullptr){
                std::cout<<"Dārgākais:\n";
                top3vec[0]->print();
            }
            if(top3vec[1]!=nullptr){
                std::cout<<"\n\nOtrais dārgākais:\n";
                top3vec[1]->print();
            }
            if(top3vec[2]!=nullptr){
                std::cout<<"\n\nTrešais dārgākais:\n";
                top3vec[2]->print();
            }
            pauseConsole();
            break;
        }
        case eAction::Top3LeastExpensive:
        {
            std::vector<Product> productVec;
            for (auto p : products)
                productVec.push_back(p.second);

            // sort by price in ascending order
            std::sort(productVec.begin(), productVec.end(),
                      [](const Product &a, const Product &b) -> bool
                      {
                          return a.price < b.price;
                      });

            cout<<"3 vislētākie produkti\n";
            for (int i = 1; i <= 3; i++)
            {
                cout << "Top " << i << ": ";
                if (i <= productVec.size())
                    cout << productVec[i - 1].name;
                cout<<"\n";
            }
            pauseConsole();
            break;
        }
        case eAction::Exit:
        {
            Product::writeProducts(products);
            return 0;
        }
        }
        Product::writeProducts(products);
    }
}