-- 4 
-- Return orders with total value(qty*unitprice) greater than 10000
-- sorted by total value
-- Tables involved: Sales.OrderDetails table

USE [Northwinds2022TSQLV7]										-- Use this Database
SELECT OrderId, SUM(Quantity * UnitPrice) as totalvalue			-- Return to me OrderID and the (Qty * UnitPrice) as totalvalue
FROM Sales.OrderDetail											-- From this table
GROUP BY orderid												-- Group order ID's together
HAVING SUM(Quantity * UnitPrice) > 10000						-- Return only the totalvalue > 10,000
ORDER BY totalvalue DESC;										-- Sort by highest to lowest
