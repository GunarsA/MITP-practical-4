#include "utils.hpp"

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

    std::cout << "Izvēlieties darbību:\n";
    for (auto action : actions)
    {
        std::cout << "\t" << (int)action.first << ". " << action.second << std::endl;
    }

    eAction result;
    input("Izvēlieties darbību [1-11]: ", (int &)result, [](int x) -> bool
          { return x >= 1 && x <= 11; });
    return result;
}

int main()
{
    cout << "3. PRAKTISKAIS" << endl;
    while (true)
    {
        clearConsole();
        eAction action = promptAction();
        switch (action)
        {
        case eAction::AddProduct:
        {
            break;
        }
        case eAction::OutputProducts:
        {
            break;
        }
        case eAction::SellProduct:
        {
            break;
        }
        case eAction::ProductInfo:
        {
            break;
        }
        case eAction::Top3MostSold:
        {
            break;
        }
        case eAction::Top3LeastSold:
        {
            break;
        }
        case eAction::Top3MostProfit:
        {
            break;
        }
        case eAction::Top3LeastProfit:
        {
            break;
        }
        case eAction::Top3MostExpensive:
        {
            break;
        }
        case eAction::Top3LeastExpensive:
        {
            break;
        }
        case eAction::Exit:
        {
            return 0;
        }
        }
    }
}