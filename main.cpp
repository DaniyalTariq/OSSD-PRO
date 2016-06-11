#include <iostream>
#include <stdlib.h>
#include "library.h"
#include<algorithm>
#include<windows.h>
using namespace std;


int counter=0;
template<class T>
bool register_book(List &Mobj,int id, List3<T>&one);

template<class T>
void registration(T & one);
void menu();
void shortMenu();
void shortmenu2();


int main()
{


    system("color 5e");
    cout<<"\n\t\t\t|-----------------------------------|\n";
    cout<<"\t\t\t|----Library Management Software----|\n";
    cout<<"\t\t\t|-----------------------------------|\n";

// Book Stock

    Book * bPtr= NULL;
    List Mobj;
    bPtr = &Mobj;



    string ar[authors_size]= {"Bob Womb", "Jon k."};
    string ar1[authors_size]= {"Walt Hen", "Dave Jes"};
    string ar2[authors_size]= {"Orange Rend"};
    string ar3[authors_size]= {"Bill Gates","Neil Capt"};
    string ar4[authors_size]= {"Stain Wan"," A. Johnson","Shane Watson"};
    string ar5[authors_size]= {"David Mount","Ronalda Weld"};
    string ar6[authors_size]= {"Rahul Gandhi"};
    string ar7[authors_size]= {"Frank melt"," Albert X."};

    bPtr->addBook("Digital Logic Design","EE",10,"Available",ar,authors_size,125487956,500,1,1999);
    bPtr->addBook("Object Oriented Programming","CS",20,"Available",ar1,authors_size,629568224,200,1,2005);
    bPtr->addBook("Discrete Mathematics","CS",30,"Available",ar2,authors_size,524612323,800,1,2006);
    bPtr->addBook("Applied Physics","SST",40,"Available",ar3,authors_size,124545458,501,1,2000);
    bPtr->addBook("Pakistan Studies","Cultural",50,"Available",ar4,authors_size,612352121,200,1,2007);
    bPtr->addBook("Islamiat","Religious",60,"Available",ar5,authors_size,124845451,600,1,2009);
    bPtr->addBook("Al Quran","Religious",70,"Available",ar6,authors_size,124545457,556,1,2001);
    bPtr->addBook("Holy Bible","Religious",80,"Available",ar7,authors_size,621254545,254,1,1998);
    bPtr->addBook("Holy Ramayain","Religious",90,"Available",ar,authors_size,111568451,875,1,2002);
    bPtr->addBook("Programming Fundamentals","CS",100,"Available",ar2,authors_size,455565450,988,1,2003);


//News Paper Magazine Stock
    NMJ * nPtr= NULL;
    List2 Nobj;
    nPtr = &Nobj;

    nPtr->addNMJ("Alpha Bravo",17,1,2010,110,"Available","Magazine");
    nPtr->addNMJ("Express New",29,1,1999,120,"Available","Epaper");
    nPtr->addNMJ("Dawn News",19,3,1996,130,"Available","Epaper");
    nPtr->addNMJ("Design O",10,3,2006,140,"Available","Magazine");
    nPtr->addNMJ("Geo News",16,3,2009,150,"Available","Epaper");
    nPtr->addNMJ("Business News",10,1,2008,160,"Available","Epaper");
    nPtr->addNMJ("Rocket Sing",10,11,2002,170,"Available","Magazine");
    nPtr->addNMJ("Robin Hood",1,12,1992,180,"Available","Magazine");
    nPtr->addNMJ("Child Labor",1,10,2003,190,"Available","Magazine");
    nPtr->addNMJ("Detective",10,1,2004,200,"Available","Magazine");






    student * ptr;

    List3 <student> one;
    List3 <teacher> two;
    List3 <staff> three;

    int choice;
    do
    {
        menu();
        cout<<"\t\t\tEnter Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            system("cls");
            registration(one);
            break;
        }
        case 2:
        {
            system("cls");
            registration(two);

            break;
        }
        case 3:
        {
            system("cls");
            registration(three);
            break;
        }
        case 5:
        {
            system("cls");
            system("CLS");
            cout<<"\n\t\t\t\tLogin to Library as Student\n\n";
            cout<<"\t\t\tEnter Registered ID: ";


            long int id;
            int pin;
            cin>>id;
            cout<<"\t\t\tPin Code: ";
            cin>>pin;
            bool login=one.login(id,pin);
            if(login==true)
            {
                int opt;
                do
                {
                    shortMenu();

                    student * p = one.get_head();

                    cout<<"\n\t\tEnter Option: ";
                    cin>>opt;
                    if(opt==1)
                    {
                        system("cls");
                        Book * trav = Mobj.get_head();
                        while(trav!=NULL)
                        {
                            cout<<"\t\t\t"<<trav->get_cat()<<endl;
                            trav=trav->next;
                        }
                        string category;
                        cout<<"\t\t\tEnter Category: ";
                        cin>>category;
                        Mobj.printbcat(category);




                    }
                    else if(opt==2)
                    {
                        system("cls");
                        bPtr->print();

                    }
                    else if(opt==3)
                    {
                        system("cls");
                        NMJ * trav = Nobj.get_head();
                        while(trav!=NULL)
                        {
                            cout<<trav->get_cat()<<endl;
                            trav=trav->next;
                        }

                    }
                    else if(opt==4)
                    {
                        system("cls");
                        bool flag=false;
                        flag=register_book(Mobj,id,one);
                        if(flag==true)
                            cout<<"\t\t\tBook Issued Successfully"<<endl<<endl;

                        else
                            cout<<"\t\t\tBook Issue Failed"<<endl<<endl;
                    }
                    else if(opt==5)
                    {
                        system("cls");
                        Book * h = Mobj.get_head();
                        long int code;
                        cout<<"\t\t\tEnter Library Book Code: ";
                        cin>>code;

                        while(h!=NULL)
                        {
                            if(h->get_code()==code)
                            {
                                h->set_status("Available");
                                h->set_issue(0,0,0);
                                h->set_return(0,0,0);
                                string ho=h->get_title();
                                if(p->del_array(ho))
                                    cout<<"\t\t\tReturned Successfully"<<endl;
                                else
                                    cout<<"\t\t\tFailed in Returning"<<endl;
                                p->set_issue(0,0,0);
                                p->set_return(0,0,0);
                                break;
                            }
                            h=h->next;
                        }
                    }
                    else if(opt==6)
                    {
                        system("cls");
                        student * t = one.get_head();
                        cout<<"\n\t\t\tList of Books which are Issued\n\n"<<endl;
                        cout<<"\t\t-------------------------------------------\n\n";
                        while(t!=NULL)
                        {
                            if(t->get_id()==id && t->get_pin()==pin)
                            {


                                t->get_array();
                                cout<<"\n\t\t\tIssue Date: "<<t->get_dayi()<<"/"<<t->get_monthi()<<"/"<<t->get_yeari()<<endl;
                                cout<<"\t\t\tReturn Date: "<<t->get_dayr()<<"/"<<t->get_monthr()<<"/"<<t->get_yearr()<<endl;

                            }
                            t=t->next;
                        }
                        cout<<endl;
                        cout<<"\t\t-------------------------------------------\n\n";
                    }
                    else if(opt==7)
                    {
                        system("cls");
                        student * t = one.get_head();
                        while(t!=NULL)
                        {
                            if(p->get_id()==id)
                            {

                                int d,m,y;
                                do
                                {
                                    system("cls");
                                    cout<<"\t\t\tEnter Date today or greater Date to check fine: (DD MM YY) : ";
                                    cin>>d>>m>>y;
                                }
                                while((d>31 or m<1 or m>12 or y<1980));
                                p->set_return(d,m,y);
                                cout<<t->fine();
                                t=t->next;
                                break;
                            }
                        }
                        cout<<endl;

                    }
                    else if(opt==8)
                    {
                        system("cls");
                        student * t = one.get_head();
                        while(t!=NULL)
                        {
                            if(p->get_id()==id)
                            {

                                if(t->fine()==0)
                                {
                                    bool flag=false;
                                    flag=register_book(Mobj,id,one);
                                    if(flag==true)
                                        cout<<"\t\t\tBook Issued Successfully"<<endl<<endl;

                                    else
                                        cout<<"\t\t\tBook Issue Failed"<<endl<<endl;

                                }
                                t=t->next;
                            }
                        }
                        cout<<endl;
                    }
                    else if(opt==9)
                    {
                        system("cls");
                        nPtr->printNMJ();
                    }

                    else
                        cout<<"\t\t\tAn error occured, may be Limit error or Invalid Library Book Code. Try Again!!\n"<<endl;



                }
                while(opt!=10);

            }
            else
            {
                cout<<"\t\t\tInvalid Credentials\n"<<endl;
            }
            break;
        }

        case 6:
        {
            system("CLS");
            cout<<"\n\t\t\t\tLogin to Library as Teacher\n\n";
            cout<<"\t\t\tEnter Registered ID: ";


            long int id;
            int pin;
            cin>>id;
            cout<<"\t\t\tPin Code: ";
            cin>>pin;
            bool login=two.login(id,pin);
            if(login==true)
            {
                int opt;
                do
                {
                    shortMenu();

                    teacher * p = two.get_head();
                    cout<<"\n\t\tEnter Option: ";
                    cin>>opt;
                    if(opt==1)
                    {
                        system("cls");
                        Book * trav = Mobj.get_head();
                        while(trav!=NULL)
                        {
                            cout<<"\t\t\t"<<trav->get_cat()<<endl;
                            trav=trav->next;
                        }
                        string category;
                        cout<<"\t\t\tEnter Category: ";
                        cin>>category;
                        Mobj.printbcat(category);




                    }
                    else if(opt==2)
                    {
                        system("cls");
                        bPtr->print();

                    }
                    else if(opt==3)
                    {
                        system("cls");
                        NMJ * trav = Nobj.get_head();
                        while(trav!=NULL)
                        {
                            cout<<trav->get_cat()<<endl;
                            trav=trav->next;
                        }

                    }
                    else if(opt==4)
                    {
                        system("cls");
                        teacher * p = two.get_head();
                        cout<<"\t\tBook - Library Code\n\n";
                        int code;
                        cin>>code;


                        cout<<"\t\tBook Issue Request Forwarded\n"<<endl;

                        int month,day,year;
                        SYSTEMTIME st;
                        GetSystemTime(&st);
                        day = st.wDay;
                        month = st.wMonth;
                        year = st.wYear;


//cin>>day>>month>>year;
                        Mobj.set_byid(id);
                        p->set_issue(day,month,year);
                        cout<<"\t\t\tIssue Date: "<<p->get_dayi()<<"/"<<p->get_monthi()<<"/"<<p->get_yeari()<<endl;
                        int dr,mr,yr;
                        mr=p->get_monthi();
                        yr=p->get_yeari();
                        dr=p->get_dayi()+p->get_limit();
                        if(yr%4==0)
                        {
                            if(mr==2 && dr>=29)
                            {
                                dr=dr-29;
                                mr++;
                            }
                            if(mr>=12 && dr>=31)
                            {
                                dr=dr-31;
                                mr=1;
                                yr++;
                            }
                            if(dr>=30 && mr%2==0)

                            {
                                if(mr==8)
                                    dr=dr-31;
                                else
                                    dr=dr-30;
                                mr++;

                            }
                            else if(dr>=31 && mr%2!=0)
                            {
                                dr=dr-30;
                                mr++;

                            }

                        }
                        else
                        {
                            if(mr==2 && dr>=28)
                            {

                                dr=dr-28;
                                mr++;

                            }
                            else if(mr>=12 && dr>=31)
                            {
                                dr=dr-31;
                                mr=1;
                                yr++;
                            }
                            else if(dr>=30 && mr%2==0)
                            {
                                if(mr==8)
                                    dr=dr-31;
                                else dr=dr-30;
                                mr++;
                                if(mr>=12)
                                {
                                    mr=1;
                                    yr++;
                                }
                            }
                            else if(dr>=31 && mr%2!=0)
                            {
                                dr=dr-31;
                                mr++;

                            }


                        }

                        p->set_return(dr,mr,yr);
                        cout<<"\t\t\tReturn Date: "<<p->get_dayr()<<"/"<<p->get_monthr()<<"/"<<p->get_yearr()<<endl;

                        string a;


                        Book * h = Mobj.get_head();
                        bool flag=false;
                        while(h!=NULL)
                        {
                            if(h->get_code()==code && h->get_status()=="AVAILABLE" )
                            {
                                cout<<p->get_current()<<endl;
                                if(p->get_current()<p->capacity)
                                {
                                    flag=Mobj.issue_book(code);
                                    h->set_issue(day,month,year);
                                    h->set_return(dr,mr,yr);
                                    a=h->get_title();
                                    p->set_array(a);
                                    counter++;
                                    p->set_current(counter);
                                    flag=true;
                                    break;
                                }
                            }
                            h=h->next;
                        }
                        if(flag==true)
                            cout<<"\t\t\tBook Issued Successfully"<<endl<<endl;

                        else
                            cout<<"\t\t\tBook Issue Failed"<<endl<<endl;
                    }
                    else if(opt==5)
                    {
                        Book * h = Mobj.get_head();
                        long int code;
                        cout<<"\t\t\tEnter Library Book Code: ";
                        cin>>code;

                        while(h!=NULL)
                        {
                            if(h->get_code()==code)
                            {
                                h->set_status("Available");
                                h->set_issue(0,0,0);
                                h->set_return(0,0,0);
                                string ho=h->get_title();
                                if(p->del_array(ho))
                                    cout<<"\t\t\tReturned Successfully"<<endl;
                                else
                                    cout<<"\t\t\tFailed in Returning"<<endl;
                                p->set_issue(0,0,0);
                                p->set_return(0,0,0);
                                break;
                            }
                            h=h->next;
                        }
                    }
                    else if(opt==6)
                    {
                        system("cls");
                        teacher * t = two.get_head();
                        cout<<"\n\t\t\tList of Books which are Issued\n\n"<<endl;
                        cout<<"\t\t-------------------------------------------\n\n";
                        while(t!=NULL)
                        {

                            if(t->get_id()==id && t->get_pin()==pin)
                            {


                                t->get_array();
                                cout<<"\n\t\t\tIssue Date: "<<t->get_dayi()<<"/"<<t->get_monthi()<<"/"<<t->get_yeari()<<endl;
                                cout<<"\t\t\tReturn Date: "<<t->get_dayr()<<"/"<<t->get_monthr()<<"/"<<t->get_yearr()<<endl;

                            }
                            t=t->next;
                        }
                        cout<<endl;
                        cout<<"\t\t-------------------------------------------\n\n";
                    }
                    else if(opt==7)
                    {
                        system("cls");
                        teacher * t = two.get_head();
                        while(t!=NULL)
                        {
                            if(p->get_id()==id)
                            {

                                int d,m,y;
                                do
                                {
                                    system("cls");
                                    cout<<"\t\t\tEnter Date today or greater Date to check fine: (DD MM YY) : ";
                                    cin>>d>>m>>y;
                                }
                                while((d>31 or m<1 or m>12 or y<1980));
                                p->set_return(d,m,y);
                                cout<<t->fine();
                                t=t->next;
                                break;
                            }
                        }
                        cout<<endl;

                    }
                    else if(opt==8)
                    {
                        system("cls");
                        student * t = one.get_head();
                        while(t!=NULL)
                        {
                            if(p->get_id()==id)
                            {

                                if(t->fine()==0)
                                {
                                    bool flag=false;
                                    flag=register_book(Mobj,id,one);
                                    if(flag==true)
                                        cout<<"\t\t\tBook Issued Successfully"<<endl<<endl;

                                    else
                                        cout<<"\t\t\tBook Issue Failed"<<endl<<endl;

                                }
                                t=t->next;
                            }
                        }
                        cout<<endl;
                    }
                    else if(opt==9)
                    {
                        system("cls");
                        nPtr->printNMJ();
                    }

                    else
                        cout<<"\t\t\tAn error occured, may be Limit error or Invalid Library Book Code. Try Again!!\n"<<endl;



                }
                while(opt!=10);

            }
            else
            {
                cout<<"\t\t\tInvalid Credentials\n"<<endl;
            }
            break;
        }

        case 7:
        {
            system("CLS");
            cout<<"\n\t\t\t\tLogin to Library as Staff member\n\n";
            cout<<"\t\t\tEnter Registered ID: ";


            long int id;
            int pin;
            cin>>id;
            cout<<"\t\t\tPin Code: ";
            cin>>pin;
            bool login=three.login(id,pin);
            if(login==true)
            {
                int opt;
                do
                {
                    shortmenu2();

                    staff * p = three.get_head();
                    cout<<"\n\t\tEnter Option: ";
                    cin>>opt;
                    if(opt==1)
                    {
                        system("cls");
                        Book * trav = Mobj.get_head();
                        while(trav!=NULL)
                        {
                            cout<<"\t\t\t"<<trav->get_cat()<<endl;
                            trav=trav->next;
                        }
                        string category;
                        cout<<"\t\t\tEnter Category: ";
                        cin>>category;
                        Mobj.printbcat(category);




                    }
                    else if(opt==2)
                    {
                        system("cls");
                        bPtr->print();

                    }
                    else if(opt==3)
                    {
                        system("cls");
                        NMJ * trav = Nobj.get_head();
                        while(trav!=NULL)
                        {
                            cout<<trav->get_cat()<<endl;
                            trav=trav->next;
                        }

                    }
                    else if(opt==4)
                    {
                        system("cls");
                        staff * p = three.get_head();
                        cout<<"\t\tBook - Library Code\n\n";
                        int code;
                        cin>>code;


                        cout<<"\t\tBook Issue Request Forwarded\n"<<endl;

                        int month,day,year;
                        SYSTEMTIME st;
                        GetSystemTime(&st);
                        day = st.wDay;
                        month = st.wMonth;
                        year = st.wYear;


//cin>>day>>month>>year;
                        Mobj.set_byid(id);
                        p->set_issue(day,month,year);
                        cout<<"\t\t\tIssue Date: "<<p->get_dayi()<<"/"<<p->get_monthi()<<"/"<<p->get_yeari()<<endl;
                        int dr,mr,yr;
                        mr=p->get_monthi();
                        yr=p->get_yeari();
                        dr=p->get_dayi()+p->get_limit();
                        if(yr%4==0)
                        {
                            if(mr==2 && dr>=29)
                            {
                                dr=dr-29;
                                mr++;
                            }
                            if(mr>=12 && dr>=31)
                            {
                                dr=dr-31;
                                mr=1;
                                yr++;
                            }
                            if(dr>=30 && mr%2==0)

                            {
                                if(mr==8)
                                    dr=dr-31;
                                else
                                    dr=dr-30;
                                mr++;

                            }
                            else if(dr>=31 && mr%2!=0)
                            {
                                dr=dr-30;
                                mr++;

                            }

                        }
                        else
                        {
                            if(mr==2 && dr>=28)
                            {

                                dr=dr-28;
                                mr++;

                            }
                            else if(mr>=12 && dr>=31)
                            {
                                dr=dr-31;
                                mr=1;
                                yr++;
                            }
                            else if(dr>=30 && mr%2==0)
                            {
                                if(mr==8)
                                    dr=dr-31;
                                else dr=dr-30;
                                mr++;
                                if(mr>=12)
                                {
                                    mr=1;
                                    yr++;
                                }
                            }
                            else if(dr>=31 && mr%2!=0)
                            {
                                dr=dr-31;
                                mr++;

                            }


                        }

                        p->set_return(dr,mr,yr);
                        cout<<"\t\t\tReturn Date: "<<p->get_dayr()<<"/"<<p->get_monthr()<<"/"<<p->get_yearr()<<endl;

                        string a;


                        Book * h = Mobj.get_head();
                        bool flag=false;
                        while(h!=NULL)
                        {
                            if(h->get_code()==code && h->get_status()=="AVAILABLE" )
                            {
                                cout<<p->get_current()<<endl;
                                if(p->get_current()<p->capacity)
                                {
                                    flag=Mobj.issue_book(code);
                                    h->set_issue(day,month,year);
                                    h->set_return(dr,mr,yr);
                                    a=h->get_title();
                                    p->set_array(a);
                                    counter++;
                                    p->set_current(counter);
                                    flag=true;
                                    break;
                                }
                            }
                            h=h->next;
                        }
                        if(flag==true)
                            cout<<"\t\t\tBook Issued Successfully"<<endl<<endl;

                        else
                            cout<<"\t\t\tBook Issue Failed"<<endl<<endl;
                    }
                    else if(opt==5)
                    {
                        system("cls");
                        Book * h = Mobj.get_head();
                        long int code;
                        cout<<"\t\t\tEnter Library Book Code: ";
                        cin>>code;

                        while(h!=NULL)
                        {
                            if(h->get_code()==code)
                            {
                                h->set_status("Available");
                                h->set_issue(0,0,0);
                                h->set_return(0,0,0);
                                string ho=h->get_title();
                                if(p->del_array(ho))
                                    cout<<"\t\t\tReturned Successfully"<<endl;
                                else
                                    cout<<"\t\t\tFailed in Returning"<<endl;
                                p->set_issue(0,0,0);
                                p->set_return(0,0,0);
                                break;
                            }
                            h=h->next;
                        }
                    }
                    else if(opt==6)
                    {
                        system("cls");
                        staff * t = three.get_head();
                        cout<<"\n\t\t\tList of Books which are Issued\n\n"<<endl;
                        cout<<"\t\t-------------------------------------------\n\n";
                        while(t!=NULL)
                        {

                            if(t->get_id()==id && t->get_pin()==pin)
                            {


                                t->get_array();
                                cout<<"\n\t\t\tIssue Date: "<<t->get_dayi()<<"/"<<t->get_monthi()<<"/"<<t->get_yeari()<<endl;
                                cout<<"\t\t\tReturn Date: "<<t->get_dayr()<<"/"<<t->get_monthr()<<"/"<<t->get_yearr()<<endl;

                            }
                            t=t->next;
                        }
                        cout<<endl;
                        cout<<"\t\t-------------------------------------------\n\n";
                    }
                    else if(opt==7)
                    {
                        system("cls");
                        teacher * t = two.get_head();
                        while(t!=NULL)
                        {
                            if(p->get_id()==id)
                            {

                                int d,m,y;
                                do
                                {
                                    system("cls");
                                    cout<<"\t\t\tEnter Date today or greater Date to check fine: (DD MM YY) : ";
                                    cin>>d>>m>>y;
                                }
                                while((d>31 or m<1 or m>12 or y<1980));
                                p->set_return(d,m,y);
                                cout<<t->fine();
                                t=t->next;
                                break;
                            }
                        }
                        cout<<endl;

                    }
                    else if(opt==8)
                    {
                        system("cls");
                        student * t = one.get_head();
                        while(t!=NULL)
                        {
                            if(p->get_id()==id)
                            {

                                if(t->fine()==0)
                                {
                                    bool flag=false;
                                    flag=register_book(Mobj,id,one);
                                    if(flag==true)
                                        cout<<"\t\t\tBook Issued Successfully"<<endl<<endl;

                                    else
                                        cout<<"\t\t\tBook Issue Failed"<<endl<<endl;

                                }
                                t=t->next;
                            }
                        }
                        cout<<endl;
                    }
                    else if(opt==9)
                    {
                        system("cls");
                        cout<<"\t\t\tTell your Id to remove fine";
                        long int id;
                        cin>>id;
                        char o;
                        cout<<"\t\t\tEnter t for teacher or s for sudent: ";
                        cin>>o;
                        system("cls");
                        if(o=='t' or o=='T')
                        {
                            teacher * t = two.get_head();
                            while(t!=NULL)
                            {
                                if(p->get_id()==id)
                                {


                                    p->set_return(p->get_dayi(),p->get_monthi(),p->get_yeari());
                                    cout<<t->fine();
                                    t=t->next;
                                    break;
                                }
                            }
                        }
                        else if(o=='s' or o=='S')
                        {
                            student * t = one.get_head();
                            while(t!=NULL)
                            {
                                if(p->get_id()==id)
                                {


                                    p->set_return(p->get_dayi(),p->get_monthi(),p->get_yeari());
                                    cout<<t->fine();
                                    t=t->next;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            staff * t = three.get_head();
                            while(t!=NULL)
                            {
                                if(p->get_id()==id)
                                {


                                    p->set_return(p->get_dayi(),p->get_monthi(),p->get_yeari());
                                    cout<<t->fine();
                                    t=t->next;
                                    break;
                                }
                            }

                        }
                    }
                    else if(opt==10)
                    {
                        nPtr->printNMJ();
                    }
                    else
                        cout<<"\t\t\tAn error occured, may be Limit error or Invalid Library Book Code. Try Again!!\n"<<endl;



                }
                while(opt!=11);

            }
            else
            {
                cout<<"\t\t\tInvalid Credentials\n"<<endl;
            }
            break;
        }

        default:
            cout<<"\t\t\tInvalid Input"<<endl;
        }
    }
    while(choice!=-1);
    return 0;
}



