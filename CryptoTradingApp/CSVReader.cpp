#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{

}

std::vector<oderBookEntry> CSVReader:: readCSV(std::string csvFileName)
{
    std::vector <oderBookEntry> entries;

    std :: ifstream csvFile{csvFileName};
    std :: string line;

    if (csvFile.is_open())
    {
        while (std::getline(csvFile,line))
        {
            try{
            oderBookEntry obe =stringTOBE(tokenise(line,','));
            entries.push_back(obe);

            }
            catch(const std::exception& e)
            {
                std::cout<<"CSVReader::readCSV bad Data"<<std::endl;
            }
        }//end of while
        
    }
    std:: cout<<"CSVReader : readCSV read "<<entries.size()<<" entries"<<std::endl;

    return entries;
}

std ::vector<std::string> CSVReader :: tokenise (std::string csvLine,char separator)
{
    std ::vector<std::string> tokens;

    signed int start,end;
    std:: string token;
    start = csvLine.find_first_not_of(separator,0);

   do
   {
      end = csvLine.find_first_of(separator,start);
      if(start == csvLine.length() || start == end)
      {
         break;
      }
      if (end >= 0)
      {
         token = csvLine.substr(start,end-start);
      }
      else 
      {
         token = csvLine.substr(start,csvLine.length()-start);
      }

      tokens.push_back(token);
      start = end +1;

   } while (end >0);

    return tokens;
}

oderBookEntry CSVReader :: stringTOBE(std::vector<std::string> tokens)
{
    double price,amount;
    if(tokens.size() != 5)
        {
            std:: cout << "Bad Line"<< std :: endl;
            throw std:: exception {};
        }

        try
        {
            price = std::stod(tokens[3]);
            amount = std :: stod(tokens[4]);
            //std :: cout<< price <<":"<<amount<< std ::endl;

        }
        catch(const std::exception& e)
        {
            std::cout<<"CSVReader :: stringTOBE Bad Float!"<< tokens[3]<<std::endl;
            std::cout<<"CSVReader :: stringTOBE Bad Float!"<< tokens[4]<<std::endl;
            throw;
        }


    oderBookEntry obe{price,amount,tokens[0],tokens[1],
                    oderBookEntry::stringToOrderBookType(tokens[2])};

    return obe;
}

oderBookEntry CSVReader :: stringTOBE( std::string priceString,
                                 std::string amountString,
                                 std::string timestamp,
                                 std::string product,
                                 oderBooktype orderType)
{
    double price,amount;
    try
    {
        price = std::stod(priceString);
        amount = std :: stod(amountString);
        //std :: cout<< price <<":"<<amount<< std ::endl;

    }
    catch(const std::exception& e)
    {
        std::cout<<"CSVReader :: stringTOBE Bad Float!"<< priceString<<std::endl;
        std::cout<<"CSVReader :: stringTOBE Bad Float!"<< amountString<<std::endl;
        throw;
    }

    oderBookEntry obe{  price,
                        amount,
                        timestamp,
                        product,
                        orderType};

    return obe;

}


