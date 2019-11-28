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
conta from, to;
int valor;
// The child thread will execute this function

int transferencia_deposito( void *threadarg)
{

    if (from.saldo >= valor){

   from.saldo -= valor;
    to.saldo += valor;

    }

 printf("Transferência concluída com sucesso!\n");
printf("Saldo de c1: %d\n", from.saldo);
printf("Saldo de c2: %d\n", to.saldo);
 return 0;
 pthread_exit(0);

}
int main()
{

    pthread_mutex_t mutexsum;
    printf("----------------------Escolha a opção:--------------------------\n");
    printf("1. A conta to pode receber mais de uma transferência simultânea.\n");
    printf("2. A conta from pode enviar mais de uma transferência simultânea.\n");
    printf("3.A conta from não pode enviar dinheiro se não tiver mais saldo.\n");
    printf("4.A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar.\n");
    printf("5.Poderão ser realizadas até 100 transações simultâneas de transferência.");

 void* stack;
pid_t pid;
 int i;

from.saldo = 100;
 to.saldo = 100;
 printf( "Transferindo 1 para a conta c2\n" );
valor = 1;
for (i = 0; i < 100; i++) {
  pthread_t t1;


  pthread_create (&t1, NULL,(void*)transferencia_deposito, NULL);
  pthread_mutex_lock (&mutexsum);

   perror( "clone" );
  pthread_mutex_unlock (&mutexsum);
pthread_join (t1, NULL);
   }

 printf("Transferênciasssssssssss concluídas e memória liberada.\n");
return 0;
}

