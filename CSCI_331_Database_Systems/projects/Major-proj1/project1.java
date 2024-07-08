
import java.sql.*;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
// download this file and replace the ff:
/**
 *      new QueryData(
 *           dataBaseName: "",
 *           " # ACTUAL QUERY",
 *           description: " "),
 *      
 *      new QueryData()
 */
// mssql-jdbc-12.4.1.jre11.jar                                   -> include in same folder as java file 
// TO COMPILE : javac project1.java                              -> Compile
// TO RUN :  java -cp ".;mssql-jdbc-12.4.1.jre11.jar" project1   -> Run with the JDBC file 

public class project1 {
        // Data structure to hold the queries, databases and their descriptions
        static class QueryData {
                String databaseName;
                String query;
                String description;

                public QueryData(String databaseName, String query, String description) {
                        this.databaseName = databaseName;
                        this.query = query;
                        this.description = description;
                }
        }

        // List of all queries, databases and descriptions

        static final QueryData[] QUERIES = {

                // 1. "AdventureWorks2017" - 2 Queries
                new QueryData("AdventureWorks2017",
                              "SELECT d.Name AS DepartmentName, AVG(CASE WHEN edh.EndDate IS NULL THEN DATEDIFF(YEAR, edh.StartDate, GETDATE()) ELSE DATEDIFF(YEAR, edh.StartDate, edh.EndDate) END) AS AverageTenure FROM HumanResources.Department d JOIN HumanResources.EmployeeDepartmentHistory edh ON d.DepartmentID = edh.DepartmentId GROUP BY d.Name;",
                              "Find the top 5 products (based on total quantity ordered) that were discontinued but have had a significant sales impact. For these products, list down the customers who have ordered them the most, the total quantity they've ordered, and the corresponding supplier of the product."),
            
                new QueryData("AdventureWorks2017",
                              "SELECT p.Name AS ProductName, pv.AverageLeadTime, pv.StandardPrice, pv.LastReceiptCost FROM Production.Product p JOIN Purchasing.ProductVendor pv ON p.ProductID = pv.ProductID WHERE pv.AverageLeadTime > 10 ORDER BY pv.AverageLeadTime;",
                              "Retrieve the list of products that have been purchased by vendors along with their average lead time, standard price, and the last receipt cost. Limit the results to products that have an average lead time greater than 10 days."),
            
                // 2. "AdventureWorksDW2017" - 1 Query
                new QueryData("AdventureWorksDW2017",
                              "SELECT TOP(5) e.FirstName, e.LastName, sq.CalendarYear, SUM(sq.SalesAmountQuota) as TotalSalesAmount FROM dbo.FactSalesQuota sq JOIN dbo.DimEmployee e ON sq.EmployeeKey = e.EmployeeKey WHERE sq.CalendarYear = 2010 GROUP BY e.FirstName, e.LastName, sq.CalendarYear ORDER BY TotalSalesAmount DESC;",
                              "Identify the top 5 employees with the highest sales amounts for year 2010"),
            
                // 3. "Northwinds2022TSQLV7" - 2 Queries
                new QueryData("Northwinds2022TSQLV7",
                              "SELECT C.CustomerId, c.CustomerCompanyName, O.OrderId, O.OrderDate FROM Sales.Customer AS C INNER JOIN sales.[Order] AS O ON C.CustomerId = o.CustomerId WHERE O.OrderDate = '20160212';",
                              "Find all customers who placed orders on February 12, 2016 "),
            
                new QueryData("Northwinds2022TSQLV7",
                              "USE AdventureWorks2017; WITH DepartmentEmployeeCount AS (SELECT d.DepartmentID, d.Name AS DepartmentName, COUNT(DISTINCT e.BusinessEntityID) AS EmployeeCount FROM HumanResources.Department d JOIN HumanResources.EmployeeDepartmentHistory edh ON d.DepartmentID = edh.DepartmentID JOIN HumanResources.Employee e ON edh.BusinessEntityID = e.BusinessEntityID WHERE edh.EndDate IS NULL GROUP BY d.DepartmentID, d.Name HAVING COUNT(DISTINCT e.BusinessEntityID) > 5) SELECT dec.DepartmentName, dec.EmployeeCount, (SELECT MAX(e.HireDate) FROM HumanResources.Employee e WHERE e.BusinessEntityID IN (SELECT edh2.BusinessEntityID FROM HumanResources.EmployeeDepartmentHistory edh2 WHERE edh2.DepartmentID = dec.DepartmentID AND edh2.EndDate IS NULL)) AS LatestHireDate FROM DepartmentEmployeeCount dec ORDER BY dec.EmployeeCount DESC, LatestHireDate DESC;",
                              "Retrieve departments, the number of employees in each department, and the latest hire date for those departments with more than 5 employees"),
            
                // 4. "PrestigeCars" - 1 Query
                new QueryData("PrestigeCars",
                              "SELECT C.CustomerName, C.Town, SUM(S.TotalSalePrice) AS TotalSalesForReseller FROM Data.Customer C JOIN Data.Sales S ON C.CustomerID = S.CustomerID WHERE C.isReseller = 1 GROUP BY C.CustomerName, C.Town ORDER BY TotalSalesForReseller DESC;",
                              "Determine the total sales price for each reseller customer."),
            
                // 5. "WideWorldImporters" - 2 Queries
                new QueryData("WideWorldImporters",
                              "WITH CitySupplier AS (SELECT c.CityID, c.CityName, sp.StateProvinceName, s.SupplierId, s.PaymentDays FROM Application.Cities AS c JOIN Application.StateProvinces AS sp ON c.StateProvinceID = sp.StateProvinceID JOIN Purchasing.Suppliers AS s ON c.CityID = s.DeliveryCityID) SELECT TOP(3) CityName, StateProvinceName, COUNT(SupplierId) AS NumberOfSuppliers, AVG(PaymentDays) AS AvgPaymentDays FROM CitySupplier GROUP BY CityName, StateProvinceName ORDER BY NumberOfSuppliers DESC;",
                              "Find out the top 3 cities that has the highest number of suppliers, and for each city, we want to know the average payment days for those suppliers."),
            
                new QueryData("WideWorldImporters",
                              "WITH CustomerTransactionCount AS (SELECT c.CustomerID, c.CustomerName, city.CityName, COUNT(ct.CustomerTransactionID) AS TotalTransactions FROM Sales.Customers AS c JOIN Sales.CustomerTransactions AS ct ON c.CustomerID = ct.CustomerID JOIN Application.Cities AS city ON c.DeliveryCityID = city.CityID GROUP BY c.CustomerID, c.CustomerName, city.CityName) SELECT CustomerName, CityName, TotalTransactions FROM CustomerTransactionCount WHERE TotalTransactions > 5 ORDER BY TotalTransactions DESC;",
                              "Identify in the total sales transactions for each customer, and identify which customers have had more than five transactions in the database."),
            
                // 6. "WideWorldImportersDW" - 1 Query
                new QueryData("WideWorldImportersDW",
                              "WITH TopSuppliers AS (SELECT TOP(3) p.[Supplier Key], SUM(p.[Ordered Quantity]) as TotalSuppliedQuantity FROM Fact.Purchase p JOIN Dimension.Date d ON p.[Date Key] = d.Date WHERE d.[Fiscal Year] = (SELECT MAX([Fiscal Year]) - 1 FROM Dimension.Date) GROUP BY p.[Supplier Key] ORDER BY TotalSuppliedQuantity DESC) SELECT s.Supplier, s.[Supplier Reference], ts.TotalSuppliedQuantity, AVG(s.[Payment Days]) as AveragePaymentDays FROM TopSuppliers ts JOIN Dimension.Supplier s ON ts.[Supplier Key] = s.[Supplier Key] GROUP BY s.Supplier, s.[Supplier Reference], ts.TotalSuppliedQuantity ORDER BY ts.TotalSuppliedQuantity DESC;",
                              "Determine the top 3 suppliers for the last year based on the total quantity of products they supplied. Alongside this, find the average payment days associated with these suppliers")
            };

