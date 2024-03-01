#define _GNU_SOURCE
#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_strerror.h"
#include "../s21_string.h"

START_TEST(s21_memchr_test) {
  char str[9] = "test line";
  char in_str = 'e';
  char not_in_str = 'f';
  s21_size_t n = 7;

  ck_assert_ptr_eq(memchr(str, in_str, n), s21_memchr(str, in_str, n));
  ck_assert_ptr_eq(memchr(str, not_in_str, n), s21_memchr(str, not_in_str, n));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char str1[9] = "test line";
  char str2[17] = "another test line";
  char str3[9] = "test line";
  s21_size_t n1 = 5;
  s21_size_t n2 = 9;

  ck_assert_int_eq(memcmp(str1, str2, n1), s21_memcmp(str1, str2, n1));
  ck_assert_int_eq(memcmp(str1, str2, n2), s21_memcmp(str1, str2, n2));
  ck_assert_int_eq(memcmp(str1, str3, n1), s21_memcmp(str1, str3, n1));
  ck_assert_int_eq(memcmp(str2, str3, n2), s21_memcmp(str2, str3, n2));
  ck_assert_int_eq(memcmp(str1, str3, n2), s21_memcmp(str1, str3, n2));
  ck_assert_int_eq(memcmp(str2, str3, n1), s21_memcmp(str2, str3, n1));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char str1[50] = "test line";
  char str2[50] = "another test line";
  char s21_str1[50] = "test line";
  char s21_str2[50] = "another test line";
  s21_size_t n1 = 9;
  s21_size_t n2 = 17;

  memcpy(str1, str2, n1);
  s21_memcpy(s21_str1, s21_str2, n1);
  ck_assert_str_eq(str1, s21_str1);

  memcpy(str1, str2, n2);
  s21_memcpy(s21_str1, s21_str2, n2);
  ck_assert_str_eq(str1, s21_str1);
}
END_TEST

