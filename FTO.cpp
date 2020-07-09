#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
#include<sstream>

using namespace std;

char tournament_name[20],getpassgb[10],getusergb[10];

std::string int2str(int x)
{
    std::stringstream ss;
    ss << x;
    return ss.str();
}

class goals
{
	public: 
		char playername[10];
		int goal;
};
class team
{
	public: 
		char tname[10],tarea[10],tcontact[10],capt[10];
}t[20];
class user
{
	public:
	char name[10],area[10],contact[11],username[10],upassword[10];
}u[11];
 void search_user()
{

	system("cls");
	int i,flag=0;
	fstream file;
		char user[10],pass[10],name[10],area[10],contact[11],gpass[10],guser[10];
	file.open("users.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file ";
		return;
	}
	cout<<"\nenter the username: ";
	cin>>guser;
	cout<<"\nenter the user password:  ";
	cin>>gpass;
	i=0;
	while(!file.eof())
	{	
		
		file.getline(user,10,'|');
		file.getline(pass,10,'|');
		file.getline(name,10,'|');
		file.getline(area,10,'|');
		file.getline(contact,10,'\n');
		i++;
		
		if(strcmp(user,guser)==0 && strcmp(pass,gpass)==0)
		{
			flag=1;
			cout<<"\nNO OF RECORDS CHECKED:"<<--i;
			cout<<"\nUSER WITH USERNAME:"<<user<<" AND PASSWORD:"<<pass<<"\n";
			cout<<"NAME\t\tAREA\t\tCONTACT\t\tUSERNAME\tPASSWORD\n";
			
			cout<<"----\t\t----\t\t-------\t\t--------\t--------\n";	
			cout<<name<<"\t\t"<<area<<"\t\t"<<contact<<"\t\t"<<user<<"\t\t"<<pass<<"\n";
			getch();
			
		}
	}
	if(flag==0)
	{
		cout<<"\nRECORD NOT FOUND\n";
		cout<<"\nNO OF RECORDS CHECKED:"<<--i;
		getch();
	}
}
 
 void search_team()
{
	int i,flag=0;
	
	char gcapt[10],gname[10],capt[10],name[10],area[10],contact[10];
	fstream file;
	file.open("team.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file in input mode";
		exit(1);
	}
	cout<<"\nENTER THE DETAILS\n1.TEAM NAME :";
	cin>>gname;
	cout<<"\n2.CAPTAIN'S NAME':  ";
	cin>>gcapt;
	i=0;
	while(!file.eof())
	{
		
		file.getline(name,10,'|');
		file.getline(area,10,'|');
		file.getline(contact,10,'|');
		file.getline(capt,10,'\n');
		i++;
		if(strcmp(name,gname)==0 && strcmp(capt,gcapt)==0)
		{
			flag=1;
			cout<<"\nTHE TEAM "<<gname<<"'S RECORD DETAILS ARE\n";
			cout<<"\n1.TEAM'S NAME:    "<<name;
			cout<<"\n2.AREA:           "<<area;
			cout<<"\n3.CONTACT:        "<<contact;
			cout<<"\n4.CAPTAIN'S NAME: "<<capt;
			cout<<"\n NO. OF RECORDS SEARCHED:"<<i;
			getch();
			
		}
		
	}
	file.close();
	if (flag==0)
	{	
		cout<<"\nTEAM NOT FOUND\n";
		cout<<"\n NO. OF RECORDS SEARCHED:"<<--i;
		getch();
	}

}
 
 void user_sort()
{	
	fstream file;
	user p[20];
	file.open("users.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file ";
		return;
	}
	int w=0;
	while(!file.eof())
	{	
		
		file.getline(p[w].username,10,'|');
		file.getline(p[w].upassword,10,'|');
		file.getline(p[w].name,10,'|');
		file.getline(p[w].area,10,'|');
		file.getline(p[w].contact,10,'\n');
		w++;
		}
	w--;
	
	user temp;
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<w-i-1;j++)
		{
			if(strcmp(p[j].name,p[j+1].name)>0)
			{
				temp = p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	file.close();
	file.open("users.txt",ios::out);
	for(int j=0;j<w;j++)
	{
		file<<p[j].username<<"|"<<p[j].upassword<<"|"<<p[j].name<<"|"<<p[j].area<<"|"<<p[j].contact<<"\n";
	}
	file.close();
	return;
	
}
 
int timer(char team1[],char team2[]) 
{ 
    fstream file;
    file.open("scores.txt",ios::app);
    if(!file)
	{
		cout<<"\nunable to open the file ";
		return 5;
	}
	
	int a=0,b=0,j=0,i=0;
	int mm[10],hh[10],ss[10],m[10],h[10],s[10];
	char pname1[10][10],pname2[10][10];

	time_t start, finish;
	long product;
	int min=0,hr=0,sec=0;
	
	while(true)
	{
		sec++;
		sleep(1);
		system("cls");
		if(sec==60){
			min++;
			sec=0;
		}
		if(min==60){
			hr++;
			min=0;
		}
		    
	    system("cls"); 
	  
	    cout << setfill(' ') << setw(55) << "         TIMER         \n"; 
	    cout << setfill(' ') << setw(55) << " --------------------------\n"; 
	    cout << setfill(' ') << setw(29); 
	    cout << "| " << setfill('0') << setw(2) << hr << " hrs | "; 
	    cout << setfill('0') << setw(2) << min << " min | "; 
	    cout << setfill('0') << setw(2) << sec << " sec |" << endl; 
	    cout << setfill(' ') << setw(55) << " --------------------------\n"; 
	    
		cout<<" >to PAUSE press p\n >to STOP press x"<<endl;
	    
	    cout<<"\t\t\t\t"<<team1<<"\t\t"<<team2<<"\n\n";
		cout<<"\t\t\t\t"<<a<<"\t\t"<<b<<endl;
	    cout<<"\n\n";
	    for(int k=0;k<j;k++)
				cout<<"\t\t\t"<<k+1<<"."<<pname1[k]<<"("<<h[k]<<":"<<m[k]<<":"<<s[k]<<")\t\n";
			
			for(int n=0;n<i;n++)
				cout<<"\t\t\t\t\t\t"<<n+1<<"."<<pname2[n]<<"("<<hh[n]<<":"<<mm[n]<<":"<<ss[n]<<")\t\n";
			if (kbhit())
			{
	
			    switch(getch())
			    {
				    case 'A' : case 'a' :
								    	cout<<"players name:";
								    	cin>>pname1[j];
								    	m[j]=min;
								    	h[j]=hr;
								    	s[j]=sec;
									      ++a;++j;
									      break;
			
				    case 'B' : case 'b' :
								    	cout<<"players name:";
								    	cin>>pname2[i];
								    	mm[i]=min;
								    	hh[i]=hr;
								    	ss[i]=sec;
								  	    ++b;++i;
									    break;
					       
					case 'p':case 'P':
										cout<<"\t\t\t\t GAME PAUSED";
										getche();break;
										
					case 'x':case 'X':	
										//system("cls");
										fstream file1;
										goals p[30];
										char user[10],upass[10];
										file1.open("goal.txt",ios::in);
										
										if(!file1)
										{
											cout<<"unable to open goal file\n";
											getch();
											return 5;
										}
										int w=0;
										char go[2];
										string cgo;
										std::string str;
										while(!file1.eof())
										{	
											
											file1.getline(p[w].playername,10,'|');
											file1.getline(go,2,'\n');
											p[w].goal=atoi(go);
											w++;
										}
										w--;int z;
										z=w;
										int flag=0;	
									 
											for(int m=0;m<j;m++){
												for(int y=0;y<w;y++)
												{	
													if(strcmp(pname1[m],p[y].playername)==0)
													{
														p[y].goal++;
														flag =1;
													}
												}
												if(flag ==0)
												{
													strcpy(p[w].playername,pname1[m]);
													p[w].goal=1;
													w++;
												}
												flag=0;
											}flag=0;
										for(int n=0;n<i;n++){
												for(int q=0;q<w;q++)
												{
													if(strcmp(pname2[n],p[q].playername)==0){
													
														p[q].goal++;
														flag=1;
													}
												}
												if(flag==0)
												{	strcpy(p[w].playername,pname2[n]);
													p[w].goal=1;
													w++;
												}
												flag=0;
										}
										file1.close();
										file1.open("goal.txt",ios::out);
										if(!file)
										{
											cout<<"error opeing filr\n";
											getch();return 4;
										}
										ostringstream str1;
									
										getch();
										for(int r=0;r<w;r++)
										{	
											 str.clear();
											
											str = int2str(p[r].goal);
											cout.flush();
											file1<<p[r].playername<<"|"<<str<<"\n";
											
										}
										
										file1.close();
										
										cout<<"\n\n\t\t!!!!!!!!!!!!!!FINAL SCORE!!!!!!!!!!!!!!!\n\n"<<"\t\t\t\t"<<a<<":"<<b;
										if(a>b){
										
											cout<<"\n\n\t\t\tTEAM "<<team1<<" wins by "<<a-b<<" goals";
											file<<team1<<"|"<<a<<"|"<<team2<<"|"<<b<<"|"<<a-b<<"\n";
											getch();file.close();
											return 1;
							   			}
				   		
								   		else if(a<b)
								   		{
								   			file<<team2<<"|"<<b<<"|"<<team1<<"|"<<a<<"|"<<b-a<<"\n";
								   			cout<<"\n\n\t\t\tTEAM "<<team2<<" wins by "<<b-a<<" goals";
											getch();file.close();
											return 2;
										}
									   else
										{	char c;
										   	cout<<"\n\n\t\t\tITS A DRAW BETWEEN THE team \n\n\n";
											getch();file.close();
											return 3;
									   }
			   }
			   
		}
	        
  


	}
	return 4;
}


void add_user()
{
	user u;
	system("cls");
	cout<<"\nENTER NEW USER DETAILS\n";
	cout<<"1.NAME: ";
	cin>>u.name;
	cout<<"\n2.AREA: ";
	cin>>u.area;
	cout<<" \n(only nos allowed)\n";
	cout<<"\n3.CONTACT: ";
	 for(int i=0;i<9;)
    {
        char a=getch();
        if(a>='0'&&a<='9')
        {
            u.contact[i]=a;
            cout<<a;
            ++i;
        }

        
    }
	
	
	cout<<"\n\n4.USER NAME: ";
	cin>>u.username;
	cout<<"\n5.PASSWORD: ";
	cin>>u.upassword;
	fstream file;
	
	file.open("users.txt",ios::app);
	if(!file)
	{
		cout<<"unable to open the file\n";
		return;
	}
	file<<u.username<<"|"<<u.upassword<<"|"<<u.name<<"|"<<u.area<<"|"<<u.contact<<"\n";
	file.close();
	user_sort();
	return;
}

bool user_login()
{
	fstream file1;
	char user[10],pass[10],name[10],area[10],contact[11];
	int i;
	system("cls");
	cout<<"\n\t\t\tUSER NAME: ";
	cin>>getusergb;
	cout<<"\n\t\t\tPASSWORD: ";
	 for(i=0;;)
    {
        char a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            getpassgb[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r'){
            getpassgb[i]='\0';
            break;
        }
    }


	file1.open("users.txt",ios::in);
	if(!file1)
	{
		cout<<"\ncannot open file\n";
		return 0;
	}
	
	while(!file1.eof())
	{
		file1.getline(user,10,'|');
		file1.getline(pass,10,'|');
		file1.getline(name,10,'|');
		file1.getline(area,10,'|');
		file1.getline(contact,10,'\n');
		if(strcmp(user,getusergb)==0 && strcmp(pass,getpassgb)==0)
		{
			system("cls");
			cout<<"\n\n!!!!!!!!!!LOGIN SUCCESSFUL!!!!!!!!!!";
				file1.close();
			getch();
			return true;	
			
		}
	
	}
	file1.close();
	cout<<"\n\n######### USER NOT FOUND ##########\n\n";
	return false;
}

void fixt()
{ 
	system("cls");
	
	int i,j=0;
	team s[20];
	fstream file,file1;
	file.open("team.txt",ios::in);
	file1.open("fixtures.txt",ios::out);
	if(!file || !file1)
	{
		cout<<"\nunable to open the file in input mode";
		return;
	}
	i=0;
	while(!file.eof())
	{
		
		file.getline(s[i].tname,10,'|');
		file.getline(s[i].tarea,10,'|');
		file.getline(s[i].tcontact,10,'|');
		file.getline(s[i].capt,10,'\n');
		i++;
	}
	i--;
	
	j=0;
	int c=0,k=1;
	int y=1;
	if(i==1)
	{
	//cout<<s[i].tname<<" is the winner of the tournament "<<tournament_name;
		return;
	}
	else if(i%2==0){
		cout<<"\n\t\tFIXTURES";
	
		while(j<=i&&k<=i){
		
			cout<<"\n\n\t\t"<<++c<<". "<<s[j].tname<<" vs "<<s[k].tname<<endl;
			file1<<y++<<"|"<<s[j].tname<<"|"<<s[k].tname<<"\n";
			j+=2;k+=2;
		}getch();
		return ;
	}
	else{
		cout<<"\n\t\tFIXTURES";
	
		while(j<=i&&k<=(i-1)){
			
			file1<<y++<<"|"<<s[j].tname<<"|"<<s[k].tname<<"\n";
			cout<<"\n\n\t\t"<<++c<<". "<<s[j].tname<<" vs "<<s[k].tname<<endl;
			
			j+=2;k+=2;
		}
		cout<<"\n\t\tTeam : "<<s[j].tname<<" gets a BY\n";
		getch();
		return ;
	}
	file.close();
	file1.close();
	return;
}

void delete_user(char cuser[],char upass[])
{
	
	system("cls");
	int i,j;
	fstream file2;
	user p[20];
	
	file2.open("users.txt",ios::in);
	i=0;
	while(!file2.eof())
	{	
		file2.getline(p[i].username,10,'|');
		file2.getline(p[i].upassword,10,'|');
		file2.getline(p[i].name,10,'|');
		file2.getline(p[i].area,10,'|');
		file2.getline(p[i].contact,10,'\n');
		i++;
		}
	i--;
	int flag=-1;

	for(j=0;j<=i;j++)
	{
		if(strcmp(p[j].username,cuser)==0 && strcmp(p[j].upassword,upass)==0)
		{
			flag=j;
		}
	}
	system("cls");
	if(flag==-1)
	{
		cout<<"\t\terror..!\n\t\tUSER NOT FOUND \n";
		return;
	}

	if(flag==i)
	{
		i--;
		cout<<"USER DELETED !!!\n";
		return;
	}
	
	for(j=flag;j<=i;j++)
	{
		p[j]=p[j+1];
	}
	i--;
	
	cout<<"\n USER DELETED !!!\n";
	file2.close();
	
	file2.open("users.txt",ios::out);
	if(!file2)
	{
		cout<<"\nunable to open the file ";
		return;
	}
	
	for(j=0;j<i;j++)
	{
			file2<<p[j].username<<"|"<<p[j].upassword<<"|"<<p[j].name<<"|"<<p[j].area<<"|"<<p[j].contact<<"\n";
	}
	
	file2.close();
	getch();
	user_sort();
	return;
	
}
void modify_user()
{
	system("cls");
	int i,j;
	fstream file;
	user p[20];
	char user[10],upass[10];
	file.open("users.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file ";
		return;
	}
	cout<<"\nenter the username: ";
	cin>>user;
	cout<<"\nenter the user password:  ";
	cin>>upass;
	i=0;
	while(!file.eof())
	{	
		
		file.getline(p[i].username,10,'|');
		file.getline(p[i].upassword,10,'|');
		file.getline(p[i].name,10,'|');
		file.getline(p[i].area,10,'|');
		file.getline(p[i].contact,10,'\n');
		i++;
		}
	i--;
	int flag=0;	
	for(j=0;j<=i;j++)
	{
		if(strcmp(p[j].username,user)==0 && strcmp(p[j].upassword,upass)==0)
		{
			flag=1;
			cout<<"\nthe old user record with username:"<<user<<" and password:"<<upass<<" is\n";
			cout<<"NAME\t\tAREA\t\tCONTACT\t\tUSERNAME\tPASSWORD\n";
			cout<<p[j].name<<"\t\t"<<p[j].area<<"\t\t"<<p[j].contact<<"\t\t"<<p[j].username<<"\t\t"<<p[j].upassword<<"\n";
		
			cout<<"\nenter the new values\n";
			cout<<"\nENTER NEW TEAM DETAILS\n";
			cout<<"1.NAME: ";
			cin>>p[j].name;
			cout<<"\n2.AREA: ";
			cin>>p[j].area;
			cout<<"\n(nos only)\n3.CONTACT: ";
			 for(int i=0;i<9;)
		    {
		        char a=getch();
		        if(a>='0'&&a<='9')
		        {
		            p[j].contact[i]=a;
		            cout<<a;
		            ++i;
		        }   
		    }
			
			cout<<"\n4.USER NAME: ";
			cin>>p[j].username;
			cout<<"\n5.PASSWORD: ";
			cin>>p[j].upassword;
			
			break;
		}
	}
	if(flag==0|| j==i)
	{	system("cls");
		cout<<"\nUSER HAVING USERNAME AS :" <<user<<" AND PASSWOED: "<<upass<<  " DOES NOT EXIST\n ";
				getch();
		return;
	}
	file.close();

	file.open("users.txt",ios::out);
	if(!file)
	{
		cout<<"\nunable to open the file in output mode";
		getch();
		return;
	}

	for(j=0;j<i;j++)
	{
		
		file<<p[j].username<<"|"<<p[j].upassword<<"|"<<p[j].name<<"|"<<p[j].area<<"|"<<p[j].contact<<"\n";
		
	}
	file.close();
	user_sort();
	
}

void delete_team(char name[], char capt[])
{
	
	int i,j;
	fstream file2;
	team t[50];
	
	file2.open("team.txt",ios::in);
	if(!file2)
	{
		cout<<"\n cannot open the file";
		return;
	}
	i=0;
	while(!file2.eof())
	{
		
		file2.getline(t[i].tname,10,'|');
		file2.getline(t[i].tarea,10,'|');
		file2.getline(t[i].tcontact,10,'|');
		file2.getline(t[i].capt,10,'\n');
		i++;
		}
	i--;
	int flag=-1;
	cout<<"\nCHECKED: "<<i<<" TEAMS\n"; getch();
	for(j=0;j<=i;j++)
	{
		if(strcmp(t[j].tname,name)==0 && strcmp(t[j].capt,capt)==0)
		{
			flag=j;
		}
	}
	
	if(flag==-1)
	{
		cout<<"\n\t\tERROR..!\n\t\tTEAM NOT FOUND \n";
		return;
	}

	if(flag==i)
	{
		i--;
		cout<<"\n\t\tTEAM DELETED!!!\n";
		return;
	}
	
	for(j=flag;j<=i;j++)
	{
		t[j]=t[j+1];
	}
	i--;
	cout<<"\n\t\tTEAM DELETED!\n";
	file2.close();
	
	file2.open("team.txt",ios::out);
	if(!file2)
	{
		cout<<"\n cannot open the file";
		return;
	}
	for(j=0;j<i;j++)
	{
			file2<<t[j].tname<<"|"<<t[j].tarea<<"|"<<t[j].tcontact<<"|"<<t[j].capt<<"\n";
	}
	file2.close();
	getch();
	//team_sort();
	return;

}

void modify_team()
{
	system("cls");

	char gcapt[10],gname[10],capt[10],name[10],area[10],contact[10];

	int i;
	int j;
	team s[10];
	fstream file;
	file.open("team.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file in input mode";
		exit(1);
	}
	cout<<"\nENTER THE DETAILS\n1.TEAM NAME :";
	cin>>gname;
	cout<<"\n2.CAPTAIN'S NAME':  ";
	cin>>gcapt;
	i=0;
	while(!file.eof())
	{
		
		file.getline(s[i].tname,10,'|');
		file.getline(s[i].tarea,10,'|');
		file.getline(s[i].tcontact,10,'|');
		file.getline(s[i].capt,10,'\n');
		i++;
	}
	i--;
	int flag=0;
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].tname,gname)==0 && strcmp(s[j].capt,gcapt)==0)
		{
			flag=1;
			cout<<"\nTHE TEAM "<<gname<<"'s OLD RECORD DETAILS ARE\n";
			cout<<"\n1.TEAM'S NAME:    "<<s[j].tname;
			cout<<"\n2.AREA:           "<<s[j].tarea;
			cout<<"\n3.CONTACT:        "<<s[j].tcontact;
			cout<<"\n4.CAPTAIN'S NAME: "<<s[j].capt;

			cout<<"\nenter the new values\n";
			cout<<"\nENTER NEW TEAM DETAILS\n";
			cout<<"1.TEAM NAME:        ";
			cin>>s[j].tname;
			cout<<"\n2.AREA:           ";
			cin>>s[j].tarea; 
			cout<<"\n3.CONTACT:        ";
			 for(int i=0;i<9;)
		    {
		        char a=getch();
		        if(a>='0'&&a<='9')
		        {
		            s[j].tcontact[i]=a;
		            cout<<a;
		            ++i;
		        }   
		    }
			
			cout<<"\n4.CAPTAIN'S NAME: ";
			cin>>s[j].capt;
			break;
		}
	}
	if(flag==0)
	{	system("cls");
			cout<<"\nTHE TEAM " <<gname<<" WITH CAPTAIN "<<gcapt<<  " DOES NOT EXIST\n ";
		getch();
		return;
	}
	
	file.close();

	file.open("team.txt",ios::out);
	if(!file)
	{
		cout<<"\nunable to open the file in output mode";
		getch();
		return;
	}

	for(j=0;j<i;j++)
	{
		file<<s[j].tname<<"|"<<s[j].tarea<<"|"<<s[j].tcontact<<"|"<<s[j].capt<<"\n";
	
	}
	getch();
	file.close();
