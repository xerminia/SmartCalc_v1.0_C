#include <check.h>

#include "calc.h"

START_TEST(plus) {
  char arr[255] = "10+20-(((30*30))^2^2--sin(+27))*-2.75";
  char x[255] = "\0";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "1804275000032.63012695");
}
END_TEST

START_TEST(cos2) {
  char arr[255] = "cos(x+1)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "-0.91113026");
}
END_TEST

START_TEST(sin2) {
  char arr[255] = "sin(x-1)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "0.99999021");
}
END_TEST

START_TEST(tan2) {
  char arr[255] = "tan(x*-1)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "0.64836083");
}
END_TEST

START_TEST(acos2) {
  char arr[255] = "acos(x^2)";
  char x[255] = "-0.1";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "1.56079616");
}
END_TEST

START_TEST(asin2) {
  char arr[255] = "asin(x/2)";
  char x[255] = "-0.1";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "-0.05002086");
}
END_TEST

START_TEST(testatan2) {
  char arr[255] = "atan(x%0.01)";
  char x[255] = "-0.1";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "-0.00000000");
}
END_TEST

START_TEST(sqrt2) {
  char arr[255] = "sqrt(x-*12)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "Error input!");
}
END_TEST

START_TEST(ln2) {
  char arr[255] = "ln(x)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "nan");
}
END_TEST

START_TEST(testlog2) {
  char arr[255] = "log(x)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "nan");
}
END_TEST

START_TEST(cos1) {
  char arr[255] = "-cos(x)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "0.83907153");
}
END_TEST

START_TEST(sin1) {
  char arr[255] = "-sin(25)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "0.13235175");
}
END_TEST

START_TEST(tan1) {
  char arr[255] = "-tan(x*-37)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "0.85594117");
}
END_TEST

START_TEST(acos1) {
  char arr[255] = "-acos(x-3*(x+2))";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "nan");
}
END_TEST

START_TEST(asin1) {
  char arr[255] = "-asin(x)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "nan");
}
END_TEST

START_TEST(atan1) {
  char arr[255] = "-atan(x)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "1.47112767");
}
END_TEST

START_TEST(sqrt1) {
  char arr[255] = "-sqrt(x)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "nan");
}
END_TEST

START_TEST(ln1) {
  char arr[255] = "-ln(x)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "nan");
}
END_TEST

START_TEST(log1) {
  char arr[255] = "-log(x)";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "nan");
}
END_TEST

START_TEST(ymnojenie) {
  char arr[255] = "10/10*10*1*0.18-123";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "-121.20000000");
}
END_TEST

START_TEST(error1) {
  char arr[255] = ")";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "Error input!");
}
END_TEST

START_TEST(error2) {
  char arr[255] = "**";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "Error input!");
}
END_TEST

START_TEST(error3) {
  char arr[255] = "ass";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "Error input!");
}
END_TEST

START_TEST(error4) {
  char arr[255] = "2.2.2";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "Error input!");
}
END_TEST

START_TEST(error5) {
  char arr[255] = "()";
  char x[255] = "-10";
  char res[400] = "\0";
  s21_strcat(res, calcash(arr, x));
  ck_assert_str_eq(res, "Error input!");
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("fpeEGg");
  SRunner *sr = srunner_create(s1);
  int nf;

  TCase *tc1_1 = tcase_create("fpeEGg");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, plus);
  tcase_add_test(tc1_1, cos2);
  tcase_add_test(tc1_1, sin2);
  tcase_add_test(tc1_1, tan2);
  tcase_add_test(tc1_1, acos2);
  tcase_add_test(tc1_1, asin2);
  tcase_add_test(tc1_1, testatan2);
  tcase_add_test(tc1_1, sqrt2);
  tcase_add_test(tc1_1, ln2);
  tcase_add_test(tc1_1, testlog2);
  tcase_add_test(tc1_1, cos1);
  tcase_add_test(tc1_1, sin1);
  tcase_add_test(tc1_1, tan1);
  tcase_add_test(tc1_1, acos1);
  tcase_add_test(tc1_1, asin1);
  tcase_add_test(tc1_1, atan1);
  tcase_add_test(tc1_1, sqrt1);
  tcase_add_test(tc1_1, ln1);
  tcase_add_test(tc1_1, log1);
  tcase_add_test(tc1_1, ymnojenie);
  tcase_add_test(tc1_1, error1);
  tcase_add_test(tc1_1, error2);
  tcase_add_test(tc1_1, error3);
  tcase_add_test(tc1_1, error4);
  tcase_add_test(tc1_1, error5);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
