#include <stdio.h>
#include <mpi/mpi.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    int rank, size, time_ej;
    time_t inicio, actual;
    MPI_Status estado;

    //SEGUNDOS QUE SE EJECUTARA EL PROGRAMA
    /*printf("Ingrese tiempo de ejecucion (en segundos): ");
    scanf("%d",&time_ej);*/

    //time_ej sera 10 segundos
    time_ej=10;


    MPI_Init(&argc, &argv); // Inicializamos la comunicacion de los procesos
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtenemos el numero total de hebras
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtenemos el valor de nuestro identificador

    //tiempo de inicio de la ejecucion del programa
    inicio = time(NULL); 

    for (int i=1; actual!=inicio+time_ej; i++){ 
      for (int j=0; j<=size; j++){  
        actual = time(NULL);
        if(i==1){
          if(rank == j){
            int fin_i= (i*(j+1)*(size-1)); 
            int ini_i= (fin_i-(size-1));
            primos(ini_i,fin_i);
          }
        }else{
          if(rank == j){
            int fin_i= (i*((j+1)+size)*(size-1));
            int ini_i= (fin_i-(size-1));
            primos(ini_i,fin_i);
          }
        }
      }
      actual = time(NULL); 
    }

    MPI_Finalize(); //Finalizar los procesos
    printf("Tiempo inicio: %ld Tiempo final: %ld \n", inicio, actual);
    return 0;
}

//funcion para encontrar un primo en un intervalo [inicio,final]
int primos(int i, int f){
  for (i; i<f ; i++){
    if(i>1){
      bool prime=true;
        for (int j=2; j*j<=i; j++){
            if (i % j == 0) {
                prime=false;
                break;    
            }
        }   
        if(prime) printf("Numero: %d \n", i);
    }
  }
}