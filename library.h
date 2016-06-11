#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include<iostream>
#include<algorithm>
using namespace std;


int const authors_size=15;

class Date
{
protected:
    int d,m,y;
public:
    void set_date(int dd,int mm,int yy)
    {
        d=dd;
        m=mm;
        y=yy;
    }
    int get_day()
    {
        return d;
    }
    int get_month()
    {
        return m;
    }

    void set_year(int yy)
    {
        y=yy;
    }
    int get_year()
    {
        return y;
    }

    void print_date()
    {
        cout<<d<<"/"<<m<<"/"<<y<<endl;
    }
};

class Base : public Date
{

protected:
    string title;
    string Category;
    int code;
    string Status;
    int byid;
public:

    virtual void set_title(string t) {}
    virtual string get_title() {}

    virtual void set_byid(int t) {}
    virtual int get_byid() {}

    virtual void set_status(string f) {}
    virtual string get_status() {}

    virtual void set_code(int c) {}
    virtual int get_code() {}

    virtual void set_cat(string c) {}
    virtual string get_cat() {}

    //Book Functions

    //Setters
    virtual void set_authors(string ar[],int size) {}
    virtual void set_ISBN(int code) {}
    virtual void set_no_of_copies(int c) {}
    virtual void set_copy_number(int n) {}

    //Getters
    virtual string get_Aindex(int index) {}
    virtual int get_ISBN() {}
    virtual int get_no_of_copies() {}
    virtual int get_copy_number() {}


    virtual  void addBook(string t,string c, int code, string s,string ar[],int size,int intsbn,int nc,int cn,int year) {}
    virtual void addTail(string t,string c, int code, string s,string ar[],int size,int intsbn,int nc,int cn,int year) {}
    virtual void removeHead() {}
    virtual void removeTail() {}
    virtual void print() {}

    virtual void addNMJ(string t,int d,int m,int y,int code,string status,string cat) {}
    virtual void printNMJ() {}
};

class Book : public Base
{
protected:
    string authors[authors_size];
    long int ISBN; //9-digit Number
    int number_of_copies;
    int copy_number;
    Date Issue;
    Date Return;
//Current Functions
public:
    Book*next;
    //Setters
    void set_issue(int day, int mon, int year)
    {
        Issue.set_date(day,mon,year);
    }
    void set_return(int day, int mon, int year)
    {
        Return.set_date(day,mon,year);
    }

    int get_dayi()
    {
        return Issue.get_day();
    }
    int get_monthi()
    {
        return Issue.get_month();
    }
    int get_yeari()
    {
        return Issue.get_year();
    }

    int get_dayr()
    {
        return Return.get_day();
    }
    int get_monthr()
    {
        return Return.get_month();
    }
    int get_yearr()
    {
        return Return.get_year();
    }
    void set_byid(int t)
    {
        byid=t;
    }
    int get_byid()
    {
        return byid;
    }
    void set_authors(string ar[],int size)
    {
        for(int i=0; i<size; i++)
        {
            authors[i]=ar[i];
        }
    }
    void set_ISBN(int code)
    {
        ISBN=code;
    }
    void set_no_of_copies(int c)
    {
        number_of_copies=c;
    }
    void set_copy_number(int n)
    {
        copy_number=n;
    }

    //Getters

    string get_Aindex(int index)
    {
        return authors[index];
    }
    int get_ISBN()
    {
        return ISBN;
    }
    int get_no_of_copies()
    {
        return  number_of_copies;
    }
    int get_copy_number()
    {
        return copy_number;
    }

//Polymorphic Functions

    void set_title(string t)
    {
        title=t;
    }
    string get_title()
    {
        return title;
    }
    void set_status(string f)
    {
        Status = f;
    }
    string get_status()
    {
        transform(Status.begin(), Status.end(), Status.begin(), ::toupper);
        return Status;
    }

    void set_code(int c)
    {
        code=c;
    }
    int get_code()
    {
        return code;
    }

    void set_cat(string c)
    {
        Category=c;
    }
    string get_cat()
    {
        return Category;
    }

};

/*NewPaper, Magazine, Journal */
class NMJ : public Base
{
public:

