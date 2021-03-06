//Nathan Stackpole, 2017

#include "symbol.hpp"
#include <string>

#ifndef TOKEN_HPP
#define TOKEN_HPP

enum token_kind
{
    false_tok,
    true_tok,
    L_parenth_tok,
    R_parenth_tok,
    plus_tok,
    minus_tok,
    star_tok,
    slash_tok,
    percent_tok,
    less_than_tok,
    less_than_eq_tok,
    more_than_tok,
    more_than_eq_tok,
    int_tok,
    pipe_tok,
    amp_tok,
    or_tok,
    and_tok,
    bang_tok,
    not_eq_tok,
    eq_tok,
    conditional_tok,
    otherwise_tok,
    id_tok,
    assign_tok,
    semi_col_tok,
    L_bracket_tok,
    R_bracket_tok,

    //keywords
    true_key,
    false_key,
    bool_key,
    int_key,
    var_key,
    if_key,
    else_key,
    assert_key
};

struct token
{
    int name;
    std::string value;
    token(int, std::string);
    token(int, symbol*);
    token(int);
    token();
};

struct integer_token : public token
{
    integer_token(std::string);
};

struct boolean_token : public token
{
    boolean_token(int);
};

struct id_token : public token
{
    id_token(symbol *);
};

struct keyword_table : std::unordered_map<std::string, token_kind>
{
    keyword_table();
};

#endif