#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef Hurricane_H
#define Hurricane_H

class Hurricane
{
	//Class and friend declarations as needed

public:
	Hurricane();
	Hurricane(string hurricaneName, string landfallDate, int maxCategory);

	//Get and set methods and member functions
	string getHurricaneName() const;
	string getLandfallDate() const;
	int getMaxCategory() const;
	void setHurricaneName(string hurricaneName);
	void setLandfallDate(string landfallDate);
	void setMaxCategory(int maxCategory);

	//Utility functions if needed

	//Member Attributes
private:
	string hurricaneName;
	string landfallDate;
	int maxCategory;


};

#endif