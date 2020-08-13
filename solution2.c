#include <stdio.h> 
#include <semaphore.h> 
#include <pthread.h> 

#define N 5 //the number of philosophers 
sem_t S[N]; //semaphores for chopsticks 
void * philospher( void * num ); 
void take_chopsticks(int); 
void put_chopsticks(int); 
int phil_num[ N ]={0,1,2,3,4}; //philosopher ID 
//link used as resource https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/
//using macros to hardcode the values by giving a meaningful name with a constant
#define THINK 0
#define HUNGRY 1
#define EAT 2

#define LEFT (ph_num + 4) % N 
#define RIGHT (ph_num + 1) % N 
  

int state[N]; //used to find the state of the philosopher aka thinking, hungry or eating
int main() 
{ 
	int i; 
	pthread_t thread_id[ N ]; 
		for (i=0;i< N ;i++) 
			sem_init(&S[i],0,1); 
		for (i=0;i< N ;i++) 
			pthread_create(&thread_id[i], NULL ,philospher,&phil_num[i]); 
		for (i=0;i< N ;i++) 
		pthread_join(thread_id[i], NULL ); 
}

void *philospher( void * num ) 
{ 
	while (1) { 
		int *i = num ; 
		take_chopsticks(*i); 
		put_chopsticks(*i); 
	} 
} 
void take_chopsticks( int ph_num ) 
{ 
	printf( "Philosopher %d is Hungry\n" , ph_num );
        state[ph_num]=HUNGRY; //given the state hungry because the philosopher said
	test(ph_num);
	sem_wait(&S[ ph_num ]); //take the left chopstick 
	sleep(1);
 
	sem_wait (&S[( ph_num +1)% N ]); //take the right chopstick 
	
	sleep(1); 

} 
void put_chopsticks( int ph_num ) 
{ 
	state[ph_num]=THINK;
	test(ph_num);
	sem_post (&S[ ph_num ]); //put the left chopstick 
	
	test(LEFT);
	sleep(1);
 
	sem_post (&S[( ph_num +1)% N ]); //put the right chopstick 

	test(RIGHT);
	printf( "Philosopher %d putting chopstick %d and %d down\n" ,ph_num + 1, LEFT + 1, ph_num + 1);
        printf( "Philosopher %d is thinking\n" , ph_num ); 
	sleep(1); 
}
void test(int ph_num)
{

    if (state[ph_num] == HUNGRY 
        && state[LEFT] != EAT
        && state[RIGHT] != EAT) { 
        // state that eating 
        state[ph_num] = EAT; 
  
        sleep(2); 
  
        printf("Philosopher %d takes chopstick %d and %d\n", 
                      ph_num + 1, LEFT + 1, ph_num + 1); 
  
        printf("Philosopher %d is Eating\n", ph_num + 1); 
  
        
        sem_post(&S[ph_num]); 
    } 

}
