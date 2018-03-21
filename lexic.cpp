#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <deque>

#include "lexic.h"

using namespace std;

std::string getTripleProp(int value, int genderID, int caseID)
{
	string result;	
	if (value == 0)
		return result;

	int hungred = value / 100;
	if (hungred == 1)
	{
		const string oneHungredCases[2] = { "���", "���" };
		if (caseID == 0 || caseID == 3)
			result += oneHungredCases[0];
		else
			result += oneHungredCases[1];
	}
	else if (hungred > 1 && hungred < 5)
	{
		const string end[6] = { "���", "���", "�����", "���", "�������", "�����" };
		if (hungred == 2)
		{
			const string two[6] = { "���", "����", "����", "���", "�����", "����" };
			result += two[caseID];
			if (caseID == 3)
				result += end[0];
			else
				result += end[caseID];
		}
		else if (hungred == 3)
		{
			const string three[2] = { "���", "���" };
			if (caseID == 0 || caseID == 3)
				result += three[0];
			else
				result += three[1];
			result += end[caseID];
		}
		else if (hungred == 4)
		{
			const string four[2] = { "������", "��������" };
			if (caseID == 4)
				result += four[1];
			else
				result += four[0];
			result += end[caseID];
		}		
	}
	else if (hungred > 4)
	{
		const string fiveToNineBegin[5] = { "���", "����", "���", "�����", "�����" };
		const string fiveToNineEnd[6] = { "�", "�", "�", "�", "��", "�" };
		const string hungredEnd[6] = { "���", "���", "����", "���", "�����", "����" };
		result += fiveToNineBegin[hungred - 5] + fiveToNineEnd[caseID] + hungredEnd[caseID];
	}
	if (hungred > 0)
		result += " ";

	value %= 100;

	int dec = value / 10;
	if (dec == 1)
	{
		const string oneToNineBegin[9] = { "����", "���", "���", "�����", "���", "����", "���", "�����", "�����" };
		const string end = "������";
		const string ten = "�����";
		const string endCases[6] = { "�", "�", "�", "�", "��", "�" };
		if (value == 10)
			result += ten + endCases[caseID];
		else
		result += oneToNineBegin[value - 11] + end + endCases[caseID];
	}
	else
	{
		if (dec == 2 || dec == 3)
		{
			const string beg[2] = { "���", "���" };
			const string end = "����";
			const string endCases[6] = { "�", "�", "�", "�", "��", "�" };
			result += beg[dec - 2] + end + endCases[caseID];
		}
		else if (dec == 4)
		{
			const string fortyCases[2] = { "�����", "������" };
			if (caseID == 0 || caseID == 3)
				result += fortyCases[0];
			else
				result += fortyCases[1];

		}
		else if (dec == 9)
		{
			const string ninetyCases[2] = { "���������", "���������" };
			if (caseID == 0 || caseID == 3)
				result += ninetyCases[0];
			else
				result += ninetyCases[1];
		}
		else if (dec > 4 && dec < 9)
		{
			const string fiveToEightBegin[4] = { "���", "����", "���", "�����"};
			const string end = "�����";
			const string fiveToEightEnd[6] = { "�", "�", "�", "�", "��", "�" };
			const string fiveToEightEnd2[6] = { "", "�", "�", "", "��", "�" };
			result += fiveToEightBegin[dec - 5] + fiveToEightEnd[caseID] + end + fiveToEightEnd2[caseID];
		}		
	}
	if (dec > 0)
		result += " ";
	if (dec != 1)
		value %= 10;
	else
		return result;

	if (value == 1)
	{
		if (genderID == 1)
		{
			const string oneCases[6] = { "����", "�����", "�����", "����", "�����", "�����" };
			result += oneCases[caseID];
		}
		else
		{
			const string oneCases[6] = { "����", "������", "������", "����", "�����", "�����" };
			if (genderID == 2 && (caseID == 0 || caseID == 3))
				result += "����";
			else
				result += oneCases[caseID];
		}
	}
	else if (value == 2)
	{
		const string twoCases[6] = { "���", "����", "����", "���", "�����", "����" };
		if (genderID == 1 && caseID == 0)
			result += "���";
		else
			result += twoCases[caseID];
	}
	else if (value == 3)
	{
		const string threeCases[6] = { "���", "����", "����", "���", "�����", "����" };
		result += threeCases[caseID];
	}
	else if (value == 3)
	{
		const string fourCases[6] = { "������", "�������", "�������", "������", "��������", "�������" };
		result += fourCases[caseID];
	}
	else if (value > 4)
	{
		const string fiveToNineBegin[5] = { "���", "����", "���", "�����", "�����" };
		const string fiveToNineEnd[6] = { "�", "�", "�", "�", "��", "�" };
		result += fiveToNineBegin[value - 5] + fiveToNineEnd[caseID];
	}
	return result;
}

