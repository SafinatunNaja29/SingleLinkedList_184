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
		while (currentNode != NULL) {
			if (currentNode->NoMhs == nim) {
				cout << "NIM : " << currentNode->NoMhs << ", Nama : " << currentNode->name << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Data tidak ditemukan" << endl;
	}
}

int main() {
	int pilihan;
	do
	{
		try
		{

			cout << "1. Tambah Data" << endl;
			cout << "2. Hapus Data" << endl;
			cout << "3. Tampilkan Data" << endl;
			cout << "4. Cari Data" << endl;
			cout << "5. Keluar" << endl;
			cout << "Pilihan : ";
			cin >> pilihan;
			switch (pilihan)
			{
			case 1:
				addNode();
				cout << "Data Berhasil Ditambahkan" << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				if (listEmpty())
				{
					cout << "List Kosong" << endl;
					system("pause");
					system("cls");
					break;
				}

				int nim;
				cout << "Masukkan NIM :";
				cin >> nim;
				if (deleteNode(nim)) {
					cout << "nim : " << nim << "berhasil dihapus" << endl;
					system("pause");
					system("cls");
				}
				else
					cout << "Data tidak ditemukan" << endl;
				break;
			case 3:
				traverse();
				break;
			case 4:
				searchData();
				break;
			case 5:
				break;
			default :
				cout << "Pilihan tidak ada" << endl;
				break;
			}
		}
		catch (exception e)
		{
			cout << "Terjadi Kesalahan" << endl;
		}

	} while (pilihan != 5);
}