struct prime_number_node
{
	int prime_number;
	prime_number_node *next;
};
int calc_prime_number()
{
	prime_number_node *list_head = new prime_number_node();
	list_head->next = NULL;
	list_head->prime_number = 2;
	prime_number_node *list_tail = list_head;
	for (int number = 3; number < 100; number++)
	{
		int remainder;
		prime_number_node *cur_node_ptr = list_head;
		while (cur_node_ptr != NULL)
		{
			remainder = number % cur_node_ptr->prime_number;
			if (remainder == 0)
			{
				break;
			}
			else
			{
				cur_node_ptr = cur_node_ptr->next;
			}
		}
		if (remainder != 0)
		{
			prime_number_node *new_node_ptr = new prime_number_node();
			new_node_ptr->prime_number = number;
			new_node_ptr->next = NULL;
			list_tail->next = new_node_ptr;
			list_tail = new_node_ptr;
		}
	}

	int result = 0;
	while (list_head != NULL)
	{
		result++;
		prime_number_node *temp_ptr = list_head;
		list_head = list_head->next;
		delete temp_ptr;
	}
	return result;
}