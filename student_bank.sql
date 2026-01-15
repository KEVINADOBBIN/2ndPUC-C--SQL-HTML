-- ============================================
-- SQL Script: Student Database + Bank Transactions
-- File: student_bank.sql
-- Execute in Oracle / MySQL
-- ============================================

-- =================================
-- 1️⃣ STUDENT DATABASE
-- =================================

-- Drop table if exists
DROP TABLE IF EXISTS student_master;

-- Create student_master table
CREATE TABLE student_master (
    student_id NUMBER(4) PRIMARY KEY,
    student_name VARCHAR2(50),
    sub1_marks NUMBER(3),
    sub2_marks NUMBER(3),
    sub3_marks NUMBER(3),
    sub4_marks NUMBER(3),
    sub5_marks NUMBER(3),
    sub6_marks NUMBER(3),
    total_marks NUMBER(3),
    perc NUMBER(5,2),
    result VARCHAR2(10)
);

-- Insert sample student data
INSERT INTO student_master VALUES (101,'Amit', 45, 56, 67, 78, 89, 90, NULL, NULL, NULL);
INSERT INTO student_master VALUES (102,'Priya', 35, 42, 50, 60, 70, 80, NULL, NULL, NULL);
INSERT INTO student_master VALUES (103,'Ravi', 25, 33, 40, 20, 30, 50, NULL, NULL, NULL);
INSERT INTO student_master VALUES (104,'Sneha', 60, 70, 80, 75, 85, 90, NULL, NULL, NULL);

-- Compute total marks
UPDATE student_master
SET total_marks = sub1_marks + sub2_marks + sub3_marks + sub4_marks + sub5_marks + sub6_marks;

-- Compute percentage
UPDATE student_master
SET perc = (total_marks / 600) * 100;  -- Assuming 6 subjects, max 100 each

-- Compute result as PASS (all subjects >= 35)
UPDATE student_master
SET result = 'PASS'
WHERE sub1_marks >= 35 AND sub2_marks >= 35 AND sub3_marks >= 35
  AND sub4_marks >= 35 AND sub5_marks >= 35 AND sub6_marks >= 35;

-- Compute result as FAIL (any subject < 35)
UPDATE student_master
SET result = 'FAIL'
WHERE sub1_marks < 35 OR sub2_marks < 35 OR sub3_marks < 35
  OR sub4_marks < 35 OR sub5_marks < 35 OR sub6_marks < 35;

-- View all student records
SELECT * FROM student_master;

-- View only student id and name
SELECT student_id, student_name FROM student_master;

-- List students who passed
SELECT * FROM student_master WHERE result = 'PASS';

-- List students who failed
SELECT * FROM student_master WHERE result = 'FAIL';


-- =================================
-- 2️⃣ BANK CUSTOMER & TRANSACTION DATABASE
-- =================================

-- Drop tables if exist
DROP TABLE IF EXISTS bank;
DROP TABLE IF EXISTS customer;

-- Create customer table
CREATE TABLE customer (
    cno NUMBER(4) PRIMARY KEY,
    name VARCHAR2(50),
    caddress VARCHAR2(50),
    ophone CHAR(12)
);

-- Insert sample customers
INSERT INTO customer VALUES (1,'Amit Kumar','Delhi','9876543210');
INSERT INTO customer VALUES (2,'Priya Rao','Mumbai','9123456780');
INSERT INTO customer VALUES (3,'Ravi Sharma','Chennai','9988776655');

-- Create bank transactions table
CREATE TABLE bank (
    acc_no NUMBER(6) NOT NULL,
    trans_amount NUMBER(8,2) CHECK (trans_amount >= 0),
    trans_date DATE,
    tr_type CHAR(1),  -- C=Credit, D=Debit
    cno NUMBER(4),
    FOREIGN KEY (cno) REFERENCES customer(cno)
);

-- Insert sample bank transactions
INSERT INTO bank VALUES (100001, 5000, TO_DATE('12-01-2026','DD-MM-YYYY'),'C',1);
INSERT INTO bank VALUES (100002, 2000, TO_DATE('13-01-2026','DD-MM-YYYY'),'D',1);
INSERT INTO bank VALUES (100003, 10000, TO_DATE('14-01-2026','DD-MM-YYYY'),'C',2);
INSERT INTO bank VALUES (100004, 1500, TO_DATE('15-01-2026','DD-MM-YYYY'),'D',3);

-- View customer table
SELECT * FROM customer;

-- View bank transactions
SELECT * FROM bank;

-- Delete a customer (example cno=3)
-- DELETE FROM customer WHERE cno=3;

-- Delete bank table
-- DROP TABLE bank;
