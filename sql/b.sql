-- ① 创建院系信息表Dept_info代码
CREATE TABLE Dept_info
(
    dno char(4) primary key ,
    dname char(16) not null,
    d_chair char(8),
    d_address varchar(50),
    tel char(12)
)
--② 创建班级信息表Class_info代码
CREATE TABLE Class_info
(
    classno char(4) primary key ,
    classname char(16) not null,
    monitor char(8),
    instructor char(8),
    tel char(12),
    dno char(4),
    foreign key(dno) 
    REFERENCES Dept_info(dno)
)

--③ 创建学生信息表Student_info代码
CREATE TABLE Student_info
(
    sno char(8) primary key ,
    sname char(8) not null,
    sex char(2),
    s_native varchar(50),
    birthday smalldatetime,
    dno char(4),
    classno char(4),
    entime smalldatetime,
    home varchar(50),
    tel char(12),
    foreign key (dno) REFERENCES Dept_info(dno),
    foreign key (classno) REFERENCES Class_info(classno)
)

-- ① 向数据表S中插入记录(’S13’,’吕淑霞’,19,’女’,’CS’)
INSERT INTO S
    (sno,sname,age,sex,sdept)
VALUES('S13', '吕淑霞', 19, '女', 'CS')

INSERT into C
    (cno,cname)
VALUES('C10', '电子商务')

-- ② 吕淑霞同学选修了“电子商务”这门课，期未的考试成绩为95分，SQL语句如下
INSERT INTO SC
    (sno,cno,grade)
VALUES('S13', 'C10', 95)

INSERT INTO SC
    (sno,cno)
VALUES('S13', 'C9')

--③ 修改吕淑霞同学“电子商务”的成绩为90。
UPDATE SC SET GRADE=90 WHERE SNO='S13' AND CNO='C10'

--④ 在表SC中删除学号为’S13’和课号’C10’的记录。
DELETE FROM SC WHERE sno='S13' and cno='C10'

--3. 数据表结构的修改
--① 为学生表“S”中年龄“age”字段增加约束，限制年龄在15岁到30岁之间（包括15岁和30岁）。
ALTER TABLE S  ADD CONSTRAINT CON_age CHECK(age>=15 and age<=30)

--② 在学生表“S”中增加班级字段“class”为可变字符串类型（varchar），长度为20。
ALTER TABLE S ADD class varchar(20)


--③ 修改学生表“S”中的“class”字段的长度为50。
ALTER TABLE S ALTER COLUMN class varchar(50)

--④ 删除学生表“S”中的“class”字段。
ALTER TABLE S DROP COLUMN class 


--4．查看数据表信息 
--(1) 查看指定表“S”的空间大小等信息。
EXEC sp_spaceused 'S'

--(2) 查看所有用户表的空间表大小等信息。
EXEC sp_MSforeachtable "exec sp_spaceused '?'"  


SELECT *FROM S;
SELECT *FROM C;
SELECT *FROM SC;
