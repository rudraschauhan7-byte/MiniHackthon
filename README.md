# Personal Expense Tracker

A small menu-driven program in **C** that helps you record your expenses, sort them into categories, and check them against a monthly budget.

Built for a mini hackathon.

---

## The problem it solves

Students spend small amounts all month (snacks, rides, printouts) and often can't say where the money went. By the end of the month the allowance is gone. This program makes it quick to log each expense and shows exactly how much was spent, where, and how much is left.

---

## What it can do

- Set a **monthly budget** when the program starts
- **Add expenses** (up to 100) with an amount and a category
- Sort every expense into one of **4 categories**:
  1. Food
  2. Travel
  3. Books
  4. Entertainment
- Show a **summary**:
  - total spending
  - remaining budget
  - total for each category
  - the category where you spent the most
- Print a **warning** if you spend more than your budget
- Reject bad input (zero or negative amounts, categories outside 1 to 4)

---

## How to run it

You need a C compiler such as GCC.

1. Save the code as `expense_tracker.c`
2. Compile it:
   ```
   gcc expense_tracker.c -o expense_tracker
   ```
3. Run it:
   - Linux or Mac: `./expense_tracker`
   - Windows: `expense_tracker.exe`

---

## How to use it

1. Enter your monthly budget when asked.
2. Pick an option from the menu:

   | Option | What it does |
   |---|---|
   | 1 | Add an expense |
   | 2 | Display the expense summary |
   | 3 | Exit |

3. To add an expense, type the amount, then the category number (1 to 4).

### Example

```
Enter your monthly budget: 5000

===== Personal Expense Tracker =====
1. Add Expense
2. Display Expense Summary
3. Exit
Enter your choice: 1
Enter expense amount: 450
Select category:
1. Food
2. Travel
3. Books
4. Entertainment
Enter category: 2
Expense added successfully.
```

Summary output:

```
===== Expense Summary =====
Monthly Budget: 5000.00
Total Spending: 450.00
Remaining Budget: 4550.00

===== Category-wise Totals =====
Food: 0.00
Travel: 450.00
Books: 0.00
Entertainment: 0.00

Highest Expenditure Category: Travel
Budget Status: Within budget
```

---

## How the code works

The program has three parts.

### `main()`
- Reads the budget.
- Shows the menu again and again until you choose **3** (a `do-while` loop).
- Calls the right function for your choice.

### `addExpense()`
1. Stops if 100 expenses are already stored.
2. Reads the amount and rejects it if it is 0 or less.
3. Reads the category and rejects it if it is not 1 to 4.
4. Saves the expense and increases the counter.

### `displaySummary()`
1. Goes through all expenses and adds each one to the total and to its category's total.
2. Finds the category with the highest total.
3. Works out the remaining budget (budget minus total).
4. Prints everything, with a warning if the budget is exceeded.

### How the data is stored

Two arrays work side by side. Position `i` in both describes the same expense:

| i | amount[i] | category[i] |
|---|-----------|-------------|
| 0 | 120.50 | 1 (Food) |
| 1 | 450.00 | 2 (Travel) |

A counter, `count`, tracks how many expenses are stored.

---

## C concepts used

| Concept | Where it is used |
|---|---|
| Arrays | storing amounts, categories and category totals |
| Functions | `addExpense` and `displaySummary` |
| Pointers | `int *count`, so a function can change the counter in `main` |
| Loops | the `do-while` menu and the `for` loops for totals |
| Input validation | amount above 0, category from 1 to 4 |
| Constants (`#define`) | `MAX` and `CATEGORIES` |

---

## Flowchart

```
Start
  |
Enter budget
  |
Show menu, read choice <-----------+
  |                                |
  +-- 1: Add expense --------------+
  +-- 2: Show summary -------------+
  +-- other: Invalid choice -------+
  +-- 3: Exit
        |
       End
```

---

## Known limitations

- Data is **not saved**. Everything is lost when you close the program.
- If you type a **letter** where a number is expected, the menu can loop forever (the `scanf` return value is not checked).
- An invalid amount or category sends you back to the menu instead of asking again.
- Expenses cannot be edited or deleted, and the budget cannot be changed after it is entered.

## Ideas for the future

- Save and load expenses from a file
- Edit and delete expenses
- Check `scanf` results to handle wrong input safely
- Weekly and monthly reports
- A graphical or web interface

---

## Team

- [Team name]
- [Member names]

Made for [Hackathon name], 2026.
