struct Details
{
    char stock_name[100];
    char model_number[100];
    int count;
    char ventor[100];
    struct Details *next;
};

//function to display linked list
void displayLinkedList(struct Details *root);

//Function to insert the data
void insertData(struct Details *d);

//search data using model number
void searchElementByModelNumber(struct Details *head,char item[]);

//function to read data from this stocks_available.txt file and store in single linked list structure
struct Details* readLinkedList();
