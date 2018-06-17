#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
     int data;
     struct node *next;
}ppn,*pn;

pn init_list()
     {
          int len,i,temp;
          printf("Please input how many long the list is :\n");
          scanf("%d",&len);
          pn head = malloc(sizeof(ppn));
          head->next = NULL;
          pn tail = head;
          for(i = 0;i < len;i++)
               {
                    printf("Please input number:\n");
                    scanf("%d",&temp);
                    pn new = malloc(sizeof(ppn));
                    new->data = temp;
                    new->next = NULL;
                    tail->next = new;
                    tail = new;
               }
          return head;
     }

void tra_list(pn head)
     {
          pn t;
          t = head;
          while(t != NULL)
               {
                    if(t != head)
                         printf("%d ",t->data);
                    t = t->next;
               }
          printf("\n");
     }

void isempty(pn head)
     {
          if(head->next == NULL)
               printf("The list is empty!\n");
          else
               printf("The list is not empty!\n");
     }
void length_list(pn head)
     {
          int sum = 0;
          pn t;
          t = head;
          while(t->next != NULL)
               {
                    sum++;
                    t = t->next;
               }
          printf("List length is %d\n",sum);
     }

void insert_list(pn head,int i,int n)
     {
          int j = 0;
          pn p;
          p = head;
          while(p->next != NULL && j < i - 1)
               {
                    j ++;
                    p = p->next;
               }
          if(p == NULL || j > i -1)
               printf("Insert location is not allowed!\n");
          else
               {    
                    pn new = malloc(sizeof(ppn));
                    new->next = p->next;
                    p->next = new;
                    new->data = n;
                    printf("You have inserted %d\n",n);
               }
     }

void del_list(pn head,int n)
     {
          pn p = head;
          pn w;
          while(p->next->data != n && p->next != NULL)
               p = p->next;
          if(p->next == NULL && p->data != n)
               printf("There is no %d\n",n);
          else
               {
                    w = p->next;
                    p->next = w->next;
                    free(w);
                    printf("You have deleted %d\n",n);
               }
     }

int main()
     {
          int n,d,i;
          pn head;
          while(1)
               {
                    printf("You can choose the following options\n");
                    printf("1.Init_list()   2.tra_list()   3.isempty?()   4.length_list()  5.insert_list()  6.del_list()  7.exit()\n");
                    scanf("%d",&n);
                    if(n == 7)
                         break;
                    switch(n)
                         {
                         case 1:
                              head = init_list();
                              break;
                         case 2:
                              tra_list(head);
                              break;
                         case 3:
                              isempty(head);
                              break;
                         case 4:length_list(head);
                              break;
                         case 5:
                              printf("Please input a number and location which you want to insert:\n");
                              scanf("%d%d",&i,&d);
                              insert_list(head,i,d);
                              break;
                         case 6:
                              printf("Please input a number which you want to delete:\n");
                              scanf("%d",&d);
                              del_list(head,d);
                              break;
                         default:
                              printf("Input error!\n");
                         }
               }
          return 0;
     }


