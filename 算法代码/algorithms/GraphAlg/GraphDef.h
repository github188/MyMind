#ifndef GRAPH_DEF_H
#define GRAPH_DEF_H

#include <stdio.h>

enum Status
{
	S_NIL = 0,
	S_WHITE = 1,
	S_GRAY = 2,
	S_BLACK =3,
};

struct Vetex
{
	int id;
	Status s;
};

struct Edge
{
	void* head;
	void* end;
};

//�����ʾ
struct GraphInMatrix
{
	int edgeAmn;
	Edge *edgeArr;
};

struct ListNode;
struct VetexWithList
{
	void* vetex;
	ListNode* adjNxt;
	VetexWithList* parent;
};

struct ListNode
{
	VetexWithList* node;
	ListNode* nxt;
};

//�����ʾ
struct GraphInList
{
	int listAmn;
	ListNode *listArr;
};


#endif