# Big-number-calculator-
BigNum Calculator
Table of Contents
Project Overview
Features
Installation
Usage
Functions
Examples
Contributing
License
Project Overview
The BigNum Calculator is a C-based project designed to perform arithmetic operations on very large numbers (BigNums) using a doubly linked list data structure. This project aims to handle calculations that exceed the storage capacity of standard data types in C, providing accurate results for operations like addition, subtraction, multiplication, division, and exponentiation.

Features
Addition and Subtraction: Perform basic arithmetic operations on large numbers.
Multiplication: Efficiently multiply two large numbers.
Division and Modulus: Divide large numbers and find the remainder.
Exponentiation: Calculate power of large numbers.
Doubly Linked List: Use of doubly linked list to store and manipulate large numbers.
Installation
To install and run the BigNum Calculator, follow these steps:

Clone the repository:

bash
Copy code
git clone https://github.com/your-username/bignum-calculator.git
Navigate to the project directory:

bash
Copy code
cd bignum-calculator
Compile the source code:

bash
Copy code
gcc -o bignum_calculator main.c slice.c apc_evaluation.c dl_operations.c
Usage
After compiling the project, you can run the calculator using the following command:

bash
Copy code
./bignum_calculator
The calculator reads expressions from the standard input and processes arithmetic operations on large numbers. Enter your expression and press Enter to see the result.

Functions
slice.c
**void slice(char *expression, Dlist_t **var1, Dlist_t var2)
Parses the input expression and divides it into two large numbers and an operator.
apc_evaluation.c
*Dlist_t apc_evaluation_sum(Dlist_t **var1, Dlist_t var2, char operator)
Performs addition and subtraction of two large numbers.
*Dlist_t apc_evaluation_mul(Dlist_t **var1, Dlist_t var2, char operator)
Multiplies two large numbers.
**void apc_evaluation_power(Dlist_t **var1, Dlist_t var2)
Calculates the power of a large number.
**int apc_evaluation_div(Dlist_t **var1, Dlist_t var2, char operator)
Divides two large numbers or finds the remainder.
dl_operations.c
Dlist_t dl_create_node(int val)*
Creates a new node for the doubly linked list.
**void dl_insert_first(Dlist_t head, int val)
Inserts a new node at the beginning of the list.
*void dl_print_list(Dlist_t head)
Prints the doubly linked list.
**void dl_delete_first(Dlist_t head)
Deletes the first node of the list.
**void dl_delete_list(Dlist_t head)
Deletes the entire list.
Examples
Here are a few examples of how to use the BigNum Calculator:

Addition:

makefile
Copy code
Input: 12345678901234567890 + 98765432109876543210
Output: 111111111011111111100
Multiplication:

makefile
Copy code
Input: 12345678901234567890 * 98765432109876543210
Output: 1219326311370217952237463801111263526900
Exponentiation:

makefile
Copy code
Input: 12345678 ^ 2
Output: 152415765279684
Contributing
Contributions are welcome! If you have any suggestions, improvements, or bug fixes, please create a pull request or open an issue.

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Make your changes.
Commit your changes (git commit -m 'Add some feature').
Push to the branch (git push origin feature-branch).
Create a new Pull Request.
License
This project is licensed under the MIT License - see the LICENSE file for details.

