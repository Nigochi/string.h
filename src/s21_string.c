#include "s21_string.h"

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int i = 0;
  bool flag = true;
  char const *tmp_str = str;
  for (; i < (int)n; i++) {
    if (*(tmp_str)-c == 0) {
      flag = false;
      break;
    }
    tmp_str++;
  }
  return (!flag) ? (void *)tmp_str : S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char const *tmp_str1 = str1;
  char const *tmp_str2 = str2;
  int to_return = 0;
  for (; n > 0; n--) {
    if (*tmp_str1 != *tmp_str2) {
      to_return = *tmp_str1 - *tmp_str2;
      break;
    }
    tmp_str1++;
    tmp_str2++;
  }
  return to_return;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *tmp_dest = dest;
  char const *tmp_src = src;
  for (int i = 0; i < (int)n; i++) {
    tmp_dest[i] = tmp_src[i];
  }
  return tmp_dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *tmp_dest = dest;
  char const *tmp_src = src;
  if (tmp_dest > tmp_src) {
    for (; n != 0; n--) {
      *(tmp_dest + n - 1) = *(tmp_src + n - 1);
    }
  } else {
    for (; n != 0; n--) {
      *tmp_dest = *tmp_src;
      tmp_dest++;
      tmp_src++;
    }
  }
  return tmp_dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *str_ptr = (char *)str;
  char chr = c;
  for (; n != 0; ++str_ptr, --n) {
    *str_ptr = chr;
  }
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t len = s21_strlen(dest);
  s21_size_t i = 0 + len;
  for (; i < s21_strlen(src) + len; i++) {
    (*((char *)dest + i)) = (*((char *)src + i - len));
  }
  (*((char *)dest + i)) = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t len = s21_strlen(dest);
  s21_size_t i = 0 + len;
  for (; i < s21_strlen(src) + len && i - len < n; i++) {
    (*((char *)dest + i)) = (*((char *)src + i - len));
  }
  (*((char *)dest + i)) = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  while (*str) {
    if (*str == c) {
      result = (char *)str;
      break;
    }
    str++;
  }
  if (*str == c) {
    result = (char *)str;
  }
  return result;
}

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (; n > 0; str1++, str2++, n--) {
    if (*str1 != *str2 || !(*str1 && *str2)) {
      return *str1 - *str2;
    }
  }
  return 0;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t len = s21_strlen(src);
  return s21_memcpy(dest, src, len + 1);
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  if (src) i = 0;
  for (; src[i] != '\0' && n; i++, n--) {
    dest[i] = src[i];
  }
  while (n--) dest[i++] = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  for (; *str1 != '\0' && s21_strchr(str2, *str1) == S21_NULL; str1++, count++)
    ;
  return count;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  if (str != S21_NULL) {
    while (str[i] != '\0') {
      i++;
    }
  }
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  for (; *str1 != '\0'; str1++) {
    if (s21_strchr(str2, *str1)) return (char *)str1;
  }
  return S21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  unsigned char chr = c;
  if (!chr) return (char *)str + s21_strlen(str);
  char *ptr = (char *)str + s21_strlen(str);
  do {
    if (*ptr == chr) return ptr;
    ptr -= 1;
  } while (ptr > str);
  return S21_NULL;
}

int is_str1_in_str2(const char str1, const char *str2) {
  int flag = 0;
  for (int i = 0; flag != 1 && str2[i] != '\0'; i++) {
    if (str1 == str2[i]) {
      flag = 1;
    }
  }
  return flag;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int res = -1;
  for (int i = 0; haystack[i] != '\0' && res == -1; i++) {
    int flag = 1;
    for (int j = 0; needle[j] != '\0' && flag == 1; j++) {
      if (!(needle[j] == haystack[i + j] && haystack[i + j] != '\0')) {
        flag = 0;
      }
    }
    if (flag == 1) {
      res = i;
    }
  }
  return (res == -1) ? S21_NULL : (char *)&haystack[res];
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  for (int i = 0; is_str1_in_str2(str1[i], str2) == 1 && str1[i] != '\0';
       res++, i++)
    ;
  return res;
}

int is_delim_in_str(char str, const char *delim) {
  int res = 0;
  for (int i = 0; delim[i] != '\0'; i++) {
    if (str == delim[i]) {
      res = 1;
      break;
    }
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  int flag = 1;
  static char *res = S21_NULL;
  if (str != S21_NULL) {
    res = str;
  } else {
    str = res;
  }
  for (int i = 0;; i++) {
    if (str[i] == '\0') {
      if (i == 0) {
        flag = 0;
        break;
      } else {
        res = &str[i];
        break;
      }
    }
    if (is_delim_in_str(str[i], delim) && flag == 1) {
      str[i] = '\0';
      res = &str[i + 1];
      if (i == 0) {
        i = i - 1;
        str = &str[1];
      } else {
        break;
      }
    }
  }
  return (flag) ? str : S21_NULL;
}
