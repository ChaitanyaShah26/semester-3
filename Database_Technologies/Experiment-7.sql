/*	Procedures & Functions	*/

create database Expt_7;
use Expt_7;

create table Student (
	s_rollnoint PRIMARY KEY,
s_namevarchar(50) NOT NULL,
s_ageint,
s_addvarchar(100)
);
desc Student;

insert into Student values(1, 'John Doe', 20, '123 Maple Street, New York, NY 10001');
insert into Student values(2, 'Jane Smith', 21, '456 Oak Avenue, Los Angeles, CA 90001');
insert into Student values(3, 'Michael Johnson', 22, '789 Pine Road, Chicago, IL 60007');
insert into Student values(4, 'Emily Davis', 19, '321 Birch Lane, Houston, TX 77001');
select * from Student;

-- Procedure 1: Get Student Name using Roll No.
delimiter //
create procedure get_student_name(in student_rollnoint)
begin
	select s_name
    from Student
    where s_rollno=student_rollno;
end
//

call get_student_name(2);


-- Procedure 2: Insert Data in Student Table using Procedure
delimiter //
create procedure insert_student_data(in std_rollnoint, std_name varchar(50), std_ageint, std_add varchar(100))
begin
	insert into Student values(std_rollno, std_name, std_age, std_add);
end
//

call insert_student_data(5, 'Max Payne', 20, '123 Main St, Springfield, IL');
call insert_student_data(6, 'Keri Smith', 22, '456 Oak St, Rivertown, TX');
select * from Student;


-- Functions
-- Factorial Function
delimiter //
create function factofnum(numint)
returns int
deterministic
begin
	declare iint default 1;
    declare fact int default 1;
    while(i<=num) do
		set fact=fact*i;
        set i=i+1;
	end while;
    return fact;
end;
//

select factofnum(5);
