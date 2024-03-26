#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initBalance) : accountNumber(accNum), balance(initBalance), interestRate(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Внесено: " << amount << " руб.\n";
        }
        else {
            std::cout << "Ошибка: некорректная сумма для внесения\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Снято: " << amount << " руб.\n";
        }
        else {
            std::cout << "Ошибка: некорректная сумма для снятия или недостаточно средств\n";
        }
    }

    void transfer(BankAccount& toAccount, double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            toAccount.balance += amount;
            std::cout << "Перевод выполнен успешно: " << amount << " руб\n";
        }
        else {
            std::cout << "Ошибка: недостаточно средств на счете для перевода или некорректная сумма\n";
        }
    }

    double getBalance() {
        return balance;
    }

    void setInterestRate(double newRate) {
        interestRate = newRate;
        std::cout << "Процентная ставка обновлена: " << newRate * 100 << "%\n";
    }

    double getInterest() {
        return balance * interestRate * (1.0 / 12);
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    BankAccount account1(12345, 1000.0);
    BankAccount account2(54321, 500.0);

    int accountChoice;
    double amount;

    while (true) {
        std::cout << "Выберите счет для работы:\n";
        std::cout << "1. Счет 1\n";
        std::cout << "2. Счет 2\n";
        std::cout << "3. Выйти из программы\n";

        std::cin >> accountChoice;

        if (accountChoice == 1) {
            std::cout << "Баланс счета 1: " << account1.getBalance() << " руб\n";
        }
        else if (accountChoice == 2) {
            std::cout << "Баланс счета 2: " << account2.getBalance() << " руб\n";
        }
        else if (accountChoice == 3) {
            std::cout << "Программа завершена\n";
            break;
        }
        else {
            std::cout << "Некорректный выбор счета\n";
            continue;
        }

        int choice;
        std::cout << "Выберите операцию:\n";
        std::cout << "1. Перевод средств\n";
        std::cout << "2. Внесение средств\n";
        std::cout << "3. Выйти в меню выбора счета\n";

        std::cin >> choice;

        if (choice == 1) {
            if (accountChoice == 1) {
                std::cout << "Введите сумму для перевода со счета 1 на счет 2: ";
                std::cin >> amount;
                account1.transfer(account2, amount);
            }
            else if (accountChoice == 2) {
                std::cout << "Введите сумму для перевода со счета 2 на счет 1: ";
                std::cin >> amount;
                account2.transfer(account1, amount);
            }
        }
        else if (choice == 2) {
            if (accountChoice == 1) {
                std::cout << "Введите сумму для внесения на счет 1: ";
                std::cin >> amount;
                account1.deposit(amount);
            }
            else if (accountChoice == 2) {
                std::cout << "Введите сумму для внесения на счет 2: ";
                std::cin >> amount;
                account2.deposit(amount);
            }
        }
        else if (choice == 3) {
            std::cout << "Возвращаемся в меню выбора счета\n";
        }
        else {
            std::cout << "Некорректный выбор операции\n";
        }
    }

    return 0;
}