START_TEST(s21_memmove_test) {
  char str[20] = "123456789";
  char s21_str[20] = "123456789";
  s21_size_t n1 = 5;
  s21_size_t n2 = 8;

  memmove(&str[3], &str[2], n1);
  s21_memmove(&s21_str[3], &s21_str[2], n1);
  ck_assert_str_eq(str, s21_str);

  memmove(&str[5], &str[3], n2);
  s21_memmove(&s21_str[5], &s21_str[3], n2);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_memset_test) {
  char str[50] = "just another test line";
  char s21_str[50] = "just another test line";
  char c1 = 'f';
  char c2 = '8';
  s21_size_t n1 = 5;
  s21_size_t n2 = 8;

  memset(str, c1, n1);
  s21_memset(s21_str, c1, n1);
  ck_assert_str_eq(str, s21_str);

  memset(str, c2, n2);
  s21_memset(s21_str, c2, n2);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(s21_strcat_test) {
  char str[10] = "test line";
  char empty_str[1] = "";
  char str1[10] = "";
  char s21_str1[10] = "";
  char str2[20] = "not empty";
  char s21_str2[20] = "not empty";
  char str3[10] = "";
  char s21_str3[10] = "";

  strcat(str1, str);
  s21_strcat(s21_str1, str);
  strcat(str2, str);
  s21_strcat(s21_str2, str);
  strcat(str3, empty_str);
  s21_strcat(s21_str3, empty_str);

  ck_assert_str_eq(str1, s21_str1);
  ck_assert_str_eq(str2, s21_str2);
  ck_assert_str_eq(str3, s21_str3);
}
END_TEST

START_TEST(s21_strncat_test) {
  char str[20] = "i'd like to eat sth";
  char empty_str[1] = "";
  char str1[10] = "";
  char s21_str1[10] = "";
  char str2[20] = "no food :(";
  char s21_str2[20] = "no food :(";
  char str3[10] = "";
  char s21_str3[10] = "";
  s21_size_t n = 8;

  strncat(str1, str, n);
  s21_strncat(s21_str1, str, n);
  ck_assert_str_eq(str1, s21_str1);

  strncat(str2, str, n);
  s21_strncat(s21_str2, str, n);
  ck_assert_str_eq(str2, s21_str2);

  strncat(str3, empty_str, n);
  s21_strncat(s21_str3, empty_str, n);
  ck_assert_str_eq(str3, s21_str3);
}
END_TEST

START_TEST(s21_strchr_test) {
  char str[10] = "test line";
  int to_find = 'n';

  ck_assert_ptr_eq(strchr(str, to_find), s21_strchr(str, to_find));
  ck_assert_ptr_eq(strchr(str, to_find), s21_strchr(str, to_find));
}
END_TEST

START_TEST(s21_strcmp_test) {
  char str1[50] = "the best test";
  char str2[50] = "the best test";
  char str3[50] = "the best test ever";
  char empty_str[1] = "";

  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
  ck_assert_int_eq(strcmp(str3, str2), s21_strcmp(str3, str2));
  ck_assert_int_eq(strcmp(str1, empty_str), s21_strcmp(str1, empty_str));
  ck_assert_int_eq(strcmp(empty_str, str3), s21_strcmp(empty_str, str3));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[50] = "place for love";
  char str2[50] = "place for test";
  char str3[50] = "place for love and test";
  char empty_str[1] = "";
  s21_size_t n1 = 9;
  s21_size_t n2 = 14;

  ck_assert_int_eq(strncmp(str1, str2, n1), s21_strncmp(str1, str2, n1));
  ck_assert_int_eq(strncmp(str3, str2, n1), s21_strncmp(str3, str2, n1));
  ck_assert_int_eq(strncmp(str1, empty_str, n1),
                   s21_strncmp(str1, empty_str, n1));
  ck_assert_int_eq(strncmp(empty_str, str3, n1),
                   s21_strncmp(empty_str, str3, n1));
  ck_assert_int_eq(strncmp(str1, str2, n2), s21_strncmp(str1, str2, n2));
  ck_assert_int_eq(strncmp(str3, str2, n2), s21_strncmp(str3, str2, n2));
  ck_assert_int_eq(strncmp(str1, empty_str, n2),
                   s21_strncmp(str1, empty_str, n2));
  ck_assert_int_eq(strncmp(empty_str, str3, n2),
                   s21_strncmp(empty_str, str3, n2));
}
END_TEST

START_TEST(s21_strcpy_test) {
  char str[50] = "im empty";
  char str1[50] = "im empty second";
  char str2[50] = "the best cpy test";
  char s21_str[50] = "im empty";
  char s21_str1[50] = "im empty second";
  char s21_str2[50] = "the best cpy test";
  char empty_line[1] = "";

  strcpy(str, str2);
  s21_strcpy(s21_str, s21_str2);
  ck_assert_str_eq(str, s21_str);

  strcpy(str1, str2);
  s21_strcpy(s21_str1, s21_str2);
  ck_assert_str_eq(str1, s21_str1);

  strcpy(str1, empty_line);
  s21_strcpy(s21_str1, empty_line);
  ck_assert_str_eq(str1, s21_str1);
}
END_TEST

START_TEST(s21_strncpy_test) {
  char str[50] = "hello";
  char str1[50] = "how're u";
  char str2[50] = "i will be cloned";
  char s21_str[50] = "hello";
  char s21_str1[50] = "how're u";
  char s21_str2[50] = "i will be cloned";
  char empty_line[1] = "";
  s21_size_t n = 10;
  s21_size_t n1 = 5;

  strncpy(str, str2, n);
  s21_strncpy(s21_str, s21_str2, n);
  ck_assert_str_eq(str, s21_str);

  strncpy(str1, str2, n1);
  s21_strncpy(s21_str1, s21_str2, n1);
  ck_assert_str_eq(str1, s21_str1);

  strncpy(str1, empty_line, n1);
  s21_strncpy(s21_str1, empty_line, n1);
  ck_assert_str_eq(str1, s21_str1);
}
END_TEST

START_TEST(s21_strcspn_test) {
  char str[50] = "test line";
  char empty_str[1] = "";
  char to_find[10] = "es";

  ck_assert_int_eq(strcspn(str, to_find), s21_strcspn(str, to_find));
  ck_assert_int_eq(strcspn(str, empty_str), s21_strcspn(str, empty_str));
  ck_assert_int_eq(strcspn(empty_str, to_find),
                   s21_strcspn(empty_str, to_find));
}
END_TEST

START_TEST(s21_strerror_test) {
  int errno = -1;
  int errmax = 150;
  while (errno < errmax) {
    ck_assert_str_eq(s21_strerror(errno), strerror(errno));
    errno++;
  }
  for (int i = 0; i < ERRMAX + 1; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(s21_strlen_test) {
  char str[10] = "test line";
  char empty_str[1] = "";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
  ck_assert_int_eq(strlen(empty_str), s21_strlen(empty_str));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str[10] = "test line";
  char empty_str[1] = "";
  char to_find[10] = "tes";

  ck_assert_ptr_eq(strpbrk(str, to_find), s21_strpbrk(str, to_find));
  ck_assert_ptr_eq(strpbrk(str, empty_str), s21_strpbrk(str, empty_str));
  ck_assert_ptr_eq(strpbrk(empty_str, to_find),
                   s21_strpbrk(empty_str, to_find));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char str[] = "char *strrchr(const char *str, int c)";
  int in_str = 'c';
  int not_in_str = 'w';
  ck_assert_ptr_eq(strrchr(str, in_str), s21_strrchr(str, in_str));
  ck_assert_ptr_eq(strrchr(str, not_in_str), s21_strrchr(str, not_in_str));

  char str_null[1];
  ck_assert_ptr_eq(strrchr(str_null, in_str), s21_strrchr(str_null, in_str));
}
END_TEST

START_TEST(s21_strspn_test) {
  char str2[] = "char *strrchr(const char *str, int c)";
  char str1[] = "char *strrchr(const char *str, int c)";

  ck_assert_int_eq((int)strspn(str1, str2), (int)s21_strspn(str1, str2));

  char str2_1[] = "c r*ha";
  ck_assert_int_eq((int)strspn(str1, str2_1), (int)s21_strspn(str1, str2_1));

  char str_null[1];
  ck_assert_int_eq((int)strspn(str_null, str2),
                   (int)s21_strspn(str_null, str2));
  ck_assert_int_eq((int)strspn(str1, str_null),
                   (int)s21_strspn(str1, str_null));
}
END_TEST

START_TEST(s21_strstr_test) {
  char str2[] = "char *strrchr(const char *str, int c)";
  char str1[] = "har *";

  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));

  char str2_1[] = " c)l";
  ck_assert_ptr_eq(strstr(str1, str2_1), s21_strstr(str1, str2_1));

  char str_null[1];
  ck_assert_ptr_eq(strstr(str_null, str2), s21_strstr(str_null, str2));
  ck_assert_ptr_eq(strstr(str1, str_null), s21_strstr(str1, str_null));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str1[] = ".test1/test2///te..st3/test4",
       str2[] = ".test1/test2///te..st3/test4";
  char sep1[] = "/.";
  char *istr1, *istr2;

  istr1 = strtok(str1, sep1);
  istr2 = s21_strtok(str2, sep1);
  ck_assert_pstr_eq(istr1, istr2);

  while (istr2 != NULL || istr1 != NULL) {
    ck_assert_pstr_eq(istr1, istr2);
    istr1 = strtok(NULL, sep1);
    istr2 = s21_strtok(S21_NULL, sep1);
  }
}
END_TEST

START_TEST(s21_to_upper_test) {
  char str[100] = "azhello112+__2f";
  char upper_str[100] = "AZHELLO112+__2F";
  char *res = (char *)s21_to_upper(str);
  ck_assert_str_eq(res, upper_str);
  free(res);

  char str2[100] = "azHello112+__2f";
  char upper_str2[100] = "AZHELLO112+__2F";
  res = (char *)s21_to_upper(str2);
  ck_assert_str_eq(res, upper_str2);
  free(res);

  res = (char *)s21_to_upper(NULL);
  ck_assert_pstr_eq(res, S21_NULL);
  free(res);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str[100] = "aZHELLO112+__2F";
  char lower_str[100] = "azhello112+__2f";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, lower_str);
  free(res);
}
END_TEST

