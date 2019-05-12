/******************************************************************
 * Header file for the helper functions. This file includes the
 * required header files, as well as the function signatures and
 * the semaphore values (which are to be changed as needed).
 ******************************************************************/


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/time.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include <ctype.h>
# include <iostream>


# define SEM_KEY 0x18 // 0x50 Change this number as needed

struct Shared_data {
  int id;
  int duration;
  
};

struct Producer {
  int prod_id; // keeping track of which producer we are using
  int queue_size; // size of the queue (shared data)
  //size_t items_number; // number of items in the queue
  int number_jobs; // number of jobs per producer
  int* sem_id; // needed to enable use of semaphores
  int* prod_queue_index;
  Shared_data* pointer_queue; // pointer to the shared data

};

struct Consumer {
  int cons_id;
  int queue_size;
  int *sem_id;
  int* cons_queue_index;
  Shared_data* pointer_queue;

};

union semun {
    int val;               /* used for SETVAL only */
    struct semid_ds *buf;  /* used for IPC_STAT and IPC_SET */
    ushort *array;         /* used for GETALL and SETALL */
};

int check_arg (char *);
int sem_create (key_t, int);
int sem_init (int, int, int);
void sem_wait (int, short unsigned int);
void sem_signal (int, short unsigned int);
int sem_close (int);
int sem_timedwait (int id, short unsigned int num);
