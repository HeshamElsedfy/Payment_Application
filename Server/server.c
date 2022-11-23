
#include "server.h"
#define ACC_DB_SIZE 255
ST_accountsDB_t accountsDB[ACC_DB_SIZE]=
{   {2500.0, RUNNING, "8989374615436851"},
    {10000.0, BLOCKED, "5807117076043875"},
    {90000.0, RUNNING, "5807007776043875"},
    {80000.0, RUNNING, "5807007076043875"},
    {100000.0, RUNNING, "5807007076043875"},
    {300000.0, RUNNING, "5807007076043875"},
    {200000.0, RUNNING, "5807007076043875"},
    {400000.0, BLOCKED, "5807007076043875"},
    {3000.0, RUNNING, "8989374615136809"},
    {1000.0, RUNNING, "8989374615436898"},
    {2000.0, RUNNING, "8982374615436851"}
};
#define TRANS_DB_SIZE 255
ST_transaction_t tranactionsDB[TRANS_DB_SIZE]={};
uint32_t transactionCount=0;
EN_transState_t recieveTransactionData(ST_transaction_t *transData){
    ST_cardData_t cardData;
    ST_terminalData_t terminalData;
    boolean accountFound=0;
    float maxAmmount=0;
    if(transactionCount>=TRANS_DB_SIZE){
        return INTERNAL_SERVER_ERROR;
    }
    else{
        /*do nothing*/
    }

    /*getting Card data*/
    EN_cardError_t cardErr = CARD_OK;
    printf("Enter Card data\n");
    printf("Card Holder Name: ");
    cardErr=getCardHolderName(&cardData);
    printf("\nCard Expiry Date: ");
    cardErr=getCardExpiryDate(&cardData);
    printf("\nCard PAN: ");
    cardErr=getCardPAN(&cardData);
    /*checking if card data is Valid*/
    if(CARD_OK != cardErr ){
        transData->transState=FRAUD_CARD;
        return FRAUD_CARD;
    }
    else{
        /*do nothing*/
    }
    /*getting terminal data*/
    EN_terminalError_t termErr=TERMINAL_OK;
    printf("Enter terminal data\n");
    printf("Transaction Date:");
    termErr=getTransactionDate(&terminalData);
    termErr=isCardExpired(&cardData,&terminalData);
    printf("\nTransaction Amount:");
    termErr=getTransactionAmount(&terminalData);
    printf("\nMaximum Amount:");
    scanf("%f",&maxAmmount);
    termErr=setMaxAmount(&terminalData,maxAmmount);
    termErr=isBelowMaxAmount(&terminalData);
    /*checking if terminal data is Valid*/
    if(TERMINAL_OK!=termErr){
        transData->transState=DECLINED_INSUFFECIENT_FUND;
        return DECLINED_INSUFFECIENT_FUND;
    }
    else{
        /*do nothing*/
    }
    transData->cardHolderData=cardData;
    transData->terminalData=terminalData;

    uint8_t i=0;
    for(i=0;i<ACC_DB_SIZE;i++){
        if(0 == strcmp(cardData.primaryAccountNumber,accountsDB[i].primaryAccountNumber)){
            accountFound=1;
            break;
        }
        else{
        /*do nothing*/
        }
    }
    if(!accountFound){
        transData->transState=FRAUD_CARD;
        return FRAUD_CARD;
    }
    else{
        /*do nothing*/
    }
    if(accountsDB[i].state == BLOCKED){
        transData->transState=DECLINED_STOLEN_CARD;
        return DECLINED_STOLEN_CARD;
    }
    else{
        /*do nothing*/
    }
    printf("%d\n",i);
    printf("%f\n",terminalData.transAmount);
    printf("%f\n",accountsDB[i].balance);
    if(terminalData.transAmount > accountsDB[i].balance ){
        transData->transState=DECLINED_INSUFFECIENT_FUND;
        return DECLINED_INSUFFECIENT_FUND;
    }
    else{
        /*do nothing*/
    }

    transData->transState=APPROVED;
    accountsDB[i].balance-=transData->terminalData.transAmount;
    return APPROVED;
}
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence){
    uint8_t i=0;
    for(i=0;i<ACC_DB_SIZE;i++){
        if(0 == strcmp(cardData->primaryAccountNumber,accountsDB[i].primaryAccountNumber)){
            *accountRefrence=accountsDB[i];
            return SERVER_OK;
        }
        else{
            /*do nothing*/
        }
    }
    accountRefrence=NULL;
    return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence){
    if(accountRefrence->state == BLOCKED){
        return BLOCKED_ACCOUNT;
    }
    else{
        return SERVER_OK;
    }
}
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence){
    if(termData->transAmount > accountRefrence->balance){
        return LOW_BALANCE;
    }
    else{
        return SERVER_OK;
    }
}
EN_serverError_t saveTransaction(ST_transaction_t *transData){
    tranactionsDB[transactionCount]=*transData;
    transactionCount++;
    return SERVER_OK;
}
void listSavedTransactions(void){
    char* transactionStatesArr[]={"APPROVED", "DECLINED_INSUFFECIENT_FUND", "DECLINED_STOLEN_CARD", "FRAUD_CARD", "INTERNAL_SERVER_ERROR"};
    for(uint8_t i=0;i<transactionCount;i++){
        printf("#############################\n");
        printf("Transaction Sequence Number: %d\n" , tranactionsDB[i].transactionSequenceNumber);
        printf("Transaction Date: %s\n" , tranactionsDB[i].terminalData.transactionDate);
        printf("Transaction Amount: %f\n" , tranactionsDB[i].terminalData.transAmount);
        printf("Transaction State: %d\n", transactionStatesArr[tranactionsDB[i].transState]);
        printf("Terminal Max Amount: %f\n", tranactionsDB[i].terminalData.maxTransAmount);
        printf("Cardholder Name: %s\n",tranactionsDB[i].cardHolderData.cardHolderName);
        printf("PAN: %s\n",tranactionsDB[i].cardHolderData.primaryAccountNumber);
        printf("Card Expiration Date: %s\n",tranactionsDB[i].cardHolderData.cardExpirationDate);
        printf("#############################\n");
    }
}
