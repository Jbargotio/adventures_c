#include "lists.h"
/*
 * check_cycle - checks if linked list has cycle
 * Return : 1-there is a cycle, 0 no cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow,*fast;
	slow = fast = list;/*point slow and fast to beginning of linked list*/
	/*move slow node one node at a time in every iteration
	 * fast node moves two nodes at a time
	 * if slow and fast meet,linked list has a cycle
	 */
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			return 1;
		}
	}
	return 0;
}
