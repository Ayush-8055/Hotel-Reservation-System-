#include<mysqlx/xdevapi.h>
#include <iostream>

using namespace std;
using namespace mysqlx;

int main() {
    try {
        // Create a session to the MySQL server
        Session mySession("localhost", 33060, "root", "your_password");

        // SQL statement execution
        Schema myDb = mySession.getSchema("test_db");
        Table myTable = myDb.getTable("test_table");

        RowResult myResult = myTable.select("*").execute();

        // Fetch results
        for (Row row : myResult) {
            cout << "Row: ";
            for (unsigned i = 0; i < row.colCount(); ++i) {
                cout << row[i] << " ";
            }
            cout << endl;
        }

        // Close session
        mySession.close();
    }
    catch (const mysqlx::Error& err) {
        cout << "Error: " << err.what() << endl;
    }
    catch (std::exception &ex) {
        cout << "STD Exception: " << ex.what() << endl;
    }
    catch (const char* ex) {
        cout << "Exception: " << ex << endl;
    }

    return 0;
}
