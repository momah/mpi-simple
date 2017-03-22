#include <stdio.h>
#include <string.h>
#include "mpi.h"


int main(int argc, char **argv) {
  int dest, tag, rc, i;
  MPI_Status status;
  char message[20];

  /* Comienza las llamadas a MPI */
  rc = MPI_Init(&argc, &argv);

  /* Averiguamos el número de procesos que estan 
   * ejecutando nuestro porgrama 
   */ 
  int size;
  rc = MPI_Comm_size(MPI_COMM_WORLD, &size);
  
  /* Averiguamos el rango de nuestro proceso */
  int rank;
  rc = MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // Get the name of the processor
  //char processor_name[MPI_MAX_PROCESSOR_NAME];
  //int name_len;
  //MPI_Get_processor_name(processor_name, &name_len);


  tag = 100;
	
/*  
  if(rank == 0) {
    strcpy(message, "Hello, world");
    for (i = 1; i < size; i++) 
      rc = MPI_Send(message, 13, MPI_CHAR, i, tag, MPI_COMM_WORLD);
  } 
  else 
    rc = MPI_Recv(message, 13, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
*/


    if (rank != 0) {
        /* Crea mensaje */
        sprintf(message, "Hello, world from %d", rank);
        /* Usa strlen+1 para que la marca /0 se transmita */
        rc = MPI_Send(message, strlen(message)+1, MPI_CHAR, 
            dest, tag, MPI_COMM_WORLD);
    } else { /* rank == 0 */
        for (i = 1; i < size; i++) {
            rc = MPI_Recv(message, 100, MPI_CHAR, i,
                tag, MPI_COMM_WORLD, &status);
            printf("%s\n", message);
        }
    }


  //printf( "node %d : %.13s\n", rank, message);
  rc = MPI_Finalize();
}

