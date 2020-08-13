#include <stdio.h> 
#include <semaphore.h> 
#include <pthread.h> 

#define N 5 //the number of philosophers 
sem_t S[N]; //semaphores for chopsticks 
void * philospher( void * num ); 
void take_chopsticks(int); 
void put_chopsticks(int); 
int phil_num[ N ]={0,1,2,3,4}; //philosopher ID 

int counter=0; //counter variable to see the number of philosophers
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

	if(counter <4){ //want to maker sure that there is only 4 philosophers eating
 	counter+=1; //there is a philsopher at the table
	sem_wait(&S[ ph_num ]); //take the left chopstick 
	printf( "Philosopher %d takes chopstick %d \n" , ph_num , ph_num ); 

	sleep(1);
 
	sem_wait (&S[( ph_num +1)% N ]); //take the right chopstick 
	printf( "Philosopher %d takes chopstick %d \n" , ph_num ,( ph_num +1)% N );
 
	printf( "Philosopher %d is eating\n" , ph_num ); 
	sleep(1); 
	}
} 
void put_chopsticks( int ph_num ) 
{ 
	sem_post (&S[ ph_num ]); //put the left chopstick 
	printf( "Philosopher %d putting chopstick %d \n" , ph_num , ph_num ); 
	sleep(1);
 
	sem_post (&S[( ph_num +1)% N ]); //put the right chopstick 
	printf( "Philosopher %d putting chopstick %d \n" , ph_num ,( ph_num +1)% N );
	counter-=1; //if done eating the philosopher count global varaible decrements

        printf( "Philosopher %d is thinking\n" , ph_num ); 
	sleep(1); 
}
