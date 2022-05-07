# NOI Singapore 2020
Determined to get a silver in my second competitive coding competition. Due to the COVID-19 pandemic, the competition had a qualifier where the top 30 participants competed onsite. For the qualifier, we were allowed to use our own devices, IDE and offline materials from home. 

## Overview
Award: Silver Medal
Points: 154
Ranking: 44
Organized By: National University of Singapore

## Solutions (Qualifier)
### 1. Crypto
Points: 100/100

#### Problem Analysis
We are given a series of numbers. We need to find the lexicographical order of the numbers - 1 being when all numbers are sorted.

#### Solution
We first sort all the numbers to get the first series in the lexicographical order. 

It is easier to use a smaller example than dive right in. Let's use a simple example `3 2 4 1`. The sorted form of `3 2 4 1` is `1 2 3 4`.

##### Human Solve
We can get our answer by iterating the numbers in lexicographical order
```
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
```
Therefore the answer is **16**.


##### Analysis of the Human Method
To get the lexicographical order, we simply count the orders before that. 

The first 12 records can be calculated by multiplying the available numbers prior to the desired value `3` with the number of available permutations of the remaining digits.

We shall let the first part of this multiplication be `x`, and the second part `y!`.

`x` simply calculated by the number of numbers already used that are less than the current value - in this case, no numbers are used so `x = 2`. `y!` is the factorial of the number of remaining slots.
```
orders before "X x x x" = (numbersUsed)*(digitsLeftToProcess!)
orders before "3 x x x" = 2*(3!) = 12
```

We can repeat this for the next 2 records `3 1 2 4` and `3 1 4 2`. `3` has been used but is not less than `2`. Only `1` is less than `2`, so `x = len({1}) = 1`. Clearly, we only have `2` digits left.
```
orders before "3 2 x x" = (1)*(2!) = 2
```

Finally, we come to the last record to eliminate - `3 2 1 4`. Numbers `3` and `2` have already been used, leaving us with `1`. Hence, `x = len({1}) = 1`. `y` is just `1` with `1` digit remaining.
```
orders before "3 2 4 x" = 1*1 = 1
```

Summing them all together gives 15. We add 1 to account for the final answer case, giving us **16**!

##### Coding & Optimization
Writing this in code is as hard as it is to understand the above analysis. Below are some concepts and optimizations I used to solve the challenge.

**Conversion**
Since the numbers are not given from 1 to N, we should simply sort the numbers and use the sorted index for each number rather than the number itself. In fancier shorter terms - discretize each number for ease of calculation.

This way, we can truly treat each number as 0,1,2,3,4...

**Finding x**
To quickly find the numbers used that are less than the current value, we use a fenwick tree, where the index determines if a value has been used. We initialize all values to 1. Once a number has been used we set it to 0. We can then use the fenwick tree to sum from the first index to the current index.

**Easy y!**
Since the limit for the number of numbers is 300000, we can simply generate/precompute the first 300000 factorials modulus 1000000007 and save them into an array for ease of access.

**Modulus**
The answer is required to be `% 1000000007`. This is simple as only multiplication and addition are used. Thus, we can perform our modulus as and when we want after each operation.

**Subtask 3**
To cater for subtask 3, we add an extra boolean to output `1` if the numbers are strictly increasing and `n % 1000000007` if the numbers are strictly decreasing

### 2. Fule Station
Points: 49/100

- Sort the fuel stops in order
- Write a function to determine if we can reach the end
- Brute force iterate from 1 to total distance

### 3. Relay
Points: 5/100

Used Dijkstra and brute forced the solution.