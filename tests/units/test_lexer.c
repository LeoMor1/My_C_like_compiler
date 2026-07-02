#include <check.h>
#include "lexer/lexer.h"
#include <stdlib.h>

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

START_TEST(test_scanfile)
{
    LexerData data;
    initLexerData(&data, "test_files/input03");

    TokenList tokenList;
    initTokenList(&tokenList);
    scanfile(&data, &tokenList);
    ck_assert_ptr_nonnull(&tokenList);
    ck_assert_int_eq(getTokenListCount(&tokenList), 7);

    Token *token = getToken(&tokenList, 0);
    ck_assert_str_eq(tokenToStr(token), "Token Type: intlist, Value: 1");

    token = getToken(&tokenList, 1);
    ck_assert_str_eq(tokenToStr(token), "Token Type: +");

    token = getToken(&tokenList, 2);
    ck_assert_str_eq(tokenToStr(token), "Token Type: -");

    token = getToken(&tokenList, 3);
    ck_assert_str_eq(tokenToStr(token), "Token Type: /");

    token = getToken(&tokenList, 4);
    ck_assert_str_eq(tokenToStr(token), "Token Type: *");

    token = getToken(&tokenList, 5);
    ck_assert_str_eq(tokenToStr(token), "Token Type: UNKMOWN");

    token = getToken(&tokenList, 6);
    ck_assert_str_eq(tokenToStr(token), "Token Type: EOF");

    deleteLexerData(&data);
}
END_TEST

START_TEST(test_scanfile_empty)
{
    LexerData data;
    initLexerData(&data, "test_files/empty_file");

    TokenList tokenList;
    initTokenList(&tokenList);
    scanfile(&data, &tokenList);
    ck_assert_ptr_nonnull(&tokenList);
    ck_assert_int_eq(getTokenListCount(&tokenList), 1);

    Token *token = getToken(&tokenList, 0);
    ck_assert_str_eq(tokenToStr(token), "Token Type: EOF");

    deleteLexerData(&data);
}
END_TEST

START_TEST(test_tokenList_null)
{
    LexerData data;
    initLexerData(&data, "test_files/input03");

    scanfile(&data, NULL);
}
END_TEST


Suite *lexer_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Lexer");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_data_init_and_delete);
    tcase_add_test(tc_core, test_scan);
    tcase_add_test(tc_core, test_scanfile);

    tcase_add_exit_test(tc_core, test_data_init_invalid_file, EXIT_FAILURE);
    tcase_add_exit_test(tc_core, test_tokenList_null, EXIT_FAILURE);
    tcase_add_exit_test(tc_core, test_scanfile_empty, EXIT_FAILURE);

    suite_add_tcase(s, tc_core);

    return s;
}