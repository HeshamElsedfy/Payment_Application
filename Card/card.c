
#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
    uint8_t name[50]={};
    uint8_t *ret=NULL;
    ret=gets(name);
    if(strlen(name)>=24 || strlen(name)<=20 || ret == NULL){
        return WRONG_NAME;
    }
    else{
        strcpy(cardData->cardHolderName,name);
        return CARD_OK;
    }
}
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
    uint8_t expDate[10]={};
    boolean isTrueFormat = 1;
    uint8_t i=0;
    uint8_t *ret=NULL;
    ret=gets(expDate);
    while(expDate[i]!='\0'){
        if(i!=2){
            if(!(expDate[i]>='0' && expDate[i]<='9')){
                isTrueFormat=0;
            }
            else{
                /*do nothing*/
            }
        }
        else{
            if(expDate[i]!='/'){
                isTrueFormat=0;
            }
            else{
                /*do nothing*/
            }
        }
        i++;
    }

    if(strlen(expDate)!= 5 || !isTrueFormat || ret == NULL){
        return WRONG_EXP_DATE;
    }
    else{
        strcpy(cardData->cardExpirationDate,expDate);
        return CARD_OK;
    }
}
EN_cardError_t getCardPAN(ST_cardData_t *cardData){
    uint8_t pan[30]={};
    uint8_t *ret=NULL;
    ret=gets(pan);
    if(strlen(pan)<16 || strlen(pan)>19 || ret == NULL){
        return WRONG_PAN;
    }
    else{
        strcpy(cardData->primaryAccountNumber,pan);
        return CARD_OK;
    }
}
