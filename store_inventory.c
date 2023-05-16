#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store_inventory.h"


// function to display linked list
void displayLinkedList(struct Details *root)
{
	struct Details *temp = root;
	printf("\nLinkedList: ");

	while(temp!=NULL)
	{
	printf("\n%s, %s, %d, %s  ",temp->stock_name,temp->model_number, temp->count,temp->ventor);
	temp = temp->next;
	}

}

//function to insert new data
void insertData(struct Details *d){

	char stock_name[100];
	char model_number[100];
	int count;
	char ventor[100];

	printf("\nAdding new data to existing linked list\n");
	printf("Enter stock name\n");

	scanf("%s",stock_name);
	fflush(stdin);
	printf("\nEnter model number\n");
	scanf("%s",model_number);
	printf("\nEnter count\n");
	scanf("%d",&count);
	printf("\nEnter Ventor\n");
	scanf("%s",ventor);

	struct Details *temp=(struct Details*)malloc(sizeof(struct Details));
	strcpy(temp->stock_name,stock_name);
	strcpy(temp->model_number,model_number);
	temp->count = count;
	strcpy(temp->ventor,ventor);
	temp->next=d;
	d=temp;
	displayLinkedList(temp);
}

//function to search data
void searchElementByModelNumber(struct Details *head,char item[]){
	
	int flag=0;
	char searchItem[20];	
	struct Details *current = head;	// Initialize current
	strcpy(searchItem,item);

	// traverse till then end of the linked list
	while (current != NULL)
	{
		if (strcasecmp(searchItem,current->model_number)==0)
		{
			flag=1;
			printf("\nstock details are \nstock name: %s,count: %d,ventor: %s\n",current->stock_name,current->count,current->ventor);
	  
		}
		current = current->next;

	}
	if(flag==0)
		printf("stock not available");
}

// function to read data from file
struct Details* readLinkedList() 
{

	FILE* file = fopen("stocks_available.txt", "r");
	if(file == NULL) 
	{
		printf("Failed to open the file.\n");
		return 0;
	}

	struct Details* head = NULL;
	struct Details* current = NULL;
	char line[256];

	while(fgets(line, sizeof(line), file)) 
	{
		
        	char* stock_name = strtok(line, ",");
        	char* model_number = strtok(NULL, ",");
        	char* countstr = strtok(NULL, ",");
        	int count = atoi(countstr);
		char* ventor = strtok(NULL, ",");

			struct Details* newNode = (struct Details*)malloc(sizeof(struct Details));
        		if(newNode == NULL) 
			{
            			printf("Failed to allocate memory for new node.\n");
            			return 0;
        		}

        		// Copy the data fields into the new node
        		strncpy(newNode->stock_name, stock_name,sizeof(newNode->stock_name) - 1);
        		strncpy(newNode->model_number, model_number,sizeof(newNode->model_number) - 1);
        		newNode->count = count;
        		strncpy(newNode->ventor, ventor,sizeof(newNode->ventor)-1);

        		newNode->next = NULL;
			
			// Check if the linked list is empty
        		if(head == NULL) 
			{
				head = newNode;
            			current = newNode;
        		} 
			else 
			{
            			current->next = newNode;
            			current = current->next;
        		}
	
            	}
		

	fclose(file);
	return head;
}
