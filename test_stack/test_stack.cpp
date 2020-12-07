#include "../Stack/Stack.h"

#include "gtest.h"

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Stack <int> bf(3));
}

TEST(Stack, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(Stack<int> bf(-5));
}

TEST(Stack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(Stack <int> bf(MAX_SIZE + 1));
}

TEST(Stack, can_create_copied_stack)
{
	Stack<int> bf(10);

	ASSERT_NO_THROW(Stack<int> bf1(bf));
}

TEST(Stack, copied_stack_is_equal_to_source_one)
{
	Stack <int> bf1(10), bf2(10);
	for (int i = 0; i < bf1.GetSize(); i++)
	{
		bf1[i] = i + 1;
		bf2[i] = bf1[i];
	}
	EXPECT_EQ(bf1, bf2);
}

TEST(Stack, copied_stack_has_its_own_memory)
{
	Stack <int> bf1(10), bf2(10);
	for (int i = 0; i < 10; i++)
	{
		bf1[i] = i + 1;
		bf2[i] = bf1[i];
	}
	EXPECT_NE(&bf1[0], &bf2[0]);
}

TEST(Stack, can_get_size)
{
	Stack<int> bf(10);
	EXPECT_EQ(10, bf.GetSize());
}

TEST(Stack, can_put_element)
{
	Stack<int> bf(10);
	ASSERT_NO_THROW(bf.Push(15));
	EXPECT_EQ(15, bf.Top());
}

TEST(Stack, can_assign_stack_to_itself)
{
	Stack <int> bf(10);
	for (int i = 0; i < bf.GetSize(); i++)
	{
		bf[i] = i + 1;
	}
	ASSERT_NO_THROW(bf = bf);
}

TEST(Stack, can_assign_stacks_of_equal_size)
{
	Stack <int> bf1(10), bf2(10);
	for (int i = 0; i < bf1.GetSize(); i++)
	{
		bf1[i] = i + 1;
	}
	ASSERT_NO_THROW(bf2 = bf1);
	EXPECT_EQ(bf1.GetSize(), bf2.GetSize());
}

TEST(Stack, assign_operator_change_stack_size)
{
	Stack <int> bf1(10), bf2(15);
	bf2 = bf1;
	EXPECT_EQ(bf1.GetSize(), bf2.GetSize());
}

TEST(Stack, can_assign_stacks_of_different_size)
{
	Stack <int> bf1(10), bf2(7);
	for (int i = 0; i < bf1.GetSize(); i++)
	{
		bf1[i] = i + 1;
	}
	ASSERT_NO_THROW(bf2 = bf1);
}

TEST(Stack, compare_equal_stacks_return_true)
{
	Stack <int> bf1(10);
	for (int i = 0; i < bf1.GetSize(); i++)
	{
		bf1[i] = i + 1;
	}
	Stack <int> bf2 = bf1;
	EXPECT_EQ(1, bf1 == bf2);
}

TEST(Stack, compare_stack_with_itself_return_true)
{
	Stack <int> bf(10);
	for (int i = 0; i < bf.GetSize(); i++)
	{
		bf[i] = i + 1;
	}
	EXPECT_EQ(1, bf == bf);
}

TEST(Stack, stacks_with_different_size_are_not_equal)
{
	Stack <int> bf1(10), bf2(15);
	EXPECT_EQ(1, bf1 != bf2);
}

TEST(Stack, can_put_out_of_not_empty_stack)
{
	Stack<int>bf(10);
	bf.Push(2);
	ASSERT_NO_THROW(bf.Pop());
}

TEST(Stack, cant_put_out_of_empty_stack)
{
	Stack<int>bf(10);
	ASSERT_ANY_THROW(bf.Pop());
}

TEST(Stack, empty_stack_return_true)
{
	Stack <int> bf(10);
	EXPECT_EQ(1, bf.Empty());
}

TEST(Stack, can_check_that_stack_is_empty)
{
	Stack <int> bf(10);
	ASSERT_NO_THROW(bf.Empty());
}

TEST(Stack, cant_put_in_full_stack)
{
	Stack<int>bf(1);
	bf.Push(2);
	ASSERT_ANY_THROW(bf.Push(2));
}

TEST(Stack, can_put_in_not_full_stack)
{
	Stack<int>bf(2);
	bf.Push(1);
	ASSERT_NO_THROW(bf.Push(2));
}

TEST(Stack, full_stack_return_true)
{
	Stack<int>bf(1);
	bf.Push(2);
	EXPECT_EQ(1, bf.Full());
}

TEST(Stack, can_check_that_stack_is_full)
{
	Stack<int>bf(10);
	ASSERT_NO_THROW(bf.Full());
}

TEST(Stack, can_return_the_top)
{
	Stack<int>bf(10);
	bf.Push(2);
	ASSERT_NO_THROW(bf.Top());
}

TEST(Stack, cant_return_the_top_of_empty_stack)
{
	Stack<int>bf(10);
	bf.Empty();
	ASSERT_ANY_THROW(bf.Top());
}






