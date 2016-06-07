#include<iostream>
#include<fstream>
#include<string>
#define MAX 50


using namespace std;

const string CONNECT = "adb connect ";
const string DISCONNECT = "adb disconnect ";
const string FILE_NAME= "data.adb";

void readFile();
int Menu();
void writeFile(string ip_connect);



//đọc file  và phát lệnh
void readFile(){
	
	string data;

	//FILE *f;
	//int n = 0;
	//fopen_s(&f, FILE_NAME, "r");

	//if (f == NULL){
	//	cout << "loi file rong" << endl;
	//}
	//else{
	//	fscanf_s(f, "%d", &n);
	//	for (int i = 0; i < n; ++i) {
	//		fscanf_s(f, "%d", &data[i]);   // truyền vào con trỏ file , tên file cần đọc , nhập dl vào mảng a
	//	}
	//}
	//fclose(f);

	//system();

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


// ghi file
void writeFile(string ip_connect , string action)
{
	fstream f;
	f.open(FILE_NAME, ios::out);   // dùng chung file
	string data = action + ip_connect;
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
		cout << "3. Disconnect ADB qua mang. " << endl; k++;
		cout << "4. Ipconfig ." << endl; k++;

		cout << "0. thoat ." << endl; k++;
		cout << "nhap lua chon: " << endl;
	} while (cv < 0 || cv >k);
	return cv;
	
}

void main(){

	int cv;
	string ip_connect;

	char data[MAX];

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
			writeFile(ip_connect, DISCONNECT);
			readFile();                         
			cout << "da ngat ket noi voi thiet bi hien hanh " << endl;
			break;
		case 4:
			system("ipconfig");
			break;
		default:
			cout << " nhap sai lua chon ";
			break;
		}
		system("pause");
		system("cls");
	} while (cv != 0);
	
	system("pause");
}