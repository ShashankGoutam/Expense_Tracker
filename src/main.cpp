#include "ExpenseManager.h"
#include <iostream>

int main() {
    ExpenseManager manager("data/expenses.txt");

    int choice;
    while (true) {
        std::cout << "\n==== Expense Tracker ====\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. List Expenses\n";
        std::cout << "3. Show Total\n";
        std::cout << "4. Monthly Summary\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string date, category;
            double amount;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> date;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            manager.addExpense(Expense(date, category, amount));
        }
        else if (choice == 2) {
            manager.listExpenses();
        }
        else if (choice == 3) {
            manager.showTotal();
        }
        else if (choice == 4) {
            std::string month;
            std::cout << "Enter month (YYYY-MM): ";
            std::cin >> month;
            manager.monthlySummary(month);
        }
        else if (choice == 5) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
