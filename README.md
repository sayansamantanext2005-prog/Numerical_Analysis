# Sum of the Infinite Series

## Problem

Find the sum of the infinite series correct to **five decimal places**:

\[
e^{-x} = 1 - x + \frac{x^2}{2!} - \frac{x^3}{3!} + \frac{x^4}{4!} - \cdots
\]

The program is written in **C**.

---

## Algorithm

The direct calculation of each term using powers and factorials would be inefficient because we would repeatedly calculate `x^i` and `i!`.

Instead, calculate every term from the previous term.

Let the current term be:

\[
T_{i-1} = \frac{(-x)^{i-1}}{(i-1)!}
\]

Then:

\[
T_i = \frac{(-x)^i}{i!}
\]

Therefore,

\[
T_i
= T_{i-1}\times\frac{-x}{i}
\]

So the next term can be generated using only one multiplication and one division.

### Steps

1. Read the value of `x`.
2. Initialize:
   - `sum = 1`
   - `term = 1`
   - `i = 1`
3. Calculate the next term using:

   ```text
   term = term * (-x) / i
   ```

4. Add the term to `sum`.
5. Continue until:

   ```text
   |term| < 1e-10
   ```

6. Print the result using five digits after the decimal point.

---

## Why `1e-10`?

The required answer is correct to five decimal places.

The rounding threshold for five decimal places is:

\[
\frac{1}{2}\times10^{-5}=5\times10^{-6}
\]

We use the much smaller tolerance:

\[
10^{-10}
\]

Thus, the terms are continued until their contribution is extremely small compared with the required precision.

Also, `printf("%.5f", sum)` controls the **display precision**; it does not itself improve the mathematical accuracy of the series.

---

## Example

### Input

```text
2
```

### Series

\[
e^{-2}
=1-2+\frac{2^2}{2!}-\frac{2^3}{3!}+\frac{2^4}{4!}-\cdots
\]

### Output

```text
e^(-2.00000) = 0.13534
```

---

## Complexity

If `N` terms are required before the stopping condition is satisfied:

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

The algorithm does not store the individual terms.

---

## Important Note

This implementation is intended for ordinary finite values of `x`. For very large positive or negative values, floating-point overflow/underflow and cancellation can affect numerical accuracy.

## Compilation

Using GCC:

```bash
gcc main.c -o main -lm
```

Run:

```bash
./main
```
