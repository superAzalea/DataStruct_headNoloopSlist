/*
 * =====================================================================================
 *
 *       Filename:  02head_noloop_slist_adt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/25/2016 23:47:48
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Azalea, 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "slist_adt.h"
static void slist_add(struct slist_info *pslist,struct node_info *pnode)
{
	pnode->next = pslist->head.next;
	pslist->head.next = pnode;
}

static void slist_add_tail(struct slist_info 
	*pslist, struct node_info *pnode)
{
	struct node_info *cur ;
	//空链表
	//if(pslist->head.next == NULL) {
	if (pslist->head.next == NULL)  {
		cur = &pslist->head;
	} else {
	//非空链表
		for (cur = pslist->head.next; 
			cur != NULL && cur->next != NULL; cur = cur->next){;}
	}
	pnode->next = NULL;
	cur->next = pnode;
}

static void slist_for_each( struct slist_info *pslist,void (*todo)(struct node_info *pnode))
{
	struct node_info *cur;
	for( cur = pslist->head.next; cur != NULL ;cur = cur->next){
		todo(cur);
	}
}



int slist_init(struct slist_info *info)
{
	assert(info != NULL);
	info->head.next = NULL;
	info->add = slist_add;
	info->add_tail = slist_add_tail;
	info->for_each = slist_for_each;
	return 0;
}



int slist_destroy(struct slist_info *info)
{
	return 0;
}
