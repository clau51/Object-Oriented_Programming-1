//int LoadDictionary(const char* const file)
//{
//	Word word = {};
//	Definition definition = {};

//	int ok = 1;
//	if (openFileForRead(file))
//	{
//		ok = 0;
//		while (noOfRecsWords < MAX_WORDS &&
//			freadWord(&word))
//		{
//			while (noOfRecsDef < MAX_DEF &&
//				freadDefinition(&definition))
//			{
//				defRecs[noOfRecsDef++] = definition;
//			}

//			wordRecs[noOfRecsWords++] = word;
//		}
//		closeFile();
//	}

//	return ok;
//}

//int LoadDictionary(const char* const file)
//{
//	Word word = {};
//	Definition definition = {};

//	int ok = 1;
//	if (openFileForRead(file))
//	{
//		ok = 0;
//		while (!feof(sfptr))
//		{
//			ch = fgetc(sfptr);
//			if (ch == '\t')
//			{
//				// Store characters until end of line.
//				fscanf(sfptr, "%[^:]: %[^\n]\n", definition.type, definition.definition);	
//			}
//			else
//			{
//				// Store character until end of line.
//				//Word temp = { 0 };
//				//int i;
//				//for (i = 0; i != '\n'; i++)
//				//{
//				//	word.word[i] = ch;
//				//}
//				//fscanf(sfptr, "%[^\n]\n", temp.word);

//				//for (i = 1; i < strlen(temp.word); i++)
//				//{
//				//	strcpy(&word.word[i], &temp.word[i]);
//				//}

//				wordRecs[noOfRecs++] = word;
//			}
//		}
//		closeFile();
//	}


		//cout << dictRecs.words[0].word << endl;
		//cout << dictRecs.words[0].definitions[0].type << ": " << dictRecs.words[0].definitions[0].definition << endl;
		//cout << dictRecs.words[1].word << endl;
		//cout << dictRecs.words[1].definitions[0].type << ": " << dictRecs.words[1].definitions[0].definition << endl;
		//cout << dictRecs.words[1].definitions[1].type << ": " << dictRecs.words[1].definitions[1].definition << endl;
		//cout << dictRecs.words[1].definitions[2].type << ": " << dictRecs.words[1].definitions[2].definition << endl;
		//cout << dictRecs.words[1].definitions[3].type << ": " << dictRecs.words[1].definitions[3].definition << endl;
		//cout << dictRecs.words[2].word << endl;
		//cout << dictRecs.words[2].definitions[0].type << ": " << dictRecs.words[2].definitions[0].definition << endl;
		//cout << dictRecs.words[2].definitions[1].type << ": " << dictRecs.words[2].definitions[1].definition << endl;
		//cout << dictRecs.words[3].word << endl;
		//cout << dictRecs.words[3].definitions[0].type << ": " << dictRecs.words[3].definitions[0].definition << endl;
		//cout << dictRecs.words[3].definitions[1].type << ": " << dictRecs.words[3].definitions[1].definition << endl;

		//cout << dictRecs.words[0].definitions[0].type;

		//cout << dictRecs.totalWord << endl;



		//cout << dictRecs.words[4].word << endl;
		//cout << dictRecs.words[4].definitions[0].type << ": " << dictRecs.words[4].definitions[0].definition << endl;


	//void DisplayWords(const Word* word)
	//{

	//	int i;
	//	int flag = 0;
	//	//for (i = 0; word[i] != '\0' && flag == 0; i++)
	//	//{

	//	//}
	//	for (i = 0; i < noOfRecsWords; i++)
	//	{
	//		cout << word->word[i];
	//	}
	//}

	//void displaDictionaryList()
	//{

	//	for (int i = 0; i < noOfRecsWords; i++)
	//	{
	//		cout << DisplayWord(&)
	//	}
	//}