-- 3 
-- Return employees with last name containing the letter 'e' twice or more
-- Tables involved: HR.Employees table

USE [Northwinds2022TSQLV7]															-- USE TSQLv4 Database
SELECT EmployeeId, EmployeeFirstName, EmployeeLastName								-- Return these columns
FROM HumanResources.Employee														-- Querying from the HR.Employees table
WHERE LEN(EmployeeLastName) - LEN(REPLACE(EmployeeLastName, 'e', '')) = 2;			-- Where 'e' occurs twice in a last name.
																					--		Logic : Name - all letter e's. The difference is the number of e's
