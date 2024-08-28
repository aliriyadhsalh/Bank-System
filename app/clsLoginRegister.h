#pragma once
#include <iostream>

class clsLoginRegister
{
private:
	string _Time = "";
	string _UserName = "";
	string _Password = "";
	short _Permission = 0;


public:

	clsLoginRegister()
	{

	}

	clsLoginRegister(string Time, string UserName, string Password, short Permission)
	{
		_Time = Time;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;

	}

	void SetTime(string Time)
	{
		_Time = Time;
	}

	string GetTime()
	{
		return _Time;
	}

	_declspec(property(get = GetTime, put = SetTime)) string Time;

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	_declspec(property(get = GetUserName, put = SetUserName)) string UserName;


	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	_declspec(property(get = GetPassword, put = SetPassword)) string Password;


	void SetPermission(short Permission)
	{
		_Permission = Permission;
	}

	short GetPermission()
	{
		return _Permission;
	}

	_declspec(property(get = GetPermission, put = SetPermission)) short Permission;

	static clsLoginRegister _ConvertLinetoLogObject(string Line, string Separator = "#//#")
	{
		vector<string> vLine = clsString::Split(Line, Separator);

		return clsLoginRegister(vLine[0], vLine[1], vLine[2], stoi(vLine[2]));
	}

	static vector<clsLoginRegister> GetLoginRegisterList()
	{
		vector <clsLoginRegister> vLog;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{
				clsLoginRegister Log = _ConvertLinetoLogObject(Line);

				vLog.push_back(Log);
			}

			MyFile.close();

		}

		return vLog;

	}

};

