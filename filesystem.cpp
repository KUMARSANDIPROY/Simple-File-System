#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <set>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>				
#include <stdlib.h>

#define block_size 4

using namespace std;

// filename | inode
unordered_map<string,int> meta_data;     
// inode | no_of_blocks
unordered_map<int,int> disk_blocks;    
//to maintain unique filenames
set<string> file_list;
//to maintain unique inodes
set<int> inode_list;

//Receiving the command by the user
 vector<string> split(string str, char delimiter) 
 {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    while(getline(ss, tok, delimiter)  ) 
	{
        internal.push_back(tok);
    }
    return internal;
}
vector <string> get_command()
{
    string  cmd;
    //initialCommit();
    getline(cin, cmd);
    vector <string> cmmCMD = split(cmd, ' ');
    return cmmCMD;
}


//creating a new file in the file system

int create(vector<string> cmd)
{
	FILE *fin;
	if (cmd.size() < 3)
	{
        cout << "MISSING DATA: Insufficient arguments \n";
        return 0;
    }
    if(file_list.find(cmd[1])!=file_list.end())
    {
    	cout<< "File with the name already exists!! \n";
    	return 0;
	}
	//insert the filename into the list
	file_list.insert(cmd[1]);
	//create a unique inode for file
	int inode;
	while(1)
	{
		inode = rand();
		if(inode_list.find(inode) == inode_list.end())
		{
			//insert filename and corresponding inode into meta_data
			meta_data.insert(make_pair(cmd[1], inode));
			break;
		}
	}
	//insert the inode into the inode list
	inode_list.insert(inode);
    string content = cmd[2];
    if(cmd.size()>3)
    {
    	for(int i=3; i<cmd.size();i++)
    	{
    		content.append(" ");
    		content.append(cmd[i]);
		}
	}
    content.erase(content.begin()+0);
    content.erase(content.begin()+content.length()-1);
    
    //calculate the number of disk files required
    int nblocks;
    if(content.length() % 4 == 0)
    	nblocks = content.length()/4;
    else
    	nblocks = content.length()/4 + 1;
    
    //create disk block files with name inodeno_blockno
    int temp = 0;
    for(int i=1; i<= nblocks; i++ )
    {
    	string fc = content.substr(temp, 4);
    	char num[3], inode_num[20], fname[20];
    	memset(num,0,3);
    	memset(inode_num, 0 , 20);
    	sprintf(inode_num, "%d",inode);
		sprintf(num,"%d",i);
		_snprintf(fname,sizeof(fname),"%s%s%s%s%s", "root/", inode_num, "_", num,".txt");
		const char* con = fc.c_str();
		fin = fopen(fname, "w");
		fprintf(fin, con );
		fclose(fin);
		temp += 4;
	}
	disk_blocks.insert(make_pair(inode, nblocks));
    cout<<"File created\n"<<endl;
}

//deleting a file from the file system
void delete_file(vector<string> cmd)
{
	string filename = cmd[1];
	//check if the file with given name is present in the file system
	auto it1 = meta_data.find(filename);
	if(it1 == meta_data.end())
	{
		cout<<"file not found"<<endl;
		return;
	}
		
	//get the inode of the file to be deleted
	int inode = it1->second;
	//remove the file entry from the meta data
	meta_data.erase(filename);
	
	//retrieve the number of disk files created for the file to be deleted
	auto it2 = disk_blocks.find(inode);
	int nblocks = it2->second;
	
	// remove the disk block entry from the file
	disk_blocks.erase(inode);
	
	//delete all the disk files
	for(int i=1; i<= nblocks; i++ )
    {
    	char num[3], inode_num[20], fname[20];
    	memset(num,0,3);
    	memset(inode_num, 0 , 20);
    	sprintf(inode_num, "%d",inode);
		sprintf(num,"%d",i);
		_snprintf(fname,sizeof(fname),"%s%s%s%s%s", "root/", inode_num, "_", num,".txt");
		remove(fname);
	}
	//remove the file from the list of files
	file_list.erase(cmd[1]);
	//remove the inode from the inode list
	inode_list.erase(inode);
	
	cout<<"File deleted"<<endl;
}

//rename a file 
void rename(vector<string> cmd)
{
	if(cmd.size() !=3)
	{
		cout << "MISSING DATA: Insufficient arguments \n";
        return;
	}
	string filename = cmd[1];
	string newfname = cmd[2];
	//check whether the new filename is unique
	if(file_list.find(cmd[2])!=file_list.end())
    {
    	cout<< "File with the name already exists!! \n";
    	return;
	}
	//check if the file with given name is present in the file system
	auto it1 = meta_data.find(filename);
	if(it1 == meta_data.end())
	{
		cout<<"file not found"<<endl;
		return;
	}
	int inode = it1->second;
	meta_data.erase(filename);
	//rename the filename in the metadata
	meta_data.insert(make_pair(newfname, inode));
	//remove the file from the list of files
	file_list.erase(cmd[1]);
	//insert the new filename into the list of files
	file_list.insert(cmd[2]);
}

//display the contents of a file
void display(vector<string> cmd)
{
	FILE *fin;
	string filename = cmd[1];
	//check if the file with given name is present in the file system
	auto it1 = meta_data.find(filename);
	if(it1 == meta_data.end())
	{
		cout<<"file not found"<<endl;
		return;
	}
	//get the inode of the file to be displayed
	int inode = it1->second;
	
	//retrieve the number of disk files created for the file to be displayed
	auto it2 = disk_blocks.find(inode);
	int nblocks = it2->second;
	
	//display all the disk file contents
	for(int i=1; i<= nblocks; i++ )
    {
    	char num[3], inode_num[20], fname[20];
    	char buf[10];
    	memset(num,0,3);
    	memset(inode_num, 0 , 20);
    	sprintf(inode_num, "%d",inode);
		sprintf(num,"%d",i);
		_snprintf(fname,sizeof(fname),"%s%s%s%s%s","root/", inode_num, "_", num,".txt");
		fin = fopen(fname, "r");
		fscanf(fin,"%[^\n]s", buf);
		cout<<buf;
	}
	cout<<endl;
}

//list all the files from the metadata
void list_files()
{
	cout<<"-------------------------------------------------"<<endl;
	cout<<"FILE NAME\tINODE NUMBER\n";
	cout<<"-------------------------------------------------"<<endl;
	for(auto it : meta_data)
	{
		cout<<it.first<<"\t\t"<<it.second<<endl;
	}
	cout<<"-------------------------------------------------"<<endl;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	vector<string> cmd;
	int res;
	
	//creating root directory
	char* dirname= "root";
	mkdir(dirname);
	
	while(1)
	{
		cout<<"\nEnter Command $ ";
		//read the command from the user
		cmd = get_command();
		
		if ( cmd[0] == "mf" )
		{
			res = create(cmd);
			if(res == 0)
			{
				cout<<"Cannot create the file"<<endl;
			}
		}
		else if ( cmd[0] == "df" )
		{
			delete_file(cmd);
		}
		else if ( cmd[0] == "rf" )
		{
			rename(cmd);
		}
		else if ( cmd[0] == "pf" )
		{
			display(cmd);
		}
		else if ( cmd[0] == "ls" )
		{
			list_files();
		}
		else
		{
			cout<<"Enter a valid command!!!"<<endl;
		}
		
	}
	
	return 0;
}
