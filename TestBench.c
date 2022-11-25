
#include "Card/card.h"
#include "Terminal/terminal.h"
#include "Server/server.h"
#include "Application/app.h"
/**************************************************
*****************Card Module Test Cases************
***************************************************/
void getCardHolderNameTest(void){

/**Test case 1: valid name**/
ST_cardData_t user1 ;
EN_cardError_t err1 = CARD_OK;
/**used name : Hesham Mahmoud Ramzy El**/
printf("\nTest Case 1\n");
printf("Input Data: ");
err1=getCardHolderName(&user1);

printf("Expected Result:%d\n",CARD_OK);
printf("Actual Result: %d\n",err1);

/**Test case 2: name less Than 20 Characters **/
ST_cardData_t user2 ;
EN_cardError_t err2 = CARD_OK;
    /*used name : Hesham Mahmoud Ramzy */
printf("\nTest Case 2\n");
printf("Input Data: ");
err2=getCardHolderName(&user2);

printf("Expected Result:%d\n",WRONG_NAME);
printf("Actual Result: %d\n",err2);

/*Test case 3: name more Than 24 Characters*/
ST_cardData_t user3 ;
EN_cardError_t err3 = CARD_OK;
    /*used name : Hesham Mahmoud Ramzy Elsedfy*/
printf("\nTest Case 3\n");
printf("Input Data: ");
err3=getCardHolderName(&user3);
printf("Expected Result:%d\n",WRONG_NAME);
printf("Actual Result: %d\n",err3);

/*Test case 4: NULL Pointer Passed*/
ST_cardData_t user4 ;
EN_cardError_t err4 = CARD_OK;
    /*used name : Hesham Mahmoud Ramzy Elsedfy*/
printf("\nTest Case 4\n");
printf("Input Data: ");
err4=getCardHolderName(&user4);
printf("Expected Result:%d\n",WRONG_NAME);
printf("Actual Result: %d\n",err4);

}
void getCardExpiryDateTest (void){
        /*Test case 1: valid date*/
    ST_cardData_t user1 ;
    EN_cardError_t err1 = CARD_OK;
        /*used date : 11/25*/
    printf("\nTest Case 1\n");
    printf("Input Data: ");
    err1=getCardExpiryDate(&user1);

    printf("Expected Result:%d\n",CARD_OK);
    printf("Actual Result: %d\n",err1);

    /*Test case 2: invalid date format */
    ST_cardData_t user2 = {0,0,0};
    EN_cardError_t err2 = CARD_OK;
        /*used date : 11.25 */
    printf("\nTest Case 2\n");
    printf("Input Data: ");
    err2=getCardExpiryDate(&user2);

    printf("Expected Result:%d\n",WRONG_EXP_DATE);
    printf("Actual Result: %d\n",err2);

    /*Test case 3: wrong string length */
    ST_cardData_t user3 = {0,0,0};
    EN_cardError_t err3 = CARD_OK;
        /*used date : 3/11/25 */
    printf("\nTest Case 3\n");
    printf("Input Data: ");
    err3=getCardExpiryDate(&user3);

    printf("Expected Result:%d\n",WRONG_EXP_DATE);
    printf("Actual Result: %d\n",err3);
        /*Test case 4: NULL Pointer Passed  */
    EN_cardError_t err4 = CARD_OK;
        /*used date : */
    ST_cardData_t user4 = {0,0,0};
    printf("\nTest Case 4\n");
    printf("Input Data: ");
    err4=getCardExpiryDate(&user4);

    printf("Expected Result:%d\n",WRONG_EXP_DATE);
    printf("Actual Result: %d\n",err4);

}
void getCardPANTest (void){
/*Test case 1: valid pan*/
ST_cardData_t user1 = {0,0,0};
EN_cardError_t err1 = CARD_OK;
    /*used PAN : 01234567890123456*/
printf("\nTest Case 1\n");
printf("Input Data: ");
err1=getCardPAN(&user1);

printf("Expected Result:%d\n",CARD_OK);
printf("Actual Result: %d\n",err1);

/*Test case 2: pan less Than 16 Characters */
ST_cardData_t user2 = {0,0,0};
EN_cardError_t err2 = CARD_OK;
    /*used PAN : 012345 */
printf("\nTest Case 2\n");
printf("Input Data: ");
err2=getCardPAN(&user2);

printf("Expected Result:%d\n",WRONG_PAN);
printf("Actual Result: %d\n",err2);

/*Test case 3: pan more Than 19 Characters*/
ST_cardData_t user3 = {0,0,0};
EN_cardError_t err3 = CARD_OK;
    /*used PAN : 01234567890123456789012*/
printf("\nTest Case 3\n");
printf("Input Data: ");
err3=getCardPAN(&user3);
printf("Expected Result:%d\n",WRONG_PAN);
printf("Actual Result: %d\n",err3);

/*Test case 4: NULL Pointer Passed*/
ST_cardData_t user4 = {0,0,0};
EN_cardError_t err4 = CARD_OK;
    /*used PAN :  */
printf("\nTest Case 4\n");
printf("Input Data: ");
err4=getCardPAN(&user4);
printf("Expected Result:%d\n",WRONG_PAN);
printf("Actual Result: %d\n",err4);
}

