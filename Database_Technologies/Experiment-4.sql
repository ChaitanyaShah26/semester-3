/*
	Employee (e_no, e_name, jobtitle, joindate, sal, d_no);
	Department (d_no, d_name)
	1.	Display the names of the employees whose department no. is 4
	2.	Find the names of the employees whose department name is ‘AI&DS’
	3.	Display the names of employees whose job title is manager
	4.	List all names and join date of employees whose name starts with letter ‘P’
	5.	List names of employees who earn more than 50000
	6.	List name of all employees who joined between 2020 and 2024
	7.	List all names and join date of employees whose name has letter e as the second letter
	8.	Display name of employees excluding job title CEO
	9.	Display employees in descending order of join date
	10.	Calculate average sal of department no. 5
	11.	Find the average salary of employees whose average salary is greater than 10000 and department no. is 2
*/

create database exp_4;
use exp_4;

create table department(
  d_no int PRIMARY KEY,
  d_name varchar(100) NOT NULL
);

create table Employees(
  e_no int PRIMARY KEY,
  e_name varchar(100) NOT NULL,
  jobtitle varchar(100),
  joindate int,
  sal int,
  d_no int references department(d_no)
);



insert into department values(1,'Computer');
insert into department values(2,'IT');
insert into department values(3,'AI&DS');
insert into department values(4,'DS');
insert into department values(5,'AI&ML');
select * from department;

insert into Employees values(1010,'Clark','CEO',2012,4000000,2);
insert into Employees values(1011,'Pearson','CFO',2012,4000000,2);
insert into Employees values(1050,'Harvey','COO',2012,3000000,1);
insert into Employees values(1100,'Louis','HR',2016,2000000,3);
insert into Employees values(1005,'Mike','Department Head',2011,1000000,3);
insert into Employees values(1080,'Donna','Director',2015,500000,4);
insert into Employees values(2050,'Rachel','Manager',2022,50000,4);
insert into Employees values(2100,'Harold','Manager',2024,40000,5);
insert into Employees values(2001,'Peter','Manager',2020,60000,1);
insert into Employees values(2023,'Steve','Manager',2021,64000,3);
insert into Employees values(2000,'Mabel','Manager',2020,50000,4);
insert into Employees values(2120,'Oliver','Employee',2024,25000,5);
insert into Employees values(2110,'Marissa','Employee',2024,25000,5);
select * from Employees;

select e_name
from Employees
where d_no = 4;

select e_name
from Employees e,department d
where e.d_no = d.d_no and d_name= 'AI&DS';

select e_name
from Employees
where jobtitle = 'Manager';

select e_name, joindate
from Employees
where e_name like 'P%';

select e_name, sal
from Employees
where sal>50000
order by sal desc;

select e_name
from Employees
where joindate between 2020 and 2024;

select e_name, joindate
from Employees
where e_name like '_e%';

select e_name
from Employees
where jobtitle != 'CEO';

select e_name, joindate
from Employees
order by joindate desc;

select avg(sal) as Average_Salary
from Employees
where d_no=5;

select avg(sal) as Average_Salary
from Employees
where d_no=2
group by d_no
having avg(sal)>10000;
