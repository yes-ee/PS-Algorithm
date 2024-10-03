# [Silver V] I Could Have Won - 27584 

[문제 링크](https://www.acmicpc.net/problem/27584) 

### 성능 요약

메모리: 2156 KB, 시간: 4 ms

### 분류

브루트포스 알고리즘, 구현, 시뮬레이션, 문자열

### 제출 일자

2024년 10월 3일 14:55:15

### 문제 설명

<p>"We will be closing in about 5 minutes. Thank you for visiting the ICPC gym today."</p>

<p>With this announcement, Alice and Bob stopped playing their rock-paper-scissors marathon in the middle of the $10$th game. Each player scores a point if their throw beats the other player's throw. Each game was played by the <em>first-to-11</em> rule, meaning that whoever scores $11$ points first wins the game. Today, Bob narrowly defeated Alice by a single game; he scored 11 points first in five games, while Alice only scored 11 points first in four games.</p>

<p>After carefully inspecting how each game was played, however, Alice realized that she could have won more games than Bob if they played under slightly different rules, such as <em>first-to-5</em> or <em>first-to-8</em>, instead of the regular <em>first-to-11</em>.</p>

<p>Given the sequence of points scored by Alice and Bob, determine all values of $k$ such that Alice would have won more games than Bob under the <em>first-to-</em>$k$ rule.</p>

<p>Both Alice and Bob start with zero points at the beginning of a game. As soon as one player reaches $k$ points, that player wins the game, and a new game starts. Alice wins a game if she scores $k$ points before Bob does. Neither player wins the game if it's interrupted by the gym closing before either player reaches $k$ points.</p>

### 입력 

 <p>The single line of input consists of a string of uppercase letters "<code>A</code>" or "<code>B</code>", denoting who scored each point from the beginning of the rock-paper-scissors marathon. The length of the string is between $1$ and $2\,000$ letters, inclusive. "<code>A</code>" means Alice scored the point, "<code>B</code>" means Bob scored the point.</p>

### 출력 

 <p>On the first line, output the number of positive integers $k$ for which a <em>first-to-</em>$k$ rule would have made Alice win more games than Bob. If this number isn't zero, on the next line output all such values of $k$ in increasing order, separated by spaces.</p>