        public static void main(String[] args) {
                // Prompt user for database selection

                // boolean value for playagain
                boolean pl = true;
                while (pl) {
                        String[] databases = {
                                          "AdventureWorks2017","AdventureWorksDW2017", "Northwinds2022TSQLV7", "PrestigeCars", "WideWorldImporters", "WideWorldImportersDW"
                        };
                        String selectedDb = (String) JOptionPane.showInputDialog(null, "Choose a database",
                                        "Database Selection",
                                        JOptionPane.QUESTION_MESSAGE, null, databases, databases[0]);

                        // Display queries related to the chosen database
                        String[] descriptions = java.util.Arrays.stream(QUERIES)
                                        .filter(q -> q.databaseName.equals(selectedDb)) // Filter queries by database
                                                                                        // q->q.databaseName.equals(selectedDb)
                                                                                        // means q is a QueryData object
                                                                                        // and q.databaseName is the
                                                                                        // databaseName field of that
                                                                                        // object
                                        .map(q -> q.description) // .map(q -> q.description) // Map the filtered queries
                                                                 // to their descriptions
                                        .toArray(String[]::new);// .toArray(String[]::new); // Convert the mapped
                                                                // descriptions to an array of strings
                        String selectedDescription = (String) JOptionPane.showInputDialog(null, "Choose a query",
                                        "Query Selection", // Prompt user for query selection
                                        JOptionPane.QUESTION_MESSAGE, null, descriptions, descriptions[0]); // Display
                                                                                                            // the
                                                                                                            // descriptions
                                                                                                            // in a
                                                                                                            // dropdown

                        // Fetch the selected query
                        String selectedQuery = java.util.Arrays.stream(QUERIES) // Filter queries by description
                                        .filter(q -> q.description.equals(selectedDescription))// .filter(q ->
                                                                                               // q.description.equals(selectedDescription))
                                                                                               // //
                                                                                               // q->q.description.equals(selectedDescription)
                                                                                               // means q is a QueryData
                                                                                               // object and
                                                                                               // q.description is the
                                                                                               // description field of
                                                                                               // that object
                                        .findFirst() // .findFirst() // Get the first query that matches the description
                                        .get().query; // .get().query; // Get the query field of the query data object

                        // Connection string
                        String connectionString = "jdbc:sqlserver://localhost:13001;databaseName=" + selectedDb // Parameterize
                                                                                                                // database
                                                                                                                // name
                                                                                                                // in
                                                                                                                // URL
                                        + ";user=sa;password=PH@123456789;encrypt=true;trustServerCertificate=true";

                        try (Connection conn = DriverManager.getConnection(connectionString)) { // Establish connection
                                                                                                // to the database using
                                                                                                // the connection string
                                StringBuilder jsonOutput = new StringBuilder("[\n"); // Initialize a string builder to
                                                                                     // hold the output
                                if (selectedQuery.contains("GO")) { // If the query contains the word "GO", split the
                                                                    // query by "GO" and execute each part separately
                                        String[] commands = selectedQuery.split("\\bGO\\b", -1); // Split the query by
                                                                                                 // "GO"
                                        for (String command : commands) { // Execute each part separately
                                                if (command != null && !command.trim().isEmpty()) { // If the command is
                                                                                                    // not null or
                                                                                                    // empty, execute it
                                                        executeAndAppendToJson(command.trim(), conn, jsonOutput); // Execute
                                                                                                                  // the
                                                                                                                  // command
                                                                                                                  // and
                                                                                                                  // append
                                                                                                                  // the
                                                                                                                  // results
                                                                                                                  // to
                                                                                                                  // the
                                                                                                                  // output
                                                } // If the command is null or empty, do nothing
                                        }
                                } else {
                                        executeAndAppendToJson(selectedQuery, conn, jsonOutput); // If the query does
                                                                                                 // not contain the word
                                                                                                 // "GO", execute it and
                                                                                                 // append the results
                                                                                                 // to the output
                                }

                                jsonOutput.append("]\n"); // Close the output

                                // Display results in a scrollable pane
                                JTextArea textArea = new JTextArea(20, 50); // Initialize a text area to display the
                                                                            // output
                                textArea.setText(jsonOutput.toString()); // Set the text of the text area to the output
                                textArea.setWrapStyleWord(true); // Set the text area to wrap words
                                textArea.setLineWrap(true); // Set the text area to wrap lines
                                textArea.setCaretPosition(0); // Set the caret position to the beginning of the text
                                                              // area. Caret is the blinking cursor
                                textArea.setEditable(false); // Set the text area to be non-editable
                                JScrollPane scrollPane = new JScrollPane(textArea); // Initialize a scroll pane to
                                                                                    // display the text area
                                JOptionPane.showMessageDialog(null, scrollPane, "Query Results",
                                                JOptionPane.INFORMATION_MESSAGE); // Display the scroll pane in a dialog
                                                                                  // box
                        } catch (SQLException e) { // Catch any SQL exceptions
                                JOptionPane.showMessageDialog(null, "Error executing the query: " + e.getMessage()); // Display
                                                                                                                     // the
                                                                                                                     // error
                                                                                                                     // message
                                                                                                                     // in
                                                                                                                     // a
                                                                                                                     // dialog
                                                                                                                     // box
                        }

                        // Prompt user to play again
                        int playagain = JOptionPane.showConfirmDialog(null, "Would you like to query again?",
                                        "Query Again?", // Prompt user to play again
                                        JOptionPane.YES_NO_OPTION);
                        if (playagain == JOptionPane.NO_OPTION) {
                                pl = false;
                        }
                }
        }

