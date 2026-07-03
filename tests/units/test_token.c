#include <check.h>
#include <stdlib.h>
#include "malloc_mock.h"
#include "token.h"
#include "tokenList.h"

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
    token.tokenType = T_PLUS;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: +");

    token.tokenType = T_MINUS;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: -");

    token.tokenType = T_SLASH;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: /");

    token.tokenType = T_STAR;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: *");

    token.tokenType = T_INTLIT;
    token.intValue = 0;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: intlist, Value: 0");

    token.tokenType = T_EOF;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: EOF");

    token.tokenType = -1;
    ck_assert_str_eq(tokenToStr(&token), "Token Type: UNKMOWN");
}
END_TEST

START_TEST(initTokenList_and_deleteTokenList)
{
    TokenList list;
    initTokenList(&list);

    ck_assert_ptr_nonnull(list.items);
    ck_assert_int_eq(list.count, 0);
    ck_assert_int_eq(list.capacity, 16);

    deleteTokenList(&list);

    ck_assert_ptr_null(list.items);
    ck_assert_int_eq(list.count, 0);
    ck_assert_int_eq(list.capacity, 0);
}
END_TEST

START_TEST(test_malloc_failure_in_initTokenList)
{
    set_malloc_should_fail(true);

    TokenList list;
    // This should cause the program to exit due to malloc failure
    initTokenList(&list);

    // If we reach this point, the test has failed
    ck_abort_msg("initTokenList did not exit on malloc failure");

    // set_malloc_should_fail(false);
}

START_TEST(appendToken_and_getToken)
{
    TokenList list;
    initTokenList(&list);

    Token token1 = {T_PLUS, 0};
    Token token2 = {T_INTLIT, 42};

    appendTokenInList(&list, token1);
    appendTokenInList(&list, token2);

    ck_assert_int_eq(getTokenListCount(&list), 2);

    Token *retrievedToken1 = getTokenAtInList(&list, 0);
    ck_assert_int_eq(retrievedToken1->tokenType, T_PLUS);
    ck_assert_int_eq(retrievedToken1->intValue, 0);

    Token *retrievedToken2 = getTokenAtInList(&list, 1);
    ck_assert_int_eq(retrievedToken2->tokenType, T_INTLIT);
    ck_assert_int_eq(retrievedToken2->intValue, 42);

    deleteTokenList(&list);
}
END_TEST

START_TEST(growTokenList)
{
    TokenList list;
    initTokenList(&list);

    for (size_t i = 0; i < 20; i++) {
        Token token = {T_INTLIT, (int)i};
        appendTokenInList(&list, token);
    }

    ck_assert_int_eq(getTokenListCount(&list), 20);
    ck_assert_int_ge(list.capacity, 20);

    deleteTokenList(&list);
}
END_TEST

START_TEST(test_getToken_out_of_bounds)
{
    TokenList list;
    initTokenList(&list);

    Token token = {T_INTLIT, 42};
    appendTokenInList(&list, token);
    getTokenAtInList(&list, 0); // This should work
    getTokenAtInList(&list, 1); // This should cause an error and exit the program

}
END_TEST

START_TEST(test_tokenListToStr_and_printTokenList)
{
    TokenList list;
    initTokenList(&list);

    Token token1 = {T_PLUS, 0};
    Token token2 = {T_INTLIT, 42};

    appendTokenInList(&list, token1);
    appendTokenInList(&list, token2);

    for (size_t i = 0; i < 20; i++) {
        Token token = {T_INTLIT, (int)i};
        appendTokenInList(&list, token);
    }

    char *listStr = tokenListToStr(&list);
    ck_assert_ptr_nonnull(listStr);
    ck_assert_str_eq(listStr, "[+, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist, intlist]");

    printTokenList(&list); // This will print to stdout

    free(listStr);
    deleteTokenList(&list);
}
END_TEST


Suite *token_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Token");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_tokenTypeToStr);
    tcase_add_test(tc_core, test_tokenToStr);
    tcase_add_test(tc_core, initTokenList_and_deleteTokenList);
    tcase_add_test(tc_core, appendToken_and_getToken);
    tcase_add_test(tc_core, growTokenList);
    tcase_add_test(tc_core, test_tokenListToStr_and_printTokenList);
    

    tcase_add_exit_test(tc_core, test_getToken_out_of_bounds, EXIT_FAILURE);
    tcase_add_exit_test(tc_core, test_malloc_failure_in_initTokenList, EXIT_FAILURE);

    suite_add_tcase(s, tc_core);

    return s;
}