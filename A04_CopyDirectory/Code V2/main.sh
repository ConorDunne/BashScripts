#! /bin/bash


#
#       Student Name:           Conor Dunne
#       Student Number:         17379526
#       Student Email:          conor.dunne2@ucdconnect.ie
#
#       A bash file to copy a directory structure to a new folder
#





#       Main Recursive Function
#               Enters directory and copys folders to destionation
function scanDirectory {
#       Create folders
        #       Gets list of files in current directory
        dir=$(ls -d $1*/)

        #       Loops through each file
        for FOLDER in ${dir[@]}
        do
                #       Creates file
                file=${FOLDER/#$1}
                mkdir $2$file

                #       Goes into new file (Recursion)
                scanDirectory $FOLDER $2$file
        done

#       Copy over images as .jpg
        #       Gets list of images in current directory
        images=$(ls $1*.png)

        #       Loops through each image
	for IMAGE in ${images[@]}
	do
		#	Removes prefix and suffix from image
		i=${IMAGE/#$1}
		i2=${i%.png}

		#	Converts image to jpg in Dest folder
		convert $IMAGE $2$i2.jpg
	done
}



#	Test User Input
	#	Tests Number of Arguments
if [ $# -ne 2 ]
then
	echo "ERROR: Incorrect Number of Arguments - 2 Required"
	exit
fi

	#	Tests if Source file exits
if [ ! -d $1 ]
then 
	echo "ERROR: Source File Does Not Exist"
	exit
else
	Src=$1
fi

	#	Tests if Output ends with / and adds one if it doesn't
if [ $2 != */ ]
then
	Dest=$2/
else
	Dest=$2
fi

	#	Tests if program has permission to write
#if [   ]
#then
#	echo "ERROR: Insufficient Permissions"
#	exit
#fi

#	Runs Program (All Tests Complete)
mkdir $2			#	Create Initial Dest Folder
scanDirectory $Src $Dest	#	Creates Folder Directory Structure through Recursion
