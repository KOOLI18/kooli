#include <stdio.h>
#include <string.h>
//int borrowBook();
int borrowedbook, choice, id, original_id, i;
int available_books[5]= {00, 01, 02, 03, 04};
char processed_books[3][50];
char AvailableBook_names[5][50]= {"Time and money by Joe.T", "The 5am club by Peter Jackson", "In secret by Jolie Watkins", "The Desire of Ages by Ellen. G White", "AI Vs Human by Kaata Ronald"};
int checkAvailability(void){
    do{
    printf("Enter the book ID\n");
    scanf("%d", &id);
    printf("Enter the book ID again\n");
    scanf("%d", &original_id);
    }
    while(id!= original_id);
    for(i=0; i<5; i++){
        if(id== available_books[i]){
            printf("Dear user, the book '%s' you've selected indeed exists\n", AvailableBook_names[id]);
        }
    }
    for(i=0; i<3; i++){
        strcpy(processed_books[i], AvailableBook_names[id]);
    }
    if(id>5){
        printf("The book you've selected doesn't exist at the moment\n");
        printf("Here are the books we have, take careful note of the IDs\n");
        printf("Available books\n 1. Time and money by Joe.T\n 2. The 5am club by Peter Jackson\n 3. In secret by Jolie Watkins\n 4. The Desire of Ages by Ellen. G White\n 5. AI Vs Human by Kaata Ronald\n");
        printf("The program will request you for the id after restarting, hope you have it\n");
    }
    return 0;
}
void borrowBook(int size){
    //checkAvailability();
    printf("Alright, wait a minute as we process it\n");
    //int size;
    //size= 5;
    for(i=id; i<size-1; i++){
        available_books[i]= available_books[i+1];
        strcpy(AvailableBook_names[i], AvailableBook_names[i+1]);
    }
    size--;
    printf("current number of books is %d\n", size);
    //available_books[5]= available_books[size];
    printf("Here is a list of available books at the moment:\n");
    for(i=0; i<size; i++){
        printf("%d. %s\n", available_books[i], AvailableBook_names[i]);
    }
}
 
int main(void){
    int size, limit;
    printf("Dear user, welcome to Enjoe Digital Library! Glad to have you\n");
    printf("Below is our menu, please select an option:\n");
    printf("Enjoe Digital Library:\nWould you like to;\n\t1. View available books\n\t2. Borrow a book\n");
    scanf("%d", &choice);
    if(choice==2){
        printf("Would you like to borrow a book? Enter 1 to proceed: \n");
        scanf("%d", &choice);
        return_flag:
        size= 5;
        if (choice== 1){
            limit= 1;
            again:
            if(limit<= 3){
                printf("Alright, We are here to serve you dear\n");
                checkAvailability();
                borrowBook(size);
                printf("Would you like to borrow another book? Enter 1 to accept\n");
                scanf("%d", &choice);
                if(choice== 1){
                    size--;
                    limit++;
                    goto again;
                }
                else{
                    printf("Alright, enjoy reading book %s, hope it satisfies your interests\n", AvailableBook_names[original_id]);
                }
            }
            else{
                printf("Dear user, you have exceeded your limit of 3 books a time,\nPlease enjoy reading the books '%s', '%s', and '%s'", processed_books[0], processed_books[1], processed_books[2]);
            }
        }
        else{
            printf("Alright, feel free to ask for any book anytime\n");
            printf("You can instead have a look at our current books and pick you favorite\n");
            printf("Enter 1 to have a look at our repository\n");
            scanf("%d", &choice);
            if(choice== 1){
                printf("Alright, take careful note of the book id for the specific one you want\n");
                printf("Available books\n 1. Time and money by Joe.T\n 2. The 5am club by Peter Jackson\n 3. In secret by Jolie Watkins\n 4. The Desire of Ages by Ellen. G White\n 5. AI Vs Human by Kaata Ronald\n");
                printf("The program will request you for the id after restarting, hope you have it\n");
            }
            else{
                printf("Sorry to hear that, we try to be helpful when needed\n");
                printf("Should I tell you a funny quote\n");
                scanf("%d", &choice);
                if(choice== 1){
                    printf("Next time a stranger tries to talk to you when you're alone,\n Just look at them shocked and whisper\n'you can see me? Damn!!'\n");
                    printf("Should I tell you another joke?\n");
                    scanf("%d", &choice);
                    if(choice== 1){
                        printf("The secret of staying young is to live honestly, eat slowly and lie about your age\n");
                    }
                    else{
                        printf("Alright, we are here to help, come only here for your favorite books\n");
                    }
                }
                else{
                    printf("Alright, we are here to help, come only here for your favorite books\n");
                }
            }
        }
    }
    else{
        printf("Available books:\n 1. Time and money by Joe.T\n 2. The 5am club by Peter Jackson\n 3. In secret by Jolie Watkins\n 4. The Desire of Ages by Ellen. G White\n 5. AI Vs Human by Kaata Ronald\n");
        printf("If you're interested in borrowing one of the books or two, press 1\n");
        scanf("%d", &choice);
            goto return_flag;
    }
}