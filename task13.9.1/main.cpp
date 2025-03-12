#include<iostream>
#include"class.h"

int main() {
    setlocale(LC_ALL, "");
    Human network;
    network.addHuman("Alice");
    network.addHuman("Bob");
    network.addHuman("Charlie");
    network.addHuman("David");
    network.addHuman("Eve");
    network.addHuman("Frank");
    network.addHuman("Grace");

    network.addFriendship("Alice", "Bob");
    network.addFriendship("Alice", "Charlie");
    network.addFriendship("Bob", "David");
    network.addFriendship("Charlie", "Eve");
    network.addFriendship("David", "Frank");
    network.addFriendship("Eve", "Grace");

    network.findMostTreeH();

    return 0;
}