#pragma once
#include "HurricaneNode.h"

class HurricaneList
{
public:
	HurricaneList();
	~HurricaneList();
	bool empty() const;
	const Hurricane& front() const;
	const Hurricane& back() const;
	void addFront(const Hurricane& first);
	void addBack(const Hurricane& back);
	void removeFront();
	void removeObject(string hurricaneName);
	void editList(string hurricaneName);
	void displayList() const;
	void searchList(string hurricaneName);

private:
	Node* head;
	Node* tail;
};