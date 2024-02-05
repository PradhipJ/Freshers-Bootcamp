#include "gtest/gtest.h"
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectedZeroForEmptyInput) {
	//Arrange
	int expectedResult = 0;
	string input = "";

	//Act
	int actualResult = StringCalculator::addNumbers(input);

	//Assert
	ASSERT_EQ(expectedResult, actualResult);
}

TEST(StringCalculatorAddTests, ExpectedZeroForZeroInput) {
	//Arrange
	int expectedResult = 0;
	string input = "0";

	//Act
	int actualResult = StringCalculator::addNumbers(input);

	//Assert
	ASSERT_EQ(expectedResult, actualResult);
}

TEST(StringCalculatorAddTests, ExpectedNumberForSingleNumber) {
	//Arrange
	int expectedResult = 2;
	string input = "2";

	//Act
	int actualResult = StringCalculator::addNumbers(input);

	//Assert
	ASSERT_EQ(expectedResult, actualResult);
}

TEST(StringCalculatorAddTests, ExpectedSumForTwoNumbers) {
	//Arrange
	int expectedResult = 3;
	string input = "1,2";

	//Act
	int actualResult = StringCalculator::addNumbers(input);

	//Assert
	ASSERT_EQ(expectedResult, actualResult);
}

TEST(StringCalculatorAddTests, ExpectedExceptionForNegativeNumber) {
	//Arrange
	string input = "-1";

	//Act and Assert
	EXPECT_THROW(StringCalculator::addNumbers(input), std::invalid_argument);
}

TEST(StringCalculatorAddTests, ExpectedSumIgnoringFourDigitNumbers) {
	//Arrange
	int expectedResult = 6;
	string input = "1,2,1001,3";

	//Act
	int actualResult = StringCalculator::addNumbers(input);

	//Assert
	ASSERT_EQ(expectedResult, actualResult);
}