//Functions

template<class T>
bool register_book(List &Mobj,int id, List3<T>&one)
{
    T * p = one.get_head();
    cout<<"\t\tBook - Library Code\n\n";
    int code;
    cin>>code;


    cout<<"\t\t\t\t\tBook Issue Request Forwarded\n"<<endl;

    int month,day,year;
    SYSTEMTIME st;
    GetSystemTime(&st);
    day = st.wDay;
    month = st.wMonth;
    year = st.wYear;


//cin>>day>>month>>year;
    Mobj.set_byid(id);
    p->set_issue(day,month,year);
    cout<<"\t\t\tIssue Date: "<<p->get_dayi()<<"/"<<p->get_monthi()<<"/"<<p->get_yeari()<<endl;
    int dr,mr,yr;
    mr=p->get_monthi();
    yr=p->get_yeari();
    dr=p->get_dayi()+p->get_limit();
    if(yr%4==0)
    {
        if(mr==2 && dr>=29)
        {
            dr=dr-29;
            mr++;
        }
        if(mr>=12 && dr>=31)
        {
            dr=dr-31;
            mr=1;
            yr++;
        }
        if(dr>=30 && mr%2==0)

        {
            if(mr==8)
                dr=dr-31;
            else
                dr=dr-30;
            mr++;

        }
        else if(dr>=31 && mr%2!=0)
        {
            dr=dr-30;
            mr++;

        }

    }
    else
    {
        if(mr==2 && dr>=28)
        {

            dr=dr-28;
            mr++;

        }
        else if(mr>=12 && dr>=31)
        {
            dr=dr-31;
            mr=1;
            yr++;
        }
        else if(dr>=30 && mr%2==0)
        {
            if(mr==8)
                dr=dr-31;
            else dr=dr-30;
            mr++;
            if(mr>=12)
            {
                mr=1;
                yr++;
            }
        }
        else if(dr>=31 && mr%2!=0)
        {
            dr=dr-31;
            mr++;

        }


    }

    p->set_return(dr,mr,yr);
    cout<<"\t\t\tReturn Date: "<<p->get_dayr()<<"/"<<p->get_monthr()<<"/"<<p->get_yearr()<<endl;

    string a;


    Book * h = Mobj.get_head();
    bool flag=false;
    while(h!=NULL)
    {
        if(h->get_code()==code && h->get_status()=="AVAILABLE" )
        {
            cout<<p->get_current()<<endl;
            if(p->get_current()<p->capacity)
            {
                flag=Mobj.issue_book(code);
                h->set_issue(day,month,year);
                h->set_return(dr,mr,yr);
                a=h->get_title();
                p->set_array(a);
                counter++;
                p->set_current(counter);
                return true;
                break;
            }
        }
        h=h->next;
    }
    return false;
}

