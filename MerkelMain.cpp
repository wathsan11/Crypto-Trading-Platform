#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <limits>


MerkelMain :: MerkelMain()
{

}

void MerkelMain :: init()
{
    //loadOrderBook();
    currentTime = OrderBook.getEarliestTime();

    while (true)
    {

    printMenu();
    int input = getUserOption();
    processUserOption(input);
    }

}

/*void MerkelMain :: loadOrderBook()
{
      orders = CSVReader::readCSV("20200317a.csv");


    // orders.push_back(oderBookEntry {1000,0.01,"01:24.9","BTC/USDT",oderBooktype::ask});
    // oderBookEntry order1{1000,0.01,"01:24.9","BTC/USDT",oderBooktype::ask};
    // oderBookEntry order3{0.02187308,7.44564869," 2020/03/17 17:01:24.884492","ETH/BTC",oderBooktype::bid};
    // oderBookEntry order4{0.02185561,9.14455526,"01:24.9","ETH/BTC",oderBooktype::bid};
    // orders.push_back(order1);
    // orders.push_back(order3);
    // orders.push_back(order4);
}
*/


void MerkelMain :: printMenu()
{
        //1 print help
    std :: cout << "1 : print help" << std :: endl;

    //2 print exchange stats
    std :: cout << "2 : print exchange stats" << std :: endl;

    //3 make an offer
    std :: cout << "3 : make an offer" << std :: endl;

    //4 make a bid
    std :: cout << "4 : make a bid" << std :: endl;

    //5 print wallet
    std :: cout << "5 : print wallet" << std :: endl;

    //6 continue
    std :: cout << "6 : continue" << std :: endl;

    std :: cout << "=============="<< std :: endl;
    std :: cout << "Current time is : "<<currentTime<<std::endl;

}

int MerkelMain :: getUserOption()
{
    std::string line;
    int userOption=0;
    std :: cout << "Type in 1-6"<< std :: endl;
    std::getline(std::cin,line);

    try
     {
        userOption = std::stoi(line);
     }
     catch(const std::exception& e)
     {
        //
     }

    //std :: cin >> userOption;
    std :: cout << "You Choose : "<<userOption << std ::endl;
    
    return userOption;
}


void MerkelMain :: printHelp()
{
    std :: cout << "Help - Your aimm is to make money. Analyse the market and make bids and offers"<< std :: endl;
}

void MerkelMain :: marketStats()
{
    for(std:: string const& p : OrderBook.GetKnownProducts())
    {
        std::cout<<"Product :"<<p<<std::endl;

        std::vector <oderBookEntry> entries = OrderBook.getOrders(oderBooktype::ask,p,currentTime);
        std::cout<<"Asks seen: "<<entries.size()<<std::endl;
        std::cout<<"Max ask: "<<OrderBook::GetHighPrice(entries)<<std::endl;
        std::cout<<"Low ask: "<<OrderBook::GetLowPrice(entries)<<std::endl;
    }


    // std :: cout << "OrderBook contains : "<< orders.size() << " entries."<< std :: endl;
    // unsigned int Bids = 0;
    // unsigned int Asks = 0;

    // for(oderBookEntry& e :orders)
    // {
    //     if(e.orderType==oderBooktype::ask)
    //     {
    //         Asks++;
    //     }
    //     if(e.orderType==oderBooktype::bid)
    //     {
    //         Bids++;
    //     }
    // }
    // std :: cout << "OrderBook asks :"<< Asks << " bids:"<< Bids<<std :: endl;

}

void MerkelMain :: enterAsk()
{
    std :: cout << "Make an Ask - enter the amount: Product,Price,Amount --> Eg:-ETH/BTC,200,0.5 "<< std :: endl;
    std:: string input;

    //std::cin.ignore(std::numeric_limits<std::streamsize>::max() ,'\n');
    std::getline(std::cin,input);

    std::vector<std::string> tokens = CSVReader::tokenise(input,',');
    if(tokens.size()!=3)
    {
        std::cout <<"MerkelMain :: enterAsk Bad input:"<<input <<std::endl;
    }
    else
    {
       try{ oderBookEntry obe = CSVReader::stringTOBE( tokens[1],
                                                   tokens[2],
                                                   currentTime,
                                                   tokens[0],
                                                   oderBooktype::ask
                                                );
            OrderBook.insertorder(obe);
            

          }
          catch(const std::exception& e)
          {
                std::cout<<"MerkelMain :: enterAsk Bad Input :"<<std::endl;

          }
    }
    std::cout <<"You typed :"<<input <<std::endl;
}

void MerkelMain :: enterBid()
{
    std :: cout << "Make a bid - enter the amount"<< std :: endl;

}

void MerkelMain :: printWallet()
{
    std :: cout << "Your wallet is empty"<< std :: endl;
}

void MerkelMain :: gotoNextTimeframe()
{
    std :: cout << "Going to next time frame"<< std :: endl;
    std :: vector <oderBookEntry> sales = OrderBook.matchAsksToBids("ETH/BTC",currentTime);
    std::cout << "Sales: "<<sales.size()<<std::endl;
    for(oderBookEntry& sale : sales)
    {
        std::cout << "Sale price: "<<sale.price<<" amount: "<<sale.amount<<std::endl;
    }
    currentTime = OrderBook.getNextTime(currentTime);
}

void MerkelMain :: processUserOption(int userOption)
{
     if (userOption == 0)
    {
        std :: cout << "Invalid choise. Choose 1-6"<< std :: endl;
    }

    if (userOption == 1)
    {
        printHelp();
    }

    if (userOption == 2)
    {
        marketStats();

    }

    if (userOption == 3)
    {
        enterAsk();
    }

    if (userOption == 4)
    {
        enterBid();
    }

    if (userOption == 5)
    {
        printWallet();
    }

    if (userOption == 6)
    {
       gotoNextTimeframe();
    }
}
