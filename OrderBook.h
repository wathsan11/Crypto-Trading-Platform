#include "OrderBookEntry.h"
#include <string>
#include "CSVReader.h"
#include <vector>

class OrderBook
{
private:

    std::vector<oderBookEntry> orders;
    

public:

    /** Construct, readind a csvFile */
    OrderBook(std::string FileName);
    /**Return vector of all products(Currency) in the data set */
    std:: vector<std::string> GetKnownProducts();
    /*Return vector of orders according to thr sent filters */
    std::vector<oderBookEntry> getOrders(oderBooktype type,std::string product,std::string timestamp);

    /** Returns the erliest time in the oerderbook */
    std:: string getEarliestTime();
    /**Returns the next time after the sent time in the orderbook */
    /**if there is no next timestamp, wraps arround to the start */
    std:: string getNextTime(std::string timestamp);

    static double GetHighPrice(std::vector<oderBookEntry>& orders);
    static double GetLowPrice(std::vector<oderBookEntry>& orders);
    void insertorder(oderBookEntry& order); 

    std::vector<oderBookEntry> matchAsksToBids(std::string product,std::string timestamp);

};


