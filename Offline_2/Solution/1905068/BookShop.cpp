/*******************************Offline 2****************************************/
/* Implement the functions of the class BookShop below as per the instructions  */
/* given inline the class definition. Make sure the output of the code in the   */
/* main function matches the given sample output. You may add/delete codes in   */
/* the main function during your testing. But before submission remove all your */
/* modifications from the main function and submit it as provided initially.    */
/********************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include "Book.cpp"

using namespace std;

class BookShop{
	char name[100];
	Book* books; //List of books in the shop
	int size;  //maximum number of books the shop can keep
	int count; //tracks currently how many numbers in the shop
	public:
		void setName(char* name){
		/*Set the name of the bookshop to the given name*/
            strcpy(this->name,name);
		}

		BookShop(){//Default constructor
		/*Initialize with size 5 and name to empty string ""*/
            size = 5;
            books = new Book[5];
            strcpy(this->name,"");
            count = 0;
		}

		BookShop(char* name, int size){//Parameterized constructor
		/*Initialize with the given name and size*/
            this->size = size;
            strcpy(this->name,name);
            books = new Book[size];
            count = 0;
		}

		BookShop(const BookShop& bs){//Copy constructor
		/*Write necessary code for the copy constructor*/
            this->size = bs.size;
            this->count = bs.count;
            strcpy(this->name,name);
            this->books = new Book[size];

            for(int i=0;i<count;i++){
                books[i]=bs.books[i];
            }
		}

		~BookShop(){//Destructor
		/*Free memory as applicable*/
            delete[] books;
		}

		void addBook(Book b){
		/*Add book b to the end of the list*/
            books[count] = b;
            count++;
		}

		void addBook(Book* ba, int count){
		/*Add the given array of books ba to the end of the list*/
            int num1 = 0, num2 = this->count;
            while(num1<count){
                books[num2] = ba[num1];
                this->count++;
                num1++;
                num2++;
            }
		}

		Book getBookInfo(char* title){
		/*Return the **first** book that has the given title. Assume there is atleast one book in the list with the given title*/
            for(int i=0;i<count;i++){
                char* ck = books[i].getTitle();
                if(strcmp(ck,title) == 0){
                    return books[i];
                }
            }
		}

		void updateBookPrice(int isbn, int price){
		/*Update the price of the book with given isbn to the given price*/
            for(int i=0;i<count;i++){
                int ci = books[i].getISBN();
                if(ci == isbn){
                    books[i].setPrice(price);
                    break;
                }
            }
		}

		void removeBook(int isbn){
		/*Remove the book with the given isbn from the list. After removing a book all the books below the removed book will be shifted up, i.e, there will be no hole in the list*/
            int k=0;

            for(int i=0;i<count;i++){
                int ci = books[i].getISBN();
                if(ci == isbn){
                    k=1;
                    for(int j=i+1;j<count;j++){
                        books[j-1] = books[j];
                    }
                }
                if(k) break;
            }

            count--;
		}

		int totalPrice(){
		/*Return the sum of the prices of all the books in the list*/
            int sum=0;

            for(int i=0;i<count;i++){
                int cp = books[i].getPrice();
                sum+=cp;
            }

            return sum;
		}

		void print(){
		/*Print the bookshop's name followed by information of all the books in the bookshop*/
            cout << "Bookshop name: " << name << endl;
            for(int i=0;i<count;i++){
                char* ct = books[i].getTitle();
                int ci = books[i].getISBN(), cp = books[i].getPrice();
                cout << "ISBN: " << ci << ", " << "Title: " << ct << ", " << "Price: " << cp << endl;
            }

		}

		BookShop mergeShop(BookShop b){
		/* Return a new bookshop object that will contain all the books of this bookshop and the given bookshop b*/ 			/* Use the title **MergedShop** of the new bookshop*/

            int a=this->size+b.size;
            BookShop mrg("Mergedbookshop",a);

            for(int i=0;i<this->count;i++){
                mrg.books[i]=this->books[i];
                mrg.count++;
            }
            for(int i=0;i<b.count;i++){
                mrg.books[i+this->count]=b.books[i];
                mrg.count++;
            }

            return mrg;
		}
};

int main(){

	BookShop bs1;
	bs1.setName("Boimela");
	Book b1(101,"Teach Yourself C++",100);
	Book b2(102,"Teach Yourself C",200);
	Book b3(103,"Java For Dummies",300);
	bs1.addBook(b1);
	bs1.addBook(b2);
	bs1.addBook(b3);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 102, Title: Teach Yourself C, Price: 200
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */
	cout<<endl;
	cout<<"Total price of books: "<<bs1.totalPrice()<<endl;	/*Output:
															   Total price of books: 600
															*/

	cout<<endl;
	bs1.removeBook(102);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	bs1.updateBookPrice(101,500);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	Book jfd=bs1.getBookInfo("Java For Dummies");
	jfd.print();  /*Output:
					 ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	Book ba[3]={Book(201,"Operating Systems",1000),Book(202,"Compilers",2000),Book(203,"Computer Networks",1500)};
	BookShop bs2("Puthighor",5);
	bs2.addBook(ba,3);
	bs2.print();  /*Output:
					 Bookshop Name: Puthighor
					 ISBN: 201, Title: Operating Systems, Price: 1000
					 ISBN: 202, Title: Compilers, Price: 2000
					 ISBN: 203, Title: Computer Networks, Price: 1500
				 */

	cout<<endl;
	BookShop bs3=bs1.mergeShop(bs2);
	bs3.setName("Mullick Brothers");
	bs3.print(); /*Output:
					Bookshop Name: Mullick Brothers
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
					ISBN: 201, Title: Operating Systems, Price: 1000
					ISBN: 202, Title: Compilers, Price: 2000
					ISBN: 203, Title: Computer Networks, Price: 1500
				 */
}
