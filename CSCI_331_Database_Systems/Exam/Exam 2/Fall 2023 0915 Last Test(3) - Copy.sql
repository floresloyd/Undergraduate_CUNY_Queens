/*
	Name: Loyd Flores
	class : 09:15

	Email: loyd.flores49@qmail.cuny.edu 
	
	file Name to be uploaded: CSCI331 Fall2023LastTest-YourLastNameFirstname.sql
*/

/*
	1) Write a query that returns all orders placed on the first day of activity or on the last day of activity (OrderDate) found in the [Sales].[Order] table using subqueries.

		1. Hard coding the OrderDate to 2016-05-06 or 2014-07-04 will be marked as incorrect.
		2. Hint: consider using a set operation and subquery or CTE
		3. Tables involved: [Sales].[Order], [Sales].[Customer], and [HumanResources].[Employee]. 
		
		Sample output is below:

				OrderId	OrderDateType		OrderDate	CustomerCompanyName	EmployeeFullName
				10248	Minimum OrderDate	2014-07-04		Customer ENQZT		Sven Mortensen

				11077	Maximum OrderDate	2016-05-06		Customer NYUHS		Sara Davis
				11076	Maximum OrderDate	2016-05-06		Customer RTXGC		Yael Peled
				11075	Maximum OrderDate	2016-05-06		Customer CCKOT		Maria Cameron
				11074	Maximum OrderDate	2016-05-06		Customer JMIKW		Russell King
*/

/*

-- Flores, Loyd : #1 
-- Create the view that gives us access to the FirstOrderDate and LastOrderDate
WITH OrderActivityDates AS (
    SELECT
        MIN(OrderDate) AS FirstOrderDate,
        MAX(OrderDate) AS LastOrderDate
    FROM [Sales].[Order]
)
SELECT
    O.OrderId,
    CASE 
		-- Case Statements to handle Orderdates from Sales.Order
        WHEN O.OrderDate = OAD.FirstOrderDate THEN 'Minimum OrderDate'
        WHEN O.OrderDate = OAD.LastOrderDate THEN 'Maximum OrderDate'
    END AS OrderDateType,
    O.OrderDate,
    C.CustomerCompanyName,
	-- Concat to display required Name which is the employees full name
    CONCAT(E.EmployeeFirstName, ' ', E.EmployeeLastName) AS EmployeeFullName
FROM [Sales].[Order] O
-- Gives us access to CustomerCompanyName
INNER JOIN [Sales].[Customer] C ON O.CustomerId = C.CustomerId
-- Gives us Access to Employee First, Last Name
INNER JOIN [HumanResources].[Employee] E ON O.EmployeeId = E.EmployeeId
CROSS JOIN OrderActivityDates OAD
-- Only give me orders that were either ordered on the first or last day 
WHERE O.OrderDate = OAD.FirstOrderDate OR O.OrderDate = OAD.LastOrderDate
ORDER BY O.OrderId;

*/

/*
		2) Write a query that summarizes all employees whose first names start with the letter 'P' and bytheir SalesYear.

		Tables involved: [Sales].[Order], [Sales].[OrderDetail], and [HumanResources].[Employee].

			a. Calculate the number of ActualNumberOfOrders sold 
			b. derive Total Sales using the Sales.OrderDetails (quantity and unit price).
			c. The query returns all orders placed by the employees slected

	Sample output is below:
					  EmployeeFullName		SalesYear	ActualNumberOfOrders		Total Sales 
						Patricia Doyle			2016				19					42020.75
						Patricia Doyle			2015				19					29577.55
						Patricia Doyle			2014				5					11365.70
						Paul Suurs				2016				19					14475.00
						Paul Suurs				2015				33					45992.00
						Paul Suurs				2014				15					17731.10	

*/

/*
-- Flores, Loyd #2 
SELECT
	-- Manual Concatenation of Strings 
    E.EmployeeFirstName + ' ' + E.EmployeeLastName AS EmployeeFullName,
	-- Obtain Sales year
    YEAR(O.OrderDate) AS SalesYear,
	-- Get Number of orders 
    COUNT(DISTINCT O.OrderId) AS ActualNumberOfOrders,
	-- Total Sales
    SUM(OD.Quantity * OD.UnitPrice) AS TotalSales
FROM [HumanResources].[Employee] E
JOIN [Sales].[Order] O ON E.EmployeeId = O.EmployeeId
JOIN [Sales].[OrderDetail] OD ON O.OrderId = OD.OrderId
-- First name starts with P 
WHERE E.EmployeeFirstName LIKE 'P%'
GROUP BY E.EmployeeFirstName, E.EmployeeLastName, YEAR(O.OrderDate)
ORDER BY EmployeeFullName, SalesYear DESC;
*/



/*
--	3) Find all of the customers that made no purchases 

		■ Tables involved: [Sales].[Order] and [Sales].[Customer]  in the subquery

			CustomerId		CustomerCompanyName
*/

