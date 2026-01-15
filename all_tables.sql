-- ============================================
-- SQL Script: Electricity Bills + Employee Tables
-- Save as: all_tables.sql
-- Execute in Oracle / MySQL
-- ============================================

-- ===============================
-- 1️⃣ ELECTRICITY BILL TABLE
-- ===============================
DROP TABLE IF EXISTS elect_bill;

CREATE TABLE elect_bill (
    rr_number VARCHAR(10),
    consumer_name VARCHAR(25),
    billing_date DATE,
    units NUMBER(4),
    amount NUMBER(6,2),
    due_date DATE
);

-- Insert 10 records
INSERT INTO elect_bill VALUES ('A1001','Manjunath', TO_DATE('12-02-2014','DD-MM-YYYY'), 34, NULL, NULL);
INSERT INTO elect_bill VALUES ('B1190','Reeta', TO_DATE('14-02-2014','DD-MM-YYYY'), 128, NULL, NULL);
INSERT INTO elect_bill VALUES ('C1234','Nithin', TO_DATE('09-02-2014','DD-MM-YYYY'), 234, NULL, NULL);
INSERT INTO elect_bill VALUES ('B2345','Porinitha', TO_DATE('13-02-2014','DD-MM-YYYY'), 150, NULL, NULL);
INSERT INTO elect_bill VALUES ('A1988','Jairun Vahra', TO_DATE('23-02-2014','DD-MM-YYYY'), 277, NULL, NULL);
INSERT INTO elect_bill VALUES ('A2458','Solanki', TO_DATE('12-02-2014','DD-MM-YYYY'), 289, NULL, NULL);
INSERT INTO elect_bill VALUES ('A3459','Patilss', TO_DATE('15-02-2014','DD-MM-YYYY'), 178, NULL, NULL);
INSERT INTO elect_bill VALUES ('B3765','Lashasurni', TO_DATE('13-02-2014','DD-MM-YYYY'), 176, NULL, NULL);
INSERT INTO elect_bill VALUES ('A4790','Lakshmon', TO_DATE('16-02-2014','DD-MM-YYYY'), 299, NULL, NULL);
INSERT INTO elect_bill VALUES ('B4801','Ramesh', TO_DATE('18-02-2014','DD-MM-YYYY'), 160, NULL, NULL);

-- Compute amount
-- Minimum charge = 50
UPDATE elect_bill SET amount = 50;
-- For units > 100
UPDATE elect_bill
SET amount = 50 + 100*4.5 + (units - 100)*5.5
WHERE units > 100;
-- For units <= 100
UPDATE elect_bill
SET amount = 50 + units*1.5
WHERE units <= 100;
-- Due date = billing_date + 15 days
UPDATE elect_bill SET due_date = billing_date + 15;

-- View electricity bills
SELECT * FROM elect_bill;

-- =================================
-- 2️⃣ DEPARTMENT AND EMPLOYEE TABLES
-- =================================
DROP TABLE IF EXISTS employee;
DROP TABLE IF EXISTS department;

-- Create Department table
CREATE TABLE department (
    dept_id NUMBER(2),
    dept_name VARCHAR2(20),
    supervisor VARCHAR2(20)
);

-- Insert department data
INSERT INTO department VALUES (01,'Purchase','Ameen');
INSERT INTO department VALUES (02,'Accounts','Krishna Reddy');
INSERT INTO department VALUES (03,'Sales','Tanveer FGC');
INSERT INTO department VALUES (04,'Apprentice','Ashish Mehra');

-- Create Employee table
CREATE TABLE employee (
    emp_id NUMBER(4),
    dept_id NUMBER(2),
    emp_name VARCHAR2(25),
    emp_salary NUMBER(5),
    bonus NUMBER(5)
);

-- Insert employee data
INSERT INTO employee VALUES (1009,01,'Aren Gupta',25000, NULL);
INSERT INTO employee VALUES (1045,02,'Priya Rao',27500, NULL);
INSERT INTO employee VALUES (1034,02,'Vanshidhar',23700, NULL);
INSERT INTO employee VALUES (1067,03,'Anup Kaul',36000, NULL);
INSERT INTO employee VALUES (1058,04,'Hari Prasad',29000, NULL);
INSERT INTO employee VALUES (1029,03,'Anil Goul',29350, NULL);
INSERT INTO employee VALUES (1044,02,'Harsha Shenoy',52000, NULL);
INSERT INTO employee VALUES (1030,03,'Surya',14500, NULL);
INSERT INTO employee VALUES (1022,04,'Keerth',37900, NULL);
INSERT INTO employee VALUES (1055,01,'Rohit',31000, NULL);

-- Compute bonus = 5% of salary
UPDATE employee SET bonus = emp_salary * 0.05;

-- =================================
-- 3️⃣ SQL Queries / Reports
-- =================================

-- 3.1 Employees in Accounts department
SELECT emp_name FROM employee
WHERE dept_id = (SELECT dept_id FROM department WHERE dept_name='Accounts');

-- 3.2 Count, min, max, avg salary in Accounts
SELECT COUNT(*) AS total_employees,
       MIN(emp_salary) AS min_salary,
       MAX(emp_salary) AS max_salary,
       AVG(emp_salary) AS avg_salary
FROM employee
WHERE dept_id = (SELECT dept_id FROM department WHERE dept_name='Accounts');

-- 3.3 Employees under a particular supervisor (example: Tanveer FGC)
SELECT emp_name
FROM employee
WHERE dept_id = (SELECT dept_id FROM department WHERE supervisor='Tanveer FGC');

-- 3.4 Departments with only one employee
SELECT dept_name
FROM department
WHERE dept_id IN (
    SELECT dept_id
    FROM employee
    GROUP BY dept_id
    HAVING COUNT(emp_id) = 1
);

-- 3.5 Increase salary of Sales department by 15%
UPDATE employee
SET emp_salary = emp_salary * 1.15
WHERE dept_id = (SELECT dept_id FROM department WHERE dept_name='Sales');

-- 3.6 Delete all employees in Apprentice department
DELETE FROM employee
WHERE dept_id = (SELECT dept_id FROM department WHERE dept_name='Apprentice');

-- =================================
-- END OF SCRIPT
-- =================================
