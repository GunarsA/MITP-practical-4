#include "utils.hpp"
#include "Product.h"
#include <map>

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
    std::map<std::string, Product> products;
    cout << "3. PRAKTISKAIS" << endl;
    while (true)
    {
        clearConsole();
        eAction action = promptAction();
        switch (action)
        {
        case eAction::AddProduct:
        {
            std::string productName;
            input("Ievadiet produkta nosaukumu: ", productName);
            int unitsAdding;
            // TODO (O.P.): pabeigt šo ig
            break;
        }
        case eAction::OutputProducts:
        {
            // TODO (O.P.)
            break;
        }
        case eAction::SellProduct:
        {
            std::string productName;
            input("Ievadiet produkta nosaukumu: ", productName);
            // TODO (K.P.):
            break;
        }
        case eAction::ProductInfo:
        {
            std::string productName;
            input("Ievadiet produkta nosaukumu: ", productName);
            // TODO (O.P.)
            break;
        }
        case eAction::Top3MostSold:
        {
            // TODO (O.P.)
            break;
        }
        case eAction::Top3LeastSold:
        {
            // TODO (K.P.)
            break;
        }
        case eAction::Top3MostProfit:
        {
            // TODO (K.P.)
            break;
        }
        case eAction::Top3LeastProfit:
        {
            // TODO (O.P.)
            break;
        }
        case eAction::Top3MostExpensive:
        {
            // TODO (O.P.)
            break;
        }
        case eAction::Top3LeastExpensive:
        {
            // TODO (K.P.)
            break;
        }
        case eAction::Exit:
        {
            // TODO (O.P.)
            return 0;
        }
        }
    }
}