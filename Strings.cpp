#include "Strings.h"

std::string substitute(const std::string& text, const std::map<std::string, std::string> &converter)
{
	std::string result;

	for (size_t i = 0; i < text.size();)
	{
		bool flag = false;

		for (auto it = converter.cbegin(); it != converter.cend(); ++it)
		{
			std::string key = it->first;
			std::string value = it->second;

			if (i + key.size() <= text.size())
			{
				if (text.substr(i, key.size()) == key)
				{
					result += value;
					i += key.size();
					matched = true;
					break;
				}
			}
		}

		if (!flag)
		{
			result += text[i];
			i++;
		}
	}

	return result;
}
