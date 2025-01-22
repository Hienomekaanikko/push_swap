#include "push_swap.h"

static void add_target_mode_0(t_list *curr_to, t_list *from)
{
	t_list		*curr_from;
	long long		closest;
	long long		found;
	long long		value_to;
	long long		value_from;
	long long		num;

	value_to = *(long long*)curr_to->content;
	found = 0;
	closest = INT_MAX;
	curr_from = from;
	while (curr_from)
	{
		value_from = *(long long*)curr_from->content;
		if (value_from < value_to)
		{
			num = value_to - value_from;
			if (num > 0 && num < closest)
			{
				closest = num;
				curr_to->target = value_from;
				found = 1;
			}
		}
		curr_from = curr_from->next;
	}
	if (!found)
		curr_to->target = highest(&from);
}

static void add_target_mode_1(t_list *curr_to, t_list *from)
{
	t_list		*curr_from;
	long long		closest;
	long long		found;
	long long		value_to;
	long long		value_from;
	long long		num;

	curr_from = from;
	closest = INT_MAX;
	found = 0;
	value_to = *(long long*)curr_to->content;
	while (curr_from)
	{
		value_from = *(long long*)curr_from->content;
		if (value_from > value_to)
		{
			num = value_from - value_to;
			if (num < closest)
			{
				closest = num;
				curr_to->target = value_from;
				found = 1;
			}
		}
		curr_from = curr_from->next;
	}
	if (!found)
		curr_to->target = lowest(&from);
}


void add_targets(t_list **to, t_list **from, int mode)
{
	t_list	*curr_to;

	curr_to = *to;
	while (curr_to)
	{
		if (mode == 0)
			add_target_mode_0(curr_to, *from);
		else if (mode == 1)
			add_target_mode_1(curr_to, *from);
		curr_to = curr_to->next;
	}
}
