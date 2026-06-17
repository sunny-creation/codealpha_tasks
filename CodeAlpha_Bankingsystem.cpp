#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

class Account {
public:
    int accountNo;
    double balance;
    vector<Transaction> history;

    Account(int accNo) {
        accountNo = accNo;
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount <= balance) {
            balance -= amount;
            receiver.balance += amount;

            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(Transaction("Transfer Received", amount));

            cout << "Transfer Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void showHistory() {
        cout << "\nTransaction History\n";
        for (int i = 0; i < history.size(); i++) {
            cout << history[i].type << " : Rs." << history[i].amount << endl;
        }
    }

    void showAccount() {
        cout << "\nAccount Number : " << accountNo << endl;
        cout << "Balance : Rs." << balance << endl;
    }
};

class Customer {
public:
    int id;
    string name;
    Account account;

    Customer(int cid, string cname, int accNo)
        : account(accNo) {
        id = cid;
        name = cname;
    }

    void display() {
        cout << "\nCustomer ID : " << id << endl;
        cout << "Customer Name : " << name << endl;
        account.showAccount();
    }
};

int main() {
    int id, accNo;
    string name;

    cout << "Enter Customer ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Account Number: ";
    cin >> accNo;

    Customer customer(id, name, accNo);

    int choice;
    double amount;

    do {
        cout << "\n====== Banking System ======\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Show Account Details\n";
        cout << "5. Show Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Amount: ";
            cin >> amount;
            customer.account.deposit(amount);
            break;

        case 2:
            cout << "Enter Amount: ";
            cin >> amount;
            customer.account.withdraw(amount);
            break;

        case 3: {
            int acc2;
            cout << "Enter Receiver Account Number: ";
            cin >> acc2;

            Account receiver(acc2);

            cout << "Enter Amount: ";
            cin >> amount;

            customer.account.transfer(receiver, amount);
            break;
        }

        case 4:
            customer.display();
            break;

        case 5:
            customer.account.showHistory();
            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}