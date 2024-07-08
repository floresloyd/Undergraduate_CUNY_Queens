// import java.sql.*;

/** TRYING TO RUN OUR FIRST STORED PROCEDURE */

// public class Project2 {
//     // mssql-jdbc-12.4.1.jre11.jar -> include in same folder as java file
//     // TO COMPILE : javac Project2.java -> Compile
//     // TO RUN : java -cp ".;mssql-jdbc-12.4.1.jre11.jar" Project2 -> Run with the JDBC file

//     public static void main(String[] args) {
//         // Connection string
//         String connectionString = "jdbc:sqlserver://localhost:13001;databaseName=BIClass"
//                                 + ";user=sa;password=PH@123456789;encrypt=true;trustServerCertificate=true";
        
//         try (Connection conn = DriverManager.getConnection(connectionString)) {
//             // Prepare the stored procedure call
//             CallableStatement stmt = conn.prepareCall("{call Project2.Load_DimCustomer}");
            
//             // Set the value for the '@GroupMemberUserAuthorizationKey' parameter
//             // You will need to replace 'yourAuthorizationKey' with the actual key value
//             //stmt.setString(1, "1");
            
//             // Execute the stored procedure
//             stmt.execute();
//             System.out.println("");
//             System.out.println("Stored procedure executed successfully.");
            
//             // Clean-up environment
//             stmt.close();
            
//         } catch (SQLException e) {
//             e.printStackTrace();
//         }
//     }
// }


/** TESTING STORED PROCEDURE : RETURNS AN INTEGER 432 */

// import java.sql.*;

// public class Project2 {

//     public static void main(String[] args) {
//         // Connection string
//         String connectionString = "jdbc:sqlserver://localhost:13001;databaseName=BIClass"
//                                 + ";user=sa;password=PH@123456789;encrypt=true;trustServerCertificate=true";
        
//         try (Connection conn = DriverManager.getConnection(connectionString)) {
//             // Prepare the stored procedure call
//             CallableStatement stmt = conn.prepareCall("{call Project2.Load_DimCustomer}");
            
//             // Execute the stored procedure and get the returned value
//             boolean hasResults = stmt.execute();
//             if (hasResults) {
//                 ResultSet rs = stmt.getResultSet();
//                 if (rs.next()) {
//                     int returnedValue = rs.getInt("ReturnValue");
//                     System.out.println("Stored procedure returned: " + returnedValue);
//                 }
//             }
            
//             // Clean-up environment
//             System.out.println("Test");
//             stmt.close();
            
//         } catch (SQLException e) {
//             e.printStackTrace();
//         }
//     }
// }


/** RETURNS NAMES FROM USERAUTH */
import java.sql.*;

public class Project2 {

    public static void main(String[] args) {
        // Connection string
        String connectionString = "jdbc:sqlserver://localhost:13001;databaseName=BIClass"
                                + ";user=sa;password=PH@123456789;encrypt=true;trustServerCertificate=true";
        
        try (Connection conn = DriverManager.getConnection(connectionString)) {
            // Prepare the stored procedure call
            CallableStatement stmt = conn.prepareCall("{call Project2.Load_DimCustomer}");
            
            // Execute the stored procedure
            boolean hasResults = stmt.execute();
            if (hasResults) {
                try (ResultSet rs = stmt.getResultSet()) {
                    // Process the result set
                    while (rs.next()) {
                        // Assuming you know the structure of your table, you can retrieve data like this:
                        // String someColumnValue = rs.getString("ColumnName");
                        // System.out.println(someColumnValue);

                        // For now, let's just print the first column of each row
                        System.out.println(rs.getString(4));
                    }
                }
            }
            
            // Clean-up environment
            stmt.close();
            
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}



