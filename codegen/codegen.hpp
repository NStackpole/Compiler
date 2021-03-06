//Nathan Stackpole

#include "../parser/parser.hpp"
#include "../lexer/lexer.hpp"

#ifndef CODEGEN_HPP
#define CODEGEN_HPP

std::vector<token *> lex(char *, keyword_table *, symbol_table *);

expr *parse(std::vector<token *>, symbol_table *, std::deque<scope *> &);

#endif