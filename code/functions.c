// including the header file containing all function prototypes & structure definition
#include"header.h"

// defining a function to create the sequence of operations
void insert_op(int *a,long long b)
{
  a[0] = 1;
  for(long long i=1;i<b;i++)
  {
    a[i] = rand()%2 + 1;
  }
}

// defining a function to calculate total no. of insertion & deletion operations
long long *total(int *a,long long b)
{
  long long count1 = 0;
  long long count2 = 0;

  for(long long i=0;i<b;i++)
  {
    if(a[i] == 1)
    {
      count1 ++;
    }
    else
    {
      count2 ++;
    }
  }

  long long *arr = (long long *)malloc(2 * sizeof(long long));
  *arr = count1;
  *(arr+1) = count2;
  return arr;
}

// defining a function to carry out insertion operation
void insert(int x)
{

// if the table is already full we need to increase its size by the increase_factor
  if(t->current_size == t->max_size)
  {
    int *arr1 = (int *)realloc(t->data,ceil(t->increase_factor*t->max_size*sizeof(int)));
    for(long long i=t->max_size;i<ceil(t->increase_factor*t->max_size);i++)
    {
      *(arr1+i) = 0;
    }
    *(arr1+t->max_size) = x;
    t->data = arr1;
    t->current_size += 1;
    t->max_size = ceil(t->max_size * t->increase_factor);
  }

// else we just insert a new value and increase the current_size by 1
  else
  {
    *(t->data+t->current_size) = x;
    t->current_size += 1;
  }
}

// defining a function to carry out deletion operation
int delete()
{

// if table is empty then we return -999
  if(t->current_size == 0)
  {
      //printf("\nThe table is empty\n");
    return(-999);
  }

// else if the fraction of elements in the table is greater than the decrease_at_factor, then we just assign the last element as 0 and decrement the current_size by 1
  else if((float)t->current_size/t->max_size > t->decrease_at_factor)
  {
    int k = *(t->data+t->current_size-1);
    *(t->data+t->current_size-1) = 0;
    t->current_size -= 1;
    return k;
  }

// else we decrease the size of the table by the same factor as the increase_factor if there is no data loss happening
  else
  {

  // no data lost so, decrease the table size
    if(((float) 1/t->increase_factor)*t->max_size >= (t->current_size))
    {
      int k = *(t->data+t->current_size-1);
      *(t->data+t->current_size-1) = 0;
      int *arr2 = (int *)realloc(t->data,ceil(((float) 1/t->increase_factor)*t->max_size*sizeof(int)));
      t->current_size -= 1;
      t->max_size = ceil(((float) 1/t->increase_factor)*t->max_size);
      t->data = arr2;
      return k;
    }

  // data is getting lost so we don't decrease the table size
    else
    {
      int k = *(t->data+t->current_size-1);
      *(t->data+t->current_size-1) = 0;
      t->current_size -= 1;
      return k;
    }
  }
}

// defining a function to display the current state of the table
void display()
{
  printf("The current state of the Table is  [ ");
  for(long long i=0;i<t->max_size;i++)
  {
    printf("%d ,",*(t->data+i));
  }
  printf("]\n\n");
}

// defining a function to calculate various statistical values
double *find_stats(double *a,double *b,int c1,int c2)
{
  double max_insertion = -1;
  double max_deletion = -1;
  double avg_all = 0;
  double avg_insert = 0;
  double avg_delete = 0;

  if(c1>0)
  {
    for(int i=0;i<c1;i++)
    {
      if(*(a+i)>max_insertion)
      {
        max_insertion = *(a+i);
      }
      avg_all += *(a+i);
      avg_insert += *(a+i);
    }
  }

  if(c2>0)
  {
    for(int j=0;j<c2;j++)
    {
      if(*(b+j)>max_deletion)
      {
        max_deletion = *(b+j);
      }
      avg_all += *(b+j);
      avg_delete += *(b+j);
    }
  }

  avg_all = (float) avg_all/(c1+c2) ;
  avg_insert = (float) avg_insert/c1;
  avg_delete = (float) avg_delete/c2;

  double *arr = (double *)malloc(4 * sizeof(double));
  *(arr) = max_insertion;
  *(arr+1) = max_deletion;
  *(arr+2) = avg_all;
  *(arr+3) = avg_insert;
  *(arr+4) = avg_delete;

  return arr;
}

// defining a function to display all the calculated statistical values
void display_stats(double *z)
{

  if(*z < 0)
  {
    printf("No insertions done\n");
  }
  else
  {
    printf("Maximum time for insertion is  %lf ms\n",*z);
  }
  if(*(z+1) < 0)
  {
    printf("No deletions done\n");
  }
  else
  {
    printf("Maximum time for deletion is  %lf ms\n",*(z+1));
  }
  printf("Average time for all operations is  %lf ms\n",*(z+2));
  if(*z < 0)
  {
    printf("No insertions done\n");
  }
  else
  {
    printf("Average time for all insertions is  %lf ms\n",*(z+3));
  }
  if(*(z+1) < 0)
  {
    printf("No deletions done\n");
  }
  else
  {
    printf("Average time for all deletions is  %lf ms\n\n\n",*(z+4));
  }
  printf("\n");
}
