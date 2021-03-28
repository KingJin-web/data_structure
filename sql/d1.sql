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


insert into sc  values('09001101','0101',68);
insert into sc  values('09001101','0206',76);
insert into sc  values('09001103','0101',62);
insert into sc  values('09001104','0206',82);
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
insert into sc  values('09001108','0101',68);
insert into sc  values('09001109','0212',null);
insert into sc  values('09001109','0302',76);
insert into sc  values('09001110','0101',66);





-- 实验三  简单查询和连接查询
-- 1 实验目的
-- （1）使学生掌握SQL Server查询分析器的使用方法，加深对Transact-SQL语言查询语句的理解
-- （2）熟练掌握简单表的数据查询、数据排序和数据连接查询的操作方法
-- 2 实验内容
-- （1）简单查询操作：实验包括投影、选择条件表达、数据排序、使用临时表等
-- （2）连接查询操作：实验包括等值连接、自然连接、求笛卡儿积、一般连接、外连接、内连接、左连接、右连接和自连接等
-- 3实验步骤
-- 1、/查询计算机系学生的学号和姓名

select sno,sname from s where dept='计算机系'; 

-- 2、查询选修了课程的学生学号
select distinct(sno) from sc;

-- 3、查询选修课程号为0101的学生学号和成绩，并要求对查询结果按成绩降序排列，如果成绩相同则按学号升序排列
select sno,grade from sc where cno='0101' order by grade desc,sno asc;

-- 4、查询选修课程号为0101的成绩在65-70分之间的学生学号和成绩，并将成绩乘以系数0.8输出
select sno,grade*0.8 as 'sore' from sc where cno='0101' and grade between 80 and 90;

-- 5、查询信息管理系或计算机系姓张的学生的信息
select * from s where dept in ('信息管理系','计算机系') and sname like '张%' ;

-- 6、查询缺少了成绩的学生的学号和课程号
select sno,cno from sc where grade is null; 

-- 7、查询每个学生的情况以及他（她）所选修的课程
select s.*,c.cname from s,sc,c where s.sno=sc.sno and sc.cno=c.cno; 

-- 8、查询学生的学号、姓名、选修的课程名及成绩
select s.sno,sname,cname,grade from s,sc,c where s.sno=sc.sno and sc.cno=c.cno;

-- 9、查询选修数学课程且成绩为90分以上的学生学号、姓名及成绩
select s.sno,sname,grade from s,sc,c where s.sno=sc.sno and sc.cno=c.cno  and cname='数学' and grade>=90;

select s.sno,sname,grade from s,sc,c where s.sno=sc.sno and sc.cno=c.cno  and cname like '%数学' and grade>=70;

-- 10、查询每一门课的间接先行课（即先行课的先行课）。
select first.cno,second.pcno from c as first,c as second where first.pcno=second.cno; 

select c1.cname as 先行课 ,c1.cname as 间接先行课 from c c1,c c2 where c1.pcno = c2.cno;



