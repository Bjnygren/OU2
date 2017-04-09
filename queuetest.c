/*
 * A program for testing the data type queue, as described in the book 
 * "Datatyper och Algoritmer" by Janlert and  Wiberg.
 * Each test builds on the assumption that the previous tests has been 
 * passed, thus there's no need to check, for example, isEmpty in each
 *  function that needs an empty queue.
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* 
 * Purpose: 
 * 				Test axiom 1 of the data type queue. Axiom 1 states that for a 
 * 				correctly implemented queue, a newly created queue is 
 * 				empty.  
 */
void test1(){
    fprintf(stderr,"Test of axiom 1:\n");
	
	// Perform the operations stated in axiom 1: create a new queue and check 
	// if it is empty.
	queue *q = queue_empty();
    queue_setMemHandler(q,free);
	if(!queue_isEmpty(q)){
        fprintf(stderr,"ERROR! Newly created queue is not empty.\n");
        queue_free(q);
        exit(1);
    }
	
	queue_free(q);
    fprintf(stderr,"Ok.\n\n");
}

/* 
 * Purpose: 
 * 				Test axiom 2 of the data type queue. Axiom 2 states that in a 
 * 				correctly implemented queue, a queue with an enqueued element 
 * 				is not empty.  
 */
void test2(){
    fprintf(stderr,"Test of axiom 2:\n");
    queue *q = queue_empty();
    int *val = malloc(5*sizeof(val));
    queue_setMemHandler(q,free);
	
	//Perform operations stated in axiom 2: enqueue an element and check if 
	// the queue is empty.
	queue_enqueue(q,val);
	if(queue_isEmpty(q)){
        fprintf(stderr,"ERROR! Queue is empty even though elements are"
			" enqueued.\n");		
        queue_free(q);
        exit(1);
	}
	
	queue_free(q);
	fprintf(stderr,"Ok.\n\n");
}

/* 
 * Purpose: 
 * 				Test axiom 3 of the data type queue. Axiom 3 states that in a 
 * 				correctly implemented queue, given an empty queue, enqueueing 
 * 				an element and then dequeueing an element yields the original 
 * 				empty queue. 
 */
void test3(){
	fprintf(stderr,"Test of axiom 3:\n");
	int *val = malloc(sizeof(val));
	queue *q=queue_empty();
	queue_setMemHandler(q,free);
	
	// Perform the operations stated in axiom 3: Enqueue an element, then 
	// dequeue an element. 
	queue_enqueue(q,val);
	queue_dequeue(q);
	
	// Checks if queue is empty after the performed operations.
	if(!queue_isEmpty(q)){
		fprintf(stderr,"ERROR! Enqueueing and then dequeuing does not produce"
			"the original queue.\n");
		queue_free(q);
		exit(1);
	}
	
	queue_free(q);
	fprintf(stderr,"Ok\n\n");
}

/* 
 * Purpose: 
 * 				Test axiom 4 of the data type queue. Axiom 4 states that in a 
 * 				correctly implemented queue, given an non-empty queue, 
 * 				enqueueing an element and then dequeueing an element is 
 * 				equal to dequeueing an element and then enqueueing an element.
 */
void test4(){
	fprintf(stderr,"Test of axiom 4:\n");
	queue *q1 = queue_empty();
	queue *q2 = queue_empty();	
	queue_setMemHandler(q1,free);
	queue_setMemHandler(q2,free);

	//Assigns values that will make up the non-empty queue. Memory deallocation
	// is handled by MemHandler.
	for(int i = 0; i < 3; i++){
		int *ini_queue_val = malloc(sizeof ini_queue_val);
		*ini_queue_val = i+1;
		queue_enqueue(q1, ini_queue_val);
		
		ini_queue_val = malloc(sizeof ini_queue_val);
		*ini_queue_val = i+1;
		queue_enqueue(q2, ini_queue_val);
	}

	// Performing the operations stated in axiom 4: dequeue(enqueue(v,q1)) and 
	// enqueue(v,(dequeue(q2)).
	int *val = malloc(sizeof val); 
	queue_enqueue(q1,val);
	queue_dequeue(q1);
	val = malloc(sizeof val); 
	queue_dequeue(q2);
	queue_enqueue(q2,val);
	
	//Checks if the first values of the queues are equal after the 
	// performed operations. 
	if(*(int*)queue_front(q1) != *(int*)queue_front(q2)){
		fprintf(stderr,"ERROR! The values in the first elements of the queues "
			"does not match.\n ");
		queue_free(q1);
		queue_free(q2);
		exit(1);
	}
	
	queue_free(q2);
	queue_free(q1);
	fprintf(stderr,"Ok.\n\n");}

/* 
 * Purpose: 
 * 				Test axiom 5 of the data type queue. Axiom 5 states that in a 
 * 				correctly implemented queue, given an empty queue, enqueueing
 * 				an element and then inspecting the first element of the queue 
 * 				yields the enqueued element.
 */
void test5(){
	fprintf(stderr,"Test of axiom 5: \n");
	queue *q = queue_empty();
	queue_setMemHandler(q,free);
	int *val = malloc(sizeof val);
	
	//Perform the operations specified by axiom 5: enqueue an element 
	// and check if the element in the front of the queue is equal to the 
	// enqueued element.
	queue_enqueue(q,val);
	if(queue_front(q) != val){
		fprintf(stderr, "ERROR! First element in queue does not equal the "
			"enqueued element.\n");
		queue_free(q);
		exit(1);
	}
	
	queue_free(q);
	fprintf(stderr,"Ok.\n\n");
}

/* 
 * Purpose: 
 * 				Test axiom 6 of the data type queue. Axiom 6 states that in a 
 * 				correctly implemented queue, given a non-empty queue, 
 * 				inspecting the first value of the queue yields same value as 
 * 				enqueueing an element and then inspecting the first value of 
 * 				the queue.
 */
void test6(){
	fprintf(stderr,"Test of axiom 6:\n");
	queue *q = queue_empty();
	queue_setMemHandler(q,free);
	int *val = malloc(sizeof val);
	
	// Enqueue elements in the queue to create a non-empty queue and assign 
	// front_q the first element of the queue.
	for(int i = 0; i < 3; i++) {
		int* ini_queue_val = malloc(sizeof ini_queue_val);
		queue_enqueue(q, ini_queue_val);
	}
	int *front_q = queue_front(q);
	
	// Perform the operations specified by axiom 6: enqueue an element and 
	// check if the first element in the queue is same as it was before enqueuing.
	queue_enqueue(q,val);
	if(queue_front(q) !=front_q){
		fprintf(stderr,"ERROR! Enqueuing an element changes value of the first"
			" element in queue.\n");
		queue_free(q);
		exit(1);
	}
	
	queue_free(q);
	fprintf(stderr,"Ok.\n");
} 

int main(){
    test1();
    test2();
	test3();
	test4();
	test5();
	test6();
	return(0);
}

