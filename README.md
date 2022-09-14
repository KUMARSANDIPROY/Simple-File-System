File System
----------------------------------
Designed a simple File System having defined constraints using C++.
Implemented multiple functions such as create a file, list all files, delete the file, read and write the file.




Input 
-----------------------------

* Input is taken through Console.

* Input includes the following commands: 
	- mf file-name “filecontents”
	- df file-name
	- rf file-name1 file-name2
        - pf file-name 
        - ls




Data structures used
------------------------------

* Two unordered maps are used to maintain the meta data and disk blocks

	* meta_data : name of the file | inode number
	* disk_blocks : inode number | number of blocks

* Two sets are used to check for the uniqueness of the file names and inode numbers.




Commands
-----------------------------

* mf file-name “filecontents”
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
 
![189676424-737578e1-f081-4972-a770-9bb4aa088460](https://user-images.githubusercontent.com/52081779/190222596-c8d85518-e14d-4585-b727-8fc4f8789f18.JPG)
![189676426-7f38af7f-db83-4749-8368-5c43b3ce9475](https://user-images.githubusercontent.com/52081779/190222707-f95c5515-d2bb-431c-ab92-538aa18ec8d0.JPG)
![189676429-e4646a9c-b028-477e-a2d6-1151dac7815d](https://user-images.githubusercontent.com/52081779/190222830-5e8e061e-e7ac-4fa8-a841-35a48bfcd2d4.JPG)
![189676432-1dd93a82-53d3-4f01-8f8c-c8e4d660dfef](https://user-images.githubusercontent.com/52081779/190222908-6e17cf88-3b98-413f-8790-38f8bebd5e3d.JPG)
![189676416-bc03ba4a-ad32-4a53-a53b-9625a3225a8f](https://user-images.githubusercontent.com/52081779/190223029-f6d62b6b-4036-4f8d-89d0-cba266bb9514.JPG)
