# Homework Ex4_1 and Ex4_2

Solutions to **04_Operator Overloading.pdf**, pages **27–28**. Each exercise
is a separate program; compile the `.cpp` files within that exercise only.

## Ex4_1 — Fraction

Implements all requested operators: `+`, `-`, `*`, `/`, `>`, `<`, `==`, `>=`,
`<=`, `!=`, `=`, `+=`, `*=`, prefix/postfix `++` and `--`, `(float)`, `(int)`,
`>>`, and `<<`.

- Fractions are reduced with a positive denominator; zero becomes `0/1`.
- Input is two integers per fraction: `numerator denominator`. Output is `n/d`.
- Prefix increment/decrement changes the object and returns a reference to it;
  postfix returns its previous value. Each operation adds/subtracts one.
- Integer conversion truncates toward zero, e.g. `-7/2` becomes `-3`.
- A zero denominator, division by zero, or a reduced result outside the `int`
  range is rejected. Intermediate arithmetic uses `long long` for 32-bit ints.
- Invalid stream input sets `failbit` and leaves that destination unchanged.
- The default copy operations are sufficient because the class owns no dynamic
  memory.

The demo reads two fractions and demonstrates every requested operator. With
the supplied input, the sum, difference, product, and quotient are respectively
`5/4`, `-1/4`, `3/8`, and `2/3`.

## Ex4_2 — Array of integers

Implements all requested operators: concatenation `+`, `=`, `+=`, `[]`,
`(int*)`, `>>`, and `<<`.

- Owns a dynamically allocated `int[]` and implements the Big Three: destructor,
  copy constructor, and copy assignment. Copies have independent storage.
- `+` concatenates in order; `+=` appends, including when appending to itself.
- `[]` returns an element reference so `array[i] = value` works; a const overload
  supports reading const arrays. Invalid indices throw `std::out_of_range`.
- Pointer conversion exposes the existing storage. Do not delete the returned
  pointer; it becomes invalid when the array is destroyed or its storage is
  replaced by assignment, `+=`, or successful input. An empty array returns
  `nullptr`. Const arrays support conversion to `const int*`.
- Input is `length element1 element2 ...`; length zero represents an empty
  array. Output is `{1,2,3}`. Negative lengths or missing/noninteger elements
  fail input without changing that destination.

The demo reads two arrays and demonstrates all operators and deep copying.
The supplied input produces `{1,2,3,4,5}` for concatenation.

## Build and run (from the repository root)

Requires C++17 for `std::gcd`.

```bash
mkdir -p GPT_hw-Ex4_/Ex4_1/build GPT_hw-Ex4_/Ex4_2/build
g++ -std=c++17 -Wall -Wextra -Wpedantic GPT_hw-Ex4_/Ex4_1/*.cpp -o GPT_hw-Ex4_/Ex4_1/build/program
g++ -std=c++17 -Wall -Wextra -Wpedantic GPT_hw-Ex4_/Ex4_2/*.cpp -o GPT_hw-Ex4_/Ex4_2/build/program
./GPT_hw-Ex4_/Ex4_1/build/program < GPT_hw-Ex4_/Ex4_1/input.txt
./GPT_hw-Ex4_/Ex4_2/build/program < GPT_hw-Ex4_/Ex4_2/input.txt
```

On Windows, use the repository's existing VS Code build task with either
exercise's `main.cpp` open. That task reads the **root** `input.txt`; copy the
desired exercise's sample input there before running it.
