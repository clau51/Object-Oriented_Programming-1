#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dictionary.h"
#include "word.h"

using namespace std;

namespace sdds
{
	//Dictionary dictRecs[MAX_NO_OF_RECS] = {0};
	int noDefRecs = 0;
	int noWordRecs = 0;
	char ch;
	Dictionary dictRecs = { 0 };
	Word wordRecs[MAX_WORDS] = {0};
	Definition defRecs[MAX_DEF] = {0};
	FILE* sfptr = nullptr;
	
	bool openFileForRead(const char* const file)
	{
		sfptr = fopen(file, "r");
		return sfptr != NULL;
	}

	bool openFileForOverwrite(const char* const file)
	{
		sfptr = fopen(file, "w");
		return sfptr != NULL;
	}

	bool freadWord(Word* word)
	{
		bool success = fscanf(sfptr, "%[^\n]", word->word);
		return success;
	}

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
		Word word = {};
		Definition definition = {};

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
				else  //dictionary.words[100].word[1].definitions[1].type[1].definition[1]
				{
					ungetc(ch, sfptr);
					if (freadWord(&word))
					{
						//wordRecs[noWordRecs++] = word;
						dictRecs.words[noWordRecs++] = word;
						noDefRecs = 0;
						dictRecs.totalWord = noWordRecs;
					}
				}
			}
			closeFile();
		}

		return ok;
	}

	//bool saveList()
	//{
	//	bool ok = false;
	//	if (openFileForOverwrite(sfptr))
	//	{

	//	}
	//}

	void justTesting()
	{

		for (int i = 0; i < dictRecs.totalWord; i++)
		{
			cout << dictRecs.words[i].word << endl;

			for (int j = 0; j < dictRecs.words[i].totalDef; j++) 
			{
				cout << dictRecs.words[i].definitions[j].type << ": ";
				cout << dictRecs.words[i].definitions[j].definition << endl;
			}
		}
	}

	int searchWordIndex(const char* string)
	{
		int flag = 0;
		int index = 0;

		for (int i = 0; i < dictRecs.totalWord && flag == 0; i++)
		{
			if (strcmp(string, dictRecs.words[i].word) == 0)
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

	//void addNewWord ()

	//Dictionary getNewRecord(const char* word, const char* type, const char* definition)
	//{
	//	Dictionary dictionary = {};

	//}

	//int mostRecentWordIndex()
	//{
	//	;
	//}

	//int emptyWordIndex()
	//{
	//	return dictRecs.totalWord;
	//}

	//int sendTotalWords()
	//{
	//	return dictRecs.totalWord;
	//}

	//bool isWordExist()
	//{
	//	return searchWordIndex()
	//}

	//Utils
	int getInt(int min, int max)
	{
		int userInput;
		int i;
		int flag;


		do
		{
			flag = 0;
			cin >> userInput;
			if (userInput < min || userInput > max)
			{
				cout << "The number you have entered is invalid. Please enter a valid number: ";
				flag = 1;
			}
		} while (flag == 1);

		return userInput;
	}

}
