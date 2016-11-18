#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    struct emp{
                char name[40];
                int age;
                float bs;
                };
    struct emp e;
    char ch='y';
    fp=fopen("ep.txt","w+b");

    do
    {
        printf("\nEnter the data:\n");
        scanf("%s %d %f",e.name,&e.age,&e.bs);

        //fprintf(fp,"%s %d %f",e.name,e.age,e.bs);
        fwrite(&e,sizeof(e),1,fp);

        printf("\nWant to add more data(y/n):\n");
        ch=getche();
        printf("\n");
        //fputc("\n",fp);
    }while(ch=='y');

    char str[40];
    float a;

    rewind(fp);

    printf("\nenter name of that person to modify\n");
    scanf("%s",str);
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        if(strcmp(str,e.name)==0)
            break;
    }

    printf("\nNow enter his/her new bs:\n");
    scanf("%f",&a);

    fseek(fp,-sizeof(e.bs),SEEK_CUR);

    fwrite(&a,sizeof(e.bs),1,fp);

    rewind(fp);

    while(fread(&e,sizeof(e),1,fp)==1)
    {
        printf("%s %d %f\n",e.name,e.age,e.bs);
    }


    fclose(fp);
    return 0;
}
