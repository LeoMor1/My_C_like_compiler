#include "utils.h"
#include <check.h>

START_TEST(test_chrpos)
{
    int test = chrpos("0123456789", '4');
    ck_assert_int_eq(4, test);
}
END_TEST


Suite *utils_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Utils");
    tc_core = tcase_create("Utils");

    tcase_add_test(tc_core, test_chrpos);
    suite_add_tcase(s, tc_core);

    return s;
}