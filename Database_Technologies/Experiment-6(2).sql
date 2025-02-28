/*	Triggers	*/

create database Expt6_Triggers;
use Expt6_Triggers;

create table Employee (
	e_id int PRIMARY KEY,
e_name varchar(50) NOT NULL,
e_sal int
);

create table audit (
	emp_id int,
emp_name varchar(50),
emp_sal int,
	audit_action varchar(100),
audit_date date
);

insert into Employee values(1, 'Alice Johnson', 75000);
insert into Employee values(2, 'Bob Smith', 62000);
insert into Employee values(3, 'Charlie Brown', 85000);
insert into Employee values(4, 'Diana Prince', 78000);
insert into Employee values(5, 'Mark McGann', 96000);
select * from Employee;


DELIMITER //
create trigger audit_trigger after insert on Employee
for each row
BEGIN
DECLARE emp_id int;
    DECLARE emp_name varchar(50);
    DECLARE emp_sal int;
    DECLARE audit_action varchar(100);

    SET emp_id = NEW.e_id;
    SET emp_name = NEW.e_name;
    SET emp_sal = NEW.e_sal;
    SET audit_action = 'New Record Inserted';

	insert into audit values(emp_id,emp_name,emp_sal,audit_action,now());
END;
//

insert into Employee values(6,"Chaitanya",5000);
select * from Employee;
select * from audit;


DELIMITER //
create trigger audit_trigger_delete after delete on Employee
for each row
BEGIN
	DECLARE emp_id int;
    DECLARE emp_name varchar(50);
    DECLARE emp_sal int;
    DECLARE audit_action varchar(100);

    SET emp_id = OLD.e_id;
    SET emp_name = OLD.e_name;
    SET emp_sal = OLD.e_sal;
    SET audit_action = 'Record Deleted';

	insert into audit values(emp_id,emp_name,emp_sal,audit_action,now());
END;
//

delete from Employee where e_id=2;
select * from Employee;
select * from audit;

DELIMITER //
create trigger audit_trigger_update after update on Employee
for each row
BEGIN
	DECLARE emp_id int;
    DECLARE emp_name varchar(50);
    DECLARE emp_sal int;
    DECLARE audit_action varchar(100);

    SET emp_id = NEW.e_id;
    SET emp_name = NEW.e_name;
    SET emp_sal = NEW.e_sal;
    SET audit_action = 'Record Updated';

	insert into audit values(emp_id,emp_name,emp_sal,audit_action,now());
END;
//

update Employee set e_sal=80000 where e_id=4;
select * from Employee;
select * from audit;