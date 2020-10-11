#include "OurException.h"
#include <sstream>

OurException::OurException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* OurException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* OurException::GetType() const noexcept
{
	return "Our Exception";
}

int OurException::GetLine() const noexcept
{
	return line;
}

const std::string& OurException::GetFile() const noexcept
{
	return file;
}

std::string OurException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl
		<< "[Line]" << line;
	return oss.str();
}
