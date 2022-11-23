
#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
    /* date Format dd/mm/yyyy */
uint8_t transactionDate[15]={};
uint8_t* ret=NULL;
ret=gets(transactionDate);
for(uint8_t i=0;i<10;i++){
    if(i==2 || i== 5){
        if(transactionDate[i]!='/'){
            return WRONG_DATE;
        }
        else{
            /*do nothing*/
        }
    }
    else{
        if(transactionDate[i]<'0' || transactionDate[i]>'9'){
            return WRONG_DATE;
        }
        else{
            /*do nothing*/
        }
    }
}
if(10!=strlen(transactionDate) || ret == NULL){
    return WRONG_DATE;
}
else{
    strcpy(termData->transactionDate,transactionDate);
    return TERMINAL_OK;
}
}
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData){
    uint8_t termDateMonths=(termData->transactionDate[3]-'0')*10+termData->transactionDate[4]-'0';

    uint16_t termDateYears=(termData->transactionDate[6]-'0')*1000+(termData->transactionDate[7]-'0')*100+
                            (termData->transactionDate[8]-'0')*10+termData->transactionDate[9]-'0';

    uint8_t cardDateMonths=(cardData->cardExpirationDate[0]-'0')*10+cardData->cardExpirationDate[1]-'0';

    uint16_t cardDateYears= 2000 + (cardData->cardExpirationDate[3]-'0')*10 + cardData->cardExpirationDate[4] - '0';
    if(termDateYears > cardDateYears){
        return EXPIRED_CARD;
    }
    else if(termDateYears == cardDateYears){
        if(termDateMonths > cardDateMonths){
            return EXPIRED_CARD;
        }
        else{
            return TERMINAL_OK;
        }
    }
    else{
        return TERMINAL_OK;
    }
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
    float transAmmount = 0;
    scanf("%f",&transAmmount);
    if(transAmmount<=0){
        return INVALID_AMOUNT;
    }
    else{
        termData->transAmount=transAmmount;
        return TERMINAL_OK;
    }
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){
    if(termData->transAmount > termData->maxTransAmount){
        return EXCEED_MAX_AMOUNT;
    }
    else{
        return TERMINAL_OK;
    }
}
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount){
    if(maxAmount <= 0){
        return INVALID_MAX_AMOUNT;
    }
    else{
        termData->maxTransAmount=maxAmount;
        return TERMINAL_OK;
    }
}
