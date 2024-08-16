1. **Directory Management**:
   - The program starts by checking if a directory named `Data` exists. If not, it creates one. This directory acts as the root folder where databases (as directories) and tables (as CSV files) are stored.

3. **Supported Commands**:
   - **Create Database**: The command `create database <dbname>` creates a new directory within the `Data` directory to represent a database.
   - **Create Table**: The command `create table <dbname> <tablename>` creates a CSV file within the specified database directory. The program also handles table structure by allowing the user to define columns within parentheses.
   - **Show Databases**: The command `show databases` lists all the databases (directories) within the `Data` directory.
   - **Show Tables**: The command `show tables <dbname>` lists all the tables (CSV files) within the specified database directory.
   - **View Table**: The command `view <dbname> <tablename>` displays the contents of the specified table.
   - **Drop Database**: The command `drop database <dbname>` deletes the specified database directory.
   - **Drop Table**: The command `drop table <dbname> <tablename>` deletes the specified table CSV file.
   - **Insert Data**: The command `insert <dbname> <tablename> <values>` inserts data into the specified table.
   - **Delete Row**: The command `delete <dbname> <tablename> <row>` deletes a specific row from the table.

4. **Error Handling**:
   - The program includes error messages for common issues, such as attempting to create an already existing database or table, or trying to delete a non-existent row. It also checks for incorrect input format and unexpected commands.

5. **Control Flow**:
   - The program uses `goto` statements to loop back to the start of the input prompt after each command execution or error, allowing the user to continue interacting with the program.

6. **ScreenShots**:

![image](https://github.com/user-attachments/assets/60881473-31e2-46ae-b199-b48601069491)
![image](https://github.com/user-attachments/assets/3f000563-4038-480f-abcb-81da8f49b6dc)
![image](https://github.com/user-attachments/assets/bbb0941f-7864-4a32-8a75-bc76ae840515)



### Key Takeaways:

- The program simulates basic database operations using file and directory management in C.
- It provides a simple command-line interface for creating and managing databases and tables, viewing their contents, and modifying them by inserting or deleting data.
