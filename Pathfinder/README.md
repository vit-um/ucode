<p align="center">
    <a href="https://ucode.world/en/" target="_blank">
        <img src="../marathon_C/img/ucode_logo_minimal.png?raw=true" height="100px">
    </a>
    <h1 align="center">Ucode-PathFinder</h1>
    <br>
</p>

## Skills

Reasoning & Argumentation, Creativity, Communication, Critical Thinking, Problem Solving, Analysis, Innovation Thinking, Agility & Adaptability, Initiative, Responsibility, Self-Management, UNIX, Git, Procedural Programming, Algorithms, C

## Instalation:
0. Support OS: Ubuntu
1. Download code [here](.)
2. Default mode: `make` or `make all`
3. Silent debug mode: `make debug` (need main.c file)
4. File for use: pathfinder


## Task description

Create a program that finds all the shortest paths between all the islands, using informationabout the bridges that connect them. The program:
- reads data from a file. Its name is specified as a command-line argument
- finds all the shortest paths between each combination of two islands
- prints the paths using the FIFO (first) rule for the islands to the standard output.

### Input file description:
* the first line in the file is the number of islands
* the remaining lines describe the distance between the two islands, one per line. Eachline consists of two islands, the length of the bridge between them and a newline ina format:   
``island1-island2,length_of_bridge``:  
	+ the names of the islands contain only alphabetic characters and cannot be emptyor identical  
	+ the length of the bridge contains only numbers, cannot be empty and has a positivevalue  
	+ the sum of the lengths of all bridges in the file does not exceed ``INT_MAX``   

## [Go back](../README.md)
