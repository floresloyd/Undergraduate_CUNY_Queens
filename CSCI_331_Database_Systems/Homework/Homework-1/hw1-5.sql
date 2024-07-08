-- 5
-- Write a query against the HR.Employees table that returns employees
-- with a last name that starts with a lower case letter.
-- Remember that the collation of the sample database
-- is case insensitive (Latin1_General_CI_AS).
-- For simplicity, you can assume that only English letters are used
-- in the employee last names.
-- Tables involved: Sales.OrderDetails table

USE [Northwinds2022TSQLV7]															-- Use this database
SELECT EmployeeId, EmployeeLastName 												-- Return empid and last name
FROM HumanResources.Employee													    -- From this table
WHERE ascii(left(EmployeeLastName, 1)) between ascii('a') and ascii('z');			-- If the first letter in their name is small caps (ascii a-z)