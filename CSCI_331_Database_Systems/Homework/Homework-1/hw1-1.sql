-- 1
-- Return orders placed in June 2015
-- Tables involved: TSQLV4 database, Sales.Orders table

USE [Northwinds2022TSQLV7];														-- Specify to use TSQLv4 Database
SELECT OrderId, OrderDate, CustomerId, EmployeeId								-- Returns selected columns
FROM [Sales].[order]															-- Specify which table to query
WHERE orderdate >= '2015-06-01' AND orderdate <= '2015-06-30';					-- Orders placed in June 2015 (2015-06-01 to 2015-06-30)