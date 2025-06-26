#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
    public:
        MerkelMain();
        void init();

    private :
        //void loadOrderBook();
        void printMenu();
        int getUserOption();
        void printHelp();
        void marketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void processUserOption(int userOption);

        std :: string currentTime;


        //std :: vector <oderBookEntry> orders;
        OrderBook OrderBook{"test.csv"};


};