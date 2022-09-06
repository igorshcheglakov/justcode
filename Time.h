#ifndef TIME_H_
#define TIME_H_

#include <string>

class Time
{
public:
	Time();
	Time(const Time& other);
	Time &operator=(const Time& other);

	Time &now();
	time_t get() const;
	time_t elapsed() const;
	std::string format(const std::string& fmt) const;

private:
	time_t m_time;

private:
	static const size_t FMT_BUFFER_SIZE;
};

#endif // TIME_H_
