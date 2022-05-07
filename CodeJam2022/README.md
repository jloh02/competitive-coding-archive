# Google CodeJam 2022
Result: Qualified for Round 1
Highest Ranking: 1951 in Round 1B
Organized By: Google

Finally felt satisfied after playing. Competed on my off days from army. Couldn't participate in 1C because of  :(

## Qualification
Ranking: 3292
Points: 71/100

### Punch Cards
Points: 11/11

Simple "ascii drawing"/format/looping/procedural coding

### 3D Printing
Points: 13/13

Greedy algorithm with checks and hardcoding

### d1000000 
Points: 20/20

- Sort all dice
- Greedy algorithm, ignoring dice that have values that are too small to increment

### Chain Reaction
Points: 27/27

- Based on the limits, each node will only point to a smaller index node
- We can process from initiators by interating the nodes from the end to the start (similar to building a tree)
- We maintain a state `{maximum value, current sum}` for each node
- When we process each node, we do 3 steps
  1. "Absorb" the lowest value branch to become the main branch
  2. Update the current node's maximum value by either taking the highest value among all child branches or the current node's value (whichever is higher)
  3. Terminate all remaining child branches by summing their maximum values
- Eventually, we will reach the `0` node where we sum all the states and their respective values


## Round 1A
Ranking: 2159
Points: 56/100
Penalty Time: 2:09:40
Qualification Criteria: 56 | 1:12:41

### Double or One Thing
Points: 25/25

- Task: Duplicate any of the letters in a string to produce the lowest in lexicographical order
- Simplification: Duplicate all letters where the next different letter is after the current letter

### Equal Sum
Points: 31/31

- Interactive Task: Give 100 unique numbers. Judge will return another 100 numbers. Determine a set of numbers which sum to exactly half of the total sum of numbers 
- Produce a set of numbers that can create any number
- Solution: Give a set of numbers that can create any number below 10e9. When returning final output, subtract largest numbers until target sum is below 10e9. Print the numbers to hit final target
  - Proposed solution: Give all binary numbers
  - Solution used: Generate all numbers {10,20,30...90,100,200,300...10e9} + {1,2,4,8}. For remaining numbers, use up all big numbers less than 10e9


## Round 1B
Ranking: 1951
Points: 85/100
Penalty Time: 2:35:33
Qualification Criteria: 85 | 2:00:33

### Pancake Deque
Points: 25/25

Greedy Algorithm to take the lesser of the ends first

### Controlled Inflation
Points: 35/35

- Standard DP problem
- Observation: For each customer, only the highest and lowest value matters
- Return: Minimum number of presses required
- State: customer index, current air level
- Processing: Assess if bringing the air level to maximum then minimum or minimum to maximum results in lower change in air level and hence less presses

### ASeDatAb
Points: 25/40

NGL, I don't know what I was doing. I spammed solutions until I got points. 

- Using human logic, if the number of `1`s is more than 4, send all `1`s to invert all numbers
- For numbers less than 4, send that number of `1`s with remaining as `0`, the order shouldn't matter because of randomization