#include "OrderBook.h"
#include "CSVReader.h"
#include <map>
#include <algorithm>


OrderBook::OrderBook(std::string FileName)
{
    orders = CSVReader::readCSV(FileName);

}
   
std:: vector<std::string> OrderBook::GetKnownProducts()
{
    std::vector<std::string> products;
    std::map<std::string,bool> prodMap;

    for(oderBookEntry& e:orders)
    {
        prodMap[e.product]=true;
    }

    for(auto const& e:prodMap)
    {
        products.push_back(e.first);
    }

    return products;
}

std::vector<oderBookEntry> OrderBook::getOrders(oderBooktype type,std::string product,std::string timestamp)
{
    std::vector<oderBookEntry> orders_sub;

    for (oderBookEntry e: orders)
    {
        if(e.orderType == type && e.product== product && e.timestamp==timestamp)
        {
            orders_sub.push_back(e);
        }
    }

    return orders_sub;
}

double OrderBook:: GetHighPrice(std::vector<oderBookEntry>& orders)
{
    double max = orders[0].price;
    for(oderBookEntry& p : orders)
    {
        if(p.price>max)
        {
            max = p.price;
        }

    }

    return max;
}

double OrderBook:: GetLowPrice(std::vector<oderBookEntry>& orders)
{
    double low = orders[0].price;
    for(oderBookEntry& e : orders)
    {
        if(e.price<low)
        {
            low = e.price;
        }
    }
    return low;
}

std:: string OrderBook:: getEarliestTime()
{
    return orders[0].timestamp;
}

std:: string OrderBook::getNextTime(std::string timestamp)
{
    std:: string next_timestamp="";
    for(oderBookEntry& e : orders)
    {
        if(e.timestamp>timestamp)
        {
            next_timestamp = e.timestamp;
            break;

        }
        if(next_timestamp=="")
        {
            next_timestamp = orders[0].timestamp;
        }

    }
    return next_timestamp;
}

void OrderBook:: insertorder(oderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(),orders.end(),oderBookEntry::compareByTimestamp);
}



std::vector<oderBookEntry>  OrderBook:: matchAsksToBids(std::string product,std::string timestamp)
{
    //     asks = Orderbook.asks
    std:: vector<oderBookEntry> asks = getOrders(oderBooktype::ask,product,timestamp);
    // bids = OrderBook.asks
    std:: vector<oderBookEntry> bids = getOrders(oderBooktype::bid,product,timestamp);
    // sales = []
    std::vector<oderBookEntry> sales;
    // sort asks lowest first
    std::sort(asks.begin(),asks.end(),oderBookEntry::compareByPriceAsc);
    // sort bids highest first
    std::sort(bids.begin(),bids.end(),oderBookEntry::compareByPriceDesec);

    // for ask in asks:
    for(oderBookEntry& ask : asks)
    {
    //     for bid in bids:
        for(oderBookEntry& bid :bids)
        {
    //             if bid.Price >= ask.Price # we have a match
            if (bid.price >= ask.price)
            {
    //             sale = new order()
    //             sale.Price = ask.Price
                oderBookEntry sale{ask.price,0,timestamp,product,oderBooktype::sales};
    //             # now workout how much was sold and crete new bids and asks covering anything that was not sold
//                 if bid.amount == ask.amount: # bid completely clears the ask

                if (bid.amount== ask.amount)
                {
    //                     sale.amount = ask.amount
                    sale.amount = ask.amount;                
    //                     sales.append(sale)
                    sales.push_back(sale);
    //                     bid.amount = 0 # make the bid not processed again
                    bid.amount=0;
    //                     # can do no more with ask
    //                     # go on to next ask
    //                     break
                    break;
                }


    //                 if bid.amount > ask.amount: # ask is completely gone. slice the bid
                if(bid.amount > ask.amount)
                {
    //                     sale.amount = ask.amount
                    sale.amount= ask.amount;
    //                     sales.append(sale)
                    sales.push_back(sale);
    //                     # we adjust the bid in place so it can be used to process the next ask
    //                     bid.amount = bid.amount - ask.amount
                    bid.amount = bid.amount-ask.amount;
    //                     # ask is completely gone, so go to next ask
    //                     break
                    break;
                }


    //                 if bid.amount < ask.amount: # bid is completely gone, slice the ask
                if (bid.amount < ask.amount)
                {
    //                     sale.amount = bid.amount
                    sale.amount=bid.amount;
    //                     sales.appent(sale)
                    sales.push_back(sale);
    //                     # update the ask and allow futher bids to process the remaining amount
    //                     ask.amount = ask.amount - bid.amount
                    ask.amount = ask.amount - bid.amount;
    //                     bid.amount = 0 # make sure bid is not processed again
                    bid.amount = 0;
    //                     # some ask remains. so go to the next bid
    //                     continue
                    continue;
                }

                
            }

        }

    }
    return sales;
}