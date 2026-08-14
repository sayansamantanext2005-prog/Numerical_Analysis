# Regula Falsi Method in C

## Problem

Solve the equation

\[
x - e^{-x} = 0
\]

using the **Regula Falsi (False Position) method**.

The program uses a `while` loop instead of a `do-while` loop.

---

## 1. Define the Function

Rewrite the equation as:

\[
f(x)=x-e^{-x}
\]

We need to find the value of `x` for which:

\[
f(x)=0
\]

---

## 2. Choose the Initial Interval

Take:

```text
a = 0
b = 1
```

Evaluate the function:

\[
f(0)=0-e^0=-1
\]

\[
f(1)=1-e^{-1}\approx0.63212
\]

Therefore:

\[
f(0)\times f(1)<0
\]

So, according to the Intermediate Value Theorem, there is at least one root in `[0, 1]`.

---

## 3. Regula Falsi Formula

The next approximation is calculated using:

\[
c=
\frac{a f(b)-b f(a)}
     {f(b)-f(a)}
\]

where:

- `a` = lower bound
- `b` = upper bound
- `c` = new approximation

---

## 4. Updating the Interval

After calculating `c`, evaluate `f(c)`.

If:

\[
f(a)f(c)<0
\]

then the root lies between `a` and `c`, so:

```c
b = c;
```

Otherwise:

```c
a = c;
```

This ensures that the root remains bracketed by `[a,b]`.

---

## 5. Stopping Condition

We use:

```c
fabs(f(c)) < 1e-6
```

as the convergence criterion.

Therefore, the iterations continue while:

```c
while (fabs(f(c)) >= tolerance)
```

When `|f(c)|` becomes smaller than `10^-6`, the approximation is sufficiently close to the root.

The final result is printed using:

```c
printf("%.5f", c);
```

which displays the answer to five decimal places.

---

## 6. Why Use a `while` Loop?

The program first calculates the initial value of `c`:

```c
c = (a * f(b) - b * f(a)) / (f(b) - f(a));
```

Then the `while` loop checks whether the approximation has converged:

```c
while (fabs(f(c)) >= tolerance)
```

Inside the loop:

1. Display the current iteration.
2. Check which side contains the root.
3. Update `a` or `b`.
4. Calculate the new `c`.
5. Check the convergence condition again.

This avoids using a `do-while` loop.

---

## 7. Algorithm

```text
START

Define f(x) = x - exp(-x)

Set:
    a = 0
    b = 1
    tolerance = 1e-6

Check:
    f(a) * f(b) < 0

Calculate:
    c = [a*f(b) - b*f(a)] / [f(b)-f(a)]

WHILE |f(c)| >= tolerance

    If f(a)*f(c) < 0
        b = c
    Else
        a = c

    Calculate new c using Regula Falsi formula

END WHILE

Print c to 5 decimal places

END
```

---

## 8. Result

The root of

\[
x-e^{-x}=0
\]

is approximately:

\[
\boxed{x=0.56714}
\]

---

## 9. Complexity

If `N` iterations are required:

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

Only a constant number of variables are used.

---

## 10. Compilation

Using GCC:

```bash
gcc main.c -o main -lm
```

Run:

```bash
./main
```

The `-lm` option links the mathematical library required for `exp()` and `fabs()`.
