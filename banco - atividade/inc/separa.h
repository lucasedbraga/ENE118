#ifndef SEPARA_H
#define SEPARA_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

const vector<string> explode(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

vector<string> separar_csv(string str)
{
	vector<string> v{explode(str, ',')};
	return v;
}

#endif