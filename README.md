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
* git checkout test

* branch 생성
* git checkout -b test

* local branch를 origin으로 push
* git push origin test