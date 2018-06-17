#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ER 1
#define OK 0
#define length 100

typedef struct list
{
     int *data;
     int len;
}l;

int init_list(l *a)
     {
          a->data = ( int *)malloc( sizeof( int )*length);
          a->len = 0;
          memset(a->data,'a',sizeof(int)*length);
          if(!a->data)
               {
                    printf( "List init error!\n");
                    return ER;
               }
          else
               {
                    printf( "List has init!\n");
                    return OK;
               }
     }
int chaxun(l *a)
{
          int i;
          if((char)a->data[a->len - 1] == 'a')
               {
                    a->len --;
                    chaxun(a);
               }
          else
               return OK;
}
int destroy_list(l *a)
     {
          free(a->data);
          if( a->data)
               {
                    printf( "list do not destroyed!\n");
                    return ER;
               }
          else
               {
                    printf( "list has destroyed!\n");
                    return OK;
               }
     }
int clear_list(l *a)
     {
          int i;
          if( a->len == 0)
               {
                    printf( "list is clear!\n");
                    return ER;
               }
          else
               {
                    for( i = 0;i < a->len;i++)
                         a->data[i] = 'a';
                    a->len = 0;
                    printf( "list has cleared!\n");
                    return OK;
               }
     }

int isempty( l *a)
     {
          if( a->len == 0)
               {
                    printf( "it is empty!\n");
                    return OK;
               }
          else
               {
                    printf( "it is not empty!\n");
                    return ER;
               }
     }
int len_list( l *a)
     {
          printf( "the length is %d\n",a->len);
          return a->len;
     }
int get_elem( l *a,int i,int *n)
     {
          if( isempty( a))
               {
                    printf( "it is empty!\n");
                    return ER;
               }
          else
               {
                    *n = a->data[ i];
                    printf( "you got %d\n",*n);
                    return OK;
               }
     }

int locate_elem(l *a,int n,int *i)
     {
          int b,c = 0;
          for(b = 0;b < a->len;b++ )
               {
                    if( a->data[b] == n)
                         {
                              c = 1;
                              *i = b+1;
                              printf( "the location is %d\n",*i);
                              return OK;
                         }
               }
          if( c == 0)
               return ER;
     }

int delete_elem(l *a,int n)
     {
          int i,j;
          if(locate_elem(a,n,&i) && !isempty(a))
               return ER;
          for( j = i;j<a->len;j++)
               a->data[j-1] = a->data[j];
          a->data[a->len - 1] = 'a';
          a->len --;
          chaxun(a);
          return OK;
     }
int insert_elem(l *a,int i,int n)
     {
          int j;
          if(a->len <= length - 1 && i < length && i >= 1)
               {
                    for(j = a->len -1;j > i-2;j--)
                         a->data[j+1] = a->data[j];
                    a->data[i-1] = n;
                    if( i> a->len)
                         a->len = i;
                    else
                         a->len ++;
                    printf( "you have inserted %d\n",n);
                    return OK;
               }
          else
               {
                    printf( "error!\n");
                    return ER;
               }
     }
int next_elem(l *a,int n,int *n1)
     {
          int i;
          if( a->len <= length -1 && !locate_elem( a,n,&i))
               {
                    *n1 = a->data[i];
                    printf( "the next is %d\n",*n1);
                    return OK;
               }
          else
               {
                    printf( "no next!\n");
                    return ER;
               }
     }
int pre_elem(l *a,int n,int *n1)
     {
          int i;
          if( a->len >= 2 && !locate_elem( a,n,&i))
               {
                    *n1 = a->data[i-2];
                    printf( "the pre is %d\n",*n1);
               }
          else
               {
                    printf( "no pre!\n");
                    return ER;
               }
     }
int bb(l *a)
     {
          int i;
          for( i = 0;i<length;i++)
               printf( "%d ",a->data[i]);
          return OK;
     }
int tra_list(l *a)
     {
          int i;
          if(!isempty(a))
               {
                    printf( "it is empty!\n");
                    return ER;
               }
          for( i = 0;i<a->len;i++)
               {
                    if((char)a->data[i] != 'a')
                         printf( "%d ",a->data[ i]);
                    else
                         printf( "0 ");
               }
          printf( "\n");
          return OK;
     }


int main( )
     {
          l a;
          int n,m,i;
          while(1)
               {
                    printf("1:init_list,2:destroy_list,3:clear_list,4:isempty,5:len_list,6:get_elem\n7:locate_elem,8:delete_elem,9:insert_elem,10:pre_elem,11:next_elem,12:tra_list\n");
                    scanf( "%d",&n);
                    if( n == 0)
                         break;
                    switch( n)
                         {
                         case 1:
                              init_list(&a);
                              break;
                         case 2:
                              destroy_list(&a);
                              break;
                         case 3:
                              clear_list(&a);
                              break;
                         case 4:
                              isempty(&a);
                              break;
                         case 5:
                              len_list(&a);
                              break;
                         case 6:
                              get_elem(&a,i,&m);
                              break;
                         case 7:
                              printf( "please input number you want to locate:\n");
                              scanf( "%d",&m);
                              locate_elem(&a,m,&i);
                              break;
                         case 8:
                              printf( "please input number you want to delete:\n");
                              scanf( "%d",&m);
                              delete_elem(&a,m);
                              break;
                         case 9:
                              printf( "please input number and locate you want to insert:\n");
                              scanf( "%d%d",&m,&i);
                              insert_elem(&a,i,m);
                              break;
                         case 10:
                              printf( "please input number:\n");
                              scanf( "%d",&m);
                              pre_elem(&a,m,&i);
                              break;
                         case 11:
                              printf( "please input number:\n");
                              scanf( "%d",&m);
                              next_elem(&a,m,&i);
                              break;
                         case 12:
                              tra_list(&a);
                              break;
                         case 13:
                              bb(&a);
                         }
               }
          return 0;
     }
