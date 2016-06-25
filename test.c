/*
 * =====================================================================================
 *
 *       Filename:  02test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/26/2016 00:07:46
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Azalea, 
 *   Organization:  
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "slist_adt.h"
#include <assert.h>

void print_node (struct node_info *pnode)
{
	printf("%s:%d\n",pnode->name,pnode->age);
}

int main()
{
	struct node_info s[] = {
		{"小明",8},
		{"小花",4},
		{"小强",18},
		{"小敏",19},
	};
	struct slist_info *slist = (struct slist_info *)malloc(sizeof(*slist));
	assert(slist != NULL);
	slist_init(slist);
	int i;
	for (i = 0; i <sizeof s /sizeof s[0]; ++i) {
		slist->add_tail(slist,s+i);
	}
	slist->for_each(slist,print_node);
	slist_destroy(slist);
	free(slist);
	return 0;
}
