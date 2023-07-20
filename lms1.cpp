#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
using namespace std;
class book{
    char bno[6];
    char book_name[50]; //title of book
    char authName[20]; //author of book
  public:
    void create_book(){
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<< "\nEnter Book Number : ";
        cin>>bno;
        cin.ignore();
        cout<< "\n\nEnter Name of the Book : ";
        gets(book_name);
        cout<<"\n\nEnter Author's name : ";
        gets(authName);
        cout<<"\n\n\nBook Created...";
    }

    void show_book(){
        cout<<"\nBook number : " << bno;
        cout<<"\nBook Name : ";
        puts(book_name);
        cout<<"Author Name : ";
        puts(authName);
    }    
    char* retbno(){ return bno; }
	
    void report(){cout<<bno<<setw(30)<<book_name<<setw(30)<<authName<<endl;}

}; //end of class book
fstream f, f1;
book b;
void write_book(){
    char ch;
    f.open("book.dat", ios::out|ios::app);
    do{
        b.create_book();
        f.write((char*)&b, sizeof(book));
        cout<<"\n\nDo you want to add more books...(y/n?)";
        cin>>ch;
    }while( ch == 'y'|| ch == 'Y' );
    f.close();
}

void display_spb(char n[]){
    cout<<"\nBOOK DETAILS\n";
    int flag = 0;
    f.open("book.dat", ios::in);
    while(f.read((char*)&b, sizeof(book))){
        if( strcmpi(b.retbno(),n) == 0 ){
            b.show_book();
            flag = 1;
        }
    }

    f.close();
    if(flag==0) cout<<"\n\nBook does not exist";
    getch();
}
void display_allb(){
    
    f.open("book.dat", ios::in);
    if(!f){
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    while(f.read((char*)&b, sizeof(book))) b.report();
     f.close();
     getch();
}

void delete_book(){
    char n[6];
    
    cout<<"\n\n\n\tDELETE BOOK ...";
    cout<<"\n\nEnter Book number of Book to Delete : ";
    cin >> n;
    f.open("book.dat", ios::in|ios::out);
    fstream f2;
    f2.open("Temp.dat", ios::out);
    f.seekg(0, ios::beg);
    while( f.read((char*)&b, sizeof(book)) ) if(strcmpi(b.retbno(),n)!=0)                          f2.write((char*)&b, sizeof(book));
    f2.close();
    f.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
}






void student(){ // function hundumaa display gochuufi fuula is jalqaba irra dhufu agarsiisuuf
 		int navigate;
 		string viewresearches;
 		cout << "[1] Search for Books" << endl;
 		cout << "[2] View Books" << endl;
 		cout << "[3] Main menu" << endl;
 		cout << endl;
 		cout << endl;
 		cout << "To navigate choose the numbers: ";
 		cin >> navigate; // fuula bira deemu barbaanne argachuuf if fayyadamne
 		switch(navigate){
        case 1: 
            char num[6];
            cout<<"\n\n\tPlease Enter The book No. ";
            cin>>num;
            display_spb(num);
            break;
        case 2: 
            display_allb(); 
            break;
        case 3: return;
        default: cout<<"\a";
		
	} student();
}
	
void admin(){
    
    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t(1) CREATE BOOK ";
    cout<<"\n\n\t(2) DISPLAY ALL BOOKS ";
    cout<<"\n\n\t(3) DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t(4) DELETE BOOK ";
    cout<<"\n\n\t(4) MAIN MENU ";
    cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
    cin>>ch2;
    switch(ch2){
        case 1: 
            write_book(); 
            break;
        case 2: 
            display_allb(); 
            break;
        case 3:
            char num[6];
            cout<<"\n\n\tPlease Enter The book No. ";
            cin>>num;
            display_spb(num);
            break;
        case 4: 
            delete_book(); 
            break;
        case 5: return;
        default: cout<<"\a";
    }
    admin(); //recursion
}
	
void adminlog(){
	int adm;
	cout << "\n\n\t=======WELCOME TO  LIBRARY===============" << endl;
	cout << "\t=========================================";
	cout << endl;
	cout<<"\n\n\t(1) ADIMNSTRATOR ";
    cout<<"\n\n\t(2) STUDENT " << endl;
    cout << "\n\n\n\tChoose the correct number to navigate: ";
    cin>>adm;
    switch(adm){
        case 1:   
            admin(); 
            break;
        case 2: 
            student(); 
            break;
        case 3: return;
        default: cout<<"\a";
}
adminlog();
}

	int main(){
		adminlog();
		
}
