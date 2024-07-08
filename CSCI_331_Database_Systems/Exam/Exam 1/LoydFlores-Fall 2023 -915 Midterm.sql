/*
	Class 9:15 AM

	Questions 1 through 7 are worth 12 points each and Question 8 is 16 points

	Submit this file with the following name: YourName-Fall 2023 - 915-Test1.sql

	Name : Loyd Flores________________________________

	Email: loyd.flores49@qmail.cuny.edu_______________

	Put all of your answers below each of the questions in this document. Optionally, Open a second query window to do your work.  
	
	!!!! Not submitting all of your answers in this one document will have a 25 point deduction for not following instructions

	Good Luck.

*/

/*
Question 1
	Using the dbo.Digits table with itself to create the units, tens and hundreds table alias CalculatedNumber

		select Hundreds.digit                                  as Hundreds
			 , Tens.digit                                      as Tens
			 , Units.digit                                     as Units
			 , concat(Hundreds.digit, Tens.digit, Units.digit) as CalculatedNumber
		from dbo.digits           as Hundreds
			cross join dbo.digits as Tens
			cross join dbo.digits as Units

	Generate the predicate of  two sets of numbers  From 000 to 999 in ascending order through a cartesian product relatve to the hundreds digit

	CalculatedNumber	Tens digit					Units digit
	Set 1				Hundreds equals Tens		Hundreds equals Units * 3

				Hundreds	Tens	Units	CalculatedNumber
					0		  0		  0				000
					3		  3		  1				331
					6		  6		  2				662
					9		  9		  3				993
	Make sure the result set has only 4 rows

*/

/* -- ANSWER FOR QUESTION #1

SELECT Hundreds.digit AS Hundreds,
       Tens.digit AS Tens,
       Units.digit AS Units,
       CONCAT(Hundreds.digit, Tens.digit, Units.digit) AS CalculatedNumber
FROM dbo.digits AS Hundreds
CROSS JOIN dbo.digits AS Tens			-- Using the dbo.Digits table with itself 
CROSS JOIN dbo.digits AS Units			-- Using the dbo.Digits table with itself 
WHERE Hundreds.digit = Tens.digit 		-- Condition for the hundreds digit to equal the tens digit
AND Hundreds.digit = Units.digit * 3 	-- Condition for the hundreds digit to be three times the units digit
*/

/*
	Question 2
	Using the dbo.Nums table derive the calander year (January 4-2000 through October 26, 2023) months.
  
	Make sure the result set has only 7263 rows
				
			n	FourthOfTheMonth
			1	2000-01-04
			2	2000-02-04
			3	2000-03-04
			4	2000-04-04
			.
			.
			.
			N   2023-10-04
*/
/* -- ANSWER FOR QUESTION 2
USE DB0915_loydflores49;
-- CTE 
WITH NumberedDates AS (
    SELECT ROW_NUMBER() OVER (ORDER BY (SELECT NULL)) AS n 			-- Assigns each integer as one row 
    FROM dbo.Nums													-- ORDER BY (SELECT NULL) allows us to not focus on one column so that we can get it ordered in a sequential manner
)

SELECT n,
       DATEADD(MONTH, n - 1, '2000-01-04') AS FourthOfTheMonth 		
FROM NumberedDates
WHERE DATEADD(MONTH, n - 1, '2000-01-04') <= '2023-10-26' 			-- limit the output dates up to October 26, 2023.
AND DAY(DATEADD(MONTH, n - 1, '2000-01-04')) = 4					--  ensures that the generated date is the 4th day of the month

*/

