#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "store_inventory.h"

int main() {

	char item[20];
	//struct Details*head = NULL;
	struct Details* newHead1 = readLinkedList();

	int option=0;

	printf(" 1. Print all list.\n");
	printf(" 2. Get stock by model number.\n");
	printf(" 3. Add a new entry.\n");
	printf(" 4. exit.\n");
	printf("Please enter the option\n");
	scanf("%d", &option);

	switch(option)
		{
			case 1:	if(newHead1 )
					 displayLinkedList(newHead1);
				else
					printf("List is empty");
				break;

			case 2:	printf("\n\n Enter model number to display stock\n");
				scanf("%s",item);
				if(newHead1!=NULL)
					searchElementByModelNumber(newHead1,item);
				else
					printf("List is empty");
				break;
			case 3:	insertData(newHead1);
				break;

			case 4:	exit(0);
				break;
		}

	return 0;    
}	
    
