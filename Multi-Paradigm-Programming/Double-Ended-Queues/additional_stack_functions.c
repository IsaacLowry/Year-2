
// a function to display the contents of a stack
int displayStack(Stack *pStack)
{
	// if there is no stack to traverse
	if (pStack == NULL)
		return NULL_PARAM;

	// if the stack is empty
	if (pStack->top == NULL)
		return SUITABLE_ERROR_CODE;

	// traverse the entire Stack, from top to bottom
	Node *nextNodeToDisplay = pStack->top;
	while (nextNodeToDisplay != NULL)
	{
		// display node
		printf("Next node on Stack: %lf\n", nextNodeToDisplay->score);

		// move to next node down the stack
		nextNodeToDisplay = nextNodeToDisplay->next;
	}

	// done
	return SUCCESS;
}

// a function to remove the node at the tail of the Stack
int removeAtTail(Stack *pStack, double *data)
{
	// if there is no stack
	if (pStack == NULL)
		return NULL_PARAM;

	// if the data pointer isn't valid
	if (data == NULL)
		return NULL_PARAM;

	// if the stack is empty
	if (pStack->top == NULL)
		return SUITABLE_ERROR_CODE;

	// if there is only 1 item in the Stack
	if (pStack->top->next == NULL)
	{
		// get data in top node
		*data = pStack->top->score;

		// remove the top of the stack
		Node *nodeToRemove = pStack->top;
		pStack->top = NULL;
		free(nodeToRemove);
		return SUCCESS;
	}
	else
	{
		// we need to traverse the stack until we find 
		// the node at the end of it
		// we know there is at least one node after
		// the top of the stack so we start there but also
		// retaining a pointer to the node that is 
		// immediately previous to the node we
		// want to remove too
		Node *endNode = pStack->top->next;
		Node *prevNode = pStack->top;

		// while there is still another node to move to
		// at the end of the stack
		while (endNode->next != NULL)
		{
			// store current position (node prior
			// to that which may be at the end)
			prevNode = endNode;

			// shift the end node down
			endNode = endNode->next;	
		}

		// detach the end node from the stack (by detaching
		// it from the node above it)
		prevNode->next = NULL;

		// get data in end node
		*data = endNode->score;

		// free the end node
		free(endNode);		
	}

}


