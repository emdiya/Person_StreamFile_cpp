#include <iostream>
#include <fstream>
#include  <conio.h>
#include <stdlib.h>
using namespace std;
class Person{
	private:
		int code;
		string name;
		string gender;
	public:
		void Input(){
			cout<<"Input Code = "; cin>>code;
			cin.ignore();
			cout<<"Input Name = "; cin>>name;
			cout<<"Input Sex = "; cin>>gender;
		}
		void Output(){
			cout<<code<<"\t"<<name<<"\t"<<gender<<endl;
		}
		int getcode(){
			return code;
		}
};
int main()
{
	int i,n,op;
	fstream file;
	Person per;
	Person per1;
	do{
		system("cls");
		cout<<":::::::::::::::::::::::::::::: Menu ::::::::::::::::::::::::::"<<endl;
		cout<<"\t1. Input"<<endl;
		cout<<"\t2. Outout"<<endl;
		cout<<"\t3. Search"<<endl;
		cout<<"\t4. Update"<<endl;
		cout<<"\t5. Remove"<<endl;
		cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
		cout<<"Please Choose One = "; cin >>op;
		switch(op){
			case 1:{
				file.open("person1.txt",ios::out);
				cout<<"Input N = "; cin>>n;
				for(i=0;i<n;i++){
					per.Input();
					file.write((char*)&per, sizeof(per));
				}
				file.close();
			}break;
			case 2:{
				file.open("person1.txt",ios::in);
				cout<<"Code\tName\tGender"<<endl;
				while(file.read((char*)&per, sizeof(per))){
					per.Output();
				}
				file.close();
			}break;
			case 3:{
				int svalue,b=0;
				cout<<"Input Code to Search = "; cin>>svalue;
				file.open("person1.txt",ios::in);
				cout<<"Code\tName\tGender"<<endl;
				while(file.read((char*)&per, sizeof(per))){
					if(per.getcode() == svalue){
						per.Output();
						b=1;
					}
				}
				if(b==0){
					cout<<"Search Not Found!!!"<<endl;
				}
				file.close();
			}break;
			case 4:{
				int uvalue,b=0;
				fstream temp;
				cout<<" Input Code to Update = "; cin>>uvalue;
				file.open("person1.txt",ios::in);
				temp.open("Temp.txt",ios::out);
				while(file.read((char*)&per, sizeof(per))){
					if(uvalue == per.getcode()){
						per1.Input();
						temp.write((char*)&per1, sizeof(per1));
						b=1;
					}else{
						temp.write((char*)&per, sizeof(per));
					}
				}
				if(b==0){
					cout<<"\n\tUpdate Error!!!\2\a"<<endl;
				}
				file.close();
				temp.close();
				remove("person1.txt");
				rename("Temp.txt","person1.txt");
			}break;
		}
	}while(getch()==13);
}