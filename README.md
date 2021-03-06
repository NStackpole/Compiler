# Compiler Design Repository
This repository holds work (a compiler) done for my Compiler Design class. 

This compiler currently:
* Can evaluate the following expressions : Not, And, Or, Xor, Conditional, <, >, ==, !=, <=, >=, and then (&&), or else (||), division, modulus, negation, multiplication, subtraction, addition.
* Has a very basic type system: integer and boolean.
* Checks the types of expressions to make sure they are well formed. If an expression is not well formed the program will abort.
* Use lexical analysis to generate tokens from lines of text (source code).
* Uses a parser to generate abstract syntax trees.
* Has a calculator program that accepts input through standard in. Takes input through standard input, lexes the lines, printing out the tokens as it goes, then parses them, and finally evaluates them.
* Integer and boolean variables can be declared and used in expressions.

TODO:
* Implement expression printing
* Implement code generation (JVM or LLVM)

#### File Descriptions:

* AST: Describes the Abstract Syntax Tree for this assignment. Contains definitons for all of the expressions listed above, as well as the definition of the type system.
* type_check: Contains a function called check that checks the types of expressions to make sure they are well formed. (ex. makes sure < is given two integers). If the expression is not well formed the program will abort.
* eval: Contains a function called eval that evaluates expressions. Will throw an exception if one of the following issues is detected: Integer overflow, division by zero or minimum integer value, modular divison by zero or minimum integer value.
* test: Contains tests for the constructors and evals of each type of expression.
* lexer: These files contain the lexer, which takes in lines of text and generate tokens.
* calculator: Defines a calculator that uses the lexer to evaluate user input.
* parser: contains the parser, which takes a vector of tokens and turns it into an expression.
* codgen: will hold the code to call a library that will generat code based on given abstract syntax trees.
