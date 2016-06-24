#include<iostream>
#include<fstream>
#include<string>


using namespace std;

const string CONNECT = "adb connect ";
const string DISCONNECT = "adb disconnect ";
const string GITHUB = "start https://github.com/trantronghienit/CommandsADB";
const string FILE_NAME= "data.adb";
const string FILE_NAME_COMMANDS = "commands.adb";

void readFile();
int Menu();
void writeFile(string ip_connect);



//đọc file  và phát lệnh
void readFile(){
	
	string data;

	fstream f;
	//string line;
	f.open(FILE_NAME , ios::in);

	
	while (!f.eof())
	{
		getline(f, data);
		//data += line;
	}
	f.close();
	// truyền lệnh 
	system(data.c_str());

}

void readFile(string file_name){

	string data;

	fstream f;
	//string line;
	f.open(file_name, ios::in);


	while (!f.eof())
	{
		getline(f, data);
		//data += line;
	}
	f.close();
	// truyền lệnh 
	system(data.c_str());

}



// ghi file
void writeFile(string ip_connect , string action)
{
	fstream f;
	f.open(FILE_NAME, ios::out);   // dùng chung file
	string data = action + ip_connect;
	f << data;

	f.close();
}


// ghi file
void writeFile(string action)
{
	fstream f;
	f.open(FILE_NAME_COMMANDS, ios::out);   // dùng chung file
	string data = action;
	f << data;

	f.close();
}

int Menu(){

	int k = 0 , cv = 0;
	do{
		cout << "CHUONG TRINH LENH ADB CO BAN " << endl;
		cout << "=================== Hien Tran design=========== " << endl;
		cout << "1. kiem tra devices." << endl; k++;
		cout << "2. connect ADB qua mang ." << endl; k++;
		cout << "3. connect ADB voi ip la 192.168.1.* ." << endl; k++;
		cout << "4. connect ADB voi ip la 192.168.2.* ." << endl; k++;
		cout << "5. da connect lan truoc roi ." << endl; k++;
		cout << "6. Disconnect ADB qua mang. " << endl; k++;
		cout << "7. nhap lenh bang tay " << endl; k++;
		cout << "8. adb help " << endl; k++;
		cout << "9.github of me" << endl;k++;
		cout << "10. Ipconfig ." << endl; k++;

		cout << "0. thoat ." << endl; k++;
		cout << "nhap lua chon: " << endl;
	} while (cv < 0 || cv >k);
	return cv;
	
}

void main(){

	int cv;
	string ip_connect;
	string command;

	do{
		cv = Menu();
		cin >> cv;
		switch (cv)
		{
		case 1:
			system("adb devices");
			break;
		case 2:
			cout << "nhap ip ket noi: ";
			cin.ignore();
			getline(cin , ip_connect);
			writeFile(ip_connect, CONNECT);
			readFile();
			break;
		case 3:
			cout << "ip ket noi 192.168.1.";
			cin.ignore();
			getline(cin, ip_connect);
			writeFile("192.168.1." + ip_connect, CONNECT);
			readFile();
			break;
		case 4:
			cout << "ip ket noi 192.168.2.";
			cin.ignore();
			getline(cin, ip_connect);
			writeFile("192.168.2." + ip_connect, CONNECT);
			readFile();
			break;
		case 5:
			readFile();
			break;
		case 6:
			writeFile(ip_connect, DISCONNECT);
			readFile();                         
			cout << "da ngat ket noi voi thiet bi hien hanh " << endl;
			break;
		case 7:
			cout << "nhap lenh :" << endl;
			cin.ignore();
			getline(cin, command);
			writeFile(command);
			readFile(FILE_NAME_COMMANDS);
			break;
		case 8:
			system("adb help");
			break;
		case 9: // add git
			system(GITHUB.c_str());
			break;
		case 10:
			system("ipconfig");
			break;
		default:
			cout << " nhap sai lua chon ";
			break;
		}
		system("pause");
		system("cls");
	} while (cv != 0 );
	
	system("pause");
}
