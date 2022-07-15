#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
int stateCount = 0;
int cityCount = 0;
//int partyCount = 0;
int stateIdNo = 0;
int cityIdNo = 0;
int partyId = 0;
int candidateId = 0;
int voterId = 0;
int resultId = 0;
int a[100005],seg[4*100005];

/*function to check condition for insertion sort*/

void getStateCount(){
   ifstream finStateCount;
   finStateCount.open("stateCount.txt");
   if(!finStateCount){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finStateCount>>stateCount;
   finStateCount.close();
}
void getCityCount(){
   ifstream finCityCount;
   finCityCount.open("cityCount.txt");
   if(!finCityCount){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finCityCount>>cityCount;
   finCityCount.close();
}
/*void getPartyCount(){
   ifstream finPartyCount;
   finPartyCount.open("partyCount.txt");
   if(!finPartyCount){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finPartyCount>>partyCount;
   finPartyCount.close();
}*/
void getStateIdNo(){
   ifstream finStateIdNo;
   finStateIdNo.open("stateIdNo.txt");
   if(!finStateIdNo){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finStateIdNo>>stateIdNo;
   finStateIdNo.close();
}
void getCityIdNo(){
   ifstream finCityIdNo;
   finCityIdNo.open("cityIdNo.txt");
   if(!finCityIdNo){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finCityIdNo>>cityIdNo;
   finCityIdNo.close();
}
void getPartyIdNo(){
   ifstream finPartyIdNo;
   finPartyIdNo.open("partyIdNo.txt");
   if(!finPartyIdNo){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finPartyIdNo>>partyId;
   finPartyIdNo.close();
}
void getCandidateId(){
   ifstream finCandidateId;
   finCandidateId.open("candidateId.txt");
   if(!finCandidateId){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finCandidateId>>candidateId;
   finCandidateId.close();
}
void getVoterId(){
   ifstream finVoterId;
   finVoterId.open("voterId.txt");
   if(!finVoterId){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finVoterId>>voterId;
   finVoterId.close();
}
void getResultId(){
   ifstream finResultId;
   finResultId.open("resultId.txt");
   if(!finResultId){
      cout<<"\n   File not Exists\n";getch();return;
   }
   finResultId>>resultId;
   finResultId.close();
}

void setStateCount(){
   ofstream foutStateCount;
   foutStateCount.open("stateCount.txt");
   foutStateCount<<stateCount;
   foutStateCount.close();

}
void setCityCount(){
   ofstream foutCityCount;
   foutCityCount.open("cityCount.txt");
   foutCityCount<<cityCount;
   foutCityCount.close();

}
/*void setPartyCount(){
   ofstream foutPartyCount;
   foutPartyCount.open("partyCount.txt");
   foutPartyCount<<partyCount;
   foutPartyCount.close();

}*/
void setStateIdNo(){
   ofstream foutStateIdNo;
   foutStateIdNo.open("stateIdNo.txt");
   foutStateIdNo<<stateIdNo;
   foutStateIdNo.close();

}
void setCityIdNo(){
   ofstream foutCityIdNo;
   foutCityIdNo.open("cityIdNo.txt");
   foutCityIdNo<<cityIdNo;
   foutCityIdNo.close();

}
void setPartyIdNo(){
   ofstream foutPartyIdNo;
   foutPartyIdNo.open("partyIdNo.txt");
   foutPartyIdNo<<partyId;
   foutPartyIdNo.close();

}
void setCandidateId(){
   ofstream foutCandidateId;
   foutCandidateId.open("candidateId.txt");
   foutCandidateId<<candidateId;
   foutCandidateId.close();

}
void setVoterId(){
   ofstream foutVoterId;
   foutVoterId.open("voterId.txt");
   foutVoterId<<voterId;
   foutVoterId.close();

}
void setResultId(){
   ofstream foutResultId;
   foutResultId.open("resultId.txt");
   foutResultId<<resultId;
   foutResultId.close();

}

void funFrontPage(){
   cout<<"\n\n   Hi, Welcome To Our Project : Election Without Corona Project";
   getch();
   system("cls");
   cout<<"\n\n\t\t\t\t  JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY";
   cout<<"\n\t\t\t\t\t\tSec(62) NOIDA  \n\n\n";
   cout<<"\t\t\t\t  ALGORITHMS AND PROBLEMS SOLVING : 15B17CI411\n\n\n";
   cout<<"\t\t\t\t      MINI-PROJECT  : ELECTION WITHOUT CORONA \n\n";
   cout<<"\t\t\t\t\t        Batch : B3\n\n";
   cout<<"\n\n\n\t\t\t\t\tDevelopedBy : ";
   cout<<"\n\n\t\t\t\t\t\tKUNAL         : 19103103";
   cout<<"\n\n\t\t\t\t\t\tUTKARSH GARG  : 19103108";
   cout<<"\n\n\t\t\t\t\t\tAKASH DWIVEDI : 19103095";
   cout<<"\n\n\t\t\t\t\t\tPURVI         : 19103114";
   cout<<"\n\n\t\t\t\t\t\tAKASH SHARMA  : 19103112";

   getch();
}
void funHeading(string Heading){
   system("cls");
   cout<<"\n\t\t\t\t\tMINI PROJECT : ELECTION(s) WITHOUT CORONA\n\n\n";
   //transform(Heading.begin(),Heading.end(),Heading.begin(), :: toupper);
   cout<<"   "<<Heading<<"\n";
}
int stringCmp(string str1,string str2){
   int l1 = str1.length();
   int l2 = str2.length();
   int x = (l1>l2)?l1:l2;
   for(int i=0;i<x;i++){
      if(str2[i]>str1[i]){return 1;}
      else if(str2[i]<str1[i]){return 0;}
   }
   if(l1==l2) return 2;
   if(l2>l1) return 1;
   return 0;
}
int stringMatch(string str1,string str2){
   int l1 = str1.length();
   int l2 = str2.length();
   if(l1!=l2) return 0;
   for(int i=0;i<l1;i++){
      if(str2[i]!=str1[i]){
         return 0;
      }
   }
   return 1;
}
int countDigits(int a){
   int i =0 ;
   while(a>0){
      i++;
      a/=10;
   }
   return i;
}
int countChar(char * arr){
   int i=0;
   while(arr[i]!='\0'){i++;}
   return i;
}
int choiceAdmin(int a){
   int x;
   if(a==0){
      funHeading("Options : ");
      cout<<"\n   1. Voter Login"<<endl;
      cout<<"   2. Candidate Login"<<endl;
      cout<<"   3. Party Login"<<endl;
      cout<<"   4. Create Account/Party"<<endl;
      cout<<"   5. View Result(s)"<<endl;
      cout<<"   6. Admin Side"<<endl;
      cout<<"   7. Exit"<<endl;
   }
   else if(a==1){
      funHeading("Maintain Record : ");
      cout<<"\n   0. GoBack"<<endl;
      cout<<"\n   1. View Voter Record"<<endl;
      cout<<"   2. View Candidate Record"<<endl;
      cout<<"   3. View Party Record"<<endl;
      cout<<"   4. Reset All Votes and Seats"<<endl;
   }
   else if(a==2){
      funHeading("Admin Side Features : ");
      cout<<"\n   0. GoBack"<<endl;
      cout<<"\n   1. Alter State Record"<<endl;
      cout<<"   2. Alter District Record"<<endl;
      cout<<"   3. Maintain Data"<<endl;
      cout<<"   4. Set Result Record"<<endl;

   }
   else if(a==3){
      funHeading("Altering State Record : ");
      cout<<"\n   0.GoBack"<<endl;
      cout<<"\n   1.Add State Record"<<endl;
      cout<<"   2.Show State Record"<<endl;
      cout<<"   3.Delete State Record"<<endl;
      cout<<"   4.Update State Record"<<endl;

   }
   else if(a==4){
      funHeading("Altering City Record : ");
      cout<<"\n   0.GoBack"<<endl;
      cout<<"\n   1.Add City Record"<<endl;
      cout<<"   2.Show City Record"<<endl;
      cout<<"   3.Delete City Record"<<endl;
      cout<<"   4.Update City Record"<<endl;

   }
   else if(a==5){
      funHeading("Creating an Account : ");
      cout<<"\n   0.GoBack"<<endl;
      cout<<"\n   1.Voter Account"<<endl;
      cout<<"   2.Candidate Account"<<endl;
      cout<<"   3.Create A Party"<<endl;

   }
   else if(a==6){
      //funHeading("Options : ");
      cout<<"\n\n   Options : - ";
      cout<<"\n\n   0.LogOut"<<endl;
      cout<<"   1.View Members List"<<endl;
      cout<<"   2.Update Data"<<endl;

   }
   else if(a==7){
      //funHeading("Options : ");
      cout<<"\n\n   Options : - ";
      cout<<"\n\n   0.LogOut"<<endl;
      cout<<"   1.View Other Members List"<<endl;
      cout<<"   2.Update Data"<<endl;

   }
   else if(a==8){
      //funHeading("Options : ");
      cout<<"\n\n   Options : - ";
      cout<<"\n\n   0.LogOut"<<endl;
      cout<<"   1.Do Vote"<<endl;
      cout<<"   2.Update Data"<<endl;

   }
   else if(a==9){
      funHeading("Showing the Result(s) : ");
      cout<<"\n   0.GoBack"<<endl;
      cout<<"\n   1.OverAll Result"<<endl;
      cout<<"   2.Result in a Specific State"<<endl;
      cout<<"   3.Result in a Specific District"<<endl;
      cout<<"   4.List of Results for an Interval"<<endl;
   }
   cout<<"\n   Enter your Choice : ";
   cin>>x;
   return x;
}

class State{
   private:
      int stateId,seats;
      char stateName[25];

   public:
      State(){
         stateId = 0;
         seats = 0;
         strcpy(stateName,"NoName");
      }
      State(char *sName){
         stateCount++;
         stateId=stateCount;
         seats = 0;
         strcpy(stateName,sName);
      }
      void getStateInfo(){
         cout<<"Enter the Name : ";
         cin.getline(stateName,24);
         getStateIdNo();
         stateId = ++stateIdNo;
         setStateIdNo();
         stateCount++;
         seats = 0;
      }
      void showStateInfo(){
         cout<<stateName<<endl;
      }

      int getSeats(){return seats;}
      void setSeats(int x){seats =  x;}

      int getstateId(){return stateId;}
      void setstateId(int id){stateId = id;}

      string getstateName(){return stateName;}
      char * getstateName2(){return stateName;}
      void setstateName(char * sName){strcpy(stateName,sName);}


      int storeState();
      int getStates(int x);
};
int State::getStates(int x){
   int i=0;
   ifstream finStateRecord;
   finStateRecord.open("States.txt",ios::in|ios::binary);
   if(!finStateRecord){cout<<"\n   File not Found";}
   else{
      while(!finStateRecord.eof()&&i!=x+1)
      {
         finStateRecord.read((char *)this,sizeof(*this));
         i++;
      }
   }
}
int State::storeState(){
   ofstream foutState;
   foutState.open("States.txt",ios::app|ios::binary);
   foutState.write((char *)this,sizeof(*this));
   foutState.close();
}
void funStateInput(State *bs1,int x){
   int y = x+stateCount;
   State obj;
   for(int i =stateCount,k=0;i<y;i++,k++){
      if(x>1){cout<<"\n   Enter State "<<k+1<<"\n";}
      else{cout<<"\n";}
      cout<<"   ";
      obj.getStateInfo();
      string objName = obj.getstateName();
      int j;
      for(j = stateCount-1;j>0;j--){
         string cmpName = bs1[j-1].getstateName();
         int k = stringCmp(cmpName,objName);
         if(k==0){bs1[j] = bs1[j-1];}
         else{break;}
      }
      bs1[j] = obj;
   }
}
void insertNewState(){
   int x;
   getStateCount();
   cout<<"\n   Enter the No. of State's you want to Insert: ";
   cin>>x;cin.ignore();
   if(x==0){return;}
   State bs1[stateCount+x];
   funHeading("Inserting State's Record: ");
   cout<<endl<<"   S.No.  StateName\n\n";
   for(int i=0;i<stateCount;i++){
      bs1[i].getStates(i);
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      bs1[i].showStateInfo();
   }
   funStateInput(bs1,x);
   setStateCount();
   remove("States.txt");
   for(int i=0;i<stateCount;i++){bs1[i].storeState();}
   cout<<"\n\n   Record Inserted\n\n   Press any Key To Update The Record";
   getch();
}
int inputDeleteChoices(){
   int x;
   cout<<"   1.Delete Via SerialNumber(*Convenient)"<<endl;
   cout<<"   2.Delete Via StateName"<<endl;
   cout<<"   3.Go Back"<<endl;
   cout<<"\n   Enter your Choice : ";
   cin>>x;
   return x;
}
void deleteState(){
   getStateCount();
   if(stateCount==0){cout<<"\n   No Record Exists";getch();return;}
   State bs1[stateCount];
   for(int i=0;i<stateCount;i++){bs1[i].getStates(i);}
   redo:;
   funHeading("Deleting A State Record : ");
   cout<<endl<<"   S.No.  StateName\n\n";
   for(int i=0;i<stateCount;i++){
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      bs1[i].showStateInfo();
   }
   cout<<"\n\n";
   int ch = inputDeleteChoices();
   if(ch == 1){
      int sr;
      cout<<"\n   Enter the S.No. : ";cin>>sr;
      if(sr<=0||sr>stateCount){cout<<"\n   Invalid No!";getch();goto redo;}
      cin.ignore();
      char cnfm;
      cout<<"\n   Are you Sure to Delete Record "<<bs1[sr-1].getstateName()<<" (y/n) : ";
      //cnfm = getch();cout<<cnfm;
      cin>>cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
         stateCount--;
         cout<<"\n\n   Record Deleted\n\n   Press any Key to Update Record";getch();
      }
      goto redo;
   }
   else if(ch==2){
      int sr;char sName[25];
      cout<<"\n   Enter the StateName : ";
      cin.ignore();cin.getline(sName,19);
      bool f=0;
      for(int i=0;i<stateCount;i++){
         string stName = bs1[i].getstateName();
         int match = stringMatch(stName,sName);
         if(match==1){f=1;sr=i+1;break;}
      }
      if(f!=1){cout<<"\n\n   Record Already Not Exists\n\n   Press any Key";getch();goto redo;}
      char cnfm;
      cout<<"\n   Are you Sure to Delete Record "<<bs1[sr-1].getstateName()<<" (y/n) : ";cin>>cnfm;//cnfm = getch();cout<<cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
         stateCount--;
         cout<<"\n\n   Record Deleted\n\n   Press any Key to Update Record";getch();
      }
      goto redo;
   }
   else if (ch==3){
      setStateCount();
      remove("States.txt");
      for(int i=0;i<stateCount;i++){bs1[i].storeState();}
      return;
   }
   else{cout<<"\n   Enter the Correct Choice!";getch();goto redo;}
}
int inputUpdateChoices(){
   int x;
   cout<<"   1.Update Via SerialNumber(*Convenient)"<<endl;
   cout<<"   2.Update Via StationName"<<endl;
   cout<<"   3.Go Back"<<endl;
   cout<<"\n   Enter your Choice : ";
   cin>>x;
   return x;
}
void updateState(){
   getStateCount();
    if(stateCount==0){cout<<"\n   No Record Exists";getch();return;}
   State bs1[stateCount];
   for(int i=0;i<stateCount;i++){bs1[i].getStates(i);}
   redo:;
   funHeading("Updating A State Record : ");
   cout<<endl<<"   S.No.  StateName\n\n";
   for(int i=0;i<stateCount;i++){
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      bs1[i].showStateInfo();
   }
   cout<<"\n\n";
   char newName[25];
   int ch = inputUpdateChoices();
   if(ch == 1){
      int sr;cout<<"\n   Enter the S.No. : ";cin>>sr;
      if(sr<=0||sr>stateCount){cout<<"\n   Invalid No!";getch();goto redo;}
      cin.ignore();
      cout<<"\n   Enter New StateName forState ("<<bs1[sr-1].getstateName()<<") : ";
      cin.getline(newName,24);
      char cnfm;
      cout<<"\n   Are you Sure to Update the Record to "<<newName<<" (y/n) : ";
      cin>>cnfm;
      //cnfm = getch();
      //cout<<cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
         stateCount--;
         State obj(newName);
         int j;
         for(j = stateCount-1;j>0;j--){
            string cmpName = bs1[j-1].getstateName();
            int k = stringCmp(cmpName,newName);
            if(k==0){bs1[j] = bs1[j-1];}
            else{break;}
         }
         bs1[j] = obj;
         cout<<"\n\n   Record Updated\n\n   Press any Key to Update Record";getch();
      }
      goto redo;
   }
   else if(ch==2){
      int sr;char sName[25];
      cout<<"\n   Enter the StateName : ";
      cin.ignore();cin.getline(sName,24);
      bool f=0;
      for(int i=0;i<stateCount;i++){
         string stName = bs1[i].getstateName();
         int match = stringMatch(stName,sName);
         if(match==1){f=1;sr=i+1;break;}
      }
      if(f!=1){cout<<"\n\n   No Record Found\n\n   Press any Key";getch();goto redo;}
      cout<<"\n   Enter New StateName forState ("<<bs1[sr-1].getstateName()<<") : ";
      cin.getline(newName,24);
      char cnfm;
      cout<<"\n   Are you Sure to Update the Record to "<<newName<<" (y/n) : ";
      //cnfm = getch();cout<<cnfm;
      cin>>cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
         stateCount--;
         State obj(newName);
         int j;
         for(j = stateCount-1;j>0;j--){
            string cmpName = bs1[j-1].getstateName();
            int k = stringCmp(cmpName,newName);
            if(k==0){bs1[j] = bs1[j-1];}
            else{break;}
         }
         bs1[j] = obj;
         cout<<"\n\n   Record Updated\n\n   Press any Key to Update Record";getch();
      }
      goto redo;
   }
   else if (ch==3){
      setStateCount();
      remove("States.txt");
      for(int i=0;i<stateCount;i++){bs1[i].storeState();}
      return;
   }
   else{cout<<"\n   Enter the Correct Choice!";getch();goto redo;}
}
void viewStateRecord(){
   getStateCount();
   if(stateCount==0){cout<<"\n   No Record Found";getch();return;}
   State bs1[stateCount];
   cout<<endl<<"   S.No.  StateName    Seats\n\n";
   char * sName;
   for(int i=0;i<stateCount; i++){
      bs1[i].getStates(i);
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      sName = bs1[i].getstateName2();
      cout<<sName;
      j = countChar(sName);
      for(int k = j;k<14;k++) cout<<" ";
      cout<<bs1[i].getSeats()<<endl;
   }
   getch();
}

class City : public State{
   private:
      int cityId,LeadcandidateId;
      char cityName[25];

   public:
      City(){
         setstateId(0);
         setSeats(0);
         LeadcandidateId = 0;
         setstateName("NoName");
         strcpy(cityName,"NoName");
         cityId = 0;
      }

       int getCityInfo(int sId,char * sName){
         setstateId(sId);
         setstateName(sName);
         cout<<"Enter the Name : ";
         cin.getline(cityName,24);
         cityCount++;
         int s = 1;
         /*cout<<"   Enter the No. of Seats : ";
         cin>>s;cin.ignore();*/
         setSeats(s);
         getCityIdNo();
         cityId = ++cityIdNo;
         setCityIdNo();
         LeadcandidateId = 0;
         return s;
      }
      void showCityInfo(){
         cout<<cityName<<endl;
      }
      //int getSeats(){return seats;}
      //void setSeats(int x){seats = seats + x;}
      int getcityId(){return cityId;}
      string getcityName(){return cityName;}
      char * getcityName2(){return cityName;}
      int getLeadCandidateId(){return LeadcandidateId;}

      void setCityId(int n){cityId = n;}
      void setcityName(char *name){strcpy(cityName,name);}
      int storeCity();
      int getCity(int x);
      void setLeadCandidateId(int n){LeadcandidateId = n;}
};
int City::getCity(int x){
   int i=0;
   ifstream finCityRecord;
   finCityRecord.open("Cities.txt",ios::in|ios::binary);
   if(!finCityRecord){cout<<"\n   File not Found";}
   else{
      while(!finCityRecord.eof()&&i!=x+1)
      {
         finCityRecord.read((char *)this,sizeof(*this));
         i++;
      }
   }
}
int City::storeCity(){
   ofstream foutCity;
   foutCity.open("Cities.txt",ios::app|ios::binary);
   foutCity.write((char *)this,sizeof(*this));
   foutCity.close();
}
int funCityInput(int stateId,char * stateName,City *b,int x){
   int y = x+cityCount,stateSeats=0;
   City obj;
   for(int i =cityCount,k=0;i<y;i++,k++){
      if(x>1){cout<<"\n   Enter City "<<k+1<<"\n";}
      else{cout<<"\n";}
      cout<<"   ";
      stateSeats = stateSeats + obj.getCityInfo(stateId,stateName);

      string objState = obj.getstateName();
      int j;
      for(j = cityCount-1;j>0;j--){
         string cmpState = b[j-1].getstateName();
         int k = stringCmp(cmpState,objState);
         if(k==0){b[j] = b[j-1];}
         else if(k==2){
            string objCity = obj.getcityName();
            string cmpCity = b[j-1].getcityName();
            int k = stringCmp(cmpCity,objCity);
            if(k==0){b[j] = b[j-1];}
            else{goto in;}
         }
         else{break;}
      }
      in:;
      b[j] = obj;

   }
   return stateSeats;
}
void insertNewCity(){
   int x;
   getCityCount();
   getStateCount();
   State bs1[stateCount];
   funHeading("Inserting City's Record: ");
   cout<<endl<<"   S.No.  StateName\n\n";
   for(int i=0;i<stateCount;i++){
      bs1[i].getStates(i);
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      bs1[i].showStateInfo();
   }
   int st;
   cout<<"\n   Select the State via serialNo. : ";
   cin>>st;cin.ignore();
   cout<<"\n   Enter the No. of Cities you want to Insert: ";
   cin>>x;cin.ignore();
   if(x==0){return;}

   City c[cityCount+x];
   //funHeading("Inserting State's Record: ");
   cout<<endl<<"\n\n   S.No.  CityName    Seats\n\n";
   char * cName;
   for(int i=0;i<cityCount; i++){
      c[i].getCity(i);
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      cName = c[i].getcityName2();
      cout<<cName;
      j = countChar(cName);
      for(int k = j;k<14;k++) cout<<" ";
      cout<<c[i].getSeats()<<endl;
      //cout<<"   "<<c[i].getstateId()<<"  "<<c[i].getstateName()<<endl;
   }
   int seatsCount = funCityInput(bs1[st-1].getstateId(),bs1[st-1].getstateName2(),c,x);
   seatsCount = seatsCount + bs1[st-1].getSeats();
   bs1[st-1].setSeats(seatsCount);
   setCityCount();
   remove("States.txt");
   for(int i=0;i<stateCount;i++){bs1[i].storeState();}
   remove("Cities.txt");
   for(int i=0;i<cityCount;i++){c[i].storeCity();}
   cout<<"\n\n   Record Inserted\n\n   Press any Key To Update The Record";
   getch();
}
/*int inputDeleteChoices(){
   int x;
   cout<<"   1.Delete Via SerialNumber(*Convenient)"<<endl;
   cout<<"   2.Delete Via StateName"<<endl;
   cout<<"   3.Go Back"<<endl;
   cout<<"\n   Enter your Choice : ";
   cin>>x;
   return x;
}*/
void deleteCity(){
   /*getStateCount();
   if(stateCount==0){cout<<"\n   No Record Exists";getch();return;}
   State bs1[stateCount];
   for(int i=0;i<stateCount;i++){bs1[i].getStates(i);}
   redo:;*/
   funHeading("Deleting A State Record : ");
   cout<<"   Available Soon";
   getch();
   /*cout<<endl<<"   S.No.  StateName\n\n";
   for(int i=0;i<stateCount;i++){
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      bs1[i].showStateInfo();
   }
   cout<<"\n\n";
   int ch = inputDeleteChoices();
   if(ch == 1){
      int sr;
      cout<<"\n   Enter the S.No. : ";cin>>sr;
      if(sr<=0||sr>stateCount){cout<<"\n   Invalid No!";getch();goto redo;}
      cin.ignore();
      char cnfm;
      cout<<"\n   Are you Sure to Delete Record "<<bs1[sr-1].getstateName()<<" (y/n) : ";
      //cnfm = getch();cout<<cnfm;
      cin>>cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
         stateCount--;
         cout<<"\n\n   Record Deleted\n\n   Press any Key to Update Record";getch();
      }
      goto redo;
   }
   else if(ch==2){
      int sr;char sName[25];
      cout<<"\n   Enter the StateName : ";
      cin.ignore();cin.getline(sName,19);
      bool f=0;
      for(int i=0;i<stateCount;i++){
         string stName = bs1[i].getstateName();
         int match = stringMatch(stName,sName);
         if(match==1){f=1;sr=i+1;break;}
      }
      if(f!=1){cout<<"\n\n   Record Already Not Exists\n\n   Press any Key";getch();goto redo;}
      char cnfm;
      cout<<"\n   Are you Sure to Delete Record "<<bs1[sr-1].getstateName()<<" (y/n) : ";cin>>cnfm;//cnfm = getch();cout<<cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
         stateCount--;
         cout<<"\n\n   Record Deleted\n\n   Press any Key to Update Record";getch();
      }
      goto redo;
   }
   else if (ch==3){
      setStateCount();
      remove("States.txt");
      for(int i=0;i<stateCount;i++){bs1[i].storeState();}
      return;
   }
   else{cout<<"\n   Enter the Correct Choice!";getch();goto redo;}*/
}
/*int inputUpdateChoices(){
   int x;
   cout<<"   1.Update Via SerialNumber(*Convenient)"<<endl;
   cout<<"   2.Update Via StationName"<<endl;
   cout<<"   3.Go Back"<<endl;
   cout<<"\n   Enter your Choice : ";
   cin>>x;
   return x;
}*/
void updateCity(){
   /*getStateCount();
    if(stateCount==0){cout<<"\n   No Record Exists";getch();return;}
   State bs1[stateCount];
   for(int i=0;i<stateCount;i++){bs1[i].getStates(i);}
   redo:;*/
   funHeading("Updating A State Record : ");
   cout<<"   Available Soon";
   getch();
   /*cout<<endl<<"   S.No.  StateName\n\n";
   for(int i=0;i<stateCount;i++){
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      bs1[i].showStateInfo();
   }
   cout<<"\n\n";
   char newName[25];
   int ch = inputUpdateChoices();
   if(ch == 1){
      int sr;cout<<"\n   Enter the S.No. : ";cin>>sr;
      if(sr<=0||sr>stateCount){cout<<"\n   Invalid No!";getch();goto redo;}
      cin.ignore();
      cout<<"\n   Enter New StateName forState ("<<bs1[sr-1].getstateName()<<") : ";
      cin.getline(newName,24);
      char cnfm;
      cout<<"\n   Are you Sure to Update the Record to "<<newName<<" (y/n) : ";
      cin>>cnfm;
      //cnfm = getch();
      //cout<<cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
         stateCount--;
         State obj(newName);
         int j;
         for(j = stateCount-1;j>0;j--){
            string cmpName = bs1[j-1].getstateName();
            int k = stringCmp(cmpName,newName);
            if(k==0){bs1[j] = bs1[j-1];}
            else{break;}
         }
         bs1[j] = obj;
         cout<<"\n\n   Record Updated\n\n   Press any Key to Update Record";getch();
      }
      goto redo;
   }
   else if(ch==2){
      int sr;char sName[25];
      cout<<"\n   Enter the StateName : ";
      cin.ignore();cin.getline(sName,24);
      bool f=0;
      for(int i=0;i<stateCount;i++){
         string stName = bs1[i].getstateName();
         int match = stringMatch(stName,sName);
         if(match==1){f=1;sr=i+1;break;}
      }
      if(f!=1){cout<<"\n\n   No Record Found\n\n   Press any Key";getch();goto redo;}
      cout<<"\n   Enter New StateName forState ("<<bs1[sr-1].getstateName()<<") : ";
      cin.getline(newName,24);
      char cnfm;
      cout<<"\n   Are you Sure to Update the Record to "<<newName<<" (y/n) : ";
      //cnfm = getch();cout<<cnfm;
      cin>>cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
         stateCount--;
         State obj(newName);
         int j;
         for(j = stateCount-1;j>0;j--){
            string cmpName = bs1[j-1].getstateName();
            int k = stringCmp(cmpName,newName);
            if(k==0){bs1[j] = bs1[j-1];}
            else{break;}
         }
         bs1[j] = obj;
         cout<<"\n\n   Record Updated\n\n   Press any Key to Update Record";getch();
      }
      goto redo;
   }
   else if (ch==3){
      setStateCount();
      remove("States.txt");
      for(int i=0;i<stateCount;i++){bs1[i].storeState();}
      return;
   }
   else{cout<<"\n   Enter the Correct Choice!";getch();goto redo;}*/
}
void viewCityRecord(){
   getCityCount();
   if(cityCount==0){cout<<"\n   No Record Found";getch();return;}
   City bs1[cityCount];
   cout<<endl<<"   S.No.  StateName    CityName    Seats\n\n";
   char * sName;
   for(int i=0;i<cityCount; i++){
      bs1[i].getCity(i);
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      sName = bs1[i].getstateName2();
      cout<<sName;
      j = countChar(sName);
      for(int k = j;k<12;k++) cout<<" ";
      sName = bs1[i].getcityName2();
      cout<<sName;
      j = countChar(sName);
      for(int k = j;k<14;k++) cout<<" ";
      cout<<bs1[i].getSeats()<<endl;

      //cout<<"   "<<bs1[i].getLeadCandidateId()<<endl;
   }
   getch();
}

/*void setCityLeadCandidate(){
   getCityCount();
   City bs1[cityCount];
   for(int i=0;i<cityCount;i++){
      bs1[i].getCity(i);
      bs1[i].setLeadCandidateId(0);
   }


   remove("Cities.txt");
   for(int i=0;i<cityCount;i++){bs1[i].storeCity();}
   cout<<"\n\n   Record Inserted\n\n   Press any Key To Update The Record";
   getch();
}*/
class Password{
private:
   char password[10];
public:
   Password(){
      strcpy(password,"1234");
   }

   char * getPassword(){return password;}
   string getPassword2(){return password;}
   void setPassword(char * pWord){strcpy(password,pWord);}
};

class Party:public Password{
   private:
      int PartyID,votes,Members,seats;
      char partyName[50],headName[25];

   public:
      Party(){
         PartyID = 0;
         votes = 0;
         Members = 0;
         seats = 0;
         strcpy(partyName,"NoName");
         strcpy(headName,"NoName");
         setPassword("1234");
      }

      void getPartyInfo(){
         getPartyIdNo();
         PartyID = ++partyId;
         setPartyIdNo();
         //partyCount++;
         votes = 0;
         seats = 0;
         Members = 1;
         cin.ignore();
         cout<<"Enter the PartyName : ";
         cin.getline(partyName,49);

         cout<<"\n   Enter the HeadName : ";
         cin.getline(headName,24);

         char arr[10],cr;
         cout<<"\n   Enter the Password : ";
         for(int i=0;i<10;i++){
            cr = getch();
            if(cr!='\r'){cout<<"*";arr[i]=cr;}

            else{
                  arr[i]='\0';
               setPassword(arr);
               break;
            }
         }
         //cout<<"\n\nPassword : "<<arr;
      }
      char * getPartyName(){return partyName;}
      char * getHeadName(){return headName;}
      string getPartyName2(){return partyName;}

      int getPartyId(){return PartyID;}
      int getVotes(){return votes;}
      int getMembers(){return Members;}
      int getSeats(){return seats;}

      void setPartyName(char *newName){strcpy(partyName,newName);}
      void setHeadName(char *newName){strcpy(headName,newName);}
      void setVotes(int n){votes = n;}
      void setPartyId(int n){PartyID = n;}
      void setMembers(int n){Members=n;}
      void setSeats(int n){seats=n;}

      int storeParty();
      int getParty(int x);
};
class Candidate:public Party,public City{
   private:
      int candidateID,seats;
      char candidateName[25],candidatePost[30],gender;

   public:
      Candidate(){
         setPartyId(0);
         setMembers(0);
         setVotes(0);
         seats=0;
         setPartyName("NoName");
         setHeadName("NoName");
         setPassword("1234");
         setstateId(0);
         setCityId(0);
         setstateName("NoName");
         setcityName("NoName");
      }

      void getCandidateInfo(){
         getCandidateId();
         candidateID = ++candidateId;
         cout<<"\n\n   Your Id :  "<<candidateID;
         setCandidateId();
         cin.ignore();
         cout<<"\n\n   Enter Your Name            :  ";
         cin.getline(candidateName,24);
         cout<<"\n   Enter Your Designation     :  ";
         cin.getline(candidatePost,29);
         cout<<"\n   Enter Your Gender(M/F)     :  ";
         cin>>gender;

         redo1:;
         funHeading("Creating Candidate Account : ");
         cout<<"\n\n   Your Id : "<<candidateID;
         cout<<"\n\n   Enter Your Name            :  "<<candidateName;
         cout<<"\n\n   Enter Your Designation     :  "<<candidatePost;
         cout<<"\n\n   Enter Your Gender(M/F)     :  "<<gender<<"\n\n";
         getStateCount();
         State bs1[stateCount];
         cout<<endl<<"   S.No.  State\n\n";
         for(int i=0;i<stateCount;i++){
            bs1[i].getStates(i);
            cout<<"   "<<i+1<<".";
            int j = countDigits(i+1);
            for(int k = j;k<8;k++)
               cout<<" ";
            bs1[i].showStateInfo();
         }
         int sr;cout<<"\n   Choose Your State (S.No) : ";cin>>sr;
         if(sr<=0||sr>stateCount){cout<<"\n   Invalid Choice!";getch();goto redo1;}
         setstateId(bs1[sr-1].getstateId());setstateName(bs1[sr-1].getstateName2());

         redo2:;
         funHeading("Creating Candidate Account : ");
         cout<<"\n\n   Your Id : "<<candidateID;
         cout<<"\n\n   Enter Your Name            :  "<<candidateName;
         cout<<"\n\n   Enter Your Designation     :  "<<candidatePost;
         cout<<"\n\n   Enter Your Gender(M/F)     :  "<<gender;
         cout<<"\n\n   Select Your State          :  "<<getstateName2()<<"\n\n";
         getCityCount();
         City cs1[cityCount];
         cout<<endl<<"   S.No.  City\n\n";
         for(int i=0;i<cityCount;i++){
            cs1[i].getCity(i);
            if(cs1[i].getstateId()==getstateId()){
               cout<<"   "<<i+1<<".";
               int j = countDigits(i+1);
               for(int k = j;k<8;k++)
                  cout<<" ";
               cs1[i].showCityInfo();

            }
         }
         cout<<"\n   Choose Your City (S.No) : ";cin>>sr;
         if(sr<=0||sr>cityCount){cout<<"\n   Invalid Choice!";getch();goto redo2;}
         setCityId(cs1[sr-1].getcityId());setcityName(cs1[sr-1].getcityName2());

         redo3:;
         funHeading("Creating Candidate Account : ");
         cout<<"\n\n   Your Id : "<<candidateID;
         cout<<"\n\n   Enter Your Name            :  "<<candidateName;
         cout<<"\n\n   Enter Your Designation     :  "<<candidatePost;
         cout<<"\n\n   Enter Your Gender(M/F)     :  "<<gender;
         cout<<"\n\n   Select Your State          :  "<<getstateName2();
         cout<<"\n\n   Select Your City          :  "<<getcityName2()<<"\n\n";
         getPartyIdNo();
         Party ps1[partyId];
         cout<<endl<<"   S.No.  Party\n\n";
         for(int i=0;i<partyId;i++){
            ps1[i].getParty(i);
            cout<<"   "<<i+1<<".";
            int j = countDigits(i+1);
            for(int k = j;k<8;k++)cout<<" ";
            cout<<ps1[i].getPartyName()<<endl;
         }
         cout<<"\n   Choose Your Party (S.No) : ";cin>>sr;
         if(sr<=0||sr>partyId){cout<<"\n   Invalid Choice!";getch();goto redo3;}
         setPartyId(ps1[sr-1].getPartyId());setPartyName(ps1[sr-1].getPartyName());
         setHeadName(ps1[sr-1].getHeadName());
         int m = ps1[sr-1].getMembers();ps1[sr-1].setMembers(m+1);
         setPartyIdNo();
         remove("Party.txt");
         for(int i=0;i<partyId;i++){ps1[i].storeParty();}


         funHeading("Creating Candidate Account : ");
         cout<<"\n\n   Your Id : "<<candidateID;
         cout<<"\n\n   Enter Your Name            :  "<<candidateName;
         cout<<"\n\n   Enter Your Designation     :  "<<candidatePost;
         cout<<"\n\n   Enter Your Gender(M/F)     :  "<<gender;
         cout<<"\n\n   Select Your State          :  "<<getstateName2();
         cout<<"\n\n   Select Your City           :  "<<getcityName2();
         cout<<"\n\n   Choose Your Party          :  "<<getPartyName()<<"\n\n";

         setMembers(1);
         setVotes(0);
         seats=0;
         setLeadCandidateId(0);

         char arr[10],cr;
         cout<<"\n   Enter the Password : ";
         for(int i=0;i<10;i++){
            cr = getch();
            if(cr!='\r'){cout<<"*";arr[i]=cr;}

            else{
               arr[i]='\0';
               setPassword(arr);
               break;
            }
         }

         //cout<<"\n\nPassword : "<<arr;
      }

      char * getCandidateName(){return candidateName;}
      char * getCandidateDesignation(){return candidatePost;}
      string getCandidateName2(){return candidateName;}
      int getCandidateID(){return candidateID;}
      int getSeats(){return seats;}
      int getCandidateVotes(){return getVotes();}

      void setCandidateVotes(int n){setVotes(n);}
      void setCandidateName(char *newName){strcpy(candidateName,newName);}
      void setCandidatePost(char *newPost){strcpy(candidatePost,newPost);}
      void setSeats(int n ){seats = n;}

      int storeCandidate();
      int getCandidate(int x);
};

int Party::getParty(int x){
   int i=0;
   ifstream finPartyRecord;
   finPartyRecord.open("Party.txt",ios::in|ios::binary);
   if(!finPartyRecord){cout<<"\n   File not Found";}
   else{
      while(!finPartyRecord.eof()&&i!=x+1)
      {
         finPartyRecord.read((char *)this,sizeof(*this));
         i++;
      }
   }
}
int Party::storeParty(){
   ofstream foutParty;
   foutParty.open("Party.txt",ios::app|ios::binary);
   foutParty.write((char *)this,sizeof(*this));
   foutParty.close();
}
int funPartyInput(Party *bs1,int x){
   Party obj;
   cout<<"   ";
   obj.getPartyInfo();
   /*string objName = obj.getPartyName2();
   int j;
   for(j = partyCount-1;j>0;j--){
      string cmpName = bs1[j-1].getPartyName2();
      int k = stringCmp(cmpName,objName);
      if(k==0){bs1[j] = bs1[j-1];}
      else{break;}
   }*/
   bs1[partyId-1] = obj;

   return obj.getPartyId();
}
int insertNewParty(){
   int x=1,Id=0;
   getPartyIdNo();
   //cout<<"\n   Enter the No. of State's you want to Insert: ";
   //cin>>x;cin.ignore();
   if(x==0){return Id;}
   Party bs1[partyId+x];

   funHeading("Inserting Party Record: \n");
   for(int i=0;i<partyId;i++){
      bs1[i].getParty(i);
   }
   Id = funPartyInput(bs1,x);
   setPartyIdNo();
   remove("Party.txt");
   for(int i=0;i<partyId;i++){bs1[i].storeParty();}
   cout<<"\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
   getch();
   return Id;
}
int partyLogin(){
   getPartyIdNo();
   if(partyId==0){cout<<"\n   No Record Found";getch();return 0;}
   Party bs1[partyId];
   funHeading("Party Login Page: ");
   cout<<endl<<"   S.No.   PartyName\n\n";
   for(int i=0;i<partyId;i++){
      bs1[i].getParty(i);
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++) cout<<" ";
      cout<<bs1[i].getPartyName()<<endl;
   }
   int x;
   cout<<"\n   Select the Party via S.No. : ";
   cin>>x;cin.ignore();
   char paswrd[10],cr;
   string cmpPaswrd = bs1[x-1].getPassword2();
   cout<<"\n   Enter Your Password: ";
   for(int i=0;i<10;i++){
      cr = getch();
      if(cr!='\r'){paswrd[i]=cr;cout<<"*";}
      else{
            paswrd[i]='\0';
         break;
      }
   }
   //cout<<"\n\nPassword : "<<paswrd;
   //cout<<"\n\nCmpPassword : "<<cmpPaswrd;
   int match = stringMatch(paswrd,cmpPaswrd);
   if(match==1){return bs1[x-1].getPartyId();}
   else{
      cout<<"\n   Wrong Password!";
      getch();
   }

      return 0;

}
int inputPartyUpdateChoice(){
   int x;
   cout<<"   1.Change HeadName"<<endl;
   cout<<"   2.Change Password"<<endl;
   cout<<"   3.Go Back"<<endl;
   cout<<"\n   Enter your Choice : ";
   cin>>x;
   return x;
}
int confirm(){
   char x;
   cout<<"\n   Are You Sure (y/n) : ";cin>>x;
   //x = getch();cout<<x;
   if(x=='y'||x=='Y') return 1;
   else return 0;
}
void displayCandidateInfo(Candidate obj){
   int c=0;
   c=countDigits(obj.getCandidateID());
   cout<<"   "<<obj.getCandidateID();
   for(int i=c;i<7;i++) cout<<" ";
   c=countChar(obj.getCandidateName());
   cout<<obj.getCandidateName();
   for(int i=c;i<25;i++) cout<<" ";
   c=countChar(obj.getstateName2());
   cout<<obj.getstateName2();
   for(int i=c;i<20;i++) cout<<" ";
   c=countChar(obj.getcityName2());
   cout<<obj.getcityName2();
   for(int i=c;i<20;i++) cout<<" ";
   c=countDigits(obj.getVotes());
   cout<<obj.getVotes();

}
void viewPartyInfo(int Id){
   getPartyIdNo();
   if(partyId==0){cout<<"\n   No Record Found";getch();return;}
   Party bs1[partyId],obj;
   getCandidateId();
   Candidate cs1[candidateId];

   int sIndex = Id-1;
   for(int i=0;i<partyId;i++){
      bs1[i].getParty(i);
      /*if(bs1[i].getPartyId()==Id){
         sIndex = i;
      }*/
   }


   obj = bs1[sIndex];
   obj.setSeats(0);
   obj.setVotes(0);
   for(int i=0;i<candidateId;i++){
      cs1[i].getCandidate(i);
      if(cs1[i].getPartyId()==obj.getPartyId()){
         int pseats = obj.getSeats();
         pseats = pseats + cs1[i].getSeats();
         obj.setSeats(pseats);
         int pVotes = obj.getVotes();
         pVotes = pVotes + cs1[i].getCandidateVotes();
         obj.setVotes(pVotes);
      }
   }
   redo:;
   funHeading("");
   cout<<"\n   PartyName : "<<obj.getPartyName();
   cout<<"\n   Head      : "<<obj.getHeadName();
   cout<<"\n   Members   : "<<obj.getMembers();
   cout<<"\n   Seats     : "<<obj.getSeats();
   cout<<"\n   Votes     : "<<obj.getVotes();
   choice:;
   int ch = choiceAdmin(6);
   switch (ch){
   case 1:
      goto choice1;
   /*case 3:
      goto choice3;*/
   case 2:
      goto choice2;
   case 0:
      //bs1[sIndex].setMembers(3);
      setPartyIdNo();
      remove("Party.txt");
      for(int i=0;i<partyId;i++){bs1[i].storeParty();}
      return;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto redo;
   }
   choice1:;
      funHeading("List Of Members : -");
      cout<<"\n   PartyName : "<<obj.getPartyName();
      cout<<"       Head : "<<obj.getHeadName();
      cout<<"       Members : "<<obj.getMembers();

      cout<<"\n\n\n   ID         Name                  State               City            Votes\n";
      for(int i=0;i<candidateId;i++){
         //cs1[i].getCandidate(i);
         if(cs1[i].getPartyId()==obj.getPartyId()){
            displayCandidateInfo(cs1[i]);
            cout<<"\n";
         }
      }
      getch();
      goto redo;
   /*choice3:;
      char cnfm;
      cout<<"\n   Are you Sure to Delete Your Party "<<obj.getPartyName()<<" (y/n) : ";
      //cnfm = getch();cout<<cnfm;
      cin>>cnfm;
      if(cnfm == 'y'||cnfm == 'Y'){
         for(int i=sIndex;i<partyId;i++){bs1[i]=bs1[i+1];}
         partyId--;
         cout<<"\n\n   Record Deleted\n\n   Press any Key to Update Record";getch();
      }
      else{
         goto redo;
      }
      setPartyIdNo();
      remove("Party.txt");
      for(int i=0;i<partyId;i++){bs1[i].storeParty();}
      return;*/
   choice2:;

   cout<<"\n\n";
   int ch3 = inputPartyUpdateChoice();
   cin.ignore();
   if(ch3 == 1){
      char newName[25];
      cout<<"\n   Enter the New HeadName : ";
      cin.getline(newName,24);
      int y=confirm();
      if(y==1){
         bs1[sIndex].setHeadName(newName);
         cout<<"\n\n   Record Has Been Updated\n\n   Press Any Key";
         getch();
      }
      goto redo;
   }
   else if(ch3==2){
      char newPassword[10],cr;
      cout<<"\n   Enter the New Password : ";
      for(int i =0;i<10;i++){
         cr=getch();
         if(cr!='\r'){newPassword[i]=cr;cout<<"*";}
         else{newPassword[i]='\0';break;}
      }
      int y=confirm();
      if(y==1){
         bs1[sIndex].setPassword(newPassword);
         cout<<"\n\n   Record Has Been Updated\n\n   Press Any Key";
         getch();
      }
      goto redo;
   }
   else if (ch3==3){
      goto redo;
   }
   else{cout<<"\n   Enter the Correct Choice!";getch();goto redo;}
}

int Candidate::getCandidate(int x){
   int i=0;
   ifstream finCandidateRecord;
   finCandidateRecord.open("candidates.txt",ios::in|ios::binary);
   if(!finCandidateRecord){cout<<"\n   File not Found";}
   else{
      while(!finCandidateRecord.eof()&&i!=x+1)
      {
         finCandidateRecord.read((char *)this,sizeof(*this));
         i++;
      }
   }
}
int Candidate::storeCandidate(){
   ofstream foutCandidate;
   foutCandidate.open("candidates.txt",ios::app|ios::binary);
   foutCandidate.write((char *)this,sizeof(*this));
   foutCandidate.close();
}
int funCandidateInput(Candidate *bs1,int x){
   Candidate obj;
   cout<<"   ";
   obj.getCandidateInfo();
   /*int objPartyId = obj.getPartyId();
   string objName = obj.getstateName();
   int j;
   for(j = candidateId-1;j>0;j--){
         int cmpPartyId = bs1[j-1].getPartyId();
         //int k = stringCmp(cmpState,objState);
         if(objPartyId<cmpPartyId){bs1[j] = bs1[j-1];}
         else if(objPartyId=cmpPartyId){

            string cmpState = bs1[j-1].getstateName();
            int k = stringCmp(cmpState,objName);
            if(k==0){bs1[j] = bs1[j-1];}
            else{goto in;}
         }
         else{break;}
      }
      in:;
      bs1[j] = obj;*/
      //getCandidateId();
      //cout<<candidateId<<"  "<<obj.getCandidateID();
      bs1[candidateId-1] = obj;

   return obj.getCandidateID();
}
int insertNewCandidate(){
   int x=1,Id=0;
   getCandidateId();
   if(x==0){return Id;}
   Candidate bs1[candidateId+x];

   funHeading("Creating Candidate Account : \n");
   for(int i=0;i<candidateId;i++){
      bs1[i].getCandidate(i);
   }
   Id = funCandidateInput(bs1,x);
   setCandidateId();
   remove("candidates.txt");
   for(int i=0;i<candidateId;i++){bs1[i].storeCandidate();}
   cout<<"\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
   getch();
   return Id;
}
int CandidateLogin(){
   getCandidateId();
   if(candidateId==0){cout<<"\n   No Record Found";getch();return 0;}
   Candidate bs1[candidateId];
   for(int i=0;i<candidateId;i++){
      bs1[i].getCandidate(i);
   }
   redo:;
   funHeading("Candidate Login Page: ");

   int Id;
   cout<<"\n   Enter Your Id : ";
   cin>>Id;cin.ignore();
   bool f = 0;int index = Id-1;
   if(Id == bs1[index].getCandidateID()){
      f=1;
   }
   /*for(int i=0;i<candidateId;i++){
      if(Id == bs1[i].getCandidateID()){
         index = i;
         f=1;
         break;
      }
   }*/
   if(f!=1){cout<<"\n   No Account exists with this Id!";getch();goto redo;}

   char paswrd[10],cr;
   string cmpPaswrd = bs1[index].getPassword2();
   cout<<"\n   Enter Your Password: ";
   for(int i=0;i<10;i++){
      cr = getch();
      if(cr!='\r'){paswrd[i]=cr;cout<<"*";}
      else{
            paswrd[i]='\0';
         break;
      }
   }
   //cout<<"\n\nPassword : "<<paswrd;
   //cout<<"\n\nCmpPassword : "<<cmpPaswrd;
   int match = stringMatch(paswrd,cmpPaswrd);
   if(match==1){return bs1[index].getCandidateID();}
   else{
      cout<<"\n   Wrong Password!";
      getch();
   }
   return 0;

}
int inputCandidateUpdateChoice(){
   int x;
   cout<<"   1.Change Name"<<endl;
   cout<<"   2.Change Password"<<endl;
   cout<<"   3.Change Description"<<endl;
   cout<<"   4.Go Back"<<endl;
   cout<<"\n   Enter your Choice : ";
   cin>>x;
   return x;
}
void viewCandidateInfo(int Id){
   getCandidateId();
   if(candidateId==0){cout<<"\n   No Record Found";getch();return;}
   Candidate bs1[candidateId],obj;
   int sIndex = Id-1;
   for(int i=0;i<candidateId;i++){
      bs1[i].getCandidate(i);
      /*if(bs1[i].getCandidateID()==Id){
      sIndex = i;
      }*/
   }
   redo:;
   obj = bs1[sIndex];
   funHeading("Welcome : ");
   cout<<"\n   PartyName  : "<<obj.getPartyName();
   cout<<"        Head  : "<<obj.getHeadName();
   cout<<"\n\n   Name         : "<<obj.getCandidateName();
   cout<<"\n   Designation  : "<<obj.getCandidateDesignation();
   cout<<"\n   State        : "<<obj.getstateName2();
   cout<<"\n   City         : "<<obj.getcityName2();
   cout<<"\n   Votes        : "<<obj.getVotes();
   cout<<"\n   Seats        : "<<obj.getSeats();
   choice:;
   int ch = choiceAdmin(7);
   switch (ch){
   case 1:
      goto choice1;
   case 2:
      goto choice2;
   case 0:
      /*setPartyCount();*/
      remove("candidates.txt");
      for(int i=0;i<candidateId;i++){bs1[i].storeCandidate();}
      return;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto redo;
   }
   choice1:;
   funHeading("List Of Other Members : -");
      cout<<"\n   PartyName : "<<obj.getPartyName();
      cout<<"       Head : "<<obj.getHeadName();

      cout<<"\n\n\n   ID         Name                  State               City            Votes\n";
      for(int i=0;i<candidateId;i++){
         if(bs1[i].getPartyId()==obj.getPartyId() && bs1[i].getCandidateID() != obj.getCandidateID()){
            displayCandidateInfo(bs1[i]);
            cout<<"\n";
         }
      }
      getch();
      goto redo;
   choice2:;
   cout<<"\n\n";
   int ch3 = inputCandidateUpdateChoice();
   cin.ignore();
   if(ch3==1){
      char newName[25];
      cout<<"\n   Enter the New HeadName : ";
      cin.getline(newName,24);
      int y=confirm();
      if(y==1){
         bs1[sIndex].setCandidateName(newName);
         cout<<"\n\n   Record Has Been Updated\n\n   Press Any Key";
         getch();
      }
      goto redo;
   }
   else if(ch3==2){
      char newPassword[10],cr;
      cout<<"\n   Enter the New Password : ";
      for(int i =0;i<10;i++){
         cr=getch();
         if(cr!='\r'){newPassword[i]=cr;cout<<"*";}
         else{newPassword[i]='\0';break;}
      }
      cout<<"\n";
      int y=confirm();
      if(y==1){
         bs1[sIndex].setPassword(newPassword);
         cout<<"\n\n   Record Has Been Updated\n\n   Press Any Key";
         getch();
      }
      goto redo;
   }
   else if(ch3==3){
      char newDescription[25];
      cout<<"\n   Enter the New Description : ";
      cin.getline(newDescription,24);
      int y=confirm();
      if(y==1){
         bs1[sIndex].setCandidatePost(newDescription);
         cout<<"\n\n   Record Has Been Updated\n\n   Press Any Key";
         getch();
      }
      goto redo;
   }
   else if (ch3==4){
      goto redo;
   }
   else{cout<<"\n   Enter the Correct Choice!";getch();goto redo;}
}

class Voter:public Password,public City{
   private:
      int voterID,partyId,age;
      char voterName[25],partyName[50],gender;

   public:
      Voter(){
         partyId = 0;
         age = 18;
         voterID = 0;
         strcpy(partyName,"null");
         strcpy(voterName,"null");
         setPassword("1234");
         setstateId(0);
         setCityId(0);
         setstateName("NoName");
         setcityName("NoName");
      }

      void getVoterInfo(){
         getVoterId();
         voterID = ++voterId;
         cout<<"\n\n   Your Id :  "<<voterID;

         cin.ignore();
         cout<<"\n\n   Enter Your Name            :  ";
         cin.getline(voterName,24);
         cout<<"\n   Enter Your Age             :  ";
         cin>>age;
         cout<<"\n   Enter Your Gender(M/F)     :  ";
         cin>>gender;

         redo1:;
         funHeading("Creating Voter Account : ");
         cout<<"\n\n   Your Id : "<<voterID;
         cout<<"\n\n   Enter Your Name            :  "<<voterName;
         cout<<"\n\n   Enter Your Age             :  "<<age;
         cout<<"\n\n   Enter Your Gender(M/F)     :  "<<gender<<"\n\n";
         getStateCount();
         State bs1[stateCount];
         cout<<endl<<"   S.No.  State\n\n";
         for(int i=0;i<stateCount;i++){
            bs1[i].getStates(i);
            cout<<"   "<<i+1<<".";
            int j = countDigits(i+1);
            for(int k = j;k<8;k++)
               cout<<" ";
            bs1[i].showStateInfo();
         }
         int sr;cout<<"\n   Choose Your State (S.No) : ";cin>>sr;
         if(sr<=0||sr>stateCount){cout<<"\n   Invalid Choice!";getch();goto redo1;}
         setstateId(bs1[sr-1].getstateId());setstateName(bs1[sr-1].getstateName2());

         redo2:;
         funHeading("Creating Voter Account : ");
         cout<<"\n\n   Your Id : "<<voterID;
         cout<<"\n\n   Enter Your Name            :  "<<voterName;
         cout<<"\n\n   Enter Your Age             :  "<<age;
         cout<<"\n\n   Enter Your Gender(M/F)     :  "<<gender;
         cout<<"\n\n   Select Your State          :  "<<getstateName2()<<"\n\n";
         getCityCount();
         City cs1[cityCount];
         cout<<endl<<"   S.No.  City\n\n";
         for(int i=0;i<cityCount;i++){
            cs1[i].getCity(i);
            if(cs1[i].getstateId()==getstateId()){
               cout<<"   "<<i+1<<".";
               int j = countDigits(i+1);
               for(int k = j;k<8;k++)
                  cout<<" ";
               cs1[i].showCityInfo();

            }
         }
         cout<<"\n   Choose Your City (S.No) : ";cin>>sr;
         if(sr<=0||sr>cityCount){cout<<"\n   Invalid Choice!";getch();goto redo2;}
         setCityId(cs1[sr-1].getcityId());setcityName(cs1[sr-1].getcityName2());

         redo3:;
         funHeading("Creating Voter Account : ");
         cout<<"\n\n   Your Id : "<<voterID;
         cout<<"\n\n   Enter Your Name            :  "<<voterName;
         cout<<"\n\n   Enter Your Age             :  "<<age;
         cout<<"\n\n   Enter Your Gender(M/F)     :  "<<gender;
         cout<<"\n\n   Select Your State          :  "<<getstateName2();
         cout<<"\n\n   Select Your City           :  "<<getcityName2()<<"\n\n";


         partyId = 0;
         strcpy(partyName,"null");
         setLeadCandidateId(0);
         char arr[10],cr;
         cout<<"\n   Enter the Password : ";
         for(int i=0;i<10;i++){
            cr = getch();
            if(cr!='\r'){cout<<"*";arr[i]=cr;}

            else{
               arr[i]='\0';
               setPassword(arr);
               break;
            }
         }
         setVoterId();

      }

      char * getVoterName(){return voterName;}
      char * getVoterPartyName(){return partyName;}
      string getVoterName2(){return voterName;}
      int getVoterID(){return voterID;}
      int getVoterAge(){return age;}
      char getVoterGender(){return gender;}
      int getVoterPartyId(){return partyId;}

      void setVoterName(char *newName){strcpy(voterName,newName);}
      void setPartyName(char *newParty){strcpy(partyName,newParty);}
      void setPartyId(int n ){partyId = n;}
      void setAge(int n){age = n;}
      int storeVoter();
      int getVoter(int x);
};
int Voter::getVoter(int x){
   int i=0;
   ifstream finVoterRecord;
   finVoterRecord.open("voter.txt",ios::in|ios::binary);
   if(!finVoterRecord){cout<<"\n   File not Found";}
   else{
      while(!finVoterRecord.eof()&&i!=x+1)
      {
         finVoterRecord.read((char *)this,sizeof(*this));
         i++;
      }
   }
}
int Voter::storeVoter(){
   ofstream foutVoter;
   foutVoter.open("voter.txt",ios::app|ios::binary);
   foutVoter.write((char *)this,sizeof(*this));
   foutVoter.close();
}
int funVoterInput(Voter *b,int x){
   Voter obj;
   cout<<"   ";
   obj.getVoterInfo();
   /*string objState = obj.getstateName();
      int j;
      for(j = voterId-1;j>0;j--){
         string cmpState = b[j-1].getstateName();
         int k = stringCmp(cmpState,objState);
         if(k==0){b[j] = b[j-1];}
         else if(k==2){
            string objCity = obj.getcityName();
            string cmpCity = b[j-1].getcityName();
            int k = stringCmp(cmpCity,objCity);
            if(k==0){b[j] = b[j-1];}
            else{goto in;}
         }
         else{break;}
      }
      in:;
      b[j] = obj;*/
      b[voterId-1] = obj;

   return obj.getVoterID();
}
int insertNewVoter(){
   int x=1,Id=0;
   getVoterId();
   if(x==0){return Id;}
   Voter bs1[voterId+x];

   funHeading("Creating Voter Account : \n");
   for(int i=0;i<voterId;i++){
      bs1[i].getVoter(i);
   }
   Id = funVoterInput(bs1,x);
   setVoterId();
   remove("voter.txt");
   for(int i=0;i<voterId;i++){bs1[i].storeVoter();}
   cout<<"\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
   getch();
   return Id;
}
int VoterLogin(){
   getVoterId();
   if(voterId==0){cout<<"\n   No Record Found";getch();return 0;}
   Voter bs1[voterId];
   for(int i=0;i<voterId;i++){
      bs1[i].getVoter(i);
   }
   redo:;
   funHeading("Voter Login Page: ");

   int Id;
   cout<<"\n   Enter Your Id : ";
   cin>>Id;cin.ignore();
   bool f = 0;
   int index=Id-1;
   //cout<<bs1[index].getVoterID();
   if(Id == bs1[index].getVoterID()){
      f=1;
   }
   /*for(int i=0;i<voterId;i++){
      if(Id == bs1[i].getVoterID()){
         index = i;
         f=1;
         break;
      }
   }*/
   if(f!=1){cout<<"\n   No Account exists with this Id!";getch();goto redo;}

   char paswrd[10],cr;
   string cmpPaswrd = bs1[index].getPassword2();
   cout<<"\n   Enter Your Password: ";
   for(int i=0;i<10;i++){
      cr = getch();
      if(cr!='\r'){paswrd[i]=cr;cout<<"*";}
      else{
            paswrd[i]='\0';
         break;
      }
   }
   //cout<<"\n\nPassword : "<<paswrd;
   //cout<<"\n\nCmpPassword : "<<cmpPaswrd;
   int match = stringMatch(paswrd,cmpPaswrd);
   if(match==1){return Id;}
   else{
      cout<<"\n   Wrong Password!";
      getch();
   }
   return 0;

}
int inputVoterUpdateChoice(){
   int x;
   cout<<"   1.Change Name"<<endl;
   cout<<"   2.Change Age"<<endl;
   cout<<"   3.Change Password"<<endl;
   cout<<"   4.Go Back"<<endl;
   cout<<"\n   Enter your Choice : ";
   cin>>x;
   return x;
}
void displayCandidateForVote(Candidate obj){
   int c=0;
   c=countDigits(obj.getCandidateID());
   cout<<"   "<<obj.getCandidateID();
   for(int i=c;i<7;i++) cout<<" ";
   c=countChar(obj.getCandidateName());
   cout<<obj.getCandidateName();
   for(int i=c;i<25;i++) cout<<" ";
   /*c=countChar(obj.getstateName2());
   cout<<obj.getstateName2();
   for(int i=c;i<20;i++) cout<<" ";
   c=countChar(obj.getcityName2());
   cout<<obj.getcityName2();
   for(int i=c;i<20;i++) cout<<" ";*/
   c=countChar(obj.getPartyName());
   cout<<obj.getPartyName();
}
void voterMakeVote(Voter *vs1,int Id){
   getCandidateId();
   Candidate cs1[candidateId];
   getCityCount();
   City city1[cityCount];
   int cIndex;
   int vCityId = vs1[Id-1].getcityId();
   for(int i=0;i<cityCount;i++){
      city1[i].getCity(i);
      if(city1[i].getcityId()==vCityId){
         cIndex = i;
      }
   }
   funHeading("Making A Vote : \n");
   cout<<"   State : "<<vs1[Id-1].getstateName2()<<"        City : "<<vs1[Id-1].getcityName2();
   cout<<"\n\n\n   ID      CandidateName                  Party\n";
   for(int i=0;i<candidateId;i++){
      cs1[i].getCandidate(i);
      if(cs1[i].getcityId()==vCityId){
         displayCandidateForVote(cs1[i]);
         cout<<"\n";
      }
   }
   int selectedId;
   cout<<"\n\n   Select via Id whom you want to vote :  ";
   cin>>selectedId;
   char ays;
   cout<<"\n   Are you sure to vote for " << cs1[selectedId-1].getCandidateName() <<" ( "<< cs1[selectedId-1].getPartyName()<<" ) (y/n):";
   cin>>ays;
   if(ays=='y' || ays =='Y'){
      int vote = cs1[selectedId-1].getCandidateVotes();
      cs1[selectedId-1].setCandidateVotes(vote+1);
      vs1[Id-1].setPartyId(cs1[selectedId-1].getCandidateID());
      vs1[Id-1].setPartyName(cs1[selectedId-1].getPartyName());
      int leadingCandidate = city1[cIndex].getLeadCandidateId();
      if(leadingCandidate!=0){
         int maxvotes = cs1[leadingCandidate-1].getCandidateVotes();
         if(vote>maxvotes){city1[cIndex].setLeadCandidateId(selectedId);}

      }
      else{
         int maxvotes = 0;
         for(int i=0;i<candidateId;i++){
            if(cs1[i].getcityId()==vCityId){
               if(cs1[i].getCandidateVotes()>maxvotes){
                  maxvotes = cs1[i].getCandidateVotes();
                  city1[cIndex].setLeadCandidateId(cs1[i].getCandidateID());
               }
            }
         }
      }
      for(int i=0;i<candidateId;i++){
            if(cs1[i].getcityId()==vCityId){
               if(cs1[i].getCandidateID()==city1[cIndex].getLeadCandidateId()){
                     cs1[i].setSeats(1);
               }
               else{
                  cs1[i].setSeats(0);
               }
            }
         }
      remove("Cities.txt");
      for(int i=0;i<cityCount;i++){city1[i].storeCity();}
      remove("candidates.txt");
      for(int i=0;i<candidateId;i++){cs1[i].storeCandidate();}

      cout<<"\n   Voted Successfully\n\n   Press any Key To Update Data";
      getch();
   }
   else return;

}
void viewVoterInfo(int Id){
   getVoterId();
   if(voterId==0){cout<<"\n   No Record Found";getch();return;}
   Voter bs1[voterId],obj;
   int sIndex = Id -1;
   for(int i=0;i<voterId;i++){
      bs1[i].getVoter(i);
      /*if(bs1[i].getVoterID()==Id){
      sIndex = i;
      }*/
   }
   redo:;
   obj = bs1[sIndex];
   funHeading("Welcome : ");
   cout<<"\n   Name   : "<<obj.getVoterName();
   cout<<"          VotedToParty : "<<obj.getVoterPartyName();
   cout<<"\n   Age    : "<<obj.getVoterAge();
   cout<<"\n   Gender : "<<obj.getVoterGender();
   cout<<"\n   State  : "<<obj.getstateName2();
   cout<<"\n   City   : "<<obj.getcityName2();
   choice:;
   int ch = choiceAdmin(8),able;
   switch (ch){
   case 1:
      able = obj.getVoterPartyId();
      //cout<<able;getch();
      if(able==0){
         voterMakeVote(bs1,Id);
      }
      else {cout<<"\n   You have already voted.Now you can't change your vote";getch();
         //voterMakeVote(bs1,Id);
      }
      goto redo;
   case 2:
      goto choice2;
   case 0:
      /*setPartyCount();*/
      remove("voter.txt");
      for(int i=0;i<voterId;i++){bs1[i].storeVoter();}
      return;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto redo;
   }
   choice2:;

   cout<<"\n\n";
   int ch3 = inputVoterUpdateChoice();
   cin.ignore();
   if(ch3 == 1){
      char newName[25];
      cout<<"\n   Enter the New Name : ";
      cin.getline(newName,24);
      int y=confirm();
      if(y==1){
         bs1[sIndex].setVoterName(newName);
         cout<<"\n\n   Record Has Been Updated\n\n   Press Any Key";
         getch();
      }
      goto redo;
   }
   else if(ch3 == 2){
      int newAge;
      cout<<"\n   Enter the New Age : ";
      cin>>newAge;
      int y=confirm();
      if(y==1){
         bs1[sIndex].setAge(newAge);
         cout<<"\n\n   Record Has Been Updated\n\n   Press Any Key";
         getch();
      }
      goto redo;
   }
   else if(ch3==3){
      char newPassword[10],cr;
      cout<<"\n   Enter the New Password : ";
      for(int i =0;i<10;i++){
         cr=getch();
         if(cr!='\r'){newPassword[i]=cr;cout<<"*";}
         else{newPassword[i]='\0';break;}
      }
      cout<<"\n";
      int y=confirm();
      if(y==1){
         bs1[sIndex].setPassword(newPassword);
         cout<<"\n\n   Record Has Been Updated\n\n   Press Any Key";
         getch();
      }
      goto redo;
   }
   else if (ch3==4){
      goto redo;
   }
   else{cout<<"\n   Enter the Correct Choice!";getch();goto redo;}
}

class Interval{
   public:
      int low;
      int high;
      int PID;
      Interval(){
         low = 0;
         high = 0;
         PID = 0;
      }
      Interval(int l,int h, int p){
         low = l;
         high = h;
         PID = p;
      }
      void getIntervalInfo(){
         cout<<"\n   Enter Low : ";
         cin>>low;
         cout<<"\n   Enter High : ";
         cin>>high;
         getPartyIdNo();
         Party ps1[partyId];
         cout<<endl<<"   ID  Party\n\n";
         for(int i=0;i<partyId;i++){
            ps1[i].getParty(i);
            cout<<"   "<<ps1[i].getPartyId()<<".";
            int j = countDigits(i+1);
            for(int k = j;k<8;k++)cout<<" ";
            cout<<ps1[i].getPartyName()<<endl;
         }
         cout<<"\n   Choose The Party (ID) : ";cin>>PID;
         resultId++;

      }
      int getLow(){return low;}
      int getHigh(){return high;}
      int getpId(){return PID;}

      void setLow(int l){low = l;}
      void setHigh(int h){high = h;}
      void setpId(int p){PID = p;}

      int storeInterval();
      int getInterval(int x);

};
int Interval::getInterval(int x){
   int i=0;
   ifstream finIntervalRecord;
   finIntervalRecord.open("Record.txt",ios::in|ios::binary);
   if(!finIntervalRecord){cout<<"\n   File not Found";}
   else{
      while(!finIntervalRecord.eof()&&i!=x+1)
      {
         finIntervalRecord.read((char *)this,sizeof(*this));
         i++;
      }
   }
}
int Interval::storeInterval(){
   ofstream foutInterval;
   foutInterval.open("Record.txt",ios::app|ios::binary);
   foutInterval.write((char *)this,sizeof(*this));
   foutInterval.close();
}
struct ITNode{
	Interval *i;
	int max;
	ITNode *left, *right;
};
ITNode * newNode(Interval i){
	ITNode *temp = new ITNode;
	temp->i = new Interval(i);
	temp->max = i.getHigh();
	temp->left = temp->right = NULL;
	return temp;
};
ITNode *insert(ITNode *root, Interval i){
	if (root == NULL) return newNode(i);

   int l = root->i->getLow();

	if (i.getLow() < l) root->left = insert(root->left, i);
   else root->right = insert(root->right, i);

	if (root->max < i.getHigh()) root->max = i.getHigh();

	return root;
}
bool doOVerlap(Interval i1, Interval i2){
	if (i1.getLow() < i2.getHigh() && i2.getLow() < i1.getHigh()) return true;
	return false;
}
//segment start
void build(int ind,int low, int high){
    if(low==high)
    {
        seg[ind]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);

}
int query(int ind,int low, int high, int l, int r){
    if(low>=l && high<=r)
    {
        return seg[ind];
    }
    if(high<l || low>r)
        return INT_MIN;
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return max(left,right);
}
void update(int low,int high,int idx,int new_val,int ind ){
    if(low==high)
    {
        a[idx]=new_val;
        seg[ind]==new_val;
        return;
    }
    else{
        int mid=(low+high)/2;
        if(low<=idx && idx<=mid)
        {
            update(low,mid,idx,new_val,2*ind+1);
        }
        else{
            update(mid+1,high,idx,new_val,2*ind+2);
    }
        seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);

    }
}
//segment end
void displayResultRecord(ITNode *root){
   getPartyIdNo();
   Party bs1[partyId];
   for(int i=0;i<partyId;i++){
      bs1[i].getParty(i);
   }
   int RpId = root->i->PID;
   int c=0;
   //c=countDigits(obj.getCandidateID());
   cout<<"   "<<root->i->low<<" - "<<root->i->high;
   for(int i=0;i<7;i++) cout<<" ";
   c=countDigits(bs1[RpId-1].getPartyId());
   cout<<bs1[RpId-1].getPartyId();
   for(int i=c;i<7;i++) cout<<" ";
   c=countChar(bs1[RpId-1].getPartyName());
   cout<<bs1[RpId-1].getPartyName();
   for(int i=c;i<30;i++) cout<<" ";
   c=countChar(bs1[RpId-1].getHeadName());
   cout<<bs1[RpId-1].getHeadName()<<"\n";
}

Interval *overlapSearchAllSorted(ITNode *root, Interval i){
    if (root==NULL) return NULL;
    if (root->left != NULL && root->left->max>=i.low)
      overlapSearchAllSorted(root->left, i);
    if (doOVerlap(*(root->i), i)) displayResultRecord(root);
      //cout <<"\nOverlaps with [" << root->i->getLow()<<","<<root->i->getHigh()<<"]    PartyID : "<<root->i->getpId();
    overlapSearchAllSorted(root->right,i);
}
void inorder(ITNode *root){
	if (root == NULL) return;
	inorder(root->left);
	cout << "[" << root->i->getLow() << ", " << root->i->getHigh() << "]"
		<< " max = " << root->max<<"PartyId = "<<root->i->getpId() << endl;
	inorder(root->right);
}


void displayVoterRecord(Voter bs1[],int vId){
   funHeading("Voter's Record : ");

   cout<<"\n   ID     NAME               AGE   GENDER   STATE          CITY     Vote-STATUS\n\n";

   for(int i=0;i<vId;i++){
      int c=0;
      c=countDigits(bs1[i].getVoterID());
      cout<<"   "<<bs1[i].getVoterID();
      for(int i=c;i<7;i++) cout<<" ";
      c=countChar(bs1[i].getVoterName());
      cout<<bs1[i].getVoterName();
      for(int i=c;i<20;i++) cout<<" ";
      c=countDigits(bs1[i].getVoterAge());
      cout<<bs1[i].getVoterAge();
      for(int i=c;i<7;i++) cout<<" ";

      cout<<bs1[i].getVoterGender();
      for(int i=1;i<7;i++) cout<<" ";

      c=countChar(bs1[i].getstateName2());
      cout<<bs1[i].getstateName2();
      for(int i=c;i<15;i++) cout<<" ";
      c=countChar(bs1[i].getcityName2());
      cout<<bs1[i].getcityName2();
      for(int i=c;i<15;i++) cout<<" ";
      c = bs1[i].getVoterPartyId();
      if(c == 0)cout<<"0\n";
      else cout<<"1\n";

   }
}
void viewVoterRecord(){
   getVoterId();
   if(voterId==0){cout<<"\n   No Record Found";getch();return;}
   Voter bs1[voterId];
   for(int i = 0;i<voterId;i++){
      bs1[i].getVoter(i);
   }

   displayVoterRecord(bs1,voterId);
   redo:;
   cout<<"\n\n   0.GoBack";
   cout<<"\n   1.Apply Filter (Sort/OrderBy (State,City))";
   int ch;
   cout<<"\n\n   Enter Your Choice : ";
   cin>>ch;
   if(ch == 0){
      return;
   }
   else{
      Voter bs2[voterId],obj;
      int id = 0;
      for(int i = 0;i<voterId;i++){
         obj = bs1[i];
         string objState = obj.getstateName();
         int j;
         for(j=id;j>0;j--){
            string cmpState = bs2[j-1].getstateName();
            int k = stringCmp(cmpState,objState);
            if(k==0){bs2[j] = bs2[j-1];}
            else if(k==2){
               string objCity = obj.getcityName();
               string cmpCity = bs2[j-1].getcityName();
               int k = stringCmp(cmpCity,objCity);
               if(k==0){bs2[j] = bs2[j-1];}
               else{goto in;}
            }
            else{break;}

         }
         in:;
         id++;
         bs2[j] = obj;
      }
      displayVoterRecord(bs2,voterId);
      goto redo;
   }

}
void displayCandidateRecord(Candidate bs1[],int cId){
   funHeading("Candidate's Record : ");

   cout<<"\n   ID     NAME                     PARTYNAME                    STATE           CITY         VOTES  SEATS\n\n";
   for(int i=0;i<cId;i++){
      int c=0;
      c=countDigits(bs1[i].getCandidateID());
      cout<<"   "<<bs1[i].getCandidateID();
      for(int i=c;i<7;i++) cout<<" ";
      c=countChar(bs1[i].getCandidateName());
      cout<<bs1[i].getCandidateName();
      for(int i=c;i<25;i++) cout<<" ";
      c=countChar(bs1[i].getPartyName());
      cout<<bs1[i].getPartyName();
      for(int i=c;i<30;i++) cout<<" ";
      c=countChar(bs1[i].getstateName2());
      cout<<bs1[i].getstateName2();
      for(int i=c;i<15;i++) cout<<" ";
      c=countChar(bs1[i].getcityName2());
      cout<<bs1[i].getcityName2();
      for(int i=c;i<15;i++) cout<<" ";
      c=countDigits(bs1[i].getCandidateVotes());
      cout<<bs1[i].getCandidateVotes();
      for(int i=c;i<7;i++) cout<<" ";
      cout<<bs1[i].getSeats()<<"\n";
   }
}
void viewCandidateRecord(){
   getCandidateId();
   if(candidateId==0){cout<<"\n   No Record Found";getch();return;}
   Candidate bs1[candidateId];

   for(int i=0;i<candidateId;i++){
      bs1[i].getCandidate(i);
   }
   displayCandidateRecord(bs1,candidateId);
   redo:;
   cout<<"\n\n   0.GoBack";
   cout<<"\n   1.Apply Filter";
   int ch;
   cout<<"\n\n   Enter Your Choice : ";
   cin>>ch;
   if(ch != 1){
      return;
   }
   else{
      Candidate bs2[candidateId],obj;
      int id = 0;
      cout<<"\n   0.GoBack";
      cout<<"\n   1.Sort/OrderBy(Id)";
      cout<<"\n   2.Sort/OrderBy(State,City,PartyName)";
      cout<<"\n   3.Sort/OrderBy(PartyName,State,City)";
      cout<<"\n\n   Enter Your Choice : ";
      cin>>ch;
      if(ch==2){
         for(int i = 0;i<candidateId;i++){
            obj = bs1[i];
            string objState = obj.getstateName();
            int j;
            for(j=id;j>0;j--){
               string cmpState = bs2[j-1].getstateName();
               int k = stringCmp(cmpState,objState);
               if(k==0){bs2[j] = bs2[j-1];}
               else if(k==2){
                  string objCity = obj.getcityName();
                  string cmpCity = bs2[j-1].getcityName();
                  int k = stringCmp(cmpCity,objCity);
                  if(k==0){bs2[j] = bs2[j-1];}
                  else if(k==2){
                     string objParty = obj.getPartyName2();
                     string cmpParty = bs2[j-1].getPartyName2();
                     int k = stringCmp(cmpParty,objParty);
                     if(k==0){bs2[j] = bs2[j-1];}
                     else{goto in;}
                  }
                  else{goto in;}
               }
               else{break;}

            }
            in:;
            id++;
            bs2[j] = obj;
         }
         displayCandidateRecord(bs2,candidateId);
         goto redo;
      }
      else if(ch==3){
         for(int i = 0;i<candidateId;i++){
            obj = bs1[i];
            string objParty = obj.getPartyName2();
            int j;
            for(j=id;j>0;j--){
               string cmpParty = bs2[j-1].getPartyName2();
               int k = stringCmp(cmpParty,objParty);
               if(k==0){bs2[j] = bs2[j-1];}
               else if(k==2){
                  string objState = obj.getstateName();
                  string cmpState = bs2[j-1].getstateName();
                  int k = stringCmp(cmpState,objState);
                  if(k==0){bs2[j] = bs2[j-1];}
                  else if(k==2){
                     string objCity = obj.getcityName();
                     string cmpCity = bs2[j-1].getcityName();
                     int k = stringCmp(cmpCity,objCity);
                     if(k==0){bs2[j] = bs2[j-1];}
                     else{goto in2;}
                  }
                  else{goto in2;}
               }
               else{break;}

            }
            in2:;
            id++;
            bs2[j] = obj;
         }
         displayCandidateRecord(bs2,candidateId);
         goto redo;
      }
      else{
         displayCandidateRecord(bs1,candidateId);
         goto redo;
      }
   }

}
void viewPartyRecord(){
   getPartyIdNo();
   if(partyId==0){cout<<"\n   No Record Found";getch();return;}
   Party bs1[partyId];

   funHeading("Party's Record : ");

   cout<<"\n   ID     NAME                          HEAD             MEMBERS\n\n";
   for(int i=0;i<partyId;i++){
      bs1[i].getParty(i);
      int c=0;
      c=countDigits(bs1[i].getPartyId());
      cout<<"   "<<bs1[i].getPartyId();
      for(int i=c;i<7;i++) cout<<" ";
      c=countChar(bs1[i].getPartyName());
      cout<<bs1[i].getPartyName();
      for(int i=c;i<30;i++) cout<<" ";
      c=countChar(bs1[i].getHeadName());
      cout<<bs1[i].getHeadName();
      for(int i=c;i<20;i++) cout<<" ";
      cout<<bs1[i].getMembers()<<"\n";
   }

   cout<<"\n\n   Press Any Key To Go Back";getch();
}
void ResetVotes(){
   funHeading("Reseting the Record in DataBase : ");
   cout<<"\n\n   1.Reset Voter's Record\n";
   cout<<"   2.Reset Party/Candidate's Record";
   cout<<"\n\n   Enter Your Choice : ";
   int ch;
   cin>>ch;
   char c;
   cout<<"\n   Are you sure to reset the Record (y/n) :";
   cin>>c;
   if(c=='y' || c=='Y'){
      if(ch == 1){
       getVoterId();
         if(voterId!=0){
            Voter vs1[voterId];
            for(int i=0;i<voterId;i++){
               vs1[i].getVoter(i);
               vs1[i].setPartyId(0);
               vs1[i].setPartyName("null");
            }
            remove("voter.txt");
            for(int i=0;i<voterId;i++){vs1[i].storeVoter();}

         }

      }
      if(ch==2){
         getCandidateId();
         if(candidateId!=0){
            Candidate cs1[candidateId];
            for(int i=0;i<candidateId;i++){
               cs1[i].getCandidate(i);
               cs1[i].setCandidateVotes(0);
               cs1[i].setSeats(0);
            }
            remove("candidates.txt");
            for(int i=0;i<candidateId;i++){cs1[i].storeCandidate();}
         }
      }



      cout<<"\n\n   Record has been reseted. Press any Key to Go Back";getch();
   }
   else return;
}

void funIntervalInput(Interval *b){
   Interval obj;
   obj.getIntervalInfo();
   int objpID = obj.getpId();
      int j = resultId-1;
      for(j = resultId-1;j>0;j--){
         int cmppId = b[j-1].getpId();
         if(objpID<cmppId){b[j] = b[j-1];}
         else{break;}
      }
      b[j] = obj;
}

void setResultRecord(){
   getResultId();
   Interval bs1[resultId+1];

   funHeading("Inserting New Result Record : \n");
   for(int i=0;i<resultId;i++){
      bs1[i].getInterval(i);
      //cout<<"\n   "<<bs1[i].low<<" - "<<bs1[i].high<<"     PartyId: "<<bs1[i].PID;
   }
   funIntervalInput(bs1);
   setResultId();
   remove("Record.txt");
   for(int i=0;i<resultId;i++){bs1[i].storeInterval();}
   cout<<"\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
   getch();
}

void showResult1(){
   redo:;
   funHeading("Showing OverAll Result");

   cout<<"\n   PartyName                     HeadName               Votes     Seats\n\n";
   getPartyIdNo();
   Party p1[partyId];
   getCandidateId();
   Candidate c1[candidateId];
   for(int j=0;j<partyId;j++){
      p1[j].getParty(j);
      p1[j].setSeats(0);
      p1[j].setVotes(0);
   }
   for(int i=0;i<candidateId;i++){
      c1[i].getCandidate(i);
      int pId = c1[i].getPartyId();

      int pseats = p1[pId-1].getSeats();
      pseats = pseats + c1[i].getSeats();
      p1[pId-1].setSeats(pseats);
      int pVotes = p1[pId-1].getVotes();
      pVotes = pVotes + c1[i].getCandidateVotes();
      p1[pId-1].setVotes(pVotes);

   }
   for(int j=0;j<partyId;j++){
      int c=0;
      c=countChar(p1[j].getPartyName());
      cout<<"   "<<p1[j].getPartyName();
      for(int k=c;k<30;k++) cout<<" ";
      c=countChar(p1[j].getHeadName());
      cout<<p1[j].getHeadName();
      for(int k=c;k<25;k++) cout<<" ";
      c=countDigits(p1[j].getVotes());
      cout<<p1[j].getVotes();
      for(int k=c;k<10;k++) cout<<" ";
      //c=countDigits(c1[i].getSeats());
      cout<<p1[j].getSeats();
      cout<<"\n";

   }



   /*for(int j=0;j<partyId;j++){
      p1[j].getParty(j);
      p1[j].setSeats(0);
      p1[j].setVotes(0);
      bool f = 0;
      for(int i=0;i<candidateId;i++){
         c1[i].getCandidate(i);
         if(c1[i].getPartyId() == p1[j].getPartyId()){

            f = 1;
            int pseats = p1[j].getSeats();
            pseats = pseats + c1[i].getSeats();
            p1[j].setSeats(pseats);
            int pVotes = p1[j].getVotes();
            pVotes = pVotes + c1[i].getCandidateVotes();
            p1[j].setVotes(pVotes);

         }
      }

      if(f == 1){
         int c=0;
         c=countChar(p1[j].getPartyName());
         cout<<"   "<<p1[j].getPartyName();
         for(int k=c;k<30;k++) cout<<" ";
         c=countChar(p1[j].getHeadName());
         cout<<p1[j].getHeadName();
         for(int k=c;k<25;k++) cout<<" ";
         c=countDigits(p1[j].getVotes());
         cout<<p1[j].getVotes();
         for(int k=c;k<10;k++) cout<<" ";
         //c=countDigits(c1[i].getSeats());
         cout<<p1[j].getSeats();
         cout<<"\n";
      }
   }
   */
   getch();
}
void showResult2(){
   redo:;
   funHeading("Showing result for a Specific State : ");
   getStateCount();
   State bs1[stateCount];
   cout<<endl<<"   S.No.  State\n\n";
   for(int i=0;i<stateCount;i++){
      bs1[i].getStates(i);
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++)
         cout<<" ";
      bs1[i].showStateInfo();
   }
   int sr;cout<<"\n   Choose Your State (S.No) : ";cin>>sr;
   if(sr<=0||sr>stateCount){cout<<"\n   Invalid Choice!";getch();goto redo;}

   redo2:;
   funHeading("Showing result for a Specific State : ");
   cout<<"\n\n   Selected State          :  "<<bs1[sr-1].getstateName2()<<" ("<<bs1[sr-1].getSeats()<<")"<<"\n\n";


   cout<<"\n   PartyName                     HeadName               Votes     Seats\n\n";
   getPartyIdNo();
   Party p1[partyId];
   getCandidateId();
   Candidate c1[candidateId];

   for(int j=0;j<partyId;j++){
      p1[j].getParty(j);
      p1[j].setSeats(0);
      p1[j].setVotes(0);
      bool f = 0;
      for(int i=0;i<candidateId;i++){
         c1[i].getCandidate(i);
         if(c1[i].getPartyId() == p1[j].getPartyId()){
            if(c1[i].getstateId()==bs1[sr-1].getstateId()){
               f = 1;
               int pseats = p1[j].getSeats();
               pseats = pseats + c1[i].getSeats();
               p1[j].setSeats(pseats);
               int pVotes = p1[j].getVotes();
               pVotes = pVotes + c1[i].getCandidateVotes();
               p1[j].setVotes(pVotes);
            }
         }
      }

      if(f == 1){
         int c=0;
         c=countChar(p1[j].getPartyName());
         cout<<"   "<<p1[j].getPartyName();
         for(int k=c;k<30;k++) cout<<" ";
         c=countChar(p1[j].getHeadName());
         cout<<p1[j].getHeadName();
         for(int k=c;k<25;k++) cout<<" ";
         c=countDigits(p1[j].getVotes());
         cout<<p1[j].getVotes();
         for(int k=c;k<10;k++) cout<<" ";
         //c=countDigits(c1[i].getSeats());
         cout<<p1[j].getSeats();
         cout<<"\n";
      }
   }
   getch();
}
void showResult3(){
   redo:;
   funHeading("Showing result for a Specific District : ");
   getStateCount();
   State bs1[stateCount];
   cout<<endl<<"   S.No.  State\n\n";
   for(int i=0;i<stateCount;i++){
      bs1[i].getStates(i);
      cout<<"   "<<i+1<<".";
      int j = countDigits(i+1);
      for(int k = j;k<8;k++)
         cout<<" ";
      bs1[i].showStateInfo();
   }
   int sr;cout<<"\n   Choose Your State (S.No) : ";cin>>sr;
   if(sr<=0||sr>stateCount){cout<<"\n   Invalid Choice!";getch();goto redo;}

   redo2:;
   funHeading("Showing result for a Specific District : ");
   cout<<"\n\n   Select Your State          :  "<<bs1[sr-1].getstateName2()<<"\n\n";
   getCityCount();
   City cs1[cityCount];
   cout<<endl<<"   S.No.  City\n\n";
   for(int i=0;i<cityCount;i++){
      cs1[i].getCity(i);
      if(cs1[i].getstateId()==bs1[sr-1].getstateId()){
         cout<<"   "<<i+1<<".";
         int j = countDigits(i+1);
         for(int k = j;k<8;k++)
            cout<<" ";
         cs1[i].showCityInfo();

      }
   }
   int sr2;cout<<"\n   Choose Your City (S.No) : ";cin>>sr2;
   if(sr<=0||sr>cityCount){cout<<"\n   Invalid Choice!";getch();goto redo2;}

   funHeading("Showing result for a Specific District : ");
   cout<<"\n\n   Selected State       :  "<<bs1[sr-1].getstateName2();
   cout<<"\n\n   Selected District    :  "<<cs1[sr2-1].getcityName2()<<"\n\n";

   cout<<"\n   PartyName                     HeadName                 CandidateName          Votes     Seats\n\n";
   getCandidateId();
   Candidate c1[candidateId];
   for(int i=0;i<candidateId;i++){
      c1[i].getCandidate(i);
      if(c1[i].getcityId()==cs1[sr2-1].getcityId()){
         int c=0;
         c=countChar(c1[i].getPartyName());
         cout<<"   "<<c1[i].getPartyName();
         for(int i=c;i<30;i++) cout<<" ";
         c=countChar(c1[i].getHeadName());
         cout<<c1[i].getHeadName();
         for(int i=c;i<25;i++) cout<<" ";
         c=countChar(c1[i].getCandidateName());
         cout<<c1[i].getCandidateName();
         for(int i=c;i<25;i++) cout<<" ";
         c=countDigits(c1[i].getCandidateVotes());
         cout<<c1[i].getCandidateVotes();
         for(int i=c;i<10;i++) cout<<" ";
         //c=countDigits(c1[i].getSeats());
         cout<<c1[i].getSeats();
         cout<<"\n";
      }
   }
   getch();
}
void showResult4(){
   getResultId();
   Interval bs1[resultId+1];
   ITNode *root = NULL;
   funHeading("List of Record For Specific Interval : \n");
   for(int i=0;i<resultId;i++){
      bs1[i].getInterval(i);
      root = insert(root,bs1[i]);
   }
   int low,high;
   cout<<"\n   Low : ";cin>>low;
   cout<<"\n   High : ";cin>>high;
   Interval x = Interval(low,high,0);
   cout<<"\n   Record for Interval [" << x.low <<","<<x.high <<"] : \n\n";
   cout<<"   Interval          ID     PartyName                     HeadName\n\n";
   overlapSearchAllSorted(root,x);
   getch();
}


