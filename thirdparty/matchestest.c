#include "../src/libmatches/checktruth.h"
#include "../src/libmatches/choosegame.h"
#include "../src/libmatches/commonrules.h"
#include "../src/libmatches/difficulty.h"
#include "../src/libmatches/gamepvp.h"
#include "../src/libmatches/gamepvbh.h"
#include "../test/ctest.h"

CTEST(checktruth, check_first) {
  const int checkvalue = 5;
  const int amount = 100;
  const int result = check(checkvalue, amount);
  const int expected = 1;
  ASSERT_EQUAL(expected, result);
}

CTEST(checktruth, check_second) {
  const int checkvalue = 5;
  const int amount = 4;
  const int result = check(checkvalue, amount);
  const int expected = 2;
  ASSERT_EQUAL(expected, result);
}

CTEST(checktruth, check_third) {
  const int checkvalue = 0;
  const int amount = 100;
  const int result = check(checkvalue, amount);
  const int expected = 3;
  ASSERT_EQUAL(expected, result);
}

CTEST(checktruth, check_fourth) {
  const int checkvalue = 11;
  const int amount = 100;
  const int result = check(checkvalue, amount);
  const int expected = 3;
  ASSERT_EQUAL(expected, result);
}

CTEST(commonrules, check_first) {
  const char value = 'n';
  const int result = restart(1, value);
  const int expected = 0;
  ASSERT_EQUAL(expected, result);
}

CTEST(typeofbot, type_easy) {
  const char diff = 'e';
  const int result = difficulty(diff);
  const int expected = 1;
  ASSERT_EQUAL(expected, result);
}

CTEST(typeofbot, type_hard) {
  const char diff = 'h';
  const int result = difficulty(diff);
  const int expected = 2;
  ASSERT_EQUAL(expected, result);
}

CTEST(typeofgame, type_user) {
  const char game = 'm';
  const int result = choosegame(game);
  const int expected = 1;
  ASSERT_EQUAL(expected, result);
}

CTEST(typeofgame, type_bot) {
  const char game = 'B';
  const int result = choosegame(game);
  const int expected = 2;
  ASSERT_EQUAL(expected, result);
}

CTEST(hardbot, case_first) {
  const int result = bothturn(95, 5);
  const int expected = 92;
  ASSERT_EQUAL(expected, result);
}

CTEST(hardbot, case_second) {
  const int result = bothturn(93, 7);
  const int expected = 92;
  ASSERT_EQUAL(expected, result);
}

CTEST(hardbot, case_third) {
  const int result = bothturn(90, 10);
  const int expected = 80;
  ASSERT_EQUAL(expected, result);
}

CTEST(hardbot, case_fourth) {
  const int result = bothturn(50, 8);
  const int expected = 48;
  ASSERT_EQUAL(expected, result);
}

CTEST(hardbot, case_fifth) {
  const int result = bothturn(12, 5);
  const int expected = 2;
  ASSERT_EQUAL(expected, result);
}

CTEST(hardbot, case_sixth) {
  const int result = bothturn(100, 10);
  const int expected = 92;
  ASSERT_EQUAL(expected, result);
}