/*
		Question 3

		Use the Sales.Customer table
		
		Using the concat function, create the location alias (rename) from CustomerCountry,CustomerRegion and CustomerCity.  
		Make sure that there is a comma space seperation such as Canada, BC, Tsawassen

		Make sure the result set has only 91 rows

				CustomerCompanyName		CustomerContactName			CustomerCity	CustomerRegion	CustomerCountry		Location
				Customer NRZBB			Allen, Michael				Berlin				NULL			Germany			Germany, Berlin
				Customer MLTDN			Hassall, Mark				M�xico D.F.			NULL			Mexico			Mexico, M�xico D.F.
				Customer KBUDE			Strome, David				M�xico D.F.			NULL			Mexico			Mexico, M�xico D.F.
				Customer HFBZG			Cunningham, Conor			London				NULL			UK				UK, London
				Customer HGVLZ			Higginbotham, Tom			Lule�				NULL			Sweden			Sweden, Lule�
				Customer XHXJV			Poland, Carole				Mannheim			NULL			Germany			Germany, Mannheim
				Customer QXVLA			Bansal, Dushyant			Strasbourg			NULL			France			France, Strasbourg
				Customer QUHWH			Ilyina, Julia				Madrid				NULL			Spain			Spain, Madrid
				Customer RTXGC			Raghav, Amritansh			Marseille			NULL			France			France, Marseille
				Customer EEALV			Culp, Scott					Tsawassen			BC				Canada			Canada, BC, Tsawassen
*/

/* -- ANSWER FOR QUESTION 3

-- SELECT 
--     CustomerCompanyName,
--     CustomerContactName,
--     CustomerCity,
--     CustomerRegion,
--     CustomerCountry,
--     CASE 				
--         WHEN CustomerRegion IS NULL THEN CONCAT(CustomerCountry, ', ', CustomerCity) -- Case statement to handle concatenation of entries where there is no region
--         ELSE CONCAT(CustomerCountry, ', ', CustomerRegion, ', ', CustomerCity)       -- If it is not null concat everything
--     END AS Location
-- FROM
--     Sales.Customer

*/



/*
	Question 4

	Use the previous question's query
	create a predicate using the location to isolate Coutries that begin with G or F or A or I with a regex expression

	Make sure the result set has only 33 rows and order by CustomerCountry

		CustomerCompanyName			CustomerContactName		CustomerCity	CustomerRegion	CustomerCountry	Location
		Customer NRZBB				Allen, Michael			Berlin			NULL			Germany		Germany, Berlin
		Customer RTXGC				Raghav, Amritansh		Marseille		NULL			France		France, Marseille
		Customer PSNMQ				Ray, Mike				Buenos Aires	NULL			Argentina	Argentina, Buenos Aires
		Customer THHDP				Kane, John				Graz			NULL			Austria		Austria, Graz
		Customer WMFEA				Schm�llerl, Martin		Torino			NULL			Italy		Italy, Torino
		Customer FRXZL				�skarsson, J�n Harry	Cork			Co. Cork		Ireland		Ireland, Co. Cork, Cork

*/

/* -- ANSWER FOR QUESTION 4 
-- Previous Query
SELECT
    CustomerCompanyName,
    CustomerContactName,
    CustomerCity,
    CustomerRegion,
    CustomerCountry,
    CASE 
        WHEN CustomerRegion IS NULL THEN CONCAT(CustomerCountry, ', ', CustomerCity)
        ELSE CONCAT(CustomerCountry, ', ', CustomerRegion, ', ', CustomerCity)
    END AS Location
FROM
    Sales.Customer
WHERE
    CustomerCountry LIKE 'G%' OR 		-- Coutries that begin with G
    CustomerCountry LIKE 'F%' OR 		-- Coutries that begin with F
    CustomerCountry LIKE 'A%' OR 		-- Coutries that begin with A
    CustomerCountry LIKE 'I%'			-- Coutries that begin with I
ORDER BY
    CustomerCountry						-- Last query to be ran, just gives us a pretty result


*/



/*
	Question 5

		Use the Sales.Orders table

		Find all orders with an orderdate for the calendar year 2015 (12 rows returned)
		grouped on the month of the orderdate and use the alias OrderMonth
		aggregate: 
					TotalCountPerMonth
					TotalFreigtCharges
		ordered by 
					OrderMonth ascending

			OrderMonth	TotalCountPerMonth	TotalFreigtCharges	MinimumFreigtCharges	MaximumFreigtCharges
			1					33					2238.98				0.20					458.78
			2					29					1601.45				2.74					189.09
			3					30					1888.81				1.35					708.95
			4					31					2939.10				0.15					789.95
			5					32					3461.40				1.43					1007.64
			6					30					1852.65				3.01					252.49
			7					33					2458.72				0.48					544.08
			8					33					3078.27				0.14					487.38
			9					37					3237.05				0.90					388.98
			10					38					3945.53				0.58					810.05
			11					34					2008.85				1.39					243.73
			12					48					3757.96				1.10					351.53
*/

