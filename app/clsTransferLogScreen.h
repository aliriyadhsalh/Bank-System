#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"


using namespace std;

class clsTransferLogScreen : protected clsScreen
{

private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferRecord.DateTime;
        cout << "| " << setw(10) << left << TransferRecord.AccountNumberSourceClient;
        cout << "| " << setw(10) << left << TransferRecord.AccountNumberDestinationClient;
        cout << "| " << setw(10) << left << TransferRecord.BalanceTransfer;
        cout << "| " << setw(10) << left << TransferRecord.BalanceSourceClient;
        cout << "| " << setw(10) << left << TransferRecord.BalanceDestinationClient;
        cout << "| " << setw(10) << left << TransferRecord.UserName;
    }



public:

    static void ShowTransferLogScreen()
    {


        vector <clsBankClient::stTransferLogRecord> vLoginRegisterRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t____________________________________________________________";
        cout << "_______________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "sAcct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t____________________________________________________________";
        cout << "_______________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vLoginRegisterRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t____________________________________________________________";
        cout << "_______________________________________\n" << endl;

    }
};

