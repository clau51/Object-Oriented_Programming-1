//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 19, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "word.h"
#include "dictionary.h"

using namespace std;

namespace sdds
{
	//Saves the dictionary into a file
	void SaveDictionary(const char* filename)
	{
		if (openFileForWrite(filename))
		{
			fwriteDictionary();
		}
		closeFile();
	}
	
	//Search in dictionary for the word and display all definitions found
	void DisplayWord(const char* word)
	{
		int index;
		
		//Get the index of the word; if it is not found, index will be -1
		index = searchWordIndex(word);

		//If the word is found, display all definitions
		if (index >= 0)
		{
			cout << "FOUND: [" << word << "] has " << "[" 
				<< dictRecs.m_words[index].m_totalDef << "]" << " definitions:" << endl;
			
			//Display definitions by passing in the index
			printTypeDefinition(index);
		}
		//If the word is not found, display a message
		else
		{
			cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
		}
	}

	//Add a new word to the dictionary; if it exists then update the definition instead
	void AddWord(const char* word, const char* type, const char* definition)
	{
		int existWordIndex = 0;
		int emptyWordIndex = 0;
		int emptyDefIndex = 0;

		//Get the index of the word; if it is not found, index will be -1
		existWordIndex = searchWordIndex(word);
		emptyWordIndex = dictRecs.m_totalWord;

		//Check if the word is already in the dictionary (if it is -1, it is a NEW word and not in the dictionary)
		if (existWordIndex < 0)
		{
			//Check if there is space in the dictionary
			if (emptyWordIndex < MAX_WORDS)
			{
				//Check if the word is too long
				if (checkLen(word, MAX_WORD_LEN))
				{
					//If the word is not too long, copy it into the dictionary
					strcpy(dictRecs.m_words[emptyWordIndex].m_word, word);

					//Check if the type and definition is too long
					if (checkLen(type, MAX_WORD_LEN) && checkLen(definition, MAX_DEF_LEN))
					{
						//If the type and definition is not too long, copy it into the dictionary
						copyTypeDefinition(emptyWordIndex, 0, type, definition);
						//Add to the total word count
						dictRecs.m_totalWord++;
						//Add to the total definition count
						dictRecs.m_words[emptyWordIndex].m_totalDef++;
					}
					else
					{
						printLenError();
					}
				}
				else
				{
					printLenError();
				}
			}
			else
			{
				cout << "Dictionary is full." << endl;
			}
		}
		//Else if the word is already in the dictionary (found), change the type and definition only
		else
		{
			//Check if there is space for the type and definition 
			if (emptyDefIndex < MAX_DEF)
			{
				//Check if the type and definition is too long
				if (checkLen(type, MAX_WORD_LEN) && checkLen(definition, MAX_DEF_LEN))
				{
					//Set the empty index for the definition to be the total definition count (since an index of and array is always one less than the total count)
					emptyDefIndex = dictRecs.m_words[existWordIndex].m_totalDef;
					//Copy the type and definition into the dictionary
					copyTypeDefinition(existWordIndex, emptyDefIndex, type, definition);
					//Increment the total definition count
					dictRecs.m_words[existWordIndex].m_totalDef++;
				}
				else
				{
					printLenError();
				}
			}
			else
			{
				cout << "Max definitions has been reached." << endl;
			}
		}
	}

	//Update the definition of a word
	int UpdateDefinition(const char* word, const char* type, const char* definition)
	{
		int userInput = 0;
		int minNum;
		int maxNum;
		int index; 

		//Get the index of the word; if it is not found, index will be -1
		index = searchWordIndex(word);
		minNum = 1;
		maxNum = dictRecs.m_words[index].m_totalDef;

		//If there is more than one definition, prompt user to ask which definition to update
		if (maxNum > 1)
		{
			cout << "The word [" << word << "] has multiple definitions:" << endl;
			
			//Pass in the index of the word to display all definitions of that particular word
			printTypeDefinition(index);
			cout << "Which one to update? ";
			userInput = getInt(minNum, maxNum);

			//Check if the type and definition is too long
			if (checkLen(type, MAX_WORD_LEN) && checkLen(definition, MAX_DEF_LEN))
			{
				//If the type and definition is not too long, update it into the dictionary
				copyTypeDefinition(index, userInput - 1, type, definition);
			}
			else
			{
				printLenError();
			}
		}
		
		//If there is only one definition, update it automatically
		else
		{
			if (checkLen(type, MAX_WORD_LEN) && checkLen(definition, MAX_DEF_LEN))
			{
				copyTypeDefinition(index, 0, type, definition);
			}
			else
			{
				printLenError();
			}
		}
		return 0;
	}

	//Search for the index of a word
	int searchWordIndex(const char* string)
	{
		int i;
		int exist = 0;
		int index = 0;

		for (i = 0; i < dictRecs.m_totalWord && exist == 0; i++)
		{
			//Check if the word is in the dictionary
			if (strcmp(string, dictRecs.m_words[i].m_word) == 0)
			{
				index = i;
				
				//Exit the loop if the word is found
				exist = 1;
			}
			else
			{
				index = -1;
			}
		}

		//Return the index of the word
		return index;
	}

	//Print the type and definition of a word at a particular index
	void printTypeDefinition(const int index)
	{
		int i;

		for (i = 0; i < dictRecs.m_words[index].m_totalDef; i++)
		{
			cout << i + 1 << ". " << "{" << dictRecs.m_words[index].m_definitions[i].m_type
				<< "} " << dictRecs.m_words[index].m_definitions[i].m_definition << endl;
		}
	}

	//Copy the type and definition into the dictionary
	void copyTypeDefinition(int wordIndex, int defIndex, const char* type, const char* definition)
	{
		strcpy(dictRecs.m_words[wordIndex].m_definitions[defIndex].m_type, type);
		strcpy(dictRecs.m_words[wordIndex].m_definitions[defIndex].m_definition, definition);
	}

	//Check if the length of a string is too long
	bool checkLen(const char* string, int maxLength)
	{
		return strlen(string) < unsigned(maxLength + 1);
	}

	//Print error message
	void printLenError()
	{
		cout << "ERROR: Exceeded maximum length!" << endl;
	}
}