#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader
{
private:
    
    static oderBookEntry stringTOBE(std::vector<std::string> tokens);

public:
    CSVReader();
    static std::vector<std::string> tokenise (std::string csvLine,char separator);
    static std::vector<oderBookEntry> readCSV(std::string csvFileName);
    static oderBookEntry stringTOBE(std::string product,
                                     std::string price,
                                      std::string amount,
                                      std::string timestamp,
                                      oderBooktype orderType);
};

