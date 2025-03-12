#include"class.h"
#include <queue>
//Граф
Graph::Graph() :size(0) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = 0;
		}
	}
}
void Graph::addEdge(int v1, int v2) {
	if (v1 < SIZE && v2 < SIZE) {
		matrix[v1][v2] = matrix[v2][v1] = 1;
	}
}
void Graph::delEdge(int v1, int v2) {
	if (v1 < SIZE && v2 < SIZE) {
		matrix[v1][v2] = matrix[v2][v1] = 0;
	}
}
bool Graph::connected(int v1, int v2) {
	return (v1 < SIZE && v2 < SIZE && matrix[v1][v2] == 1);
}
void Graph::findMostTree(int start, bool res[SIZE]) {
	int distance[SIZE];
	std::queue<int> q;

	for (int i = 0; i < SIZE; i++) distance[i] = INF;

	q.push(start);
	distance[start] = 0;

	while (!q.empty()) {
		int person = q.front();
		q.pop();

		if (distance[person] >= 3) continue;

		for (int i = 0; i < SIZE; i++) {
			if (matrix[person][i] == 1 && distance[i] == INF) {
				distance[i] = distance[person] + 1;
				q.push(i);
				res[i] = true;
			}
		}
	}
}
//Люди
Human::Human() :size(0) {}
int Human::findIndex(const std::string& name) {
	for (int i = 0; i < size; i++) {
		if (names[i] == name) return i;
	}
	return -1;
}
void Human::addHuman(const std::string& name) {
	if (size < SIZE) {
		names[size] = name;
		size++;
	}
	else {
		std::cout << "Максимальное количество людей достигнуто!" << std::endl;
	}
}
void Human::addFriendship(const std::string& name1, const std::string& name2) {
	int idx1 = findIndex(name1);
	int idx2 = findIndex(name2);
	if (idx1 != -1 && idx2 != -1) {
		graph.addEdge(idx1, idx2);
	}
}
void Human::delFriendship(const std::string& name1, const std::string& name2) {
	int idx1 = findIndex(name1);
	int idx2 = findIndex(name2);
	if (idx1 != -1 && idx2 != -1) {
		graph.delEdge(idx1, idx2);
	}
}
bool Human::areFriends(const std::string& name1, const std::string& name2) {
	int idx1 = findIndex(name1);
	int idx2 = findIndex(name2);
	return (idx1 != -1 && idx2 != -1 && graph.connected(idx1, idx2));
}
void Human::findMostTreeH() {
	bool connections[SIZE][SIZE] = { false };

	for (int i = 0; i < size; i++) {
		bool result[SIZE] = { false };
		graph.findMostTree(i, result);
		for (int j = 0; j < size; j++) {
			if (result[j] && i < j) {
				connections[i][j] = true;
			}
		}
	}

	std::cout << "Пары людей, знакомых через <= 3 рукопожатия:" << std::endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (connections[i][j]) {
				std::cout << names[i] << " - " << names[j] << std::endl;
			}
		}
	}
}



