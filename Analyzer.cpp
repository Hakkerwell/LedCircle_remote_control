/*
1. отсекаем первую строку (заканчивается на \r\n)
2. отсекаем текст по \r\n\r\n
3. остальное считаем телом
*/
#include <iostream>
using namespace std;
#include "include/HttpParser/Analyzer.hpp"

//TODO отсечения контрольных символов
//TODO если был достигнут конец после какого-то шага, то не продолжать
//TODO минимальный размер каждого элемента по ..StartOn и ..EndOn
//TODO маркеры
Analyzer *Analyzer::analyze() {
	int cursorPos = 0;
	
	int firstLineStartOn = 0;
	int firstLineEndOn = 0;
	int headerStartOn = 0;
	int headersEndOn = 0;
	int bodyStartOn = 0;
	int bodyEndOn = 0;
	
	char currChar = ' ';
	char prevChar = ' ';
	
	
	// Определение первой линии
	firstLineStartOn = 0;
	for (currChar = ' ', prevChar = ' '; currChar != '\0'; ++cursorPos) {
		currChar = text_[cursorPos];
		
		if (currChar == '\n' && prevChar == '\r')
			break;
		
		prevChar = currChar;
	}
	firstLineEndOn = cursorPos;
	
	// Определение заголовка
	headerStartOn = cursorPos;
	for (currChar = ' ', prevChar = ' '; currChar != '\0'; ++cursorPos) {
		currChar = text_[cursorPos];
		//cout << currChar << endl;
		// проверка конструкции вида: \r\n\r\n
		if (currChar == '\n' && prevChar == '\r')
			if (text_[cursorPos - 2] == '\n' && text_[cursorPos - 3] == '\r')
				break;
		
		prevChar = currChar;
	}
	headersEndOn = cursorPos;
	
	// Определение тела
	bodyStartOn = cursorPos;
	for (currChar = ' '; currChar != '\0'; ++cursorPos)
		currChar = text_[cursorPos];
	bodyEndOn = cursorPos;
	
	// Сохранение текста в первую строку, заголовок и тело
	savePart(firstLineText_, firstLineStartOn, firstLineEndOn);
	savePart(header_, headerStartOn, headersEndOn);
	savePart(body_, bodyStartOn, bodyEndOn);
	
	return this;
}

//						ссылка на указатель char*
void Analyzer::savePart(char *&variable, int startOn, int endOn) {
	int textLen = endOn - startOn;
	
	variable = new char[textLen];
	for (int i = 0; i < textLen; ++i)
		variable[i] = text_[startOn + i];
}