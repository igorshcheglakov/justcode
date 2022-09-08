#ifndef LOG_H_
#define LOG_H_

#include <cstring>

#ifndef LOG_TAG
#define LOG_TAG nullptr
#endif

#ifndef __MODULE__
#define __MODULE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

class Logger
{
public:
	enum class LogLevel
	{
        	Debug,
        	Error,
        	Info,
        	Warn,
	};

public:
	virtual ~Logger() = default;

	static Logger &getInstance();

	virtual void log(LogLevel level, const char *tag, const char *fmt, ...) const = 0;

};

#define PRINT_LOG(level, fmt, args...) \
	do { \
		Logger::getInstance().log(level, LOG_TAG, "%s: %s(%d) > " fmt, __MODULE__, __FUNCTION__, __LINE__, ##args); \
	} while (0)

#define LOGD(fmt, args...) PRINT_LOG(LogLevel::Debug, fmt, ##args)
#define LOGE(fmt, args...) PRINT_LOG(LogLevel::Error, fmt, ##args)
#define LOGI(fmt, args...) PRINT_LOG(LogLevel::Info, fmt, ##args)
#define LOGW(fmt, args...) PRINT_LOG(LogLevel::Warn, fmt, ##args)

#endif // LOG_H_
