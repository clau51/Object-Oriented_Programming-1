//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 19, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dictionary.h"
#include "word.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	int noDefRecs = 0;
	int noWordRecs = 0;
	Dictionary dictRecs = { 0 };
	FILE* sfptr = nullptr;

	//Discard previously existing dictionary
	void clearList()
	{
		int i;
		const struct Word emptyWord = { 0 };
		
		for (i = 0; i < dictRecs.m_totalWord; i++)
		{
			dictRecs.m_words[i] = emptyWord;
		}
	}

	//Open file for read and check if NULL
	bool openFileForRead(const char* const file)
	{
		sfptr = fopen(file, "r");
		return sfptr != NULL;
	}

	//Open file for write and check if NULL
	bool openFileForWrite(const char* const file)
	{
		sfptr = fopen(file, "w");
		return sfptr != NULL;
	}

	//Reads formatted input into stream for word
	bool freadWord(Word* word)
	{
		bool success = fscanf(sfptr, "%[^\n]", word->m_word);
		return success;
	}

	//Reads formatted input into stream for definition
	bool freadDefinition(Definition* definition) {
		bool success = fscanf(sfptr, "%[^:]: %[^\n]", 
			definition->m_type, definition->m_definition);
		return success;
	}

	//Close file
	void closeFile()
	{
		if (sfptr)
		{
			fclose(sfptr);
		}
	}

	//Load dictionary
	int LoadDictionary(const char* const file)
	{
		char ch;
		Word word = {};
		Definition definition = {};
		
		clearList();

		int ok = 1;
		//If file reads successfully
		if (openFileForRead(file))
		{
			ok = 0;
			//Read until end of file
			while (!feof(sfptr))
			{
				//Get character from stream
				ch = fgetc(sfptr);
				if (ch == '\t')
				{ 
					if (freadDefinition(&definition))
					{
						//Add definition to dictionary; noOfWordRecs must be decremented by 1 since it gets incremented
						//to the next index when a word is added
						dictRecs.m_words[noWordRecs - 1].m_definitions[noDefRecs++] = definition;
						//The total definitions in the dictionary gets incremented
						dictRecs.m_words[noWordRecs - 1].m_totalDef = noDefRecs;
					};
				}
				else if (ch == '\n' || ch == EOF)
				{
					;
				}
				else  
				{
					//Go back one character to capture the first letter of the word
					ungetc(ch, sfptr);
					if (freadWord(&word))
					{
						//Add word to dictionary and increment noOfWordRecs to the next index
						dictRecs.m_words[noWordRecs++] = word;
						//The total words in the dictionary gets incremented
						dictRecs.m_totalWord = noWordRecs;
						//Reset noOfDefRecs to 0 for the next word
						noDefRecs = 0;
					}
				}
			}
			closeFile();
		}

		return ok;
	}

	//Sends formatted output to stream for dictionary
	void fwriteDictionary()
	{
		int i;
		int j;
		
		//Loop through all words in dictionary
		for (i = 0; i < dictRecs.m_totalWord; i++)
		{
			fprintf(sfptr, "%s\n", dictRecs.m_words[i].m_word);
			
			//Loop through all definitions in dictionary
			for (j = 0; j < dictRecs.m_words[i].m_totalDef; j++)
			{
				fprintf(sfptr, "\t%s: %s\n", dictRecs.m_words[i].m_definitions[j].m_type,
					dictRecs.m_words[i].m_definitions[j].m_definition);
			}
		}
	}

	//***NOTE***: Should be in Utils.cpp file (matrix doesn't allow submission)
	//Get user input integer
	int getInt(int min, int max)
	{
		int number;
		int isValid = 1;

		do
		{
			isValid = 1;
			cin >> number;
			if (number < min || number > max)
			{
				cout << "The number you have entered is invalid. Please enter a valid number: ";
				isValid = 0;
			}
			//If input is not between min and max, continue prompting for user input.
		} while (isValid == 0);

		return number;
	}
}
