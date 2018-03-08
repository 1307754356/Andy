#	Github学习笔记
***
基础概念

##	工作区  ---   暂存区   ---  版本库  ---  远程仓库
###	Working Directory--Stage--Repository
##	1.	git status
>查看工作区，版本库中未添加或未提交的资料

##	2.    git add *filename.txt*

>用于将**工作区**的资料放入**暂存区**

##	3.    git commit -m"*comment*"
>将**暂存区**的资料放入版本库 
>>**注：未add到暂存区的文件不会提交**

##	4.	git checkout  -- *file*
>让这个文件回到最近一次**git commit**或**git add**时的状态
>
>也就是丢弃**file**在工作区的修改
>>注此处的**“--”**非常重要 

##	5.	git reset HEAD *file*
>把**暂存区**的修改撤销掉**（unstage）**，重新放回**工作区**
>
>此种情况适用于将错误修改add到了暂存区但仍未提交的时候
>>此时，会将暂存区的修改放回工作区，**然后在工作区的撤销可通过第四条实现**

##	6.	git log
>显示从最近到最远的**提交**日志(commit相当于存档)
>>*git log --pretty=oneline*写成这样就可以简化弹出的信息
>
>**git reset --hard HEAD^**可以让版本库调至上一版本（上一百个版本可以使用（ＨＥＡＤ～１００））
>
>配合 **git reflog（命令历史）**使用，可以方便地在版本之间穿梭
>> **git reset --hard** *版本号（输入前几位可供分辨即可）* 

##	7.	git rm *file*
>在工作区内删除一个文件后，使用**git status**可看到文件被删除，此时
>>**若想从版本库中删除**，则使用git rm *file*，然后提交，则此文件从版本库中删除
>
>>**若想保留此文件**，使用**git checkout -- file**来撤销工作区的修改

##	8.远程仓库
>####	关联仓库
>要关联一个远程库，使用命令**git remote add origin git@server-name:path/repo-name.git**
>> 举例：**git@github.com:1307754356/again.git**
>>>**again**是版本库名，**1307754356**是用户名，要注意最后的 **.git**

>关联后，使用命令**git push -u origin master**第一次推送master分支的所有内容

>此后，每次本地提交后，只要有必要，就可以使用命令**git push origin master**推送最新修改
>***
>####	克隆仓库
>要克隆一个仓库，使用命令 git clone git@github.com:michaelliao/gitskills.git
>>举例：**git clone git@github.com:1307754356/gitskills.git**

##	9.Branch
>####	创建分支
>查看分支：**git branch**

>创建分支：**git branch name**

>切换分支：**git checkout name**

>创建+切换分支：**git checkout -b name**

>合并某分支到当前分支：**git merge name**
>
>禁用Fast forward的合并（可保留分支信息）**git merge --no-ff -m "merge with no-ff" dev**

>删除分支：**git branch -d name**
>***
>####	解决冲突
>>在分支（举例dev），**dev在版本1上做了修改，master在版本1上做了另一种修改，则此时合并会产生冲突**

>>**（具体描述后续补充）**
>
>     
        	<<<<<<< HEAD
		Creating a new branch is quick & simple.
		=======
		Creating a new branch is quick AND simple.
		>>>>>>> feature1
>手动修改后，即可合并
>>**git log --graph --pretty=oneline --abbrev-commit**可查看简化树状合并图
>***
>####	储存现场
>####	**git stash**
>
>可以把当前工作现场“储藏”起来，等以后恢复现场后继续工作
>
>恢复现场首先应切换至储存的分支，然后使用**git stash list**查看列表

>一是用git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除

>另一种方式是用git stash pop，恢复的同时把stash内容也删了

>也可以多次stash，然后使用 git stash apply stash@{num}
>>num指stash的序号
>***
>####	删除未合并分支
>git会提示The branch 'xxx' is not fully merged.
>此时只需要 git branch -D xxx  就可以强制删除
>***
>####	远程推送分支
>**git push origin dev**
>
>就可以把这个分支推送到远程仓库
##	10.多人协作
>git diff *file*可查看现在的文件和版本库中文件的区别

（未完待续）