template<class T>
void registration(T & one)
{

    cout<<"\t\t\tEnter Name: ";
    string name;
    cin.ignore();
    getline(cin,name);

    cout<<"\t\t\tEnter ID: ";
    int id;
    cin>>id;
    cout<<"\t\t\tEnter Pin Code (Integers): ";
    int pin;
    cin>>pin;

    one.addstudent(name,id,pin);

    cout<<"\t\t\tRecord Registered Successfully"<<endl;
}
void menu()
{
    cout<<"\n\t\t\tPress 1 to Register in Library as Student"<<endl;
    cout<<"\t\t\tPress 2 to Register in Library as Teacher"<<endl;
    cout<<"\t\t\tPress 3 to Register in Library as Staff"<<endl;
    cout<<"\t\t\tPress 5 to Login as Student"<<endl;
    cout<<"\t\t\tPress 6 to Login as Teacher"<<endl;
    cout<<"\t\t\tPress 7 to Login as Staff"<<endl;
}
void shortMenu()
{
    cout<<"\n\t\t\tWelcome to Alpha Library\n\n";
    cout<<"\t\t\tPress 1 - Categories of Books"<<endl;
    cout<<"\t\t\tPress 2 - List of Books"<<endl;
    cout<<"\t\t\tPress 3 - Categories of Magazines/News Paper/Journal"<<endl;
    cout<<"\t\t\tPress 4 - Issued Books"<<endl;
    cout<<"\t\t\tPress 5 - Return Books"<<endl;
    cout<<"\t\t\tPress 6 - See Issue Books"<<endl;
    cout<<"\t\t\tPress 7 - See Fine by Entering Actual Date"<<endl;
    cout<<"\t\t\tPress 8 - Re-Issue Books"<<endl;
    cout<<"\t\t\tPress 9 - List of Magazines/News Paper/Journal"<<endl;
    cout<<"\n\t\tPress 10 - Main Menu"<<endl;

}
void shortmenu2()
{

    cout<<"\n\t\t\tWelcome to Alpha Library\n\n";
    cout<<"\t\t\tPress 1 - Categories of Books"<<endl;
    cout<<"\t\t\tPress 2 - List of Books"<<endl;
    cout<<"\t\t\tPress 3 - Categories of Magazines/News Paper/Journal"<<endl;
    cout<<"\t\t\tPress 4 - Issue Books"<<endl;
    cout<<"\t\t\tPress 5 - Return Books"<<endl;
    cout<<"\t\t\tPress 6 - See Issued Books"<<endl;
    cout<<"\t\t\tPress 7 - See Fine by Entering Actual Date"<<endl;
    cout<<"\t\t\tPress 8 - Re-Issue Books"<<endl;
    cout<<"\t\t\tPress 9 - Remove Fine"<<endl;
    cout<<"\t\t\tPress 10 - List of Magazines/News Paper/Journal"<<endl;
    cout<<"\n\t\tPress 11 - Main Menu"<<endl;
}


