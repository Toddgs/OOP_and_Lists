#pragma once
#include "Hurricane.h"

class Node //Node for hurricane class
{
public:
	Hurricane hurricane; //The hurricane element in this node
	Node* next; //The node pointer to the next item in the list
	Node* prev; //The node pointer to the previous item in the list.

	//friend class HurricaneList;
};