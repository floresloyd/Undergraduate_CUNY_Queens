-- 8 
-- Calculate row numbers for orders
-- based on order date ordering (using order id as tiebreaker)
-- for each customer separately
-- Tables involved: Sales.Orders table

-- Arranges all of the customers orders by puting it to row 1 ... n
-- Arranged by date

USE [Northwinds2022TSQLV7]																										-- Use TSQLv4 DB			
SELECT CustomerId, OrderDate, OrderId, ROW_NUMBER() OVER (PARTITION BY CustomerId ORDER BY OrderDate, OrderId) AS RowNumber		--ROW_NUMBER (counts rows), --OVER (how we count the rows), We cout it by grouping all cust id orders together
FROM Sales.[Order]																									
ORDER BY CustomerId, RowNumber;																								    -- Sorting by custid so customer 1 goes first and rownumber to see all orders in a cronological order		
