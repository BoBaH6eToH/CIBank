#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <deque>

#include "lexic.h"

using namespace std;

#define CASE_SIZE 6

std::string getTripleProp(int value, int genderID, int caseID)
{
	string result;	
	if (value == 0)
		return result;

	/* обработка количества сотен */
	int hungred = value / 100;	
	if (hungred == 1)
	{
		const string oneHungredCases[2] = { "сто", "ста" };
		if (caseID == 0 || caseID == 3)
			result += oneHungredCases[0];
		else
			result += oneHungredCases[1];
	}
	else if (hungred > 1 && hungred < 5)
	{
		const string end[CASE_SIZE] = { "сти", "сот", "мстам", "ста", "мястами", "хстах" };
		if (hungred == 2)
		{
			const string two[CASE_SIZE] = { "две", "двух", "двум", "две", "двумя", "двух" };
			result += two[caseID];
			if (caseID == 3)
				result += end[0];
			else
				result += end[caseID];
		}
		else if (hungred == 3)
		{
			const string three[2] = { "три", "тре" };
			if (caseID == 0 || caseID == 3)
				result += three[0];
			else
				result += three[1];
			result += end[caseID];
		}
		else if (hungred == 4)
		{
			const string four[2] = { "четыре", "четырьмя" };
			if (caseID == 4)
				result += four[1];
			else
				result += four[0];
			result += end[caseID];
		}		
	}
	else if (hungred > 4)
	{
		const string fiveToNineBegin[5] = { "пят", "шест", "сем", "восем", "девят" };
		const string fiveToNineEnd[CASE_SIZE] = { "ь", "и", "и", "ь", "ью", "и" };
		const string hungredEnd[CASE_SIZE] = { "сот", "сот", "стам", "сот", "стами", "стах" };
		result += fiveToNineBegin[hungred - 5] + fiveToNineEnd[caseID] + hungredEnd[caseID];
	}
	if (hungred > 0)
		result += " ";

	value %= 100;

	/* обработка количества десятков */
	int dec = value / 10;	
	if (dec == 1)
	{
		const string oneToNineBegin[9] = { "один", "две", "три", "четыр", "пят", "шест", "сем", "восем", "девят" };
		const string end = "надцат";
		const string ten = "десят";
		const string endCases[CASE_SIZE] = { "ь", "и", "и", "ь", "ью", "и" };
		if (value == 10)
			result += ten + endCases[caseID];
		else
		result += oneToNineBegin[value - 11] + end + endCases[caseID];
	}
	else
	{
		if (dec == 2 || dec == 3)
		{
			const string beg[2] = { "два", "три" };
			const string end = "дцат";
			const string endCases[CASE_SIZE] = { "ь", "и", "и", "ь", "ью", "и" };
			result += beg[dec - 2] + end + endCases[caseID];
		}
		else if (dec == 4)
		{
			const string fortyCases[2] = { "сорок", "сорока" };
			if (caseID == 0 || caseID == 3)
				result += fortyCases[0];
			else
				result += fortyCases[1];

		}
		else if (dec == 9)
		{
			const string ninetyCases[2] = { "девяносто", "девяноста" };
			if (caseID == 0 || caseID == 3)
				result += ninetyCases[0];
			else
				result += ninetyCases[1];
		}
		else if (dec > 4 && dec < 9)
		{
			const string fiveToEightBegin[4] = { "пят", "шест", "сем", "восем"};
			const string end = "десят";
			const string fiveToEightEnd[CASE_SIZE] = { "ь", "и", "и", "ь", "ью", "и" };
			const string fiveToEightEnd2[CASE_SIZE] = { "", "и", "и", "", "ью", "и" };
			result += fiveToEightBegin[dec - 5] + fiveToEightEnd[caseID] + end + fiveToEightEnd2[caseID];
		}		
	}
	if (dec > 0)
		result += " ";
	if (dec != 1)
		value %= 10;
	else
		return result;

	/* обработка количества единиц */
	if (value == 1)
	{
		if (genderID == 1)
		{
			const string oneCases[CASE_SIZE] = { "одна", "одной", "одной", "одну", "одной", "одной" };
			result += oneCases[caseID];
		}
		else
		{
			const string oneCases[CASE_SIZE] = { "один", "одного", "одному", "один", "одним", "одном" };
			if (genderID == 2 && (caseID == 0 || caseID == 3))
				result += "одно";
			else
				result += oneCases[caseID];
		}
	}
	else if (value == 2)
	{
		const string twoCases[CASE_SIZE] = { "два", "двух", "двум", "два", "двумя", "двух" };
		if (genderID == 1 && caseID == 0)
			result += "две";
		else
			result += twoCases[caseID];
	}
	else if (value == 3)
	{
		const string threeCases[CASE_SIZE] = { "три", "трех", "трем", "три", "тремя", "трех" };
		result += threeCases[caseID];
	}
	else if (value == 3)
	{
		const string fourCases[CASE_SIZE] = { "четыре", "четырех", "четырем", "четыре", "четырьмя", "четырех" };
		result += fourCases[caseID];
	}
	else if (value > 4)
	{
		string fiveToNineBegin[5] = { "пят", "шест", "сем", "восем", "девят" };
		const string fiveToNineEnd[CASE_SIZE] = { "ь", "и", "и", "ь", "ью", "и" };
		if (value == 8 && !(caseID == 0 || caseID == 3))
			fiveToNineBegin[value - 5][3] = 'ь';
		result += fiveToNineBegin[value - 5] + fiveToNineEnd[caseID];
	}
	if (value != 0)
		result += " ";
	return result;
}

