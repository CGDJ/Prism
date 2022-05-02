#include "pch.h"
#include "Prism_vector_templated.h"

TEST(pVector_Templated_tests, InitTestDefault) {

	pVector<float, 3> a;
	EXPECT_FLOAT_EQ(a.data[0], 0);
	EXPECT_FLOAT_EQ(a.data[1], 0);
	EXPECT_FLOAT_EQ(a.data[2], 0);
}
TEST(pVector_Templated_tests, InitTestCustom) {

	pVector<float, 3> a(3);
	EXPECT_FLOAT_EQ(a.data[0], 3);
	EXPECT_FLOAT_EQ(a.data[1], 3);
	EXPECT_FLOAT_EQ(a.data[2], 3);
}

TEST(pVector_Templated_tests, OperatorSetEquals) {

	pVector<float, 3> a(3);
	pVector<float, 3> b(7);
	a = b;
	EXPECT_FLOAT_EQ(a.data[0], 7);
	EXPECT_FLOAT_EQ(a.data[1], 7);
	EXPECT_FLOAT_EQ(a.data[2], 7);
}
TEST(pVector_Templated_tests, OperatorVectorAddition) {

	pVector<float, 3> a(3);
	pVector<float, 3> b(7);
	a = a+b;
	EXPECT_FLOAT_EQ(a.data[0], 10);
	EXPECT_FLOAT_EQ(a.data[1], 10);
	EXPECT_FLOAT_EQ(a.data[2], 10);
}
TEST(pVector_Templated_tests, OperatorVectorSubtraction) {

	pVector<float, 3> a(10);
	pVector<float, 3> b(14);
	a = a - b;
	EXPECT_FLOAT_EQ(a.data[0], -4);
	EXPECT_FLOAT_EQ(a.data[1], -4);
	EXPECT_FLOAT_EQ(a.data[2], -4);
}
TEST(pVector_Templated_tests, OperatorDecrement) {

	pVector<float, 3> a(3);
	EXPECT_FLOAT_EQ(a.data[0], 3);
	EXPECT_FLOAT_EQ(a.data[1], 3);
	EXPECT_FLOAT_EQ(a.data[2], 3);
	--a;
	EXPECT_FLOAT_EQ(a.data[0], 2);
	EXPECT_FLOAT_EQ(a.data[1], 2);
	EXPECT_FLOAT_EQ(a.data[2], 2);
	a--;
	EXPECT_FLOAT_EQ(a.data[0], 1);
	EXPECT_FLOAT_EQ(a.data[1], 1);
	EXPECT_FLOAT_EQ(a.data[2], 1);
}
TEST(pVector_Templated_tests, OperatorIncrement) {

	pVector<float, 3> a(3);
	EXPECT_FLOAT_EQ(a.data[0], 3);
	EXPECT_FLOAT_EQ(a.data[1], 3);
	EXPECT_FLOAT_EQ(a.data[2], 3);
	++a;
	EXPECT_FLOAT_EQ(a.data[0], 4);
	EXPECT_FLOAT_EQ(a.data[1], 4);
	EXPECT_FLOAT_EQ(a.data[2], 4);
	a++;
	EXPECT_FLOAT_EQ(a.data[0], 5);
	EXPECT_FLOAT_EQ(a.data[1], 5);
	EXPECT_FLOAT_EQ(a.data[2], 5);
}
TEST(pVector_Templated_tests, OperatorMultiplyFloat) {

	pVector<float, 3> a(3);
	EXPECT_FLOAT_EQ(a.data[0], 3);
	EXPECT_FLOAT_EQ(a.data[1], 3);
	EXPECT_FLOAT_EQ(a.data[2], 3);
	a = a * 2;
	EXPECT_FLOAT_EQ(a.data[0], 6);
	EXPECT_FLOAT_EQ(a.data[1], 6);
	EXPECT_FLOAT_EQ(a.data[2], 6);
}
TEST(pVector_Templated_tests, isNUllVector) {

	pVector<float, 3> a(3);
	pVector<float, 3> b;
	EXPECT_TRUE(b.isNullVector());
	EXPECT_FALSE(a.isNullVector());
	
}
TEST(pVector_Templated_tests, start) {

	pVector<float, 3> a(3);
	ASSERT_EQ(a.start(), &a.data[0]);
	
}
TEST(pVector_Templated_tests, end) {

	pVector<float, 10> a(3);
	ASSERT_EQ(a.end(), &a.data[9]);

}
TEST(pVector_Templated_tests, numberOfElements) {

	pVector<float, 10> a(3);
	pVector<float, 5> b(3);
	EXPECT_EQ(a.number_of_elements(),10);
	EXPECT_EQ(b.number_of_elements(), 5);

}
TEST(pVector_Templated_tests, magnitude) {

	pVector<float, 3> a(3);
	
	EXPECT_FLOAT_EQ(a.magnitude(), 5.196152422706631);
	

}
TEST(pVector_Templated_tests, normalize) {

	pVector<float, 3> a(10);
	pVector<float, 3>b(0.57735026);
	EXPECT_FLOAT_EQ(a.normalize().data[0], b.data[0]);
	a.data[0] = 1;
	a.data[1] = 0;
	a.data[2] = 0;
	EXPECT_FLOAT_EQ(a.normalize().data[0], 1);

}
