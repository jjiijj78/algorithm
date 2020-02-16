
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


vector <int> leaf_node;
int n;
int** arr;

void allocation();
void prints();
void find_lnode();
int main() {
	
	allocation();
	prints();
	find_lnode();
	return 0;
}

void allocation() {
	cin >> n;
	arr = new int*[n - 1];
	for (int i = 0; i < n - 1; i++) {
		arr[i] = new int[3];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

}
void prints() {

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << "a" << endl;
}
void find_lnode() {

	for (int i = 0; i < n - 1; i++) {
		leaf_node.push_back(arr[i][1]);
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j][0] == arr[i][1]) {
				leaf_node.pop_back();
				break;
			}
		}
	}
}