std::string sumProp(long long nSum, std::string sGender, std::string sCase)
{
	vector <string> cases{ "И", "Р", "Д", "В", "Т", "П" };
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

	vector <string> genders{ "М", "Ж", "С" };
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
	if (caseID == 5)		// Case == "П"
		result += "о ";	
	if (nSum < 0)
	{
		result += "минус ";
		nSum *= -1;
	}
	else if (nSum == 0)
	{
		vector <string> zeroCases{ "ноль", "ноля", "нолю", "ноль", "нолем", "ноле" };
		return result + zeroCases[caseID];
	}

	deque <string> tripleProp;	// дек для хранения строк для каждой из разрядных троек

	/* Алгоритм: разбиваем исходное число на разрядные тройки: 
	 - до 1000
	 - тысячи
	 - миллионы
	 - миллиарды
		Написание числа для каждой из троек вычисляется независимо в функции getTripleProp 
	 и помещается в getTripleProp с указанием разрядного множителя, если необходимо. После
	 вычисления последней тройки, строится полное представление числа.
	 */
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
			vector <string> thousandCases{ "тысяч", "тысяч", "тысячам", "тысяч", "тысячами", "тысячах" };
			if (thousands % 10 > 0 && thousands % 10 < 5)
			{
				if (thousands % 10 == 1)
					thousandCases = { "тысяча", "тысячи", "тысячу", "тысяча", "тысячей", "тысяче" };
				else
					thousandCases[0] = thousandCases[3] = "тысячи";
			}				
			tripleResult += thousandCases[caseID];
		}
		else if (tripleProp.size() == 2)
		{
			vector <string> millionCases{ "миллионов", "миллионов", "миллионам", "миллионов", "миллиона", "миллионах" };
			int millions = nSum % 1000;			
			if (millions % 10 > 1 && millions % 10 < 5)
			{
				if (millions % 10 == 1)
					millionCases = { "миллион", "миллион", "миллиону", "миллион", "миллионом", "миллионе" };
				else
					millionCases[0] = millionCases[3] = "миллиона";
			}
			tripleResult += millionCases[caseID];
		}
		else if (tripleProp.size() == 3)
		{
			vector <string> billionCases{ "миллиардов", "миллиардов", "миллиардам", "миллиардов", "миллиардами", "миллиардах" };
			int decBillions = (nSum % 1000) % 10;
			if (decBillions > 1 && decBillions < 5)
				billionCases[0] = billionCases[3] = "миллиард";
			else if (decBillions == 1)
				billionCases = { "миллиард", "миллиарда", "миллиарду", "миллиард", "миллиардом", "миллиарде" };
				

			
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
