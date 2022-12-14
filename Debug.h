#ifndef DEBUG_H_ 
#define DEBUG_H_

#define ASSERT(expr) do { if (!(expr)) Debug::throwAssertException(__FILE__, __LINE__, __PRETTY_FUNCTION__, #expr); } while (0)

namespace Debug
{
	void throwAssertException(const char*, int, const char*, const char *);
	void hexdump(const unsigned char *buf, size_t len);
};

#endif // DEBUG_H_
