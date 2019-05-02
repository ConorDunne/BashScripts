#!/usr/bin/env python3

#
#	Student Name:		Conor Dunne
#	Student Number:		17379526
#	Student Email:		conor.dunne2@ucdconnect.ie
#
#	A program that analyses apache log files and returns the following information:
#		The number of unique IP addresses 
#		The top N IP addresses in order of requests
#		Number of requests for a given IP address
#		Lists all requests for a given IP address
#		Lists IP addresses for a certain day along side the number of requests
#

import sys
import getopt
import collections
import re


#   Main function (Main body)
def main(argv):
    #   Tests number of inputs
    if(len(argv) < 3):
        helpMessage()
        sys.exit(2)

    #   Takes flags from command line input
    opts = getFlags(argv[1:len(argv)])
   
    #   Looks at flags and gives output depending on the flag
    for o, a in opts:
        if o == "-l":
            f = openFile(a)
        if o == "-h":
            helpMessage()
        elif o == "-n":
            nFlag(f)
        elif o == "-t":
            tFlag(f, int(a))
        elif o == "-v":
            vFlag(f, a)
        elif o == "-L":
            LFlag(f, a)
        elif o == "-d":
            dFlag(f)

    #   Closes file and program
    f.close()
    sys.exit(2)

def getFlags(flags):
 #   Formats flags into opts and args using getopt
    try:
        opts, args = getopt.getopt(flags, "l:hnt:v:L:d:z")
        return opts
    except getopt.GetoptError as err:
        print(err)
        helpMessage()
        sys.exit(2)

def openFile(fileName):
    try:
        f = open(fileName)
        return f
    except IOError:
        print("Could not read file:", argv[2])
        helpMessage()
        sys.exit(2)

def helpMessage():
    print("Usage: ./assign4.py -l [FILE] [OPTIONS]")
    print("Returns analytical data on Apache log files")
    print("Must take flag for data\n")

    print("Options are as follows")
    print("  -h\tDisplay this help and exit")
    print("  -n\tDisplays number of unique IP addresses in log")
    print("  -t\t List top N IP addresses in log file by number of requests")
    print("\t\tRequires Numerical Argument")
    print("  -v\t Gives number of visits by an IP address")
    print("\t\tRequires Valid IP address")
    print("  -L\tLists all requests by an IP address")
    print("\t\tRequires Valid IP address")
    print("  -d\tLists number of requests for all IP addresses on a specific day")
    print("\t\tRequires Valid data (ddMMMyyyy eg 09Feb2013)")



#   Creates a dictionary of every IP and their number of requests
    #   For -n and -t flags
def ipCountDict(f):
    ip_dict = {}
    line = f.readline()

    while line:
        ip = line.split(' ', 1)[0] 
        
        if ip in ip_dict:
            ip_dict[ip] += 1
        elif ip != "::1":
            ip_dict[ip] = 1
        
        line = f.readline()

    return ip_dict

#   Function for -n Flag (Total Number of unique log files)
def nFlag(f):
    ip_dict = ipCountDict(f)
    print(len(ip_dict)) 

#   Function for -t Flag (x IP's with most requests - x most common IP's)
def tFlag(f, arg):
    ip_dict = ipCountDict(f)
    c = collections.Counter(ip_dict).most_common(arg)

    print("{}\t\t\t  {}".format("IP", "Requests"))
    for i, n in c:
        print("{}\t\t: {}".format(i, n))

#   Function for -v Flag (Total Number of visits for a given IP)
def vFlag(f, arg):
    ip_dict = ipCountDict(f)
    print(ip_dict[arg])
 
#   Function for -L Flag (List of all requests for a given IP)
def LFlag(f, arg):
    line = f.readline()

    while line:
        ip = line.split(' ', 1)[0]
        index = []

        if(ip == arg):
            for i in re.finditer("\"", line):
                index.append(i.start())

            print("{} ... {} ...".format(ip, line[index[0]:index[2]]))
        
        line = f.readline()


#   Function for -d Flag (IP's and the number of visits for a given day)
def dFlag(f, arg):
    ip_dict = {}
    line = f.readline()
    search = arg[:2] + "/" + arg[2:5] + "/" + arg[5:]

    while line:
        ip = line.split(' ', 1)[0]
        date = re.findall("\d{2}\/\w{3}\/\d{4}", line)
        
        if ip != "::1" and date[0] == search:
            if ip in ip_dict:
                ip_dict[ip] += 1
            else:
                ip_dict[ip] = 1

        line = f.readline()
        
    for a in ip_dict:
        print("{}\t: {}".format(a, ip_dict[a]))

#   Python Program Body - Calls Main Function
main(sys.argv)


