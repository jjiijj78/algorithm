#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
int arr[10][10];
int arr_copy[10][10];
int location_x, location_y, number,direction;
int zero_count, tot_zero_count=10000;

 struct cctv{
	int location_x;
	int location_y;
	int number;
	int direction = 0;
};
vector <cctv> vec;
cctv temp;
map <int, int> number_pair;
struct stacks {
	int number;
	int direction;
};
stacks stack_temp;
vector<stacks> one_line;
vector<vector<stacks>> tot_line;

vector <int> dir;
void function2(int count, int direction);
int function();
void draw(int location_x, int location_y, int number, int direction);
void copys();
void print();

int main() {



	//1번 한쪽 ,2번 평행, 3번 직각, 4번 3방향, 5번 방향
	//scanf("%d %d",&N,&M);
	cin >> N >> M;

	for (int i=0; i < N; i++) {
		for (int j=0; j < M; j++){

			cin >> arr[i][j];

			if (arr[i][j] != 0 && arr[i][j]!=6)
			{
				temp.location_x = i;
				temp.location_y = j;
				temp.number = arr[i][j];
				vec.push_back(temp);
			}
		}
	}

	number_pair.insert(pair<int,int>(1, 4));
	number_pair.insert(pair<int, int>(2, 2));
	number_pair.insert(pair<int, int>(3, 4));
	number_pair.insert(pair<int, int>(4, 4));
	number_pair.insert(pair<int, int>(5, 1));

	int count = 0;
	int direction = 0;
	function2(count, direction);
	function();
	cout << tot_zero_count;
	return 0;

}
void function2(int count, int direction) {//vector의 몇번째, 방향
	if (count < vec.size()) {
		int number = vec.at(count).number;
		for (int direction = 0; direction < number_pair[number]; direction++)
		{

			stack_temp.direction = direction;
			stack_temp.number = number;
			one_line.push_back(stack_temp);
			function2(count+1, direction);
			one_line.pop_back();
		}
		
	}
	else if (count == vec.size()) {
		tot_line.push_back(one_line);
		
	}

}
int function() {
	for (int i = 0; i < tot_line.size(); i++)
	{
		print();
		copys();
		print();
		cout << tot_line.at(i).size();
		for (int j = 0; j < tot_line.at(i).size();j++) {
			cout << "(" << tot_line.at(i).at(j).number << "," << tot_line.at(i).at(j).direction << ")";
	
		}
		cout << endl;
		for (int j = 0; j < tot_line.at(i).size(); j++) {
			
			location_x = vec.at(j).location_x;
			location_y = vec.at(j).location_y;
			number = tot_line.at(i).at(j).number;
			direction = tot_line.at(i).at(j).direction;
			draw(location_x, location_y, number, direction);
		}
		print();
		zero_count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr_copy[i][j] == 0) {
					zero_count += 1;
				}
			}
		}
		tot_zero_count = tot_zero_count > zero_count ? zero_count : tot_zero_count;
	}
		return tot_zero_count;
}
	

void draw(int location_x,int location_y,int number, int direction) {
	int direction_all;
	dir
	if (number == 1)
	{
		dir.push_back(direction);
	}else if (number == 2) {

		dir.push_back(direction);
		dir.push_back(direction+2);
	}else if (number == 3) {
		dir.push_back(direction);
		dir.push_back((direction + 1) % 4);
	}else if (number == 4) {
		dir.push_back(direction);
		dir.push_back((direction + 1) % 4);
		dir.push_back((direction + 3) % 4);
	}else if (number == 5) {
		dir.push_back(direction);
		dir.push_back((direction + 1) % 4);
		dir.push_back((direction + 2) % 4);
		dir.push_back((direction + 3) % 4);
	}


	for (int m = 0; m < dir.size(); m++) {
		direction_all = dir.at(m);
		if (direction_all == 0) {//draw Top
			for (int i = location_x; i >=0; i--) {
				if (arr_copy[i][location_y] == 6)break;
				arr_copy[i][location_y] = 1;
			}
		}
		if (direction_all == 1) {//draw Right
			for (int i = location_y; i < M; i++) {
				if (arr_copy[location_x][i] == 6)break;
				arr_copy[location_x][i] = 1;
			}
		}
		if (direction_all == 2) {//draw Down
			for (int i = location_x; i < N; i++) {
				if (arr_copy[i][location_y] == 6)break;
				arr_copy[i][location_y] = 1;
			}
		}
		if (direction_all == 3) {//draw Left
			for (int i = location_y; i >=0; i--) {
				if (arr_copy[location_x][i] == 6)break;
				arr_copy[location_x][i] = 1;
			}
		}
	}
	

}
void copys() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr_copy[i][j] = arr[i][j];
		}
	}
}
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr_copy[i][j];
		}
		cout << endl;
	}
}