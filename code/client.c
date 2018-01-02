// including the file containing all the function definitions
#include"functions.c"

int main(void)
{

// making an array to store the sequence of operations
  long long num_of_operations;
  //printf("Enter no. of operations\n");
  scanf("%lld",&num_of_operations);

  int *operations = (int *)malloc(num_of_operations * sizeof(int));
  int x;

// strucure for recording time taken for various operations
  struct timespec start;
  struct timespec end;

// function to insert the sequence of operations into the array
  insert_op(operations,num_of_operations);

// initialising array containing various increase_factors
  float up_factor[5] = {1.25,1.5,1.75,2,3};
// initialising array containing various decrease_at_factors
  float down_factor[3] = {0.25,0.5,0.75};

// declaring 2D-arrays(matrices) to store various statistical values for different combinations of increase_factors & decrease_at_factors
  double max_insert[5][3];
  double max_delete[5][3];
  double avg_op[5][3];
  double avg_insertion[5][3];
  double avg_deletion[5][3];

// declaring variables to store the no. of insertion and deletion operations respectively
  long long insert_count,delete_count;

// initialising variables to store the best value for each statistic
  double best_insert = 999;
  double best_delete = 999;
  double best_avg_all = 999;
  double best_avg_insertion = 999;
  double best_avg_deletion = 999;

  float factor1,factor2,factor3,factor4,factor5,factor6,factor7,factor8,factor9,factor10;

// running the code for all combinations of increase_factors & decrease_at_factors
  for(int m=0;m<5;m++)
  {
    for(int n=0;n<3;n++)
    {
      printf("\nImplementing the dynamic table with Increase_factor = %f and Decrease_at_factor = %f\n\n",up_factor[m],down_factor[n]);

    // initialising the dynamic table
      t = (TABLE *)malloc(sizeof(TABLE));
      t->max_size = 1;
      t->current_size = 0;
      t->increase_factor = up_factor[m];
      t->decrease_at_factor = down_factor[n];
      int *arr = (int *)malloc(sizeof(int));
      arr[0] = 0; // initially I am filling the table with zeroes
      t->data = arr;

    // calling the function which returns the total no. of insertion & deletion operations respectively
      long long *count = total(operations,num_of_operations);

    // insert_count stores total no. of insertions
      insert_count = *count;
    // delete_count stores total no. of deletions
      delete_count = *(count+1);

    // declaring arrays to store the various insertion & deletion timings
      double *insertion_timings = (double *)malloc(insert_count * sizeof(double));
      double *deletion_timings = (double *)malloc(delete_count * sizeof(double));

      int i=0;
      int j=0;

    // applying the sequence of operations on the previously initialised dynamic table
      for(long long k=0;k<num_of_operations;k++)
      {

      // for me 1 means insertion operation
        if(operations[k]==1)
        {

        // calling the insert function & recording the time taken for insertion operation
          clock_gettime(CLOCK_REALTIME, &start);

        // I am inserting a random variable between 0 to 99 into the table
          insert(rand()%100);
          clock_gettime(CLOCK_REALTIME, &end);
          double insert_time = time_elapsed(&start, &end);
          insertion_timings[i++] = insert_time;
        }

      // for me 2 means deletion operation
        else if(operations[k]==2)
        {

        // calling the delete function & recording the time taken for deletion operation
          clock_gettime(CLOCK_REALTIME, &start);
          int y = delete();
          clock_gettime(CLOCK_REALTIME, &end);

        // if the table is empty then delete function returns -999.
        // except for that case in every other case we append the time recorded in the array
          if(y!=-999)
          {
            double delete_time = time_elapsed(&start, &end);
            deletion_timings[j++] = delete_time;
          }
        }
      }

    // displaying the final state of the dynamic table
      display();

    // calling the find_stats function which calculates all statistical values
      double *ptr = find_stats(insertion_timings,deletion_timings,insert_count,delete_count);

      max_insert[m][n] = *ptr;
      max_delete[m][n] = *(ptr+1);
      avg_op[m][n] = *(ptr+2);
      avg_insertion[m][n] = *(ptr+3);
      avg_deletion[m][n] = *(ptr+4);

    // displaying all the calculated statistical values
      display_stats(ptr);

    // freeing all the pointers which are no longer required
      free(t);
      free(ptr);
      free(insertion_timings);
      free(deletion_timings);
    }
  }

// displaying the Matrix containing maximum insertion times
  if(insert_count>0)
  {
  	printf("Matrix containing Maximum Insertion times\nRows represent increase_factors[1.25,1.5,1.75,2,3] and Columns represent decrease_at_factors[0.25,0.5,0.75]\n\n");

  	for(int i=0;i<5;i++)
  	{
    		printf("    ");
    		for(int j=0;j<3;j++)
    		{
      			printf("%lfms  ",max_insert[i][j]);
      			if(max_insert[i][j]<best_insert)
      			{
        			best_insert = max_insert[i][j];
        			factor1 = up_factor[i];
        			factor2 = down_factor[j];
      			}
    		}
    		printf("\n\n");
  	}
   }

// displaying the Matrix containing maximum deletion times
  if(delete_count>0)
  {
  	printf("\nMatrix containing Maximum Deletion times\nRows represent increase_factors[1.25,1.5,1.75,2,3] and Columns represent decrease_at_factors[0.25,0.5,0.75] \n\n");

  	for(int i=0;i<5;i++)
  	{
    		printf("    ");
    		for(int j=0;j<3;j++)
    		{
      			printf("%lfms  ",max_delete[i][j]);
      			if(max_delete[i][j]<best_delete)
      			{
       				best_delete = max_delete[i][j];
        			factor3 = up_factor[i];
        			factor4 = down_factor[j];
      			}
    		}
    		printf("\n\n");
  	}
   }

// displaying the Matrix containing Average time of all Operations
  if((insert_count + delete_count)>0)
  {
  	printf("\nMatrix containing Average time of all Operations\nRows represent increase_factors[1.25,1.5,1.75,2,3] and Columns represent decrease_at_factors[0.25,0.5,0.75] \n\n");

  	for(int i=0;i<5;i++)
  	{
    		printf("    ");
    		for(int j=0;j<3;j++)
    		{
      			printf("%lfns  ",avg_op[i][j]*1000000);
      			if(avg_op[i][j]<best_avg_all)
      			{
        			best_avg_all = avg_op[i][j];
        			factor5 = up_factor[i];
        			factor6 = down_factor[j];
      			}
    		}
    		printf("\n\n");
  	}
   }

// displaying the Matrix containing Average time of all Insertions
  if(insert_count>0)
  {
  	printf("\nMatrix containing Average time of all Insertions\nRows represent increase_factors[1.25,1.5,1.75,2,3] and Columns represent decrease_at_factors[0.25,0.5,0.75] \n\n");

  	for(int i=0;i<5;i++)
  	{
    		printf("    ");
    		for(int j=0;j<3;j++)
    		{
      			printf("%lfns  ",avg_insertion[i][j]*1000000);
      			if(avg_insertion[i][j]<best_avg_insertion)
      			{
        			best_avg_insertion = avg_insertion[i][j];
        			factor7 = up_factor[i];
        			factor8 = down_factor[j];
      			}
    		}
    		printf("\n\n");
  	}
   }

// displaying the Matrix containing Average time of all Deletions
  if(delete_count>0)
  {
  	printf("\nMatrix containing Average time of all Deletions\nRows represent increase_factors[1.25,1.5,1.75,2,3] and Columns represent decrease_at_factors[0.25,0.5,0.75] \n\n");

  	for(int i=0;i<5;i++)
  	{
    		printf("    ");
    		for(int j=0;j<3;j++)
    		{
      			printf("%lfns  ",avg_deletion[i][j]*1000000);
      			if(avg_deletion[i][j]<best_avg_deletion)
      			{
        			best_avg_deletion = avg_deletion[i][j];
        			factor9 = up_factor[i];
        			factor10 = down_factor[j];
      			}
    		}
    		printf("\n\n");
  	}
   }

  printf("\n");

// displaying the best statistical values
  if(insert_count>0)
  {
    printf("The best maximum insertion time is %lf ms\n",best_insert);
    printf("Best increase factor for this is %f\n",factor1);
    printf("Best decrease at factor for this is %f\n\n\n",factor2);
  }

  if(delete_count>0)
  {
    printf("The best maximum deletion time is %lf ms\n",best_delete);
    printf("Best increase factor for this is %f\n",factor3);
    printf("Best decrease at factor for this is %f\n\n\n",factor4);
  }

  if((insert_count + delete_count)>0)
  {
    printf("The best average time for all operations is %lf ns\n",best_avg_all*1000000);
    printf("Best increase factor for this is %f\n",factor5);
    printf("Best decrease at factor for this is %f\n\n\n",factor6);
  }

  if(insert_count>0)
  {
    printf("The best average time for insertion is %lf ns\n",best_avg_insertion*1000000);
    printf("Best increase factor for this is %f\n",factor7);
    printf("Best decrease at factor for this is %f\n\n\n",factor8);
  }

  if(delete_count>0)
  {
    printf("The best average time for deletion is %lf ns\n",best_avg_deletion*1000000);
    printf("Best increase factor for this is %f\n",factor9);
    printf("Best decrease at factor for this is %f\n\n\n",factor10);
  }

return 0;
}
