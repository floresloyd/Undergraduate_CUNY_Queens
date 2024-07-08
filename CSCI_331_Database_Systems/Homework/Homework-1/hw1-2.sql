-- 2 
-- Return orders placed on the last day of the month
-- Tables involved: Sales.Orders table

USE [Northwinds2022TSQLV7]												-- Use TSQLv4 Database
SELECT OrderId, OrderDate, CustomerId, EmployeeId						-- Return these columns. EOMONTH = END OF MONTH
FROM [Sales].[Order]													-- FROM sales.orders tableyyy
WHERE orderdate = EOMONTH(orderdate)