std::string sumProp(long long nSum, std::string sGender, std::string sCase)
{
	vector <string> cases{ "�", "�", "�", "�", "�", "�" };
	int caseID = -1;
	for (int i = 0, end = cases.size(); i < end; i++)
	{
		if (cases[i] == sCase)
		{
			caseID = i;
			break;
		}
	}
	assert(caseID > -1);

	vector <string> genders{ "�", "�", "�" };
	int genderID = -1;
	for (int i = 0, end = genders.size(); i < end; i++)
	{
		if (genders[i] == sGender)
		{
			genderID = i;
			break;
		}
	}
	assert(genderID > -1);	
	
	string result;	
	if (caseID == 5)
		result += "� ";	
	if (nSum < 0)
	{
		result += "����� ";
		nSum *= -1;
	}
	else if (nSum == 0)
	{
		vector <string> zeroCases{ "����", "����", "����", "����", "�����", "����" };
		return result + zeroCases[caseID];
	}

	deque <string> tripleProp;
	while (nSum > 0)
	{
		int tempGenderID = genderID;
		if (tripleProp.size() == 1)
			tempGenderID = 1;
		else if (tripleProp.size() > 1)
			tempGenderID = 0;
		string tripleResult = getTripleProp(nSum % 1000, tempGenderID, caseID);
		if (tripleProp.size() == 1)
		{
			int thousands = nSum % 1000;
			vector <string> thousandCases{ "�����", "�����", "�������", "�����", "��������", "�������" };
			if (thousands % 10 > 0 && thousands % 10 < 5)
			{
				if (thousands % 10 == 1)
					thousandCases = { "������", "������", "������", "������", "�������", "������" };
				else
					thousandCases[0] = thousandCases[3] = "������";
			}				
			tripleResult += thousandCases[caseID];
		}
		else if (tripleProp.size() == 2)
		{
			vector <string> millionCases{ "���������", "���������", "���������", "���������", "��������", "���������" };
			int millions = nSum % 1000;			
			if (millions % 10 > 1 && millions % 10 < 5)
			{
				if (millions % 10 == 1)
					millionCases[0] = millionCases[3] = "�������";
				else
					millionCases[0] = millionCases[3] = "��������";
			}
			tripleResult += millionCases[caseID];
		}
		else if (tripleProp.size() == 3)
		{
			vector <string> billionCases{ "����������", "����������", "����������", "����������", "�����������", "����������" };
			int decBillions = (nSum % 1000) % 10;
			if (decBillions > 1 && decBillions < 5)
				billionCases[0] = billionCases[3] = "��������";
			else if (decBillions == 1)
				billionCases[0] = billionCases[3] = "��������";
				

			
			tripleResult += billionCases[caseID];		
		}		
		tripleProp.push_front(tripleResult + " ");
		nSum /= 1000;
	}
	while (tripleProp.size())
	{
		result += tripleProp.front();
		tripleProp.pop_front();
	}
	return result;
}