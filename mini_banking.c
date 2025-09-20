#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

// Function prototypes
void createAccount(Account *acc, int *count);
void deposit(Account accounts[], int count);
void withdraw(Account accounts[], int count);
void checkBalance(Account accounts[], int count);
void displayAccounts(Account accounts[], int count);

int main() {
    Account accounts[100]; // Array to store up to 100 accounts
    int choice;
    int count = 0; // Current number of accounts

    printf("===== Welcome to Mini Banking System =====\n");

    do {
        printf("\n1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount(&accounts[count], &count);
                break;
            case 2:
                deposit(accounts, count);
                break;
            case 3:
                withdraw(accounts, count);
                break;
            case 4:
                checkBalance(accounts, count);
                break;
            case 5:
                displayAccounts(accounts, count);
                break;
            case 6:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to create a new account
void createAccount(Account *acc, int *count) {
    printf("\nEnter Account Number: ");
    scanf("%d", &acc->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc->name);
    printf("Enter Initial Balance: ");
    scanf("%f", &acc->balance);

    (*count)++;
    printf("Account created successfully!\n");
}

// Function to deposit money
void deposit(Account accounts[], int count) {
    int accNum, found = 0;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    for(int i = 0; i < count; i++) {
        if(accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully! New balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }
    if(!found) printf("Account not found!\n");
}

// Function to withdraw money
void withdraw(Account accounts[], int count) {
    int accNum, found = 0;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    for(int i = 0; i < count; i++) {
        if(accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if(amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            }
            found = 1;
            break;
        }
    }
    if(!found) printf("Account not found!\n");
}

// Function to check account balance
void checkBalance(Account accounts[], int count) {
    int accNum, found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    for(int i = 0; i < count; i++) {
        if(accounts[i].accountNumber == accNum) {
            printf("Account Holder: %s\nBalance: %.2f\n", accounts[i].name, accounts[i].balance);
            found = 1;
            break;
        }
    }
    if(!found) printf("Account not found!\n");
}

// Function to display all accounts
void displayAccounts(Account accounts[], int count) {
    printf("\n===== All Accounts =====\n");
    for(int i = 0; i < count; i++) {
        printf("Account Number: %d | Name: %s | Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}