    //Polymorphic Functions
    NMJ * next;
    virtual void set_byid(int t)
    {
        byid=t;
    }
    virtual int get_byid()
    {
        return byid;
    }
    void set_title(string t)
    {
        title=t;
    }
    string get_title()
    {
        return title;
    }
    void set_status(string f)
    {
        Status = f;
    }
    string get_status()
    {
        transform(Status.begin(), Status.end(), Status.begin(), ::toupper);
        return Status;
    }

    void set_code(int c)
    {
        code=c;
    }
    int get_code()
    {
        return code;
    }

    void set_cat(string c)
    {
        Category=c;
    }
    string get_cat()
    {
        return Category;
    }
};
class List: public Book
{

    Book * head;
    Book * tail;
public:

    List()
    {
        head=tail=NULL;
    }

    ~ List()
    {
        delete head;
        delete tail;
    }
    Book * get_head()
    {
        return head;
    }
    void addBook(string t,string c, int code, string s,string ar[],int size,int intsbn,int nc,int cn,int year)
    {
        Book * temp= new Book;

        temp->set_title(t);
        temp->set_cat(c);
        temp->set_code(code);
        temp->set_status(s);
        temp->set_ISBN(intsbn);
        temp->set_no_of_copies(nc);
        temp->set_copy_number(cn);
        temp->set_year(year);
        temp->set_authors(ar,size);

        temp->next=head;

        if(tail==NULL)
            head=tail=temp;
        else
            head=temp;
    }
    bool issue_book(long int code)
    {
        Book * trav = head;
        while(trav!=NULL)
        {
            if(code==trav->get_code())
            {
                trav->set_status("Issued");

                return true;
            }
            trav=trav->next;
        }
        return false;
    }
    void addTail(string t,string c, int code, string s,string ar[],int size,int intsbn,int nc,int cn,int year)
    {
        Book * temp = new Book;

        temp->set_title(t);
        temp->set_cat(c);
        temp->set_code(code);
        temp->set_status(s);
        temp->set_ISBN(intsbn);
        temp->set_no_of_copies(nc);
        temp->set_copy_number(cn);
        temp->set_year(year);
        temp->set_authors(ar,size);

        temp->next=NULL;

        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;

        }
    }
    void removeHead()
    {
        Base*temp=head;
        head=head->next;
        delete temp;
    }
    void removeTail()
    {
        if(head==NULL)
        {
            cout<<"\t\t\tEmpty"<<endl;
        }
        else if(head==tail)
        {
            delete tail;
            head=tail=NULL;
        }
        else
        {
            Book *current = head;

            while(current->next!=tail)
            {
                current=current->next;
            }
            delete tail;
            current->next=NULL;
            tail=current;
        }
    }
    void print()
    {
        Book * current=head;
        int counter=0;
        while(current!=NULL)
        {
            cout<<"\n\t**************************************************************\n";
            cout<<"\t|                      Book No. "<<counter+1<<" Details                    |\n";
            cout<<"\t**************************************************************\n\n";
            cout<<endl;

            cout<<"\t\tBook Title: "<<current->get_title()<<endl<<endl;
            for(int i=0; i<authors_size; i++ )
            {
                if(current->get_Aindex(i)=="") break;
                cout<<"\t\tAuthor: "<<current->get_Aindex(i)<<endl;
            }
            counter++;
            cout<<"\t\tYear of Publication: "<<current->get_year()<<endl;
            cout<<"\n\t\tCopy Number: "<<current->get_copy_number()<<endl;
            cout<<"\t\tCategory: "<<current->get_cat()<<endl;
            cout<<"\t\tLibrary Code: "<<current->get_code()<<endl;

            if(current->get_status()=="ISSUED")
            {
                cout<<"\t\tIssued by: "<<byid<<endl;
                cout<<"\t\tIssue Date: "<<current->get_dayi()<<"/"<<current->get_monthi()<<"/"<<current->get_yeari()<<endl;
                cout<<"\t\tReturn Date: "<<current->get_dayr()<<"/"<<current->get_monthr()<<"/"<<current->get_yearr()<<endl;
            }
            cout<<"\t\tStatus: "<<current->get_status()<<endl;
            cout<<"\t\tISBN: "<<current->get_ISBN()<<endl;
            cout<<"\t\tNo. of Copies: "<<current->get_no_of_copies()<<endl;
            cout<<"\t\tCopy No: "<<current->get_copy_number()<<endl;

            current=current->next;
        }
        cout<<"\n\t**************************************************************\n";
        cout<<"\t|                      Record Finished                       |\n";
        cout<<"\t**************************************************************\n\n";
    }
    void printbcat(string cat)
    {
        Book * current=head;
        int counter=0;
        while(current!=NULL)
        {
            if(current->get_cat()==cat)
            {
                cout<<"\n\t**************************************************************\n";
                cout<<"\t|                      Book No. "<<counter+1<<" Details                    |\n";
                cout<<"\t**************************************************************\n\n";
                cout<<endl;

                cout<<"\t\tBook Title: "<<current->get_title()<<endl<<endl;
                for(int i=0; i<authors_size; i++ )
                {
                    if(current->get_Aindex(i)=="") break;
                    cout<<"\t\tAuthor: "<<current->get_Aindex(i)<<endl;
                }
                counter++;
                cout<<"\t\tYear of Publication: "<<current->get_year()<<endl;
                cout<<"\n\t\tCopy Number: "<<current->get_copy_number()<<endl;
                cout<<"\t\tCategory: "<<current->get_cat()<<endl;
                cout<<"\t\tLibrary Code: "<<current->get_code()<<endl;

                if(current->get_status()=="ISSUED")
                {
                    cout<<"\t\tIssued by: "<<byid<<endl;
                    cout<<"\t\tIssue Date: "<<current->get_dayi()<<"/"<<current->get_monthi()<<"/"<<current->get_yeari()<<endl;
                    cout<<"\t\tReturn Date: "<<current->get_dayr()<<"/"<<current->get_monthr()<<"/"<<current->get_yearr()<<endl;
                }
                cout<<"\t\tStatus: "<<current->get_status()<<endl;
                cout<<"\t\tISBN: "<<current->get_ISBN()<<endl;
                cout<<"\t\tNo. of Copies: "<<current->get_no_of_copies()<<endl;
                cout<<"\t\tCopy No: "<<current->get_copy_number()<<endl;
            }
            current=current->next;
        }
        cout<<"\n\t**************************************************************\n";
        cout<<"\t|                      Record Finished                       |\n";
        cout<<"\t**************************************************************\n\n";
    }


};

