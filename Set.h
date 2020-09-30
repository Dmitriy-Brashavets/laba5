#pragma once
#include<iostream>
class Set {
private:
	static int MAX_SIZE;
	int aSize;
	char *apArr;
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

int Set::MAX_SIZE = 225;

Set::Set() : apArr(nullptr), aSize(0) {}
Set::Set(const Set &oth) {
	aSize = oth.aSize;
	apArr = new char[aSize];
	for (int i = 0; i < aSize; i++)
		apArr[i] = oth.apArr[i];
}
bool Set::ItIs(char ch) const{
	for (int i = 0; i < aSize; i++)
		if (apArr[i] == ch) return 1;
	return 0;
}
Set::~Set() {
	delete[] apArr;
}
void Set::Add(char ch) {
	if (ItIs(ch) || aSize == MAX_SIZE) return;
	char *pTmp = new char[aSize + 1];
	for (int i = 0; i < aSize; i++)
		pTmp[i] = apArr[i];
	pTmp[aSize++] = ch;
	delete[] apArr;
	apArr = pTmp;
}
void Set::Input() {
	char ch;
	while (std::cin >> ch && aSize < MAX_SIZE && ch != '.')
		Add(ch);
}
void Set::Print() {
	for (int i = 0; i < aSize; i++)
		std::cout << apArr[i] << " ";
	std::cout << std::endl;
}
Set::operator int() {
	return aSize;
}
Set Set::operator+(char ch) {
	Set newSet;
	for (int i = 0; i < aSize; i++)
		newSet.Add(apArr[i]);
	newSet.Add(ch);
	return newSet;
}
Set Set::operator*(const Set &oth) {
	Set newSet;
	for (int i = 0; i < aSize; i++)
		for (int j = 0; j < oth.aSize; j++)
			if (apArr[i] == oth.apArr[j])
				newSet.Add(apArr[i]);
	return newSet;
}