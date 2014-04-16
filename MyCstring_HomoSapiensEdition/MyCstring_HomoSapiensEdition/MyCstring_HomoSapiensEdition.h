#ifdef MYCSTRING_HOMOSAPIENSEDITION_EXPORTS
#define MYCSTRING_API extern "C" __declspec(dllexport) 
#else
#define MYCSTRING_API extern "C" __declspec(dllimport) 
#endif

#include "string.h"

#define EOS 127


MYCSTRING_API size_t my_strlen(const char * str);

MYCSTRING_API char * my_strcpy(char * destination, const char * source);

MYCSTRING_API char * my_strncpy(char * destination, const char * source, size_t num);

MYCSTRING_API char * my_strcat(char * destination, const char * source);

MYCSTRING_API char * my_strncat(char * destination, const char * source, size_t num);

MYCSTRING_API int my_strcmp(const char * str1, const char * str2);

MYCSTRING_API int my_strncmp(const char * str1, const char * str2, size_t num);

MYCSTRING_API char * my_strchr(const char * str, int character);

MYCSTRING_API size_t my_strcspn(const char * str1, const char * str2);

MYCSTRING_API char * my_strpbrk(char * str1, const char * str2);

MYCSTRING_API char * my_strrchr(char * str, int character);

MYCSTRING_API size_t my_strspn(const char * str1, const char * str2);

MYCSTRING_API char * my_strstr(char * str1, const char * str2);

MYCSTRING_API char * my_strtok(char * str, const char * delimiters);

MYCSTRING_API char * getstr(void);

MYCSTRING_API size_t printstr(const char * str);

MYCSTRING_API char * StdstrToMystr(char* str);