START_TEST(s21_insert_test) {
  char src[100] = "Hello !";
  char str[100] = "World";
  s21_insert(src, str, 10);
  ck_assert_str_eq(src, "Hello !");
  char *res = s21_insert(src, str, 6);
  ck_assert_str_eq(res, "Hello World!");
  s21_insert(src, NULL, 10);
  s21_insert(NULL, str, 10);
  free(res);
}
END_TEST

START_TEST(s21_trim_test) {
  char src[100] = "  ,.,. trimmed ,., line ., ,";
  char src2[100] = "";
  char trim[100] = " .,";
  char trim3[100] = "";
  char *res = s21_trim(src, trim);
  char *res2 = s21_trim(src2, trim);
  char *res3 = s21_trim(src, NULL);
  char *res4 = s21_trim(src, trim3);
  char *res5 = s21_trim(NULL, trim3);
  char *res6 = s21_trim("aaaaaaaa", "aa");
  ck_assert_str_eq(res, "trimmed ,., line");
  ck_assert_str_eq(res2, "");
  ck_assert_str_eq(res3, ",.,. trimmed ,., line ., ,");
  ck_assert_str_eq(res4, ",.,. trimmed ,., line ., ,");
  ck_assert_pstr_eq(res5, S21_NULL);
  ck_assert_str_eq(res6, "");
  free(res);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
}
END_TEST

