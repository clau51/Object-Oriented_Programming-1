#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "dictionary.h"


using namespace std;

namespace sdds
{
	int noDefRecs = 0;
	int noWordRecs = 0;
	Dictionary dictRecs = { 0 };
	Word wordRecs[MAX_WORDS] = { {0} };
	Definition defRecs[MAX_DEF] = { {{0}} };
	FILE* sfptr = nullptr;

	//Discard previously existing dictionary
	void clearList()
	{
		int i;
		const struct Word emptyWord = { 0 };
		
		for (i = 0; i < dictRecs.totalWord; i++)
		{
			dictRecs.words[i] = emptyWord;
		}
	}

	//Open file and check if NULL
	bool openFileForRead(const char* const file)
	{
		sfptr = fopen(file, "r");
		return sfptr != NULL;
	}

	//Write in file and check if NULL
	bool openFileForWrite(const char* const file)
	{
		sfptr = fopen(file, "w");
		return sfptr != NULL;
	}

	//Reads formatted input into stream for word
	bool freadWord(Word* word)
	{
		bool success = fscanf(sfptr, "%[^\n]", word->word);
		return success;
	}

	//Reads formatted input into stream for definition
	bool freadDefinition(Definition* definition) {
		bool success = fscanf(sfptr, "%[^:]: %[^\n]", 
			definition->type, definition->definition);
		return success;
	}

	void closeFile()
	{
		if (sfptr)
		{
			fclose(sfptr);
		}
	}

	int LoadDictionary(const char* const file)
	{
		char ch;
		Word word = {};
		Definition definition = {};
		
		clearList();

		int ok = 1;
		if (openFileForRead(file))
		{
			ok = 0;
			while (!feof(sfptr))
			{
				ch = fgetc(sfptr);
				if (ch == '\t')
				{ 
					if (freadDefinition(&definition))
					{
						dictRecs.words[noWordRecs - 1].definitions[noDefRecs++] = definition;
						dictRecs.words[noWordRecs - 1].totalDef = noDefRecs;
					};
				}
				else if (ch == '\n' || ch == EOF)
				{
					;
				}
				else  
				{
					ungetc(ch, sfptr);
					if (freadWord(&word))
					{
						dictRecs.words[noWordRecs++] = word;
						dictRecs.totalWord = noWordRecs;
						noDefRecs = 0;
					}
				}
			}
			closeFile();
		}

		return ok;
	}

	void fwriteDictionary()
	{
		int i;
		int j;
		
		for (i = 0; i < dictRecs.totalWord; i++)
		{
			fprintf(sfptr, "%s\n", dictRecs.words[i].word);
			for (j = 0; j < dictRecs.words[i].totalDef; j++)
			{
				fprintf(sfptr, "\t%s: %s\n", dictRecs.words[i].definitions[j].type,
					dictRecs.words[i].definitions[j].definition);
			}
		}
	}

	int searchWordIndex(const char* string)
	{
		int i;
		int flag = 0;
		int index = 0;

		for (i = 0; i < dictRecs.totalWord && flag == 0; i++)
		{
			if (strcmp(string, dictRecs.words[i].word) == 0) //Check if word is in dictionary
			{
				index = i;
				flag = 1;
			}
			else
			{
				index = -1;
			}
		}

		return index;
	}

	void printTypeDefinition(const int index)
	{
		int i;

		for (i = 0; i < dictRecs.words[index].totalDef; i++)
		{
			cout << i + 1 << ". " << "{" << dictRecs.words[index].definitions[i].type 
				<< "} " << dictRecs.words[index].definitions[i].definition << endl;
		}
	}

	//Should be in utils.cpp file (matrix doesn't allow submission)
	//Get input integer
	int getInt(int min, int max)
	{
		int number;
		int flag = 0;

		do
		{
			flag = 0;
			cin >> number;
			if (number < min || number > max)
			{
				cout << "The number you have entered is invalid. Please enter a valid number: ";
				flag = 1;
			}
		} while (flag == 1);

		return number;
	}

	void copyTypeDefinition(int wordIndex, int defIndex, const char* type, const char* definition)
	{
		strcpy(dictRecs.words[wordIndex].definitions[defIndex].type, type);
		strcpy(dictRecs.words[wordIndex].definitions[defIndex].definition, definition);
	}

	bool checkLen(const char* string, int maxLength)
	{
		return strlen(string) < unsigned(maxLength + 1);
	}

	void printLenError()
	{
		cout << "ERROR: Exceeded maximum length!" << endl;
	}

	// MAX WORDS = 100 words
	// MAX DEFINITIONS = 8 definitions
	// MAX WORD LENGTH = 64 characters
	// MAX TYPE LENGTH = 64 characters
	// MAX DEF LENGTH = 1024 characters

}
