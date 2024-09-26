# Repository for Coding Test

## GitHub에서 처음 원격 리포지토리를 만들 때
* git init //.git이 생성됨 -> .git 기준으로 원격 리포지토리와 연결됨
* git add .
* git branch -M main

* git config --global user.name github_username
* git config --global user.email github_email

* git commit -m "initial commit"
* git remote add origin https://github.com/username/MyFirstGit.git

* 본인의 토큰 번호가 있다면 토큰번호에 추가하고 없으면 "토큰번호@"는 삭제해서 진행
* git remote set-url origin https://토큰번호@github.com/username/MyFirstGit.git
* git push -u origin main

## 다른 사람의 GitHub에서 원격 리포지토리를 pull 받을 때
* 우선 main인 경우
* git pull origin main

* 다른 branch인 경우 ex. test
* git checkout -b test // test 브랜치를 로컬에 생성하고 이동
* git pull origin test // 원격 test 브랜치를 로컬로 가져옴

## 원격 Repository에 push 하기
* git branch // 우선 올바른 branch에 있는가 확인
* git add . // . 은 수정된 모든 파일을 추가한다는 의미
* git commit -m "text" // text에 원하는 message 입력
* git push origin branch // branch는 원격 리포지토리의 branch 이름

## Branch
* branch 이동
* git checkout test

* branch 생성
* git checkout -b test

* local branch를 origin으로 push
* git push origin test

## Pull Request를 했거나, 이전의 commit 메세지를 수정하고 싶을 때
* git rebase -i HEAD~3 // 3은 최근부터 3개의 commit을 가져온다는 의미, 다른 숫자로 변경 가능
* 그럼 본인이 선택했던 편집기로 commit 목록이 뜸
* 변경하고 싶은 commit 앞에 pick이라고 적혀있는걸 reword로 변경하고 편집기 종료
* 이제 reword로 변경한 commit들의 목록이 뜸
* 수정하고 편집기 종료하면 commit 메세지가 변경되어 있음