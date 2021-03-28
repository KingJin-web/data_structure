Create database student
On primary
(name=student_data,
Filename='d:\sql\student_data.mdl',
Size=10mb,
Maxsize=50mb,
Filegrowth=1mb)
Log on
(name=student_log,
Filename='d:\sql\student_log.ldl',
Size=2mb,
Maxsize=5mb,
Filegrowth=1%)

create table s
(sno char(10) primary key,
sname char(10) not null,
age int ,
sex char(2),
dept varchar(50));

create table c
(cno char(10) primary key,
cname char(20) not null,
credit float,
pcno varchar(20),
describe varchar(100));

create table sc
(sno char(10) ,
cno char(10), 
grade float,
primary key(sno,cno),
foreign key(sno)references s(sno),
foreign key(cno)references c(cno));

insert into s  values('09001101','张林',18,'男','计算机系');
insert into s  values('09001102','程明',18,'男','计算机系');
insert into s  values('09001103','王艳',19,'女','计算机系');
insert into s  values('09001104','严平平',20,'女','计算机系');
insert into s  values('09001105','王洪敏',19,'女','信息管理系');
insert into s  values('09001106','孙祥新',18,'男','信息管理系');
insert into s  values('09001107','吕占英',19,'女','信息管理系');
insert into s  values('09001108','李义',19,'男','机械工程系');
insert into s  values('09001109','牟万里',18,'男','机械工程系');
insert into s  values('09001110','刘丽霞',20,'女','机械工程系');
insert into s  values('09001111','张小林',18,'男','计算机系');


insert into c  values('0101','计算机基础',5,'0101','可自学');
insert into c  values('0102','C++程序设计',4,'null','可自学');
insert into c  values('0206','离散数学',4,'0102','可自学');
insert into c  values('0208','数据结构',4,'0101','可自学');
insert into c  values('0209','操作系统',4,'0101','可自学');
insert into c  values('0210','微机原理',5,'0101','可自学');
insert into c  values('0211','图形学',3,'0102','可自学');
insert into c  values('0212','数据库原理',4,'0102','可自学');
insert into c  values('0301','计算机网络',3,'0102','可自学');
insert into c  values('0302','软件工程',3,'0102','可自学');


insert into sc  values('09001101','0211',68);
insert into sc  values('09001101','0206',76);
insert into sc  values('09001103','0211',62);
insert into sc  values('09001104','0206',82);
insert into sc  values('09001104','0208',82);
insert into sc  values('09001104','0212',82);
insert into sc  values('09001105','0212',82);
insert into sc  values('09001106','0209',75);
insert into sc  values('09001106','0102',71);
insert into sc  values('09001106','0206',75);
insert into sc  values('09001106','0301',79);
insert into sc  values('09001106','0101',84);
insert into sc  values('09001106','0302',62);
insert into sc  values('09001106','0211',78);
insert into sc  values('09001106','0212',null);
insert into sc  values('09001106','0210',87);
insert into sc  values('09001106','0208',82);
insert into sc  values('09001108','0211',68);
insert into sc  values('09001109','0212',null);
insert into sc  values('09001109','0302',76);
insert into sc  values('09001110','0211',66);






-- 实验三  简单查询和连接查询
-- 1 实验目的
-- （1）使学生掌握SQL Server查询分析器的使用方法，加深对Transact-SQL语言查询语句的理解
-- （2）熟练掌握简单表的数据查询、数据排序和数据连接查询的操作方法
-- 2 实验内容
-- （1）简单查询操作：实验包括投影、选择条件表达、数据排序、使用临时表等
-- （2）连接查询操作：实验包括等值连接、自然连接、求笛卡儿积、一般连接、外连接、内连接、左连接、右连接和自连接等
-- 3实验步骤
-- 1、/查询计算机系学生的学号和姓名
-- 2、查询选修了课程的学生学号
-- 3、查询选修课程号为0101的学生学号和成绩，并要求对查询结果按成绩降序排列，如果成绩相同则按学号升序排列
-- 4、查询选修课程号为0101的成绩在65-70分之间的学生学号和成绩，并将成绩乘以系数0.8输出
-- 5、查询信息管理系或计算机系姓张的学生的信息
-- 6、查询缺少了成绩的学生的学号和课程号
-- 7、查询每个学生的情况以及他（她）所选修的课程
-- 8、查询学生的学号、姓名、选修的课程名及成绩
-- 9、查询选修数学课程且成绩为90分以上的学生学号、姓名及成绩
-- 思考题：
-- （1）用语句查询时，如何提高数据查询和连接速度
-- （2）对于常用的查询形式或查询结果，怎样处理较好
-- 10、查询每一门课的间接先行课（即先行课的先行课）。


