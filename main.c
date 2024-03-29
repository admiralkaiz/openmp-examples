#include <omp.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
  omp_set_num_threads(4);

  time_t start_serial, start_parallel, end_serial, end_parallel;

  time(&start_serial);

  for (int i = 0; i < 4; i++)
    printf("Hello, world!");
  
  time(&end_serial);

  printf("Serial time taken: %f second(s)", (double)end_serial - (double)start_serial);

  time(&start_parallel);

  #pragma omp parallel
  {
    int id = omp_get_thread_num();
    printf("Hello, world! From thread #%d\n", id);
  }

  time(&end_parallel);
  printf("Parallel time taken: %f second(s)", (double)end_parallel - (double)start_parallel);

  return 0;
}