//	team_sort();
	return;
}


void add_team()
{
	team t;
	system("cls");
	cout<<"\nENTER NEW TEAM DETAILS\n";
	cout<<"1.TEAM NAME:		   ";
	cin>>t.tname;
	cout<<"\n2.AREA: 		   ";
	cin>>t.tarea;
	cout<<" \n(only nos allowed)\n";
	cout<<"\n3.CONTACT: ";
	 for(int i=0;i<9;)
    {
        char a=getch();
        if(a>='0'&&a<='9')
        {
            t.tcontact[i]=a;
            cout<<a;
            ++i;
        }   
    }
	cout<<"\n4.CAPTAIN'S NAME: ";
	cin>>t.capt;
	fstream file;
	
	file.open("team.txt",ios::app);
	if(!file)
	{
		cout<<"unable to open the file\n";
		return;
	}
	file<<t.tname<<"|"<<t.tarea<<"|"<<t.tcontact<<"|"<<t.capt<<"\n";
	file.close();
	//team_sort();
	return;
}
void disp_teams()
{
	system("cls");
	//team_sort();
	char capt[10],name[10],area[10],contact[10];
	fstream file;
	file.open("team.txt",ios::in);
	int i;
	int j;
	i=0;
	cout<<"\nTEAM NAME\tAREA\t\tCONTACT\t\t\tCAPTAIN\n";
	cout<<"*********\t****\t\t*******\t\t\t*******\n";
	
	while(!file.eof())
	{
		
		file.getline(name,10,'|');
		file.getline(area,10,'|');
		file.getline(contact,10,'|');
		file.getline(capt,10,'\n');
		i++;
		cout<<name<<"\t\t"<<area<<"\t\t"<<contact<<"\t\t"<<capt<<"\n";
	}
	i--;
	cout<<"\nTOTAL TEAMS:"<<i;
    getch();
    return;
}
void disp_user(){
	
	fstream file1;
	char user[10],pass[10],getuser[10],getpass[10],name[10],area[10],contact[11];
	int i=0;
	system("cls");
	
	file1.open("users.txt",ios::in);
	if(!file1)
	{
		cout<<"\ncannot open file\n";
		return ;
	}
	cout<<"\nNAME\t\tAREA\t\tCONTACT\t\t\tUSERNAME\tPASSWORD\n";
	cout<<"****\t\t****\t\t*******\t\t\t********\t********\n";
	
	while(!file1.eof())
	{
		i++;
		file1.getline(getuser,10,'|');
		file1.getline(getpass,10,'|');
		file1.getline(name,10,'|');
		file1.getline(area,10,'|');
		file1.getline(contact,10,'\n');
		cout<<name<<"\t\t"<<area<<"\t\t"<<contact<<"\t\t"<<getuser<<"\t\t"<<getpass<<"\n";
		
	}
	i--;
	cout<<"\nTOTAL USERS: "<<i;
	file1.close();
	getch();
	return;
}

