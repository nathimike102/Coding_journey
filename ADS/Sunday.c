/*
DSA
-->Bit Masking
-->Maths
-->stl in cpp
-->Array
-->String
-->Matrix
-->Sorting

-->Recursion
-->binary search
-->two pointer
-->prefix
-->sliding window
-->greedy

DS
-->Linked list
-->Stacks
-->Queues
-->Trees
-->Graphs
-->DP
*/

//BIT MASKING
// int count_dgits = log10(num)+1;
// int count_binary = log2(num)+1;

// and(&), or(|), not(~), xor(^)

#include<stdio.h> 
#include<math.h>

void printBinary(int n){
	int bit_count = log2(n)+1;
	int mask = (1<<bit_count-1);
	for(int i=bit_count-1;i>=0;i++){
		if(mask&n){
			printf("1");
		}else{
			printf("0");
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	printBinary(n);
}