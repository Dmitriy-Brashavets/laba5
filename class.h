#pragma once

#include <iostream>

class Set {
private:
	static int MAX_SIZE;
	int aSize;
	char* apArr;
public:
	operator int();
	Set operator + (char);
	Set operator * (const Set&);
	void Print();
	void Input();
	void Add(char);
	bool ItIs(char) const;
	Set();
	Set(const Set&);
	~Set();
};