void admin_login()
{
	char user[10],pass[10],capt[10],tname[10],team1[10],team2[10],duser[10],upass[10];
	char ul;
		system("cls");
	cout<<"\n\n\n\t\t\t1.USER NAME: ";
	cin>>user;
	cout<<"\n\t\t\t2.PASSWORD:  ";
	
	 for(int i=0;;)
    {
        char a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
	bool cha=false;
	int c;
	if((strcmp(user,"admin")==0)&&(strcmp(pass,"1234")==0))
		{
			cout<<"\n\t\t>>>>>LOGIN SUCCESSFUL<<<<<";
			system("cls");
			while(!cha){
			system("cls");
			//system("color A1");
			cout<<"\n\t1.ADD TEAMS \n\t2.DELETE TEAM\n\t3.MODIFY TEAM\n\t";
			cout<<"4.DISPLAY TEAMS\n\t5.DISPLAY USERS\n\t6.DELETE USER\n\t7.MODIFY USER\n\t8.FIXTURES FOR THE TOURNAMENT\n\t9.FOOTBALL SCORE MANAGER\n\t0.BACK\n";
			cin>>c;
			switch(c)
			{	
				case 0: cha=true;break;
			
				case 1: add_team();break;
				
				case 2: cout<<"\nENTER DETAILS\n1.TEAM NAME: ";
						cin>>tname;
						cout<<"\n2.CAPTAIN NAME: ";
						cin>>capt;
						delete_team(tname,capt); break;
				
				case 3: modify_team();break;
				
				case 4: disp_teams();break;
				
				case 5: disp_user();break;
				
				case 6: cout<<"\nenter the username: ";
						cin>>duser;
						cout<<"\nenter the user password:  ";
						cin>>upass;
						
						delete_user(duser,upass);break;
				case 7: modify_user();break;
				case 8: fixt();break;
				
				case 9: cout<<"\nENTER THE TWO TEAMS\nTEAM 1 :";
						cin>>team1;
						cout<<"\nTEAM 2:";
						cin>>team2;
						ul=timer(team1,team2);
						break;
						
				default: cout<<"\nENTER A VALID CHOICE\n";			}		
			}		
	}
	else
		cout<<"\n\n\n\t\t\t>>>>>LOGIN FAILED<<<<<\n\n\t\t\t>>>>WRONG CREDENTIALS<<<<\n";
		getch();
		return;
}

void hscorer()
{
	
	fstream file1;
	int w=0;
	char go[2];
	file1.open("goal.txt",ios::in);
	if(!file1)
	{
		cout<<"cannot open file";
		return;
	}
	goals p[20];
	while(!file1.eof())
	{	
		file1.getline(p[w].playername,10,'|');
		file1.getline(go,2,'\n');
		p[w].goal=atoi(go);
		w++;
	}
	w--;									
	 goals temp;
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<w-i-1;j++)
		{
			
			if(p[j].goal < p[j+1].goal)
			{
				temp = p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	cout<<"\n\n\t\tTHE HIGHEST SCORER AWARD GOES TO: "<<endl;
	for(int i=0;i<3;i++)
		cout<<"\t\t"<<i+1<<". "<<p[i].playername<<"("<<p[i].goal<<")"<<endl;
	getch(); 	
	return;
}

void start_tournament()
{	
	char var;
	ofstream fcopy;
	ifstream fteam;
	fcopy.open("init_teams.txt",ios::out);
	fteam.open("team.txt",ios::in);
	if(!fcopy||!fteam)
	{
		cout<<"error opening files";
		return;
	}
		
	char capt[10],name[10],area[10],contact[10],no[5];
	while(!fteam.eof())
	{
		//fteam.getline(no,2,'|');
		fteam.getline(name,10,'|');
		fteam.getline(area,10,'|');
		fteam.getline(contact,10,'|');
		fteam.getline(capt,10,'\n');
		
		fcopy<<name<<"|"<<area<<"|"<<contact<<"|"<<capt<<"\n";
	}

	fteam.close();
	fcopy.close();
	cout<<"\nfile copied successfully\n";
	getch();
	//system("cls");
	cout<<"ENTER TOURNAMENT'S NAME: ";
	cin>>tournament_name;
	
	fstream file;
	fixt();
	//system("cls");
	int i;
	char name1[10],name2[10],lcapt1[10],lcapt2[10],tname1[10],tname2[10];
	int k=0;
	int ch;
	int q=0;
	cout<<"\nTOURNAMENT: ";
	cout<<tournament_name;
	cout<<"\nFIXTURES FOR LEVEL:"<<q++;	
			getch();
		while(k>=0){
				k=0;
				fixt();
				file.open("fixtures.txt",ios::in);
				if(!file)
				{
					cout<<"cannot open the file";
					return;
				}
				while(!file.eof())
				{	
					k++;
					file.getline(no,5,'|');
					file.getline(name1,10,'|');
					file.getline(name2,10,'\n');
				}
				k--;
				//cout<<"k="<<k;
				getch();
				file.close();
				file.open("fixtures.txt",ios::in);
				
				//cout<<"after inner fixt";getch();
				i=k;
			while(i>=1)
			{	
				file.getline(no,5,'|');
				file.getline(name1,10,'|');
				file.getline(name2,10,'\n');
				//cout<<"i="<<i<<" k="<<k;getch();
				cout<<"\nMATCH NO. "<<no<<":"<<name1<<" vs "<<name2<<" WILL START\n";
				system("pause");
				ch=timer(name1,name2);
				if(ch==1){
				
					cout<<"\n\nENTER LOOSING TEAM "<<name2<<" CAPTAIN'S NAME: ";
					cin>>lcapt1;
					delete_team(name2,lcapt1);
				}
				else if(ch==2){
					cout<<"\n\nENTER LOOSING TEAM "<<name1<<" CAPTAIN'S NAME: ";
					cin>>lcapt1;
					delete_team(name1,lcapt1);
				}
				else
				{
					fstream file1;
					file1.open("scores.txt",ios::in);
					cout<<"\n\nENTER LOOSING TEAM "<<name1<<" CAPTAIN'S NAME: ";
					cin>>lcapt1;
					cout<<"\n\nENTER LOOSING TEAM "<<name2<<" CAPTAIN'S NAME: ";
					cin>>lcapt2;
					char gd,sco1,sco2;
					int gdiff1,gdiff2,gdiff,score1,score2;
					while(!file1.eof())
					{
						file1.getline(tname1,10,'|');//winning team to be kept first
						file1.get(sco1);
						score1=(int)sco1;
						file1.getline(tname2,10,'|');
						file1.get(sco2);
						score2=(int)sco2;
						file1.get(gd);
						gdiff=(int)gd;
						if(strcmp(tname1,name1)==0)
							gdiff1+=gdiff;
						else if(strcmp(tname1,name2)==0)
							gdiff2+=gdiff;
					}
					if(gdiff1>gdiff2)
						delete_team(name2,lcapt2);
					
					else if(gdiff1<gdiff2)
						delete_team(name1,lcapt1);
					
					else
						cout<<"\nBOTH THE TEAMS ARE GOING TO THE NEXT ROUND";
				}
				i--;
				
			}
			k--;
			file.close();
		}
		file.close(); 
		file.open("team.txt",ios::in);
		if(!file)
		{
			cout<<"cannot open teams file";
			return;
		}
		while(!file.eof())
		{
			file.getline(name1,10,'|');
				
		}
		system("cls");
		cout<<"\n\n\t\t   ###########TEAM###########\n\n";
		system("color E8");
		
		cout<<"\t\t\t|||||||||||||||\n\t\t\t\t";cout<<name1;cout<<"\n\t\t\t|||||||||||||||";
		cout<<" \n\n\t\t\tIS THE WINNER OF\n \n\t\t ###########  ";
		cout<<tournament_name;	
		cout<<" ###########\n\n\t\t\tTOURNAMENT";
		system("color A1");
		system("color B2");
		sleep(1);
			system("color C3");
			sleep(1);
				system("color D4");
				sleep(1);	
					system("color E5");
					sleep(1);
		hscorer();
		getch();
		system("color f2");
		return;
}

int main()
{	
	system("color f2");
	bool succ;
	fstream file;
	system("cls");
	int ch,cs,cont=0;
	char cpass[10],pass[10],user[10];
	char a;
	 CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 10;
cfi.dwFontSize.X = 2;                   // Width of each character in the font
cfi.dwFontSize.Y = 46;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName,L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
system("color f2");
cout<<"\n\t\t>>>>>>>> WELCOME <<<<<<<<<\n\n";
	cout<<"\t\t___________________________\n";
	cout<<"\t\t___________________________\n\n";
	cout<<"\t\t>>>> FUTSAL TOURNAMENT <<<<\n";
	cout<<"\t\t___________________________\n";
	cout<<"\t\t___________________________\n\n\n\t\t\tLOADING...\n\n\t\t\t ";
	for(int u=0;u<10;u++)
	{
		for(int l=0;l<u%3;l++)
			cout<<"#";
		sleep(u%2);
	}
	// CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = 30;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName,L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


	while(1)
	{	system("cls");
		start:
		cout<<"\n\n1. USER SIGNUP\n2. USER LOGIN\n3. ADMIN LOGIN\n4. START THE TOURNAMENT\n5. CLEAR ALL THE DATA\n6. SEARCH USER\n7. SEARCH TEAM\n8. EXIT\n";
		cin>>ch;
		switch(ch)
		{
			case 1 : add_user();
					  break;
			
			case 2: succ=user_login();
					if(succ==true)
					{
						while(!cont){
						
							system("cls");
							
							cout<<"\n1. REGISTER FOR TOURNAMENT\n2. HIGHEST SCORES\n3. VIEW TEAMS\n4. DELETE MY ACCOUNT\n5.LOGOUT\n";
							cin>>cs;
							switch(cs)
							{
								case 1: add_team();break;
								
								case 2: hscorer();break;
								
								case 3: disp_teams();break;
								
								case 4:cout<<"\n ENTER PASSWORD:";
										cin>>cpass;
										if(strcmp(cpass,getpassgb)==0)
										{
											cout<<"\nPRESS Y TO CONFIRM DELETION OF YOUR ACCOUNT\n";
											a=getch();
											if(a=='y'||a=='Y')
											{
												delete_user(getusergb,getpassgb);
												goto start;
											}
											else
											{
												cout<<"\n ACCOUNT NOT WILL NOT BE DELETED\n";
												break;
											}
										}
										else{
											cout<<"\n PASSWORD DOES NOT MATCH\nCANCELLING DELETION\n";
											break;
										}
										break;
										
									case 5: cont=1;break;
									default:cout<<"\nENTER A VALID CHOICE\n";
							}
						}
							
					}
					else
					{
						cout<<"\n INVALID CREDENTIALS\nTERMINATING ";
						
						cout<<".";
						sleep(1);
						cout<<".";
						sleep(1);
						cout<<".";
						sleep(1);
						getch();
						system("cls");
						goto start;								
					}
										
					break;
					
			case 3: admin_login();break;
			
			case 4: 						cout<<"\nADMIN ID:";
											cin>>user;
											cout<<"\nADMIN PASSWORD: ";
											 for(int i=0;;)
										    {
										        char a=getch();
										        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
										        {
										            pass[i]=a;
										            ++i;
										            cout<<"*";
										        }
										        if(a=='\b'&&i>=1)
										        {
										            cout<<"\b \b";
										            --i;
										        }
										        if(a=='\r')
										        {
										            pass[i]='\0';
										            break;
										        }
										    }
											
											int c;
											if((strcmp(user,"admin")==0)&&(strcmp(pass,"1234")==0))
												{
													start_tournament();break;
											}
											else{
												
											cout<<"\n INVALID CREDENTIALS\nTERMINATING ";
											
												cout<<".";
												sleep(1);
												cout<<".";
												sleep(1);
												cout<<".";
												sleep(1);
												system("cls");
											goto start;
												
											}
											break;
											
			case 5:  						cout<<"\nADMIN ID:";
											cin>>user;
											cout<<"\nADMIN PASSWORD: ";
											 for(int i=0;;)
										    {
										        char a=getch();
										        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
										        {
										            pass[i]=a;
										            ++i;
										            cout<<"*";
										        }
										        if(a=='\b'&&i>=1)
										        {
										            cout<<"\b \b";
										            --i;
										        }
										        if(a=='\r')
										        {
										            pass[i]='\0';
										            break;
										        }
										    }
											
											if((strcmp(user,"admin")==0)&&(strcmp(pass,"1234")==0))
												{

											file.open("team.txt",ios::out|ios::trunc);
											if(!file)
											{
												cout<<"error";goto start;
											}
											file.clear();
											file.close();	
											file.open("goal.txt",ios::out);
											file.clear();
											file.close();
											file.open("scores.txt",ios::out);
											file.clear();
											file.close();
											file.open("users.txt",ios::out);
											file.clear();
											file.close();
											file.open("init_teams.txt",ios::out);
											file.clear();
											file.close();
											cout<<"\nSYSTEM RESET COMPLETED...\n";
											getch();
											system("cls");
											goto start;
										}
										else
										{
											cout<<"\n INVALID CREDENTIALS\nTERMINATING ";
											
												cout<<".";
												sleep(1);
												cout<<".";
												sleep(1);
												cout<<".";
												sleep(1);
												system("cls");
											goto start;
											
										}
											
									break;
			case 6:search_user();break;
			case 7: search_team();				
			case 8: exit(0);break;
			
			default: cout<<"ENTER A VALID CHOICE\n";
		}	
	}
}