class List2: public NMJ
{

    NMJ * head;
    NMJ * tail;
public:

    List2()
    {
        head=tail=NULL;
    }
    ~ List2()
    {
        delete head;
        delete tail;
    }
    NMJ* get_head()
    {
        return head;
    }
    void addNMJ(string t,int d,int m,int y,int code,string status,string cat)
    {
        NMJ * temp= new NMJ;

        temp->set_title(t);
        temp->set_date(d,m,y);
        temp->set_code(code);
        temp->set_status(status);
        temp->set_cat(cat);

        temp->next=head;

        if(tail==NULL)
            head=tail=temp;
        else
            head=temp;
    }
    void printNMJ()
    {
        NMJ * current=head;
        int counter=0;
        while(current!=NULL)
        {
            cout<<"\n\t**************************************************************\n";
            cout<<"\t|                News Magazine No. "<<counter+1<<" Details                 |\n";
            cout<<"\t**************************************************************\n\n";
            cout<<endl;

            cout<<"\t\tTitle: "<<current->get_title()<<endl<<endl;

            counter++;
            cout<<"\t\tPublication Date: ";
            current->print_date();
            cout<<"\t\tCategory: "<<current->get_cat()<<endl;
            cout<<"\t\tLibrary Code: "<<current->get_code()<<endl;

            if(current->get_status()=="ISSUED")
            {
                cout<<"yes"<<endl;
            }
            cout<<"\t\tStatus: "<<current->get_status()<<endl;

            current=current->next;
        }
        cout<<"\n\t**************************************************************\n";
        cout<<"\t|              Magazine Record Finished                      |\n";
        cout<<"\t**************************************************************\n\n";
    }
};

