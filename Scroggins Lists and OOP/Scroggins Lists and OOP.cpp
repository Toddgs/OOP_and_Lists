//Todd Scroggins, Visual Studio 2017
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include "HurricaneList.h"
#include "Hurricane.h"
#include "HurricaneNode.h"

using namespace std;


// Press any key to continue.
void pressAnyKey()
{
	cout << "\nPress any key to continue" << endl << endl;
	_getch(); // Waits and gets next character entered.		
}

int main()
{
	int choice; //Used to store the choice the user makes in the menu.
	bool theMeaningOfLife = true; //Variable to keep program alive, while true it continues to run.
	HurricaneList hurricaneList; //The list of hurricanes.

	//Menu for selections.
    cout << "Hello World! SELECT OPTION OR FACE IMMINENT DOOM\n";
	cout << "Please make a selection:\n";
	cout << "1: Add an item to the front of the list.\n";
	cout << "2: Add an item to the back of the list.\n";
	cout << "3: Search for an item in the list.\n";
	cout << "4: Edit a specific item from the list.\n";
	cout << "5: Delete an item from the list.\n";
	cout << "6: Display the list.\n";
	cout << "7: Exit the program.\n";
	

	while(theMeaningOfLife)
	{
		cout << "Please enter a selection: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1: //Adding to the front of the list.
		{
			//Variables declared
			string hurricaneName = "", landFallDate = ""; //Strings for data for the hurricanes
			int maxCategory = 0; //Int for storing the max category of the hurricane.

			//Get the information to create a new hurricane.
			cout << "Hurricanes need a name! What is it?\n";
			cin >> hurricaneName;
			cout << "What was it's landfall date?\n";
			cin >> landFallDate;
			cout << "And last, what was it's highest category?\n";
			cin >> maxCategory;

			Hurricane temp(hurricaneName, landFallDate, maxCategory); //Creates the new hurricane.
			Hurricane *newHurricane = &temp; //Getting a pointer to the new hurricane.
			hurricaneList.addFront(temp); //Adding the new hurricane to the front of the list.
			cout << "Adding to the front of the list.";
			
			pressAnyKey();
			break;
		}
		case 2: //Adding to the back of the list.
		{	
			string hurricaneName = "", landFallDate = ""; //Strings for data for the hurricanes
			int maxCategory = 0; //Int for storing the max category of the hurricane.

			//Taking in needed information to add a hurricane to the list.
			cout << "Hurricanes need a name! What is it?\n";
			cin >> hurricaneName;
			cout << "What was it's landfall date?\n";
			cin >> landFallDate;
			cout << "And last, what was it's highest category?\n";
			cin >> maxCategory;

			Hurricane temp(hurricaneName, landFallDate, maxCategory);
			Hurricane *newHurricane = &temp;
			hurricaneList.addBack(temp);
			cout << "Adding to the back of the list.";
			
			pressAnyKey();
			break;
		}
		case 3: //Searching for an item in the list.
		{	
			//Variable Declariations
			string tempName = "";

			//Get needed data
			cout << "What is the name of the hurricane you're searching for?\n";
			cin >> tempName;

			//Call Search function
			hurricaneList.searchList(tempName);
			pressAnyKey();
			break;
		}
		case 4: //Editing specific selected item from the list.
		{	
			//Initialize variables
			string tempName = "";
			
			//Get needed data
			cout << "Which Hurricane would you like to edit?";
			cin >> tempName;
			
			//Call edit function
			hurricaneList.editList(tempName);
			
			pressAnyKey();
			break;
		}
		case 5: //Removing a specific item from the list
		{	
			//Initialize variables
			string tempName = "";

			//Get needed data
			cout << "Which Hurricane do you want to remove?";
			cin >> tempName;

			//Call removeObject function
			hurricaneList.removeObject(tempName);
			
			pressAnyKey();
			break;
		}
		case 6: //Display entire list
		{	
			cout << "Displaying...";
			hurricaneList.displayList();
			
			pressAnyKey();
			break;
		}
		case 7: //Exit Program
		{	
			theMeaningOfLife = false;
			cout << "Exiting";
			
			pressAnyKey();
			break;
		}
		default: //Error message
		{	
			cout << "I'm sorry, that isn't a valid selection!";
			
			pressAnyKey();
			break;
		}
		}
	}
}

