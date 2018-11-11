/*
класс используется для удобного хранения информации


*/

#include "include/DataStructures/Constants.hpp"
#include "include/DataStructures/Message.hpp"

//TODO паттерн builder

RequestMessage::RequestMessage() {
	RequestLine_ = new RequestLine();
	Header_ = new Header[1];
	Body_ = new Body();
	
	// Инициализация строки запроса
	RequestLine_->setType(MESSAGE_TYPE::REQUEST);
	RequestLine_->setHttpVersion(1.0);
	RequestLine_->setMethod(REQUEST_METHOD::GET);
	RequestLine_->setRequestTarget((char*)"127.0.0.1:735");

	// Инициализация заголовка
	Header_[0].setName((char*)"User-Agent");
	Header_[0].setValue((char*)"c++/MessageLib/0.1");
	
	// Инициализация тела сообщения
	Body_->setText(new char[0]);
}


ResponseMessage::ResponseMessage() {
	ResponseLine_ = new ResponseLine();
	Header_ = new Header[1];
	Body_ = new Body();
	
	
	// Инициализация строки запроса
	ResponseLine_->setType(MESSAGE_TYPE::REQUEST);
	ResponseLine_->setHttpVersion(1.0);
	ResponseLine_->setStatusCode(REQUEST_METHOD::GET);
	ResponseLine_->setReasonPhrase((char*)"OK");		//TODO const_cast

	// Инициализация заголовка
	Header_[0].setName((char*)"Server-Origin");
	Header_[0].setValue((char*)"c++/MessageLib/0.1");
	
	// Инициализация тела сообщения
	Body_->setText(new char[0]);
}