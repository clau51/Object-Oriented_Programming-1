#include <iostream>
#include "dictionary.h"

using namespace std;

namespace sdds
{
	const int MAX_WORD_LEN = 64;
	const int MAX_DEF_LEN = 1024;

	struct Dictionary
	{
		char word[MAX_WORD_LEN + 1];
		char type[MAX_WORD_LEN + 1];
		char definition[MAX_DEF_LEN + 1];
	};

	FILE* sfptr = nullptr;

	
	bool openFileForRead()
	{
		sfptr = fopen("dictionary.txt", "r");
		return sfptr != NULL;
	}

	bool freadDictionary(Dictionary* dictionary)
	{
		bool success = fscanf(sfptr, "%[^\n]\n\t%[^:]:%[^\n]\n", 
			dictionary->word, dictionary->type, dictionary->definition) <= 8;
	}
}
