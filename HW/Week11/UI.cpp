#include<iostream>
using namespace std;
#include "UI.h"

int UI::getMenu() {
	int menu;
	cout << "����:1, ����:2, ��κ���:3, ����:4>>";
	cin >> menu;
	return menu;
}

int UI::getShapeMenu() {
	int shapetype;
	cout << "��:1, ��:2, �簢��:3>>";
	cin >> shapetype;
	return shapetype;
}

int UI::getShapedelete() {
	int shapeIn;
	cout << "�����ϰ��� �ϴ� ������ �ε���>>";
	cin >> shapeIn;
	return shapeIn;
}

void UI::printIn(string msg) {
	cout << msg << endl;
}

void UI::print(string msg) {
	cout << msg;
}

void UI::print(int msg) {
	cout << msg;
}