#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

#define IS_LOWER(c) ((c) >= 97 && (c) <= 122)
#define IS_UPPER(c) ((c) >= 65 && (c) <= 90)

void *s21_to_upper(const char *str) {
  if (!str) {
    return S21_NULL;
  }
  char *upper_str = malloc((s21_strlen(str) + 1) * sizeof(char));
  if (!upper_str) {
    return S21_NULL;
  }
  for (char *upper_ptr = upper_str;; ++str, ++upper_ptr) {
    *upper_ptr = IS_LOWER(*str) ? *str - 32 : *str;
    if (!*str) {
      break;
    }
  }
  return upper_str;
}

void *s21_to_lower(const char *str) {
  if (!str) {
    return S21_NULL;
  }
  char *lower_str = malloc((s21_strlen(str) + 1) * sizeof(char));
  if (!lower_str) {
    return S21_NULL;
  }
  for (char *lower_ptr = lower_str;; ++str, ++lower_ptr) {
    *lower_ptr = IS_UPPER(*str) ? *str + 32 : *str;
    if (!*str) {
      break;
    }
  }
  return lower_str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!str || !src) {
    return S21_NULL;
  }
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);
  if (start_index > len_src) {
    return S21_NULL;
  }
  char *n_src = malloc((len_src + len_str + 1) * sizeof(char));
  if (!n_src) {
    return S21_NULL;
  }
  s21_strcpy(n_src, src);
  s21_memmove(n_src + start_index + len_str, n_src + start_index,
              len_src - start_index + 1);
  s21_memcpy(n_src + start_index, str, len_str);
  return n_src;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (!src) {
    return S21_NULL;
  }
  s21_size_t len_src = s21_strlen(src);
  char *n_src = malloc((len_src + 1) * sizeof(char));
  if (!n_src) {
    return S21_NULL;
  }
  if (*src) {
    s21_size_t begin = 0;
    s21_size_t end = 0;
    if (trim_chars == S21_NULL || *trim_chars == '\0') {
      free(n_src);
      return s21_trim(src, " \n\t");
    }
    for (; begin < len_src; ++begin) {
      if (!s21_strchr(trim_chars, src[begin])) {
        break;
      }
    }
    end = len_src - 1;
    for (;; --end) {
      if (!s21_strchr(trim_chars, src[end]) || !end) {
        break;
      }
    }
    if (end > begin) {
      for (s21_size_t i = begin; i <= end; ++i) {
        n_src[i - begin] = src[i];
      }
      n_src[end - begin + 1] = '\0';
    } else {
      n_src[0] = '\0';
    }
  } else {
    *n_src = '\0';
  }
  return (void *)n_src;
}