class People
{
protected:
    string name;
    long int id;
    int current_issued;
    Date Issue;
    Date Return;
    int pin;
public:
    People()
    {
        name="";
        id=0;
        current_issued=0;
        Issue.set_date(0,0,0);
        Return.set_date(0,0,0);
    }
    People(string n, int i, int ci, int di,int mi,int yi,int dr,int mr,int yr)
    {
        name=n;
        id=i;
        current_issued=ci;
        Issue.set_date(di,mi,yi);
        Return.set_date(dr,mr,yr);
    }
    void set_name(string n)
    {
        name=n;
    }
    string get_name()
    {
        return name;
    }
    void set_id(int i)
    {
        id=i;
    }
    int get_id()
    {
        return id;
    }
    int get_ci()
    {
        return current_issued;
    }
    void set_ci(int ci)
    {
        current_issued=ci;
    }

    void set_issue(int day, int mon, int year)
    {
        Issue.set_date(day,mon,year);
    }
    void set_return(int day, int mon, int year)
    {
        Return.set_date(day,mon,year);
    }
    int get_pin()
    {
        return pin;
    }
    void set_pin(int p)
    {
        pin =p;
    }
    int get_dayi()
    {
        return Issue.get_day();
    }
    int get_monthi()
    {
        return Issue.get_month();
    }
    int get_yeari()
    {
        return Issue.get_year();
    }

    int get_dayr()
    {
        return Return.get_day();
    }
    int get_monthr()
    {
        return Return.get_month();
    }
    int get_yearr()
    {
        return Return.get_year();
    }

    virtual int fine() {}
    virtual void print() {}
    virtual void addstudent(string name,long int id,int pin) {}

};

class student: public People
{
protected:
    int limit=7; //Returning days limit (Book)
    string ar[3]; //List of Books
    int current;
public:
    int capacity=3;
    student*next;
    student()
    {
        current=0;
        for(int i=0; i<3; i++)
            ar[i]="";
    }
    void set_current(int c)
    {
        current = c;
    }
    int get_current()
    {
        return current;
    }
    void set_limit(int c)
    {
        limit = c;
    }
    int get_limit()
    {
        return limit;
    }
    void set_array(string a)
    {
        if(current<3)
        {
            ar[current] = a;
            current++;
        }
    }
    bool del_array(string h)
    {

        int index=0;
        for(int i=0; i<current; i++)
        {
            if(ar[i]==h)
            {
                index=i;
                break;
            }
        }
        if(current>0)
        {
            if(current==1)
            {
                ar[index]=" ";
                current--;
                return true;
            }
            for(int i=index; i<current-1; i++)
            {
                ar[i]=ar[i+1];
            }
            ar[current-1]=" ";
            current--;

            return true;
        }
        else
            return false;
        return true;
    }



    void get_array()
    {
        for(int i=0; i<current; i++)
            cout<<"\t\t\t"<<ar[i]<<endl;
    }
    student(string n, int i, int ci, int di,int mi,int yi,int dr,int mr,int yr,int li,string arr[]) : People(n,i,ci,di,mi,yi,dr,mr,yr)
    {
        limit=li;
        for(int i=0; i<3; i++)
            ar[i]=arr[i];
    }
    virtual void print()
    {
    }
    int fine()
    {
        int a,b,c,days=0;
        if(Return.get_day()> Issue.get_day() )
        {
            a=Return.get_day()-Issue.get_day();
        }
        else
        {
            a=Return.get_day()-Issue.get_day();
        }
        if(Return.get_month()>Issue.get_month())
        {
            b=Return.get_month()-Issue.get_month();
        }
        else
        {
            b=Return.get_month()-Issue.get_month();
        }
        if(Return.get_year()>Issue.get_year())
        {
            c=Return.get_year()>Issue.get_year();
        }
        else
        {
            c=Return.get_year()>Issue.get_year();
        }
        days=a+(b*30)+(c*365);
        if(days>7)
            return (days-7)*10;
        else
            return 0;
    }
    virtual student* get_head() {}
};

template<class T>
class List3
{
protected:
    T * head;
    T * tail;
public:

    List3()
    {
        head=tail=NULL;
    }
    ~ List3()
    {
        delete head;
        delete tail;
    }
    bool login(long int id,int p)
    {

        T*current=head;
        while(current!=NULL)
        {

            if(id==current->get_id() && p==current->get_pin())
            {
                return true;
                break;
            }
            current=current->next;
        }
        return false;

    }
    T* get_head()
    {
        return head;
    }
    void addstudent(string name,long int id,int pin)
    {
        T * temp= new T;

        temp->set_name(name);
        temp->set_id(id);
        temp->set_pin(pin);


        temp->next=head;

        if(tail==NULL)
            head=tail=temp;
        else
            head=temp;
    }