-- 实验四 嵌套查询和组合、统计查询
-- 一 实验目的

-- （1）使学生掌握SQL Server查询分析器的使用方法，加深对Transact-SQL语言查询语句的理解

--  (2)熟练掌握数据查询的分组、统计、计算和组合的操作方法

-- 二  实验内容
--   (1) 分组查询实验，该实验中包括分组条件表达，选择组件条件的表达方法

--   (2) 使用函数查询的实验,该实验包括统计函数和分组统计函数的使用方法

--   （3）组合 查询实验

--   （4）计算和分组计算查询的实验

-- 三   实验步骤

-- 1  查询学分是5分的学生的学号和姓名

select sno ,sname from s where sno in (select sno from sc where cno in (select cno from c where credit =5));
-- 2 查询课程号为“0206”、成绩高于张林的学生的学号和成绩。
select sno, grade
from sc
where cno='0206' and grade> (select grade
    from sc
    where cno='0206' and sno=(select sno
        From s
        Where sname='张林'));
-- 3 查询其他系中比计算机系某一学生年龄小的学生姓名和年龄。
select *
from s
where dept<>'计算机系' and age<(select max(age)
    from s
    where dept='计算机系');
select * from s;
-- 4 查询其他系中比计算机系（CS）所有学生年龄都小的学生姓名及年龄。
select *
from s
where dept<>'计算机系' and age<(select min(age)
    from s
    where dept='计算机系');
-- 5 查询和“孙祥新”的“数据结构”课程分数相同的学生的学号
select sno
from sc where grade in (select grade from s, sc, c where s.sno=sc.sno and sc.cno=c.cno and c.cname='数据结构' and sname='孙祥新');
-- 6 查询所有选修了“数据结构”课程的学生姓名
select sname
from s
where sno  in (select sno
from sc
where cno= (select cno from c where cname ='数据结构' ));

-- 7 查询没有选修“数据结构”课程的学生姓名。
select sname
from s
where sno not in (select sno
from sc
where cno= (select cno from c where cname ='数据结构' ));

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

-- 10 查询选修了“图形学”课程的比此课由平均成绩大的学生的学号和成绩。
select x.sno, x.grade
From sc as x
Where x.grade>( select avg(y.grade)
    From sc as y, c 
    Where c.cname='图形学') and x.cno=  (select cno
        From c
        Where  cname='图形学'); 
-- 11  查询年龄小于男同学平均年龄的女同学的姓名和年龄。
select sname, age
From s
Where sex='女' and age< (select avg(age)
    From s
    Where sex='男');

	select * from s;
-- 12 列出各系学生的总学分，并按总学分进行降序排列。
select s.dept,count(credit) as 总学分  from s,sc,c 
where s.sno = sc.sno and sc.cno = c.cno group by s.dept order by count(credit) desc;

	select * from s;
-- 13  统计各系各门课程的平均成绩。
select  dept, cno, avg(grade) as 平均成绩 from s, sc group by dept,cno 
-- 14 查询选修了“图形学”或“离散数学”的学生的学号和平均分。
select s1.sno, avg(grade)  as 平均分
from sc as s1
where  '图形学'  in  (select cname
    from c
    where  cno  in  (select s2.cno
    from sc as s2
    where  s2.sno=s1.sno)) or '离散数学'  in  (select cname
    from c
    where cno  in (select cno
    from sc as s3
    where  s3.sno=s1.sno))
group  by  s1.sno;


select * from s;
select * from c;
select * from sc;

-- 15 查询选修了3门以上课程的学生的学号和姓名。

select sno, sname
from s
where sno in( select sc.sno
from sc
group by sc.sno
having count (*)>3);

select * from s;
select * from c;
select * from sc;