/*
-- Flores, L #3
SELECT
    C.CustomerId,
    C.CustomerCompanyName
FROM [Sales].[Customer] C
LEFT JOIN [Sales].[Order] O ON C.CustomerId = O.CustomerId
-- Return customers that made no purchases
WHERE O.OrderId IS NULL;

*/

/*
	4) Find the Maximum Order Date for Each Customer Using a Correlated Sub-Query with the Sales.Orders Table

		Tables Involved: [Sales].[Order] and [Sales].[Customer]
			
			a. The correlation is based on the CustomerId.
			b. Note that CustomerId 40 made two purchases on the same last day.

			Sample Output:

				CustomerId	CustomerCompanyName		OrderId		OrderDate		EmployeeId
				1			Customer NRZBB			11011		2016-04-09		3
				2			Customer MLTDN			10926		2016-03-04		4
				3			Customer KBUDE			10856		2016-01-28		3
				39			Customer GLLAG			11028		2016-04-16		2
				40			Customer EFFTC			10972		2016-03-24		4
				40			Customer EFFTC			10973		2016-03-24		6
				41			Customer XIIWM			11051		2016-04-27		7
*/

/*
-- Flores, L #4
SELECT
    C.CustomerId,
    C.CustomerCompanyName,
    O.OrderId,
    O.OrderDate,
    O.EmployeeId
FROM [Sales].[Customer] C
JOIN [Sales].[Order] O ON C.CustomerId = O.CustomerId
WHERE O.OrderDate = (
	-- Correlated Subquery to find max date which we're going to use for our condition
    SELECT MAX(O2.OrderDate)
    FROM [Sales].[Order] O2
    WHERE O2.CustomerId = C.CustomerId
)
ORDER BY C.CustomerId, O.OrderDate DESC;
*/
			

/*
	5) Find all of the distinct Customers orderscount by orderyear for the specific empid = 3
	
			■ Tables involved: [Sales].[Customer]and  [Sales].[.Order]  in the subquery

				EmployeeFirstName EmployeeLastName	EmployeeId	OrderYear	EmployeeCustomerCount
					Judy				Lew				3		2016				30
					Judy				Lew				3		2015				46
					Judy				Lew				3		2014				16
*/


-- FLORES, L #5
/*
SELECT
    E.EmployeeFirstName,
    E.EmployeeLastName,
    O.EmployeeId,
	-- Obtain the different years 
    YEAR(O.OrderDate) AS OrderYear,
	-- Counts the number of orders for the specific customer 
    COUNT(DISTINCT O.CustomerId) AS EmployeeCustomerCount
FROM [Sales].[Order] O
JOIN [HumanResources].[Employee] E ON O.EmployeeId = E.EmployeeId
WHERE O.EmployeeId = 3
-- Gets All the different years
GROUP BY E.EmployeeFirstName, E.EmployeeLastName, O.EmployeeId, YEAR(O.OrderDate)
ORDER BY YEAR(O.OrderDate) DESC;
*/

/*
	6) Create an Inline Table-Valued Function (TVF) to Get All Customer Orders by CustomerId

		Tables involved: [Sales].[Customer], [Sales].[Order], and [Sales].[OrderDetail]

			a. The function name must be Sales.utvf_GetAllCustomerOrdersByCustomerID with one parameter, @CustomerId, of type int.
			b. Utilize the tables [Sales].[Order] and [Sales].[OrderDetail].
			c. After creating the function, write a query to find all customer orders and items ordered.
			d. Perform a 'GROUP BY' summarization of the customer information using [Sales].[Customer] with a CROSS APPLY to Sales.utvf_GetAllCustomerOrdersByCustomerID.

		Sample Output:

			CustomerCompanyName	CustomerId	Number Of Orders	Number Of Items Ordered
			Customer NRZBB			1				6						12
			Customer MLTDN			2				4						10
			Customer KBUDE			3				7						17
*/

/*
-- FLORES, L #6 

-- Creating the Inline Table-Valued Function to Get All Customer Orders by CustomerId
CREATE FUNCTION Sales.utvf_GetAllCustomerOrdersByCustomerID(@CustomerId INT)
RETURNS TABLE
AS
RETURN
(
    SELECT
        O.CustomerId,
        COUNT(O.OrderId) AS NumberOfOrders,
        SUM(OD.Quantity) AS NumberOfItemsOrdered
    FROM [Sales].[Order] O
    INNER JOIN [Sales].[OrderDetail] OD ON O.OrderId = OD.OrderId
    WHERE O.CustomerId = @CustomerId
    GROUP BY O.CustomerId
);

-- Query to find all customer orders and items ordered using the function
SELECT
    C.CustomerCompanyName,
    C.CustomerId,
    COALESCE(OC.NumberOfOrders, 0) AS NumberOfOrders,
    COALESCE(OC.NumberOfItemsOrdered, 0) AS NumberOfItemsOrdered
FROM [Sales].[Customer] C
-- Inline table function used
CROSS APPLY Sales.utvf_GetAllCustomerOrdersByCustomerID(C.CustomerId) AS OC
ORDER BY C.CustomerId;

*/
