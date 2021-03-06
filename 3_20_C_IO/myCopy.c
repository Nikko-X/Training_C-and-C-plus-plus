/*实现copy函数*/

#include<stdio.h>
#include<stdlib.h>
#define BUFFSIZE 1024
int main(int argc,char **argv)
{
    FILE *fps,*fpd;
    char buf[BUFFSIZE];
    if(argc < 3)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>",argv[0]);
        exit(1);
    }
    fps = fopen(argv[1],"r");
    if(fps == NULL)
    {
        perror("fopen");
        exit(1);
    }

    fpd = fopen(argv[2],"w+");
    if (fpd == NULL)
    {
        fclose(fps);    //要写入的文件打开失败，要关闭源文件，否则会发生内存泄漏
        perror("fpd");
        exit(1);
    }
    
    while (fgets(buf,BUFFSIZE,fps) != NULL)
    {
        fputs(buf,fpd);

    }

    fclose(fpd);
    fclose(fps);
    exit(0);
}