#pragma once
#include <string>

class GameSales
{
    public :
        int Rank;
        std :: string Name;
        std :: string Platform;
        int Year;
        double Global_Sales;

        GameSales(int rank,std::string name,std :: string platform,int y,double GS);


};
