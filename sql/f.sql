create table sc
(sno char(10) ,
cno char(10), 
grade float,
primary key(sno,cno),
foreign key(sno)references s(sno),
foreign key(cno)references c(cno));

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
insert into sc  values('09001106','0212',98);
insert into sc  values('09001106','0210',87);
insert into sc  values('09001106','0208',82);
insert into sc  values('09001108','0101',68);
insert into sc  values('09001109','0212',88);
insert into sc  values('09001109','0302',76);
insert into sc  values('09001110','0101',66);

-- a）	建立查询学生的学号、姓名、所在系、课程号、课程名、课程学分的图
create view v_1
as
    select s.sno, sname, dept, c.cno, cname, credit
    from s, c, sc
    where s.sno=sc.sno and
        sc.cno=c.cno

select *
from v_1;
-- b）	建立查询学生的学号、姓名、选修的课程和考试成绩的视图
create view v_2
as
    select s.sno, sname, c.cno, cname,sc.grade
    from s, c, sc
    where s.sno=sc.sno and
        sc.cno=c.cno

select *
from v_2;
-- c）	建立统计每个学生的课程门数，要求列出学生学号和选课门数。
select sno,count(*) as total from sc group by sno 
create view v_3 as
	select sno,count(*) as total from sc group by sno 
select * from v_3;
-- d）	建立统计每个学生的修课总学分，要求列出学生学号和总学分
create view v_4 as
  select sno,sum(credit) as total_credit from sc join c c on sc.cno=c.cno group by sno
 select * from v_4;
-- 利用建好的视图，完成如下查询
-- a)	查询考试成绩大于或等于70分的学生的姓名，课程名和成绩
select sname,cname,grade from v_2 where grade >= 70 
-- b)	查询选课门数超过3门的学生的学号和选课门数。
select * from v_3 where total >= 3 
-- c)	查询选修课总学分超过5分的学生的学号、姓名、所在系和修课总学分
select sname,dept,total_credit from v_4 join s on v_4.sno = s.sno where total_credit >= 5
-- d)	查询计算机系，选课门数超过3门学生的姓名和选课门数
(select * from v_3 where total >= 3 and sno  in (select sno from v_1 where dept = '计算机系' ) )
-- e)	5.查询在年龄大于或等于18岁的学生中，修课总学分超过5分的学生的姓名，年龄，所在系和修课总学分。
select sname,age,dept,total_credit   from v_4 join s s on s.sno = v_4.sno 
where age >= 18 and total_credit >= 5;
