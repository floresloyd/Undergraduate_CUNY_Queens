-- 10
-- Return for each customer the customer ID and region
-- sort the rows in the output by region
-- having NULLs sort last (after non-NULL values)
-- Note that the default in T-SQL is that NULLs sort first
-- Tables involved: Sales.Customers table

USE [Northwinds2022TSQLV7]
SELECT CustomerId, CustomerRegion								-- Return custid and region
FROM Sales.Customer												-- from customerid
ORDER BY														-- MANUAL SORTING IMPLEMENTATION
    CASE
        WHEN CustomerRegion IS NULL THEN 1								-- Assign a higher value to NULL to sort it, if null make it 1
        ELSE 0 -- Sort non-NULL values first							-- if non-null make it go first
    END;															-- 0 < 1; 0 goes first
	CustomerRegion;
