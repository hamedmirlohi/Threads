#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


void* count_numbers(void* args)
{
    
    for (int i = 0; i < *((int*)args); ++i) {
        printf("Thread ID: %d ", (int)pthread_self());
        printf("i: %d\n",i);
    }
    
    return NULL;
}

int main(void)
{
    clock_t start, end;
    
    int temp = 1000;
    int* number = &temp;
    pthread_t thread_id,thread_id2;
    
    start = clock();
    
    pthread_create(&thread_id, NULL, count_numbers, number);
    pthread_create(&thread_id2, NULL, count_numbers, number);
    pthread_join(thread_id, NULL);
    pthread_join(thread_id2, NULL);
    
    end = clock();
    
    printf("performance: %ul\n", (unsigned int)(end - start) / 100);
    
    exit(0);
}