    void print()
    {
        T* current = head;
        while(current!=NULL)
        {
            cout<<" Name: "<<current->get_name()<<endl;
            cout<<" Id: "<<current->get_id()<<endl<<endl;
            current = current->next;
        }
    }

};
class teacher: public People
{
protected:

    int limit=90;
    string ar[10];
    int current;
public:
    int capacity=10;
    teacher()
    {
        current=0;
        for(int i=0; i<10; i++)
            ar[i]="";
    }
    teacher * next;

    void set_current(int c)
    {
        current = c;
    }
    int get_current()
    {
        return current;
    }
    void set_limit(int c)
    {
        limit = c;
    }
    int get_limit()
    {
        return limit;
    }
    void set_array(string a)
    {
        if(current<10)
        {
            ar[current] = a;
            current++;
        }
    }
    bool del_array(string h)
    {

        int index=0;
        for(int i=0; i<current; i++)
        {
            if(ar[i]==h)
            {
                index=i;
                break;
            }
        }
        if(current>0)
        {
            if(current==1)
            {
                ar[index]=" ";
                current--;
                return true;
            }
            for(int i=index; i<current-1; i++)
            {
                ar[i]=ar[i+1];
            }
            ar[current-1]=" ";
            current--;

            return true;
        }
        else
            return false;
        return true;
    }



    void get_array()
    {
        for(int i=0; i<current; i++)
            cout<<"\t\t\t"<<ar[i]<<endl;
    }

    void print()
    {
        cout<<"\t\t\t\nTeacher Name: "<<name<<endl;
        cout<<"\t\t\tTeacher Id: "<<id<<endl;
        cout<<"\t\t\tCurrent Book Issued: "<<current_issued<<endl<<endl;
        if(current_issued>0)
        {
            cout<<"\t\t\tIssued Date: "<<get_dayi()<<"/"<<get_monthi()<<"/"<<get_yeari()<<endl;
            cout<<"\t\t\tReturn Date: "<<get_dayr()<<"/"<<get_monthr()<<"/"<<get_yearr()<<endl<<endl;

        }
    }
};
class staff: public People
{
protected:

    int limit=21;
    string ar[5];

    int current;
public:
    int capacity=5;
    staff*next;
    staff()
    {
        current=0;
        for(int i=0; i<5; i++)
            ar[i]="";
    }

    void set_current(int c)
    {
        current = c;
    }
    int get_current()
    {
        return current;
    }
    void set_limit(int c)
    {
        limit = c;
    }
    int get_limit()
    {
        return limit;
    }
    void set_array(string a)
    {
        if(current<5)
        {
            ar[current] = a;
            current++;
        }
    }
    bool del_array(string h)
    {

        int index=0;
        for(int i=0; i<current; i++)
        {
            if(ar[i]==h)
            {
                index=i;
                break;
            }
        }
        if(current>0)
        {
            if(current==1)
            {
                ar[index]=" ";
                current--;
                return true;
            }
            for(int i=index; i<current-1; i++)
            {
                ar[i]=ar[i+1];
            }
            ar[current-1]=" ";
            current--;

            return true;
        }
        else
            return false;
        return true;
    }



    void get_array()
    {
        for(int i=0; i<current; i++)
            cout<<"\t\t\t"<<ar[i]<<endl;
    }

    void print()
    {
        cout<<"\nStaff Name: "<<name<<endl;
        cout<<"Staff Id: "<<id<<endl;
        cout<<"Current Book Issued: "<<current_issued<<endl<<endl;
        if(current_issued>0)
        {
            cout<<"Issued Date: "<<get_dayi()<<"/"<<get_monthi()<<"/"<<get_yeari()<<endl;
            cout<<"Return Date: "<<get_dayr()<<"/"<<get_monthr()<<"/"<<get_yearr()<<endl<<endl;

        }
    }
};

#endif // LIBRARY_H_INCLUDED
