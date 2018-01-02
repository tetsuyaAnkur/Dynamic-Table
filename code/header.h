// including various built-in libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double time_elapsed(struct timespec *start, struct timespec *end);

// defining the data_strucure to hold all the information related to dynamic table
struct table
{
  long long max_size;
  long long current_size;
  float increase_factor;
  float decrease_at_factor;
  int *data;
};

typedef struct table TABLE;

// creating a pointer variable of type TABLE
TABLE *t;

// defining a function which returns the time_elapsed in ms
double time_elapsed(struct timespec *start, struct timespec *end)
{
	double t = 0.0;
	t = (end->tv_sec - start->tv_sec) * 1000;
	t += (end->tv_nsec - start->tv_nsec) * 0.000001;
	return t;
}

// various function prototypes
void insert_op(int *,long long);
long long *total(int *,long long);
void insert(int);
int delete();
void display();
double *find_stats(double *,double *,int,int);
void display_stats(double *);
