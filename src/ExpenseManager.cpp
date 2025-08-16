#include "ExpenseManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

ExpenseManager::ExpenseManager(const std::string &file) : filename(file) {
    loadFromFile();
}

void ExpenseManager::loadFromFile() {
    std::ifstream in(filename);
    if (!in) return; // file may not exist yet

    std::string date, category;
    double amount;
    while (in >> date >> category >> amount) {
        expenses.emplace_back(date, category, amount);
    }
}

void ExpenseManager::saveToFile() const {
    std::ofstream out(filename);
    for (const auto &e : expenses) {
        out << e.getDate() << " "
            << e.getCategory() << " "
            << e.getAmount() << "\n";
    }
}

void ExpenseManager::addExpense(const Expense &expense) {
    expenses.push_back(expense);
    saveToFile();
}

void ExpenseManager::listExpenses() const {
    std::cout << "---- All Expenses ----\n";
    for (const auto &e : expenses) {
        std::cout << e.toString() << "\n";
    }
}

void ExpenseManager::showTotal() const {
    double total = 0;
    for (const auto &e : expenses) {
        total += e.getAmount();
    }
    std::cout << "Total Spent: $" << std::fixed << std::setprecision(2) << total << "\n";
}

void ExpenseManager::monthlySummary(const std::string &month) const {
    double total = 0;
    std::cout << "---- Summary for " << month << " ----\n";
    for (const auto &e : expenses) {
        if (e.getDate().substr(0, 7) == month) {
            std::cout << e.toString() << "\n";
            total += e.getAmount();
        }
    }
    std::cout << "Total for " << month << ": $" << total << "\n";
}
