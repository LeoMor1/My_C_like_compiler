#include <check.h>
#include "lexer/lexer.h"
#include <stdlib.h>

START_TEST(test_tokenTypeToStr)
{
    ck_assert_str_eq(tokenTypeToStr(T_PLUS), "+");
    ck_assert_str_eq(tokenTypeToStr(T_MINUS), "-");
    ck_assert_str_eq(tokenTypeToStr(T_SLASH), "/");
    ck_assert_str_eq(tokenTypeToStr(T_STAR), "*");
    ck_assert_str_eq(tokenTypeToStr(T_INTLIT), "intlist");
    ck_assert_str_eq(tokenTypeToStr(T_EOF), "EOF");
    ck_assert_str_eq(tokenTypeToStr(-1), "UNKMOWN");
}
END_TEST

START_TEST(test_tokenToStr)
{
    Token token;
    token.token = T_PLUS;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: +");

    token.token = T_MINUS;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: -");

    token.token = T_SLASH;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: /");

    token.token = T_STAR;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: *");

    token.token = T_INTLIT;
    token.intValue = 0;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: intlist, Value: 0");

    token.token = T_EOF;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: EOF");

    token.token = -1;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: UNKMOWN");
}
END_TEST

START_TEST(test_data_init_and_delete)
{
    LexerData data;
    initLexerData(&data, "test_files/input01");

    ck_assert_int_eq(data.line, 0);
    ck_assert_int_eq(data.column, 1);
    ck_assert_int_eq(data.putback, '\n');
    ck_assert_ptr_nonnull(data.infile);

    deleteLexerData(&data);

    ck_assert_int_eq(data.line, 0);
    ck_assert_int_eq(data.column, 1);
    ck_assert_int_eq(data.putback, '\n');
    ck_assert_ptr_null(data.infile);
}
END_TEST

START_TEST(test_data_init_invalid_file)
{
    LexerData data;
    initLexerData(&data, "invalide_file");
}
END_TEST

START_TEST(test_scan)
{
    LexerData data;
    initLexerData(&data, "test_files/input03");

    Token token;
    scan(&data, &token);
    ck_assert_str_eq(tokenToStr(&token), "Token Type: intlist, Value: 1");

    scan(&data, &token);
    ck_assert_str_eq(tokenToStr(&token), "Token Type: +");

    scan(&data, &token);
    ck_assert_str_eq(tokenToStr(&token), "Token Type: -");

    scan(&data, &token);
    ck_assert_str_eq(tokenToStr(&token), "Token Type: /");

    scan(&data, &token);
    ck_assert_str_eq(tokenToStr(&token), "Token Type: *");

    scan(&data, &token);
    ck_assert_str_eq(tokenToStr(&token), "Token Type: UNKMOWN");

    scan(&data, &token);
    ck_assert_str_eq(tokenToStr(&token), "Token Type: EOF");

    deleteLexerData(&data);
}
END_TEST

Suite *lexer_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Lexer");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_tokenTypeToStr);
    tcase_add_test(tc_core, test_tokenToStr);
    tcase_add_test(tc_core, test_data_init_and_delete);
    tcase_add_test(tc_core, test_scan);

    tcase_add_exit_test(tc_core, test_data_init_invalid_file, EXIT_FAILURE);

    suite_add_tcase(s, tc_core);

    return s;
}