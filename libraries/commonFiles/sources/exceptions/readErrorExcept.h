#ifndef BOB_THE_BLOB_COMMON_FILES_READ_ERROR_EXCEPT_H
#define BOB_THE_BLOB_COMMON_FILES_READ_ERROR_EXCEPT_H

#include <stdexcept>
#include <string>

class ReadError : public std::runtime_error
{
public:
	ReadError(const std::string& whatArg);
	~ReadError() = default;
};

#endif //BOB_THE_BLOB_COMMON_FILES_READ_ERROR_EXCEPT_H