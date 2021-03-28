create table s
(
    sno char(10) primary key,
    sname char(8) not null,
    age int ,
    sex char(2),
    dept varchar(50)
);

create table c
(
    cno char(10) primary key,
    cname char(20) not null,
    credit float,
    pcno varchar(20),
    describe varchar(100)
);

create table sc
(
    sno char(10) ,
    cno char(10),
    grade float,
    primary key(sno,cno),
    foreign key(sno)references s(sno),
    foreign key(cno)references c(cno)
);

insert into s
values('09001101', '张林', 18, '男', '计算机系');
insert into s
values('09001102', '程明', 18, '男', '计算机系');
insert into s
values('09001103', '王艳', 19, '女', '计算机系');
insert into s
values('09001104', '严平平', 20, '女', '计算机系');
insert into s
values('09001105', '王洪敏', 19, '女', '信息管理系');
insert into s
values('09001106', '孙祥新', 18, '男', '信息管理系');
insert into s
values('09001107', '吕占英', 19, '女', '信息管理系');
insert into s
values('09001108', '李义', 19, '男', '机械工程系');
insert into s
values('09001109', '牟万里', 18, '男', '机械工程系');
insert into s
values('09001110', '刘丽霞', 20, '女', '机械工程系');


insert into c
values('0101', '计算机基础', 5, '0101', '可自学');
insert into c
values('0102', 'C++程序设计', 4, 'null', '可自学');
insert into c
values('0206', '离散数学', 4, '0102', '可自学');
insert into c
values('0208', '数据结构', 4, '0101', '可自学');
insert into c
values('0209', '操作系统', 4, '0101', '可自学');
insert into c
values('0210', '微机原理', 5, '0101', '可自学');
insert into c
values('0211', '图形学', 3, '0102', '可自学');
insert into c
values('0212', '数据库原理', 4, '0102', '可自学');
insert into c
values('0301', '计算机网络', 3, '0102', '可自学');
insert into c
values('0302', '软件工程', 3, '0102', '可自学');



insert into sc
values('09001101', '0101', 68);
insert into sc
values('09001101', '0206', 76);
insert into sc
values('09001103', '0101', 62);
insert into sc
values('09001104', '0206', 82);
insert into sc
values('09001104', '0212', 82);
insert into sc
values('09001105', '0212', 82);
insert into sc
values('09001106', '0209', 75);
insert into sc
values('09001106', '0102', 71);
insert into sc
values('09001106', '0206', 75);
insert into sc
values('09001106', '0301', 79);
insert into sc
values('09001106', '0101', 84);
insert into sc
values('09001106', '0302', 62);
insert into sc
values('09001106', '0211', 78);
insert into sc
values('09001106', '0212', 98);
insert into sc
values('09001106', '0210', 87);
insert into sc
values('09001106', '0208', 82);
insert into sc
values('09001108', '0101', 68);
insert into sc
values('09001109', '0212', 88);
insert into sc
values('09001109', '0302', 76);
insert into sc
values('09001110', '0101', 66);


exec sp_addlogin login1,'123456'

exec sp_password '123456','abcd',login1

exec sp_grantdbaccess login1,login1_user


-- 1、建立	SQL SERVER身份验证的登录账户：log1,log2,log3
CREATE LOGIN log1 WITH PASSWORD='821742'
CREATE LOGIN log2 WITH PASSWORD='821742'
CREATE LOGIN log3 WITH PASSWORD='821742'
-- 2、用log1新建一个数据库引擎查询，此时在“可用数据库”下拉列表中选中student数据库。为什么？

-- 3、将log1,log2,log3映射为student数据库中的用户，用户名同登录名。
USE student

CREATE USER  log1 FOR LOGIN  log1
CREATE USER  log2 FOR LOGIN  log2
CREATE USER  log3 FOR LOGIN  log3

-- 4、在log1建立的数据库引擎查询中在“可用数据库”下拉列表中选中student数据库。此次能否成功，为什么？

-- 5、在log1建立的数据引擎查询中，执行下述语句能否成功，为什么？
select *
from c
-- 6、授予log1具有C表的查询权限，授予log2具有C表的插入权限
grant select on c to log1
grant insert on c to log2
-- 7、用log2建立一新的数据库引擎查询，然后执行下列语句能否成功？为什么？
Insert into c
values('0111', '计算机基础', '5', '0101', '可自学')
Insert into c
values('0112', 'C++程序设计', '4', 'null', '可自学')
-- 再次执行以下语句，能否成功，为什么？

select *
from c
-- 8、在log1建立的数据库引擎查询中再次执行下列语句，能否成功？为什么？
Select *
from c
-- 让log1 执行下列语句能否成功？为什么？
Insert into c
values('0113', 'C++程序设计', '4', 'null', '可自学')
-- 9、在student数据库中建立用户角色：robel,并将log1、 log2添加到此角色中

-- 10 授予robel具有C表插入、删除和查询的权限。
grant select on c to robel
grant insert on c to robel
grant delete on c to robel

-- 11、在log1建立的数据库引擎查询中，再执行以下语句，能否成功，为什么？

-- 12、在log2建立的数据库查询中，再次执行下列语句，能否成功，为什么？
Select *
from c
-- 13、在log3建立一个数据库引擎查询中，执行下列语句，能否成功，为什么？
Select *
from c 
-- 14、将log3添加到db_data reader角色中，并在log3建立的搜索引擎查询中再次执行下列语句，能否成功，为什么？
Select *
from c
-- 15在log3的搜索引擎查询中，执行下列语句，能否成功，为什么？
Insert into c
values('0114', 'C++程序设计', '4', 'null', '可自学')




-- （1）	查询每个学生的选课总学分，要求列出学生学号及总学分
create proc pr_1 as 
Select s.sno ,count(*) 选课门数 from s s LEFT OUTER join sc on s.sno=sc.sno    group by s.sno 

exec pr_1;
-- （2）	查询学生的学号、姓名、选课的课程号、课程名、课程学分，
--将学生所在系作为输入参数，默认值为‘计算机系’，执行此存储过程，并分
--别指定一些不同的输入参数
create proc pr_6  @s_dept char(20) = '计算机系' as
select s.sno,sname,c.cno,cname,credit
from s,c,sc
where s.sno=sc.sno and
sc.cno=c.cno and dept=@s_dept;
exec pr_6 '机械工程系';

-- （3）	查询指定系的男生人数，其中系为输入参数，人数为输出参数
create proc pr_3  @s_dept char(20) = '计算机系' as
 select count(sno) from s  where dept=@dept and sex='男' 

exec pr_3;
-- （4）	查询指定学生姓名的选课数和平均成绩，要求姓名为输入参数，
选课门数和平均成绩用输出参数返回
CREATE PROCEDURE pr_4 @s_name char(20)
AS
declare @s_count int
declare @s_avg real
SELECT  @s_avg = avg(grade) ,@s_count = count(cno)
FROM  sc,s where s.sno=sc.sno and sname=@s_name
print @s_name + '选修了' + convert(char(4) ,@s_count) + '门课程，
平均分：'+convert(char(4) , @s_avg)
exec pr_4 '严平平';
-- （5）	删除指定学生的选课记录，学号为输入参数。
CREATE PROCEDURE pr_5 @s_sno char(20) as
delete from s where sno = @s_sno;