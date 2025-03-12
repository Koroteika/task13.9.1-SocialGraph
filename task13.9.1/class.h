#pragma once
#include<iostream>
#include<string>
#include<queue>
#define SIZE 10
#define INF 1000000

class Graph {
private:
	int matrix[SIZE][SIZE];
	int size;

public:
	Graph();
	void addEdge(int v1, int v2);
	void delEdge(int v1, int v2);
	bool connected(int v1, int v2);
	void findMostTree(int start, bool res[SIZE]);
};
class Human {
private:
	std::string names[SIZE];
	Graph graph;
	int size;
	int findIndex(const std::string& name);
	
public:
	Human();
	void addHuman(const std::string& name);
	void addFriendship(const std::string& name1, const std::string& name2);
	void delFriendship(const std::string& name1, const std::string& name2);
	bool areFriends(const std::string& name1, const std::string& name2);
	void findMostTreeH();
};