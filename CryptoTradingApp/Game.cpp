#include <iostream>
#include "GameSales.h"
#include <vector>
#include <fstream>
#include <string>
#include "GameSales.cpp"

std :: vector <std :: string> tokenise(std :: string csvLine,char Seperator)
{
    std :: vector <std :: string > Tokens;
    signed int start, end;
    std :: string token;
    start = csvLine.find_first_not_of(Seperator,0);

    do{

        end = csvLine.find_first_of(Seperator,start);
        if(start== end || start==csvLine.length())
        {
            break;
        }
        if(end >=0)
        {
            token = csvLine.substr(start,end - start);
        }
        else{
            token = csvLine.substr(start,csvLine.length()-start);
        }

        Tokens.push_back(token);
        start=end+1;

    }
    while (end >0);
    

    return Tokens;
}

std :: vector<GameSales> VGSales;

int main()
{
    std :: ifstream CSVF{"vgsales.csv"};
    std :: string line;
    std :: vector<std :: string> tokens;

    if (CSVF.is_open())
    {
        while (std::getline(CSVF,line))
        {
            std :: cout<< "ReadLine ->"<<line<<std::endl;
            tokens = tokenise(line,',');

            if(tokens.size()!=11)
            {
                std::cout<<"BadLine"<<std:: endl;
                continue;
            }

            try{

            int rank = stoi(tokens[0]);
            int year = stoi(tokens[3]);
            double globalS = std :: stod(tokens[10]);
            std::cout<<"Rank : "<<rank<<" "<< "Year : "<<year<<" "<<"Globel_Sales : "<<globalS<<std::endl;

           GameSales temp {rank,tokens[1],tokens[2],year,globalS};
           VGSales.push_back(temp);
           
            }
            catch(const std::exception& e)
            {
                continue;

            }

            // for(std::string&t :tokens)
            // {
            //     std::cout<<t<<std::endl;
            // }
           
        }
        
        CSVF.close();
    }
    else
    {
        std::cout<<"Couldn't open file"<<std:: endl;
    }



    return 0;
}
