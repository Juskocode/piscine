/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 07:11:33 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:38:05 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap(t_list *list)
{
	void	*data;

	data = list->data;
	list->data = list->next->data;
	list->next->data = data;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*a;
	t_list	*b;

	a = *begin_list;
	while (a != NULL)
	{
		b = *begin_list;
		while (b->next != NULL)
		{
			if ((*cmp)(b->data, b->next->data) > 0)
				ft_list_swap(b);
			b = b->next;
		}
		a = a->next;
	}
}

void	ft_list_merge(t_list **begin_list, t_list *begin_list2)
{
	t_list	*list;

	if (begin_list == 0 || *begin_list == 0)
		*begin_list = begin_list2;
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = begin_list2;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
/*
#include <stdio.h>

int compare_integers(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int nums1[] = {1, 3, 5};
    int nums2[] = {2, 4, 6};

    t_list *list1 = NULL;
    t_list *list2 = NULL;
    for (int i = 0; i < 3; ++i)
    {
        ft_list_push_front(&list1, &nums1[i]);
        ft_list_push_front(&list2, &nums2[i]);
    }

    printf("Original List 1:\n");
    t_list *current1 = list1;
    while (current1)
    {
        printf("%d ", *(int *)(current1->data));
        current1 = current1->next;
    }
    printf("\n");

    printf("Original List 2:\n");
    t_list *current2 = list2;
    while (current2)
    {
        printf("%d ", *(int *)(current2->data));
        current2 = current2->next;
    }
    printf("\n");

    ft_sorted_list_merge(&list1, list2, &compare_integers);

    printf("Merged and Sorted List:\n");
    t_list *current_merged = list1;
    while (current_merged)
    {
        printf("%d ", *(int *)(current_merged->data));
        current_merged = current_merged->next;
    }
    printf("\n");

    while (list1)
    {
        t_list *temp1 = list1;
        list1 = list1->next;
        free(temp1);
    }

    return 0;
}
*/
