#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace MyLib
{
	class clsCalculator
	{
	private:

		float _Result = 0;
		float _LastNumber = 0;
		string _LastOperation = "Clear";
		float _PreviousResult = 0;

	public:

		void Add(float Number)
		{
			_LastNumber = Number;
			_PreviousResult = _Result;
			_LastOperation = "Adding";
			_Result += Number;
		}

		void Subtract(float Number)
		{
			_LastNumber = Number;
			_PreviousResult = _Result;
			_LastOperation = "Subtracting";
			_Result -= Number;
		}

		void Divide(float Number)
		{
			if (Number == 0) Number = 1;
			_LastNumber = Number;
			_PreviousResult = _Result;
			_LastOperation = "Dividing";
			_Result /= Number;
		}

		void Multiply(float Number)
		{
			_LastNumber = Number;
			_PreviousResult = _Result;
			_LastOperation = "Multipling";
			_Result *= Number;
		}

		float GetFinalResult()
		{
			return _Result;
		}

		void Clear()
		{
			_LastNumber = 0;
			_PreviousResult = 0;
			_LastOperation = "Clear";
			_Result = 0;
		}

		void CancelLastOperation()
		{
			//_LastNumber = 0;
			_LastOperation = "Cancelling Last Operation " + _LastOperation;
			_Result = _PreviousResult;
		}

		// get
		void PrintResult()
		{
			cout << "Result After " << _LastOperation << " " << _LastNumber << " is: " << _Result << endl;
		}



	};

	class clsPerson
	{
	private:

		int _ID = 0;
		string _FirstName = "";
		string _LastName = "";
		string _FullName = "";
		string _Email = "";
		string _Phone = "";


	public:


		clsPerson(int ID, string FirstName, string LastName, string Gmail, string Number)
		{
			_ID = ID;
			_FirstName = FirstName;
			_LastName = LastName;
			_Email = Gmail;
			_Phone = Number;
		}

		// ID Read Only
		int ID()
		{
			return _ID;
		}

		void setFirstName(string FirstName)
		{
			_FirstName = FirstName;
		}

		string FirstName()
		{
			return _FirstName;
		}

		void setLastName(string LastName)
		{
			LastName = _LastName;
		}

		string LastName()
		{
			return _LastName;
		}

		string FullName()
		{
			return (_FirstName + " " + _LastName);
		}

		void setPhone(string Phone)
		{
			_Phone = Phone;
		}

		string Phone()
		{
			return _Phone;
		}

		void setEmail(string Email)
		{
			_Email = Email;
		}

		string Email()
		{
			return _Email;
		}

		void SendEmail(string Subject, string Body)
		{
			cout << "\nThe following message sent successfully to email: " << _Email
				<< "\nSubject: " << Subject
				<< "\nBody: " << Body << endl;
		}

		void SendSMS(string TextMessage)
		{
			cout << "\nThe following SMS sent successfully to phone: " << _Phone
				<< endl << TextMessage << endl;
		}

		void Print()
		{
			cout << "\nInfo:";
			cout << "\n________________________";
			cout << "\nID         : " << _ID;
			cout << "\nFirstName  : " << _FirstName;
			cout << "\nLastName   : " << _LastName;
			cout << "\nFullName   : " << FullName();
			cout << "\nEmail      : " << _Email;
			cout << "\nPhone      : " << _Phone;
			cout << "\n________________________\n";
		}

	};

	class clsEmployee : public clsPerson
	{
	private:
		string _Title = "";
		string _Department = "";
		float _Salary = 0;

	public:

		clsEmployee(int ID, string FirstName, string LastName, string Email,
			string Phone, string Title, string Department, float Salary)
			: clsPerson(ID, FirstName, LastName, Email, Phone)
		{
			_Title = Title;
			_Department = Department;
			_Salary = Salary;
		}

		void setTitle(string Title)
		{
			_Title = Title;
		}

		string Title()
		{
			return _Title;
		}

		void setDepartment(string Department)
		{
			_Department = Department;
		}

		string Department()
		{
			return _Department;
		}

		void setSalary(float Salary)
		{
			_Salary = Salary;
		}

		float Salary()
		{
			return _Salary;
		}


		void Print()
		{
			cout << "\nInfo:";
			cout << "\n________________________";
			cout << "\nID         : " << ID();
			cout << "\nFirstName  : " << FirstName();
			cout << "\nLastName   : " << LastName();
			cout << "\nFullName   : " << FullName();
			cout << "\nEmail      : " << Email();
			cout << "\nPhone      : " << Phone();
			cout << "\nTitle      : " << _Title;
			cout << "\nDepartment : " << _Department;
			cout << "\nSalary     : " << _Salary;
			cout << "\n________________________\n";
		}
	};

	class clsProgrammer : public clsEmployee
	{
	private:
		string _MainProgrammingLanguage = "";

	public:
		clsProgrammer(int ID, string FirstName, string LastName, string Email,
			string Phone, string Title, string Department, float Salary, string MainProgrammingLanguage)
			: clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary)
		{
			_MainProgrammingLanguage = MainProgrammingLanguage;
		}

		void SetMainProgrammingLanguage(string MainProgrammingLanguage)
		{
			_MainProgrammingLanguage = MainProgrammingLanguage;
		}

		string MainProgrammingLanguage()
		{
			return _MainProgrammingLanguage;
		}

		void Print()
		{
			cout << "\nInfo:";
			cout << "\n________________________";
			cout << "\nID         : " << ID();
			cout << "\nFirstName  : " << FirstName();
			cout << "\nLastName   : " << LastName();
			cout << "\nFullName   : " << FullName();
			cout << "\nEmail      : " << Email();
			cout << "\nPhone      : " << Phone();
			cout << "\nTitle      : " << Title();
			cout << "\nDepartment : " << Department();
			cout << "\nSalary     : " << Salary();
			cout << "\nMain Programming Language : " << _MainProgrammingLanguage;
			cout << "\n________________________\n";
		}

	};
}