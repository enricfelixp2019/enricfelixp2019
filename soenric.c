#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
// 64kB stack
#define FIBER_STACK 1024*64
struct c {
int saldo;
};
typedef struct c conta;
conta from, to,aux;
int valor;
// The child thread will execute this function

int transferencia_deposito( void *threadarg)
{pthread_mutex_t mutexsum;
  for (int i = 0; i < 50; i++) {
    if (from.saldo >= valor){
  pthread_mutex_lock (&mutexsum);
   from.saldo -= to.saldo;
    to.saldo += from.saldo;
  pthread_mutex_unlock (&mutexsum);
    }
    }

 printf("Transferência concluída com sucesso!\n");
printf("Saldo de c1: %d\n", from.saldo);
printf("Saldo de c2: %d\n", to.saldo);
 return 0;
 pthread_exit(0);

}

int transferencia_inversa( void *threadarg)
{pthread_mutex_t mutexsum;
  for (int j = 0; j < 50; j++) {
    if (to.saldo>=from.saldo){
  pthread_mutex_lock (&mutexsum);
   to.saldo -= from.saldo;
    from.saldo += to.saldo;
  pthread_mutex_unlock (&mutexsum);
    }
    }

printf("Transferência concluída com sucesso!\n");
printf("Saldo de c1: %d\n", from.saldo);
printf("Saldo de c2: %d\n", to.saldo);
 return 0;
 pthread_exit(0);

}


int main()
{



 void* stack;
pid_t pid;
 int i;

from.saldo = 100;
 to.saldo = 100;

 printf( "Transferindo 1 para a conta c2\n" );
valor = 1;


            
            pthread_t t1,t2;


            pthread_create (&t1, NULL,(void*)transferencia_deposito, NULL);
            

            perror( "clone" );
            
            pthread_join (t1, NULL);
            

            pthread_create (&t2, NULL,(void*)transferencia_inversa, NULL);
          

            perror( "clone" );
        
            pthread_join (t2, NULL);

    return 0;
            
            
            
            

        printf("Transferências concluídas e memória liberada.\n");
    }
