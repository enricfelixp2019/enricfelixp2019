#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
// 64kB stack
#define FIBER_STACK 1024*64
pthread_mutex_t mutexsum; 
struct c {
int saldo;
};
typedef struct c conta;
conta from, to;
int valor;
// The child thread will execute this function

int transferencia_deposito( void *threadarg){
   
    if (from.saldo >= valor){
      pthread_mutex_lock (&mutexsum);
      from.saldo -= valor;
      to.saldo += valor;
      pthread_mutex_unlock (&mutexsum);

    }

printf("Transferência concluída com sucesso!\n");
printf("Saldo de c1: %d\n", from.saldo);
printf("Saldo de c2: %d\n", to.saldo);

return 0;


}

int transferencia_inversa( void *threadarg){
    if (to.saldo>valor){
      pthread_mutex_lock (&mutexsum);
      to.saldo -= valor;
      from.saldo += valor;
      pthread_mutex_unlock (&mutexsum);
    }

printf("Transferência concluída com sucesso!\n");
printf("Saldo de c1: %d\n", from.saldo);
printf("Saldo de c2: %d\n", to.saldo);
 return 0;
 

}


int main(){
   
int cont=0;
 void* stack;
pid_t pid;
 int i;

 from.saldo = 100;
 to.saldo = 100;

 printf( "Transferindo 2 para a conta c2\n" );
valor = 2;
pthread_t t1,t2;

  
           
            
   for (int j = 1; j <= 50; j++){

            pthread_create (&t2, NULL,(void*)transferencia_inversa, NULL);
            

            perror( "clone" );
          
            
            pthread_join (t2, NULL);
             cont ++;
            printf("contador=%d\n",cont);
   }


for (int k = 1; k<=50 ; k++) {
            
            
            
    
            pthread_create (&t1, NULL,(void*)transferencia_deposito, NULL);
            
            perror( "clone" );

            pthread_join (t1, NULL);
            cont ++;
            printf("contador=%d\n",cont);
    
  }
    printf("Transferências concluídas e memória liberada.\n");
    return 0;
    }
