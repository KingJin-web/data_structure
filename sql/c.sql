
CREATE TABLE s1
(
    sno char(9) PRIMARY KEY,
    sname char(10),
    sex char(2),
    age smallint,
    sdept varchar(50)
)

ALTER TABLE s1 ADD CONSTRAINT PK_son PRIMARY KEY CLUSTERED(sno)

drop table s1

CREATE TABLE s1
(
    sno char(9) NOT NULL PRIMARY KEY,
    sname char(8) NOT NULL CONSTRAINT S_sno UNIQUE,
    sex char(2),
    age smallint,
    sdept varchar(50)
)

CREATE TABLE s1
(
    sno char(9) NOT NULL PRIMARY KEY,
    sname char(8) NOT NULL CONSTRAINT S_sno UNIQUE,
    sex char(2),
    age smallint CHECK(age>=15 and age<=30),
    sdept varchar(50)
)



CREATE TABLE SC1
(
    sno char(9) NOT NULL,
    cno char(4) NOT NULL,
    GRADE REAL NULL,
    PRIMARY KEY(sno,cno),
    FOREIGN KEY(sno) REFERENCES s(sno),
    FOREIGN KEY(cno) REFERENCES s(cno),
)

