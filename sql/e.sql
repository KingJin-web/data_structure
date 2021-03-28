
-- 实验四 嵌套查询和组合、统计查询
-- 一 实验目的

-- （1）使学生掌握SQL Server查询分析器的使用方法，加深对Transact-SQL语言查询语句的理解

--  (2)熟练掌握数据查询的分组、统计、计算和组合的操作方法

-- 二  实验内容
--(1) 分组查询实验，该实验中包括分组条件表达，选择组件条件的表达方法

--(2) 使用函数查询的实验,该实验包括统计函数和分组统计函数的使用方法

--（3）组合 查询实验

--（4）计算和分组计算查询的实验

-- 三   实验步骤

-- 1  查询选修了“离散数学”的学生的学号和姓名
select sno, sname
from s
where sno in (select sno
from sc
where cno=  (select cno
from c
where  cname='离散数学'));

-- 2 查询课程号为“0206”、成绩高于张林的学生的学号和成绩。
select sno, grade
from sc
where cno='0101' and grade> (select grade
    from sc
    where cno='0101' and sno=(select sno
        From s
        Where sname='张林'));
-- 3 查询其他系中比计算机系某一学生年龄小的学生姓名和年龄。
select *
from s
where dept<>'计算机系' and age<(select max(age)
    from s
    where dept='计算机系');
-- 4 查询其他系中比计算机系（CS）所有学生年龄都小的学生姓名及年龄。
select *
from s
where dept<>'计算机系' and age<(select min(age)
    from s
    where dept='计算机系');
-- 5 查询和“孙祥新”的“数据库原理及应用”课程分数相同的学生的学号
select sno
from sc
where grade=(select grade
from s, sc, c
where s.sno=sc.sno and sc.cno=c.cno and c.cname='数据库原理及应用' and sname='孙祥新');
-- 6 查询所有选修了“0206”课程的学生姓名
select sname
from s
where sno in (select sno
from sc
where cno='0206');

-- 7 查询没有选修“0206”课程的学生姓名。

select sname
from s
where sno not in (select sno
from sc
where cno='0206');
-- 8 查询选修了全部课程的学生的姓名。
SELECT sname
FROM s
WHERE SNO IN ( SELECT SNO
FROM SC
GROUP BY SNO
HAVING COUNT(*)=( SELECT COUNT(*)
FROM c));
-- 9 查询选修了“计算机基础”课程的学生的平均成绩
select avg(grade) as 平均成绩
From sc
Where  sno  in 
(select sno
From sc
Where  cno= (select cno
From c
Where  cname='计算机基础')); 
-- 10 查询选修了“计算机基础”课程的比此课由平均成绩大的学生的学号和成绩。
select x.sno, x.grade
From sc as x
Where x.grade>( select avg(y.grade)
    From sc as y, c 
    Where c.cname='计算机基础') and x.cno=  (select cno
        From c
        Where  cname='计算机基础'); 
-- 11  查询年龄大于女同学平均年龄的男同学的姓名和年龄。
select sname, age
From s
Where sex='男' and age> (select avg(age)
    From s
    Where sex='女'); 

select * from s;
-- 12 列出各系学生的总人数，并按人数进行降序排列。
select dept , count(*) as total
From s
Group by dept
order by total desc;
-- 13  统计各系各门课程的平均成绩。
select  dept, cno, avg(grade) as 平均成绩 From s, sc Group by dept,cno 
-- 14 查询选修了“计算机基础”和“离散数学”的学生的学号和平均成绩。

select s1.sno, avg(grade)  as 平均分
From sc as s1
Where  '计算机基础'  in  (select cname
    From c
    Where  cno  in  (select s2.cno
    From sc as s2
    Where  s2.sno=s1.sno)) and '离散数学'  in  (select cname
    From c
    Where cno  in (select cno
    From sc as s3
    Where  s3.sno=s1.sno))
Group  by  s1.sno;

-- 15 查询选修了3门以上课程的学生的学号和姓名。

select sno, sname
from s
where sno in( select sc.sno
from sc
group by sc.sno
having count (*)>3)

select * from s;
select * from c;
select * from sc;


