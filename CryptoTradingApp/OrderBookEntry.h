#pragma once
#include <string>

enum class oderBooktype{bid, ask,unknown,sales};

class oderBookEntry
{
    public:
            double price;
            double amount;
            std:: string timestamp;
            std :: string product;
            oderBooktype orderType;

             oderBookEntry(double p, double a ,std:: string t,std :: string pr,oderBooktype ord);
             static oderBooktype stringToOrderBookType(std::string s);
             static bool compareByTimestamp(oderBookEntry& e1,oderBookEntry& e2)
             {
                return e1.timestamp < e2.timestamp;
             }

             static bool compareByPriceAsc(oderBookEntry& e1,oderBookEntry& e2)
             {
                return e1.price < e2.price;
             }

             static bool compareByPriceDesec(oderBookEntry& e1,oderBookEntry& e2)
             {
                return e1.price > e2.price;
             }

};