#include <execinfo.h>
#include <string>
#include <sstream>
#include <string>

namespace Debug
{

const int MAX_FRAMES = 32;

std::string getBasename(const std::string &path)
{
	return path.substr(path.find_last_of("/") + 1);
}

void throwAssertException(const char *path, int line, const char *func, const char *expr)
{
	std::stringstream log;
	log << "Failed assertion: " << getBasename(path) << ": " << func << "(" << line << ") > " << expr << std::endl;
	throw std::runtime_error(log.str().c_str());
}

void printStackTrace()
{
	int n;
	void* buf[MAX_FRAMES];
	char** symbols;

	n = backtrace(buf, MAX_FRAMES);
	symbols = backtrace_symbols(buf, n);

	if (symbols)
	{
		for (int j = 0; j < n; ++j)
		{
			LOGD("%s", symbols[j]);
		}

		free(symbols);
	}
}

}
