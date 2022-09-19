#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

 struct node
{
        int info;
        struct node *next;
};

struct node *start=NULL;
void create();
void display();
void add_begin();
void add_end();
void add_pos();
void remove_begin();
void remove_end();
void remove_pos();
void read();
void deserialize(struct node** root);
void add_end1(struct node** root, int value);
void serialize(struct node** root);
void reverse(struct node** head_ref);
void swap(struct node *a, struct node *b);
void sort(struct node **start);
void search();
void joinTwoLists();

int main()     
{
        int choice;
        while(1){
                printf("   \n");
                printf("   \n");
                printf("              ^^ Commands ^^               \n");
                printf("   \n");
                printf(" *** 1. Create the list.                *** \n");
                printf(" *** 2. Display it.                     *** \n");
                printf(" *** 3. Add a value at the beginning.   *** \n");
                printf(" *** 4. Add a value at the end.         *** \n");
                printf(" *** 5. Add a value at a position.      *** \n");
                printf(" *** 6. Remove a value from beginning.  *** \n");
                printf(" *** 7. Remove a value from the end.    *** \n");
                printf(" *** 8. Remove a value from a position. *** \n");
                printf(" *** 9. Append from file.               *** \n");
                printf(" *** 10. Write to file.                 *** \n");
                printf(" *** 11. Reverse.                       *** \n");
                printf(" *** 12. Sort.                          *** \n");
                printf(" *** 13. Search for a value.            *** \n");
                printf(" *** 14. Join 2 lists.                  *** \n");
                printf(" *** 15. Exit.                          *** \n");
                printf("   \n");
                printf("Enter command: \t");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        add_begin();
                                        break;
                        case 4:
                                        add_end();
                                        break;
                        case 5:
                                        add_pos();
                                        break;
                        case 6:
                                        remove_begin();
                                        break;
                        case 7:
                                        remove_end();
                                        break;
                        case 8:
                                        remove_pos();
                                        break;
                        case 9:
                                        deserialize(&start);
                                        break;
                        case 10:
                                        serialize(&start);
                                        break;
                        case 11:
                                        reverse(&start);
                                        break;
			case 12:
                                        sort(&start);
                                        break;
                        case 13:
                                        search();
                                        break;
                        case 14:
                                        joinTwoLists();
                                        break;
                        case 15:
                                        return 0;
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
void create(){
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        int a;
        printf("\n How many elements will the list have? : ");
        scanf("%d", &a);
        for(int i = 1; i <= a; i++){
            add_begin();
        }
}

void display(){
        struct node *ptr;
        if(start==NULL)
        {
                printf("\n The list has no elements: \t");
                return;
        }
        else
        {
                ptr=start;
                printf("\n The present elements in list are: \t");
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->info );
                        ptr=ptr->next;
                }
        }
}
void add_begin(){
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL) 
        {
                printf("\n Out of Memory Space: \n");
                return;
        }
        printf("\n Enter the value: \t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void add_end(){
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL) 
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf(" Enter the value: \t" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void add_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf("Enter the position:\t");
        scanf("%d",&pos);
        printf("Enter the value:\t");
        scanf("%d",&temp->info) ;
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) {
                    ptr=ptr->next;
                        if(ptr==NULL)  
                        {
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void remove_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("The list has no elements:\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("The deleted element is :%d\t",ptr->info);
                free(ptr);
        }
}
void remove_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("The list has no elements:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("The deleted element is: %d\t",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("The deleted element is: %d\t",ptr->info);
                free(ptr);
        }
}
void remove_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe list has no elements:\n");
                exit(0);
        }
        else
        {
                printf("Enter the position:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("The deleted element is:%d\t",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info );
                        free(ptr);
                }
        }
}

void add_end1(struct node** root, int v) {
    struct node* new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node -> info = v;
    
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    
    struct node* curr = *root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void deserialize(struct node** root) {
    FILE* file = fopen("./file.txt", "r");
    if (file == NULL) {
        exit(0);
    }

    int val;
    while(fscanf(file, "%d\n", &val) > 0) {
        add_end1(root, val);
    }
    fclose(file);
    file = fopen("./file.txt", "w");
    fclose(file);
}

void serialize(struct node** root) {
    FILE* file = fopen("./file.txt", "w");
    if (file == NULL) {
        exit(1);
    }

    for (struct node* curr = *root; curr != NULL; curr = curr->next) {
        fprintf(file, "%d\n", curr->info);
    }
    fclose(file);
}

void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* present = *head_ref;
    struct node* next = NULL;
    while (present != NULL) {
        next = present->next;
        present -> next = prev;
        prev = present;
        present = next;
    }
    *head_ref = prev;
}

void sort(struct node **start){ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = *start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->info > ptr1->next->info) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
void swap(struct node *x, struct node *y){ 
    int temp = x->info; 
    x->info = y->info; 
    y->info = temp; 
}

void search(){
	int x;
	bool y = false;
	printf("\nIntroduce the number: ");
	scanf("%d", &x);
    struct node *present = start;
    while (present != NULL) {
        if (present->info == x){
        	y = true;
        }
        present = present->next;
    }

    if(y){
		printf("\nTrue\n");
	}
	else{
		printf("\nFalse\n");
	}
}

void joinTwoLists(){
	struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    int x;
    printf("\n How many elements will the second list have? : ");
    scanf("%d", &x);
    for(int i = 1; i <= x; i++){
   	printf("\n Enter the %d: \t", i);
    scanf("%d",&temp->info);
    temp->next = NULL;
    add_end1(&start, temp->info);
    }
}
