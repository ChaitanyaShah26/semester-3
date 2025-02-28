/*
	customer(c_no, c_name, c_add, c_age)
	loan(c_no, l_no, loan_amt, l_date)
	1.	Create a view which includes the customer name whose loan amount is between 50000 and 100000.
	2.	Find the customer name from view whose loan amount is less than 80000.
	3.	Find the customer name whose name ends with letter ‘m’ and taken a loan amount as 90000.
*/

create database Experiment6;
use Experiment6;

create table customer (
	c_no int PRIMARY KEY,
c_name varchar(50) NOT NULL,
c_add varchar(150) NOT NULL,
c_age int NOT NULL
);

create table loan (
	c_no int references customer(c_no),
l_no int PRIMARY KEY,
loan_amt int NOT NULL,
l_date varchar(10)
);

insert into customer values(1, 'Alice Johnson', '123 Maple St, Springfield', 28);
insert into customer values(2, 'Bob Smith', '456 Oak Ave, Shelbyville', 34);
insert into customer values(3, 'Charlie Brown', '789 Pine Rd, Capital City', 22);
insert into customer values(4, 'Diana Prince', '101 Elm St, Gotham', 30);
insert into customer values(5, 'Edward Elric', '202 Birch Ln, Central City', 26);
insert into customer values(6, 'Adam', '200 Birch Ln, Central City', 28);
select * from customer;

insert into loan values(1, 10001, 40000, '10/10/2023');
insert into loan values(2, 10002, 75000, '12/11/2023');
insert into loan values(3, 10003, 50000, '01/12/2023');
insert into loan values(4, 10004, 90000, '04/12/2023');
insert into loan values(5, 10005, 200000, '29/12/2023');
insert into loan values(6, 10006, 90000, '04/01/2024');
select * from loan;

-- Query 1
create view customer_loan_data
as (
	select c.c_no, c.c_name, l.loan_amt
    from customer c, loan l
    where (c.c_no=l.c_no) AND (l.loan_amt between 50000 and 100000)
);
select * from customer_loan_data;

-- Query 2
select c_name
from customer_loan_data
where loan_amt<80000;

-- Query 3
select c_name
from customer_loan_data
where (loan_amt=90000) AND (c_name like '%m');