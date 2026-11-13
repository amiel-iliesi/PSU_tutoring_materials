// PSEUDOCODE APPENDIX FOR THE DIAGRAM

/* There are two patterns for doing this kind of thing in code, just pick the 
 * one that *feels right* for you. */

// pattern 1: base case returns
void CLL::square_all(Node* curr)
{
	// 1. run function behavior
	int x = curr->data;
	curr->data = x * x;

	// 2. determine loop condition
	if (curr == this->rear) {
		return;
	}
	else {
		square_all(curr->next);
	}
}

// pattern 2: loop condition
void CLL::square_all(Node* curr)
{
	// 1. run function behavior
	int x = curr->data;
	curr->data = x * x;

	// 2. determine loop condition
	if (curr != this->rear) {
		square_all(curr->next);
	}
}
