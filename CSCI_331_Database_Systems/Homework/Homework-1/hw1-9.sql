-- 9
-- Figure out and return for each employee the gender based on the title of courtesy
-- Ms., Mrs. - Female, Mr. - Male, Dr. - Unknown
-- Tables involved: HR.Employees table

USE [Northwinds2022TSQLV7]																				-- USE This DB
SELECT [EmployeeId], EmployeeFirstName, EmployeeLastName, EmployeeTitleOfCourtesy,						-- Return these values + gender
	CASE																			
			WHEN EmployeeTitleOfCourtesy ='Mr.' THEN 'Male'													-- If title = Mr, then gender = male
			WHEN EmployeeTitleOfCourtesy ='Ms.' OR EmployeeTitleOfCourtesy = 'Mrs.' THEN 'Female'			-- If title = Ms or Mrs, then = female
			ELSE 'Uknown'																					-- Else uknown
		END AS Gender																					-- VARIABLE NAME (gender)
FROM HumanResources.Employee																			-- From hr.employees table