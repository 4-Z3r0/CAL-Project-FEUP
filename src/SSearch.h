#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//Returns the minimum between three elements
int minThreeElem(int a, int b, int c)
{
	if (a > b && a > c)
		return min(b, c);
	else if (b > c)
		return min(a, c);
	else
		return min(a, b);
}

/*
*Auxiliary function for kmpMatcher computes the prefix of a given pattern.
*/
std::vector<int> prefixCalc(std::string pattern)
{
	std::vector<int> prefix;

	unsigned int patternSize = pattern.length();
	prefix.resize(patternSize);
	int k = 0;
	prefix.at(0) = 0;
	for (int q = 1; q < patternSize; q++)
	{
		while (k > 0 && pattern.at(k) != pattern.at(q))
			k = prefix.at(k-1);
		if (pattern.at(k) == pattern.at(q))
			k = k + 1;
		prefix.at(q) = k;
	}
	return prefix;
}



/*
*@brief Function returns the number of occurences of a certain pattern(string) in a text(string).
*@param text - text where we search the pattern
*@param pattern - pattern being searched
*@return number of occurences of the pattern in the string
*/
int kmpMatcher(std::string text, std::string pattern) {

	unsigned int textSize = text.length();
	unsigned int patternSize = pattern.length();
	unsigned int count = 0;
	if (pattern.empty() || text.empty())
		return 0;
	if (pattern.length() == text.length())
	{
		if (pattern == text)
			return 1;
		else
			return 0;
	}
	std::vector<int> prefix;
	prefix.resize(patternSize);
	int k = 0;

	prefix = prefixCalc(pattern);
	int q = 0;
	for (int i = 0; i < textSize; i++)
	{
		while (q > 0 && pattern.at(q) != text.at(i))
			q = prefix.at(q-1);
		if (pattern.at(q) == text.at(i))
			q = q + 1;
		if (q == patternSize)
		{
			q = prefix.at(q-1);
			count++;
		}

	}

	return count;
}


/*
*@brief Returns the edit distance between two strings.
*@param pattern one of the strings to compare
*@param text one of the strings to compare
*@return an integer that represents the edit distance between the two strings
*/

int EditDistance(string pattern, string text)
{
	vector<vector<int>> matrix;

	matrix.resize(pattern.size() + 1);

	for (int h = 0; h < matrix.size(); h++)
		matrix.at(h).resize(text.size() +1);

	for (int i = 0; i <= pattern.size(); i++)
		matrix[i][0] = i;

	for (int j = 0; j <= text.size(); j++)
		matrix[0][j] = j;

	for(int i = 1; i <= pattern.size(); i++)
		for (int j = 1; j <= text.size(); j++)
		{
			if (pattern.at(i-1) == text.at(j-1))
				matrix[i][j] = matrix[i - 1][j - 1];
			else
				matrix[i][j] = 1 + minThreeElem(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]);
		}
	return matrix[pattern.size()][text.size()];

}