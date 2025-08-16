#include "Expense.h"
#include <sstream>

Expense::Expense(std::string d, std::string c, double a) 
    : date(d), category(c), amount(a) {}

std::string Expense::getDate() const { return date; }
std::string Expense::getCategory() const { return category; }
double Expense::getAmount() const { return amount; }

std::string Expense::toString() const {
    std::ostringstream oss;
    oss << date << " | " << category << " | $" << amount;
    return oss.str();
}
