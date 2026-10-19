#include <stdio.h>

int main(void){
    int gs1, group, publisher, item, check;
    printf("Enter ISBN:");
    scanf("%d-%d-%d-%d-%d",&gs1, &group, &publisher, &item, &check);
    printf("GS1 Prefix: %d \n Group Identifier: %d \n Publisher Code: %d \n Item Number: %d \n Item   number: %d \n", gs1,group,publisher,item,check);
}
