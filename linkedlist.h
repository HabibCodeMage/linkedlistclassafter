#pragma once
#ifndef LINKED_LIST
#define LINKED_LIST
#include<iostream>
using namespace std;
#include<stddef.h>
class vectors
{
private:
	int x,
		y;
public:
	vectors();
	vectors(int, int);
	int getx() const;
	int gety() const;
	bool operator==(const vectors&);
	friend bool operator<(const vectors&, const vectors&);
	friend ostream& operator<<(const ostream&, const vectors&);
	void print();
	vectors object();
	vectors* next;
};
class linkedlist
{
private:

	vectors* head;
public:
	linkedlist() :head(NULL)
	{}
	void appendlist(const vectors&);
	void insertlist(const vectors&);
	void deletelist(const vectors&);
	void printlist();
	~linkedlist() {}

};
#endif // !LINKED_LIST


