#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>
#include <ctype.h>
#include <stdbool.h>

struct Node {
    char phoneNumber[14], name[26], email[21];
    int points;
    struct Node *left, *right;
} data;

void insertInput() {
    char inPhoneNumber[14], inName[26], inEmail[21];
    int inPoints, valid; 
    char isMr[] = "Mr. ";
    char isMrs[] = "Mrs.";

    do {
        valid=0;
        printf("Input phone number[10-13][numeric]: ");
        scanf("%s", inPhoneNumber); getchar();
        for(int i=0; i<strlen(inPhoneNumber); i++) {
            if(!isdigit(inPhoneNumber[i])) {
                valid=1;
                break;
            }
        }
    } while((strlen(inPhoneNumber)<10 || strlen(inPhoneNumber)>13) || valid==1);

    if(1) {
        do {
            printf("Input name[5-25][Mr. |Mrs. ]: ");
            scanf("%[^\n]", inName); getchar();
        } while((strlen(inName)<5 || strlen(inName)>25) || (strstr(inName, isMr)==NULL && strstr(inName, isMrs)==NULL));

        int jmlChar=0;
        char isCom[] = ".com";
        char isCoId[] = ".co.id";
        char checkCom, checkCoId;
        do {
            jmlChar=0, valid=0;
            printf("Input email[10-20][email format]: ");
            scanf("%s", inEmail); getchar();

            for(int i=0; i<strlen(inEmail); i++) {
                if(inEmail[i]=='@')
                    jmlChar++;
            }

            checkCom = strstr(inEmail,isCom);
            checkCoId = strstr(inEmail, isCoId);
            // for(int i=strlen(inEmail)-1; i>6; i--) {
            //     if(strstr(inEmail, ".co.id")==NULL  && strstr(inEmail, ".com")==NULL) {
            //         valid=1;
            //     }
            // }
        } while(strlen(inEmail)<10|| strlen(inEmail)>20 || jmlChar!=1 || (checkCom == NULL && checkCoId == NULL));
    }
}

int main() {
    insertInput();
}

