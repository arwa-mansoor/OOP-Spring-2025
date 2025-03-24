#include <iostream>
using namespace std;

class Account
{
	protected:	
		int accountNumber;
		float balance;
		string accountHolderName;
		string accountType;
		
	public:	
		Account(int accountNumber, float balance, string accountHolderName, string accountType) : 
		accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName), accountType(accountType){}
		
		virtual void deposit(float amount)
		{
			balance += amount;
			cout << "Amount " << amount << " deposited successfuly\n";
		}
		
		virtual void withdraw(float amount)
		{
			if(balance < amount)
			{
				cout << "Not enough money\n";
				return;
			}
			balance -= amount;
		}
		
		virtual void calculateInterest()
		{
			if(balance < 50000)
			{
				cout << "Interest: " <<  balance * 0.6 << endl;	
			}
			else if(balance < 100000)
			{
				cout << "Interest: " <<  balance * 0.9 << endl;
			}
			else
			{
				cout << "Interest: " <<  balance * 0.12 << endl;
			}	
		}
		
		void printStatement()
		{
			cout << "Account Statement\n";
			cout << "Account Number: " << accountNumber << endl;
			cout << "Balance: " << balance << endl;
		}

		void getAccountInfo()
		{
			cout << "Account Number: " << accountNumber << endl;
			cout << "Account Holder Name: " << accountHolderName << endl;
			cout << "Balance: " << balance << endl;
			cout << "Account Type: " << accountType << endl;
		}
};

class SavingsAccount : public Account
{
	protected:
		float interestRate;
		float minimumBalance;
	
	public:
		SavingsAccount(int accountNumber, float balance, string accountHolderName, float interestRate, float minimumBalance) : 
		Account(accountNumber, balance, accountHolderName, "Savings"),
		interestRate(interestRate), minimumBalance(minimumBalance){}
		
		void calculateInterest()
		{
			cout << "Interest: " << balance * interestRate/100 << endl;
		}
		
		void withdraw(float amount)
		{
			if(balance - amount < minimumBalance)
			{
				cout << "Minimum Balance requirement is not met\n";	
				return;
			}
			Account::withdraw(amount);	
		}	
};

class CheckingAccount : public Account
{
	protected:
		float overdraftLimit;
		
	public:
		CheckingAccount(int accountNumber, float balance, string accountHolderName, float overdraftLimit) : 
		Account(accountNumber, balance, accountHolderName, "Checking"),
		overdraftLimit(overdraftLimit){}
	
		void withdraw(float amount)
		{
			if(amount > (balance + overdraftLimit))
			{
				cout << "Amount exceeding overdraft limit\n";
			}
		}
};

class FixedDepositAccount : public Account
{
	protected:
		string maturityDate;
		float fixedInterestRate;
	
	public:
		FixedDepositAccount(int accountNumber, float balance, string accountHolderName, string maturityDate, float fixedInterestRate) : 
		Account(accountNumber, balance, accountHolderName, "Fixed Deposit"),
		maturityDate(maturityDate), fixedInterestRate(fixedInterestRate){}
		
		void calculateInterest()
		{
			cout << "Interest: " << balance * fixedInterestRate/100 << endl;
		}

		void withdraw(float amount) 
		{
			cout << "Money cannot be withdrawn from Fixed Deposit before maturity data\n";
		}
};

int main()
{
    Account* savings = new SavingsAccount(12345, 5000, "Mike", 5.4, 1600);

    savings->deposit(1300);
    savings->withdraw(500);
    savings->getAccountInfo();
    savings->calculateInterest();
    cout << endl;
    
    Account* checking = new CheckingAccount(67890, 3500, "John", 500);
    checking->deposit(500);
    checking->withdraw(5000);
    checking->getAccountInfo();
    cout << endl;

    Account* fixedDeposit = new FixedDepositAccount(13579, 6000, "Sara", "3/24/2025", 7.1);
    fixedDeposit->withdraw(100);
    fixedDeposit->getAccountInfo();
    fixedDeposit->calculateInterest();
    cout << endl;

    delete savings;
    delete checking;
    delete fixedDeposit;
	return 0;
}
