#include "pch.h"
#include "HurricaneList.h"

//Constructors
HurricaneList::HurricaneList()
	: head(NULL), tail(NULL) {}

//Destructors
HurricaneList::~HurricaneList()
{
	while (!empty())
	{
		removeFront();
	}
}

bool HurricaneList::empty() const
{
	return (head == NULL);
}

const Hurricane& HurricaneList::front() const
{
	return head->hurricane;
}

const Hurricane& HurricaneList::back() const
{
	return tail->hurricane;
}

void HurricaneList::addFront(const Hurricane& hurricanePtr)
{
	Node* temp = new Node; //New temp node
	temp->hurricane = hurricanePtr;
	temp->next = head;
	temp->prev = tail;
	head = temp;
}

void HurricaneList::addBack(const Hurricane& hurricanePtr)
{
	Node* temp = new Node; //New temp node
	temp->hurricane = hurricanePtr;
	temp->next = NULL;
	if (empty())
	{
		head = temp;
		return;
	}
	else
	{
		Node* tail = head;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = temp;
	}
	temp->prev = tail;
	tail = temp;
}

void HurricaneList::removeFront()
{
	if (!empty())
	{
		Node* temp = head;
		head = temp->next;
		delete temp;
	}
}

void HurricaneList::removeObject(string name)
{
	Node* temp = new Node;
	temp = head;
	bool found = false;

	while ((temp != NULL) & !found) //Search code is reused
	{
		if (temp->hurricane.getHurricaneName() == name)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
	}
	if (found) //True condition is starting point for deleting object
	{
		if (temp == head) //First condition looks for object at head
		{
			head = temp->next;		//Head is moved down one and prev head is deleted
			delete temp;
		}
		else if (temp == tail)		//Looks for object at tail
		{
			tail = NULL;			//Tail is set to null and delete the temp
			delete temp;
		}
		else
		{

			// Initialize first and last pointers to reach middle of linked list
			Node *first_ptr = head;
			Node *last_ptr = head;
			// Find the middle and previous of middle to store previous of slow_ptr
			Node *prev = NULL;
			//Create a while loop while both pointers are not null
			//The pointers will be used to hold the next and prev nodes for when the target node is found
			while (first_ptr != NULL && last_ptr->next != NULL)
			{
				first_ptr = first_ptr->next->next; //Set first node to two nodes down the list
				prev = last_ptr;					//prev node is used to hold current head
				last_ptr = last_ptr->next;			//Set last node to one down the list
			}
			//Delete the middle node
			prev->next = last_ptr->next;
			delete last_ptr;
		}
	}
}

//Displays the list of hurricanes
void HurricaneList::displayList() const
{
	if (!empty())
	{
		cout << "The following Hurricanes are in this list:\n";
		Node* temp = head;
		while (temp)
		{
			cout << "Name: " << temp->hurricane.getHurricaneName() << " Landfall date: " << 
				temp->hurricane.getLandfallDate() << " Max category: " << temp->hurricane.getMaxCategory() << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	else
	{
		cout << "There are no hurricanes in this list.\n";
	}
}

void HurricaneList::searchList(string name)
{
	Node* temp = new Node;
	temp = head;
	bool found = false;

	//Goes through list until temp is null or found is true
	while ((temp != NULL) & !found)
	{
		if (temp->hurricane.getHurricaneName() == name) //Key is name and getter pulls out each hurricane's name
		{
			found = true; //Sets found to true and breaks while loop
		}
		else
		{
			temp = temp->next; //Iterates down the list
		}
	}
	//Displays name and info
	if (found)
	{
		cout << endl << name << " has been found!\n";
		cout << name << " made landfall on " << temp->hurricane.getLandfallDate() << " and had a max category of: " << temp->hurricane.getMaxCategory() << endl;
	}
	else
	{
		cout << endl << name << " was not found.\n";
	}
}

//Uses the search function and then updates the object
void HurricaneList::editList(string name)
{
	Node* temp = new Node;
	temp = head;
	string tempName;
	string tempLandfallDate;
	double tempMaxCategory;
	bool found = false;

	while ((temp != NULL) & !found) //Search code is reused
	{
		if (temp->hurricane.getHurricaneName() == name)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
	}
	if (found) //This time, the true condition is used to update object's info
	{
		//Cout & Cin with setters is used to update info
		cout << "Update the hurricane's name" << endl;
		cin >> tempName;
		temp->hurricane.setHurricaneName(tempName);
		cout << "Update the hurricanes's land fall date" << endl;
		cin >> tempLandfallDate;
		temp->hurricane.setLandfallDate(tempLandfallDate);
		cout << "Update the hurricane's max category" << endl;
		cin >> tempMaxCategory;
		temp->hurricane.setMaxCategory(tempMaxCategory);
	}
	//What happens if we don't find it?
	else
	{
		cout << endl << name << " was not found.\n";
	}
}