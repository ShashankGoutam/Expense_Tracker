#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include <string>
#include "Expense.h"

class ExpenseManager {
private:
    std::vector<Expense> expenses;
    std::string filename;

    void loadFromFile();
    void saveToFile() const;

public:
    ExpenseManager(const std::string &file);

    void addExpense(const Expense &expense);
    void listExpenses() const;
    void showTotal() const;
    void monthlySummary(const std::string &month) const; 
};

#endif
