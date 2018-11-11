#ifndef ANALYZER_H
#define ANALYZER_H
/*
 * разделение по маркеру
 * замена текста
 * определение наличия символа













*/

class Analyzer {
	char *text_;

	char *firstLineText_;
	char *header_;
	char *body_;
	
	void savePart(char *&variable, int startOn, int endOn);
public:
	//Analyser() {};
	Analyzer(char *text)					{ this->text_ = const_cast<char*>(text); };
	
	Analyzer *analyze();
	
	char *getFirstLineText()				{ return firstLineText_; };
	char *getHeaderText()					{ return header_; };
	char *getBodyText()						{ return body_; };
};

#endif