/**************************************************
*****************Terminal Module Test Cases********
***************************************************/
void getTransactionDateTest(void){
    /**Test case 1: valid Transaction Date**/
    ST_terminalData_t user1;
    EN_terminalError_t err1 = TERMINAL_OK;
    /**used Transaction Date : 16/11/2022 **/
    printf("\nTest Case 1\n");
    printf("Input Data: ");

    err1=getTransactionDate(&user1);
    printf("Expected Result:%d\n",TERMINAL_OK);
    printf("Actual Result: %d\n",err1);

    /**Test case 2: invalid Transaction Date length**/
    ST_terminalData_t user2;
    EN_terminalError_t err2 = TERMINAL_OK;
    /**used Transaction Date : 16/11/20222 **/
    printf("\nTest Case 2\n");
    printf("Input Data: ");
    err2=getTransactionDate(&user2);
    printf("Expected Result:%d\n",WRONG_DATE);
    printf("Actual Result: %d\n",err2);

    /**Test case 3: invalid Transaction Date format**/
    ST_terminalData_t user3 ;
    EN_terminalError_t err3 = TERMINAL_OK;
    /**used Transaction Date : 16.11.2022 **/
    printf("\nTest Case 3\n");
    printf("Input Data: ");
    err3=getTransactionDate(&user3);
    printf("Expected Result:%d\n",WRONG_DATE);
    printf("Actual Result: %d\n",err3);

    /**Test case 4: Passing NULL ptr**/
    ST_terminalData_t user4;
    EN_terminalError_t err4 = TERMINAL_OK;
    /**used Transaction Date : 16.11.2022 **/
    printf("\nTest Case 4\n");
    printf("Input Data: ");
    err4=getTransactionDate(&user4);
    printf("Expected Result:%d\n",WRONG_DATE);
    printf("Actual Result: %d\n",err4);
}
void isCardExpriedTest(void){
    /**Test case 1: Card Not expired**/
    ST_terminalData_t user1_terminal ={0,0,"16/11/2022"};
    ST_cardData_t user1_card = {" "," ","11/23"};
    EN_terminalError_t err1 = TERMINAL_OK;
    /**used Transaction Date : 16/11/2022 **/
    printf("\nTest Case 1\n");
    printf("Input Data: ");

    err1=isCardExpired(&user1_card , &user1_terminal);
    printf("Expected Result:%d\n",TERMINAL_OK);
    printf("Actual Result: %d\n",err1);

    /**Test case 2: Card  expired**/
    ST_terminalData_t user2_terminal ={0,0,"16/11/2022"};
    ST_cardData_t user2_card = {" "," ","11/21"};
    EN_terminalError_t err2 = TERMINAL_OK;
    /**used Transaction Date : 16/11/2022 **/
    printf("\nTest Case 2\n");
    printf("Input Data: ");

    err2=isCardExpired(&user2_card , &user2_terminal);
    printf("Expected Result:%d\n",EXPIRED_CARD);
    printf("Actual Result: %d\n",err2);

}
void getTransactionAmountTest(void){

    /**Test case 1: Valid Transaction Amount**/
    ST_terminalData_t user1_terminal ={0,0,0};
    EN_terminalError_t err1 = TERMINAL_OK;
    /**used Transaction Amount : 10000 **/
    printf("\nTest Case 1\n");
    printf("Input Data: ");

    err1=getTransactionAmount(&user1_terminal);
    printf("Expected Result:%d\n",TERMINAL_OK);
    printf("Actual Result: %d\n",err1);

    /**Test case 2: inValid Transaction Amount**/
    ST_terminalData_t user2_terminal ={0,0,0};
    EN_terminalError_t err2 = TERMINAL_OK;
    /**used Transaction Amount : 0 **/
    printf("\nTest Case 2\n");
    printf("Input Data: ");

    err2=getTransactionAmount(&user2_terminal);
    printf("Expected Result:%d\n",INVALID_AMOUNT);
    printf("Actual Result: %d\n",err2);

}
void isBelowMaxAmountTest(void){
    /**Test case 1: Valid Transaction Amount**/
    ST_terminalData_t user1_terminal ={10000,20000,0};
    EN_terminalError_t err1 = TERMINAL_OK;
    /**used Transaction Amount :  **/
    printf("\nTest Case 1\n");
    printf("Input Data: ");

    err1=isBelowMaxAmount(&user1_terminal);
    printf("Expected Result:%d\n",TERMINAL_OK);
    printf("Actual Result: %d\n",err1);

    /**Test case 2: exceed max Transaction Amount**/
    ST_terminalData_t user2_terminal ={20000,10000,0};
    EN_terminalError_t err2 = TERMINAL_OK;
    /**used Transaction Amount :  **/
    printf("\nTest Case 2\n");
    printf("Input Data: ");

    err2=isBelowMaxAmount(&user2_terminal);
    printf("Expected Result:%d\n",EXCEED_MAX_AMOUNT);
    printf("Actual Result: %d\n",err2);
}
void setMaxAmountTest(void){
    /**Test case 1: Valid Max Transaction Amount**/
    ST_terminalData_t user1_terminal ={0,0,0};
    EN_terminalError_t err1 = TERMINAL_OK;
    /**used Transaction Max Amount : 10000 **/
    printf("\nTest Case 1\n");
    printf("Input Data: ");

    err1=setMaxAmount(&user1_terminal,10000);
    printf("Expected Result:%d\n",TERMINAL_OK);
    printf("Actual Result: %d\n",err1);

    /**Test case 2: inValid Max Transaction Amount**/
    ST_terminalData_t user2_terminal ={0,0,0};
    EN_terminalError_t err2 = TERMINAL_OK;
    /**used Transaction Max Amount : 10000 **/
    printf("\nTest Case 2\n");
    printf("Input Data: ");

    err2=setMaxAmount(&user2_terminal,-10000);
    printf("Expected Result:%d\n",INVALID_MAX_AMOUNT);
    printf("Actual Result: %d\n",err2);
}
/**************************************************
*****************Server Module Test Cases**********
***************************************************/
void recieveTransactionDataTest(void){

    /**Test case 1: Valid Transaction **/
    ST_transaction_t user1 ={0,0,0};
    EN_serverError_t err1 = APPROVED;
    /**used Transaction Data :

    Account Balance : 2500.0,
    Account State : RUNNING,
    PAN : 8989374615436851

    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/23
    Transaction Date: 23/11/2022
    Transaction Amount: 1000
    Maximum Amount :1500

     **/
    printf("\nTest Case 1\n");
    printf("Input Data: ");

    err1=recieveTransactionData(&user1);
    printf("Expected Result:%d\n",APPROVED);
    printf("Actual Result: %d\n",user1.transState);

    /**Test case 2: FRAUD CARD **/
    ST_transaction_t user2 ={0,0,0};
    EN_serverError_t err2 = APPROVED;
    /**used Transaction Data :

    Account Balance : -,
    Account State : -,
    PAN : 8989999615436851

    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/23
    Transaction Date: 23/11/2022
    Transaction Amount: 1000
    Maximum Amount :1500

     **/
    printf("\nTest Case 2\n");
    printf("Input Data: ");

    err2=recieveTransactionData(&user2);
    printf("Expected Result:%d\n",FRAUD_CARD);
    printf("Actual Result: %d\n",user2.transState);

    /**Test case 3:  Insufficient Fund **/
    ST_transaction_t user3 ={0,0,0};
    EN_serverError_t err3 = APPROVED;
    /**used Transaction Data :

    Account Balance : 2500,
    Account State : RUNNING,
    PAN : 8989374615436851

    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/23
    Transaction Date: 23/11/2022
    Transaction Amount: 3000
    Maximum Amount :4000

     **/
    printf("\nTest Case 3\n");
    printf("Input Data: ");

    err3=recieveTransactionData(&user3);
    printf("Expected Result:%d\n",DECLINED_INSUFFECIENT_FUND);
    printf("Actual Result: %d\n",user3.transState);

    /**Test case 4: Stolen Card **/
    ST_transaction_t user4 ={0,0,0};
    EN_serverError_t err4 = APPROVED;
    /**used Transaction Data :

    Account Balance : 10000.0,
    Account State : BLOCKED,
    PAN : 5807117076043875

    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/23
    Transaction Date: 23/11/2022
    Transaction Amount: 1000
    Maximum Amount :1500

     **/
    printf("\nTest Case 4\n");
    printf("Input Data: ");

    err4=recieveTransactionData(&user4);
    printf("Expected Result:%d\n",DECLINED_STOLEN_CARD);
    printf("Actual Result: %d\n",user4.transState);
}
void isValidAccountTest(void){

    /**Test case 1: Valid Account **/
    ST_cardData_t user1_Card ={"Hesham Mahmoud Ramzy El","8989374615436851","12/23"};
    ST_accountsDB_t user1_account={};
    EN_serverError_t err1 = APPROVED;
    /**used Transaction Data : **/
    printf("\nTest Case 1\n");
    printf("Input Data: card with PAN 8989374615436851 (valid PAN)\n");

    err1=isValidAccount(&user1_Card,&user1_account);
    printf("Expected Result:%d\n",SERVER_OK);
    printf("Actual Result: %d\n",err1);

    /**Test case 2: inValid Account **/
    ST_cardData_t user2_Card ={"Hesham Mahmoud Ramzy El","8989374995436851","12/23"};
    ST_accountsDB_t user2_account={};
    EN_serverError_t err2 = APPROVED;
    /**used Transaction Data : **/
    printf("\nTest Case 2\n");
    printf("Input Data: card with PAN 8989374995436851 (invalid PAN)\n");

    err2=isValidAccount(&user2_Card,&user2_account);
    printf("Expected Result:%d\n",ACCOUNT_NOT_FOUND);
    printf("Actual Result: %d\n",err2);

}
void isBlockedAccountTest(void){

    /**Test case 1: Valid Account **/
    ST_accountsDB_t user1_account={2500.0,RUNNING,"8989374615436851"};
    EN_serverError_t err1 = APPROVED;
    /**used Transaction Data : **/
    printf("\nTest Case 1\n");
    printf("Input Data: card with PAN 8989374615436851 (valid PAN)\n");
    err1=isBlockedAccount(&user1_account);
    printf("Expected Result:%d\n",SERVER_OK);
    printf("Actual Result: %d\n",err1);

    /**Test case 2: BLOCKED Account **/
    ST_accountsDB_t user2_account={2500.0,BLOCKED,"8989374615436851"};
    EN_serverError_t err2 = APPROVED;
    /**used Transaction Data : **/
    printf("\nTest Case 2\n");
    printf("Input Data: card with PAN 8989374615436851 (valid PAN)\n");
    err2=isBlockedAccount(&user2_account);
    printf("Expected Result:%d\n",BLOCKED_ACCOUNT);
    printf("Actual Result: %d\n",err2);

}
void isAmountAvailableTest(void){

    /**Test case 1: amount Available  **/
    ST_accountsDB_t user1_account={2500.0,RUNNING,"8989374615436851"};
    ST_terminalData_t user1_terminal={1000,1500,"11/5/2022"};
    EN_serverError_t err1 = SERVER_OK;
    /**used Transaction Data : **/
    printf("\nTest Case 1\n");
    printf("Input Data: Transaction Request of 1000$ for an Account with 2500$\n");
    err1=isAmountAvailable(&user1_terminal,&user1_account);
    printf("Expected Result:%d\n",SERVER_OK);
    printf("Actual Result: %d\n",err1);

    /**Test case 2: amount not Available  **/
    ST_accountsDB_t user2_account={2500.0,RUNNING,"8989374615436851"};
    ST_terminalData_t user2_terminal={3000,4000,"11/5/2022"};
    EN_serverError_t err2 = SERVER_OK;
    /**used Transaction Data : **/
    printf("\nTest Case 2\n");
    printf("Input Data: Transaction Request of 3000$ for an Account with 2500$\n");
    err2=isAmountAvailable(&user2_terminal,&user2_account);
    printf("Expected Result:%d\n",LOW_BALANCE);
    printf("Actual Result: %d\n",err2);

}
void saveTransactionTest(void){
    /**Test case 1: Available Amount **/
    ST_transaction_t user1_transaction={
                                        {"Hesham Mahmoud Ramzy El","8989374615436851" ,"12/22"},
                                        {1000 ,1500, "15/7/2022"},
                                        APPROVED,
                                        0
                                        };

    EN_serverError_t err1 = SERVER_OK;
    /**used Transaction Data : **/
    printf("\nTest Case 1\n");
    printf("Input Data: Transaction Data");
    err1=saveTransaction(&user1_transaction);
    printf("Expected Result: transaction sequence Number = 1\n");
    printf("Actual Result: transaction sequence Number = %d\n",user1_transaction.transactionSequenceNumber);

}
void listSavedTransactionsTest(void){
    ST_transaction_t user1_transaction={
                                        {"Hesham Mahmoud Ramzy El","8989374615436851" ,"12/22"},
                                        {1000 ,1500, "15/7/2022"},
                                        APPROVED,
                                        0
                                        };
    ST_transaction_t user2_transaction={
                                        {"Hesham Mahmoud Ramzy El","8989374615436851" ,"12/22"},
                                        {3000 ,4000, "15/7/2022"},
                                        DECLINED_INSUFFECIENT_FUND,
                                        0
                                        };
    ST_transaction_t user3_transaction={
                                        {"Hesham Mahmoud Ramzy El","89893746159996851" ,"12/22"},
                                        {1000 ,1500, "15/7/2022"},
                                        DECLINED_STOLEN_CARD,
                                        0
                                        };

    saveTransaction(&user1_transaction);
    saveTransaction(&user2_transaction);
    saveTransaction(&user3_transaction);
    printf("\nTest Case 1\n");
    printf("Input Data: 3 Different Transactions\n");
    printf("Expected Result: a List printed for the 3 Transactions\n");
    printf("Actual Result: \n");
    listSavedTransactions();
}

