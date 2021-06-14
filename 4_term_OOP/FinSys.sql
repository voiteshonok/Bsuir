create table Clients (
id INT NOT NULL identity(1, 1),
login varchar(20) NOT NULL,
password varchar(20) NOT NULL,
PRIMARY KEY (id)
);

INSERT INTO Clients (login,password,account_id)
VALUES ('Sla', 'Sla', 8)

SELECT *
FROM Clients


INSERT INTO Clients (login,password)
VALUES ('Jonh', 'Doe');

create table Employees (
id INT NOT NULL identity(1, 1),
login varchar(20) NOT NULL,
password varchar(20) NOT NULL,
PRIMARY KEY (id)
);

ALTER TABLE Clients
ADD account_id int NULL


INSERT INTO Employees (login,password)
VALUES ('Slav', 'Python');

SELECT *
FROM Employees


INSERT INTO Employees (login,password)
VALUES ('Pasha', 'Figasha');

INSERT INTO Employees (login,password)
VALUES ('Slav', 'Python');

SELECT *
FROM Employees
WHERE login = 'Slav' AND password = 'Python'

create table Requests (
id INT NOT NULL identity(1, 1),
client_id INT NOT NULL,
specification varchar(30) NOT NULL,
status varchar(30) NOT NULL,
time varchar(150) NOT NULL,
PRIMARY KEY (id),
FOREIGN KEY (client_id) REFERENCES Clients (id)
);

SELECT *
FROM Requests

INSERT INTO Requests (client_id, specification, status, time)
VALUES (1, 'first request', 'Pending', '12/10');

INSERT INTO Requests (client_id, specification, status, time)
VALUES (1, 'second request', 'Pending', '12/10');

INSERT INTO Requests (client_id, specification, status, time)
VALUES (1, 'third request', 'Pending', '12/10');

create table AcceptedRequests (
id INT NOT NULL identity(1, 1),
request_id INT NOT NULL,
employee_id INT NOT NULL,
time varchar(150) NOT NULL,
PRIMARY KEY (id),
FOREIGN KEY (request_id) REFERENCES Requests (id),
FOREIGN KEY (employee_id) REFERENCES Employees (id)
);

INSERT INTO AcceptedRequests (request_id, employee_id, time)
VALUES (1, 33, '12/10');

SELECT *
FROM AcceptedRequests

Select *
From Clients
Where id = 1

Update Requests
Set status = 'Pending'
Where id = 2

SELECT *
FROM Requests


SELECT * FROM Employees WHERE login='Slav'

Delete
From Requests
Where client_id = 1

create table Accounts (
id INT NOT NULL identity(1, 1),
sum INT NOT NULL,
PRIMARY KEY (id)
);

Select *
From Accounts

INSERT INTO Accounts (sum)
VALUES (55555);

SELECT SCOPE_IDENTITY()

Update Employees
Set account_id = 4
Where id = 2

select *
From Accounts 
Where id = 1

Select Employees.id, count(*)
From Employees
	left join
AcceptedRequests on Employees.id = AcceptedRequests.employee_id
where request_id is not null
Group by Employees.idvar


create table Boss (
id INT NOT NULL identity(1, 1),
login varchar(20) NOT NULL,
password varchar(20) NOT NULL,
account_id int NULL,
PRIMARY KEY (id)
);

Select *
From Boss

INSERT INTO Boss 
VALUES ('admin', 'admin', 5);


Select count(*)
From AcceptedRequests
Where employee_id = 0

create table Insurances (
id INT NOT NULL identity(1, 1),
spec varchar(100) NOT NULL,
type varchar(20) NOT NULL,
cost INT NOT NULL
);

INSERT INTO Insurances 
VALUES ('Bla Bla', 'YR', 150);

Select * 
From Insurances

INSERT INTO Insurances 
VALUES ('Bla PHIS', 'PHIS', 250);

ALTER TABLE Insurances
ADD info varchar(200) NULL

Update Insurances
Set info = 'standart'
Where id = 5