## 📌 Project Overview

This project implements the concept of **Transitive Relations** from Discrete Mathematics using the C programming language.

A relation on a set can be represented using a **relation matrix**, where each element of the matrix is either `0` or `1`.

### Features

- Takes the set size as input.
- Supports set sizes `2` and `3`.
- Generates all possible relations.
- Represents each relation using a matrix.
- Checks whether each relation is transitive.
- Counts the total number of transitive relations.
- Displays the final count.

---

## 📚 What is a Relation?

Let `A` be a set.

A relation `R` on `A` is a subset of:

`A × A`

where `A × A` is the Cartesian product of `A` with itself.

For example, if:

`A = {a, b}`

then:

`A × A = {(a,a), (a,b), (b,a), (b,b)}`

Each ordered pair can either belong to the relation or not belong to the relation.

Therefore, every possible relation can be represented using `0` and `1`.

---

## 🔄 What is a Transitive Relation?

A relation `R` is called **transitive** if:

> If `(a,b) ∈ R` and `(b,c) ∈ R`, then `(a,c) ∈ R`.

In simple words, if `a` is related to `b`, and `b` is related to `c`, then `a` must also be related to `c`.

### Example

Suppose:

`(a,b) ∈ R`

and:

`(b,c) ∈ R`

Then, for the relation to be transitive:

`(a,c) ∈ R`

must also be true.

If `(a,c)` is missing, then the relation is **not transitive**.

---

## 🎯 Project Objectives

The main objectives of this project are:

1. To understand the concept of relations.
2. To represent relations using matrices.
3. To generate all possible relations for a small set.
4. To check the transitive property of each relation.
5. To count the total number of transitive relations.
6. To apply Discrete Mathematics concepts using C programming.

---

## 💻 Programming Language

This project is written in:

**C**

---

## 🧠 How the Program Works

The program follows several steps to find the number of transitive relations.

### Step 1: Take Set Size

The program asks the user to enter the size of the set.

``c
printf("Enter set size (2 or 3): ");
scanf("%d", &n);
The program is designed for:

n = 2
n = 3
### Step 2: Calculate the Total Number of Relations

For a set containing n elements:

Number of ordered pairs = n × n

Every ordered pair can either be:

1 → Present in the relation
0 → Not present in the relation

Therefore, the total number of possible relations is:

2^(n × n)

The program calculates this using:

int total = 1 << (n * n);
Example for Set Size 2

If:

n = 2

then:

n × n = 2 × 2 = 4

Therefore:

Total relations = 2^4 = 16

So there are 16 possible relations.

Example for Set Size 3

If:

n = 3

then:

n × n = 3 × 3 = 9

Therefore:

Total relations = 2^9 = 512

So there are 512 possible relations.

### Step 3: Generate All Possible Relations

The program uses a loop to generate every possible relation:

for (int num = 0; num < total; num++)

For each value of num, a different binary pattern is generated.

For example, when there are 4 ordered pairs, possible binary patterns include:

0000
0001
0010
0011
0100
0101
...
1111

Each binary pattern represents one possible relation.

### Step 4: Create the Relation Matrix

The program creates a two-dimensional array:

int r[5][5] = {0};

This array is used to store the relation matrix.

The matrix is generated using:

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        r[i][j] = temp % 2;
        temp /= 2;
    }
}

Here:

1 means the ordered pair is present.
0 means the ordered pair is absent.
Example

A relation matrix can look like:

1 0
1 1
### Step 5: Check the Transitive Property

The program checks all possible combinations of i, j, and k.

The important condition is:

if (r[j][k] && !r[i][k]) {
    transitive = 0;
}

The program first checks whether:

r[i][j] = 1

Then it checks whether:

r[j][k] = 1

If both are true, r[i][k] must also be 1.

Therefore:

If r[i][j] = 1
and r[j][k] = 1
but r[i][k] = 0


then the relation is NOT transitive.

