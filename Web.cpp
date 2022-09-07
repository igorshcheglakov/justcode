#include "Web.h"

#include <curl/curl.h>

const int CURL_CONNECTION_TIMEOUT = 5;

size_t writeCb(char* ptr, size_t size, size_t nmemb, void* data)
{
	std::string* s = reinterpret_cast<std::string*>(data);
	for (size_t i = 0; i < size * nmemb; i++)
	{
		s->push_back(ptr[i]);
	}

	return size * nmemb;
}

std::string getFromURL(const std::string& url)
{
	std::string result;

	curl_global_init(CURL_GLOBAL_ALL);
	CURL* curl = curl_easy_init();
	i
	if (!curl)
	{
		LOGE("Failed to initialize CURL");
		curl_global_cleanup();
		return result;
	}

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCb);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, CURL_CONNECTION_TIMEOUT);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);

	CURLcode error = curl_easy_perform(curl);
	if (error != CURLE_OK)
	{
		LOGE("%s", curl_easy_strerror(error));
	}

	curl_easy_cleanup(curl);
	curl_global_cleanup();

	return result;
}
