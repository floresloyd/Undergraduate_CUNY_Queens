package proj1;

// import java.sql.*;

// public class proj1 {
//    // Database credentials and connection string
//    static final String DB_URL = "jdbc:sqlserver://localhost:13001;databaseName=TSQLV4;user=sa;password=PH@123456789;encrypt=true;trustServerCertificate=true";

//    // Query to select data from the database
//    static final String QUERY = "SELECT TOP(5) custid, orderid, orderdate FROM Sales.Orders";

//    public static void main(String[] args) {

//       try (

//             // Statement: `Statement` is a way to send SQL commands to a database. Like a
//             // messenger who carries your SQL request to the database and brings back the
//             // result.

//             // ResultSet: When you send a query (like SELECT) to the database using a
//             // `Statement`, the data that comes back is stored in a `ResultSet`. Like a
//             // container that holds all the data retrieved from the database.

//             // Default Behaviors:

//             // - TYPE_FORWARD_ONLY: By default, a `ResultSet` is "forward-only", meaning you
//             // can only go through the data in one direction: from the first item to the
//             // last. Imagine reading a book where you can only turn pages forward and cannot
//             // go back.

//             // - CONCUR_READ_ONLY: Also, by default, the `ResultSet` is "read-only", meaning
//             // you can look at the data, but you cannot change it. Like reading a library
//             // book - you can read it, but you can't write your notes in it.

//             // Sometimes, we want more flexibility when working with the data from the
//             // database, this is where we look into customization of `ResultSet`

//             // - Want to Move Backward through Data**: If you want to move both forward and
//             // backward through the data (like flipping back and forth through the pages of
//             // a book), you need a scrollable `ResultSet`.

//             // - Want to Update Data: If you want to modify the data (like editing text in a
//             // book), you need an updatable `ResultSet`.

//             // Customizing:

//             // When you create a `Statement` object, you can specify how you want your
//             // `ResultSet` to behave by providing two additional arguments:

//             //
//             // - `ResultSet.TYPE_FORWARD_ONLY` (can only move forward through data, default
//             // behavior)
//             // - `ResultSet.TYPE_SCROLL_INSENSITIVE` (can move forward and backward, but
//             // does not see changes made by others)
//             // - `ResultSet.TYPE_SCROLL_SENSITIVE` (can move forward and backward, and sees
//             // changes made by others)

//             //
//             // - `ResultSet.CONCUR_READ_ONLY` (can’t modify the data, default behavior)
//             // - `ResultSet.CONCUR_UPDATABLE` (can modify the data)

//             // - `conn` is your connection to the database.
//             // - `TYPE_SCROLL_INSENSITIVE` means you can move forward and backward through
//             // your `ResultSet`.
//             // - `CONCUR_UPDATABLE` means you can modify the data in the `ResultSet`.

//             /*
//              * In Java's JDBC, when you create a Statement object,
//              * it defaults to producing ResultSet objects that are
//              * TYPE_FORWARD_ONLY and CONCUR_READ_ONLY.
//              * If you want a scrollable result set,
//              * you must specify that when you create the Statement object.
//              * we are using concur_read_only becuase we are not updating the data
//              */
//             Connection conn = DriverManager.getConnection(DB_URL);
//             Statement stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
//             ResultSet rs = stmt.executeQuery(QUERY);) {
//          // Printing the opening bracket of the JSON array
//          System.out.print("[\n");

//          // Iterating through the result set
//          while (rs.next()) {
//             // Retrieving data from the result set by column name
//             int custId = rs.getInt("custid");
//             int orderId = rs.getInt("orderid");
//             String orderDate = rs.getString("orderdate");

//             // Formatting and printing data in JSON format
//             System.out.print("  {\n");
//             System.out.print("    \"CustomerId\": " + custId + ",\n");
//             System.out.print("    \"OrderId\": " + orderId + ",\n");
//             System.out.print("    \"OrderDate\": \"" + orderDate + "\"\n");

//             // Checking if there is another record in the result set to control comma
//             // printing
//             if (rs.isLast()) {
//                System.out.print("  }\n");
//             } else {
//                System.out.print("  },\n");
//             }
//          }

//          // Printing the closing bracket of the JSON array
//          System.out.print("]\n");

//       } catch (SQLException e) { // Handling SQL exception
//          e.printStackTrace();
//       }
//    }
// }

import java.sql.*; // Importing all classes from the java.sql package, which are needed for JDBC operations.

import javax.swing.JFrame; // Importing JFrame class for creating a window.
import javax.swing.JOptionPane; // Importing JOptionPane for showing dialogs.
import javax.swing.JScrollPane; // Importing JScrollPane for adding scroll functionality to components.
import javax.swing.JTable; // Importing JTable for displaying tabular data.
import javax.swing.table.DefaultTableModel; // Importing DefaultTableModel as a model for the JTable.

public class proj1 {

    public static void main(String[] args) {
        // Connection string for JDBC. Replace details as per your database.
        String connectionString = "jdbc:sqlserver://localhost:13001;databaseName=" + "BiClass"
                + ";user=sa;password=PH@123456789;encrypt=true;trustServerCertificate=true";

        try (Connection conn = DriverManager.getConnection(connectionString)) {
            // Establishing a database connection using the connection string.

            // Executing stored procedures.
            executeStoredProcedure(conn, "2", "[Project2].[Load_DimMaritalStatus]");
            executeStoredProcedure(conn, "5", "[Project2].[Load_DimGender]");
            executeStoredProcedure(conn, "5", "[Project2].[Load_DimOccupation]");

            // Displaying query results in tables.
            displayQueryResults("SELECT * FROM [CH-01-01-Dimension].[DimMaritalStatus]", conn);
            displayQueryResults("SELECT * FROM [CH-01-01-Dimension].[DimGender]", conn);
            displayQueryResults("SELECT * FROM [CH-01-01-Dimension].[DimOccupation]", conn);

        } catch (SQLException e) {
            // Handling SQL exceptions by showing an error message.
            JOptionPane.showMessageDialog(null, "Error: " + e.getMessage());
        }

        // Additional operations like prompting user actions can be added here.
    }

    private static void executeStoredProcedure(Connection conn, String authorizationKey, String storedProcedureName) throws SQLException {
        // Preparing to call a stored procedure.
        String storedProc = "{call " + storedProcedureName + "(?)}";
        try (CallableStatement cstmt = conn.prepareCall(storedProc)) {
            // Setting parameters and executing the stored procedure.
            cstmt.setString(1, authorizationKey);
            cstmt.executeUpdate();
        }
    }

    private static void displayQueryResults(String query, Connection conn) throws SQLException {
        // Executing a query and displaying its results.
        try (Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(query)) {

            // Setting up a table model to hold query results.
            DefaultTableModel model = new DefaultTableModel();
            ResultSetMetaData metaData = rs.getMetaData();
            int columnCount = metaData.getColumnCount();

            // Adding column names to the table model.
            for (int i = 1; i <= columnCount; i++) {
                model.addColumn(metaData.getColumnName(i));
            }

            // Iterating over the ResultSet to add rows to the table model.
            while (rs.next()) {
                Object[] row = new Object[columnCount];
                for (int i = 1; i <= columnCount; i++) {
                    row[i - 1] = rs.getObject(i);
                }
                model.addRow(row);
            }

            // Creating a JTable with the model and setting up the JFrame to display it.
            JTable table = new JTable(model);
            table.setFillsViewportHeight(true);

            JFrame frame = new JFrame("Query Results for " + query);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.add(new JScrollPane(table));
            frame.setSize(800, 600);
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        }
    }
}