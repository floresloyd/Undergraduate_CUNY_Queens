package proj1;

import java.sql.*;

public class proj1 {
   // Database credentials and connection string
   static final String DB_URL = "jdbc:sqlserver://localhost:13001;databaseName=TSQLV4;user=sa;password=PH@123456789;encrypt=true;trustServerCertificate=true";

   // Query to select data from the database
   static final String QUERY = "SELECT TOP(5) custid, orderid, orderdate FROM Sales.Orders";

   public static void main(String[] args) {

      try (

            // Statement: `Statement` is a way to send SQL commands to a database. Like a
            // messenger who carries your SQL request to the database and brings back the
            // result.

            // ResultSet: When you send a query (like SELECT) to the database using a
            // `Statement`, the data that comes back is stored in a `ResultSet`. Like a
            // container that holds all the data retrieved from the database.

            // Default Behaviors:

            // - TYPE_FORWARD_ONLY: By default, a `ResultSet` is "forward-only", meaning you
            // can only go through the data in one direction: from the first item to the
            // last. Imagine reading a book where you can only turn pages forward and cannot
            // go back.

            // - CONCUR_READ_ONLY: Also, by default, the `ResultSet` is "read-only", meaning
            // you can look at the data, but you cannot change it. Like reading a library
            // book - you can read it, but you can't write your notes in it.

            // Sometimes, we want more flexibility when working with the data from the
            // database, this is where we look into customization of `ResultSet`

            // - Want to Move Backward through Data**: If you want to move both forward and
            // backward through the data (like flipping back and forth through the pages of
            // a book), you need a scrollable `ResultSet`.

            // - Want to Update Data: If you want to modify the data (like editing text in a
            // book), you need an updatable `ResultSet`.

            // Customizing:

            // When you create a `Statement` object, you can specify how you want your
            // `ResultSet` to behave by providing two additional arguments:

            //
            // - `ResultSet.TYPE_FORWARD_ONLY` (can only move forward through data, default
            // behavior)
            // - `ResultSet.TYPE_SCROLL_INSENSITIVE` (can move forward and backward, but
            // does not see changes made by others)
            // - `ResultSet.TYPE_SCROLL_SENSITIVE` (can move forward and backward, and sees
            // changes made by others)

            //
            // - `ResultSet.CONCUR_READ_ONLY` (can’t modify the data, default behavior)
            // - `ResultSet.CONCUR_UPDATABLE` (can modify the data)

            // - `conn` is your connection to the database.
            // - `TYPE_SCROLL_INSENSITIVE` means you can move forward and backward through
            // your `ResultSet`.
            // - `CONCUR_UPDATABLE` means you can modify the data in the `ResultSet`.

            /*
             * In Java's JDBC, when you create a Statement object,
             * it defaults to producing ResultSet objects that are
             * TYPE_FORWARD_ONLY and CONCUR_READ_ONLY.
             * If you want a scrollable result set,
             * you must specify that when you create the Statement object.
             * we are using concur_read_only becuase we are not updating the data
             */
            Connection conn = DriverManager.getConnection(DB_URL);
            Statement stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = stmt.executeQuery(QUERY);) {
         // Printing the opening bracket of the JSON array
         System.out.print("[\n");

         // Iterating through the result set
         while (rs.next()) {
            // Retrieving data from the result set by column name
            int custId = rs.getInt("custid");
            int orderId = rs.getInt("orderid");
            String orderDate = rs.getString("orderdate");

            // Formatting and printing data in JSON format
            System.out.print("  {\n");
            System.out.print("    \"CustomerId\": " + custId + ",\n");
            System.out.print("    \"OrderId\": " + orderId + ",\n");
            System.out.print("    \"OrderDate\": \"" + orderDate + "\"\n");

            // Checking if there is another record in the result set to control comma
            // printing
            if (rs.isLast()) {
               System.out.print("  }\n");
            } else {
               System.out.print("  },\n");
            }
         }

         // Printing the closing bracket of the JSON array
         System.out.print("]\n");

      } catch (SQLException e) { // Handling SQL exception
         e.printStackTrace();
      }
   }
}