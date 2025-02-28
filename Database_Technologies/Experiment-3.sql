create database InventoryManagement;
use InventoryManagement;

create table products
(
	p_id int primary key,
	p_price int,
	p_expiry varchar(20)
);

create table provider
(
	pr_id int primary key,
	pr_type varchar(40),
	pr_address varchar(100)
);

create table warehouse
(
	w_no int primary key,
	w_capacity int,
	w_location varchar(100)
);

create table orders
(
	or_id int primary key,
	or_date varchar(16),
	or_time varchar(10)
);

create table sales
(
	s_number int primary key,
	s_type varchar(20),
	s_date varchar(16)
);

create table employee
(
	e_id int primary key,
	e_name varchar(50) not null,
	e_age int,
	e_experience int
);

create table customer
(
	c_id int primary key,
	c_name varchar(50) not null,
	c_contact int,
	c_age int
);

create table customer_care
(
	cc_id int primary key,
	cc_contact int,
	cc_location varchar(100)
);

create table offers
(
	o_no int primary key,
	o_name varchar(50),
	o_type varchar(20)
);

create table payment
(
	py_id int primary key,
	py_time varchar(10),
	py_date varchar(16),
	py_mode varchar(50) not null
);

create table online
(
	on_upi varchar(80),
	on_credit varchar(80),
	on_debit varchar(80)
);

create table offline
(
	off_cod varchar(80)
);


alter table products
	add pr_id int;
alter table products
	add constraint foreign key(pr_id) references provider(pr_id);

alter table products
	add c_id int;
alter table products
	add constraint foreign key(c_id) references customer(c_id);

alter table products
	add w_no int;
alter table products
	add constraint foreign key(w_no) references warehouse(w_no);


alter table orders
	add w_no int;
alter table orders
	add constraint foreign key(w_no) references warehouse(w_no);


alter table sales
	add e_id int;
alter table sales
	add constraint foreign key(e_id) references employee(e_id);


alter table customer
	add cc_id int;
alter table customer
	add constraint foreign key(cc_id) references customer_care(cc_id);


alter table customer_care
	add e_id int;
alter table customer_care
	add constraint foreign key(e_id) references employee(e_id);


alter table offers
	add c_id int;
alter table offers
	add constraint foreign key(c_id) references customer(c_id);


alter table payment
	add c_id int;
alter table payment
	add constraint foreign key(c_id) references customer(c_id);


alter table online
	add py_id int;
alter table online
	add constraint foreign key(py_id) references payment(py_id);

alter table offline
	add py_id int;
alter table offline
	add constraint foreign key(py_id) references payment(py_id);




desc products;
desc provider;
desc warehouse;
desc orders;
desc sales;
desc employee;
desc customer;
desc customer_care;
desc offers;
desc payment;
desc online;
desc offline;

insert into provider values(987654,'retail','Mumbai');
insert into provider values(654321,'wholesale','Mumbai');
insert into provider values(020202,'wholesale','Mumbai');
select * from provider;
delete from provider
  where pr_id=987654;
select * from provider;
update provider
  set pr_address='Pune';
select * from provider;
update provider
  set pr_address='Mumbai' 
  where pr_id=654321;
select * from provider;

insert into warehouse values(40105,2000,'Thane');
select * from warehouse;
delete from warehouse;
select * from warehouse;