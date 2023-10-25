#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *next;
}*head=NULL;


void pushFront()
{
    struct Node *node=(struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter Data for the node to be inserted at front : ");
    scanf("%d",&node->info);
    node->next=NULL;
    if(head==NULL)
    {        
        head=node;
    }
    else
    {
        node->next=head;
        head=node;
    }    
}

void pushEnd()
{
    struct Node *node=(struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter Data for the node to be inserted at end : ");
    scanf("%d",&node->info);
    node->next=NULL;
    if(head==NULL)
    {
        head=node;
    }
    else
    {
        struct Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;            
        }        
        temp->next=node;
    }    
}

void pushAscending()
{
    struct Node *node=(struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter Data for the node to be inserted in ascending order of info field in between the list : ");
    scanf("%d",&node->info);
    node->next=NULL;
    if(head==NULL)
    {
        printf("\nSingly link list is empty, you must have atleast two elements one at front and one at end.");
    }
    else if(head->next==NULL)
    {
        printf("\nSingly link list is having only a single element, you must have atleast two elements one at front and one at end.");               
    }
    else
    {        
        struct Node *temp=head;
        while(temp->next->info<node->info && temp->next->next!=NULL)
        {            
            temp=temp->next;                  
        }        
        node->next=temp->next;
        temp->next=node;    
    }    
}

void popFront()
{
    if(head==NULL)
    {
        printf("\nSingly link list is already empty, you cannot delete anything from the list.");
    }
    else if(head->next==NULL)
    {
        printf("\nDeleted element is : %d", head->info);
        head=NULL;
    }
    else
    {
        struct Node *temp;        
        printf("\nDeleted element is : %d", head->info);
        temp=head;
        head=head->next;
        free(temp);
    }
}

void popBefore()
{
    int pos=0, count=0;
    struct Node *temp=head, *temp1=NULL;
    if(head==NULL)
    {
        printf("\nYour Singly List is empty...");
    }
    else
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        printf("\nEnter position before which you want to delete an element : ");
        scanf("%d",&pos);    
        if(pos<=1 || pos>count+1)
        {
            printf("\nElement doesnot exist...");
        }
        else if(pos==2)
        {
            temp1=head;
            printf("\nDeleted element is : %d", head->info);
            head=head->next;
            free(temp1);
        }
        else
        {
            count=0;
            temp=head;
            while(count<pos-3)
            {
                temp=temp->next;
                count++;
            }
            temp1=temp->next;
            printf("\nDeleted element is : %d", temp1->info);
            temp->next=temp1->next;
            free(temp1);
        }
    }
    
}

void popAfter()
{
    int pos=0, count=0;
    struct Node *temp=head, *temp1=NULL;
    if(head==NULL)
    {
        printf("\nYour Singly List is empty...");
    }
    else
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        printf("\nEnter position before which you want to delete an element : ");
        scanf("%d",&pos);    
        if(pos>count)
        {
            printf("\nElement doesn't exist...");
        }
        else
        {
            count=0;
            temp=head;
            while(count<pos-1)
            {
                temp=temp->next;
                count++;
            }
            temp1=temp->next;
            printf("\nDeleted element is %d", temp1->info);
            temp->next=temp1->next;
            free(temp1);
        }
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nYour Singly List is Empty...");
    }
    else
    {
        struct Node *temp=head;
        while(temp!=NULL)
        {
            printf(" %d ", temp->info);
            temp=temp->next;
        }
    }
}

int main()
{
    int ch=0;
    do
    {
        printf("\nEnter 1. to Insert node at the front of the Singly List.");
        printf("\nEnter 2. to Insert node at the end of the Singly List.");
        printf("\nEnter 3. to Insert node in ascending order of info field in between the Singly List.");
        printf("\nEnter 4. to Delete first node from the Singly List.");
        printf("\nEnter 5. to Delete the node before specified position from the Singly List.");
        printf("\nEnter 6. to Delete the node after specified position from the Singly List.");
        printf("\nEnter 7. to Display the Singly List.");
        printf("\nEnter 8. to Exit.");
        printf("\nEnter your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                pushFront();
                break;
            case 2:
                pushEnd();
                break;
            case 3:
                pushAscending();
                break;
            case 4:
                popFront();
                break;
            case 5:
                popBefore();
                break;
            case 6:
                popAfter();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("\nInvalid option selected.");
        }
    }while(ch>=1 && ch<=8);
    return 0;
}