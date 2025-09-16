# Repository for Coding Test

## GitHub First Init
* git init
*  //.git 폴더가 생성됨
* git add .
* git branch -M main

* git config --global user.name github_username
* git config --global user.email github_email

* git commit -m "initial commit"
* git remote add origin https://github.com/username/MyFirstGit.git
* git remote set-url origin https://토큰번호@github.com/username/MyFirstGit.git
* git push -u origin main

## GitHub clone
* git clone https://github.com/username/OtherGit.git
* git pull

## Pull repository
* git pull origin main

## Push Something to repository
* git branch
* //you should check your branch before push
* git add .
* //if you want add exact file, replace . to your file name
* git commit -m "text"
* git push origin main(the name of branch)

## Branch
* branch 이동
* git checkout <name>

* branch 생성
* git checkout -b <name>

* local branch를 origin으로 push
* git push origin <name>

# Algorithm

Algorithm study for online coding test 코딩 테스트 대비 알고리즘 공부

https://www.youtube.com/c/BaaarkingDog
https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook/0x03.md

//////////////////////////////////

competition website

https://www.acmicpc.net/

https://programmers.co.kr/

https://groom.io/

https://swexpertacademy.com/

https://codeforces.com/

etc...

//////////////////////////////////


Time Complexity(시간복잡도) : the computational complexity that describes the amount of computer time it takes to run an algorithm. 입력의 크기와 문제를 해결하는데 걸리는 시간의 상관관계

Big-O Notation(빅오표기법) : mathematical notation that describes the limiting behavior of a function when the argument tends towards a particular value or infinity. 주이진 식을 값이 가장 큰 대표항만 남겨서 나타내는 방법

e.g. O(N)    : 5N + 3, 2N + 10lgN, 10N
     O(N^2)  : N^2 + 2N + 4, 6N^2 + 20N + 10lgN
     O(NlgN) : NlgN + 30N + 10, 5NlgN + 6
     O(1)    : 5, 16, 36
     
O(1) < O(lgN) < O(N) < O(NlgN) < O(N^2) < O(2^N) < O(N!)!

![image](https://user-images.githubusercontent.com/50208536/172078061-b48904e6-81fa-412c-b634-a779a436d1fb.png)

By Madison Stankevich (Dev.to) https://dev.to/madisonstankevich/big-o-notation-a-brief-overview-for-the-beginner-1o13


Space Complexity(공간복잡도) : the amount of memory space required to solve an instance of the computational problem as a function of characteristics of the input. 입력의 크기와 문제를 해결하는데 걸리는 공간의 상관관계

