#include <iostream>
#include <string>
#include <vector>

enum class oderBookType {bid ,ask };

class OrderBookEntry   // this is the name of the class
{
    public:
        double price;
        double amount;
        std ::string timestamp;
        std ::string product;
        oderBookType type;

     OrderBookEntry(double _price, double _amount, std:: string _timestamp, std:: string _product, oderBookType _type)
        :   price(_price),
            amount(_amount),
            timestamp(_timestamp),
            product(_product),
            type(_type)
    {}

};

    double computeAveragePrice(std::vector<OrderBookEntry>& entries )
    {
        double total =0;
        for(int i=0;i<entries.size();++i)
        {
            total = total + entries[i].price;
        }
        double AvgPrice = total/entries.size();

        return AvgPrice;
    }

    double computeLowPrice(std::vector<OrderBookEntry>& entries)
    {
        double LowPrice= entries[0].price;
        for(int i=0;i<entries.size();++i)
        {
            if(entries[i].price < LowPrice)
            {
                LowPrice = entries[i].price;
            }
        }

        return LowPrice;
    }

    double computeHighPrice(std::vector<OrderBookEntry>& entries)
    {
        double HighPrice = entries[0].price;
            for(int i=0;i<entries.size();++i)
            {
                if(entries[i].price > HighPrice)
                {
                    HighPrice = entries[i].price;
                }
            }
            return HighPrice;
    }

double computePriceSpread(std::vector<OrderBookEntry>& entries)
{
    return computeHighPrice(entries)-computeLowPrice(entries);
}

int main()
{
    OrderBookEntry obe1{0.02187308,7.44564869," 2020/03/17 17:01:24.884492","ETH/BTC",oderBookType::bid};
    OrderBookEntry obe2{0.02185561,9.14455526,"01:24.9","ETH/BTC",oderBookType::bid};

    std::vector <OrderBookEntry> entries;
    entries.push_back(obe1);
    entries.push_back(obe2);

    //std :: cout << "The price is "<< entries[0].price << std :: endl;
    for(OrderBookEntry& obe : entries)
    {
        std::cout << "The price is " << obe.price << std :: endl;
    }


   std :: cout << "AvgPrice : " << computeAveragePrice(entries)<< std :: endl;
   std :: cout << "LowPrice : " << computeLowPrice(entries) << std :: endl;
   std :: cout << "HighPrice : " << computeHighPrice(entries) << std :: endl;
   std :: cout << "Price Spread: " << computePriceSpread(entries)<< std :: endl;







    return 0;
}