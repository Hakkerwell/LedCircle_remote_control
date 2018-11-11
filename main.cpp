#include <iostream>
#include "include/DataStructures/Constants.hpp"
#include "include/DataStructures/Message.hpp"
#include "include/HttpParser/Analyzer.hpp"

using namespace std;


int main(int argc, char** argv) {

	cout << "start" << endl;
	Analyzer a((char*)"GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.16.3 libcurl/7.16.3 OpenSSL/0.9.7l zlib/1.2.3\r\nHost: www.example.com\r\nAccept-Language: en, mi\r\n\r\nSomeText");
	a.analyze();

	char *text = a.getHeaderText();
	char c = ' ';
	for (int i = 0; c != '\0'; i++) {
		cout << c;
		c = text[i];
	}
	
	//getFirstLineText
	//a.getHeaderText()
	//a.getBodyText()
	
	
    return 0;
}