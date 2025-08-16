#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
private:
    std::string date;      
    std::string category;  
    double amount;

public:
    Expense(std::string d, std::string c, double a);

    std::string getDate() const;
    std::string getCategory() const;
    double getAmount() const;

    std::string toString() const;
};

#endif
