//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//+++++CLASS XII COMPUTER SCIENCE PROJECT+++++
//____________________________________________________________________________
//................T  R  A  V  E  L         A  G  E  N  C  Y...................
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		     //GLOBAL DECLARATION OF DATA MEMBERS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int c=500,r=100,cy,cm,cd;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			  //HEADER FILES!!
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include<fstream.h>
   #include<conio.h>
      #include<string.h>
	 #include<stdio.h>
	    #include<stdlib.h>
	       #include<dos.h>
//-----------------------------------------------------------------------------
				     //------------------------------------------
				     //NON MEMBER FUNCTION PROTOTYPE

void border();
void show_booking();
int search_passenger(int);
void successful_booking();
void remove_booking_by_date();
void show_successful_booking();
void cancelled_booking();
void show_cancelled_booking();
//----------------------------------------------------------------------------
				     //----------------------------------------
				     //CLASS OF VEHICLE
class vehicle
{
int vehicle_no,seats,rid;
char vehicle_type[30],ac,vehiclestatus[20];
public:

       int vehicleid,byear,bmonth,bdate,a;


       int getvehicleid()
       {
       return vehicleid;
       }
       int getseats()
       {
       return seats;
       }
       char* getvehicle_type()
       {
       return vehicle_type;
       }
       char getac()
       {
       return ac;
       }
       int getvehicle_no()
       {
       return vehicle_no;
       }


       vehicle()                    //CONSTRUCTOR
       {
       vehicleid=1;
       a=0;
       }

				    //DEFINITION OF NON INLINE FUNCTION
       int assignvehicleid();
       int search_vehicle(int rid);
       void enter_info();
       void getinfo();
       void remove_vehicle();
       void update_vehicle(int);
       void display_vehicle(int);

       };
//----------------------------------------------------------------------------------
				    //----------------------------------------------
				    //CLASS OF PASSENGER
class passenger
{
int payment,place_code,adhaar_no,no_of_adults,no_of_children,distance,
customer_phoneno,customer_addharno,fare,bookingid,status,date,year,month,
phone_no;
char driver_name[30],driver_address[50],customer_address[50];
public:
       vehicle v;
       char destination[89],pick_point[90],customer_name[50];

				   //CONSTRUCTOR
	passenger()
	{
	 bookingid=1;
	 date=0;
	 month=0;
	 year=0;
	 place_code=0;
	 adhaar_no=0;
	 phone_no=0;
	 no_of_adults=0;
	 no_of_children=0;
	 distance=0;
	 fare=0;
	 customer_addharno=0;
	 customer_phoneno=0;
	 strcpy(driver_name,"null");
	 strcpy(driver_address,"null");
	 strcpy(destination,"null");
	 strcpy(pick_point,"null");
	 strcpy(customer_name,"null");
	 strcpy(customer_address,"null");
	}

      int getstatus()
	{
	 return status;
	}
      int getdate()
	{
	 return date;
	}
      int getmonth()
	{
	 return month;
	}
      int getyear()
	{
	 return year;
	}
      int getbookingid()
	{
	 return bookingid;
	}

				      //DEFINITION OF INLINE FUNCTION
      int assignbookingid();
      void tenter();
      int booking();
      void tdisplay();
      void update_booked(int);
      void cancel_booking(int);
      void issue_bill();
      int check(int,int,int);
 }t;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				      //FUNCTION TO ASSIGN VEHICLE ID
int vehicle::assignvehicleid()
      {
      vehicleid=1;
      ifstream ifs;
      ifs.open("vehicle.dat",ios::binary);
      while(ifs.read((char*)&t,sizeof(t)))
      {
      }
      if(vehicleid==1)
      {
      vehicleid=c;
      ifs.close();
      return vehicleid;
      }
      else
      {
      vehicleid=vehicleid+1;
      ifs.close();
      return vehicleid;
      }
      }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				      //FUNCTION TO SEARCH A VEHICLE

int vehicle:: search_vehicle(int rid)
       {
       int r;
       ifstream ifs;
       ifs.open("vehicle.dat",ios::binary);
       while(!ifs.eof())
       {
       ifs. read((char*)&t,sizeof(t));
       if(rid==t.v.getvehicleid())
       {
       ifs.close();
       return 0;
       }
       else
       r=1;
       }
       if(r==1)
       ifs.close();
       return 1;
       }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				     //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				     //FUNCTION TO ENTER DETAILS OF VEHICLE

