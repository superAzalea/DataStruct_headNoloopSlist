/* * =====================================================================================
 *
 *       Filename:  slist_adt.h
 *    Description:  
 *        Version:  1.0
 *        Created: 25/06/2016 23:34:18
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Azalea, 
 *   Organization:   =====================================================================================
 */

#pragma once
typedef int elem_t;
#define NAME_SIZE 20
struct node_info {
	char name[NAME_SIZE];
	int age;
	struct node_info *next;
};

/* ADT = Object + Function (对象、方法)*/
struct slist_info {
	struct node_info head;
	void (*add)(struct slist_info *info,struct node_info *pnode);
	void (*add_tail)(struct slist_info *info,struct node_info *pnode);
	void (*for_each)(struct slist_info *info,void (*todo)(struct node_info *pnode));
	void (*del)(struct slist_info *info,struct node_info *pnode);
};

/*构造和析构*/
int slist_init(struct slist_info *info);
int slist_destroy(struct slist_info *info);

