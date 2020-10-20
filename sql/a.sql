--创建学员信息数据表
use StudentManageDB
go
 if exists(select * from sysobjects where name='Students')
drop table Students
go
create table Students
(
    StudentId int identity(10000,1),--学号
    StudentName varchar(20) not null,--姓名
    Gender char(2) not null,--性别
    Birthday datetime not null,--出生日期
    StudentIdNo numeric(18,0) not null,--身份证号
    Age int not null,--年龄
    PhoneNumber varchar(50),
    StudentAddress varchar(500),
    ClassId int  not null   --班级外键
)
go
--创建班级表
if exists(select * from sysobjects where name='StudentClass')
drop table StudentClass
go
create table StudentClass
(
    ClassId int primary key,--班级编号
    ClassName varchar(20) not null
)
go
--创建成绩表
if exists(select * from sysobjects where name='ScoreList')
drop table ScoreList
go
create table ScoreList
(
    Id int identity(1,1) primary key,
    StudentId int not null,--学号外键
    CSharp int null,
    SQLServer int null,
    UpdateTime datetime not null--更新时间
)
go
--创建管理员表
if exists(select * from sysobjects where name='Admins')
drop table Admins
go
create table Admins
(
    LoignId int identity(1000,1) primary key,
    LoginPwd varchar(20) not null,--登录密码
    AdminName varchar(20) not null
)
go