/* --  ANSWER FOR QUESTION 5
SELECT 
    MONTH(OrderDate) AS OrderMonth,
    COUNT(OrderId) AS TotalCountPerMonth, 	-- Aggregate TotalCountPerMonth, since we're grouping this finds the total number of orders
    SUM(Freight) AS TotalFreightCharges,	-- Aggregate TotalFreightCharges, since we're grouping this finds the total cost of freight
    MIN(Freight) AS MinimumFreightCharges,	-- We need to utilize an aggregate function since we're grouping
    MAX(Freight) AS MaximumFreightCharges	-- We need to utilize an aggregate function since we're grouping 
FROM 
    Sales.[Order]
WHERE 
    YEAR(OrderDate) = 2015					-- Find all orders with an orderdate for the calendar year 2015 
GROUP BY 
    MONTH(OrderDate)
ORDER BY 
    OrderMonth ASC;							-- OrderMonth ascending
*/

/*
	Question 6

		Using the two queries as input for the set operations in the same order  as the 2 queries below:

SELECT        EmployeeCity, EmployeeRegion, EmployeeCountry FROM HumanResources.Employee AS e

SELECT        CustomerCity, CustomerRegion, CustomerCountry FROM  Sales.Customer AS c

	What is the distinct count of the union of the queries? 71
	What is the count of the union with duplicates of the queries? 100
	What is intersection of the queries? 3
	What is the difference of sets of these two sets (HR.Employees - sales.Customers) ? 2

*/

/* ANSWERS FOR QUESTION 6.
--	What is the distinct count of the union of the queries? 71
SELECT COUNT(*)																					-- Return all the number of rows returned 
FROM (

    SELECT EmployeeCity AS City, EmployeeRegion AS Region, EmployeeCountry AS Country 	-- 
    FROM HumanResources.Employee
    
    UNION																						-- Combines the result of 2 select statements 
																								-- Union implicitly handles all duplicates
    SELECT CustomerCity, CustomerRegion, CustomerCountry								
    FROM Sales.Customer
) AS combinedUnion;

-- 	What is the count of the union with duplicates of the queries? 100
SELECT COUNT(*)
FROM (
    SELECT EmployeeCity AS City, EmployeeRegion AS Region, EmployeeCountry AS Country 
    FROM HumanResources.Employee
    
    UNION ALL																				 -- Union all is used so we don't discard duplicates
																						     -- this is hte only difference from the previous question 
    SELECT CustomerCity, CustomerRegion, CustomerCountry
    FROM Sales.Customer
) AS combinedUnionAll;


-- 	What is intersection of the queries? 3
SELECT COUNT(*)
FROM (
    SELECT DISTINCT EmployeeCity AS City, EmployeeRegion AS Region, EmployeeCountry AS Country 
    FROM HumanResources.Employee

    INTERSECT																				-- Uses the intersect operator to find elements
																							-- that intersect in the 2 sets/tables
    SELECT DISTINCT CustomerCity, CustomerRegion, CustomerCountry
    FROM Sales.Customer
) AS intersected;

-- 	What is the difference of sets of these two sets (HR.Employees - sales.Customers) ? 2
SELECT COUNT(*)
FROM (
    SELECT DISTINCT EmployeeCity AS City, EmployeeRegion AS Region, EmployeeCountry AS Country 
    FROM HumanResources.Employee

    EXCEPT																				   -- Except is basically set difference
																						   -- It needs to follow order. In this case were 
    SELECT DISTINCT CustomerCity, CustomerRegion, CustomerCountry						   --  subtracting sales.Customers from Hr.employees (Hr.Employees - Sales.Customers)
    FROM Sales.Customer	
) AS difference;

*/