If no violation is found, the relation is considered transitive.

### Step 6: Count Transitive Relations

The variable:

int count = 0;

is used to store the number of transitive relations.

Whenever a relation is found to be transitive:

if (transitive)
    count++;

The count increases by 1.

At the end, the program displays:

printf("Transitive relations = %d\n", count);
## 🧩 Complete Source Code
#include <stdio.h>


int main() {
    int n;
    printf("Enter set size (2 or 3): ");
    scanf("%d", &n);


   int total = 1 << (n * n);
    int count = 0;


  for (int num = 0; num < total; num++) {
        int r[5][5] = {0};
        int temp = num;


   // Make relation matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[i][j] = temp % 2;
                temp /= 2;
            }
        }


   int transitive = 1;


   // Check transitivity
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (r[i][j]) {
                    for (int k = 0; k < n; k++) {
                        if (r[j][k] && !r[i][k]) {
                            transitive = 0;
                        }
                    }
                }
            }
        }


  if (transitive)
            count++;
    }


 printf("Transitive relations = %d\n", count);


return 0;
}
## ▶️ How to Compile and Run
Using GCC

Open a terminal or command prompt in the project directory.

Compile the program:

gcc transitive_relation.c -o transitive_relation
Windows
transitive_relation.exe
Linux / macOS
./transitive_relation
## 🖥️ Sample Input and Output
Example 1: Set Size 2

Input:

Enter set size (2 or 3): 2

Output:

Transitive relations = 13
Example 2: Set Size 3

Input:

Enter set size (2 or 3): 3

Output:

Transitive relations = 171
## 📈 Results
Set Size	Number of Ordered Pairs	Total Relations	Transitive Relations
2	4	16	13
3	9	512	171
## ⏱️ Time Complexity

For a set of size n:

Total number of relations = 2^(n²)

For each relation, the program checks three nested loops:

i, j, and k

Therefore, checking one relation takes approximately:

O(n³)

The overall time complexity is approximately:

O(2^(n²) × n³)

Because the number of possible relations grows very quickly, the program is mainly suitable for small set sizes such as 2 and 3.

## 💾 Space Complexity

The relation matrix is stored in:

int r[5][5];

For a set of size n, the matrix requires approximately:

O(n²)

space.

Therefore, the space complexity is:

O(n²)

## 🛠️ Concepts Used
C Programming Concepts
Variables
Data types
printf()
scanf()
Arrays
Two-dimensional arrays
Nested for loops
if statements
Boolean-style flags
Integer arithmetic
Modulo operator %
Division
Bit shifting
Discrete Mathematics Concepts
Sets
Cartesian Product
Ordered Pairs
Relations
Relation Matrix
Binary Representation
Transitive Relations
Mathematical Logic

## 📂 Project Structure
Transitive-Relations/
│
├── transitive_relation.c
│
└── README.md
transitive_relation.c

Contains the complete C source code for generating and checking transitive relations.

README.md

Contains the project documentation, explanation, usage instructions, and project information.

## 🎓 Academic Purpose

This project is created for educational purposes to demonstrate how a concept from Discrete Mathematics can be implemented using the C programming language.

The program connects mathematical theory with programming by:

Generating relations.
Representing them using matrices.
Checking the transitive property.
Counting the number of transitive relations.
## 🚀 Future Improvements

Possible improvements include:

Allowing larger set sizes.
Displaying every generated relation.
Displaying only the transitive relations.
Showing the relation matrix for each transitive relation.
Allowing the user to enter actual set elements.
Adding a menu-based interface.
Checking reflexive relations.
Checking symmetric relations.
Checking antisymmetric relations.
Checking transitive relations.
Determining whether a relation is an equivalence relation.
Creating a complete relation-property analyzer.

## 👨‍💻 Author

**Muhammad Adnan Sami**  
**Student ID:** 2025-3-60-152  
**Institution:** East West University  
**Email:** adnansamitngl5050@gmail.com
