/*A program for testing the datatype queue, as described in the book 'Datatyper och Algoritmer' with two additional functions described in queue.h
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



/* Tests axiom 1  */
void test1(){
    fprintf(stderr,"Test of axiom 1: An empty queue is empty. \n");
	queue *q = queue_empty();
    queue_setMemHandler(q,free);
    if(!queue_isEmpty(q)){
        fprintf(stderr,"ERROR! Expected  isEmpty(q) == True, got isEmpty(q) == False.\n");
        queue_free(q);
        exit(1);
    }
    fprintf(stderr,"Ok.\n\n");
    queue_free(q);
}

/*Tests axiom 2*/
void test2(){
    fprintf(stderr,"Test of axiom 2: A queue given a value is not empty.\n");
    /*Create a queue and initialize a pointer with allocated memory. */
    queue *q = queue_empty();
    int *val = malloc(5*sizeof(val));
    /* Set memory handler. Will release memory associated to an element in q when that element is removed*/
    queue_setMemHandler(q,free);
    /* Enqueue an element with value val in q*/
    queue_enqueue(q,val);
    /*Check to see if queue has an element. */
    if(queue_isEmpty(q)){
        fprintf(stderr,"ERROR! Expected isEmpty == False, got isEmpty == True\n");
        /*Free memory assiciated to q*/
        queue_free(q);
        exit(1);
	}
    fprintf(stderr,"Ok.\n\n");
    /*Free memory assiciated to q*/
    queue_free(q);
}

/*Test axiom 3: If queue is empty, adding and removing element results in the empty queue*/
void test3(){
	fprintf(stderr,"Test of axiom 3: Given an empty queue, adding and removing an element returns the empty queue.\n");
	int *val = malloc(sizeof(val));
	queue *q=queue_empty();
	queue_setMemHandler(q,free);
	queue_enqueue(q,val);
	queue_dequeue(q);
	if(!queue_isEmpty(q)){
		fprintf(stderr,"ERROR! Expected isEmpty == True, got isEmpty == False.\n");
		queue_free(q);
		exit(1);
	}
	fprintf(stderr,"Ok\n\n");
	queue_free(q);
}

/*Test axiom 4:  Given a non-empty queue, 
void test4(){
	
}*/


int main(){
    test1();
    test2();
	test3();
    return(0);
}

