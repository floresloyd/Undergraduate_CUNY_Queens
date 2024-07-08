-- 6
-- Explain the difference between the following two queries

-- Query 1
USE [Northwinds2022TSQLV7]
SELECT EmployeeId, COUNT(*) AS numorders	-- Query 1: It provides a count of orders placed by each employee before May 1, 2016.
FROM [Sales].[Order]
WHERE orderdate < '20160501'
GROUP BY EmployeeId;

-- Query 2
SELECT EmployeeId, COUNT(*) AS numorders-- Query 2: It provides a count of all orders placed by each employee but only includes 
FROM [Sales].[Order]				   -- the counts where the maximum orderdate is before May 1, 2016.
GROUP BY EmployeeId
HAVING MAX(orderdate) < '20160501'

-- In simpler terms, Query 1 counts how many orders each employee had before May 1, 2016. 
-- Query 2 counts how many orders each employee had in total but only 
-- shows those employees whose latest order (maximum orderdate) was before May 1, 2016. 

-- So, Query 1 focuses on orders before a specific date, 
-- while Query 2 considers all orders but filters based on the latest order date.