        private static void executeAndAppendToJson(String query, Connection conn, StringBuilder jsonOutput)// Execute
                                                                                                           // the query
                                                                                                           // and append
                                                                                                           // the
                                                                                                           // results to
                                                                                                           // the output
                        throws SQLException {
                try (Statement stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,
                                ResultSet.CONCUR_READ_ONLY)) { // Create a statement object with scrollable and
                                                               // updatable result set
                        if (stmt.execute(query)) { // If the query is a select query, execute it
                                ResultSet rs = stmt.getResultSet(); // Get the result set of the query
                                ResultSetMetaData metaData = rs.getMetaData(); // Get the metadata of the result set.
                                                                               // meta data is data about data. Its like
                                                                               // the column names and types of the
                                                                               // result set
                                int columnCount = metaData.getColumnCount(); // Get the number of columns in the result
                                                                             // set
                                while (rs.next()) {
                                        jsonOutput.append("  {\n"); // Append the opening brace of the json object
                                        for (int i = 1; i <= columnCount; i++) { // Loop through the columns
                                                jsonOutput.append("    \"").append(metaData.getColumnName(i))
                                                                .append("\": \"") // Append the column name and value to
                                                                                  // the output
                                                                .append(rs.getString(i)).append("\""); // Append the
                                                                                                       // column name
                                                                                                       // and value to
                                                                                                       // the output
                                                if (i < columnCount) { // If the column is not the last column, append a
                                                                       // comma
                                                        jsonOutput.append(","); // Append a comma
                                                } // If the column is the last column, do nothing
                                                jsonOutput.append("\n"); // Append a new line
                                        }
                                        jsonOutput.append(rs.isLast() ? "  }\n" : "  },\n"); // Append the closing brace
                                                                                             // of the json object
                                }
                        }
                }
        }

}