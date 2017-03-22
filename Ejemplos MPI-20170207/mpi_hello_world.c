// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header in tact.
//
// An intro MPI hello world program that uses MPI_Init, MPI_Comm_size,
// MPI_Comm_rank, MPI_Finalize, and MPI_Get_processor_name.
//
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

void numerosPrimos()
{

   int x;
    for ( x = 0; x < 2000000; x++ ) {

    int num,i,n=4,cont=2,j=0;
    int cad[1000];
    // printf("ingrese un numero\n");
    // scanf("%d",&num);
    num = 100;
    if(num>2){
        printf("2 3");
        while(cont<num){
            i=2;
            while(i<=n){
                if(i==n){
                    cad[j]=n;
                    printf(" %d ",cad[j]);
                    j++;
                    cont=cont+1;
                }else{
                if(n%i==0){
                    i=n;
                }
                }
                i=i+1;
            }
            n=n+1;
        }
    }else{
    if(num>0){
        if(num==1){
            printf(" ");
        }else{
            printf(" ");
        }
    }else{
            printf(" ");
    }
    }
  }
}


int main(int argc, char** argv) {
  // Initialize the MPI environment. The two arguments to MPI Init are not
  // currently used by MPI implementations, but are there in case future
  // implementations might need the arguments.
  MPI_Init(NULL, NULL);

  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  // Get the name of the processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);

  // Print off a hello world message
  // printf("Hello world from processor %s, rank %d out of %d processors\n",
    // processor_name, world_rank, world_size);

    numerosPrimos();

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();
}






