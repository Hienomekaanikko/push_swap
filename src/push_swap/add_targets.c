#include "push_swap.h"

static void add_target_mode_0(t_list *curr_to, t_list *from)
{
	t_list *curr_from = from;
	int closest = INT_MAX;
	int found = 0;
	int value_to = *(int*)curr_to->content;
	int value_from;

	while (curr_from)
	{
		value_from = *(int*)curr_from->content;
		if (value_from < value_to)
		{
			int num = value_to - value_from;
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
	t_list *curr_from = from;
	int closest = INT_MIN;
	int found = 0;
	int value_to = *(int*)curr_to->content;
	int value_from;

	while (curr_from)
	{
		value_from = *(int*)curr_from->content;
		if (value_from > value_to)
		{
			int num = value_from - value_to;
			if (num < 0 && -num < closest)
			{
				closest = -num;
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
	t_list *curr_to;
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