/**************************************************
***********Application Module Test Cases***********
***************************************************/
void appStartTest(void){

/**Test Case 1: Transaction Approved**/
/**Test Data:

    Account Balance : 2500.0,
    Account State : RUNNING,
    PAN : 8989374615436851

    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/23
    Transaction Date: 23/11/2022
    Transaction Amount: 1000
    Maximum Amount :1500

**/
printf("---------------Test Case 1----------------\n");
printf("Expected Output : Transaction Approved\n");
appStart();

/**Test Case 2: Exceed Maximum Amount**/
/**Test Data:

    Account Balance : 80000.0,
    Account State : RUNNING,
    PAN : 5807007076043875
    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/23
    Transaction Date: 23/11/2022
    Transaction Amount: 1000
    Maximum Amount :500

**/
printf("---------------Test Case 2----------------\n");
printf("Expected Output : Transaction Declined : Exceed maximum Amount\n");
appStart();

/**Test Case 3: Insufficient Fund **/
/**Test Data:

    Account Balance : 2500.0,
    Account State : RUNNING,
    PAN : 8989374615436851

    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/23
    Transaction Date: 23/11/2022
    Transaction Amount: 4000
    Maximum Amount :5500

**/
printf("---------------Test Case 3----------------\n");
printf("Expected Output : Transaction Declined : Insufficient Fund\n");
appStart();

/**Test Case 4: Expired Card **/
/**Test Data:

    Account Balance : 80000.0,
    Account State : RUNNING,
    PAN : 5807007076043875

    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/21
    Transaction Date: 23/11/2022
    Transaction Amount: 500
    Maximum Amount :1000

**/
printf("---------------Test Case 4----------------\n");
printf("Expected Output : Transaction Declined : Card Expired\n");
appStart();

/**Test Case 5: Stolen Card **/
/**Test Data:
    Account Balance : 10000.0,
    Account State : BLOCKED,
    PAN : 5807117076043875

    Card Holder Name: Hesham Mahmoud Ramzy El
    Card Expiry date: 10/23
    Transaction Date: 23/11/2022
    Transaction Amount: 500
    Maximum Amount :1000

**/
printf("---------------Test Case 5----------------\n");
printf("Expected Output : Transaction Declined : Stolen Card\n");
appStart();

}

int main(){
    /**Card Module Test Cases**/
    //getCardHolderNameTest();
    //getCardExpiryDateTest();
    //getCardPANTest();
    /** Terminal Module Test Cases**/
    //getTransactionDateTest();
    //isCardExpriedTest();
    //getTransactionAmountTest();
    //isBelowMaxAmountTest();
    //setMaxAmountTest();
    /** Server Module Test Cases**/
    //recieveTransactionDataTest();
    //isValidAccountTest();
    //isBlockedAccountTest();
    //isAmountAvailableTest();
    //saveTransactionTest();
    //listSavedTransactionsTest();
    /**Application Module Test Cases**/
    appStartTest();
return 0;
}
