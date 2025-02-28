/*
	Employee (ename, street, city)
	Company (cname, city)
	Works (ename, cname, sal)
	Manages (ename, mgrname)
	1.	Find name and cities of all employees who work for Infosys
	2.	Find all employees who lives in the same city as their manager
	3.	Find all employees who earn more than every employee of TCS
	4.	Find the company that has smallest payroll
*/

create database Experiment5;
use Experiment5;

create table employee (
	enamevarchar(50) PRIMARY KEY,
    street varchar(20),
    city varchar(20)
);

create table company (
	cnamevarchar(50) PRIMARY KEY,
    city varchar(20)
);

create table works (
	salint,
	enamevarchar(50) references employee(ename),
cnamevarchar(50) references company(cname)
);

create table manages (
	mgrnamevarchar(50),
enamevarchar(50) references employee(ename)
);

insert into employee values("ABC","S.V.Road","Mumbai");
insert into employee values("XYZ","ShaniwarWada","Pune");
insert into employee values("KLM","S.V.P.Road","Mumbai");
insert into employee values("PQR","M.G.Road","Pune");
insert into employee values("DEF","M.G.Road","Bangalore");
insert into employee values("GHI","M.G.Road","Mumbai");
select * from employee;

insert into company values("Infosys","Mumbai");
insert into company values("TCS","Pune");
insert into company values("Google","Bangalore");
select * from company;

insert into works values(50000,"ABC","Google");
insert into works values(80000,"XYZ","Infosys");
insert into works values(40000,"KLM","TCS");
insert into works values(40000,"PQR","TCS");
insert into works values(500000,"DEF","Infosys");
insert into works values(500000,"GHI","Google");
select * from works;

insert into manages values("DEF","XYZ");
insert into manages values("GHI","ABC");
select * from manages;


-- Query1
SELECT e.ename, e.city
FROM employee e
JOIN works w ON e.ename = w.ename
WHERE w.cname = 'Infosys';

--  Query2
SELECT e.ename
FROM employee e
JOIN manages m ON e.ename = m.ename
JOIN employee mgr ON m.mgrname = mgr.ename
WHERE e.city = mgr.city;

--  Query3
SELECT e.ename
FROM works w
JOIN employee e ON w.ename = e.ename
WHERE w.sal> ALL (
    SELECT w2.sal
    FROM works w2
    WHERE w2.cname = 'TCS'
);

--  Query4
SELECT cname
FROM works
GROUP BY cname
HAVING sum(sal) <= ALL(
	SELECT sum(sal) 
    FROM works
    WHERE cname="Infosys"
);