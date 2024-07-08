-- 7 
-- Return the three ship countries with the highest average freight for orders placed in 2015
-- Tables involved: Sales.Orders table

USE [Northwinds2022TSQLV7]											-- USE this database  
SELECT TOP 3 ShipToCountry, AVG(Freight) as avgfreight				-- Return the three highest countries with highest freight
FROM [Sales].[Order]												-- From Sales.orders table
WHERE YEAR(orderdate) = 2015										-- For the year 2015
GROUP BY ShipToCountry												-- Make sure to account for each country only once
ORDER BY avgfreight DESC;											-- sort highest to lowest