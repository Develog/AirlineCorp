#ifndef MONEY_H
#define MONEY_H


class Money
{
    public:
        Money();
        ~Money();

        void setMoney(int quantity);
        int getMoney();

        void addFlightIncome(int flightIncome);
        void setFlightIncome(int flightIncome);
        int getFlightIncome();

        void setCost(int cost);

    private:
        int _money, _flightIncome;
};

#endif // MONEY_H