/*
	Question 7

	Use the following tables in your query Sales.[Order] as o, Sales.OrderDetail as od, Sales.Customer as c and Sales.Shipper as s

			SELECT
			FROM Sales.[Order] as o
				INNER JOIN Sales.OrderDetail as od ON  od.OrderId = o.OrderId
				inner join Sales.Customer as c on c.CustomerId = o.CustomerId
				inner join Sales.Shipper as s on s.ShipperId = o.ShipperId
			WHERE 
			ORDER BY

	Find for the month of September, calculate  10 Lowest orders for the derived OrderPrice

	calculate the 
				1. Create a literal for  LowestOrderPrices using the text 'Lowest Order Prices'
				2. SeptemberOrders  alias deriving substring(cast(o.orderdate as char(10)), 1, 7) returning YYYY-09
				3. OrderPrice alias deriving product of UnitPrice and Quantity.
				4. DiscountedOrderPrice alias deriving by extending the OrderPrice calculation and applying the DiscountPercentage (1.-DiscountPercentage).
				5. DaysFromOrderToShip alias deriving the number of days between orderdate and shippeddate

			LowestOrderPrices	CustomerCompanyName	OrderDate	ShipperCompanyName	ShipToDate	SeptemberOrders	UnitPrice	Quantity	DiscountPercentage	DaysFromOrderToShip	OrderPrice	DiscountedOrderPrice
			Lowest Order Prices	Customer KBUDE		2015-09-22	Shipper ZHISN		2015-09-26	2015-09			2.50			8			0.150				4				20.00			17.0000000
			Lowest Order Prices	Customer FRXZL		2014-09-19	Shipper GVSUA		2014-10-23	2014-09			11.20			2			0.000				34				22.40			22.4000000
			Lowest Order Prices	Customer MLTDN		2014-09-18	Shipper ZHISN		2014-09-24	2014-09			28.80			1			0.000				6				28.80			28.8000000
			Lowest Order Prices	Customer SIUIH		2014-09-16	Shipper ZHISN		2014-09-23	2014-09			5.90			5			0.000				7				29.50			29.5000000
			Lowest Order Prices	Customer DVFMB		2014-09-17	Shipper ETYNR		2014-09-25	2014-09			10.00			3			0.000				8				30.00			30.0000000
			Lowest Order Prices	Customer VONTK		2014-09-12	Shipper ETYNR		2014-09-17	2014-09			17.20			2			0.000				5				34.40			34.4000000
			Lowest Order Prices	Customer YJCBX		2015-09-29	Shipper ETYNR		2015-10-03	2015-09			9.65			4			0.000				4				38.60			38.6000000
			Lowest Order Prices	Customer HGVLZ		2015-09-02	Shipper GVSUA		2015-09-11	2015-09			7.45			6			0.100				9				44.70			40.2300000
			Lowest Order Prices	Customer LJUCA		2015-09-18	Shipper ETYNR		2015-09-30	2015-09			9.00			5			0.000				12				45.00			45.0000000
			Lowest Order Prices	Customer FRXZL		2014-09-19	Shipper GVSUA		2014-10-23	2014-09			17.20			3			0.000				34				51.60			51.6000000

*/

