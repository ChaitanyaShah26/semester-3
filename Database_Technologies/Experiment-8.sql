create database Experiment8;
use Experiment8;

create table Employee (
	e_idint PRIMARY KEY,
e_namevarchar(50),
e_salint
);
desc Employee;

-- Create Transaction & Commit (Value is permanently added to table): 
start transaction;
	insert into Employee values (1001, 'Max Payne', 6000000), (1002, 'Clark ', 6000000);
commit;
select * from Employee;

-- Rollback (Value is not updated in the table): 
start transaction;
	update Employee 
    set e_sal=8000000 
    where e_id=1002;
rollback;
select * from Employee;

-- Commit (Value is updated in the table): 
start transaction;
	update Employee 
    set e_sal=8000000 
    where e_id=1002;
commit;
select * from Employee;

-- Creating Checkpoints :
start transaction;
	update Employee
    set e_sal=5000000
    where e_id=10001;
	savepoint S1;

    delete from Employee where e_id=1001;
savepoint S2;
rollback to S1;