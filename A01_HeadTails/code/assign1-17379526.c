/**
*       Student Name:           Conor Dunne
*       Student Number:         17379526
*       Student Email:          conor.dunne2@ucdconnect.ie
*       
*       To replecate the heads, tail linux command.
*       Flags -e and -o also available to display the odd or even lines within the first or last n lines
*       Flags -n also changed the number of lines to be displayed. Takes a second argument that takes a number
*       Flag -V to output the version history of the program
*       Flag -h to output help for the program (like this)
* 
*       The entire project works as wanted, except from reading from standard input.
*       It will read it line by line and output each line as you enter it.
*       It will also can't read from standard input when using tail
*/  

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void head(int numberOfLines, FILE *fptr, int OddFlag, int EvenFlag);
void tail(int numberOfLines, FILE *fptr, int OddFlag, int EvenFlag);

int main(int argc, char *argv[]) {
//  Initialise Variables
    int opt;            //  Get Option
    int nflg = 20;      //  Set Number Flag
    int Vflg = 0;       //  Set Version Flag
    int hflg = 0;       //  Set Head Flag
    int eflg = 0;       //  Set Even Flag
    int oflg = 0;       //  Set Odd Flag
    int headTail = -1;  //  Head or Tail Flag
    
//  Test for head or tail
    if(!strcmp(argv[1], "head"))
        headTail = 1;
    else if(!strcmp(argv[1], "tail"))
        headTail = 0;
    else {
        printf( "%s is an invalid first argument.\n"
                "{ head | tail } [OPTION ] . . . [ FILE ]\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
//  Get Flag Data
    while( (opt = getopt(argc, argv, "n:Vheo")) != -1) {
        switch(opt) {
            case 'n':
                nflg = atoi(optarg);
                break;
            case 'V':
                Vflg = 1;
                break;
            case 'h':
                hflg = 1;
                break;
            case 'e':
                eflg = 1;
                break;
            case 'o':
                oflg = 1;
                break;
            case '?':
                if(optopt == 'n')
                    fprintf(stderr, "Option %c needs argument\n", optopt);
                else
                    fprintf(stderr, "Unknown option %c\n", optopt);
                break;
            default:
                fprintf(stderr, "getopt\n");
                break;
        }
    }
    
//  Cannot print even and odd at once (error check)
    if(eflg == 1 && oflg == 1) {
        printf("Invalid Inputs.\nCannot print odd only and even only lines at once.");
        exit(EXIT_FAILURE);
    }
    
//  Print Help/Version
    if(Vflg == 1) {
        printf( "A user created version of the command \"Head\"\n"
                "Student Name:      Conor Dunne\n"
                "Student Number:    17379526\n");
    } if(hflg == 1) {
        printf( "Head Flags\n"
                "\t -n K    Output the first|last K lines\n"
                "\t -V      Output version info\n"
                "\t -h      Output help and exit\n"
                "\t -e      Output Even Lines\n"
                "\t -o      Output Odd Lines\n\n");
    }
    
//  Open file to read
    FILE *fptr;
        fptr = fopen(argv[argc-1], "r");
        
    if(fptr == NULL)
        fptr = stdin;
   
//  Call head and tail functions
    if(headTail == 1) {
        head(nflg, fptr, oflg, eflg);
    } else {
        tail(nflg, fptr, oflg, eflg);
    }
    
    exit(EXIT_SUCCESS);
}

//  Print the head of the file
void head(int numberOfLines, FILE *fptr, int OddFlag, int EvenFlag) {
//  Initialise Variables
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

//  To make sure that k number of lines are displayed
    if(OddFlag == 1 || EvenFlag == 1)
        numberOfLines *= 2;
    
//  Print first n lines
    for(int i=0; (i<numberOfLines && (read = getline(&line, &len, fptr)) != 1); i++) {
//  Test for odd and even flags
        if((OddFlag == 1) && (i%2 == 0)) 
            printf("%d\t%s", i+1, line);
        else if((EvenFlag == 1) && (i%2 == 1))
            printf("%d\t%s", i+1, line);
        else if(EvenFlag == 0 && OddFlag == 0)
            printf("%d\t%s", i+1, line);
    }
}

//  Print the tail of the file
void tail(int numberOfLines, FILE *fptr, int OddFlag, int EvenFlag) {
//  Initialise Variables
    unsigned long long pos; 
    char str[2*100]; 
    int count = 0;
    int found = 0;
    
//  To make sure that k number of lines are displayed
    if(OddFlag == 1 || EvenFlag == 1)
        numberOfLines *= 2;
    
// Go to End of file 
    if (fseek(fptr, 0, SEEK_END)) 
        perror("fseek() failed"); 
    else { 
//  Set Pos as number of charaters in file
        pos = ftell(fptr); 
  
//  Search for '\n' (End of Line)
        while (pos && !found) { 
// Move 'pos' away from end of file. 
            if (!fseek(fptr, --pos, SEEK_SET)) { 
                if (fgetc(fptr) == '\n') 
  
//  Stop going back when enough lines are found
                    if (count++ == numberOfLines) 
                        found = 1;
            } 
            else
                perror("fseek() failed"); 
        } 
  
// Print last n lines 
        for(int i=0; fgets(str, sizeof(str), fptr); i++) {
//  Test for Odd and Even Flags
            if((OddFlag == 1) && (i%2 == 0)) 
                printf("%d\t%s", i+1, str);
            else if((EvenFlag == 1) && (i%2 == 1))
                printf("%d\t%s", i+1, str);
            else if(EvenFlag == 0 && OddFlag == 0)
                printf("%d\t%s", i+1, str);
        }
    } 
}
