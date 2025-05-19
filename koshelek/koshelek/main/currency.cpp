#include "currency.h"
#include <iostream>
#include <sstream>
using namespace std;

//Purse
void Purse::logHistory(const Currency* curr) {
    std::ostringstream oss;
    oss << curr->getAmount();

    if (dynamic_cast<const Dollar*>(curr)) {
        history.push_back("Added Dollar: " + oss.str());
    }
    else if (dynamic_cast<const Euro*>(curr)) {
        history.push_back("Added Euro: " + oss.str());
    }
    else {
        history.push_back("Added Pound: " + oss.str());
    }
}

void Purse::addCurrency(Currency* curr) {
    currencies.push_back(std::unique_ptr<Currency>(curr));
    logHistory(curr);
}

double Purse::calculateTotal() const {
    double total = 0.0;
    for (const auto& curr : currencies) {
        total += curr->toRubles();
    }
    return total;
}

void Purse::fillRandom(int count) {
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < count; ++i) {
        int choice = rand() % 3;
        double amount = (rand() % 1000) * 0.1 + 1;

        switch (choice) {
        case 0: addCurrency(new Dollar(amount)); break;
        case 1: addCurrency(new Euro(amount)); break;
        case 2: addCurrency(new Pound(amount)); break;
        }
    }
}

void Purse::printHistory() const {
    for (const auto& entry : history) {
        std::cout << entry << "\n";
    }
}

//Dollar
double Dollar::exchangeRate = 75.0;

double Dollar::toRubles() const {
    return amount * exchangeRate;
}

void Dollar::print() const {
    std::cout << amount << " USD";
}

double Dollar::getAmount() const {
    return amount;
}

void Dollar::setExchangeRate(double rate) {
    exchangeRate = rate;
}

//Euro
double Euro::exchangeRate = 85.0;

double Euro::toRubles() const {
    return amount * exchangeRate;
}

void Euro::print() const {
    std::cout << amount << " EUR";
}

double Euro::getAmount() const {
    return amount;
}

void Euro::setExchangeRate(double rate) {
    exchangeRate = rate;
}

//Pound
double Pound::exchangeRate = 100.0;

double Pound::toRubles() const {
    return amount * exchangeRate;
}

void Pound::print() const {
    std::cout << amount << " GBP";
}

double Pound::getAmount() const {
    return amount;
}

void Pound::setExchangeRate(double rate) {
    exchangeRate = rate;
}