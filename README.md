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
 
![a1](https://user-images.githubusercontent.com/15118630/189681014-7e218c82-561f-453a-a520-01b1684bf3e4.jpg)
![a2](https://user-images.githubusercontent.com/15118630/189681042-ef9939b0-262d-495b-ba63-34143446881d.jpg)
![a3](https://user-images.githubusercontent.com/15118630/189681105-fe29e4cc-26fc-441f-acb7-014294e263a8.jpg)
![a4](https://user-images.githubusercontent.com/15118630/189681126-62d03699-ab34-41bf-85de-aef96e4a5746.jpg)
![a5](https://user-images.githubusercontent.com/15118630/189681163-f907ea26-a229-4f8b-8b00-b3d402787185.jpg)
