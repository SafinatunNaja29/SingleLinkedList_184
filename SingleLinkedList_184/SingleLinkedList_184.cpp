#include <iostream>
using namespace std;

struct Node {
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

	if (START == NULL || nim <= START->NoMhs) {
		if (START != NULL && nim == START->NoMhs) 
		{
			cout << " NIM suda ada " << endl;
			return;
		}

		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (nim >= current->NoMhs)) 
	{
		if (nim == current->NoMhs) 
		{
			cout << " NIM sudah ada " << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool searchNode(int nim, Node* current, Node* previous) {
	previous = START;
	current = START;
	while (current != NULL && nim > current->NoMhs)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return false;
	}
	else if (current->NoMhs == nim)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool deleteNode(int nim) {
	Node* current = START;
	Node* previous = START;
	if (searchNode(nim, previous, current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = current->next;
	return true;
}
bool listEmpty() {
	if (START == NULL)
		return true;
	else
		return false;

}

void traverse() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << "NIM : " << currentNode->NoMhs << ", Nama : " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void searchData() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukkan NIM : ";
		cin >> nim;
		Node* currentNode = START;
	}
}