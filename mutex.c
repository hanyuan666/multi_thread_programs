// use mutex to control the order for threads to access a shared variable;

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sharedi = 0; // shared variable
void increase_value(void *pthd_id);

pthread_mutex_t mutex_0 = PTHREAD_MUTEX_INITIALIZER;

int main(){
    int ret_thd1, ret_thd2, ret_thd3;
    char *msg1="thread1";
    char *msg2="thread2";
    char *msg3="thread3";
    pthread_t thd1,thd2,thd3;

    ret_thd1 = pthread_create(&thd1,NULL, (void *)increase_value, (void*) msg1);
    ret_thd2 = pthread_create(&thd2,NULL, (void *)increase_value, (void*) msg2);
    ret_thd3 = pthread_create(&thd3,NULL, (void *)increase_value, (void*) msg3);

    if (ret_thd1 !=0){
        printf("faliure to create thread 1\n" );
    } else {
        printf("success to create thread 1\n");
    }

    if (ret_thd2 !=0){
        printf("faliure to create thread 2\n" );
    } else {
        printf("success to create thread 2\n");
    }

    if (ret_thd3 !=0){
        printf("faliure to create thread 3\n" );
    } else {
        printf("success to create thread 3\n");
    }

   pthread_join(thd1,NULL);
   pthread_join(thd2,NULL);
   pthread_join(thd3,NULL);

   printf("sharedi=%d\n", sharedi);

   return 0;
}


void increase_value(void * pthd_id){
    long i,tmp;
    for(i=0;i<=1000;i++){

       //lock
    	if(pthread_mutex_lock(&mutex_0)!=0){
	    perror("pthread_mutex_lock");
	    exit(EXIT_FAILURE);
	}
       tmp = sharedi;
       tmp=tmp+1;
       sharedi = tmp;
       printf("%s\n",(char *)pthd_id);
       // unlock
       if (pthread_mutex_unlock(&mutex_0)!=0){
           perror("pthread_mutex_unlock");
	   exit(EXIT_FAILURE);

       }
   }
}


      
     
     
     
