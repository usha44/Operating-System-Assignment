#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int balance = 1000;
pthread_mutex_t lock;

// 1. Deposit Thread 
void *deposit(void *arg)
{ 
  for(int i= 0; i<3; i++);
  {

    pthread_mutex_lock(&lock);
    balance += 100;
    printf("Deposit: Balance = %d\n", balance);
    pthread_mutex_unlock(&lock);
    sleep(1);
   }
   return NULL;
}

//2. Withdraw Thread 
void *withdraw(void *arg)
{
  for (int i = 0; i < 3; i++)
  {
    pthread_mutex_lock(&lock);
    balance -= 50;
    printf("Withdraw: Balance =%d\n", balance);
    pthread_mutex_unlock(&lock);
    sleep(1);
   }
   return NULL;
}


//3. Balance Thread 
void *checkBalance(void *arg)
{
  for(int i = 0; i < 3; i++)
  {
    pthread_mutex_lock(&lock);
    printf("Current Balance = %d\n", balance);
    pthread_mutex_unlock(&lock);
    sleep(1);
   }
   return NULL;
}

int main()
{
    pthread_t t1, t2, t3;
    pthread_mutex_init(&lock,NULL);
    pid_t pid = fork();
    if (pid == 0)
    {
       printf("Child Process Created\n");
       return 0;
     }
     else 
     {
       printf("Parent Process Created\n");
       pthread_create(&t1, NULL, deposit, NULL);
       pthread_create(&t2, NULL, withdraw, NULL);
       pthread_create(&t3, NULL, checkBalance, NULL);

       pthread_join(t1, NULL);
       pthread_join(t2, NULL);
       pthread_join(t3, NULL);

       printf("\nRound Robin Scheduling\n");
       printf("Turn 1 = Deposit Tread\n");
       printf("Turn 2 = Withdraw Thread\n");
       printf("Turn 3 = Balance Thread\n");
   
       wait(NULL);
   
       printf("\nFinal Balance = %d\n", balance);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
 

