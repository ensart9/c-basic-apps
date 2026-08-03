# 🏆 Competition Ranking System

A console-based competition ranking system developed in C using structures (struct), dynamic memory allocation, input validation, and the Bubble Sort algorithm.
---

# 📌 Features

- 👤 Store competitor information using `struct`
- 📝 Input validation for all user entries
- 🎯 Judge score validation (0.00 - 10.00)
- 📊 Performance score calculation
- 📈 Highest and lowest score detection
- 🔄 Dynamic memory allocation using `malloc()`
- 🥇 Ranking competitors using Bubble Sort
- 🏅 Display Top 3 competitors
- 📋 Display all competitors with detailed reports

---

# 🛠 Technologies Used

- C Programming Language
- Structures (`struct`)
- Dynamic Memory Allocation (`malloc`)
- Bubble Sort Algorithm
- Standard C Libraries

---

# ⚙️ How It Works

1. Enter the number of competitors.
2. Enter each competitor's:
   - First Name
   - Last Name
   - Country
   - Age
3. Enter scores from five judges.
4. The program:
   - Validates all inputs
   - Calculates the performance score
   - Determines the highest and lowest judge scores
5. Competitors are ranked using Bubble Sort.
6. The program displays:
   - 🥇 Top 3 Competitors
   - 📋 Complete Ranking List

---

# 🧮 Performance Calculation

The program calculates each competitor's performance score using the **trimmed mean** method.

```
Performance Score =
(Total Score − Highest Score − Lowest Score)
/ (Number of Judges − 2)
```

This method minimizes the impact of extremely high or low judge scores.

---

# 🔀 Sorting Algorithm

Competitors are sorted using the Bubble Sort algorithm.

Sorting Priority:

1. Performance Score
2. Highest Judge Score
3. Lowest Judge Score

---

# 🚀 Example Output

```
========== TOP 3 ==========

Rank 1

Competitor ID : 1
First Name    : Michael 
Last Name     : jordan
Country       : United States
Age           : 28
Performance   : 9.45
```
