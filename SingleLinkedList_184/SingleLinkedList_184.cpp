#include <iostream>
using namespace std;

struct Node
{
	int NoMhs;
	string name;
	Node* next;
};

Node* START = NULL;

void addNode() {
	int nim;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukkan NIM : ";
	cin >> nim;
	cout << "Masukan Nama : ";
	cin >> nama;
	nodeBaru->NoMhs = nim;
	nodeBaru->name = nama;

}