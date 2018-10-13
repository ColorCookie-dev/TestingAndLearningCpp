// Important note:

/*

This file will not compile normally with gcc
to compile the file command is:
 ' gcc -pthread [file to compile] '
because:
-pthread tells the compiler to link in the pthread library as well as configure the compilation for threads.

Using the -lpthread option only causes the pthread library to be linked - the pre-defined macros don't get defined.

*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// This function will run as a thread
void *anotherfunction(void *arg) {    // those pointers are needed because pthread_create accepts only pointer values
    int t2 = (int)arg;                // in the functionname parameter and the arguments parameter
    printf("Calling from the thread\nNumber is: %d\n", t2);
    return NULL;
}

// main function
int main() {
    // creating a thread id
    pthread_t thread_id;
    int t = 11;
    // creating the thread
    // pthread_create(location-to-store-thread-id,
    //                 attributes: NULL in this case,
    //                   function name to run in thread,
    //                    arguments to the function: NULL in this case )
    pthread_create(&thread_id, NULL, anotherfunction, (void *)t);
    // Joining the thread to the main thread
    pthread_join(thread_id, NULL);
    printf("Thread ended\n");  // printing the status of the thread
    // closing the threads
    pthread_exit(NULL);

    return 0;
}