/* -- ANSWER FOR QUESTION 7

SELECT TOP(10)																		  -- 10 Lowest orders for the derived OrderPrice
    'Lowest Order Prices' AS LowestOrderPrices,										  -- Create a literal for  LowestOrderPrices using the text 'Lowest Order Prices'
    c.CustomerCompanyName,
    o.OrderDate,
    s.ShipperCompanyName,
    o.ShipToDate,
    SUBSTRING(CAST(o.OrderDate AS CHAR(10)), 1, 7) AS SeptemberOrders,				  --  SeptemberOrders  alias deriving substring(cast(o.orderdate as char(10)), 1, 7) returning YYYY-09
    od.UnitPrice,
    od.Quantity,
    od.DiscountPercentage,
    DATEDIFF(DAY, o.OrderDate, o.ShipToDate) AS DaysFromOrderToShip,				  --  DaysFromOrderToShip alias deriving the number of days between orderdate and shippeddate
    od.UnitPrice * od.Quantity AS OrderPrice,										  --  OrderPrice alias deriving product of UnitPrice and Quantity.
    od.UnitPrice * od.Quantity * (1 - od.DiscountPercentage) AS DiscountedOrderPrice  -- DiscountedOrderPrice alias deriving by extending the OrderPrice calculation and applying the DiscountPercentage (1.-DiscountPercentage).
FROM Sales.[Order] AS o
INNER JOIN Sales.OrderDetail AS od ON od.OrderId = o.OrderId						  -- Tables to be joined as instructed
INNER JOIN Sales.Customer AS c ON c.CustomerId = o.CustomerId							
INNER JOIN Sales.Shipper AS s ON s.ShipperId = o.ShipperId
WHERE MONTH(o.OrderDate) = 9
ORDER BY od.UnitPrice * od.Quantity
*/



  /*
		  Question 8

				Use these 3 tables: Person.Person,HR.Employee, and HR.EmployeePayHistory
					Hint : (Corrolated subquery is a requirement to solve this query)
	
				1. BusinessEntityID is a critical linkage column.
				2. Create a computed column named Employee Full Name (FirstName LastName)
				3. Create a computed column named Annualized Salary based upon the most current RateChangeDate.

				   The formula should use the following columns and two assumptions:
					a. PayFrequency
					b. Rate

					Two Assumptions
					a. Work Week Hours is a literal 40
					b. PayFrequency is monthly

				3. Create a computed column named Current Rate Date as the latest date that the employee is being paid

				4. Create another query that validates the following unique row for each employee based Current Rate Date
		
				 Sample Output (290 rows)
				 BusinessEntityID	Employee Full Name		Annualized Salary	Current Rate Date	Rate	Monthly Pay Frequency	Work Week Hours
									1	Ken S�nchez				$240,960.00			2009-01-14		125.50			2					40
									2	Terri Duffy				$121,846.08			2008-01-31		63.4615			2					40
									3	Roberto Tamburello		$83,076.86			2007-11-11		43.2692			2					40
									4	Rob Walters				$57,304.70			2011-12-15		29.8462			2					40


				 Sample Output (13 rows) of duplicated rows

				BusinessEntityID	NumberOfChanges	MaxDate
						4				3			2011-12-15
		
		use DB0915_loydflores49;
		go
*/

/* -- ANSWER FOR QUESTION 8 
-- 3. Create a computed column named Current Rate Date as the latest date that the employee is being paid
-- CTE 
WITH LatestRateChange AS
(
    SELECT 
        eph.BusinessEntityID,
        eph.RateChangeDate,
        ROW_NUMBER() OVER(PARTITION BY eph.BusinessEntityID ORDER BY eph.RateChangeDate DESC) AS rn
    FROM HR.EmployeePayHistory eph
)

SELECT 
    e.BusinessEntityID,
    CONCAT(p.FirstName, ' ', p.LastName) AS [Employee Full Name],							-- Create a computed column named Employee Full Name (FirstName LastName)
    FORMAT(eph.Rate * 40 * eph.PayFrequency * 12, '$#,##0.00') AS [Annualized Salary],		-- Create a computed column named Annualized Salary based upon the most current RateChangeDate.
    eph.RateChangeDate AS [Current Rate Date],												-- Pay rate derived from formula given above 
    eph.Rate,
    eph.PayFrequency AS [Monthly Pay Frequency],
    40 AS [Work Week Hours]
FROM LatestRateChange lrc
JOIN HR.Employee e ON e.BusinessEntityID = lrc.BusinessEntityID								-- Joining tables given above with the CTE 
JOIN Person.Person p ON p.BusinessEntityID = e.BusinessEntityID
JOIN HR.EmployeePayHistory eph ON eph.BusinessEntityID = lrc.BusinessEntityID AND eph.RateChangeDate = lrc.RateChangeDate
ORDER BY e.BusinessEntityID;

-- Did not have time for comments on this one 
-- 4. Create another query that validates the following unique row for each employee based Current Rate Date
WITH RateChanges AS (
    SELECT 
        BusinessEntityID, 
        RateChangeDate,
        ROW_NUMBER() OVER(PARTITION BY BusinessEntityID ORDER BY RateChangeDate DESC) AS row_num,
        COUNT(*) OVER(PARTITION BY BusinessEntityID) AS NumberOfChanges,
        MAX(RateChangeDate) OVER(PARTITION BY BusinessEntityID) AS MaxDate
    FROM HR.EmployeePayHistory
)

SELECT 
    BusinessEntityID, 
    NumberOfChanges, 
    MaxDate 
FROM RateChanges 
WHERE row_num = 1 AND NumberOfChanges > 1 

*/