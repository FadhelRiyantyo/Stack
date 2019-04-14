#include <iostream>
#define MAX_STACK_SIZE 10

using namespace std;

struct Element{
	int data;
	int top;
	Element *next;
};
	Element tumpuk;
	Element *head = NULL;

class myStack{
	
	public:
	void setawal(){
		tumpuk.top = -1;
	}
    
	bool isFull(){
        if(tumpuk.top == 9){
			return 1;
		}else{
			return 0;
		}
    }
    bool isEmpty(){
        if(tumpuk.top == -1){
			return 1;
		}else{
			return 0;
		}
    }
	
	void pop(){
		if (isEmpty()){
			cout<<"\nStack Kosong\n";
		}else{
			Element *tmp = new Element;
			tmp = head;
			head = head->next;
			delete tmp;
			cout<<"\nPop Berhasil\n";
			tumpuk.top--;
		}	
	}
	
	void push(int input){
		if(isFull()){
			cout << "Stack Penuh";
		}else{
			Element *tmp = new Element;
			tmp->data = input;
			tmp->next=NULL;
			if(isEmpty())
			{
				head=tmp;
				head->next=NULL;
			}else{
				tmp->next=head;
				head=tmp;
			}
			cout<<"Push berhasil \n";
			tumpuk.top++;
		}
	}
		
	void getTop(){
		if(isEmpty()){
			cout << "Stack Kosong";
		}else{
			cout << head->data;
		}
	}
	
	void print(){
		if(isEmpty()){
			cout << "Tumpukan Kosong" << endl;
		}else{
			cout << "Isi Tumpukan : " << endl;
			Element *tmp = new Element;
			tmp = head;
			while(tmp!=NULL)
			{
				cout<<tmp->data<<"  ";
				tmp=tmp->next;
			}
		}
	}
};

int nama_menu();

int main(){
	myStack obj;
	int menu,val;
	obj.setawal();
	do{
		menu = nama_menu();
		switch(menu){
			case 1:
					cout << "Masukan Angka = ";cin>>val;
					obj.push(val);
					cin.ignore();
					cin.get();
					break;
			case 2:
					if(obj.isEmpty()){
						cout << "Stack Kosong" << endl;
					}else{
						cout << "Angka ";obj.getTop(); cout << " akan dihapus";
						cin.get();
						obj.pop();
					}
					break;
			case 3:
					if(obj.isEmpty()){
						cout << "Stack Kosong" << endl;
					}else{
						cout << "Elemen Paling Atas adalah ";obj.getTop();
						cin.get();
					}
					break;
			case 4:
					obj.print();
					cin.get();
					break;
			case 5:
					exit(0);
			default:
					cout <<"\t\nPilihan tidak ada";
					cin.get();
					break;
		}
		system("clear");
	}while (menu != 5);
		cin.get();
		return 0;
}

int nama_menu(){
	int menu;
	cout << "PILIH STACK MENU : "<<endl<<endl;
	cout << "1) Push Angka"<<endl;
	cout << "2) Pop Angka"<<endl;
	cout << "3) Get Top"<<endl;
	cout << "4) Print Stack List"<<endl;
	cout << "5) Exit..."<<endl<<endl;
	cout << "Pilihan : "; cin >> menu;
	
	cin.ignore();
	system("clear");
	return menu;
}
