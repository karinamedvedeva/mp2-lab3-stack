#include "gtest.h"
#include "../Stack/Calculator.h"
#include "../Stack/Calculator.cpp"

TEST(Calculator, can_get_infix)
{
	Calculator calc;
	ASSERT_NO_THROW(calc.GetExpression());
}

TEST(Calculator, can_get_postfix)
{
	Calculator calc;
	ASSERT_NO_THROW(calc.GetPostfix());
}

TEST(Calculator, can_set_formula)
{
	Calculator calc;
	string str = "5+5-4";
	ASSERT_NO_THROW(calc.SetExpression(str));
}

TEST(Calculator, can_set_a_string_to_calculator)
{
	Calculator calc;
	string str = "5+5-4";
	ASSERT_NO_THROW(calc.SetFormula(str));
}

TEST(Calculator, can_check_wrong_brackets)
{
	Calculator calc;
	string str = "5+(5-4";
	ASSERT_ANY_THROW(calc.SetFormula(str));
}

TEST(Calculator, can_check_right_brackets)
{
	Calculator calc;
	string str = "5+(5-4)";
	ASSERT_NO_THROW(calc.SetFormula(str));
}

TEST(Calculator, can_add_numbers)
{
	Calculator calc;
	calc.SetFormula("5+4");
	calc.ToPostfix();
	EXPECT_EQ(9, calc.CalcPostfix());
}

TEST(Calculator, can_subtract_numbers)
{
	Calculator calc;
	calc.SetFormula("5-4");
	calc.ToPostfix();
	EXPECT_EQ(1, calc.CalcPostfix());
}

TEST(Calculator, can_multiply_numbers)
{
	Calculator calc;
	calc.SetFormula("5*4");
	calc.ToPostfix();
	EXPECT_EQ(20, calc.CalcPostfix());
}

TEST(Calculator, can_divide_numbers)
{
	Calculator calc;
	calc.SetFormula("8/2");
	calc.ToPostfix();
	EXPECT_EQ(4, calc.CalcPostfix());
}

TEST(Calculator, can_pow_numbers)
{
	Calculator calc;
	calc.SetFormula("8^2");
	calc.ToPostfix();
	EXPECT_EQ(64, calc.CalcPostfix());
}

TEST(Calculator, can_do_all_operations_with_numbers_together)
{
	Calculator calc;
	calc.SetFormula("1+2-5*4/5");
	calc.ToPostfix();
	EXPECT_EQ(-1, calc.CalcPostfix());
}

TEST(Calculator, cant_calculate_expression_with_wrong_number_of_operations)
{
	Calculator calc;
	calc.SetFormula("5++5-4");
	calc.ToPostfix();
	EXPECT_ANY_THROW(calc.CalcPostfix());
}
