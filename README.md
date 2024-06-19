# Big-number-calculator-
# Description
* This application performs arithmetic operations on large numbers that cannot be handled by standard data types in C.
* It supports addition, subtraction, multiplication, division, and power operations on large numbers.
* The numbers are represented using a doubly linked list to handle the large number of digits efficiently.
* The application reads an arithmetic expression from the user, parses it, and performs the specified operation on the large numbers.
# Compilation
* Requires GCC version > 8.0.
* Use make for optional compilation automation.
# Usage
* Run the program and input the arithmetic expression when prompted.
* The expression should be in the form of number1 operator number2 (e.g., 12345678901234567890 + 98765432109876543210).
* The result will be displayed after the computation.
# Processing
* The numbers are stored in a doubly linked list where each node contains a part of the large number.
* The expression is parsed to extract the operator and operands.
* Different functions are used to perform addition, subtraction, multiplication, division, and power operations on the numbers represented by the linked list.
* The results are computed and displayed in the correct order.
# Functions
# slice
* Parses the input expression to extract the two large numbers and the operator.
# apc_evaluation_sum
* Handles addition and subtraction of large numbers.
# apc_evaluation_mul
* Handles multiplication of large numbers.
# apc_evaluation_div
* Handles division of large numbers and also calculates the remainder.
# apc_evaluation_power
* Handles exponentiation of large numbers.
# check_greater
* Compares two large numbers to determine which is greater.
# dl_operations
* Contains all the doubly linked list operations, including insertion, deletion, and traversal.
This project is licensed under the MIT License - see the LICENSE file for details.

