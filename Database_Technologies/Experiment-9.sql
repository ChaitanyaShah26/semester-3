create database Experiment9;
use Experiment9;

create table customercleaned (
	customer_idint,
first_namevarchar(50),
last_namevarchar(50),
    country varchar(50),
    email varchar(100)
);

select * from customercleaned;