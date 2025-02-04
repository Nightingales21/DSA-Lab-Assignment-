#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void display(struct node *head) {
    struct node *temp = head;
    printf("Doubly Linked List: \n");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *create(struct node *head,int n) 
{
    struct node *nn,*temp;
    int i,ndata;
    for(i=0;i<n;i++)
    {
        printf("Enter node data %d :",i+1);
        scanf("%d",&ndata);
        nn=(struct node *)malloc(sizeof(struct node));
        nn->data=ndata;
        nn->prev=NULL;
        nn->next=NULL;
        if(head==NULL)
        {
            head=nn;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
            nn->prev=temp;
        }
    }
    return head;
}

struct node *insert_beg(struct node *head,int data)
{
    int ndata,i,n;
    for(i=0;i<n;i++)
    {
    printf("Enter data to be inserted in the beginning :");
    scanf("%d",&ndata);
    struct node *nn,*temp;
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=ndata;
    head->prev=nn;
    head->prev->next=head;
    head=head->prev;
    head->prev=NULL;
    return head;
    }
}

struct node *insert_end(struct node *head,struct node *tail,int data)
{
    int ndata,i,n;
    for(i=0;i<n;i++)
    {
        printf("Enter data to be inserted at the end :");
        scanf("%d",&ndata);
        struct node *nn,*temp;
        nn=(struct node *)malloc(sizeof(struct node));
        if(tail!=NULL)
        {
        nn->data=ndata;
        tail->next=nn;
        tail->next->prev=tail;
        tail=tail->next;
        tail->next=NULL;
        }
        return tail;
    }
}

int main() {
    struct node *head = NULL,*tail=NULL;
    int n,i,ndata;
    printf("Enter the number of nodes to be created: ");
    scanf("%d", &n);
    head=create(head,n);
    head=insert_beg(head,n);
    display(head);
    head=insert_end(head,tail,n);
    display(head);
    return 0;
}