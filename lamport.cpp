#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

// for conversion
bool is_proocess_id(char id)
{
	if(id == '1' || id =='2' || id == '3' || id =='4' ||  id == '5' || id == '6' || id == '7' || id == '8' || id == '9' )
		return true;
	else
		return false;
}

// driver code
int main()
{
	
	map<string,vector<vector<string>>> task;
	map<string,map<string,map<string,vector<int>>>> sent_msg_to_vec;
	cout<<"Enter task in format and type 0 in a new line to end task " <<endl;
	
	int counter=0;
	
	string lock="default";
	while(true)
	{
		string s;
		getline( std::cin, s );
		istringstream is( s );
		vector<string> inputs( ( std::istream_iterator<string>( is ) ), std::istream_iterator<string>() );
		vector<string> temp;
		if(is.str().size()!=0)
		{
			if(inputs[0]=="begin")
			{
				
				if(lock!="default")
				{
					cout<<endl<<"can't begin a new process without ending the previous process" << endl <<" Terminating the program"<<endl;
					exit(1);
				}
				if(inputs.size()!=3 || inputs[1]!="process" || inputs[2].size()!=2 || inputs[2][0]!='p' || !is_proocess_id(inputs[2][1]))
				{
					cout<<endl <<"Error detected in line"<<endl;
							for(int j=0;j<inputs.size();j++)
								cout<<inputs[j]<<" ";
							cout<<"endl";
							cout<<"The execution of program stops here only, Try again."<<endl;;
							exit(1);
				}
				if(task.find(inputs[2])!=task.end())
				{
					cout<<endl << "This process "<<inputs[2]<<" has already been taken , cant't run duplicate"<<endl;
					cout<<endl << "Error detected in line "<<endl;
							for(int j=0;j<inputs.size();j++)
								cout<<inputs[j]<<" ";
							cout<<endl;
							cout<<"The execution of program stops here only, Try again."<<endl;
							exit(1);
				}
				lock=inputs[inputs.size()-1];
				vector<vector<string>> v;
				task.insert({lock,v});
				counter++;
				
			}
			else if(inputs[0]=="end")
			{
				if(lock=="default")
				{
						cout<<"\nCan't end a process without beginning it\nProgram terminates , try again.\n";
						exit(1);
				}
				if(inputs.size()!=2 && inputs[1]!="process")
				{
					cout<<"\nError detected in line \n ";
							for(int j=0;j<inputs.size();j++)
								cout<<inputs[j]<<" ";
							cout<<endl;
							cout<<"The execution of program stops here only. Try again.\n";
							exit(1);
				}
				lock="default";
			}	
			else if(inputs[0]=="0")
			{
				if(lock!="default")
				{
						cout<< endl << "Can't terminate without ending previous process" << endl << " Program terminates , try again."<<endl;
						exit(1);
				}
				break;
			}
			else if(inputs[0]=="print" || inputs[0]=="send" || inputs[0]=="recv")
			{
				
				if(lock=="default")
				{
					cout<<endl<<" You can't write print/send/recv command without beginning a process."<< endl <<" terminating the execution here only."<<endl;
					exit(1);
				}
				for(int i=0;i<inputs.size();i++)
					temp.push_back(inputs[i]);
				task[lock].push_back(temp);
				temp.clear();
			}
			else
			{
				cout<<endl<<"Error detected in line "<<endl;
							for(int j=0;j<is.str().size();j++)
								cout<<is.str()[j];
							cout<<endl;
							cout<<"The execution of program stops here only, Try again"<<endl;
							exit(1);
			}
		}
	}
	
	map<string,int> curr;
	int temp1[9];
	map<string,vector<int>> timing;

	vector<int> vec1(9,0);
	vector<int> vec2(9,0);
	vector<int> vec3(9,0);
	vector<int> vec4(9,0);
	vector<int> vec5(9,0);
	vector<int> vec6(9,0);
	vector<int> vec7(9,0);
	vector<int> vec8(9,0);
	vector<int> vec9(9,0);

	timing.insert({"p1",vec1});
	timing.insert({"p2",vec2});
	timing.insert({"p3",vec3});
	timing.insert({"p4",vec4});
	timing.insert({"p5",vec5});
	timing.insert({"p6",vec6});
	timing.insert({"p7",vec7});
	timing.insert({"p8",vec8});
	timing.insert({"p9",vec9});
	
	for(auto i=task.begin();i!=task.end();i++)
	{
		curr.insert({i->first,0});	
	}

	while(counter!=0)
	{
		counter=0;
		for(auto i=task.begin();i!=task.end();i++)
		{
			if(curr[i->first]!=i->second.size())
			{
				if(i->second.size()>0 && i->second[curr[i->first]][0]=="recv")
				{
					
					if(i->second[curr[i->first]].size()!=3 || i->second[curr[i->first]][1].size()!=2 || i->second[curr[i->first]][1][0]!='p' || !is_proocess_id(i->second[curr[i->first]][1][1]) || i->second[curr[i->first]][2][0]!='m' )
					{
						cout<<"Error detected in line \n ";
							for(int j=0;j<i->second[curr[i->first]].size();j++)
								cout<<i->second[curr[i->first]][j]<<" ";
							cout<<"\n";
							cout<<"The execution pf program stops here only. Try again.\n";
							exit(1);
					}
					if(sent_msg_to_vec.find(i->second[curr[i->first]][1])!=sent_msg_to_vec.end())
					{
						if(sent_msg_to_vec[i->second[curr[i->first]][1]].find(i->first)!=sent_msg_to_vec[i->second[curr[i->first]][1]].end())
						{
							if(sent_msg_to_vec[i->second[curr[i->first]][1]][i->first].find(i->second[curr[i->first]][2])!=sent_msg_to_vec[i->second[curr[i->first]][1]][i->first].end())
							{
									if(i->first=="p1")
									{
										timing["p1"][0]++;
									}
									else if(i->first=="p2")
									{
										timing["p2"][1]++;
									}
									else if(i->first=="p3")
									{
										timing["p3"][2]++;
									}
									else if(i->first=="p4")
									{
										timing["p4"][3]++;
									}
									else if(i->first=="p5")
									{
										timing["p5"][4]++;
									}
									else if(i->first=="p6")
									{
										timing["p6"][5]++;
									}
									else if(i->first=="p7")
									{
										timing["p7"][6]++;
									}
									else if(i->first=="p8")
									{
										timing["p8"][7]++;
									}
									else if(i->first=="p9")
									{
										timing["p9"][8]++;
									}
									int temp[9]={0};
									timing[i->first][0]=max(timing[i->first][0],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][0]);
									timing[i->first][1]=max(timing[i->first][1],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][1]);
									timing[i->first][2]=max(timing[i->first][2],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][2]);
									timing[i->first][3]=max(timing[i->first][3],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][3]);
									timing[i->first][4]=max(timing[i->first][4],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][4]);
									timing[i->first][5]=max(timing[i->first][5],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][5]);
									timing[i->first][6]=max(timing[i->first][6],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][6]);
									timing[i->first][7]=max(timing[i->first][7],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][7]);
									timing[i->first][8]=max(timing[i->first][8],sent_msg_to_vec[i->second[curr[i->first]][1]][i->first][i->second[curr[i->first]][2]][8]);

									cout<<"received"<<" "<<i->first<<" "<<i->second[curr[i->first]][2]<<" "<<i->second[curr[i->first]][1]<<" ""<"<<timing[i->first][0]<<","<<timing[i->first][1]<<","<<timing[i->first][2]<<","<<timing[i->first][3]<<","<<timing[i->first][4]<<","<<timing[i->first][5]<<","<<timing[i->first][6]<<","<<timing[i->first][7]<<","<<timing[i->first][8]<<">\n";
								}
								curr[i->first]++;
								counter=1;
							
						}
					}
				}
				else
				{
					if(i->first=="p1")
					{
						timing["p1"][0]++;
					}
					else if(i->first=="p2")
					{
						timing["p2"][1]++;
					}
					else if(i->first=="p3")
					{
						timing["p3"][2]++;
					}
					else if(i->first=="p4")
					{
						timing["p4"][3]++;
					}
					else if(i->first=="p5")
					{
						timing["p5"][4]++;
					}
					else if(i->first=="p6")
					{
						timing["p6"][5]++;
					}
					else if(i->first=="p7")
					{
						timing["p7"][6]++;
					}
					else if(i->first=="p8")
					{
						timing["p8"][7]++;
					}
					else if(i->first=="p9")
					{
						timing["p9"][8]++;
					}

					if(i->second.size()>0 && i->second[curr[i->first]][0]=="send")
					{
						if(i->second[curr[i->first]].size()!=3 || i->second[curr[i->first]][1].size()!=2 || i->second[curr[i->first]][1][0]!='p' || !is_proocess_id(i->second[curr[i->first]][1][1]) || i->second[curr[i->first]][2][0]!='m' )
						{
							cout<<"Error detected in line \n ";
							for(int j=0;j<i->second[curr[i->first]].size();j++)
								cout<<i->second[curr[i->first]][j]<<" ";
							cout<<"\n";
							cout<<"The execution pf program stops here only. Try again.\n";
							exit(1);
						}
						
						cout<<"sent_msg_to_vec"<<" "<<i->first<<" "<<i->second[curr[i->first]][2]<<" "<<i->second[curr[i->first]][1]<<" "<<"<"<<timing[i->first][0]<<","<<timing[i->first][1]<<","<<timing[i->first][2]<<","<<timing[i->first][3]<<","<<timing[i->first][4]<<","<<timing[i->first][5]<<","<<timing[i->first][6]<<","<<timing[i->first][7]<<","<<timing[i->first][8]<<">\n";
						if(sent_msg_to_vec.find(i->first)==sent_msg_to_vec.end())
						{
							vector<int> temp(9,0);
							temp[0]=timing[i->first][0];
							temp[1]=timing[i->first][1];
							temp[2]=timing[i->first][2];
							temp[3]=timing[i->first][3];
							temp[4]=timing[i->first][4];
							temp[5]=timing[i->first][5];
							temp[6]=timing[i->first][6];
							temp[7]=timing[i->first][7];
							temp[8]=timing[i->first][8];

							map<string,map<string,vector<int>>> j;
							sent_msg_to_vec.insert({i->first,j});
							map<string,vector<int>> s;
							sent_msg_to_vec[i->first].insert({i->second[curr[i->first]][1],s});
							sent_msg_to_vec[i->first][i->second[curr[i->first]][1]].insert({i->second[curr[i->first]][2],temp});
						}
						else 
						{
							if(sent_msg_to_vec[i->first].find(i->second[curr[i->first]][1])==sent_msg_to_vec[i->first].end())
							{
								vector<int> temp(9,0);
								temp[0]=timing[i->first][0];
								temp[1]=timing[i->first][1];
								temp[2]=timing[i->first][2];
								temp[3]=timing[i->first][3];
								temp[4]=timing[i->first][4];
								temp[5]=timing[i->first][5];
								temp[6]=timing[i->first][6];
								temp[7]=timing[i->first][7];
								temp[8]=timing[i->first][8];
								map<string,vector<int>>s;
								sent_msg_to_vec[i->first].insert({i->second[curr[i->first]][1],s});
								sent_msg_to_vec[i->first][i->second[curr[i->first]][1]].insert({i->second[curr[i->first]][2],temp});

							}
							else 
							{
								vector<int> temp(9,0);
								temp[0]=timing[i->first][0];
								temp[1]=timing[i->first][1];
								temp[2]=timing[i->first][2];
								temp[3]=timing[i->first][3];
								temp[4]=timing[i->first][4];
								temp[5]=timing[i->first][5];
								temp[6]=timing[i->first][6];
								temp[7]=timing[i->first][7];
								temp[8]=timing[i->first][8];
								sent_msg_to_vec[i->first][i->second[curr[i->first]][1]].insert({i->second[curr[i->first]][2],temp});
							}
						}
						curr[i->first]++;
						counter=1;
						

					}
					else if(i->second.size()>0 && i->second[curr[i->first]][0]=="print")
					{
						if(i->second[curr[i->first]].size()!=2)
						{
							cout<<"Error detected in line \n ";
							for(int j=0;j<i->second[curr[i->first]].size();j++)
								cout<<i->second[curr[i->first]][j]<<" ";
							cout<<"\n";
							cout<<"The execution pf program stops here only. Try again.\n";
							exit(1);
						}

						cout<<"printed"<<" "<<i->first<<" "<<i->second[curr[i->first]][1]<<" "<<"<"<<timing[i->first][0]<<","<<timing[i->first][1]<<","<<timing[i->first][2]<<","<<timing[i->first][3]<<","<<timing[i->first][4]<<","<<timing[i->first][5]<<","<<timing[i->first][6]<<","<<timing[i->first][7]<<","<<timing[i->first][8]<<">\n";
						
						{
							curr[i->first]++;
							counter=1;
						}
					
					}
				}
			}
		}
	}
	int recvp=0;
	int nodead=0;
	if(counter==0)
	{
		for(auto i=task.begin();i!=task.end();i++)
		{
			if(curr[i->first]<i->second.size() && task[i->first][curr[i->first]][0]=="recv")
			{
				recvp=0;
				if(task.find(task[i->first][curr[i->first]][1])!=task.end())
				{
					for(int x=curr[task[i->first][curr[i->first]][1]];x<task[task[i->first][curr[i->first]][1]].size();x++)
					{
						if(task[task[i->first][curr[i->first]][1]][x][0]=="send" && task[task[i->first][curr[i->first]][1]][x][1]==i->first && task[task[i->first][curr[i->first]][1]][x][2]==task[i->first][curr[i->first]][2])
						{
							recvp=1;
							break;	
						}
					}
					if(recvp!=1)
					{
						cout<<"error , send of receive message < "<<task[i->first][curr[i->first]][0]<<" "<<task[i->first][curr[i->first]][1]<<" "<<task[i->first][curr[i->first]][2]<<" > not present_msg_to_vec.\n";
						nodead=1;
					}
				}
				else
				{
					cout<<"error , send of receive message < "<<task[i->first][curr[i->first]][0]<<" "<<task[i->first][curr[i->first]][1]<<" "<<task[i->first][curr[i->first]][2]<<" > not present_msg_to_vec.\n";
						nodead=1;
				}
			}
			if(nodead==0 && curr[i->first]<i->second.size())
			{	
				counter=1;
				cout<<"system deadlocked\n";
				break;
			}

		}
	}

}