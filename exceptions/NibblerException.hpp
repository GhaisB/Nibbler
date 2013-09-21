#ifndef 				__NIBBLER_EXCEPTION_HPP__
#define 				__NIBBLER_EXCEPTION_HPP__

#include 				<exception>
#include 				<string>

class 					NibblerException : public std::exception
{
private:
	const std::string 	_message;

public:
	virtual ~NibblerException() throw() {};
	
	NibblerException(const std::string &message) throw() : _message(message) {};

	virtual const char* what() const throw() {
		return this->_message.c_str();
	}

};

#endif
