#include<iostream>
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Line.h"	
#include "Rect.h"
#include "UI.h"
#include "GraphicEditor.h"

GraphicEditor::GraphicEditor() {
	pStart = NULL;
	pLast = NULL;
}
GraphicEditor::~GraphicEditor() {
	Shape* p = pStart;
	while (p != pStart) {
		Shape *q = p->getNext();
		delete p;
		p = q;
	}
}

void GraphicEditor::paint() {
	Shape* p = pStart;
	int i = 0;
	while (p != NULL) {
		UI::print(i);
		UI::print(":");
		p->paint();
		p = p->getNext();
		i++;
	}
}
void GraphicEditor::edit() {
	int shapetype = UI::getShapeMenu();
	switch (shapetype) {
		case LINE:
			add(new Line()); break;
		case CIRCLE:
			add(new Circle()); break;
		case RECT:
			add(new Rect()); break;
		default:
			UI::printIn("도형 선택 오류");

	}
}
void GraphicEditor::remove(int shapeIndex) {
	if (pLast == NULL) {
		UI::printIn("도형이 없음");
	}
	int i = 0;
	Shape* p = pStart;
	Shape* beforeP = pStart;
	if (shapeIndex == 0) {
		pStart = p->getNext();
		delete p;
		return;
	}
	while (i < shapeIndex) {
		i++;
		beforeP = p;
		p = p->getNext();
	}
	beforeP->add(p->getNext());
	delete p;
}

void GraphicEditor::remove() {
	int shapeIndex = UI::getShapedelete();
	remove(shapeIndex);
}

void GraphicEditor::run() {
	UI::printIn("그래픽 에디터 입니다.");
	while (true){
		int menu = UI::getMenu();
		switch (menu) {
		case EDIT:
			edit(); break;
		case REMOVE:
			remove(); break;
		case PAINT:
			paint(); break;
		case EXIT:
			return;
		}
	}
}
void GraphicEditor::add(Shape* p) {
	if (pStart == NULL) {
		pStart = p;
		pLast = p;
	}
	else {
		pLast->add(p);
		pLast = p;
	}
}