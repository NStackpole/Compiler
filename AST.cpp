//Nathan Stackpole

#include "AST.hpp"
#include "type.hpp"

//Constructors
Bool_expr::Bool_expr(bool v) : value(v) {}

Not_expr::Not_expr(expr *expression) : e(expression)
{
    Context cxt;
    assert(check(cxt, expression) == &cxt.boolean);
}

Or_expr::Or_expr(expr *expression1, expr *expression2) : e1(expression1), e2(expression2)
{
    Context cxt;
    assert(check(cxt, expression1) == &cxt.boolean && check(cxt, expression2) == &cxt.boolean);
}

Xor_expr::Xor_expr(expr *expression1, expr *expression2) : e1(expression1), e2(expression2)
{
    Context cxt;
    assert(check(cxt, expression1) == &cxt.boolean && check(cxt, expression2) == &cxt.boolean);
}

And_expr::And_expr(expr *expression1, expr *expression2) : e1(expression1), e2(expression2)
{
    Context cxt;
    assert(check(cxt, expression1) == &cxt.boolean && check(cxt, expression2) == &cxt.boolean);
}

EqualTo_expr::EqualTo_expr(expr *expression1, expr *expression2) : e1(expression1), e2(expression2)
{
    Context cxt;
    assert(check(cxt, expression1) == check(cxt, expression2));
}

LessThan_expr::LessThan_expr(expr *expression1, expr *expression2) : e1(expression1), e2(expression2)
{
    Context cxt;
    assert(check(cxt, expression1) == &cxt.integer && check(cxt, expression2) == &cxt.integer);
}

MoreThan_expr::MoreThan_expr(expr *expression1, expr *expression2) : e1(expression1), e2(expression2)
{
    Context cxt;
    assert(check(cxt, expression1) == &cxt.integer && check(cxt, expression2) == &cxt.integer);
}

Conditional_expr::Conditional_expr(expr *expression1, expr *expression2, expr *expression3) : e1(expression1), e2(expression2), e3(expression3)
{
    Context cxt;
    assert(check(cxt, expression1) == &cxt.boolean && check(cxt, expression2) == &cxt.boolean && check(cxt, expression3) == &cxt.boolean);
}

Integer_expr::Integer_expr(int integer) : val(integer) {}

//Base expression functions
int expr::weight(expr *e)
{
    return e->weight();
}

int expr::height(expr *e)
{
    return e->height();
}

//Bool_expr function definitions
int Bool_expr::weight() { return 1; }
int Bool_expr::height() { return 0; }
bool Bool_expr::get_value() { return value; }
void Bool_expr::accept(Visitor &v) { return v.visit(this); }

//Not_expr function definitions
int Not_expr::weight() { return 1 + expr::weight(e); }
int Not_expr::height() { return 1 + expr::height(e); }
expr *Not_expr::get_e() { return e; }
void Not_expr::accept(Visitor &v) { return v.visit(this); }

//Or_expr function definitions
int Or_expr::weight() { return 1 + expr::weight(e1) + expr::weight(e2); }
int Or_expr::height() { return 1 + std::max(expr::height(e1), expr::height(e2)); }
expr *Or_expr::get_e1() { return e1; }
expr *Or_expr::get_e2() { return e2; }
void Or_expr::accept(Visitor &v) { return v.visit(this); }

//Xor_expr function definitions
int Xor_expr::weight() { return 1 + expr::weight(e1) + expr::weight(e2); }
int Xor_expr::height() { return 1 + std::max(expr::height(e1), expr::height(e2)); }
expr *Xor_expr::get_e1() { return e1; }
expr *Xor_expr::get_e2() { return e2; }
void Xor_expr::accept(Visitor &v) { return v.visit(this); }

//And_expr function definitions
int And_expr::weight() { return 1 + expr::weight(e1) + expr::weight(e2); }
int And_expr::height() { return 1 + std::max(expr::height(e1), expr::height(e2)); }
expr *And_expr::get_e1() { return e1; }
expr *And_expr::get_e2() { return e2; }
void And_expr::accept(Visitor &v) { return v.visit(this); }

//Conditional_expr function definitions
int Conditional_expr::weight() { return 1 + expr::weight(e1) + expr::weight(e2); }
int Conditional_expr::height() { return 1 + std::max(expr::height(e1), expr::height(e2)); }
expr *Conditional_expr::get_e1() { return e1; }
expr *Conditional_expr::get_e2() { return e2; }
expr *Conditional_expr::get_e3() { return e3; }
void Conditional_expr::accept(Visitor &v) { return v.visit(this); }

//Integer functions
int Integer_expr::weight() { return 1; }
int Integer_expr::height() { return 0; }
int Integer_expr::get_val() { return val; }
void Integer_expr::accept(Visitor &v) { return v.visit(this); }

//LessThan_expr function definitions
int LessThan_expr::weight() { return 1 + expr::weight(e1) + expr::weight(e2); }
int LessThan_expr::height() { return 1 + std::max(expr::height(e1), expr::height(e2)); }
expr *LessThan_expr::get_e1() { return e1; }
expr *LessThan_expr::get_e2() { return e2; }
void LessThan_expr::accept(Visitor &v) { return v.visit(this); }

//MoreThan_expr function definitions
int MoreThan_expr::weight() { return 1 + expr::weight(e1) + expr::weight(e2); }
int MoreThan_expr::height() { return 1 + std::max(expr::height(e1), expr::height(e2)); }
expr *MoreThan_expr::get_e1() { return e1; }
expr *MoreThan_expr::get_e2() { return e2; }
void MoreThan_expr::accept(Visitor &v) { return v.visit(this); }

//EqualTo_expr function definitions
int EqualTo_expr::weight() { return 1 + expr::weight(e1) + expr::weight(e2); }
int EqualTo_expr::height() { return 1 + std::max(expr::height(e1), expr::height(e2)); }
expr *EqualTo_expr::get_e1() { return e1; }
expr *EqualTo_expr::get_e2() { return e2; }
void EqualTo_expr::accept(Visitor &v) { return v.visit(this); }