
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "strformat.h"



int string_lenth(m_string word){
	int i = 0;
	for(; word[i] != '\0'; ++i);
	
	return i;
	
}


m_string to_upper(m_string word){
	int i = 0;
	for(; word[i] != '\0'; ++i){
		if(word[i] < 'z' && word[i] > 'a'){
			word[i] -= 32;
		}
	}
	
	return word;
}

m_string append_str(m_string word1, m_string word2){
	return strcat(word1,word2);
	
}