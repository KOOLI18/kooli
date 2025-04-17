#include <stdio.h>

int main() {
    int initial_balance = 50000;
    int withdrawal;
    int balance;
    printf("Enter amount to withdraw: ");
    scanf("%d", &withdrawal);
    if (withdrawal > balance) {
        printf("Y'ellow you have insufficient balance to complete this transaction. withdrawal failed.\n");
    } else if(withdrawal <=0) {
        printf("invalid withdrawal amount. \n");
    } else{
        balance = initial_balance - withdrawal;
        printf("you have successfully withdrawn an amount of UGX: %d\n", withdrawal);
        printf("Your remaining balance is UGX: %d\n", balance);
    } 
    return 0;

}