#include <iostream>
#include <string>
#include <vector>


class Transaction
{
public:
   Transaction();
   void read();
   int get_day();
   double get_amount();
   void print() const;
private:
   int day;
   double amount;
   std::string description;
};

Transaction::Transaction()
{
   day = 0;
   amount = 0.0;
}

void Transaction::read()
{    std:: cout << "amount paid $" ;
    std::cin >> amount;
    std::cin.ignore();
    std:: cout << "Item description:";
    std::getline(std::cin,description);
    std::cout << "Day of Transaction? ";
    std::cin >> day;
    
}

void Transaction::print() const
{
    std::cout << "day:" << day << std::endl;
    std::cout << "amount:" << amount << std::endl;
    std::cout << "description:" << description << std::endl;
}

void print_transactions(const std::vector<Transaction> t)
{
    for(int i=0;i<t.size();i++)
        t[i].print();
}

int main()
{
   std::vector<Transaction> transaction;
   bool more = true;
   while(more)
   {
       Transaction t;
       t.read();
       transaction.push_back(t);
       std::cout << "Enter another (Y/N)";
       char response;
       std::cin >> response;
       if(response != 'y' && response != 'Y')
         more = false;
   }
   print_transactions(transaction);
   return 0;
}