void showResults(){
   redo:;
   int ch = choiceAdmin(9);
   switch (ch){
   case 0:
      return;
   case 1:
      showResult1();
      goto redo;
   case 2:
      showResult2();
      goto redo;
   case 3:
      showResult3();
      goto redo;
   case 4:
      showResult4();
      goto redo;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto redo;
   }
}

int main(){
   //setCityLeadCandidate();
   funFrontPage();
   int ch,Id=0;

   choice:;
   ch = choiceAdmin(0);
   switch (ch-1){
   case 0:
      Id = VoterLogin();
      if(Id!=0){viewVoterInfo(Id);}
      goto choice;
   case 1:
      Id = CandidateLogin();
      if(Id!=0){viewCandidateInfo(Id);}
      goto choice;
   case 2:
      Id = partyLogin();
      if(Id!=0){viewPartyInfo(Id);}
      goto choice;
   case 3:
      goto choice3;
   case 4:
      showResults();
      goto choice;
   case 5:
      goto choice5;
   case 6:
      goto Exit;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto choice;
   }

   choice3:;
   ch = choiceAdmin(5);
   switch (ch){
   case 1:
      Id = insertNewVoter();
      if(Id!=0){viewVoterInfo(Id);}
      goto choice;
   case 2:
      Id = insertNewCandidate();
      if(Id!=0){viewCandidateInfo(Id);}
      goto choice;
   case 3:
      Id = insertNewParty();
      if(Id!=0){viewPartyInfo(Id);}
      goto choice;
   case 0:
      goto choice;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto choice;
   }

   //choice4:;
   //goto Exit;

   choice5:;
   ch = choiceAdmin(2);
   switch (ch){
      case 1:
         goto choice5a;
      case 2:
         goto choice5b;
      case 3:
         goto choice5c;
      case 4:
         setResultRecord();
         goto choice5;
      case 0:
         goto choice;
      default:
         cout<<"\n   Enter the Correct Choice!";
         getch();
         goto choice5;

   }

   choice5a:;
   ch = choiceAdmin(3);
   switch (ch){
   case 1:
      insertNewState();
      goto choice5a;
   case 2:
      viewStateRecord();
      goto choice5a;
   case 3:
      deleteState();
      goto choice5a;
   case 4:
      updateState();
      goto choice5a;
   case 0:
      goto choice5;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto choice5a;
   }

   choice5b:;
   ch = choiceAdmin(4);
   switch (ch){
   case 1:
      insertNewCity();
      goto choice5b;
   case 2:
      viewCityRecord();
      goto choice5b;
   case 3:
      deleteCity();
      goto choice5b;
   case 4:
      updateCity();
      goto choice5b;
   case 0:
      goto choice5;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto choice5b;
   }

   choice5c:;
   ch = choiceAdmin(1);
   switch (ch){
   case 1:
      viewVoterRecord();
      goto choice5c;
   case 2:
      viewCandidateRecord();
      goto choice5c;
   case 3:
      viewPartyRecord();
      goto choice5c;
   case 4:
      ResetVotes();
      goto choice5c;
   case 0:
      goto choice5;
   default:
      cout<<"\n   Enter the Correct Choice!";
      getch();
      goto choice5c;
   }


   Exit:;
   return 0;
}


