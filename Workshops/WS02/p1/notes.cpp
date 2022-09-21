//bool read(int& value, FILE* fptr)
//{
//	//bool ok = false;
//	//if (fptr)
//	//{
//	//	ok = fscanf(fptr, "%d", &value) == 1;
//	//}
//	//return ok;
//
//	bool success = fscanf(fptr, "%d", &value) == 1;
//	return success;
//}
//bool read(double& value, FILE* fptr)
//{
//	bool ok = false;
//	if (fptr)
//	{
//		ok = fscanf(fptr, "%lf", &value) == 1;
//	}
//	return ok;
//
//	bool success = fscanf(fptr, "%lf", &value) == 1;
//	return success;
//}
//bool read(char* cstr, FILE* fptr)
//{
//	bool ok = false;
//	if (fptr)
//	{
//		ok = fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
//	}
//
//	return ok;
//	bool success = fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
//	return success;
//}