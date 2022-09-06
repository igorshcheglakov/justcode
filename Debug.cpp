#include <execinfo.h>

const int MAX_FRAMES = 32;

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