void vehicle::enter_info()
{
 clrscr();
 border();
gotoxy(3,3); cout<<" ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± ";
gotoxy(3,4); cout<<"	     E N T E R      V E H I C L E      D E T A I L S          ";
gotoxy(3,5); cout<<" ________________________________________________________________ ";
gotoxy(3,6); cout<<" **************************************************************** ";
gotoxy(4,8); cout<<" VEHICLE NO=>";
gotoxy(20,8); cin>>vehicle_no;
gotoxy(4,10);cout<<" SEATS=>";
gotoxy(20,10);cin>>seats;
gotoxy(4,12);cout<<" AC(y/n)=>";
gotoxy(20,12);cin>>ac;
gotoxy(4,14);cout<<" VEHICLE TYPE=>";
gotoxy(20,14);cin>>vehicle_type;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				     //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				     //FUNCTION TO GET DETAILS OF VEHICLE
void vehicle:: getinfo()
{
 vehicleid=assignvehicleid();
 enter_info();
gotoxy(6,17);cout<<" YOUR VEHICLE ID IS="<<vehicleid;
gotoxy(3,18);cout<<" ________________________________________________________________";
gotoxy(3,19);cout<<" ****************************************************************";
gotoxy(3,20);cout<<" ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
 }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				     //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				     //FUNCTION TO REMOVE A VEHICLE
void vehicle:: remove_vehicle()
{
  clrscr();
  border();
  int rid;
  ifstream ifs;
  ofstream ofs;
  ifs.open("vehicle.dat") ;
  ofs.open("new.dat",ios::binary|ios::app) ;
  gotoxy(8,5);cout<<" BEFORE DELETING ANY VEHICLE IT IS MANDATORY FOR THE VEHICLE";
  gotoxy(15,6);cout<<" TO COMPLETE ALL ITS EXISTING BOOKINGS";
  gotoxy(8,9);cout<<" ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
  gotoxy(8,10);cout<<" º	            REMOVE A VEHICLE                        º  ";
  gotoxy(8,11);cout<<" º	          --------------------                      º  ";
  gotoxy(8,12);cout<<" º  ENTER VEHICLE ID- ";gotoxy(30,12);cin>> rid;gotoxy(69,12);cout<<"º  ";


  int p=search_vehicle(rid);
  if(p==0)
  {
  gotoxy(8,13);cout<<" º  **********VEHICLE IS SUCCESSFULLY REMOVED**********      º";
  while(!ifs.eof())
     {
      ifs.read((char *)&t,sizeof(t));
      if(ifs.eof())break;
      if(t.v.getvehicleid()!=rid)
      ofs.write ((char *)&t,sizeof(t));
      }
   }
  else if(p!=0)
   gotoxy(8,13);cout<<" º          *********ID NOT FOUND*********                   º";
   gotoxy(8,14);cout<<" ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± ";
 ifs.close();
 ofs.close();
 remove("vehicle.dat");
 rename("new.dat","vehicle.dat");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				     //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				     //FUNCTION TO UPDATE A VEHICLE
void vehicle::update_vehicle(int id)
{
int q;
passenger p;
p.v.enter_info();
p.v.vehicleid=id;
fstream fs;
fs.open("vehicle.dat",ios::in|ios::out|ios::binary);
while(!fs.eof())
{
q=fs.tellg();
fs.read((char*)&t,sizeof(t));
if(fs.eof())break;
if(t.v.getvehicleid()==id)
{
fs.seekg(q);
fs.write((char*)&p,sizeof(p));
}
}
fs.close();
}

void vehicle::display_vehicle(int imt)
{
       gotoxy(1,imt);cout<<"±±"<<vehicleid;gotoxy(18,imt);cout<<"±±"<<getvehicle_no();gotoxy(35,imt);cout<<"±±"<<getvehicle_type();gotoxy(55,imt);cout<<"±±"<<getac();gotoxy(65,imt);cout<<"±±"<<getseats();gotoxy(79,imt);cout<<"±";

}

//------------------------------------------------------------------------------------
				     //------------------------------------------------

		 //FUNCTION TO ASSIGN BOOKING ID OF A PASSENGER

int passenger::assignbookingid()
{
bookingid=1;
ifstream ifs;
ifs.open("ttravel.dat",ios::binary);
while(ifs.read((char*)&t,sizeof(t)))
{
}
if(bookingid==1)
{
bookingid=r;
ifs.close();
return bookingid;}
else
{
bookingid=bookingid+1;
ifs.close();
return bookingid;
}
}

//--------------------------------------------------------------------------------------------------------
				     //------------------------------------------------------------------

		  //FUNCTION TO ENTER DETAILS OF A PASSENGER

void passenger::tenter()
{
gotoxy(30,9);cout<<" ENTER THE DETAILS:-";
gotoxy(3,10);cout<<" DATE OF BOOKING         -";
cin>>date;
gotoxy(3,11);cout<<" MONTH OF BOOKING        -";
cin>>month;
gotoxy(3,12);cout<<" YEAR OF BOOKING         -";
cin>>year;
gotoxy(3,13);cout<<" CUSTOMER NAME           -";
cin>>customer_name;
gotoxy(3,14);cout<<" CUSTOMER ADDRESS        -";
gets(customer_address);
gotoxy(3,15);cout<<" CUSTOMER AADHAAR NUMBER -";
cin>>customer_addharno;
gotoxy(3,16);cout<<" CUSTOMER PHONE NUMBER   -";
cin>>customer_phoneno;
gotoxy(3,17);cout<<" NUMBER OF ADULTS        -";
cin>>no_of_adults;
gotoxy(3,18);cout<<" NUMBER OF CHILDREN      -";
cin>>no_of_children;
gotoxy(3,19);cout<<" DESTINATION             -";
gets(destination);
gotoxy(3,20);cout<<" PICK POINT              -";
gets(pick_point);

}
//------------------------------------------------------------------------------------
				     //-----------------------------------------------

		  //FUNCTION FOR BOOKING A VEHICLE

int passenger::booking()
{
gotoxy(3,3);cout<<"ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ ";
gotoxy(3,4);cout<<"º>>>>>>>>>        W e L c O m E   T O   B o O k I n G        <<<<<<<<<º";
gotoxy(3,5);cout<<"º.........        ___________________________________        .........º";
gotoxy(3,6);cout<<"º:::::::::::::::          O F    V e H i C l E         :::::::::::::::º";
gotoxy(3,7);cout<<"º_____________________________________________________________________º";


int bookingid=assignbookingid();
ofstream ofs;
ofs.open("ttravel.dat",ios::binary|ios::app);
int n;
tenter();
int ee=check(date,month,year);
if(ee==0)
{
ofs.close();
cout<<"\n\n SORRY!!";
return 0;    }
int qq;
cout<<"\n\n ENTER CHOICE-";
cin>>qq;
t.v.vehicleid=qq;
t.payment=((no_of_adults+no_of_children)*1000);
ofs.write((char*)&t,sizeof(t));
ofs.close();
clrscr();
border();
gotoxy(3,3);cout<<"ºYOUR PAYMENT IS-"<<t.payment;
gotoxy(3,4);cout<<"ºPAYMENT OPTIONS -";
gotoxy(3,5);cout<<"º1- CASH";
gotoxy(3,6);cout<<"º2- CREDIT";
gotoxy(3,7);cout<<"º3- ATM";
gotoxy(3,8);cout<<"ºENTER YOUR CHOICE-";
cin>>n;
switch(n)
{
      case 1:
      {
      int u,m,n;
gotoxy(3,10);      cout<<"ºPAYMENT THROUGH CASH-";
gotoxy(3,11);      cout<<"º_______________________";
gotoxy(3,12);      cout<<"º1- WANT TO PAY BEFORE JOURNEY";
gotoxy(3,13);      cout<<"º2- WANT TO PAY AFTER JOURNEY";
gotoxy(3,14);      cout<<"º Y O U R   C H O I C E...";
gotoxy(3,15);      cin>>u;
	    switch(u)
	    {
       //....................................................................
       case 1:
       {
       clrscr();
gotoxy(3,10);       cout<<"º****GOOD DECISION****\n";
gotoxy(3,11);       cout<<"ºPAY BEFORE JOURNEY AND GET 10% DISCOUNT\n";
gotoxy(3,12);       cout<<"º~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
gotoxy(3,13);       cout<<"º---THANKS FOR PAYING---\n";
gotoxy(3,14);       cout<<"ºHAVE A SAFE AND ENJOYING TRIP!!\n";
       }break;
       //....................................................................
       case 2:
       {
       clrscr();
gotoxy(3,10);       cout<<"-----NO ISSUE-----\n";
gotoxy(3,11);       cout<<".....YOU CAN PAY LATER.....\n";
gotoxy(3,12);       cout<<"****SORRY BUT NO DISCOUNT****\n";
       }break;
       }break;
	    }
       //....................................................................
       case 2:
       {
       int o;
       char c;
gotoxy(3,10);       cout<<"****PAYMENT THROUGH CREDIT CARD****";
gotoxy(3,11);       cout<<"1.LOGIN TO NET BANKING    -:";
gotoxy(3,12);       cout<<"2.ENTER THE ACCOUNT NUMBER-:";
		    cin>>o;
gotoxy(3,13);       cout<<"3.NAME OF BANK            -:";
		    cin>>c;
gotoxy(3,14);       cout<<"PAYMENT IS DONE...          ";
gotoxy(3,15);       cout<<"|| THANKS FOR PAYING ||     ";
       }break;
       //...................................................................
       case 3:
       {
       int a;
gotoxy(3,10);       cout<<"PAYMENT THROUGH ATM";
gotoxy(3,11);       cout<<"ENTER YOUR ATM PIN";
		    cin>>a;
gotoxy(3,12);       cout<<"YOUR TRANSACTION IS COMPLETE";
gotoxy(3,13);       cout<<"****************************";
       }break;
       //....................................................................
}
gotoxy(30,15);cout<<"YOUR BOOKING ID IS-"<<bookingid;
return 1;
}
//----------------------------------------------------------------------------------
				  //-----------------------------------------------

		   //FUNCTION TO DISPLAY DETAILS OF A PASSENGER

void passenger::tdisplay()
{
cout<<"\n DATE OF BOOKING-";
cout<<date;
cout<<"\n MONTH OF BOOKING-";
cout<<month;
cout<<"\n YEAR OF BOOKING-";
cout<<year;
cout<<"\n CUSTOMER NAME -";
cout<<(customer_name);
cout<<"\n CUSTOMER ADDRESS -";
cout<<(customer_address);
cout<<"\n CUSTOMER AADHAAR NUMBER -";
cout<<customer_addharno;
cout<<"\n CUSTOMER PHONE NUMBER -";
cout<<customer_phoneno;
cout<<"\n NUMBER OF ADULTS -";
cout<<no_of_adults;
cout<<"\n NUMBER OF CHILDREN -";
cout<<no_of_children;
cout<<"\n DESTINATION -";
cout<<(destination);
cout<<"\n PICK POINT -";
cout<<(pick_point);
}
//----------------------------------------------------------------------------
				  //-------------------------------------------------

		  //update_booked() FUNCTION START

void passenger::update_booked(int id)
{
int q;
passenger e;
gotoxy(3,3);cout<<"ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ ";
gotoxy(3,4);cout<<"º>>>>>>>>>        W e L c O m E   T O   U P D A T I O N      <<<<<<<<<º";
gotoxy(3,5);cout<<"º.........        ___________________________________        .........º";
gotoxy(3,6);cout<<"º:::::::::::::::          O F    V e H i C l E         :::::::::::::::º";
gotoxy(3,7);cout<<"º_____________________________________________________________________º";

t.tenter();
fstream fs;
fs.open("ttravel.dat",ios::in|ios::out|ios::binary);
while(!fs.eof())
{
q=fs.tellg();
fs.read((char*)&e,sizeof(e));
if(fs.eof())break;
if(e.getbookingid()==id)
{
fs.seekg(q);
fs.write((char*)&t,sizeof(t));
}
}
fs.close();
}
//------------------------------------------------------------------------------------
				   //-----------------------------------------------------
			  //cancel_booking() FUNCTION START
void passenger::cancel_booking(int id)
{
ifstream ifs;
ofstream ofs;
ifs.open("ttravel.dat",ios::binary) ;
ofs.open("te.dat",ios::binary|ios::app) ;
while(!ifs.eof())
{

ifs.read((char *)&t,sizeof(t));
if(ifs.eof())
break;
cout<<t.getbookingid()<<endl;
if(t.getbookingid()!=id)
ofs.write ((char *)&t,sizeof(t));
else
cancelled_booking();
}
ifs.close();
ofs.close();
remove("ttravel.dat");
rename("te.dat","ttravel.dat");
}
//-------------------------------------------------------------------------------
				   //---------------------------------------------

		 //check() FUNCTION START

int passenger::check(int d,int m,int y)
{
clrscr();
int pn=8,uu=1,mn=0,imt=5;
ifstream ifs;
passenger a;
ifs.open("vehicle.dat",ios::binary);
while(ifs.read((char*)&a,sizeof(a)))
{
ifstream ifn;
passenger ta;
ifn.open("ttravel.dat",ios::binary);
while(ifn.read((char*)&ta,sizeof(ta)))
{
if((d==ta.date)&&(m==ta.month)&&(y==ta.year)&&(a.v.vehicleid==ta.v.vehicleid))
{
pn=0;
break;
}
else
{
if(mn==0)
{
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
cout<<"\n±±   VEHICLEID   ±±   VEHICLE NO  ±±   VEHICLE TYPE   ±±   AC   ±±   SEATS   ±±";
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
++mn;
}
pn=1;
}
}
ifn.close();

if(pn==1)
{
gotoxy(1,imt);cout<<"±±"<<a.v.vehicleid;gotoxy(18,imt);cout<<"±±"<<a.v.getvehicle_no();gotoxy(35,imt);cout<<"±±"<<a.v.getvehicle_type();gotoxy(55,imt);cout<<"±±"<<a.v.getac();gotoxy(65,imt);cout<<"±±"<<a.v.getseats();gotoxy(79,imt);cout<<"±";
++imt;
}

if(pn==8)
{
if(uu==1)
{
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
cout<<"\n±±   VEHICLEID   ±±   VEHICLE NO  ±±   VEHICLE TYPE   ±±   AC   ±±   SEATS   ±±";
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
}
gotoxy(1,imt);cout<<"±±"<<a.v.vehicleid;gotoxy(18,imt);cout<<"±±"<<a.v.getvehicle_no();gotoxy(35,imt);cout<<"±±"<<a.v.getvehicle_type();gotoxy(55,imt);cout<<"±±"<<a.v.getac();gotoxy(65,imt);cout<<"±±"<<a.v.getseats();gotoxy(79,imt);cout<<"±";
++imt;
++uu;
}
}
if(pn==1)
{
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
ifs.close();
return pn;
}
if(pn==0)
{
ifs.close();
return 0;
}
if(pn==8)
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
ifs.close();
return pn;
}                       //check() FUNCTION END
//----------------------------------------------------------------------------------------
				   //-----------------------------------------------

			//border() FUNCTION START

void border()
{
for(int i=1;i<80;i++)
{
cout<<char(517);
}
cout<<"\n";
for(i=1;i<24;i++)
{
cout<<char(517);
cout<<"\n";
}
for(i=1;i<80;i++)
{
cout<<char(517);
}
for(i=1;i<=24;i++)
{
gotoxy(80,i);
cout<<char(517);
}
}
//----------------------------------------------------------------------------------------
				   //--------------------------------------------------------

		    //show_booking() FUNCTION START

void show_booking()
{
clrscr();
ifstream ifs;
int imt=12;
ifs.open("ttravel.dat",ios::binary);
cout<<"\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
cout<<"\n\t\t\tBOOKING INFORMATION\n";
cout<<"\n\t\t\t*******************\n";
cout<<"____________________________________________________________________________\n";
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
cout<<"\n±±   BOOK ID     ±± CUSTOMER NAME ±±       FROM     ±±DESTINATION±±VEHICLE ID ±";
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
while(!ifs.eof())
{
ifs. read((char*)&t,sizeof(t));
if(ifs.eof())
break;
gotoxy(1,imt);cout<<"±±"<<t.getbookingid();gotoxy(18,imt);cout<<"±±"<<t.customer_name;gotoxy(35,imt);cout<<"±±"<<t.pick_point;gotoxy(53,imt);cout<<"±±"<<t.destination;gotoxy(66,imt);cout<<"±±"<<t.v.vehicleid;gotoxy(79,imt);cout<<"±";
++imt;
}
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
ifs.close();
}                     //show_booking() FUNCTION END
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				   //----------------------------------------------------------------------------------------------------
		      //search_passenger() FUNCTION START

int search_passenger(int id)
{
int r=0,p;
ifstream ifs;
ifs.open("ttravel.dat",ios::binary);
while(!ifs.eof())
{
ifs. read((char*)&t,sizeof(t)) ;
if(ifs.eof())
break;
if(t.getbookingid()==id)
{
ifs.close();
return 0;
}
else
r=1;
}
if(r==1)
ifs.close();
return 1;
}                      //search_passenger() FUNCTION END
//---------------------------------------------------------------------------------
				   //----------------------------------------------

		      //successful_booking() FUNCTION START

void successful_booking()
{
ofstream ofs("success.dat",ios::binary|ios::app);
ofs.write((char*)&t,sizeof(t));
ofs.close();
}                     //successful_booking() FUNCTION END
//----------------------------------------------------------------------------------
				    //--------------------------------------------

		      //show_successful_booking() FUNCTION START
void show_successful_booking()
{
ifstream ifs("success.dat",ios::binary) ;
cout<<"\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
		  cout<<"\n\t\t\tBOOKING INFORMATION\n";
		  cout<<"\n\t\t\t*******************\n";
		  cout<<"____________________________________________________________________________\n";
		  cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
		  cout<<"\n±±   BOOK ID     ±± CUSTOMER NAME ±±       FROM     ±±DESTINATION±±VEHICLE ID ±";
		  cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";


int imt=12;
while(!ifs.eof())
{
ifs.read((char *)&t,sizeof(t));
if(ifs.eof())
break;
gotoxy(1,imt);cout<<"±±"<<t.getbookingid();gotoxy(18,imt);cout<<"±±"<<t.customer_name;gotoxy(35,imt);cout<<"±±"<<t.pick_point;gotoxy(53,imt);cout<<"±±"<<t.destination;gotoxy(66,imt);cout<<"±±"<<t.v.vehicleid;gotoxy(79,imt);cout<<"±";
++imt;
}
ifs.close();
}                 //show_successful_booking FUNCTION END
//-----------------------------------------------------------------------------------------------------
				    //-------------------------------------------------------------

		 //remove_booking_bydate FUNCTION START

void remove_booking_bydate()
{
ifstream ifs;
ofstream ofs;
ifs.open("ttravel.dat",ios::binary) ;
ofs.open("te.dat",ios::binary|ios::app) ;
while(!ifs.eof())
{

ifs.read((char *)&t,sizeof(t));
if(ifs.eof())
break;
if((t.getdate()<=cd&&t.getmonth()<=cm&&t.getyear()<=cy)||(t.getyear()<cy)||(t.getyear()==cy&&t.getmonth()<cm))
successful_booking();
else
ofs.write ((char *)&t,sizeof(t));
}
ifs.close();
ofs.close();
remove("ttravel.dat");
rename("te.dat","ttravel.dat");
}                    //remove_booking_bydate FUNCTION END
//----------------------------------------------------------------------------------
				    //--------------------------------------------------

		    //cancelled_booking() FUNCTION START

void cancelled_booking()
{
ofstream ofs("cancel.dat",ios::binary|ios::app);
ofs.write((char*)&t,sizeof(t));
ofs.close();
}                   //cancelled_booking() FUNCTION END
//-------------------------------------------------------------------------------
				    //---------------------------------------------

		  //show_cancelled_booking() FUNCTION START

void show_cancelled_booking()
{
clrscr();
cout<<"\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
cout<<"\n\t\t\tBOOKING INFO\n";
cout<<"\n\t\t\t************\n";
cout<<"____________________________________________________________________________\n";
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
cout<<"\n±±   BOOK ID     ±± CUSTOMER NAME ±±       FROM     ±±DESTINATION±±VEHICLE ID ±";
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";

int imt=12;
ifstream ifs("cancel.dat",ios::binary) ;
while(!ifs.eof())
{
ifs.read((char *)&t,sizeof(t));
if(ifs.eof())
break;
gotoxy(1,imt);cout<<"±±"<<t.getbookingid();gotoxy(18,imt);cout<<"±±"<<t.customer_name;gotoxy(35,imt);cout<<"±±"<<t.pick_point;gotoxy(53,imt);cout<<"±±"<<t.destination;gotoxy(66,imt);cout<<"±±"<<t.v.vehicleid;gotoxy(79,imt);cout<<"±";
++imt;
}
cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
ifs.close();
}
		     //show_cancelled_booking() FUNCTION END
//-----------------------------------------------------------------------------------
				  //----------------------------------------------------------------------------------

		     //booking_case() FUNCTION START

void booking_case()
{
char c;
int choice,id;
do
{
clrscr();
border();
int choice;
gotoxy(22,4);cout<<"B O O K I N G   M E N U ";
gotoxy(19,5);cout<<"++++++++++++++++++++++++++++++";
gotoxy(8,10);cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± ";
gotoxy(8,11);cout<<"± 1.  BOOKING                                                  ± ";
gotoxy(8,12);cout<<"± 2.  SEARCH                                                   ± ";
gotoxy(8,13);cout<<"± 3.  UPADATE BOOKING                                          ± ";
gotoxy(8,14);cout<<"± 4.  CANCEL BOOKING                                           ± ";
gotoxy(8,15);cout<<"± 5.  DISPLAY ALL BOOKING                                      ± ";
gotoxy(8,16);cout<<"± 6.  GO TO MAIN MENU                                          ± ";
gotoxy(8,17);cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± ";
gotoxy(8,19);cout<<"ENTER YOUR CHOICE-";
cin>>choice;
switch(choice)
{
 case 1:
       {
	clrscr();
	border();
	t.booking();
	}
	break;
	//^^^^^^^^^^

 case 2:
	{
	clrscr();
	cout<<"\nEnter booking id you want to search for:-";
	cin>>id;
	int a=search_passenger(id);
	if(a==0)
	{
	t.tdisplay();
	}
	else
	cout<<"\n****RESULT NOT FOUND****\n";
	}
	break;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 case 3:
	{
	clrscr();
	cout<<"\nEnter booking id you want to update:-";
	cin>>id;
	int a=search_passenger(id);
	if(a==0)
	{
	t.update_booked(id);
	}
	else
	cout<<"\n****RESULT NOT FOUND****\n";
	}
	break;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

 case 4:
	{
	clrscr();
	cout<<"\n__________________________________________________";
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n\t\tCANCEL BOOKING";
	cout<<"\n\t\t______________";
	cout<<"\n\nEnter id you want to cancel:-  ";
	cin>>id;
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n__________________________________________________";
	int Q=search_passenger(id);
	if(Q==0)
	{
	t.cancel_booking(id);
	cout<<"\nBooking is cancelled succesfully!!";
	}
	else
	{
	cout<<"\nSORRY!!!!!!!!! id not found";
	cout<<"\n__________________________________________________";
	}
	}
	break;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

 case 5:
	{
	clrscr();
	show_booking();
	}
	break;
	//^^^^^^^^^^^^^^^^^^^^^
case 6:break;
}
getch();
clrscr();
border();
gotoxy(20,8); cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° ";
gotoxy(20,9); cout<<"°                                            ° ";
gotoxy(20,10);cout<<"°  DO YOU WANT TO CONTINUE WITH SAME PORTAL  °";
gotoxy(20,11);cout<<"° ========================================== °";
gotoxy(20,12);cout<<"°                                            °";
gotoxy(20,13);cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
gotoxy(24,12);cin>>c;
}
while(c=='y'||c=='Y');
}
//^^^^^^^^^^^^^^^//booking_case() FUNCTION END
//----------------------------------------------------------------------------------
				    //------------------------------------------------

		 //management_case() FUNCTION START

void management_case()
{
int choice,id,year,month,date,o;
char c;
do
{
clrscr();
border();
gotoxy(20,7);cout<<"M A N A G E M E N T   P O R T A L";
gotoxy(18,8);cout<<"+++++++++++++++++++++++++++++++++++";
gotoxy(8,11);cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
gotoxy(8,12);cout<<"± 1.ADD A VEHICLE                                              ±";
gotoxy(8,13);cout<<"± 2.REMOVE A VEHICLE                                           ±";
gotoxy(8,14);cout<<"± 3.UPDATE VEHICLE                                             ±";
gotoxy(8,15);cout<<"± 4.SEARCH VEHICLE                                             ±";
gotoxy(8,16);cout<<"± 5.SEARCH UNBOOKED VEHICLE ON PARTICULAR DATE                 ±";
gotoxy(8,17);cout<<"± 6.DISPLAY VEHICLE                                            ±";
gotoxy(8,18);cout<<"± 7.CANCELLED BOOKING                                          ±";
gotoxy(8,19);cout<<"± 8.SUCCESSFUL BOOKINGS                                        ±";
gotoxy(8,20);cout<<"± 9.GO TO MAIN MENU		     	                      ±";
gotoxy(8,21);cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
gotoxy(8,22);cout<<"ENTER YOUR CHOICE-";
cin>>choice;
switch(choice)
{
 case 1:
	{
	clrscr();
	ofstream ofs("vehicle.dat",ios::binary|ios::app);
	t.v.getinfo();
	ofs.write((char*)&t,sizeof(t));
	ofs.close();
	}
	break;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

 case 2:
	{
	clrscr();
	t.v.remove_vehicle();
	}
	break;
	//^^^^^^^^^^^^^^^^^

 case 3:

	{
	clrscr();
	cout<<"\nEnter vehicle id you want to update";
	cin>>id;
	int a=t.v.search_vehicle(id);
	if(a==0)
	{
	t.v.update_vehicle(id);
	}
	else
	cout<<"\n****RESULT NOT FOUND****\n";
	}
	break;

 case 4:
	{
	int imt=12;
	clrscr();
	cout<<"\nEnter booking id you want to search for:-";
	cin>>id;
	int a=t.v.search_vehicle(id);
	if(a==0)
	{
	cout<<"\n\t±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± ";
	cout<<"\n\t	    D I S P L A Y     V E H I C L E    D E T A I L S                        ";
	cout<<"\n\t________________________________________________________________ ";
	cout<<"\n\t **************************************************************** ";
	cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
	cout<<"\n±±   VEHICLEID   ±±   VEHICLE NO  ±±   VEHICLE TYPE   ±±   AC   ±±   SEATS   ±±";
	cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";

	t.v.display_vehicle(imt);
	++imt;
	cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
	}
	else
	cout<<"\n****RESULT NOT FOUND****\n";
	}
	break;
 case 5:
	{
	clrscr();
	cout<<"\nENTER YEAR";
	cin>>year;
	cout<<"\nENTER MONTH";
	cin>>month;
	cout<<"\nENTER DATE";
	cin>>date;
	int o=t.check(year,month,date);
	if(o==0)
	cout<<"SORRY NO VEHICLE FOUND";
	}
	break;
 case 6:  {
	   clrscr();
	   ifstream ifs;
	   int imt=12;
	   ifs.open("vehicle.dat",ios::binary);
	   cout<<"\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	   cout<<"\n\t ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± ";
	   cout<<"\n\t	    D I S P L A Y     V E H I C L E    D E T A I L S                        ";
	   cout<<"\n\t ________________________________________________________________ ";
	   cout<<"\n\t **************************************************************** ";
	   cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
	   cout<<"\n±±   VEHICLEID   ±±   VEHICLE NO  ±±   VEHICLE TYPE   ±±   AC   ±±   SEATS   ±±";
	   cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";

	   while(!ifs.eof())
	   {
	   ifs. read((char*)&t,sizeof(t));
	   if(ifs.eof())
	   break;
	   t.v.display_vehicle(imt);
	   ++imt;
	   }
	   cout<<"\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";

	   cout<<"\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	  ifs.close();
	    }
	    break;

 case 7:  {
	  clrscr();
	  show_cancelled_booking();
	  }
	  break;

 case 8:  {
	  clrscr();
	  show_successful_booking();
	  }
	 break;
 case 9: break;
}
getch();
clrscr();
border();
gotoxy(20,8); cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° ";
gotoxy(20,9); cout<<"°                                            ° ";
gotoxy(20,10);cout<<"°  DO YOU WANT TO CONTINUE WITH SAME PORTAL  °";
gotoxy(20,11);cout<<"° ========================================== °";
gotoxy(20,12);cout<<"°                                            °";
gotoxy(20,13);cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
gotoxy(24,12);cin>>c;

}
while(c=='y'||c=='Y');
}            //management_case() FUNCTION END
//--------------------------------------------------------------------------------
				    //-------------------------------------------

//FUNCTION intro() FOR INTRODUCTION OF THE PROJECT STUDENTS START
void intro()
{
clrscr();
border();
gotoxy(2,4);cout<<"  	   +++++++++                        ++++++++             ";
gotoxy(2,5);cout<<"  	       +       +     +              +      +             ";
gotoxy(2,6);cout<<"  	       +       + +   +   +++++++++  ++++++++   +++++++   ";
gotoxy(2,7);cout<<"  	       +       +  +  +       +      +  +       +     +   ";
gotoxy(2,8);cout<<"  	       +       +   + +       +      +    +     +     +   ";
gotoxy(2,9);cout<<"  	   +++++++++   +     +       +      +      +   +++++++   ";
gotoxy(3,13);cout<<" THE PROJECT TRAVEL AGENCY IS MADE BY THE STUDENTS OF CLASS XII-A";
gotoxy(3,15);cout<<"                        THE MEMBERS ARE AS FOLLOWS:-";
gotoxy(3,16);cout<<"                        1-MANSI TARANI";
gotoxy(3,17);cout<<"                        2-VIDUSHI CHAUHAN";
gotoxy(3,18);cout<<"                        3-NIYATI SINGH";
gotoxy(3,19);cout<<"                        4-GARIMA JAIN";
}              //intro() FUNCTION END
//-------------------------------------------------------------------------------------
				   //-------------------------------------------------
	       //ccheck() FUNCTION START

int ccheck()
{
int it=0;
ifstream ifs;
ifs.open("ttravel.dat",ios::in||ios::binary);
while(ifs.read((char*)&t,sizeof(t)))
{
it=it+1;
}
ifs.close();
return it;
}              //ccheck() FUNCTION END
//____________________________________________________________________________________________
				   //__________________________________________________
void main()
{
clrscr();
border();
gotoxy(20,5);cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
gotoxy(20,6);cout<<"°	                           °";
gotoxy(20,7);cout<<"°    ENTER CURRENT YEAR:-       °";
gotoxy(20,8);cout<<"°	                           °";
gotoxy(20,9);cout<<"°    ENTER CURRENT MONTH:-      °";
gotoxy(20,10);cout<<"°	                           °";
gotoxy(20,11);cout<<"°    ENTER  CURRENT DATE:-      °";
gotoxy(20,12);cout<<"°	                           °";
gotoxy(20,13);cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
gotoxy(46,7);cin>>cy;
gotoxy(46,9);cin>>cm;
gotoxy(46,11);cin>>cd;
int o=ccheck();
if(o!=0)
remove_booking_bydate();
clrscr();
int choice,p,id,dd,mm,yy,c=0;
do
{
border();
gotoxy(25,3);cout<<"WELCOME TO MVGN TRAVEL AGENCY";
gotoxy(23,4);cout<<"*********************************";
gotoxy(7,7);cout<<"                 _______________________.    ";
gotoxy(7,8);cout<<"		     /      |      |      |    .     ";
gotoxy(7,9);cout<<"		   /	    |      |      |	.    ";
gotoxy(7,10);cout<<"		 /__________|______|______|_______.  ";
gotoxy(7,11);cout<<"	      .___________________________________________.";
gotoxy(7,12);cout<<"      ..";
gotoxy(7,13);cout<<"    ..";
gotoxy(7,14);cout<<"   ..";
gotoxy(7,15);cout<<"  ..";
gotoxy(7,16);cout<<"   ..";
gotoxy(7,17);cout<<"    . ___________  .....  ______________     ..... ___________.  ";
gotoxy(7,18);cout<<"     . ___________.......__________________ ......._________.  ";
gotoxy(7,19);cout<<"	                 .....                     .....            ";
getch();
clrscr();
cout<<"\n                     T R A V A L     A G E N C Y ";
cout<<"\n__________________________________________________________________________";
cout<<"\n__________________________________________________________________________";
cout<<"\n\n\n	 *   *   *              *   *   *              *   *   * ";
cout<<"\n     *             *        *             *             * ";
cout<<"\n   * 1-INTRODUCTION  *    *  2- MANAGEMENT  *    *  3- PASSENGER   *";
cout<<"\n   *   PORTAL        *    *  &   VEHICLE    *    *     PORTAL      *";
cout<<"\n     *              *       *   PORTAL    *        *             * ";
cout<<"\n	 *   *    *	        *   *   *              *   *   * ";
cout<<"\n\n\n			        *   *   *  ";
cout<<"\n                            *    	   *	";
cout<<"\n                           *     4-EXIT     * ";
cout<<"\n                           *       PORTAL   * ";
cout<<"\n	               	     *             * ";
cout<<"\n				*   *   * ";
cout<<"\n____________________________________________________________________________";
cout<<"\n____________________________________________________________________________";
cout<<"\n\nENTER YOUR CHOICE-" ;
cin>>choice;
switch(choice)
{
case 1:
       {
       intro();
       }
       break;
       //________________________
case 2:
       {
       management_case();
       }
       break;
       //________________________
case 3:
       {
       booking_case();
       }
       break;
       //________________________
case 4:exit(0);
 }
getch();
clrscr();
}
while(c==0);
}
//!!!!!!!!!!!!!!!!!!!!!!!!!        T H A N K S      !!!!!!!!!!!!!!!!!!!!!!!!!
//_________________________T H E                E N D________________________
