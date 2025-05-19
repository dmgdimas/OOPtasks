#ifndef _CURRENCY_H
#define _CURRENCY_H
#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <string>


class Currency {
public:
    virtual ~Currency() = default;
    virtual double toRubles() const = 0;
    virtual void print() const = 0;
    virtual double getAmount() const = 0;
};

class Dollar : public Currency {
public:
    Dollar(double amt) : amount(amt) {}

    double toRubles() const override;

    void print() const override;

    double getAmount() const override;

    static void setExchangeRate(double rate);

private:
    double amount;
    static double exchangeRate;
};



class Euro : public Currency {
public:
    Euro(double amt) : amount(amt) {}

    double toRubles() const override;

    void print() const override;

    double getAmount() const override;

    static void setExchangeRate(double rate);

private:
    double amount;
    static double exchangeRate;
};



class Pound : public Currency {
public:
    Pound(double amt) : amount(amt) {}

    double toRubles() const override;

    void print() const override;

    double getAmount() const override;

    static void setExchangeRate(double rate);

private:
    double amount;
    static double exchangeRate;
};



class Purse {
public:
    void addCurrency(Currency* curr);
    double calculateTotal() const;
    void fillRandom(int count);
    void printHistory() const;
private:
    std::vector<std::unique_ptr<Currency>> currencies;
    std::vector<std::string> history;

    void logHistory(const Currency* curr);
};

#endif
