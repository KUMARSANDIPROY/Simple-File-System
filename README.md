File System
----------------------------------
Designed a simple File System having defined constraints using C++.
Implemented multiple functions such as create a file, list all files, delete the file, read and write the file.




Input 
-----------------------------

* Input is taken through Console.

* Input includes the following commands: 
	- mf file-name filecontents
	- df file-name
	- rf file-name1 file-name2
        - pf file-name 
        - ls
	
Commands
-----------------------------

* mf file-name filecontents
	* first check for the uniqueness of the filename
	* create a unique inode for file
	* insert filename and corresponding inode into the meta data.
	* insert the inode and filename into the sets for checking the uniqueness further.
	* calculate the number of disk files required and create disk block files with inodeno_blockno

* df file-name
	* check if the file with given name is present in the file system
	* get the inode of the file to be deleted
	* remove the file entry from the meta data
	* retrieve the number of disk files created for the file to be deleted
	* remove the disk block entry from the file
	* delete all the disk files.
	* remove the file from the list of files
	* remove the inode from the inode list.

* rf file-name1 file-name2
	* check whether the new filename is unique
	* check if the file with given name is present in the file system
	* rename the filename in the metadata
	* remove the file from the list of files
	* insert the new filename into the list of files

* pf file-name 
	* check if the file with given name is present in the file system
	* get the inode of the file to be displayed
	* retrieve the number of disk files created for the file to be displayed
	* display all the disk file contents


* ls
	* list all the files from the meta_data
  
 
 
 ---------------------------------------------------------------
 
 Screenshots
 --------------------
 ![Screenshot from 2022-09-17 00-58-33](https://user-images.githubusercontent.com/52081779/190717102-723b9d63-9b0f-4849-ad1d-b5ba064968d2.png)

![Screenshot from 2022-09-17 00-58-45](https://user-images.githubusercontent.com/52081779/190717149-338a8496-f990-44f4-a214-3e1e6c1917f9.png)
![Screenshot from 2022-09-17 01-01-07](https://user-images.githubusercontent.com/52081779/190717170-758a3ad3-5372-4290-8d31-245b342040b3.png)
![Screenshot from 2022-09-17 01-01-33](https://user-images.githubusercontent.com/52081779/190717203-de938a68-1f9b-48d5-8029-769249c33e0a.png)
![Screenshot from 2022-09-17 01-02-49](https://user-images.githubusercontent.com/52081779/190717216-594de165-5336-41c1-bf2a-c4a915026e8e.png)
