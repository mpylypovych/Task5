// MyCstring.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include "MyCstring.h"

//#define EOS 0


size_t my_strlen(const char * str)
{
	char* p = (char*)str;
	while ((*p) != EOS)
	{
		++p;
	}
	return (size_t)((p - str) / sizeof(char));
}

char * my_strcpy(char * destination, const char * source)
{
	return (char*)memcpy(destination, source, strlen(source) + 1);
}

char * my_strncpy(char * destination, const char * source, size_t num)
{
	size_t len = strlen(source);
	memcpy(destination, source, len + 1);
	if (len<num)
	{
		memset(destination + len, EOS, num - len);
	}
	return destination;
}

char * my_strcat(char * destination, const char * source)
{
	size_t sourcelen = strlen(source);
	size_t destlen = strlen(destination);
	return (char*)memcpy(destination + destlen, source, sourcelen + 1);
}

char * my_strncat(char * destination, const char * source, size_t num)
{
	size_t sourcelen = strlen(source);
	if (sourcelen<num)
	{
		num = sourcelen;
	}
	size_t destlen = strlen(destination);
	*(destination + destlen + num + 1) = EOS;
	return (char*)memcpy(destination + destlen, source, num);
}

int my_strcmp(const char * str1, const char * str2)
{
	size_t it = 0;
	while ((*(str1 + it) != EOS) && (*(str2 + it) != EOS) && !(*(str1 + it) - *(str2 + it)))
	{
		++it;
	}
	return *(str1 + it) - *(str2 + it);
}

int my_strncmp(const char * str1, const char * str2, size_t num)
{
	--num;
	size_t it = 0;
	while ((*(str1 + it) != EOS) && (*(str2 + it) != EOS) && !(*(str1 + it) - *(str2 + it)) && (it<num))
	{
		++it;
	}
	return *(str1 + it) - *(str2 + it);
}

char * my_strchr(const char * str, int character)
{
	char chr = (char)character;
	char* ptr = (char*)str;
	char* end = (char*)str + strlen(str) + 1;
	while (((*ptr) != chr) && (ptr != end))
	{
		++ptr;
	}
	if (ptr == end)
	{
		ptr = NULL;
	}
	return ptr;
}

size_t my_strcspn(const char * str1, const char * str2)
{
	char* str1_it = (char*)str1;
	char* str2_it = (char*)str2;
	char* str1_end = str1_it + strlen(str1);
	char* str2_end = str2_it + strlen(str2);
	for (; str1_it < str1_end; ++str1_it)
	{
		for (str2_it = (char*)str2; str2_it < str2_end; ++str2_it)
		{
			if ((*str1_it) == (*str2_it))
			{
				return (size_t)(str1_it - str1) / sizeof(char);
			}
		}
	}
	return (size_t)(str1_it - str1) / sizeof(char);
}

char * my_strpbrk(char * str1, const char * str2)
{
	char* str1_it = str1;
	char* str2_it = (char*)str2;
	char* str1_end = str1_it + strlen(str1);
	char* str2_end = str2_it + strlen(str2);
	for (; str1_it < str1_end; ++str1_it)
	{
		for (str2_it = (char*)str2; str2_it < str2_end; ++str2_it)
		{
			if ((*str1_it) == (*str2_it))
			{
				return str1_it;
			}
		}
	}
	return NULL;
}

char * my_strrchr(char * str, int character)
{
	char chr = (char)character;
	char* ptr = (char*)str + strlen(str) + 1;
	while (((*ptr) != chr) && (ptr >= str))
	{
		--ptr;
	}
	if (ptr < str)
	{
		ptr = NULL;
	}
	return ptr;
}

size_t my_strspn(const char * str1, const char * str2)
{
	char* str1_it = (char*)str1;
	char* str2_it = (char*)str2;
	char* str1_end = str1_it + strlen(str1);
	char* str2_end = str2_it + strlen(str2);
	for (; str1_it < str1_end; ++str1_it)
	{
		for (str2_it = (char*)str2; ((str2_it < str2_end) && ((*str1_it) != (*str2_it))); ++str2_it)
		{
		}
		if (str2_it == str2_end)
		{
			return (size_t)(str1_it - str1) / sizeof(char);
		}
	}
	return (size_t)(str1_it - str1) / sizeof(char);
}

char * my_strstr(char * str1, const char * str2)
{
	char* str1_it = str1;
	char* str2_it = (char*)str2;
	size_t str2_len = strlen(str2);
	char* str1_end = str1_it + strlen(str1) - str2_len;
	char* str2_end = str2_it + strlen(str2);

	char boolean;
	for (; str1_it < str1_end; ++str1_it)
	{
		boolean = 1;
		for (str2_it = (char*)str2; str2_it < str2_end; ++str2_it)
		{
			if (*(str1_it + (unsigned)str2_it - (unsigned)str2) != *str2_it)
			{
				boolean = 0;
				break;
			}
		}
		if (boolean)
		{
			return str1_it;
		}

	}
	return NULL;
}

char * my_strtok(char * str, const char * delimiters)
{
	static char* str_it;
	static char* str_end;
	if (str)
	{
		str_it = str;
		str_end = str_it + strlen(str);
	}

	while (strchr(delimiters, *str_it) && (str_it < str_end))
	{
		++str_it;
	}

	char* temp = str_it;

	while (!strchr(delimiters, *str_it) && (str_it < str_end))
	{
		++str_it;
	}

	if (str_it == str_end)
	{
		temp = NULL;
	}
	else
	{
		*str_it = EOS;
		++str_it;
	}

	return temp;
}