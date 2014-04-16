// MyCstring_HomoSapiensEdition.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>

#include "MyCstring_HomoSapiensEdition.h"

#define ALLOC_STEP 20


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
	free(destination);

	destination = (char*)malloc(my_strlen(source)*sizeof(char));
	if (destination)
	{
		(char*)memcpy(destination, source, (my_strlen(source) + 1)*sizeof(char) );
	}
	return destination;
}

char * my_strncpy(char * destination, const char * source, size_t num)
{
	size_t destlen = my_strlen(destination);
	size_t sourcelen = my_strlen(source);
	if (num > destlen)
	{
		free(destination);
		destination = (char*)malloc((num + 1)*sizeof(char));
		if (!destination)
		{
			return NULL;
		}
		memcpy(destination, source, num*sizeof(char));
		*(destination+num) = EOS;
	}
	else
	{
		memcpy(destination, source, min(num,sourcelen)*sizeof(char));
		if (sourcelen<num)
		{
			memset(destination + sourcelen, EOS, num - sourcelen);
		}
	}

	return destination;
}

char * my_strcat(char * destination, const char * source)
{
	size_t sourcelen = my_strlen(source);
	size_t destlen = my_strlen(destination);
	
	char* temp = NULL;
	my_strcpy(temp,destination);
	
	free(destination);
	destination = (char*)malloc((sourcelen + destlen+1)*sizeof(char));
	if (destination)
	{
		memcpy(destination, temp, destlen);
		memcpy(destination + destlen, source, sourcelen + 1);
	}
	return destination;
}

char * my_strncat(char * destination, const char * source, size_t num)
{
	size_t sourcelen = my_strlen(source);
	if (sourcelen<num)
	{
		num = sourcelen;
	}
	size_t destlen = my_strlen(destination);

	char* temp = NULL;
	my_strcpy(temp, destination);

	free(destination);
	destination = (char*)malloc((destlen + num + 1)*sizeof(char));
	if (destination)
	{
		*(destination + destlen + num + 1) = EOS;
		(char*)memcpy(destination + destlen, source, num);
	}
	return destination;
}

int my_strcmp(const char * str1, const char * str2)
{
	size_t it = 0;
	while ((*(str1 + it) != EOS) && (*(str2 + it) != EOS) && !(*(str1 + it) - *(str2 + it)))
	{
		++it;
	}
	char res = 0;
	if ((*(str1 + it) == EOS) && (*(str2 + it) != EOS))
	{
		res = 1;
	}
	else if ((*(str1 + it) != EOS) && (*(str2 + it) == EOS))
	{
		res = -1;
	}
	else if ((*(str1 + it) != EOS) && (*(str2 + it) != EOS))
	{
		if (*(str1 + it) - *(str2 + it) > 0)
		{
			res = 1;
		}
		else
			res = -1;
	}
	return (int)res;
}

int my_strncmp(const char * str1, const char * str2, size_t num)
{
	--num;
	size_t it = 0;
	while ((*(str1 + it) != EOS) && (*(str2 + it) != EOS) && !(*(str1 + it) - *(str2 + it)) && (it<num))
	{
		++it;
	}
	char res = 0;
	if ((*(str1 + it) == EOS) && (*(str2 + it) != EOS))
	{
		res = 1;
	}
	else if ((*(str1 + it) != EOS) && (*(str2 + it) == EOS))
	{
		res = -1;
	}
	else if ((*(str1 + it) != EOS) && (*(str2 + it) != EOS))
	{
		if (*(str1 + it) - *(str2 + it) > 0)
		{
			res = 1;
		}
		else
			res = -1;
	}
	return (int)res;
}

char * my_strchr(const char * str, char character)
{
	char* end = (char*)str + my_strlen(str);
	while (((*str) != character) && (str != end))
	{
		++str;
	}
	if (str == end)
	{
		str = NULL;
	}
	return (char*)str;
}

size_t my_strcspn(const char * str1, const char * str2)
{
	char* str1_it = (char*)str1;
	char* str2_it = (char*)str2;
	char* str1_end = str1_it + my_strlen(str1);
	char* str2_end = str2_it + my_strlen(str2);
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
	char* str2_it = (char*)str2;
	char* str1_end = str1 + my_strlen(str1);
	char* str2_end = str2_it + my_strlen(str2);
	for (; str1 < str1_end; ++str1)
	{
		for (str2_it = (char*)str2; str2_it < str2_end; ++str2_it)
		{
			if ((*str1) == (*str2_it))
			{
				return str1;
			}
		}
	}
	return NULL;
}

char * my_strrchr(char * str, char character)
{
	char* ptr = (char*)str + my_strlen(str) + 1;
	while (((*ptr) != character) && (ptr >= str))
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
	char* str1_end = str1_it + my_strlen(str1);
	char* str2_end = str2_it + my_strlen(str2);
	for (; str1_it < str1_end; ++str1_it)
	{
		for (str2_it = (char*)str2; (str2_it < str2_end) && ((*str1_it) != (*str2_it)); ++str2_it)
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
	char* str2_it = (char*)str2;
	size_t str2_len = my_strlen(str2);
	char* str1_end = str1 + my_strlen(str1) - str2_len;
	char* str2_end = str2_it + my_strlen(str2);

	char boolean;
	for (; str1 < str1_end; ++str1)
	{
		boolean = 1;
		for (str2_it = (char*)str2; str2_it < str2_end; ++str2_it)
		{
			if (*(str1 + (unsigned)str2_it - (unsigned)str2) != *str2_it)
			{
				boolean = 0;
				break;
			}
		}
		if (boolean)
		{
			return str1;
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
		str_end = str_it + my_strlen(str);
	}

	while (strchr(delimiters, *str_it) && (str_it < str_end))
	{
		++str_it;
	}
	if (str_it < str_end)
	{
		char* temp = str_it;

		while (!strchr(delimiters, *str_it) && (str_it < str_end))
		{
			++str_it;
		}

		*str_it = EOS;
		++str_it;

		return temp;
	}
	else
	{
		return NULL;
	}
}

char * getstr(void)
{
	size_t length = ALLOC_STEP;
	char * str = (char*)malloc(length);
	size_t i = 0;
	*(str + i) = getchar();
	while (*(str + i) != '\n')
	{
		++i;
		if (i >= length)
		{
			length += ALLOC_STEP;
			str = (char*)realloc(str, length);
		}
		*(str + i) = getchar();
	}
	*(str + i) = EOS;
	return str;
}

size_t printstr(const char * str)
{
	size_t i = 0;
	while (*(str + i) != EOS)
	{
		putchar(*(str + i));
		++i;
	}
	return i;
}

char * StdstrToMystr(char* str)
{
	size_t len = 0;
	while ((*str) != '\0')
	{
		++str;
		++len;
	}
	char* temp = (char*)malloc( (len+1)*sizeof(char));
	return temp;
}