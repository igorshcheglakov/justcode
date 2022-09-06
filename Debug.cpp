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

void hexdump(const unsigned char *buf, size_t len)
{
	size_t i, j;
	char c, str[17];

	str[16] = 0;

	for (i = 0; i < len; i++)
	{
		if ((i % 16 == 0) && (i != 0))
		{
			LOG("           ");
		}

		c = buf[i];
		str[i % 16] = (((c > 31) && (c < 127)) ? c : '.');
		LOG("%02x ", (unsigned char)c);

		if ((i % 4) == 3)
		{
			LOG(" ");
		}
		if ((i % 16) == 15)
		{
			LOG("%s\n",str);
		}
	}

	if ((i % 16) != 0)
	{
		for (j = i % 16; j < 16; j++)
		{
			LOG("   ");
			if ((j % 4) == 3)
			{
				LOG(" ");
			}
		}
		str[i % 16] = 0;
		LOG("%s\n",str);
	}
}

}
