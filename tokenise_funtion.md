tokeniseCSV
string csvLine = "thing,thing2,thing3" ##the string we are processing.
string vector tokens ##stores the tokens
char seperator =',' ##the charactor that seperates the tokens
int start,end ##used to delineate the position of the tokens

start = csvLine.find_first_not_of(seperator)

do
    end= next 'seperator' after start
    if start == csvLine.Length or Start == end ##nothing more to find
        break
    if end >= 0 ##e found the seperator
        token = csvLine.substr(start,end-start) ##start substring length
    else
        token = csvLine.substr(start,csvLine.Length-start) ##end is invalied
    tokens.push_back(token) ##save the token
    start = end + 1
while(end>0) ##cotinue the loop codition
    