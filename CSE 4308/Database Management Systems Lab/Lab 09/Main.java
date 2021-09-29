/*importing the package*/
import java.sql.*;

public class Main {
    public static void main(String[] args) {

        /*variable username used to log-in into the database(here, the username is --> system) */
        String username = "system";

        /*variable password used to log-in into the database(here, the password of the user 'system' is 'josephite') */
        String password = "josephite";

        /*variable url is stating the type of 'driver' that used to establish connection to the database and the 'port number'
        at which the database is located, at which we can establish connection to the database.
        */
        String url = "jdbc:oracle:thin:@localhost:1521/orclpdb";

        /*variable sqlQuery is storing the query which will be executing on the database and
        this query will be selecting A_ID,AMOUNT & TYPE from the TRANSACTIONS table
        of the database which will be used to do some necessary operations on them
        later on.
         */
        String sqlQuery = "SELECT A_ID, AMOUNT, TYPE FROM TRANSACTIONS";

        /*variable totalNumberOfAccounts is storing the number of accounts in the ACCOUNT table
        totalNumberOfAccounts is found by executing the SQL Query--
        SQL> select count(A_ID) from ACCOUNT;
        COUNT(A_ID)
        -----------
                238
        */
        int totalNumberOfAccounts = 238;

        /* variable finalBalance stores Individual balance after checking debit and credit */
        int[] finalBalance = new int[1001];

        /*variable account_id stores individual account_id in the 'while loop' */
        int account_id;

        /* variable typeOfAccount checks whether it's a 0 or 1
        1 indicating--> money is transferred from the account i.e. money is subtracted from the account.
        0 indicating--> money is transferred to the account i.e. money is added to the account.
         */
        String typeOfAccount;

        /*variable transactionAmount stores the whole balance whether it's debit or credit */
        int[] transactionAmount = new int[1001];

        /*variable amountOfIndividualAccount holds all the Individual Account id amount in thw 'while loop'*/
        int amountOfIndividualAccount;

        /*variable rowOfTransactionTable will keep the track of position of each row in the
        TRANSACTIONS table to compute and decide whether an account is CIP/VIP/Ordinary/Uncategorized
        according to the if-else statements
         */
        int rowOfTransactionsTable = 0;

        /*variable numberOfCipAccount is storing the total number of CIP Accounts stored on the database*/
        int numberOfCipAccount = 0;

        /*variable numberOfVipAccount is storing the total number of VIP Accounts stored on the database*/
        int numberOfVipAccount = 0;

        /*variable numberOfOrdinaryAccount is storing the total number of Ordinary Accounts stored on the database*/
        int numberOfOrdinaryAccount = 0;

        /*variable numberOfUncategorizedAccount is storing the total number of Uncategorized Accounts stored on the database*/
        int numberOfUncategorizedAccount;

        try {
            /* 1) Registering the driver class-->
            here, forName is the method that is loading the driver and this forName method
            belongs to class name called Class. Besides, the driver name or the loaded driver
            is  called 'oracle.jdbc.driver.OracleDriver'.
             */

            Class.forName("oracle.jdbc.driver.OracleDriver");

            /* 2) Creating the connection object or creating the connection-->
            here, Connection is an Interface and getConnection() is the static method that will give the object of
            Class Connection, named connection and this connection object taking three parameters url, username, password and
            getConnection() method belongs to class name DriverManager.
             */

            Connection connection = DriverManager.getConnection(url, username, password);
            /* 3) Creating the Statement object-->
            here, Statement is an Interface and the object is statement and createStatement() is the method.
             */

            Statement statement = connection.createStatement();
            System.out.println("Connection to database successful");

            /* 4) Executing the query-->
            here, executeQuery() method is used and in this method query is specified for fetching necessary data
            and sqlQuery is the variable that holds that query here. Data is fetching from the TRANSACTIONS table
            and this table is stored inside the object name result of Interface ResultSet.
             */

            ResultSet result = statement.executeQuery(sqlQuery);

            while (result.next()) {

                account_id = result.getInt("A_ID");
                amountOfIndividualAccount =  result.getInt("AMOUNT");
                typeOfAccount = result.getString("TYPE");

                if (typeOfAccount.equals("0"))
                {
                    finalBalance[account_id] += amountOfIndividualAccount;

                }
                else
                {
                    finalBalance[account_id] -= amountOfIndividualAccount;
                }

                transactionAmount[account_id] += amountOfIndividualAccount;

            }


            for (rowOfTransactionsTable = 0; rowOfTransactionsTable < totalNumberOfAccounts; rowOfTransactionsTable++){

                if (finalBalance[rowOfTransactionsTable] > 1000000 && transactionAmount[rowOfTransactionsTable] > 5000000)
                {
                    numberOfCipAccount++;
                }
                else if ((finalBalance[rowOfTransactionsTable] > 500000 && finalBalance[rowOfTransactionsTable] < 900000) && (transactionAmount[rowOfTransactionsTable] > 3500000 && transactionAmount[rowOfTransactionsTable] < 4500000))
                {
                    numberOfVipAccount++;
                }
                else if (finalBalance[rowOfTransactionsTable] < 40000 && transactionAmount[rowOfTransactionsTable] < 3000000)
                {
                    numberOfOrdinaryAccount++;
                }
            }

            numberOfUncategorizedAccount = totalNumberOfAccounts - (numberOfCipAccount + numberOfVipAccount + numberOfOrdinaryAccount);

            System.out.println("Total Number of Accounts : " + totalNumberOfAccounts);
            System.out.println("CIP count                : " + numberOfCipAccount);
            System.out.println("VIP count                : " + numberOfVipAccount);
            System.out.println("Ordinary count           : " + numberOfOrdinaryAccount);
            System.out.println("Uncategorized            : " + numberOfUncategorizedAccount);

            /* 5) Closing the connection object-->
            After finishing working with the database, the Connection is closed to our database by calling the close() method
            under the Connection class and the object was named connection. After the execution of connection.close() statement, the statement and result object
            closes automatically
             */
            connection.close();

        }

        /*This catch block handles SQLException. SQLException will occur whenever the program fails to establish connection
         to the database.
         */
        catch (SQLException e)
        {
            System.out.println(e);
        }

        /*This catch block handles ClassNotFoundException. ClassNotFoundException will occur whenever the program fails to
        register the Oracle Driver to the database
       */
        catch (ClassNotFoundException e)
        {
            System.out.println("Failed to register driver. Exception code: " + e);
        }

        System.out.println (" Thank You !") ;
    }
}