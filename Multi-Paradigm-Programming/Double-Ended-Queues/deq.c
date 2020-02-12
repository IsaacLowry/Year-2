/*
Name: Isaac Lowry
Matric number: 170025555
Module code: AC21008
*/

#include <stdio.h>
#include <stdlib.h>
#include "deq.h"

 int initDEQueue(DEQueue **qPtr) {

 	if (qPtr == NULL)
 	{
 		return NULL_PARAM;
 	}

 	if (*qPtr != NULL)
 	{
 		return BAD_INIT_PARAM;
 	}

 	(*qPtr) = (DEQueue*)myMalloc(sizeof(DEQueue));

 	if (*qPtr == NULL)
 	{
 		return OUT_OF_MEMORY;
 	}

 	(*qPtr)->head = NULL;
 	(*qPtr)->tail = NULL;

 	return SUCCESS;
 }

 int pushHead(DEQueue *qPtr, int data) {
 	
 	if (qPtr == NULL)
 	{
 		return NULL_PARAM;
 	}


 	if (qPtr->head == NULL && qPtr->tail == NULL)
 	{
 		Node *newNode = (Node*)myMalloc(sizeof(Node));

	 	if (newNode == NULL)
	 	{
	 		return OUT_OF_MEMORY;
	 	}

		newNode->data = data;
		qPtr->head = newNode;
		qPtr->tail = newNode;
		qPtr->head->next = NULL;
	}
 	
 	else if (qPtr->head != NULL && qPtr->tail != NULL)
 	{
 		Node *newNode = (Node*)myMalloc(sizeof(Node));

	 	if (newNode == NULL)
	 	{
	 		return OUT_OF_MEMORY;
	 	}


 		newNode->data = data;
 		Node *nodeToAdd = qPtr->head;
		newNode->next = nodeToAdd;
		qPtr->head = newNode;

 	} else{
		return BAD_DEQ;
	}
 	
 	return SUCCESS;


 }

int pushTail(DEQueue *qPtr, int data) {
 	
 	if (qPtr == NULL)
 	{
 		return NULL_PARAM;
 	}

 	Node *newNode = (Node*)myMalloc(sizeof(Node));

 	if (newNode == NULL)
 	{
 		return OUT_OF_MEMORY;
 	}

 	if (qPtr->tail == NULL)
 	{
 		newNode->data = data;

 		qPtr->tail = newNode;
 		qPtr->head = newNode;
 		
 	 	//add another node to tail of queue
 	} else {
	 	newNode->data = data;

	 	qPtr->tail->next = newNode;
	 	qPtr->tail = newNode;
	 
 	}


 	return SUCCESS;
 }

 int popHead(DEQueue *qPtr, int *dataPtr) {

	if (qPtr == NULL)
	{
		return NULL_PARAM;
	}

 	if (qPtr->head == NULL)
 	{
 		return POP_EMPTY_DEQ;
 	}

 	if (dataPtr == NULL)
 	{
 		return NULL_PARAM;
 	}

 	if (qPtr->head != NULL)
 	{
 		Node *nodeToRemove = qPtr->head;

	 	*dataPtr = nodeToRemove->data;

	 	qPtr->head = qPtr->head->next;

	 	nodeToRemove->next = NULL;
	 	nodeToRemove->data = 0;
	 	free(nodeToRemove);
 	}

 	return SUCCESS;
 }

 int peekHead(DEQueue *qPtr, int *dataPtr) {

 	if (qPtr == NULL)
 	{
 		return NULL_PARAM;
 	}

 	if (qPtr->head == NULL)
 	{
 		return PEEK_EMPTY_DEQ;
 	}

 	if (dataPtr == NULL)
 	{
 		return NULL_PARAM;
 	}

	*dataPtr = qPtr->head->data;

 	return SUCCESS;
 }

 int peekTail(DEQueue* qPtr, int *dataPtr) {

 	if (qPtr == NULL)
 	{
 		return NULL_PARAM;
 	}

 	if (qPtr->tail == NULL)
 	{
 		return PEEK_EMPTY_DEQ;
 	}

 	if (dataPtr == NULL)
 	{
 		return NULL_PARAM;
 	}

 	*dataPtr = qPtr->tail->data;

 	return SUCCESS;
 }

 int freeDEQueue(DEQueue* qPtr) {

 	if (qPtr == NULL)
 	{
 		return NULL_PARAM;
 	}

 	while (qPtr->head != NULL)
 	{
 		Node *currentHead = qPtr->head;
 		qPtr->head = qPtr->head->next;
 		free(currentHead);
 	} 

 	free(qPtr);

 	return SUCCESS;
 }

