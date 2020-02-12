/*
 Name: Isaac Lowry
 Matric number: 170025555
 Module code: AC21008
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int listInit(List **listPtr) {

	if (listPtr == NULL)
	{
		return NULL_PARAM;
	}

	if (*listPtr != NULL)
	{
		return BAD_INIT_PARAM;
	}

	(*listPtr) = (List*)myMalloc(sizeof(List));

	if (*listPtr == NULL)
	{
		return OUT_OF_MEMORY;
	}

	(*listPtr)->head = NULL;
	(*listPtr)->curr = NULL;
	(*listPtr)->tail = NULL;

	return SUCCESS;
}

int insertBeforeCurr(List* listPtr, int data) {

	if (listPtr == NULL)
	{
		return NULL_PARAM;
	}


	if (listPtr->head == NULL && listPtr->curr == NULL && listPtr->tail == NULL)
	{
		ListNode *newNode = (ListNode*)myMalloc(sizeof(ListNode));

		if (newNode == NULL)
		{
			return OUT_OF_MEMORY;
		}

		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		listPtr->head = listPtr->tail = listPtr->curr = newNode;
		
	}


	else if (listPtr->curr == listPtr->head && listPtr->curr->prev == NULL)
	{
	
	
		ListNode *newNode = (ListNode*)myMalloc(sizeof(ListNode));

		if (newNode == NULL)
		{
			return OUT_OF_MEMORY;
		}


		newNode->data = data;


		newNode->next = listPtr->curr;
		listPtr->curr->prev = newNode;
		listPtr->head = newNode;
	
	}


	else if (listPtr->head != listPtr->curr && listPtr->curr->prev != NULL)
	{
		
			ListNode *newNode = (ListNode*)myMalloc(sizeof(ListNode));

			if (newNode == NULL)
			{
				return OUT_OF_MEMORY;
			}			


			newNode->data = data;
			newNode->next = listPtr->curr;
			newNode->prev = listPtr->curr->prev;
			listPtr->curr->prev->next = newNode;
			listPtr->curr->prev = newNode;
			//slide 55

		
	} else {
		return BAD_LIST;
	}


	listPtr->head->prev = NULL;
	listPtr->tail->next = NULL;


	return SUCCESS;
}

int insertAfterCurr(List *listPtr, int data) {
	
	if (listPtr == NULL)
	{
		return NULL_PARAM;
	}

	if (listPtr->curr == listPtr->tail && listPtr->curr->next == NULL)
	{

			ListNode *newNode = (ListNode*)myMalloc(sizeof(ListNode));

			if (newNode == NULL)
			{
				return OUT_OF_MEMORY;
			}			


			newNode->data = data;
			newNode->prev = listPtr->curr;
			listPtr->curr->next = newNode;
			listPtr->tail = newNode;
	}

	else if (listPtr->curr->next != NULL)
	{

		ListNode *newNode = (ListNode*)myMalloc(sizeof(ListNode));

		if (newNode == NULL)
		{
			return OUT_OF_MEMORY;
		}			


		newNode->data = data;
		newNode->prev = listPtr->curr;
		newNode->next = listPtr->curr->next;
		listPtr->curr->next->prev = newNode;
		listPtr->curr->next = newNode;

	} else {
		return BAD_LIST;
	}

	return SUCCESS;
}

int currToPrev(List *listPtr) {
	
	if (listPtr ==  NULL)
	{
		return NULL_PARAM;
	}

	listPtr->curr = listPtr->curr->prev;
	
	if (listPtr->head == NULL && listPtr->curr == NULL && listPtr->tail == NULL)
	{
		return MOVE_IN_EMPTY_LIST;
	}

	else if (listPtr->curr == listPtr->head)
	{
		return MOVE_PREV_AT_HEAD;
	} else {
		return BAD_LIST;
	}

	return SUCCESS;
}

int currToNext(List *listPtr) {

	if (listPtr == NULL)
	{
		return NULL_PARAM;
	}

	listPtr->curr = listPtr->curr->next;

		if (listPtr->head == NULL && listPtr->curr == NULL && listPtr->tail == NULL)
	{
		return MOVE_IN_EMPTY_LIST;
	}

	else if (listPtr->curr == listPtr->tail)
	{
		return MOVE_NEXT_AT_TAIL;
	} else {
		return BAD_LIST;
	}

	return SUCCESS;
}

int getDataAtCurr(List* listPtr, int *data) {

	if (listPtr == NULL)
	{
		return NULL_PARAM;
	}

	if (listPtr->curr == NULL)
	{
		return GET_FROM_EMPTY_LIST;
	}

	if (data == NULL)
	{
		return NULL_PARAM;
	}

	*data = listPtr->curr->data;

	return SUCCESS;
}

int removeAtCurr(List* listPtr, int *data, int moveForward) {

	if (listPtr == NULL)
	{
		return NULL_PARAM;
	}
	
	if (data == NULL)
	{
		return NULL_PARAM;
	}

	if (listPtr->head == NULL && listPtr->curr == NULL && listPtr->tail == NULL)
	{
		return REMOVE_FROM_EMPTY_LIST;
	}

	if (listPtr->curr == listPtr->head && listPtr->curr == listPtr->tail)
	{
		ListNode *nodeToRemove = listPtr->curr;
		listPtr->head = NULL;
		listPtr->tail = NULL;
		listPtr->curr = NULL;
		free(nodeToRemove);
	}

	else if (listPtr->curr == listPtr->head)
	{
		ListNode *nodeToRemove = listPtr->curr;
		listPtr->head = nodeToRemove->next;
		listPtr->head->prev = NULL;
		listPtr->curr = listPtr->head;
		free(nodeToRemove);
	}

	else if (listPtr->curr == listPtr->tail)
	{
		ListNode *nodeToRemove = listPtr->curr;
		listPtr->tail = nodeToRemove->prev;
		listPtr->tail->next = NULL;
		listPtr->curr = listPtr->tail;
		free(nodeToRemove);
	}

	else if (listPtr->curr != listPtr->head && listPtr->curr != listPtr->tail)
	{
		ListNode *nodeToRemove = listPtr->curr;
		nodeToRemove->prev->next = nodeToRemove->next;
		nodeToRemove->next->prev = nodeToRemove->prev;
		listPtr->curr = nodeToRemove->next;
		free(nodeToRemove);

	} else{
		return BAD_LIST;
	}

	return SUCCESS;

}

int listFree(List* listPtr) {

	if (listPtr == NULL)
	{
		return NULL_PARAM;
	}

	 	while (listPtr->head != NULL)
 	{
 		ListNode *currentHead = listPtr->head;
 		listPtr->head = listPtr->head->next;
 		free(currentHead);
 	}

 	free(listPtr);

 	return SUCCESS;
}