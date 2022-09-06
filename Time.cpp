#include "Time.h"

#include <sys/time.h>

#include <cstring>

const size_t Time::FMT_BUFFER_SIZE = 32;

Time::Time()
	: m_time(0)
{
}

Time::Time(const Time &other)
{
	m_time = other.m_time;
}

Time &Time::operator=(const Time &other)
{
	if (this != &other)
	{
		m_time = other.m_time;
	}

	return *this;
}

Time &Time::now()
{
	m_time = time(nullptr);
	return *this;
}

time_t Time::get() const
{
	return m_time;
}

time_t Time::elapsed() const
{
	return time(nullptr) - m_time;
}

std::string Time::format(const std::string &fmt) const
{
	struct tm localtime;
	memset(&localtime, 0, sizeof(localtime));
	localtime_r(&m_time, &localtime);

	std::string timeStr;
	timeStr.resize(FMT_BUFFER_SIZE);
	size_t n = strftime(&timeStr[0], FMT_BUFFER_SIZE, fmt.c_str(), &localtime);
	timeStr.resize(n);

	return timeStr;
}
