#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"

int main()
{
    MerkelMain app{};
    app.init();

    //CSVReader ::readCSV("20200317a.csv");


    return 0;   
}

   /*  double price = 5315.647749;
    double  amount = 0.00027634;
    std :: string timestamp{"01:24.9"};
    std :: string product{"BTC/USDT"}; */
    //std :: string orderType{"bid"};

  /*   enum class oderBookType {bid,ask};
    //oderBookType orderType = oderBookType ::ask;

    std :: vector<double> prices;
    std :: vector<double> amounts;
    std::vector<std:: string>timestamps;
    std :: vector<std::string> products;
    std :: vector <oderBookType> orderTypes;

    prices.push_back(500.1);
    amounts.push_back(0.001);
    timestamps.push_back("01:24.9");
    products.push_back("BTC/USDT");
    orderTypes.push_back(oderBookType::bid);

    prices.push_back(5020.1);
    amounts.push_back(0.0021);
    timestamps.push_back("01:24.91");
    products.push_back("BTC/USDT");
    orderTypes.push_back(oderBookType::bid);

    std :: cout <<"prices : "<< prices[0]<< std:: endl;
    std :: cout <<"prices : "<< prices[1];
 */

    /* while (true)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);

    } */

 /* std :: vector <oderBookEntry> orders;


  

    orders.push_back(oderBookEntry {1000,0.01,"01:24.9","BTC/USDT",oderBooktype::ask});
    oderBookEntry order1{1000,0.01,"01:24.9","BTC/USDT",oderBooktype::ask};
    orders.push_back(order1);
   //std :: cout << "The Price is : "<< orders[0].price << std:: endl;

    oderBookEntry order3{0.02187308,7.44564869," 2020/03/17 17:01:24.884492","ETH/BTC",oderBooktype::bid};
    oderBookEntry order4{0.02185561,9.14455526,"01:24.9","ETH/BTC",oderBooktype::bid};

    orders.push_back(order3);
    orders.push_back(order4);

    for(unsigned int i =0; i<orders.size();++i)
    {
        std :: cout << "The Price is : "<< orders.at(i).price << std:: endl;
    }*/
   


