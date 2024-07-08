#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct Stack {
    char store[20];
    int top;
} s1, s2, s3, s4;

struct Stack push(struct Stack s, char insert) {
    s.top++;
    s.store[s.top] = insert;
    return s;
}

struct Stack pop(struct Stack s) {
    if (s.top > -1) {
    	s.store[s.top] = '\0';
    	s.top = s.top - 1;
    }
    return s;
}

int main(int argc, char* argv[]) {    
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }
    
    s1.top = -1;
    s2.top = -1;
    s3.top = -1;
    s4.top = -1;
    
    char buff;
    bool balanced = true;
    while ( fscanf(fp, "%c", &buff)==1 ) {
        switch(buff) {
            case '<' :
                s1 = push(s1, '<');
                break;
            case '(' :
            	s2 = push(s2, '(');
                break;
            case '[' :
            	s3 = push(s3, '[');
                break;
            case '{' :
            	s4 = push(s4, '{');
                break;
            case '>' :
            	if (s1.top == -1) balanced = false;
            	else s1 = pop(s1);
                break;
            case ')' :
            	if (s2.top == -1) balanced = false;
            	else s2 = pop(s2);
                break;
            case ']' :
            	if (s3.top == -1) balanced = false;
            	else s3 = pop(s3);
                break;
            case '}' :
            	if (s4.top == -1) balanced = false;
            	else s4 = pop(s4);
                break;
            default :
                printf("Invalid character\n" );
        }
    }

    if (s1.top != -1) balanced = false;
    if (s2.top != -1) balanced = false;
    if (s3.top != -1) balanced = false;
    if (s4.top != -1) balanced = false;
    printf ( balanced ? "yes" : "no" );
    fclose(fp);
    return 0;
}
