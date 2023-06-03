# DS-and-OOP

- **Instructor : 詹力韋**
- **Semester : 2022 Spring**

## Grade

- **Lab 20%**
- **HW 25% （OOP: 15%, DS: 10%）**
- **Midterm（Paper: 20%）**
- **Final Exam（Paper: 20%）**

## HW1 (OOP)

Dungeon Game

## HW2 (DS)
### Part 1. Superhero's Power Grid
>You are a superhero who needs to build a power grid to supply energy to your super-powered equipment in your city. There are n power stations in your city, connected by power lines, and the cost to supply power between each pair of stations is different. Your task is to connect all power stations with the minimum possible cost.

**Description**
1. Requirement<br>
Your task is to connect all power stations with the minimum possible cost. All  power stations are guaranteed to be connected.

2. Input / Output<br>
    Input:<br>
    - The number of power stations in the city N (2 ≤ N ≤ 1000).
    - The cost to supply power between each pair of stations, represented as a list of tuples (u, v, w), where u and v are the indices of the stations (0-based indexing) and w is the cost of supplying power between them (1 ≤ w ≤ 10^6).<br>
    
    Output:<br>
    - Output the minimum total cost of connecting all power stations.
```
Example Input:
5
0 1 5
0 2 2
2 1 1
0 3 6
1 3 3
1 4 7
3 4 2

Example output:
8
```
**Constraint**
- You are required to implement it in C++.
- You are free to use any C++ standard library.
- 2 ≤ N ≤ 1000
- 1 ≤ w ≤ 10^6


### Part 2 Shortest Time Between the Cities
**Introduction**

>In NYCU town, there are n cities and m roads between any of the two cities. All the cities are connected as a graph. To calculate the time you need when traveling between any two cities, you are given a road width w and t*3 edge weights representing the travel time for truck, car and bike modes between the towns. The time between two cities is bidirectional, which means the time from city A to city B equals the time from city B to city A. If there is no given edge between the two cities, it means we cannot pass the two cities directly. Also, you are given the three transportation size, s1, s2, s3. In each road, the transportation size must be smaller than or equal to the road width or this transportation is not able to pass by. 

Given p testcases, you have to measure the shortest time from city A to city B.

 

**Description**
1. Requirement
You need to find the shortest time and shortest path from city A to city B.


2. Input / Output
Input
The first line of input files contains two integers representing the number of nodes(n) and edges(m) in the graph.<br>
The following m lines represent the edge information. Each line contains six integers: start city(a), end city(b), road width(w), the transportation time for a truck(t1), the transportation time for a car(t2), and the transportation time for a bike(t3). The city ID starts from 1.
Then, there will be a line with the size of a truck, a car and a bike, and the size of p testcases.
In the last p lines, we will have two city index for the begin and the end.

In each line, all the input integers will be separated by space.
```
Example Input:
5 5		// n, m
1 2 3 1 4 5	// nodeA, nodeB, road width, time for truck, car, and bike
2 3 2 2 4 6
3 4 5 1 1 1
4 5 3 1 3 4 
2 5 8 2 2 2 
10 5 1	// size of truck, car, and bike
3		// p test cases
1 2 
1 5 
2 4


Example output:
5
7
6
```
**Constraint**
- You are required to implement it in C++.
- You are free to use any C++ standard library.
- All the input data here are integers.
- 1 ≤ n ≤ 500
- 1 ≤ m ≤ 1000
- 1 ≤ w < 100. 
- 1 ≤ t1, t2, t3 < 100. 
- 1 ≤ s1, s2, s3 < 100. 
- 1 ≤ p ≤ 100