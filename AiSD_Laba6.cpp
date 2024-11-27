#include "iostream"
#include "stack"
#include "list"
using namespace std;

class TopSort {
private:
	int vertices;
	list<int>* smeg;
	void TopSorting(int vertices, bool visited[], stack<int>& Stack);

public:
	TopSort(int vertices);
	void add(int v, int w);
	void sort();
};

TopSort::TopSort(int vertices) {
	this->vertices = vertices;
	smeg = new list<int>[vertices];
}

void TopSort::add(int v, int w) {
	smeg[v].push_back(w);
}

void TopSort::TopSorting(int v, bool visited[], stack<int>& Stack) {
	visited[v] = true;
	list<int>::iterator i;
	for (i = smeg[v].begin(); i != smeg[v].end(); i++) {
		if (!visited[*i])
			TopSorting(*i, visited, Stack);
	}
	Stack.push(v);
}

void TopSort::sort() {
	stack<int> mangra;
	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visited[i] = false;
	for (int i = 0; i < vertices; i++) {
		if (visited[i] == false)
			TopSorting(i, visited, mangra);
	}
	while (mangra.empty() == false) {
		cout << mangra.top() << " ";
		mangra.pop();
	}
}

void addler(TopSort& mangra, int dis) {
	cout << endl;
	int a, b;
	for(int i=0; i<dis; i++){
		cout << "Введите номер зависимую дисциплину, а после основную для неё дисциплину\n";
		cin >> a >> b;
		mangra.add(a, b);
	}
}

void correct(TopSort& mangra) {
	cout << endl;
	mangra.sort();
}

int main() {
	setlocale(LC_ALL, "RU");
	int dis;
	cout << "Введите количество дисциплин\n";
	cin >> dis;
	TopSort mangra(dis);
	while (true) {
		int mode;
		cout << endl;
		cout << "1. Ввод дисциплин\n";
		cout << "2. Проверка корретного размещения\n";
		cout << "0. Выход\n";
		cin >> mode;
		switch (mode) {
		case 1:
			addler(mangra, dis);
			break;
		case 2:
			correct(mangra);
			break;
		case 0:
			return 0;
		default:
			cout << "Неверный ввод\n";
		}
	}
}