#include "pch.h"
#include "Hurricane.h"

Hurricane::Hurricane()
{
	setHurricaneName("");
	setLandfallDate("");
	setMaxCategory(0);
}

Hurricane::Hurricane(string hurricaneName, string landfallDate, int maxCategory)
{
	setHurricaneName(hurricaneName);
	setLandfallDate(landfallDate);
	setMaxCategory(maxCategory);
}

string Hurricane::getHurricaneName() const
{
	return hurricaneName;
}

string Hurricane::getLandfallDate() const
{
	return landfallDate;
}

int Hurricane::getMaxCategory() const
{
	return maxCategory;
}

void Hurricane::setHurricaneName(string theHurricaneName)
{
	hurricaneName = theHurricaneName;
}

void Hurricane::setLandfallDate(string theLandfallDate)
{
	landfallDate = theLandfallDate;
}

void Hurricane::setMaxCategory(int theMaxCategory)
{
	if (theMaxCategory < 0)
		maxCategory = 0;
	else
		maxCategory = theMaxCategory;
}

//Utility member functions if needed. 