START_TEST(s21_sprintf_empty_format) {
  char str1[100] = {0};
  char str2[100] = {0};

  // ck_assert_int_eq(s21_sprintf(str1, ""), sprintf(str2, ""));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_max_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = INT_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%d", s21_int),
                   sprintf(str2, "%d", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_min_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = INT_MIN;
  ck_assert_int_eq(s21_sprintf(str1, "%d", s21_int),
                   sprintf(str2, "%d", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = 123;
  ck_assert_int_eq(s21_sprintf(str1, "%d", s21_int),
                   sprintf(str2, "%d", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = -123;
  ck_assert_int_eq(s21_sprintf(str1, "%d", s21_int),
                   sprintf(str2, "%d", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  ck_assert_int_eq(s21_sprintf(str1, "%.6d", s21_int),
                   sprintf(str2, "%.6d", s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  ck_assert_int_eq(s21_sprintf(str1, "%.6d", s21_int),
                   sprintf(str2, "%.6d", s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  ck_assert_int_eq(s21_sprintf(str1, "%.2d", s21_int),
                   sprintf(str2, "%.2d", s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  ck_assert_int_eq(s21_sprintf(str1, "%.2d", s21_int),
                   sprintf(str2, "%.2d", s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%9.6d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  char format[] = "%1.6d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%-9.6d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  char format[] = "%-1.6d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%09d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_force_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "% d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_wight_var) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "% *d";
  ck_assert_int_eq(s21_sprintf(str1, format, 6, s21_int),
                   sprintf(str2, format, 6, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_spec_var) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "% .*d";
  ck_assert_int_eq(s21_sprintf(str1, format, 6, s21_int),
                   sprintf(str2, format, 6, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_short) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = 123578;
  ck_assert_int_eq(s21_sprintf(str1, "%hd", s21_int),
                   sprintf(str2, "%hd", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_short_max) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = SHRT_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%hd", s21_int),
                   sprintf(str2, "%hd", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_short_min) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = SHRT_MAX + 1;
  ck_assert_int_eq(s21_sprintf(str1, "%hd", s21_int),
                   sprintf(str2, "%hd", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};
  long int s21_int = 87878123578;
  ck_assert_int_eq(s21_sprintf(str1, "%ld", s21_int),
                   sprintf(str2, "%ld", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_long_max) {
  char str1[100] = {0};
  char str2[100] = {0};
  long int s21_int = LONG_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%ld", s21_int),
                   sprintf(str2, "%ld", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = 123;
  char format[] = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = UINT_MAX;
  char format[] = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_long_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned long int s21_int = ULONG_MAX - 1;
  char format[] = "%lu";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_short_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned short int s21_int = USHRT_MAX;
  char format[] = "%hu";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = -123;
  char format[] = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = 123;
  char format[] = "%.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = -123;
  char format[] = "%.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = 123;
  char format[] = "%.2u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = -123;
  char format[] = "%.2u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%1.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  char format[] = "%1.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%-9.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%-9.6u";
  int s21_int = -123;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%09u";
  int s21_int = 123;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(s21_sprintf_f_plus) {
//   char str1[100] = {0};
//   char str2[100] = {0};

//   float s21_int = 123.157;
//   char format[] = "%f";
//   ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
//                    sprintf(str2, format, s21_int));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(s21_sprintf_f_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%f";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.9f";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.9f";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.f";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2f";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10f";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%Lf";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(s21_sprintf_comb) {
//   char str1[100] = {0};
//   char str2[100] = {0};
//   float s21_f = 123.157;
//   int s21_int = 123;
//   char format[] = "%+10f %d";
//   ck_assert_int_eq(s21_sprintf(str1, format, s21_f, s21_int),
//                    sprintf(str2, format, s21_f, s21_int));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(s21_sprintf_c) {
  char str1[100] = {0};
  char str2[100] = {0};

  char s21_int = 'v';
  char format[] = "%c";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_s) {
  char str1[100] = {0};
  char str2[100] = {0};

  char s21_int[] = "1578";
  char format[] = "%s";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_s_prec) {
  char str1[100] = {0};
  char str2[100] = {0};

  char s21_int[] = "1578";
  char format[] = "%.2s";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.7e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.7e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.;
  char format[] = "%#e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%Le";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.7E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.7E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.;
  char format[] = "%#E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%LE";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
  s21_int = -0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.7g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;

  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.7g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
  s21_int = -0.000157;

  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  // s21_int = 0.000157;

  // ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
  //                  sprintf(str2, format, s21_int));
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  // s21_int = 0.000157;

  // ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
  //                  sprintf(str2, format, s21_int));
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.0000157;

  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%#.10g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  // s21_int = 0.000157;
  // ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
  //                  sprintf(str2, format, s21_int));
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%Lg";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
  s21_int = -0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.7G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;

  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.7G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
  s21_int = -0.000157;

  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  // s21_int = 0.000157;

  // ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
  //                  sprintf(str2, format, s21_int));
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  // s21_int = 0.000157;

  // ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
  //                  sprintf(str2, format, s21_int));
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.0000157;

  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%#.10G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  // s21_int = 0.000157;
  // ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
  //                  sprintf(str2, format, s21_int));
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_G_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%LG";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = UINT_MAX;
  char format[] = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_o_shrt_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = USHRT_MAX;
  char format[] = "%ho";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_o_long_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  long int s21_int = ULONG_MAX;
  char format[] = "%lo";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = UINT_MAX;
  char format[] = "%x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_x_shrt_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = USHRT_MAX;
  char format[] = "%hx";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_x_long_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  long int s21_int = ULONG_MAX;
  char format[] = "%lx";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_X_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = UINT_MAX;
  char format[] = "%X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_X_shrt_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = USHRT_MAX;
  char format[] = "%hX";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_X_long_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  long int s21_int = ULONG_MAX;
  char format[] = "%lX";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.2o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.2o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%1.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%1.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%-9.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%-9.6o";
  int s21_int = -193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%09o";
  int s21_int = 193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%#o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.2x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.2x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%1.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%1.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%-9.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%-9.6x";
  int s21_int = -193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%09x";
  int s21_int = 193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%#x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.2X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.2X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%1.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%1.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%-9.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%-9.6X";
  int s21_int = -193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%09X";
  int s21_int = 193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%#X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_p) {
  char str1[100] = {0};
  char str2[100] = {0};

  char *s21_int = str1;
  char format[] = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(s21_sprintf_p_wight) {
//   char str1[100] = {0};
//   char str2[100] = {0};

//   char *s21_int = str1;
//   char format[] = "%24p";
//   int res = s21_sprintf(str1, format, s21_int);
//   int res_orig = sprintf(str1, format, s21_int);
//   ck_assert_int_eq(res, res_orig);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(s21_sprintf_n) {
  char str1[100] = {0};
  char str2[100] = {0};
  int n1;
  int n2;
  int d1, d2;
  char format[] = "abra %ncdabrs";
  d1 = s21_sprintf(str1, format, &n1);
  d2 = sprintf(str2, "abra %ncdabrs", &n2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

// START_TEST(s21_sprintf_percent) {
//   char str1[100] = {0};
//   char str2[100] = {0};
//   char format[] = "%%bo";
//   ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_empty_format, *tc_int, *tc_uint, *tc_f, *tc_c, *tc_s, *tc_e, *tc_g;
  TCase *tc_o, *tc_x, *tc_p, *tc_n;
  s = suite_create("suite_sprintf");
  tc_empty_format = tcase_create("empty_format");
  tcase_add_test(tc_empty_format, s21_sprintf_empty_format);
  suite_add_tcase(s, tc_empty_format);
  tc_int = tcase_create("int");
  tcase_add_test(tc_int, s21_sprintf_int_plus);
  tcase_add_test(tc_int, s21_sprintf_int_max_plus);
  tcase_add_test(tc_int, s21_sprintf_int_min_plus);
  tcase_add_test(tc_int, s21_sprintf_int_minus);
  tcase_add_test(tc_int, s21_sprintf_int_plus_prec_more_len);
  tcase_add_test(tc_int, s21_sprintf_int_minus_prec_more_len);
  tcase_add_test(tc_int, s21_sprintf_int_plus_prec_less_len);
  tcase_add_test(tc_int, s21_sprintf_int_minus_prec_less_len);
  tcase_add_test(tc_int, s21_sprintf_int_plus_prec_more_len_wight_more);
  tcase_add_test(tc_int, s21_sprintf_int_minus_prec_more_len_wight_less);
  tcase_add_test(tc_int, s21_sprintf_int_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_int, s21_sprintf_int_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_int, s21_sprintf_int_plus_wight_zero);
  tcase_add_test(tc_int, s21_sprintf_int_plus_short);
  tcase_add_test(tc_int, s21_sprintf_int_plus_long);
  tcase_add_test(tc_int, s21_sprintf_int_plus_short_max);
  tcase_add_test(tc_int, s21_sprintf_int_plus_short_min);
  tcase_add_test(tc_int, s21_sprintf_int_force_plus);
  tcase_add_test(tc_int, s21_sprintf_int_wight_var);
  tcase_add_test(tc_int, s21_sprintf_int_spec_var);

  tcase_add_test(tc_int, s21_sprintf_int_plus_long_max);
  suite_add_tcase(s, tc_int);
  tc_uint = tcase_create("uint");
  tcase_add_test(tc_uint, s21_sprintf_uint_minus);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_prec_more_len);
  tcase_add_test(tc_uint, s21_sprintf_uint_minus_prec_more_len);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_prec_less_len);
  tcase_add_test(tc_uint, s21_sprintf_uint_minus_prec_less_len);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_prec_more_len_wight_more);
  tcase_add_test(tc_uint, s21_sprintf_uint_minus_prec_more_len_wight_less);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_uint, s21_sprintf_uint_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_wight_zero);
  tcase_add_test(tc_uint, s21_sprintf_uint_max);
  tcase_add_test(tc_uint, s21_sprintf_uint_long_max);
  tcase_add_test(tc_uint, s21_sprintf_uint_short_max);
  suite_add_tcase(s, tc_uint);
  tc_f = tcase_create("float");
  // tcase_add_test(tc_f, s21_sprintf_f_plus);
  tcase_add_test(tc_f, s21_sprintf_f_minus);
  tcase_add_test(tc_f, s21_sprintf_f_plus_prec_more_len);
  tcase_add_test(tc_f, s21_sprintf_f_minus_prec_more_len);
  tcase_add_test(tc_f, s21_sprintf_f_dot);
  tcase_add_test(tc_f, s21_sprintf_f_prec_less);
  tcase_add_test(tc_f, s21_sprintf_f_wight_plus);
  tcase_add_test(tc_f, s21_sprintf_f_plus_long);
  suite_add_tcase(s, tc_f);
  // tc_comb = tcase_create("comb");
  // tcase_add_test(tc_f, s21_sprintf_comb);
  // suite_add_tcase(s, tc_comb);
  tc_c = tcase_create("char");
  tcase_add_test(tc_c, s21_sprintf_c);
  suite_add_tcase(s, tc_c);
  tc_s = tcase_create("str");
  tcase_add_test(tc_s, s21_sprintf_s);
  tcase_add_test(tc_s, s21_sprintf_s_prec);
  suite_add_tcase(s, tc_s);
  tc_e = tcase_create("e");
  tcase_add_test(tc_e, s21_sprintf_e_plus);
  tcase_add_test(tc_e, s21_sprintf_e_minus);
  tcase_add_test(tc_e, s21_sprintf_e_plus_prec_more_len);
  tcase_add_test(tc_e, s21_sprintf_e_minus_prec_more_len);
  tcase_add_test(tc_e, s21_sprintf_e_dot);
  tcase_add_test(tc_e, s21_sprintf_e_prec_less);
  tcase_add_test(tc_e, s21_sprintf_e_wight_plus);
  tcase_add_test(tc_e, s21_sprintf_e_plus_sharp);
  tcase_add_test(tc_e, s21_sprintf_e_plus_long);
  tcase_add_test(tc_e, s21_sprintf_E_plus);
  tcase_add_test(tc_e, s21_sprintf_E_minus);
  tcase_add_test(tc_e, s21_sprintf_E_plus_prec_more_len);
  tcase_add_test(tc_e, s21_sprintf_E_minus_prec_more_len);
  tcase_add_test(tc_e, s21_sprintf_E_dot);
  tcase_add_test(tc_e, s21_sprintf_E_prec_less);
  tcase_add_test(tc_e, s21_sprintf_E_wight_plus);
  tcase_add_test(tc_e, s21_sprintf_E_plus_sharp);
  tcase_add_test(tc_e, s21_sprintf_E_plus_long);
  suite_add_tcase(s, tc_e);
  tc_g = tcase_create("g");
  tcase_add_test(tc_g, s21_sprintf_g_plus);
  tcase_add_test(tc_g, s21_sprintf_g_minus);
  tcase_add_test(tc_g, s21_sprintf_g_plus_prec_more_len);
  tcase_add_test(tc_g, s21_sprintf_g_minus_prec_more_len);
  tcase_add_test(tc_g, s21_sprintf_g_dot);
  tcase_add_test(tc_g, s21_sprintf_g_prec_less);
  tcase_add_test(tc_g, s21_sprintf_g_wight_plus);
  tcase_add_test(tc_g, s21_sprintf_g_plus_sharp);
  tcase_add_test(tc_g, s21_sprintf_g_plus_long);
  tcase_add_test(tc_g, s21_sprintf_G_plus);
  tcase_add_test(tc_g, s21_sprintf_G_minus);
  tcase_add_test(tc_g, s21_sprintf_G_plus_prec_more_len);
  tcase_add_test(tc_g, s21_sprintf_G_minus_prec_more_len);
  tcase_add_test(tc_g, s21_sprintf_G_dot);
  tcase_add_test(tc_g, s21_sprintf_G_prec_less);
  tcase_add_test(tc_g, s21_sprintf_G_wight_plus);
  tcase_add_test(tc_g, s21_sprintf_G_plus_sharp);
  tcase_add_test(tc_g, s21_sprintf_G_plus_long);
  suite_add_tcase(s, tc_g);
  tc_o = tcase_create("o");
  tcase_add_test(tc_o, s21_sprintf_o_minus);
  tcase_add_test(tc_o, s21_sprintf_o_plus);
  tcase_add_test(tc_o, s21_sprintf_o_max);
  tcase_add_test(tc_o, s21_sprintf_o_shrt_max);
  tcase_add_test(tc_o, s21_sprintf_o_long_max);
  tcase_add_test(tc_o, s21_sprintf_o_plus_prec_more_len);
  tcase_add_test(tc_o, s21_sprintf_o_minus_prec_more_len);
  tcase_add_test(tc_o, s21_sprintf_o_plus_prec_less_len);
  tcase_add_test(tc_o, s21_sprintf_o_minus_prec_less_len);
  tcase_add_test(tc_o, s21_sprintf_o_plus_prec_more_len_wight_more);
  tcase_add_test(tc_o, s21_sprintf_o_minus_prec_more_len_wight_less);
  tcase_add_test(tc_o, s21_sprintf_o_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_o, s21_sprintf_o_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_o, s21_sprintf_o_plus_wight_zero);
  tcase_add_test(tc_o, s21_sprintf_o_plus_sharp);
  suite_add_tcase(s, tc_o);
  tc_x = tcase_create("x");
  tcase_add_test(tc_x, s21_sprintf_x_minus);
  tcase_add_test(tc_x, s21_sprintf_x_plus);
  tcase_add_test(tc_o, s21_sprintf_x_max);
  tcase_add_test(tc_o, s21_sprintf_x_shrt_max);
  tcase_add_test(tc_o, s21_sprintf_x_long_max);
  tcase_add_test(tc_x, s21_sprintf_x_plus_prec_more_len);
  tcase_add_test(tc_x, s21_sprintf_x_minus_prec_more_len);
  tcase_add_test(tc_x, s21_sprintf_x_plus_prec_less_len);
  tcase_add_test(tc_x, s21_sprintf_x_minus_prec_less_len);
  tcase_add_test(tc_x, s21_sprintf_x_plus_prec_more_len_wight_more);
  tcase_add_test(tc_x, s21_sprintf_x_minus_prec_more_len_wight_less);
  tcase_add_test(tc_x, s21_sprintf_x_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_x, s21_sprintf_x_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_x, s21_sprintf_x_plus_wight_zero);
  tcase_add_test(tc_x, s21_sprintf_x_plus_sharp);
  tcase_add_test(tc_x, s21_sprintf_X_minus);
  tcase_add_test(tc_x, s21_sprintf_X_plus);
  tcase_add_test(tc_o, s21_sprintf_X_max);
  tcase_add_test(tc_o, s21_sprintf_X_shrt_max);
  tcase_add_test(tc_o, s21_sprintf_X_long_max);
  tcase_add_test(tc_x, s21_sprintf_X_plus_prec_more_len);
  tcase_add_test(tc_x, s21_sprintf_X_minus_prec_more_len);
  tcase_add_test(tc_x, s21_sprintf_X_plus_prec_less_len);
  tcase_add_test(tc_x, s21_sprintf_X_minus_prec_less_len);
  tcase_add_test(tc_x, s21_sprintf_X_plus_prec_more_len_wight_more);
  tcase_add_test(tc_x, s21_sprintf_X_minus_prec_more_len_wight_less);
  tcase_add_test(tc_x, s21_sprintf_X_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_x, s21_sprintf_X_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_x, s21_sprintf_X_plus_wight_zero);
  tcase_add_test(tc_x, s21_sprintf_X_plus_sharp);
  suite_add_tcase(s, tc_x);
  tc_p = tcase_create("p");
  tcase_add_test(tc_p, s21_sprintf_p);
  // tcase_add_test(tc_p, s21_sprintf_p_wight);
  suite_add_tcase(s, tc_p);
  tc_n = tcase_create("n");
  tcase_add_test(tc_n, s21_sprintf_n);
  suite_add_tcase(s, tc_n);
  // tc_percent = tcase_create("percent");
  // tcase_add_test(tc_percent, s21_sprintf_percent);
  // suite_add_tcase(s, tc_percent);
  return s;
}

Suite *s21_string_suite(void) {
  Suite *suite;
  suite = suite_create("s21_string");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, s21_memchr_test);
  tcase_add_test(tcase_core, s21_memcmp_test);
  tcase_add_test(tcase_core, s21_memcpy_test);
  tcase_add_test(tcase_core, s21_memmove_test);
  tcase_add_test(tcase_core, s21_memset_test);
  tcase_add_test(tcase_core, s21_strcat_test);
  tcase_add_test(tcase_core, s21_strncat_test);
  tcase_add_test(tcase_core, s21_strchr_test);
  tcase_add_test(tcase_core, s21_strcmp_test);
  tcase_add_test(tcase_core, s21_strncmp_test);
  tcase_add_test(tcase_core, s21_strcpy_test);
  tcase_add_test(tcase_core, s21_strncpy_test);
  tcase_add_test(tcase_core, s21_strcspn_test);
  tcase_add_test(tcase_core, s21_strlen_test);
  tcase_add_test(tcase_core, s21_strpbrk_test);
  tcase_add_test(tcase_core, s21_strrchr_test);
  tcase_add_test(tcase_core, s21_strspn_test);
  tcase_add_test(tcase_core, s21_strstr_test);
  tcase_add_test(tcase_core, s21_strtok_test);

  tcase_add_test(tcase_core, s21_strerror_test);

  tcase_add_test(tcase_core, s21_to_lower_test);
  tcase_add_test(tcase_core, s21_to_upper_test);
  tcase_add_test(tcase_core, s21_insert_test);
  tcase_add_test(tcase_core, s21_trim_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  srunner_add_suite(suite_runner, sprintf_test());
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_set_log(suite_runner, "test.log");
  srunner_run_all(suite_runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
