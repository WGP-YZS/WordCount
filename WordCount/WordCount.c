#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>  
int openFilt();//打开文件 
int wordCount();//计算单词数 
int charCount();//计算字符数 
int main(int argc, char *argv[]){
	FILE *fp = fopen(argv[2],"r");//打开文件 
	if(openFile(fp)==-1){
		printf("文件读取失败！");
		return 0;  
	}
	if(!strcmp(argv[1],"-c")){
		int CHARCOUNT = charCount(fp);
		printf("字符数：%d",CHARCOUNT); 
	}else if(!strcmp(argv[1],"-w")){
		int WORDCOUNT = wordCount(fp); 
		printf("单词数：%d",WORDCOUNT);
	}
	fclose(fp);//关闭文件
	return 0;	 
}
int openFile(FILE *fp){ //打开文件夹，返回-1表示未成功
	if(!fp){
		return -1; 
	} 
}
int wordCount(FILE *fp){//计算单词数
	char c;
	int count=0; 
	c = fgetc(fp);//读取文件中的一个字符，并且光标指向下一个 
	while(c!=-1){
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
			while((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){//遇到空格或标点符号则跳出循环 
				c = fgetc(fp);
			}
			count++;
			c = fgetc(fp);
		}else{
			c = fgetc(fp);
		}
	}
	return count;
}
int charCount(FILE *fp){//计算字符数
	char c;
	int count=0; 
	c = fgetc(fp);//读取文件中的一个字符，并且光标指向下一个 
	while(c!=-1){
		c = fgetc(fp);
		count++;
	}
	return count;
}
