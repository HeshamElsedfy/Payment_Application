
#include "app.h"
void appStart(void){

EN_transState_t   err_transaction=APPROVED;
EN_terminalError_t err_terminal=TERMINAL_OK;
EN_serverError_t  err_server=SERVER_OK;
EN_cardError_t err_card=CARD_OK;
ST_accountsDB_t account;
ST_transaction_t   transaction;


err_transaction=recieveTransactionData(&transaction);

switch(err_transaction){
    case APPROVED:
        /*do nothing*/
    break;
    case DECLINED_STOLEN_CARD:
        printf("\nTransaction Declined \n Blocked Account\n");
        return;
    break;
    case INTERNAL_SERVER_ERROR:
        printf("\nTransaction Declined \n Internal Server Error\n");
        return;
    break;
}
err_terminal=isCardExpired(&transaction.cardHolderData,&transaction.terminalData);
if(EXPIRED_CARD == err_terminal){
    printf("\nTransaction Declined \n Card Expired\n");
    return;
}
err_server=isValidAccount(&transaction.cardHolderData,&account);
if(ACCOUNT_NOT_FOUND == err_server){
    printf("\nTransaction Declined \n Invalid Account\n");
    return;
}
else{
    /*do nothing*/
}
err_server=isAmountAvailable(&transaction.terminalData,&account);
if(LOW_BALANCE == err_server){
    printf("\nTransaction Declined \n Insufficient Fund\n");
    return;
}
else{
    /*do nothing*/
}
err_terminal=isBelowMaxAmount(&transaction.terminalData);
if(EXCEED_MAX_AMOUNT == err_terminal){
    printf("\nTransaction Declined \n Exceed Maximum Allowed Amount\n");
    return;
}
else{
    /*do nothing*/
}

if(CARD_OK == err_card && SERVER_OK == err_server && TERMINAL_OK == err_terminal && APPROVED == err_transaction){
    printf("Transaction Approved\n");
    saveTransaction(&transaction);
}
else{
    /*do nothing*/
}

}
