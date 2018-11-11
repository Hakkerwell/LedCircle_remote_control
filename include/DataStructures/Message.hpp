#ifndef MESSAGE_H
#define MESSAGE_H

struct Message;
struct RequestMessage;
struct ResponseMessage;

//-----------------------------------------------------------------------------------------

struct Line {
protected:
	int type_;				// запрос или ответ
	float HTTP_version_;
public:
	int 	getType()						{ return type_; };
	float 	getHttpVersion()                { return HTTP_version_; };
	
	void 	setType(int type)               { this->type_ = type; };
	void 	setHttpVersion(float version)	{ this->HTTP_version_ = version; };
};

//-----------------------------------------------------------------------------------------

// Компоненты сообщения

// Первая строка

//method SP request-target SP HTTP-version CRLF
struct RequestLine : public Line {
protected:
	int 	method_;
	char 	*request_target_;
public:
	int 	getMethod()                     { return method_; };
	char 	*getRequestTarget()             { return request_target_; };
	
	void setMethod(int method)              { this->method_ = method; };
	void setRequestTarget(char *target)     { this->request_target_ = const_cast<char*>(target); };		//TODO убрать const_cast
};

//HTTP-version SP status-code SP reason-phrase CRLF
struct ResponseLine : public Line {
protected:
	int 	status_code_;
	char 	*reason_phrase_;
public:
	int 	getStatusCode()                 { return status_code_; };
	char 	*getReasonPhrase()              { return reason_phrase_; };
	
	void setStatusCode(int code)            { this->status_code_ = code; };
	void setReasonPhrase(char *phrase)	{ this->reason_phrase_ = const_cast<char*>(phrase); };
};

// Заголовок

struct Header {
protected:
	char 	*name_;
	char 	*value_;
public:
	char 	*getName() 			{ return name_; };
	char 	*getValue()                     { return value_; };
	
	void setName(char *name)                { this->name_ = const_cast<char*>(name); };
	void setValue(char *value)              { this->value_ = const_cast<char*>(value); };
};

// Тело

struct Body {
protected:
	char 	*text_;
public:
	char 	*getText() 			{ return text_; };
	
	void setText(char *text)                { this->text_ = const_cast<char*>(text); };
};

//-----------------------------------------------------------------------------------------

// Повторяющиеся элементы в запросе и ответе
struct Message {
protected:
	int 	headersCount_;
	
	Header 	*Header_;
	Body 	*Body_;
public:
	Header *getHeader()			{ return Header_; };
	Body *getBody()				{ return Body_; };
};

//-----------------------------------------------------------------------------------------

// Реализация сообщения запроса и ответа

struct RequestMessage : public Message {
private:
	RequestLine *RequestLine_;
public:
	RequestMessage();
	
	RequestLine *getRequestLine()           { return RequestLine_; };
};

struct ResponseMessage : public Message {
private:
	ResponseLine *ResponseLine_;
public:
	ResponseMessage();
	
	ResponseLine *getResponseLine() { return ResponseLine_; };
};

#endif