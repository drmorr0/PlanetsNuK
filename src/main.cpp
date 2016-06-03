
#include <json/json.h>
#include <fstream>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 1)
	{
		printf("Usage: %s <turnfile>\n", argv[0]);
		return -1;
	}

	ifstream turnfile(argv[1]);
	
	Json::Value root;
	turnfile >> root;
	cout << root << "\n";

	return 0;
}



