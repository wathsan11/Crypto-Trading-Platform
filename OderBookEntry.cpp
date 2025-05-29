#include "OrderBookEntry.h"

   oderBookEntry:: oderBookEntry(double p, double a ,std:: string t,std :: string pr,oderBooktype ord)
        :price(p),
         amount(a),
         timestamp( t),
         product(pr),
         orderType(ord)
    {
    
    }


    oderBooktype oderBookEntry:: stringToOrderBookType(std::string s)
    {
     if (s=="ask")
     {
          return oderBooktype::ask;
     }
     if (s== "bid")
     {
          return oderBooktype::bid;
     }
     return oderBooktype::unknown;

    }