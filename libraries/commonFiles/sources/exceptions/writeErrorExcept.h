#ifndef BOB_THE_BLOB_COMMON_FILES_WRITE_ERROR_EXCEPT_H
#define BOB_THE_BLOB_COMMON_FILES_WRITE_ERROR_EXCEPT_H

#include <stdexcept>
#include <string>

class WriteError : public std::runtime_error
{
public:
	WriteError(const std::string& whatArg);
	~WriteError() = default;
};

#endif //BOB_THE_BLOB_COMMON_FILES_WRITE_ERROR_EXCEPT_H